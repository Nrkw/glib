#ifndef GL_MOUSE_EVENT_HPP
#define GL_MOUSE_EVENT_HPP

namespace gl
{
    class MouseEvent
    {
        public:
            enum MouseAction
            {
                MOUSE_MOVE,
                MOUSE_RBUTTON_DOWN,
                MOUSE_RBUTTON_UP,
                MOUSE_LBUTTON_DOWN,
                MOUSE_LBUTTON_UP,
                MOUSE_WHEEL
            };

            MouseEvent(WPARAM wParam, LPARAM lParam, MouseAction action)
            {
                this->wParam = wParam;
                this->lParam = lParam;
                this->action = action;
            }
            void getMousePosition(int& x, int& y)
            {
                x = GET_X_LPARAM(lParam);
                y = GET_Y_LPARAM(lParam);
            }
            void getMouseWheelDelta(int& delta)
            {
                delta = GET_WHEEL_DELTA_WPARAM(wParam);
            }
            MouseAction action;
        private:
            int GET_X_LPARAM(LPARAM lParam)
            {
                return LOWORD(lParam);
            }
            int GET_Y_LPARAM(LPARAM lParam)
            {
                return HIWORD(lParam);
            }
            WPARAM wParam;
            LPARAM lParam;
    };
};

#endif