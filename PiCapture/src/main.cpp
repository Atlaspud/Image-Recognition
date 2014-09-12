#include "camera.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstdio>
#include <sys/time.h>

using namespace cv;

// Capture size
#define WIDTH 512
#define HEIGHT 512

int main(int argc, char *argv[])
{
	// Open the camera at 15fps, one level of downsampling, and BGR conversion
	CCamera* cam = StartCamera(WIDTH, HEIGHT, 15, 1, true);

	for (;;) {
		// Acquire an image
		Mat display_img = cam->Capture(0);
		if (!display_img.data) {
			printf("Failed to acquire image\n");
			continue;
		}

		// Display
		imshow("Display", display_img);

		// Update the GUI
		waitKey(10);
	}

	StopCamera();
}
