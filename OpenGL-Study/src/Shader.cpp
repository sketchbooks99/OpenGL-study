#include "Shader.h"

// ===================================================================
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

// ===================================================================
void Shader::useShader() {
	glUseProgram(shaderID_);
}

// ===================================================================
void Shader::setUniformBool(const std::string& _name, bool _bool) {
	glUniform1i(glGetUniformLocation(shaderID_, _name.c_str()), (int)_bool);
}

// ===================================================================
void Shader::setUniformInt(const std::string& _name, int _value) {
	glUniform1i(glGetUniformLocation(shaderID_, _name.c_str()), _value);
}

// ===================================================================
void Shader::setUniformFloat(const std::string& _name, float _value) {
	glUniform1f(glGetUniformLocation(shaderID_, _name.c_str()), _value);
}

// ===================================================================
void Shader::setUniformVec2(const std::string& _name, const glm::vec2& _vec) {
	glUniform2fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, &_vec[0]);
}

// ===================================================================
void Shader::setUniformVec3(const std::string& _name, const glm::vec3& _vec) {
	glUniform3fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, &_vec[0]);
}

// ===================================================================
void Shader::setUniformVec4(const std::string& _name, const glm::vec4& _vec) {
	glUniform4fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, &_vec[0]);
}

// ===================================================================
void Shader::setUniformVec2v(const std::string& _name, const glm::vec2& _vec, int _num) {
	glUniform2fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, &_vec[0]);
}

// ===================================================================
void Shader::setUniformVec3v(const std::string& _name, const glm::vec3& _vec, int _num) {
	glUniform3fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, &_vec[0]);
}

// ===================================================================
void Shader::setUniformVec4v(const std::string& _name, const glm::vec4& _vec, int _num) {
	glUniform4fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, &_vec[0]);
}

// ===================================================================
void Shader::setUniformMat2(const std::string& _name, const glm::mat2& _mat) {
	glUniformMatrix2fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, GL_FALSE, &_mat[0][0]);
}

// ===================================================================
void Shader::setUniformMat3(const std::string& _name, const glm::mat3& _mat) {
	glUniformMatrix3fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, GL_FALSE, &_mat[0][0]);
}

// ===================================================================
void Shader::setUniformMat4(const std::string& _name, const glm::mat4& _mat) {
	glUniformMatrix4fv(glGetUniformLocation(shaderID_, _name.c_str()), 1, GL_FALSE, &_mat[0][0]);
}

// ===================================================================
void Shader::setUniformMat2v(const std::string& _name, const glm::mat2& _mat, int _num) {
	glUniformMatrix2fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, GL_FALSE, &_mat[0][0]);
}

// ===================================================================
void Shader::setUniformMat3v(const std::string& _name, const glm::mat3& _mat, int _num) {
	glUniformMatrix3fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, GL_FALSE, &_mat[0][0]);
}

// ===================================================================
void Shader::setUniformMat4v(const std::string& _name, const glm::mat4& _mat, int _num) {
	glUniformMatrix4fv(glGetUniformLocation(shaderID_, _name.c_str()), _num, GL_FALSE, &_mat[0][0]);
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