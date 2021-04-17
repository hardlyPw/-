# include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

SceneID startScene, background, HD, ND, SD;
ObjectID start, end, money_art, turn, X, X2, X3, money_change,money_change2, howbox, how,arrow,
one, two, three, four, five, six, seven, eight, nine, zero, //일의 자리
one_0, two_0, three_0, four_0, five_0, six_0, seven_0, eight_0, nine_0, zero_0, //십의자리
one_00, zero_00, two_00,//백의 자리
tuza_0, tuza_00, tuza_10, tuza_20, tuza_30, tuza_40, tuza_50, tuza_60, tuza_70, // 투자 금액 보여주기
plus_nexen, minus_nexen, plus_koogle, minus_koogle, plus_nanosoft, minus_nanosoft, //플러스 마이너스
nexen, koogle, nanosoft,//기업 간판
day_1, day_2, day_3, //1일차, 2일차, 3일차
ban_1, ban_3,//상한선 표시
minus_check, have_check,
R_nexen, R_koogle, R_nano, R_nexen3, R_koogle3, R_nano3,//랜덤함수 
news_button_1, news_button_2, news_button_3, //뉴스버튼
news_nexen_1G, news_nexen_1B, news_nexen_2G, news_nexen_2B, news_nexen_3, news_nano_1G, news_nano_1B, news_nano_2G, news_nano_2B, news_nano_3, news_koogle_1G, news_koogle_1B, news_koogle_2G, news_koogle_2B, news_koogle_3,
nexen_up, nexen_down, koogle_up, koogle_down, nano_up, nano_down, nexen3, koogle3, nano3, nexen3G, koogle3B, nano3G; //투자 결과

int money = 50, tuza = 0, tuza_nexen = 0, tuza_koogle = 0, tuza_nanosoft = 0, day_check=1;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {

    ObjectID object = createObject(image);
    
    locateObject(object, scene, x, y);

    if (shown) {
        showObject(object);
    }
    return object;
}
void random_def() {
    srand((unsigned int)time(NULL));
    R_nexen = rand() % 2;
    R_koogle = rand() % 2;
    R_nano = rand() % 2;
    R_nexen3 = rand() % 100;
    R_koogle3 = rand() % 100;
    R_nano3 = rand() % 100;
}



void hide() { //돈 1의자리 숨기기
    hideObject(zero);
    hideObject(one);
    hideObject(two);
    hideObject(three);
    hideObject(four);
    hideObject(five);
    hideObject(six);
    hideObject(seven);
    hideObject(eight);
    hideObject(nine);
}
void hide_1() {//돈 10의자리 숨기기
    hideObject(zero_0);
    hideObject(one_0);
    hideObject(two_0);
    hideObject(three_0);
    hideObject(four_0);
    hideObject(five_0);
    hideObject(six_0);
    hideObject(seven_0);
    hideObject(eight_0);
    hideObject(nine_0);
}
void hide_2() {//돈 100의 자리 숨기기
    hideObject(zero_00);
    hideObject(one_00);
    hideObject(two_00);
}

void hide_news_button() {//뉴스보는 버튼 숨기기
    hideObject(news_button_1);
    hideObject(news_button_2);
    hideObject(news_button_3);
}
void show_news_button() {//뉴스보는 버튼 보이기
    showObject(news_button_1);
    showObject(news_button_2);
    showObject(news_button_3);
}
void hide_news() {//뉴스 숨기기
    hideObject(news_koogle_1B);
    hideObject(news_koogle_1G);
    hideObject(news_koogle_2B);
    hideObject(news_koogle_2G);
    hideObject(news_koogle_3);
    hideObject(news_nexen_1B);
    hideObject(news_nexen_1G);
    hideObject(news_nexen_2B);
    hideObject(news_nexen_2G);
    hideObject(news_nexen_3);
    hideObject(news_nano_1B);
    hideObject(news_nano_1G);
    hideObject(news_nano_2B);
    hideObject(news_nano_2G);
    hideObject(news_nano_3);
}
void hide_change() {
    hideObject(money_change);
    hideObject(X2);
    hideObject(nexen_up);
    hideObject(nexen_down);
    hideObject(koogle_up);
    hideObject(koogle_down);
    hideObject(nano_up);
    hideObject(nano_down);
}
void money_C() { // 돈 1의자리 계산해서 보이기
    if (money % 10 == 0) {
        hide();
        showObject(zero);
    }
    else if (money % 10 == 1) {
        hide();
        showObject(one);
    }
    else if (money % 10 == 2) {
        hide();
        showObject(two);
    }
    else if (money % 10 == 3) {
        hide();
        showObject(three);
    }
    else if (money % 10 == 4) {
        hide();
        showObject(four);
    }
    else if (money % 10 == 5) {
        hide();
        showObject(five);
    }
    else if (money % 10 == 6) {
        hide();
        showObject(six);
    }
    else if (money % 10 == 7) {
        hide();
        showObject(seven);
    }
    else if (money % 10 == 8) {
        hide();
        showObject(eight);
    }
    else if (money % 10 == 9) {
        hide();
        showObject(nine);
    }
}
void money_C10() { //돈 10의자리 계산해서 보이기
    
    if (money / 10 == 0 or money / 10 == 10) {
        hide_1();
        showObject(zero_0);
    }
    else if (money / 10 == 1 or money / 10 == 11) {
        hide_1();
        showObject(one_0);
    }
    
    else if (money / 10 == 2 or money / 10 == 12) {
        hide_1();
        showObject(two_0);
    }
    else if (money / 10 == 3 or money / 10 == 13) {
        hide_1();
        showObject(three_0);
    }
    else if (money / 10 == 4 or money / 10 == 14) {
        hide_1();
        showObject(four_0);
    }
    else if (money / 10 == 5 or money / 10 == 15) {
        hide_1();
        showObject(five_0);
    }
    else if (money / 10 == 6 or money / 10 == 16) {
        hide_1();
        showObject(six_0);
    }
    else if (money / 10 == 7 or money / 10 == 17) {
        hide_1();
        showObject(seven_0);
    }
    else if (money / 10 == 8 or money / 10 == 18) {
        hide_1();
        showObject(eight_0);
    }
    else if (money / 10 == 9 or money / 10 == 19) {
        hide_1();
        showObject(nine_0);
    }
}

void money_C100() { //돈 100의자리 계산해서 보이기
    if (money >= 100 and money<200) {
        showObject(one_00);
        hideObject(zero_00);
        hideObject(two_00);
    }
    else if (money < 100) {
        showObject(zero_00);
        hideObject(one_00);
        hideObject(two_00);
    }
    else if (money >= 200) {
        showObject(two_00);
        hideObject(one_00);
        hideObject(zero_00);
    }
}
void hide_tuza() { //투자금액 숨기기
    hideObject(tuza_00);
    hideObject(tuza_10);
    hideObject(tuza_20);
    hideObject(tuza_30);
    hideObject(tuza_40);
    hideObject(tuza_50);
    hideObject(tuza_60);
    hideObject(tuza_70);
}
void hide_PMbutton() {
    hideObject(plus_koogle);
    hideObject(plus_nanosoft);
    hideObject(plus_nexen);
    hideObject(minus_nexen);
    hideObject(minus_koogle);
    hideObject(minus_nanosoft);
}
void show_PMbutton(){ //플러스 마이너스 버튼 보이기
    showObject(plus_koogle);
    showObject(plus_nanosoft);
    showObject(plus_nexen);
    showObject(minus_nexen);
    showObject(minus_koogle);
    showObject(minus_nanosoft);
}
void tuza_C() { //투자금액 확인
    if (tuza == 0) {
        hide_tuza();
        showObject(tuza_00);
    }
    else if (tuza == 10) {
        hide_tuza();
        showObject(tuza_10);
    }
    else if (tuza == 20) {
        hide_tuza();
        showObject(tuza_20);
    }
    else if (tuza == 30) {
        hide_tuza();
        showObject(tuza_30);
    }
    else if (tuza == 40) {
        hide_tuza();
        showObject(tuza_40);
     }
    else if (tuza == 50) {
        
        hide_tuza();
        showObject(tuza_50);
    }
    else if (tuza == 60) {
        
        hide_tuza();
        showObject(tuza_60);
    }
    else if (tuza == 70) {
       
        hide_tuza();
        showObject(tuza_70);
    }
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == start) {
        enterScene(background);
        money_C();
        money_C10();
        money_C100();
        random_def();
    }
    else if (object == end) {
        endGame();
    }
    else if (object == howbox) {
        showObject(how);
    }
    else if (object == plus_nexen) {
        if (day_check == 1 or day_check == 2) {
            if (tuza >= 0 and tuza < 50 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_nexen = tuza_nexen + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_koogle);
                hideObject(minus_koogle);
                hideObject(plus_nanosoft);
                hideObject(minus_nanosoft);
            }
        }
        else if (day_check == 3) {
            if (tuza >= 0 and tuza < 100 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_nexen = tuza_nexen + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_koogle);
                hideObject(minus_koogle);
                hideObject(plus_nanosoft);
                hideObject(minus_nanosoft);
            }
        }
        
        
    }
    else if (object == minus_nexen) {
        if (day_check == 1 or day_check == 2) {
            if (tuza > 0 and tuza <= 50) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_nexen = tuza_nexen - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_nexen == 0) {
                    showObject(plus_koogle);
                    showObject(minus_koogle);
                    showObject(plus_nanosoft);
                    showObject(minus_nanosoft);
                }
            }
        }
        else if (day_check == 3) {
            if (tuza > 0 and tuza <= 100) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_nexen = tuza_nexen - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_nexen == 0) {
                    showObject(plus_koogle);
                    showObject(minus_koogle);
                    showObject(plus_nanosoft);
                    showObject(minus_nanosoft);
                }
            }
        }
       
    }
    else if (object == plus_koogle) {
        if (day_check == 1 or day_check == 2) {
            if (tuza >= 0 and tuza < 50 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_koogle = tuza_koogle + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_nexen);
                hideObject(minus_nexen);
                hideObject(plus_nanosoft);
                hideObject(minus_nanosoft);
            }
        }
        else if (day_check == 3) {
            if (tuza >= 0 and tuza < 100 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_koogle = tuza_koogle + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_nexen);
                hideObject(minus_nexen);
                hideObject(plus_nanosoft);
                hideObject(minus_nanosoft);
            }
        }
        
        
    }
    else if (object == minus_koogle) {
        if (day_check == 1 or day_check == 2) {
            if (tuza > 0 and tuza <= 50) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_koogle = tuza_koogle - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_koogle == 0) {
                    showObject(plus_nexen);
                    showObject(minus_nexen);
                    showObject(plus_nanosoft);
                    showObject(minus_nanosoft);
                }
            }
        }
        else if (day_check == 3) {
            if (tuza > 0 and tuza <= 100) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_koogle = tuza_koogle - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_koogle == 0) {
                    showObject(plus_nexen);
                    showObject(minus_nexen);
                    showObject(plus_nanosoft);
                    showObject(minus_nanosoft);
                }
            }
        }
    }
    else if (object == plus_nanosoft) {
        if (day_check == 1 or day_check == 2) {
            if (tuza >= 0 and tuza < 50 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_nanosoft = tuza_nanosoft + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_nexen);
                hideObject(minus_nexen);
                hideObject(plus_koogle);
                hideObject(minus_koogle);
            }
        }
        else if (day_check == 3) {
            if (tuza >= 0 and tuza < 100 and money >= 10) {
                money = money - 10;
                tuza = tuza + 10;
                tuza_nanosoft = tuza_nanosoft + 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                hideObject(plus_nexen);
                hideObject(minus_nexen);
                hideObject(plus_koogle);
                hideObject(minus_koogle);
            }
        }
    }
    else if (object == minus_nanosoft) {
        if (day_check == 1 or day_check == 2) {
            if (tuza > 0 and tuza <= 50) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_nanosoft = tuza_nanosoft - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_nanosoft == 0) {
                    showObject(plus_koogle);
                    showObject(minus_koogle);
                    showObject(plus_nexen);
                    showObject(minus_nexen);
                }
            }
        }
        else if (day_check == 3) {
            if (tuza > 0 and tuza <= 100) {
                money = money + 10;
                tuza = tuza - 10;
                tuza_nanosoft = tuza_nanosoft - 10;
                money_C();
                money_C10();
                money_C100();
                tuza_C();
                if (tuza_nanosoft == 0) {
                    showObject(plus_koogle);
                    showObject(minus_koogle);
                    showObject(plus_nexen);
                    showObject(minus_nexen);
                }
            }
        }
    }
    else if (object == news_button_1) {
    showObject(X);
    hide_news_button();
    if (day_check == 1) {
        if (R_nexen == 0) {
            showObject(news_nexen_1B);
        }
        else {
            showObject(news_nexen_1G);
        }
    }
    else if (day_check == 2) {
        if (R_nexen == 0) {
            showObject(news_nexen_2B);
        }
        else {
            showObject(news_nexen_2G);
        }
    }
    else if (day_check == 3) {
            showObject(news_nexen_3);      
    }
        
    }
    else if (object == news_button_2) {
    showObject(X);
    hide_news_button();
    if (day_check == 1) {
        if (R_koogle == 0) {
            showObject(news_koogle_1B);
        }
        else {
            showObject(news_koogle_1G);
        }
    }
    else if (day_check == 2) {
        if (R_koogle == 0) {
            showObject(news_koogle_2B);
        }
        else {
            showObject(news_koogle_2G);
        }
    }
    else if (day_check == 3) {
        showObject(news_koogle_3);
    }
    }
    else if (object == news_button_3) {
    showObject(X);
    hide_news_button();
    if (day_check == 1) {
        if (R_nano == 0) {
            showObject(news_nano_1B);
        }
        else {
            showObject(news_nano_1G);
        }
    }
    else if (day_check == 2) {
        if (R_nano == 0) {
            showObject(news_nano_2B);
        }
        else {
            showObject(news_nano_2G);
        }
    }
    else if (day_check == 3) {
        showObject(news_nano_3);
    }
    }
    else if (object == X) {
    show_news_button();
    hide_news();
    hideObject(X);
    }
    else if (object == X2) {
    hide_change();
}
    else if (object == turn) {
    
        if (day_check == 1) {
            hide();
            hide_1();
            hide_2();
            show_PMbutton();
            hideObject(day_1);
            showObject(day_2);
            showObject(X2);
            showObject(money_change);
        }
        else if (day_check == 2) {
            hide();
            hide_1();
            hide_2();
            show_PMbutton();
            hideObject(day_2);
            showObject(day_3);
            hideObject(ban_1);
            showObject(ban_3);      
            showObject(X2);
            showObject(money_change);
        }
        if (day_check != 3) {
            if (tuza_nanosoft > 0) {
                if (R_nano == 1) {
                    money = money + tuza_nanosoft * 1.5;
                }
                else if (R_nano == 0) {
                    money = money + tuza_nanosoft * 0.5;
                }
            }
            else if (tuza_nexen > 0) {
                if (R_nexen == 1) {
                    money = money + tuza_nexen * 1.5;
                }
                else if (R_nexen == 0) {
                    money = money + tuza_nexen * 0.5;
                }
            }
            else if (tuza_koogle) {
                if (R_koogle == 1) {
                    money = money + tuza_koogle * 1.5;
                }
                else if (R_koogle == 1) {
                    money = money + tuza_koogle * 0.5;
                }
            }
            if (R_nexen == 1) showObject(nexen_up);
            else showObject(nexen_down);
            if (R_koogle == 1) showObject(koogle_up);
            else showObject(koogle_down);
            if (R_nano == 1) showObject(nano_up);
            else showObject(nano_down);
        }
        else if (day_check==3){
            hide_1();
            hide_news_button();
            hide_PMbutton();
            showObject(arrow);
            showObject(money_change2);
            hideObject(ban_3);
            hideObject(nanosoft);
            if (R_nexen3 > 40) showObject(nexen3G);
            else showObject(nexen3);
            if (R_koogle3 > 80) showObject(koogle3);
            else showObject(koogle3B);
            if (R_nano3 > 20) showObject(nano3G);
            else showObject(nano3);

            if (tuza_nexen > 0) {
                if (R_nexen3 > 40) {
                    money = money + tuza_nexen * 2.0;
                }
                else if (R_nexen <= 40) {
                    money = money + tuza_nexen * 0.5;
                }
            }
            else if (tuza_koogle > 0) {
                if (R_koogle3 > 80) {
                    money = money + tuza_koogle * 2.5;
                }
                else if (R_koogle3 <= 80) {
                    money = money + tuza_koogle * 0.1;
                }
            }
            else if (tuza_nanosoft > 0) {
                if (R_nano3 > 20) {
                    money = money + tuza_nanosoft * 1.8;
                }
                else if (R_nano3 <= 20) {
                    money = money + tuza_nanosoft * 0.7;
                }
            }

        }
        
        money_C();
        money_C10();
        money_C100();    
        random_def();
        tuza = 0;
        tuza_nanosoft = 0;
        tuza_nexen = 0;
        tuza_koogle = 0;
        tuza_C();
        day_check = day_check + 1;
    }
    else if (object == arrow) {
        if (money <= 50) {
            enterScene(SD);
            showMessage("난 결국 돈을 많이 벌지 못했다..(새드엔딩)");
        }
        else if (money > 50 and money <= 150) {
            enterScene(ND);
            showMessage("그럭저럭 돈을 잘 번것 같다...(노말엔딩)");
        }
        else {
            enterScene(HD);
            showMessage("당신은 투자의 귀재! 돈을 정말 많이 벌었다! (해피엔딩)");
        }

    }
}


int main() {
    setMouseCallback(mouseCallback);
	startScene = createScene("주식게임", "시작화면.png");
    background = createScene("주식게임", "배경.png");
    HD = createScene("해피엔딩", "HD.jpg");
    ND = createScene("노말엔딩", "ND.jpg");
    SD = createScene("새드엔딩", "SD.jpg");
    turn = createObject("턴.png", background, 1300, 350, true);
    money_art = createObject("동전.png", background, 420, 630, true);
    scaleObject(money_art, 0.3f);
    have_check = createObject("have.png", background, 600, 630, true);
    X = createObject("X.png", background, 290, 400, false);
    howbox = createObject("howbox.png", startScene, 250, 50, true);
    how = createObject("how.png", startScene, 300, 200, false);
    arrow = createObject("끝.png", background, 1200, 100, false); //결과 보는 화살표
    // 마이너스기호
    minus_check = createObject("마이너스기호.png", background, 210, 450, false);
    //돈 일의자리
    one = createObject("1.png", background, 700, 640, false);
    two = createObject("2.png", background, 700, 640, false);
    three = createObject("3.png", background, 700, 640, false);
    four = createObject("4.png", background, 700, 640, false);
    five = createObject("5.png", background, 700, 640, false);
    six = createObject("6.png", background, 700, 640, false);
    seven = createObject("7.png", background, 700, 640, false);
    eight = createObject("8.png", background, 700, 640, false);
    nine = createObject("9.png", background, 700, 640, false);
    zero = createObject("0.png", background, 700, 640, false);
    // 돈 십의자리
    one_0 = createObject("10.png", background, 665, 641, false);
    two_0 = createObject("20.png", background, 670, 640, false);
    three_0 = createObject("30.png", background, 670, 640, false);
    four_0 = createObject("40.png", background, 670, 640, false);
    five_0 = createObject("50.png", background, 665, 640, false);
    six_0 = createObject("60.png", background, 670, 640, false);
    seven_0 = createObject("70.png", background, 670, 640, false);
    eight_0 = createObject("80.png", background, 670, 640, false);
    nine_0 = createObject("90.png", background, 670, 640, false);
    zero_0 = createObject("00.png", background, 670, 640, false);
    // 돈 백의자리
    one_00 = createObject("100.png", background, 633, 642, false);
    zero_00 = createObject("000.png", background, 633, 642, true);
    two_00 = createObject("2.png", background, 633, 642, false);
    //덧셈 뺄셈
    plus_nexen = createObject("더하기.png", background, 450, 400, true);
    minus_nexen = createObject("빼기.png", background, 550, 400, true);
    plus_koogle = createObject("더하기.png", background, 730, 400, true);
    minus_koogle = createObject("빼기.png", background, 830, 400, true);
    plus_nanosoft = createObject("더하기.png", background, 1050, 400, true);
    minus_nanosoft = createObject("빼기.png", background, 1150, 400, true);
    // 기업
    nexen = createObject("nexen.png", background, 400, 500, true);
    scaleObject(nexen, 0.3f);
    koogle = createObject("koogle.png", background, 700, 530, true);
    scaleObject(koogle, 0.4f);
    nanosoft = createObject("nanosoft.png", background, 1000, 500, true);
    scaleObject(nanosoft, 0.4f);

    //요일
    day_1 = createObject("1주차.png", background, 230, 700, true);
    day_2 = createObject("2주차.png", background, 230, 700, false);
    day_3 = createObject("3주차.png", background, 230, 700, false);

    //상한선
    ban_1 = createObject("1일차상한선.png", background, 200, 100, true);
    ban_3 = createObject("3일차상한선.png", background, 250, 100, false);
    // 투자 금액
    tuza_0 = createObject("0.png", background, 1000, 645, true);
    tuza_00 = createObject("0.png", background, 950, 645, false);
    tuza_10 = createObject("1.png", background, 950, 645, false);
    tuza_20 = createObject("2.png", background, 950, 645, false);
    tuza_30 = createObject("3.png", background, 950, 645, false);
    tuza_40 = createObject("4.png", background, 950, 645, false);
    tuza_50 = createObject("5.png", background, 950, 645, false);
    tuza_60 = createObject("6.png", background, 950, 645, false);
    tuza_70 = createObject("7.png", background, 950, 645, false);

    //뉴스
    news_koogle_1B = createObject("1_koogle_B.png", background, 350, 100, false);
    news_koogle_2B = createObject("2_koogle_B.png", background, 350, 100, false);
    news_koogle_1G = createObject("1_koogle_G.png", background, 350, 100, false);
    news_koogle_2G = createObject("2_koogle_G.png", background, 350, 100, false);
    news_koogle_3 = createObject("3_koogle.png", background, 350, 100, false);
    news_nexen_1B = createObject("1_nexen_B.png", background, 350, 100, false);
    news_nexen_1G = createObject("1_nexen_G.png", background, 350, 100, false);
    news_nexen_2B = createObject("2_nexen_B.png", background, 350, 100, false);
    news_nexen_2G = createObject("2_nexen_G.png", background, 350, 100, false);
    news_nexen_3 = createObject("3_nexen.png", background, 350, 100, false);
    news_nano_1B = createObject("1_nano_B.png", background, 350, 100, false);
    news_nano_1G = createObject("1_nano_G.png", background, 350, 100, false);
    news_nano_2B = createObject("2_nano_B.png", background, 350, 100, false);
    news_nano_2G = createObject("2_nano_G.png", background, 370, 100, false);
    news_nano_3 = createObject("3_nano.png", background, 350, 100, false);
    scaleObject(news_koogle_1B, 1.1f);
    scaleObject(news_koogle_2B, 1.1f);
    scaleObject(news_koogle_1G, 1.1f);
    scaleObject(news_koogle_2G, 1.1f);
    scaleObject(news_koogle_3, 1.1f);
    scaleObject(news_nano_1B, 1.1f);
    scaleObject(news_nano_1G, 1.1f);
    scaleObject(news_nano_2G, 1.1f);
    scaleObject(news_nano_2B, 1.1f);
    scaleObject(news_nano_3, 1.1f);
    scaleObject(news_nexen_1B, 1.1f);
    scaleObject(news_nexen_1G, 1.1f);
    scaleObject(news_nexen_2B, 1.1f);
    scaleObject(news_nexen_2G, 1.1f);
    scaleObject(news_nexen_3, 1.1f);

    news_button_1 = createObject("news_button.png", background, 410, 250, true);
    news_button_2 = createObject("news_button.png", background, 710, 250, true);
    news_button_3 = createObject("news_button.png", background, 1010, 250, true);
    //변동가 확인
    money_change = createObject("변동사항.png", background, 450, 80, false);
    money_change2 = createObject("변동사항2.png", background, 350, 80, false);
    nexen_up = createObject("넥슨증가.png", background, 500, 300, false);
    nexen_down = createObject("넥슨감소.png", background, 500, 300, false);
    koogle_up = createObject("쿠글증가.png", background, 750, 300, false);
    koogle_down = createObject("쿠글감소.png", background, 750, 300, false);
    nano_up = createObject("나노소프트증가.png", background, 1000, 300, false);
    nano_down = createObject("나노소프트감소.png", background, 1000, 300, false);
    nexen3 = createObject("낵슨3.png", background, 360, 450, false);
    koogle3 = createObject("쿠글3.png", background, 360, 250, false);
    nano3 = createObject("나노소프트3.png", background, 360, 100, false);
    nexen3G = createObject("낵슨3G.png", background, 360, 450, false);
    koogle3B = createObject("쿠글3B.png", background, 360, 350, false);
    nano3G = createObject("나노3G.png", background, 360, 100, false);
    
    X2 = createObject("X.png", background, 380, 580, false);
    start = createObject("start.png", startScene, 100, 100, true);
    end = createObject("end.png", startScene, 100, 50, true);
	startGame(startScene);


}