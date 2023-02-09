#include "main.h"
#include "pros/apix.h"

// LVGL objects
lv_obj_t *pg_main;
lv_obj_t *pg_auton;
lv_obj_t *btn_main_to_auton;
lv_obj_t *btn_auton_to_main;
lv_obj_t *btnm_auton_select;
lv_obj_t *lbl;
lv_style_t main_style;
lv_style_t btn_style;

const char *auton_display_map[] = {"Skills - Best",
                                   "Skills - Realistic",
                                   "\n",
                                   "Match - Best",
                                   "Match - Realistic",
                                   "\n",
                                   "Test",
                                   "None",
                                   ""};

static lv_res_t show_auton_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, true);
    lv_obj_set_hidden(pg_auton, false);
    return LV_RES_OK;
}
static lv_res_t show_main_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, false);
    lv_obj_set_hidden(pg_auton, true);
    return LV_RES_OK;
}

static lv_res_t auton_select(lv_obj_t *btnm);

/**
 * Runs initialization code.This occurs as soon as the program is started.
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // GUI init

    lv_style_copy(&main_style, &lv_style_plain);

    main_style.body.main_color = LV_COLOR_HEX(0x041a31);
    main_style.body.grad_color = main_style.body.main_color;
    main_style.text.color = LV_COLOR_HEX(0xdfdfdf);

    lv_style_copy(&btn_style, &main_style);

    btn_style.body.border.color = LV_COLOR_HEX(0xf8c649);
    btn_style.body.border.width = 2;
    btn_style.body.radius = 30;

    pg_main = lv_page_create(lv_scr_act(), NULL);
    lv_obj_set_size(pg_main, 480, 240);
    lv_obj_align(pg_main, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_page_set_style(pg_main, LV_PAGE_STYLE_BG, &main_style);

    pg_auton = lv_page_create(lv_scr_act(), NULL);
    lv_obj_set_size(pg_auton, 480, 240);
    lv_obj_align(pg_auton, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_page_set_style(pg_auton, LV_PAGE_STYLE_BG, &main_style);

    lv_obj_set_hidden(pg_auton, true);

    btn_main_to_auton = lv_btn_create(pg_main, NULL);
    lv_btn_set_action(btn_main_to_auton, LV_BTN_ACTION_CLICK, show_auton_pg);
    lv_obj_align(btn_main_to_auton, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
    lv_btn_set_style(btn_main_to_auton, LV_BTN_STYLE_REL, &btn_style);

    lbl = lv_label_create(btn_main_to_auton, NULL);
    lv_obj_align(lbl, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(lbl, "Auton Menu");

    btn_auton_to_main = lv_btn_create(pg_auton, NULL);
    lv_btn_set_action(btn_auton_to_main, LV_BTN_ACTION_CLICK, show_main_pg);
    lv_obj_align(btn_auton_to_main, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
    lv_btn_set_style(btn_auton_to_main, LV_BTN_STYLE_REL, &btn_style);

    lbl = lv_label_create(btn_auton_to_main, NULL);
    lv_obj_align(lbl, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(lbl, "Main Menu");

    btnm_auton_select = lv_btnm_create(pg_auton, NULL);
    lv_btnm_set_map(btnm_auton_select, auton_display_map);
    lv_obj_align(btnm_auton_select, NULL, LV_ALIGN_CENTER, 40, 0);
    lv_obj_set_size(btnm_auton_select, 300, 180);

    lv_obj_report_style_mod(&main_style);
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
