#include "Shader.h"

void Shader::LoadShader(const char* _vert_path, const char* _frag_path) {
	// load vertex shader code from the file
	std::string vertShaderCode;
	std::ifstream vertShaderStream(_vert_path, std::ios::in);
	if (vertShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << vertShaderStream.rdbuf();
		vertShaderCode = sstr.str();
		vertShaderStream.close();
	}
	else {
		cout << "Impossible to open" << _vert_path << endl;
		return;
	}

	// load fragment shader code from the file
	std::string fragShaderCode;
	std::ifstream fragShaderStream(_frag_path, std::ios::in);
	if (fragShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << fragShaderStream.rdbuf();
		fragShaderCode = sstr.str();
		fragShaderStream.close();
	}
	else {
		cout << "Impossible to open" << _frag_path << endl;
		return;
	}

	// vertex shader 
	int fragShader = glCreateShader(GL_VERTEX_SHADER);
	char const* vertShaderSource = vertShaderCode.c_str();
	glShaderSource(vertShader, 1, &vertShaderSource, NULL);
	glCompileShader(vertShader);

	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << infoLog << endl;
	}

	//  fragment shader 
	int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	char const* fragShaderSource = fragShaderCode.c_str();
	glShaderSource(fragShader, 1, &fragShaderSource, NULL);
	glCompileShader(fragShader);

	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << infoLog << endl;
	}

	// link source to shader
	shaderID_ = glCreateProgram();
	glAttachShader(shaderID_, vertShader);
	glAttachShader(shaderID_, fragShader);
	glLinkProgram(shaderID_);

	// check for linking errors
	glGetProgramiv(shaderID_, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderID_, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << endl;
	}

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

int LoadShader(const char* _vert_path, const char* _frag_path)
{
	// ファイルからシェーダーコードを読み込む
	std::string vertShaderCode;
	std::ifstream vertShaderStream(_vert_path, std::ios::in);
	if (vertShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << vertShaderStream.rdbuf();
		vertShaderCode = sstr.str();
		vertShaderStream.close();
	}
	else {
		cout << "Impossible to open " << _vert_path << endl;
		//getchar();
		return 0;
	}

	string fragShaderCode;
	ifstream fragShaderStream(_frag_path, ios::in);
	if (fragShaderStream.is_open()) {
		stringstream sstr;
		sstr << fragShaderStream.rdbuf();
		fragShaderCode = sstr.str();
		fragShaderStream.close();
	}
	else {
		cout << "Impossible to open " << _frag_path << endl;
		//getchar();
		return 0;
	}

	// vertex shader
	int vertShader = glCreateShader(GL_VERTEX_SHADER);
	char const* vertShaderSource = vertShaderCode.c_str();
	glShaderSource(vertShader, 1, &vertShaderSource, NULL);
	glCompileShader(vertShader);

	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << infoLog << endl;
	}

	// fragment shader
	int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	char const* fragShaderSource = fragShaderCode.c_str();
	glShaderSource(fragShader, 1, &fragShaderSource, NULL);
	glCompileShader(fragShader);

	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED " << infoLog << endl;
	}

	// link shader
	int program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	// check for linking errors
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << endl;
	}

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return program;
}