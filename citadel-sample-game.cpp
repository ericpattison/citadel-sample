#include "castle/game/Game.h"
#include "watchtower/Color.h"

#include "keep/containers/Vector.h"

#ifdef WIN32
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "projects/glext.h"
#else

#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#endif
class CitadelSampleGame : public Game {
public:
	CitadelSampleGame(SPtr<Device> device):Game() {
#ifdef WIN32
		glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
		glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
		glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
		glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
		glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
		glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
#endif

        Color clearColor(127, 66, 255, 255);
        device->SetClearColor(clearColor);

		Vector<real> v = { 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f };

		glGenBuffers(1, &vb);
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glBufferData(GL_ARRAY_BUFFER, v.size(), v.asArray(), GL_STATIC_DRAW);
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		const char* vs_src = "attribute vec3 vp; void main(){ gl_Position = vec4(vp, 1.0); }";
		const char* fs_src = "void main() { gl_FragColor = vec4(0.5, 0.0, 0.5, 1.0); }";

		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vs_src, nullptr);
		glCompileShader(vs);

		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fs_src, nullptr);
		glCompileShader(fs);

		sp = glCreateProgram();
		glAttachShader(sp, vs);
		glAttachShader(sp, fs);
		glLinkProgram(sp);
    }

	virtual void Update() {
	
	}

	virtual void Render() {

		glUseProgram(sp);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

	}
private:
	GLuint vb;
	GLuint vao;
	GLuint sp;
#ifdef WIN32
	PFNGLGENBUFFERSPROC glGenBuffers;
	PFNGLBINDBUFFERPROC glBindBuffer;
	PFNGLBUFFERDATAPROC glBufferData;
	PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
	PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
	PFNGLCREATESHADERPROC glCreateShader;
	PFNGLSHADERSOURCEPROC glShaderSource;
	PFNGLCOMPILESHADERPROC glCompileShader;
	PFNGLCREATEPROGRAMPROC glCreateProgram;
	PFNGLATTACHSHADERPROC glAttachShader;
	PFNGLLINKPROGRAMPROC glLinkProgram;
	PFNGLUSEPROGRAMPROC glUseProgram;
#endif
	
};

UPtr<Game> createGame(SPtr<Device> device) {
	return MakeUPtr<CitadelSampleGame>(device);
}
GameRegistrar registrar(createGame);
