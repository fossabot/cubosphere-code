/**
Copyright (C) 2010 Chriddo
Copyright (C) 2018 Valeri Ochinski <v19930312@gmail.com>

This program is free software;
you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program;
if not, see <http://www.gnu.org/licenses/>.
**/

#pragma once

#include <GL/glew.h>
#include <SDL.h>

#include <string>
#include <vector>

// (IDENT-CODE, PRESS or RELEASE, First-Time-Down (toggle)
using KeyboardFunc = void(*)(int,int,int);

class Keyboard {
	protected:
		int keynum;
		Uint8 *keydown;
		std::vector<Uint8> downbefore;
		std::vector<double> pressedtime;
		KeyboardFunc handler;
		double rep_start_time;
		double rep_rep_time;
		int textinputmode;
		SDL_keysym lastkeysim;
	public:
		SDL_keysym GetLastKeySim() {return lastkeysim;}
		void SetKeyRepeatTimes(double rstart,double rrep) {rep_start_time=rstart; rep_rep_time=rrep;}
		void StartTextInput();
		void StopTextInput();
		//TKeyboard();
		// void Initialize();
		double & GetPressedTime(int ident) {return pressedtime[ident];}
		int IsPressed(int ident) {return keydown[ident];}
		int DownBefore(int ident) {return downbefore[ident];}
		SDLKey GetKeyConstFor(std::string keyname);
		void SetHandler(KeyboardFunc h) {handler=h;}
//    void RegisterKey(SDLKey key,int ident,TKeyboardFunc func, int toggle);
		void DispatchEvent(SDL_Event *ev);
		void HandleKeys();
		void Init();
		std::string GetKeyName(int key);
	};

extern void LUA_KEYB_RegisterLib();

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
