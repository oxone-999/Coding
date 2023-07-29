bl_info = {
    "name": "Bezier Road Generator",
    "author": "Your Name",
    "version": (1, 0),
    "blender": (2, 80, 0),
    "location": "View3D > Add > Mesh",
    "description": "Generates a road along a bezier curve on a sculpted mesh",
    "warning": "",
    "wiki_url": "",
    "category": "Add Mesh",
}

import bpy
import bmesh


class BezierRoadGenerator(bpy.types.Operator):
    """Generate a road along a bezier curve on a sculpted mesh"""
    bl_idname = "mesh.bezier_road_generator"
    bl_label = "Bezier Road Generator"
    bl_options = {'REGISTER', 'UNDO'}

    distance_threshold: bpy.props.FloatProperty(
        name="Distance Threshold",
        description="The maximum distance between a mesh vertex and the road path for the vertex to be modified",
        default=0.1,
        min=0.0,
        max=10.0,
    )

    width: bpy.props.FloatProperty(
        name="Width",
        description="The width of the road",
        default=2.0,
        min=0.0,
        max=10.0,
    )

    thickness: bpy.props.FloatProperty(
        name="Thickness",
        description="The thickness of the road",
        default=0.1,
        min=0.0,
        max=10.0,
    )

    def execute(self, context):
        # Get the selected bezier curve and sculpted mesh
        curve = context.scene.objects.active
        mesh = context.selected_objects[1].data

        # Create a new bmesh for the sculpted mesh
        bm = bmesh.new()
        bm.from_mesh(mesh)

        # Extrude the road mesh along the curve
        for spline in curve.data.splines:
            if spline.type == 'BEZIER':
                for i in range(spline.resolution_u):
                    u = float(i) / (spline.resolution_u - 1)
                    pos, tangent, _ = spline.bezier_point(u, handle_type='VECTOR')
                    normal = -tangent.cross((0,0,1)).normalized()
                    up = tangent.cross(normal).normalized()
                    section = [(self.width/2.0*up - self.thickness/2.0*tangent + pos),
                               (self.width/2.0*up + self.thickness/2.0*tangent + pos),
                               (-self.width/2.0*up + self.thickness/2.0*tangent + pos),
                               (-self.width/2.0*up - self.thickness/2.0*tangent + pos),
                               (self.width/2.0*up - self.thickness/2.0*tangent + pos)]
                    verts = []
                    for vert in section:
                        found = False
                        for v in bm.verts:
                            if (vert - v.co).length < self.distance_threshold:
                                found = True
                                verts.append(v)
                                break
                        if not found:
                            verts.append(bm.verts.new(vert))
                    faces = []
                    for j in range(len(verts) - 1):
                        faces.append((verts[j], verts[j + 1], verts[j + 1] + len(section), verts[j] + len(section)))
                    bm.faces.new(faces)

        # Update the sculpted mesh
        bm.to_mesh(mesh)
        mesh.update()
        mesh.update(calc_edges=True)
        bm.free()

        # Set the active object to the sculpted mesh
        context.scene.objects.active = context.selected_objects[1]
        return {'FINISHED'}


def menu_func(self, context):
    self.layout.operator(BezierRoadGenerator.bl_idname)


def register():
    bpy.utils.register_class(BezierRoadGenerator)
    bpy.types.VIEW3D_MT_mesh_add.append(menu_func)


def unregister():
    bpy.utils.unregister_class(BezierRoadGenerator)
    bpy.types.VIEW3D_MT_mesh_add.remove(menu_func)


if __name__ == "__main__":
    register()
