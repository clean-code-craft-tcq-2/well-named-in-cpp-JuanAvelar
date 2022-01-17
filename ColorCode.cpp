#include <iostream>
#include "ColorCode.h"
const char* TelCoColorCoder::MajorColorNames[]   = {"White", "Red", "Black", "Yellow", "Violet"};
const int         TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* TelCoColorCoder::MinorColorNames[]   = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int         TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

TelCoColorCoder::ColorPair::ColorPair(MajorColor major, MinorColor minor): majorColor_(major), minorColor_(minor){
  pairNumber_ = major * numberOfMinorColors + minor + 1;
}
TelCoColorCoder::ColorPair::ColorPair(int pair): pairNumber_(pair){
    if(pair < 1 || pair > numberOfMajorColors*numberOfMinorColors) throw std::invalid_argument("\n\n\tERROR: Pair number exceeds range of possibilities!\n");
    int zeroBasedPairNumber = pair - 1;
    majorColor_ = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    minorColor_ = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
}
TelCoColorCoder::MajorColor TelCoColorCoder::ColorPair::getMajor() {
    return majorColor_;
}
TelCoColorCoder::MinorColor TelCoColorCoder::ColorPair::getMinor() {
    return minorColor_;
}
int TelCoColorCoder::ColorPair::getNumber() {
    return pairNumber_;
}
std::string TelCoColorCoder::ColorPair::ToString() {
    std::string colorPairStr = std::string(MajorColorNames[majorColor_]);
    colorPairStr += " | ";
    colorPairStr += MinorColorNames[minorColor_];
    return colorPairStr;
}
TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    return ColorPair(pairNumber);
}
int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return ColorPair(major, minor).getNumber();
}
void TelCoColorCoder::PrintAllCodes(void){
  std::cout << "\n\n||  \t  Reference Manual Color Coding\t      ||\n";
  std::cout << "||--------------------------------------------||" << '\n';
    for(int colorPairNo = 1; colorPairNo <= numberOfMajorColors*numberOfMinorColors; colorPairNo++){
        std::cout << "||No." << colorPairNo << "\t|\tColors: " << ColorPair(colorPairNo).ToString() << "\t      ||" << std::endl;
        if(!(colorPairNo%numberOfMinorColors)) std::cout << "||--------------------------------------------||" << '\n';
    }
}
