/**
Copyright (c) 2020 Somesh Daga <s2daga@uwaterloo.ca>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "uwrt_arm_hw/arm_control_loop.h"

namespace uwrt
{
namespace arm
{
/**
 * Arm Control Loop for the real Arm hardware
 */
class RealArmControl : public ArmControlLoop
{
public:
  /**
   * \brief Constructor
   */
  RealArmControl();
  /**
   * \brief Destructor
   */
  ~RealArmControl();

  /**
   * \brief Read, Write and perform controller updates based on control period
   */ 
  void spinOnce();
  /**
   * Blocking loop of reads, writes and controller updates
   */
  void spin();

private:
  int loop_hz_;
  ros::Duration control_period_;  ///< The rate at which to perform controller updates
};  // class RealArmControl
}  // namespace arm
}  // namespace uwrt
