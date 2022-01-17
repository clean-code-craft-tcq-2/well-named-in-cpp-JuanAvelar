namespace TelCoColorCoder
{
    enum MajorColor                   {WHITE,    RED,   BLACK,   YELLOW,   VIOLET };
    extern const char* MajorColorNames[];
    extern int         numberOfMajorColors;

    enum MinorColor                   {BLUE,    ORANGE,   GREEN,   BROWN,   SLATE };
    extern const char* MinorColorNames[];
    extern int         numberOfMinorColors;

    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor);
            MajorColor getMajor();
            MinorColor getMinor();
            std::string ToString();
    };
    ColorPair GetColorFromPairNumber(int pairNumber);
    int       GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void      GetAllCodes(void);
}
