#include "Headers/Model.h"



Model::Model(Mesh& mesh, Shader& shader) :
	shader(shader),
	mesh(mesh)
{
	shader.use();
	shininess = 32;
}

Model::Model(Shader& shader) :
	shader(shader)
{
	shader.use();
	shininess = 32;
}

Model::~Model()
{
}

void Model::useCubeMesh()
{
	float vertices[] = {
		// positions          // normals           // colour
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.2f, 0.3f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.2f, 0.3f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.2f, 0.3f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.2f, 0.3f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.2f, 0.3f
	};

	mesh = Mesh();
	mesh.CreateMesh(vertices, 36);
}

void Model::updateColourShader()
{
	shader.setFloat("shininess", shininess);
}