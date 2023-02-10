#include "gui.h"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_label.h"
#include "string.h"

// LVGL objects
lv_obj_t *pg_main;
lv_obj_t *pg_auton;
lv_obj_t *btn_main_to_auton;
lv_obj_t *btn_auton_to_main;
lv_obj_t *btnm_auton_select;
lv_obj_t *lbl;
lv_style_t main_style;
lv_style_t btn_style;

enum auton auton_id = none;

lv_res_t show_auton_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, true);
    lv_obj_set_hidden(pg_auton, false);
    return LV_RES_OK;
}
lv_res_t show_main_pg(lv_obj_t *btn) {
    lv_obj_set_hidden(pg_main, false);
    lv_obj_set_hidden(pg_auton, true);
    return LV_RES_OK;
}

const char *auton_display_map[] = {"Skills - Best",
                                   "Skills - Realistic",
                                   "\n",
                                   "Match - Best",
                                   "Match - Realistic",
                                   "\n",
                                   "Test",
                                   "None",
                                   ""};

lv_res_t auton_select_action(lv_obj_t *btnm, const char *text) {
    if (strcmp(text, auton_display_map[0])) {
        auton_id = skills_best;
        lv_label_set_text(lbl, text);
    } else if (strcmp(text, auton_display_map[1])) {
        auton_id = skills_real;
        lv_label_set_text(lbl, text);
    } else if (strcmp(text, auton_display_map[3])) {
        auton_id = match_best;
        lv_label_set_text(lbl, text);
    } else if (strcmp(text, auton_display_map[4])) {
        auton_id = match_real;
        lv_label_set_text(lbl, text);
    } else if (strcmp(text, auton_display_map[6])) {
        auton_id = test;
        lv_label_set_text(lbl, text);
    } else {
        auton_id = none;
        lv_label_set_text(lbl, text);
    }
    return LV_RES_OK;
}

void gui_init() {

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

    lv_btnm_set_action(btnm_auton_select, auton_select_action);

    lbl = lv_label_create(pg_auton, NULL);
    lv_obj_align(lbl, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
    lv_label_set_text(lbl, "None");
}
