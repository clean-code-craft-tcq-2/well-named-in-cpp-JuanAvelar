namespace TelCoColorCoder
{
    enum MajorColor                   {WHITE,    RED,   BLACK,   YELLOW,   VIOLET };
    extern const char* MajorColorNames[];
    extern const int   numberOfMajorColors;

    enum MinorColor                   {BLUE,    ORANGE,   GREEN,   BROWN,   SLATE };
    extern const char* MinorColorNames[];
    extern const int   numberOfMinorColors;

    class ColorPair {
        private:
            int pairNumber_;
            MajorColor majorColor_;
            MinorColor minorColor_;
        public:
            ColorPair(MajorColor major, MinorColor minor);
            ColorPair(int pair);
            MajorColor getMajor();
            MinorColor getMinor();
            int getNumber();
            std::string ToString();
    };
    ColorPair GetColorFromPairNumber(int pairNumber);
    int       GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void      PrintAllCodes(void);
}
