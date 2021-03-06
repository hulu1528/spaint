/**
 * tvginput: InputState.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#ifndef H_TVGINPUT_INPUTSTATE
#define H_TVGINPUT_INPUTSTATE

#include <map>
#include <vector>

#include "Keycode.h"
#include "MouseButton.h"

namespace tvginput {

/**
 * \brief An instance of this class maintains the current state of the keyboard and mouse.
 */
class InputState
{
  //#################### PRIVATE VARIABLES ####################
private:
  std::map<Keycode,bool> m_keyDown;
  std::map<MouseButton,bool> m_mouseButtonDown;
  int m_mouseMotionX, m_mouseMotionY;
  int m_mousePositionX, m_mousePositionY;
  std::vector<int> m_mousePressedX, m_mousePressedY;

  //#################### CONSTRUCTORS ####################
public:
  InputState();

  //#################### COPY CONSTRUCTOR & ASSIGNMENT OPERATOR ####################
private:
  InputState(const InputState&);
  InputState& operator=(const InputState&);

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  bool key_down(Keycode key) const;
  bool mouse_button_down(MouseButton button) const;
  int mouse_motion_x() const;
  int mouse_motion_y() const;
  bool mouse_position_known() const;
  int mouse_position_x() const;
  int mouse_position_y() const;
  int mouse_pressed_x(MouseButton button) const;
  int mouse_pressed_y(MouseButton button) const;
  void press_key(Keycode key);
  void press_mouse_button(MouseButton button, int x, int y);
  void release_key(Keycode key);
  void release_mouse_button(MouseButton button);
  void reset();
  void set_mouse_motion(int x, int y);
  void set_mouse_position(int x, int y);
};

}

#endif
