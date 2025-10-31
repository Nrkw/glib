#ifndef GL_KEY_EVENT_HPP
#define GL_KEY_EVENT_HPP

namespace gl
{
    
    class KeyEvent
    {
        public:
            enum KeyAction
            {
                KEY_DOWN,
                KEY_UP,
                KEY_PRESS,
            };
            KeyEvent(WPARAM keycode, LPARAM lParam, KeyAction action)
            {
                this->keycode = keycode;
                this->lParam = lParam;
                this->action = action;
            }
            WPARAM keyCode;
            KeyAction action;
            // 仮想キーコードを文字に変換
            std::wstring getKeyChar() const
            {
                BYTE keyboardState[256];
                GetKeyboardState(keyboardState); // 現在のキーボード状態を取得

                wchar_t buffer[2] = {0}; // 変換結果を格納するバッファ
                int result = ToUnicode(
                    keycode,                     // 仮想キーコード
                    (lParam >> 16) & 0xFF,       // スキャンコード
                    keyboardState,               // キーボード状態
                    buffer,                      // 出力バッファ
                    2,                           // バッファのサイズ
                    0                            // フラグ
                );

                if (result > 0)
                {
                    return std::wstring(buffer, result); // 変換された文字を返す
                }
                return L""; // 変換できなかった場合は空文字を返す
            }

            static bool isShiftPressed()
            {
                return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
            }
            static bool isCtrlPressed()
            {
                return (GetKeyState(VK_CONTROL) & 0x8000) != 0;
            }
            WPARAM keycode;
            LPARAM lParam;
    };
}
#endif