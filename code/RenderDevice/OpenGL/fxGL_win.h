private:
	HWND    gl_wnd;
	HDC     gl_dc;
    HGLRC   gl_rc;

		
	void Init(HWND window_handle);
	void Shut(void);

	void SetupPixelFormat(int rgb_bits, int z_bits);
