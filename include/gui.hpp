#ifndef GUI_HPP
#define GUI_HPP

#include "pros/apix.h"

/**
 * The header file for the GUI namespace. The GUI uses a namespace rather
 * than a class due to the nature of the LittleVGL C graphics library. I've
 * tried using classes, but they run into too many issues with LVGL functions
 *
 * The GUI namespace contains functions for creating more complex LVGL objects.
 */

namespace GUI {
/**
 * A function to create an LVGL button object. It packages all the LVGL
 * functions to create, set the press type and action, and align a button
 * into one function, as well as handling the creation of a label for the
 * button
 *
 * @param parent: the LVGL object the image should be created in
 * @param pressType: the button press type (Click, hold, long press, etc.)
 * @param function: the function to be called when the button is triggered
 * @param text: the label text on the button
 *
 * @return A pointer to a new LVGL button created using the given specs
 */
lv_obj_t *createButton(lv_obj_t *parent, lv_btn_action_t pressType,
                       lv_action_t function, const char *text);

/**
 * A function to create an LVGL label object. It packages all the LVGL functions
 * to create, align, and set the text of a label
 *
 * @param parent: the LVGL object the image should be created in
 * @param text: the text of the label
 *
 * @return A pointer to a new LVGL label created using the given specs
 */
lv_obj_t *createLabel(lv_obj_t *parent, const char *text);

/**
 * A function to create an LVGL button matrix object. It packages all the LVGL
 * functions to create, set the character map of, and align and size the button
 * matrix into one function
 *
 * @param parent: the LVGL object the image should be created in
 * @param map: a pointer to a String array used to generate the matrix of
 *             buttons and their labels
 * @param function: the function to be called when a button in the matrix is
 * clicked
 *
 * @return A pointer to a new LVGL button matrix created using the given specs
 */
lv_obj_t *createButtonMatrix(lv_obj_t *parent, const char *map[],
                             lv_btnm_action_t function);
} // namespace GUI

#endif // gui.hpp