class Camera{
    public:
        Camera();    
	void setAlpha(double delta);
	void setBeta(double delta);
	void setZoom(int delta);
	void view(double pos_x, double pos_y);

    private:
	double width;
	double height;
	double alpha;
	double raio;
	double beta;
	double max_beta;
	double min_beta;
	
};