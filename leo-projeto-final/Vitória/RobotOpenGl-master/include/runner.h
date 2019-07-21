class Runner{
	public:
		Runner();
		static void run(int argc, char* argv[]);
	private:
		static GLint Width;
		static GLint Height;
		static int pos_mouse_x;
		static int pos_mouse_y;
		static Robot robot;
		static Camera camera; 
		static Plataform plataform; 

		static void reshape(int width, int height);
		static void initLighting(void);
		static void keyboard(unsigned char key, int x, int y);
		static void moving_mouse(int x, int y);
		static void mouse(int button, int state, int x, int y);
		static void display(void);


};