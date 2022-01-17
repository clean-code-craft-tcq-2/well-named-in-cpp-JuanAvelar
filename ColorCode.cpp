#include <iostream>
#include "ColorCode.h"
const char* TelCoColorCoder::MajorColorNames[]   = {"White", "Red", "Black", "Yellow", "Violet"};
int         TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* TelCoColorCoder::MinorColorNames[]   = {"Blue", "Orange", "Green", "Brown", "Slate"};
int         TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

TelCoColorCoder::ColorPair::ColorPair(MajorColor major, MinorColor minor): majorColor(major), minorColor(minor){
  //empty
}
TelCoColorCoder::MajorColor TelCoColorCoder::ColorPair::getMajor() {
    return majorColor;
}
TelCoColorCoder::MinorColor TelCoColorCoder::ColorPair::getMinor() {
    return minorColor;
}
std::string TelCoColorCoder::ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}
int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}
