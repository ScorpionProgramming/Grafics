#version 430 core

void main(void)
{
	const vec4 vertices[6] = vec4[6](vec4( 0.0, 0.0, 0.5, 1.0),
									vec4( -0.2, 0.2, 0.5, 1.0),
									vec4( 0.2, 0.2, 0.5, 1.0),
									vec4( 0.0, 0.0, 0.5, 1.0),
									vec4( -0.2, -0.2, 0.5, 1.0),
									vec4( 0.2, -0.2, 0.5, 1.0)
                                    );
   gl_Position = vertices[gl_VertexID];
}