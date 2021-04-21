#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    FILE *solution;
    solution = fopen ("solution.txt", "r");
    int rows = 0, cols = 0;
    fscanf(solution, "%d %d", &rows, &cols);
    int arr[rows][cols];

    int row, col;
    for (row = 0; row < rows; row++){
        for (col = 0; col < cols; col++){
            fscanf(solution, "%d", &arr[row][col]);
        }
    }

    Mat maze = Mat::zeros(rows, cols, CV_8UC3);

    int scale = 1;

	for(int i=0;i<maze.rows;i++) {
		for (int j=0;j<maze.cols;j++) {
		    if (arr[i][j] == 0) {maze.at<cv::Vec3b>(i,j)[0] = 255;   maze.at<cv::Vec3b>(i,j)[1] = 255; maze.at<cv::Vec3b>(i,j)[2] = 255;}
		    else if (arr[i][j] == 1) {maze.at<cv::Vec3b>(i,j)[0] = 0  ;   maze.at<cv::Vec3b>(i,j)[1] = 0  ; maze.at<cv::Vec3b>(i,j)[2] = 0  ;}
		    else if (arr[i][j] == 2) {maze.at<cv::Vec3b>(i,j)[0] = 0  ;   maze.at<cv::Vec3b>(i,j)[1] = 255; maze.at<cv::Vec3b>(i,j)[2] = 0  ;}
		    else if (arr[i][j] == 3) {maze.at<cv::Vec3b>(i,j)[0] = 255;   maze.at<cv::Vec3b>(i,j)[1] = 0  ; maze.at<cv::Vec3b>(i,j)[2] = 0  ;}
		    else if (arr[i][j] == 4) {maze.at<cv::Vec3b>(i,j)[0] = 0  ;   maze.at<cv::Vec3b>(i,j)[1] = 0  ; maze.at<cv::Vec3b>(i,j)[2] = 255;}
		}
	}


	namedWindow("SOLUTION", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "SOLUTION", maze);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
