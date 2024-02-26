/*
Build a tool that allows users to perform various image processing operations like resizing, cropping, and filtering.

Load Image: Allow users to load an image.
Display Image: Display the loaded image in the application.
Image Filters: Implement basic image filters like grayscale, blur, and sharpen.
Color Adjustment: Allow users to adjust image colors, brightness, and contrast.
Crop and Resize: Provide options to crop and resize the image.
Image Saving: Enable users to save the processed image.
User Interface: Design a user-friendly interface for easy interaction
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ImageProcessor {
public:
    ImageProcessor(const string &imagePath) {
        image = imread(imagePath);
        if (image.empty()) {
            cout << "Could not open or find the image" << endl;
            exit(0);
        }
    }

    void applyFilter(int filterType) {
        Mat filteredImage;

        switch (filterType) {
            case 1:
                cvtColor(image, filteredImage, COLOR_BGR2GRAY);
                break;
            case 2:
                GaussianBlur(image, filteredImage, Size(5, 5), 0, 0);
                break;
            case 3:
                medianBlur(image, filteredImage, 5);
                break;
            case 4:
                Canny(image, filteredImage, 100, 200);
                break;
            case 5:
                Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 5);
                filter2D(image, filteredImage, -1, kernel);
                break;
            default:
                cout << "Invalid filter type" << endl;
                return;
        }

        image = filteredImage;
    }

    void applyColorAdjustment(int adjustmentType, int channel, int value) {
        Mat adjustedImage;

        switch (adjustmentType) {
            case 1:
                cvtColor(image, adjustedImage, COLOR_BGR2HSV);
                break;
            case 2:
                cvtColor(image, adjustedImage, COLOR_BGR2HLS);
                break;
            case 3:
                cvtColor(image, adjustedImage, COLOR_BGR2YCrCb);
                break;
            default:
                cout << "Invalid adjustment type" << endl;
                return;
        }

        vector<Mat> channels;
        split(adjustedImage, channels);

        if (channel >= 0 && channel < 3) {
            channels[channel] += value;
            merge(channels, 3, adjustedImage);

            cvtColor(adjustedImage, image, COLOR_HSV2BGR);
        } else {
            cout << "Invalid channel index" << endl;
        }
    }

    void cropAndResize(const Rect &roi) {
        Mat croppedImage = image(roi);
        resize(croppedImage, image, Size(), 2, 2, INTER_CUBIC);
    }

    void displayImage() {
        imshow("Image", image);
        waitKey(0);
    }

    void saveImage(const string &savePath) {
        imwrite(savePath, image);
    }

private:
    Mat image;
};

int main() {
    string imagePath, savePath;
    int operation;

    cout << "Enter image path: ";
    cin >> imagePath;

    ImageProcessor imageProcessor(imagePath);

    while (true) {
        cout << "1. Apply Filter" << endl;
        cout << "2. Color Adjustment" << endl;
        cout << "3. Crop and Resize" << endl;
        cout << "4. Display Image" << endl;
        cout << "5. Save Image" << endl;
        cout << "6. Exit" << endl;
        cin >> operation;

        switch (operation) {
            case 1: {
                int filterType;
                cout << "Enter filter type (1 - Grayscale, 2 - Gaussian Blur, 3 - Median Blur, 4 - Canny, 5 - Sharpen): ";
                cin >> filterType;
                imageProcessor.applyFilter(filterType);
                break;
            }
            case 2: {
                int adjustmentType, channel, value;
                cout << "Enter adjustment type (1 - HSV, 2 - HLS, 3 - YCrCb): ";
                cin >> adjustmentType;
                cout << "Enter channel index (0 - Hue, 1 - Saturation, 2 - Value): ";
                cin >> channel;
                cout << "Enter adjustment value (-255 to 255): ";
                cin >> value;
                imageProcessor.applyColorAdjustment(adjustmentType, channel, value);
                break;
            }
            case 3: {
                Rect roi;
                cout << "Enter top, left, width, and height: ";
                cin >> roi.x >> roi.y >> roi.width >> roi.height;
                imageProcessor.cropAndResize(roi);
                break;
            }
            case 4:
                imageProcessor.displayImage();
                break;
            case 5:
                cout << "Enter save path: ";
                cin >> savePath;
                imageProcessor.saveImage(savePath);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid operation type" << endl;
        }
    }

    return 0;
}