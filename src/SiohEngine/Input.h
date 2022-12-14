#ifndef SIOHENGINE_INPUT_H
#define SIOHENGINE_INPUT_H

#include <SDL2/SDL.h>
#include <iostream>
#include <list>

namespace SiohEngine
{
	struct Input
	{
	public:
		bool GetKey(SDL_Keycode code);
		bool GetKeyDown(SDL_Keycode code);
		bool GetKeyUp(SDL_Keycode code);
		

	private:
		friend struct Core;

		static std::list<SDL_Keycode> keys;
		static std::list<SDL_Keycode> keyDown;
		static std::list<SDL_Keycode> keyUp;
	};

	struct Keys
	{
		static const int UP = SDLK_UP; ///< Up arrow key
		static const int DOWN = SDLK_DOWN; ///< Down arrow key
		static const int LEFT = SDLK_LEFT; ///< Left arrow key
		static const int RIGHT = SDLK_RIGHT; ///< Right arrow Key
		static const int A = SDLK_a; ///< A key
		static const int B = SDLK_b; ///< B key
		static const int C = SDLK_c; ///< C key
		static const int D = SDLK_d; ///< D	key
		static const int E = SDLK_e; ///< E	key
		static const int F = SDLK_f; ///< F	key
		static const int G = SDLK_g; ///< G	key
		static const int H = SDLK_h; ///< H	key
		static const int I = SDLK_i; ///< I	key
		static const int J = SDLK_j; ///< J	key
		static const int K = SDLK_k; ///< K	key
		static const int L = SDLK_l; ///< L	key
		static const int M = SDLK_m; ///< M	key
		static const int N = SDLK_n; ///< N	key
		static const int O = SDLK_o; ///< O	key
		static const int P = SDLK_p; ///< P	key
		static const int Q = SDLK_q; ///< Q	key
		static const int R = SDLK_r; ///< R	key
		static const int S = SDLK_s; ///< S	key
		static const int T = SDLK_t; ///< T	key
		static const int U = SDLK_u; ///< U	key
		static const int V = SDLK_v; ///< V	key
		static const int W = SDLK_w; ///< W	key
		static const int X = SDLK_x; ///< X	key
		static const int Y = SDLK_y; ///< Y	key
		static const int Z = SDLK_z; ///< Z	key
		static const int key_0 = SDLK_0; ///< Keyboard 0 key
		static const int key_1 = SDLK_1; ///< Keyboard 1 key
		static const int key_2 = SDLK_2; ///< Keyboard 2 key
		static const int key_3 = SDLK_3; ///< Keyboard 3 key
		static const int key_4 = SDLK_4; ///< Keyboard 4 key
		static const int key_5 = SDLK_5; ///< Keyboard 5 key
		static const int key_6 = SDLK_6; ///< Keyboard 6 key
		static const int key_7 = SDLK_7; ///< Keyboard 7 key
		static const int key_8 = SDLK_8; ///< Keyboard 8 key
		static const int key_9 = SDLK_9; ///< Keyboard 9 key
		static const int FN_1 = SDLK_F1; ///< Function 1 key
		static const int FN_2 = SDLK_F2; ///< Function 2 key
		static const int FN_3 = SDLK_F3; ///< Function 3 key
		static const int FN_4 = SDLK_F4; ///< Function 4 key
		static const int FN_5 = SDLK_F5; ///< Function 5 key
		static const int FN_6 = SDLK_F6; ///< Function 6 key
		static const int FN_7 = SDLK_F7; ///< Function 7 key
		static const int FN_8 = SDLK_F8; ///< Function 8 key
		static const int FN_9 = SDLK_F9; ///< Function 9 key
		static const int FN_10 = SDLK_F10; ///< Function 10 key
		static const int FN_11 = SDLK_F11; ///< Function 11 key
		static const int FN_12 = SDLK_F12; ///< Function 12 key
		static const int SPACE = SDLK_SPACE; ///< Spacebar
		static const int BACKSPACE = SDLK_BACKSPACE; ///< Backspace key
		static const int RETURN = SDLK_RETURN; ///< Enter/return key
		static const int ENTER = SDLK_KP_ENTER; ///< Keypad enter key
		static const int LSHIFT = SDLK_LSHIFT; ///< Left shift key
		static const int RSHIFT = SDLK_RSHIFT; ///< Right shift key
		static const int LCTRL = SDLK_LCTRL; ///< Left control key
		static const int RCTRL = SDLK_RCTRL; ///< Right control key
		static const int LALT = SDLK_LALT; ///< Left alt key
		static const int RALT = SDLK_RALT; ///< Right alt key
		static const int TAB = SDLK_TAB; ///< Tab key
		static const int CAPSLOCK = SDLK_CAPSLOCK; ///< Caps lock key
		static const int INSERT = SDLK_INSERT; ///< Insert key
		static const int DELETE = SDLK_DELETE; ///< Delete Key
		static const int HOME = SDLK_HOME; ///< Home key
		static const int END = SDLK_END; ///< End key
		static const int PGUP = SDLK_PAGEUP; ///< Page up key
		static const int PGDN = SDLK_PAGEDOWN; ///< Page down key
		static const int PRINTSCREEN = SDLK_PRINTSCREEN; ///< Printscreen key
		static const int SCROLLLOCK = SDLK_SCROLLLOCK; ///< Scroll lock key
		static const int PAUSE = SDLK_PAUSE; ///< Pause key
		static const int NUM_0 = SDLK_KP_0; ///< Keypad 0 key
		static const int NUM_1 = SDLK_KP_1;	///< Keypad 1 key
		static const int NUM_2 = SDLK_KP_2;	///< Keypad 2 key
		static const int NUM_3 = SDLK_KP_3;	///< Keypad 3 key
		static const int NUM_4 = SDLK_KP_4;	///< Keypad 4 key
		static const int NUM_5 = SDLK_KP_5;	///< Keypad 5 key
		static const int NUM_6 = SDLK_KP_6;	///< Keypad 6 key
		static const int NUM_7 = SDLK_KP_7;	///< Keypad 7 key
		static const int NUM_8 = SDLK_KP_8;	///< Keypad 8 key
		static const int NUM_9 = SDLK_KP_9;	///< Keypad 9 key
		static const int NUM_DOT = SDLK_KP_PERIOD; ///< Keypad period key
		static const int NUM_ADD = SDLK_KP_PLUS; ///< Keypad plus key
		static const int NUM_MINUS = SDLK_KP_MINUS; ///< Keypad minus key
		static const int NUM_MULTIPLY = SDLK_KP_MULTIPLY; ///< Keypad multiply key
		static const int NUM_DIVIDE = SDLK_KP_DIVIDE; ///< Keypad divide key
		static const int MINUS = SDLK_MINUS; ///< Minus key
		static const int PLUS = SDLK_PLUS; ///< Plus key
		static const int SEMICOLON = SDLK_SEMICOLON; ///< Semicolon key
		static const int AT = SDLK_AT; ///< At/apostrophe key
		static const int HASH = SDLK_HASH; ///< Hash key
		static const int SLASH = SDLK_SLASH; ///< Forward slash key
		static const int BACKSLASH = SDLK_BACKSLASH; ///< Back slash key
		static const int PERIOD = SDLK_PERIOD; ///< Period key
		static const int COMMA = SDLK_COMMA; ///< Comma key
		static const int LSQUAREBRACKET = SDLK_LEFTBRACKET; ///< Left square bracket key
		static const int RSQUAREBRACKET = SDLK_RIGHTBRACKET; ///< Right square bracket key
		static const int ESCAPE = SDLK_ESCAPE; ///< Escape key
	};
}

#endif // !SIOHENGINE_INPUT_H
