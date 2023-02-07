#include "gui.hpp"

/**
 * The implementations for the GUI namespace functions.
 * The functions initialize LVGL objects, as well as doing some configuration
 * for the objects.
 */

lv_obj_t *GUI::createButton(lv_obj_t *parent, lv_btn_action_t pressType,
                            lv_action_t function, const char *text) {
    // Creating an LVGL button
    lv_obj_t *btn = lv_btn_create(parent, NULL);
    // Setting the button's action upon a given type of trigger
    lv_btn_set_action(btn, pressType, function);

    // Creating a label for the button
    lv_obj_t *label = createLabel(btn, text);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    /**
     * Return the created button
     * This returns the button to the declared LVGL object in
     * initialize, making that object into an identical button to
     * the button btn created in this function.
     */
    return btn;
}

lv_obj_t *GUI::createLabel(lv_obj_t *parent, const char *text) {
    // Creating a LVGL Label
    lv_obj_t *lbl = lv_label_create(parent, NULL);

    // Setting the label's text
    lv_label_set_text(lbl, text);
    /**
     * Return the created label
     * This returns the label to the declared LVGL object in
     * initialize, making that object into an identical label to
     * the label lbl created in this function.
     */
    return lbl;
}

lv_obj_t *GUI::createButtonMatrix(lv_obj_t *parent, const char *map[],
                                  lv_btnm_action_t function) {
    // Creating an LVGL button matrix
    lv_obj_t *btnm = lv_btnm_create(parent, NULL);
    // Setting the button matrix's action upon a given type of trigger
    lv_btnm_set_action(btnm, function);
    // Set the String array to be used to create the button matrix
    lv_btnm_set_map(btnm, map);

    /**
     * Return the created button matrix
     * This returns the button matrix to the declared LVGL object in
     * initialize, making that object into an identical button matrix to
     * the button matrix btnm created in this function.
     */
    return btnm;
}