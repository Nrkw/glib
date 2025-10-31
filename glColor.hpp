#ifndef GLCOLOR_HPP
#define GLCOLOR_HPP
namespace gl
{
    class Color
    {
        public:
            Color(float r, float g, float b, float a = 1.0f)
                : red(r), green(g), blue(b), alpha(a) {}
            float red;
            float green;
            float blue;
            float alpha;
            static Color White() { return Color(1.0f, 1.0f, 1.0f); }
            static Color Black() { return Color(0.0f, 0.0f, 0.0f); }
            static Color Red()   { return Color(1.0f, 0.0f, 0.0f); }
            static Color Green() { return Color(0.0f, 1.0f, 0.0f); }
            static Color Blue()  { return Color(0.0f, 0.0f, 1.0f); }
            static Color Transparent() { return Color(0.0f, 0.0f, 0.0f, 0.0f); }
            //Webの色で登録されている基本的な色（skyblue, coral, goldなどhexでなく文字で表されている）もここに追加していく
            static Color SkyBlue() { return Color(0.529f, 0.808f, 0.922f); }
            static Color Coral() { return Color(1.0f, 0.498f, 0.314f); }
            static Color Gold() { return Color(1.0f, 0.843f, 0.0f); }
            static Color Lime() { return Color(0.0f, 1.0f, 0.0f); }
            static Color Magenta() { return Color(1.0f, 0.0f, 1.0f); }
            static Color Cyan() { return Color(0.0f, 1.0f, 1.0f); }
            static Color Yellow() { return Color(1.0f, 1.0f, 0.0f); }
            static Color Gray() { return Color(0.502f, 0.502f, 0.502f); }
            static Color Orange() { return Color(1.0f, 0.647f, 0.0f); }
            static Color Purple() { return Color(0.502f, 0.0f, 0.502f); }
            static Color Brown() { return Color(0.647f, 0.165f, 0.165f); }
            static Color Pink() { return Color(1.0f, 0.753f, 0.796f); }
            static Color Olive() { return Color(0.502f, 0.502f, 0.0f); }
            static Color Teal() { return Color(0.0f, 0.502f, 0.502f); }
            static Color Navy() { return Color(0.0f, 0.0f, 0.502f); }
            static Color Maroon() { return Color(0.502f, 0.0f, 0.0f); }
            static Color Silver() { return Color(0.753f, 0.753f, 0.753f); }
            static Color GoldMetallic() { return Color(1.0f, 0.843f, 0.0f); }
            static Color Bronze() { return Color(0.804f, 0.498f, 0.196f); }
            static Color Copper() { return Color(0.722f, 0.451f, 0.2f); }
            static Color Emerald() { return Color(0.314f, 0.784f, 0.471f); }
            static Color Sapphire() { return Color(0.063f, 0.322f, 0.639f); }
            static Color Ruby() { return Color(0.878f, 0.066f, 0.373f); }
            static Color Amber() { return Color(1.0f, 0.749f, 0.0f); }
            static Color Mint() { return Color(0.596f, 1.0f, 0.596f); }
            static Color Lavender() { return Color(0.902f, 0.902f, 0.980f); }
            static Color Peach() { return Color(1.0f, 0.855f, 0.725f); }
            static Color Chocolate() { return Color(0.824f, 0.412f, 0.118f); }
            static Color Salmon() { return Color(1.0f, 0.549f, 0.412f); }
            static Color Turquoise() { return Color(0.251f, 0.878f, 0.816f); }
            static Color Indigo() { return Color(0.294f, 0.0f, 0.510f); }
            static Color Violet() { return Color(0.933f, 0.510f, 0.933f); }
            static Color MagentaFuchsia() { return Color(1.0f, 0.0f, 1.0f); }
            static Color Chartreuse() { return Color(0.498f, 1.0f, 0.0f); }
            static Color Aquamarine() { return Color(0.498f, 1.0f, 0.831f); }
            static Color Crimson() { return Color(0.863f, 0.078f, 0.235f); } 
            static Color Khaki() { return Color(0.941f, 0.902f, 0.549f); }
            static Color Plum() { return Color(0.867f, 0.627f, 0.867f); }
            static Color Mustard() { return Color(1.0f, 0.859f, 0.251f); }
            static Color Periwinkle() { return Color(0.8f, 0.8f, 1.0f); }
            static Color SalmonPink() { return Color(1.0f, 0.568f, 0.643f); }
            static Color SlateGray() { return Color(0.439f, 0.502f, 0.565f); }
            static Color OliveDrab() { return Color(0.420f, 0.557f, 0.137f); }
            static Color FireBrick() { return Color(0.698f, 0.133f, 0.133f); }
            static Color DarkGoldenrod() { return Color(0.722f, 0.525f, 0.043f); }
            static Color MediumSeaGreen() { return Color(0.235f, 0.702f, 0.443f); }
            static Color LightSeaGreen() { return Color(0.125f, 0.698f, 0.667f); }
            static Color DarkSlateBlue() { return Color(0.282f, 0.239f, 0.545f); }
            static Color MediumOrchid() { return Color(0.729f, 0.333f, 0.827f); }
            static Color DeepPink() { return Color(1.0f, 0.078f, 0.576f); }
            static Color Goldenrod() { return Color(0.855f, 0.647f, 0.125f); }
            static Color DarkOliveGreen() { return Color(0.333f, 0.420f, 0.184f); }
            static Color SeaGreen() { return Color(0.180f, 0.545f, 0.341f); }
            static Color RoyalBlue() { return Color(0.255f, 0.412f, 0.882f); }
            static Color DarkViolet() { return Color(0.580f, 0.0f, 0.827f); }
            static Color HotPink() { return Color(1.0f, 0.412f, 0.706f); }
            static Color DarkOrange() { return Color(1.0f, 0.549f, 0.0f); }
            static Color ForestGreen() { return Color(0.133f, 0.545f, 0.133f); }
            static Color DodgerBlue() { return Color(0.118f, 0.565f, 1.0f); }
            static Color MediumPurple() { return Color(0.576f, 0.439f, 0.859f); }
            static Color PaleVioletRed() { return Color(0.859f, 0.439f, 0.576f); }
            static Color LightCoral() { return Color(0.941f, 0.502f, 0.502f); }
            static Color SandyBrown() { return Color(0.957f, 0.643f, 0.376f); }
            static Color MediumTurquoise() { return Color(0.282f, 0.820f, 0.800f); }
            static Color DarkSlateGray() { return Color(0.184f, 0.310f, 0.310f); }
            static Color MediumSlateBlue() { return Color(0.482f, 0.408f, 0.933f); }
            static Color LightPink() { return Color(1.0f, 0.714f, 0.757f); }
            static Color CoralReef() { return Color(1.0f, 0.498f, 0.314f); }
            static Color SunflowerYellow() { return Color(1.0f, 0.843f, 0.0f); }
            static Color OceanBlue() { return Color(0.0f, 0.502f, 0.753f); }
            static Color ForestGreenDark() { return Color(0.133f, 0.545f, 0.133f); }
            static Color SunsetOrange() { return Color(1.0f, 0.325f, 0.0f); }
            static Color MintGreen() { return Color(0.596f, 1.0f, 0.596f); }
            static Color LavenderBlush() { return Color(1.0f, 0.941f, 0.961f); }
            static Color PeachPuff() { return Color(1.0f, 0.855f, 0.725f); }
            static Color DarkChocolate() { return Color(0.545f, 0.271f, 0.075f); }
            static Color LightSalmon() { return Color(1.0f, 0.627f, 0.478f); }
            static Color AquamarineLight() { return Color(0.498f, 1.0f, 0.831f); }
            static Color IndigoDeep() { return Color(0.063f, 0.322f, 0.639f); }
            static Color VioletLight() { return Color(0.933f, 0.510f, 0.933f); }
            static Color MagentaBright() { return Color(1.0f, 0.0f, 1.0f); }
            static Color ChartreuseBright() { return Color(0.498f, 1.0f, 0.0f); }
            static Color AquamarineBright() { return Color(0.498f, 1.0f, 0.831f); }
            static Color CrimsonDeep() { return Color(0.863f, 0.078f, 0.235f); }
            static Color KhakiLight() { return Color(0.941f, 0.902f, 0.549f); }
            static Color PlumLight() { return Color(0.867f, 0.627f, 0.867f); }
            static Color MustardBright() { return Color(1.0f, 0.859f, 0.251f); }
            static Color PeriwinkleLight() { return Color(0.8f, 0.8f, 1.0f); }
            static Color SalmonPinkLight() { return Color(1.0f, 0.568f, 0.643f); }
            static Color SlateGrayLight() { return Color(0.439f, 0.502f, 0.565f); }
            static Color OliveDrabLight() { return Color(0.420f, 0.557f, 0.137f); }
            static Color FireBrickDeep() { return Color(0.698f, 0.133f, 0.133f); }
            static Color DarkGoldenrodDeep() { return Color(0.722f, 0.525f, 0.043f); }
            static Color MediumSeaGreenDeep() { return Color(0.235f, 0.702f, 0.443f); }
            static Color LightSeaGreenDeep() { return Color(0.125f, 0.698f, 0.667f); }
            static Color DarkSlateBlueDeep() { return Color(0.282f, 0.239f, 0.545f); }
            static Color MediumOrchidDeep() { return Color(0.729f, 0.333f, 0.827f); }
            static Color DeepPinkBright() { return Color(1.0f, 0.078f, 0.576f); }
            static Color GoldenrodBright() { return Color(0.855f, 0.647f, 0.125f); }
            static Color DarkOliveGreenDeep() { return Color(0.333f, 0.420f, 0.184f); }
            static Color SeaGreenDeep() { return Color(0.180f, 0.545f, 0.341f); }
            static Color RoyalBlueDeep() { return Color(0.255f, 0.412f, 0.882f); }
            static Color DarkVioletDeep() { return Color(0.580f, 0.0f, 0.827f); }
            static Color HotPinkBright() { return Color(1.0f, 0.412f, 0.706f); }
            static Color DarkOrangeBright() { return Color(1.0f, 0.549f, 0.0f); }
            static Color ForestGreenDeep() { return Color(0.133f, 0.545f, 0.133f); }
            static Color DodgerBlueBright() { return Color(0.118f, 0.565f, 1.0f); }
            static Color MediumPurpleDeep() { return Color(0.576f, 0.439f, 0.859f); }
            static Color PaleVioletRedDeep() { return Color(0.859f, 0.439f, 0.576f); }
            static Color LightCoralLight() { return Color(0.941f, 0.502f, 0.502f); }
            static Color SandyBrownLight() { return Color(0.957f, 0.643f, 0.376f); }
            static Color MediumTurquoiseLight() { return Color(0.282f, 0.820f, 0.800f); }
            static Color DarkSlateGrayDeep() { return Color(0.184f, 0.310f, 0.310f); }
            static Color MediumSlateBlueDeep() { return Color(0.482f, 0.408f, 0.933f); }
            static Color LightPinkLight() { return Color(1.0f, 0.714f, 0.757f); }
            static Color CoralReefLight() { return Color(1.0f, 0.498f, 0.314f); }
            static Color SunflowerYellowLight() { return Color(1.0f, 0.843f, 0.0f); }
            static Color OceanBlueLight() { return Color(0.0f, 0.502f, 0.753f); }
            static Color ForestGreenDarkLight() { return Color(0.133f, 0.545f, 0.133f); }
            static Color SunsetOrangeLight() { return Color(1.0f, 0.325f, 0.0f); }
            static Color MintGreenLight() { return Color(0.596f, 1.0f, 0.596f); }
            static Color LavenderBlushLight() { return Color(1.0f, 0.941f, 0.961f); }
            static Color PeachPuffLight() { return Color(1.0f, 0.855f, 0.725f); }
            static Color DarkChocolateLight() { return Color(0.545f, 0.271f, 0.075f); }
            


    };
};
#endif