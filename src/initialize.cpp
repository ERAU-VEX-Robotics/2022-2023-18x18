#include "main.h"
#include "pros/apix.h"

// LVGL objects
lv_obj_t *pg_main;
lv_obj_t *pg_auton;
lv_obj_t *btn_main_to_auton;
lv_obj_t *btn_auton_to_main;
lv_obj_t *btnm_auton_select;
lv_obj_t *lbl;

static lv_res_t show_auton_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, false);
    lv_obj_set_hidden(pg_auton, true);
    return LV_RES_OK;
}
static lv_res_t show_main_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, true);
    lv_obj_set_hidden(pg_auton, false);
    return LV_RES_OK;
}

/**
 * Runs initialization code.This occurs as soon as the program is started.
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // GUI init
    pg_main = lv_page_create(lv_scr_act(), NULL);
    pg_auton = lv_page_create(lv_scr_act(), NULL);

    lv_obj_set_hidden(pg_auton, true);

    btn_main_to_auton = lv_btn_create(pg_main, NULL);
    lv_btn_set_action(btn_main_to_auton, LV_BTN_ACTION_CLICK, show_auton_pg);

    btn_auton_to_main = lv_btn_create(pg_auton, NULL);
    lv_btn_set_action(btn_auton_to_main, LV_BTN_ACTION_CLICK, show_main_pg);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
