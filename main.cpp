#include <iostream>
#include "Option.h"
#include "CPrint.h"
#include <windows.h>
#include <string>
#include "Cinema.h"
#include "CZone.h"
#include "CPerson_Info.h"
#include "CMovie_Info.h"
#include "CAnalyze.h"
#include <fstream>
#include <vector>
using namespace std;

void fileRead(vector<string>& v, ifstream& fin) {
    string line;
    while (getline(fin, line)) {
        v.push_back(line);
    }
}

int main() {

    CZone zones[ZONE_NUM] = { CZone(SEAT_ROW_NUM, SEAT_COL_NUM), CZone(SEAT_ROW_NUM, SEAT_COL_NUM),
                           CZone(SEAT_ROW_NUM, SEAT_COL_NUM), CZone(SEAT_ROW_NUM, SEAT_COL_NUM), };


    CMovie_Info movies[MOVIES_NUM] = { CMovie_Info("¾îº¥Á®½º", 6), CMovie_Info("¼Ò¿ï", 6), CMovie_Info("±¤ÇØ", 6), CMovie_Info("¾î¹Ù¿ô Å¸ÀÓ",6) };

    std::string movie_title[MOVIES_NUM];
    for (int i = 0; i < MOVIES_NUM; i++) {
        movie_title[i] = movies[i].get_movie_name();
    }

    

    schedule_table daily_movie[MOVIES_NUM][SCHEDULE_NUM] = { {schedule_table(0, schedule::MORNING_1), schedule_table(0, schedule::MORNING_2), schedule_table(0, schedule::MORNING_3), schedule_table(0, schedule::AFTERNOON_1), schedule_table(0, schedule::AFTERNOON_2), schedule_table(0, schedule::AFTERNOON_3)},
                                                           {schedule_table(1, schedule::MORNING_1), schedule_table(1, schedule::MORNING_2), schedule_table(1, schedule::MORNING_3), schedule_table(1, schedule::AFTERNOON_1), schedule_table(1, schedule::AFTERNOON_2), schedule_table(1, schedule::AFTERNOON_3),},
                                                           {schedule_table(2, schedule::MORNING_1), schedule_table(2, schedule::MORNING_2), schedule_table(2, schedule::MORNING_3), schedule_table(2, schedule::AFTERNOON_1), schedule_table(2, schedule::AFTERNOON_2), schedule_table(2, schedule::AFTERNOON_3),},
                                                           {schedule_table(3, schedule::MORNING_1), schedule_table(3, schedule::MORNING_2), schedule_table(3, schedule::MORNING_3), schedule_table(3, schedule::AFTERNOON_1), schedule_table(3, schedule::AFTERNOON_2), schedule_table(3, schedule::AFTERNOON_3),},
    };
    
    for (int i = 0; i < MOVIES_NUM; i++) {
        for (int j = 0; j < SCHEDULE_NUM; j++) {
            movies[i].get_movie_schedule()[j].set_m_zone_num(daily_movie[i][j].get_m_zone_num());
            movies[i].get_movie_schedule()[j].set_m_movie_schedule(daily_movie[i][j].get_m_movie_schedule());
        }
    }
    
    for (int i = 0; i < MOVIES_NUM; i++) {
        for (int j = 0; j < SCHEDULE_NUM; j++) {
            int zone = daily_movie[i][j].m_zone_num;
            zones[zone].set_movie_info(daily_movie[i][j].m_movie_schedule, movie_title[i]);
        }
    }




    CPerson_Info people[PEOPLE_NUM];
    /*
    std::string names[PEOPLE_NUM] = { "°­±â¼ö","°­³²±Ô","°­´Ù¿¬","°­¼º·É","°­¼öÁø","°­Áö¿ø","°­ÇüÃ¢","°í¼®¿µ","°ø¼Ò¸í","°û¹ÎÀç",
                                   "±¸ÈñÅÂ","±Ç¼öÇö","±ÇÃ¶È£","±è°­»ê","±è±ÔÅÂ","±è±Ù¿ì","±è±âÇö","±èµµ¿í","±èµµÈÆ","±èµ¿¸í",
                                   "±èµ¿È¯","±è¸®¾Æ","±è¹Î°ü","±è¹ÎÁÖ","±è¹ÎÃ¶","±è»óÀ±","±è¼­¿¬","±è¼­¿µ","±è¼±µæ","±è¼º¹ü",
                                   "±è¼øÁØ","±è¿µ¶ô","±è¿ìÁ¤","±è¿ìÇü","±èÀºÁø","±èÁ¤¿í","±èÁ¤À±","±èÁÖ¿¬","±èÁö¼±","±èÁö¿µ",
                                   "±èÁö¿ì","±èÁöÇÑ","±èÁöÇö","±èÁøÇõ","±èÇüÁø","±èÈ£¿¬","±èÈ¿¸í","±èÈÖ¿µ","³²±Ý³»","³ëÀ¯Áø",
                                   "·ù±â¿Ï","·ùÇöÅÂ","¸íÈ£¼º","¹®º´½Â","¹Ú±¤È£","¹Ú±ÙÇü","¹ÚµµÇö","¹Úµ¿³è","¹Ú»óÇö","¹ÚÀ¯Á¤",
                                   "¹ÚÀºÇý","¹ÚÀç¼®","¹ÚÁ¦ÈÆ","¹ÚÂùÈ£","¹ÚÇý¹Î","¹èÁÖ¿¹","¹éÃ¢Çö","¼­À±¼®","¼­Á¤¹Î","¼®±âÀº",
                                   "¼±¿ìÀ±","¼ºÀÇÇö","¼ÕÈñÁø","¼Û±Ô¿µ","¼Û¹ÎÁö","¼ÛÃ¤Çö","½Åµ¿½Â","¾Èº´À±","¾È¼­¿µ","¾ÈÀ±Áö",
                                   "¾ÈÀ±Çý","¾çÈ¿ÁØ","¾çÈñÁÖ","¿©¹«ÇÑ","¿°°æÀº","¿À¹ÌÁø","¿ÀÀÎ¼º","¿ÀÀçÀÍ","¿ìÇõ»ó","À¯¹Ì¶ó",
                                   "À¯º´¼±","À¯¼ÖÁö","À¯¿ëÁØ","À¯Á¤½Ä","À¯Áö¼±","À¯È£¼±","À±±¹·Î","À±±â¾Ö","À±¿ø°Ç","À±ÈñÃ¶" };

    std::string phonenumber[PEOPLE_NUM] = { "01040737288", "01022830273", "01070534850", "01024545406", "01064343371",
                                         "01005162651", "01028025800", "01040481280", "01028167418", "01040708460",
                                         "01017125103", "01056444201", "01044164115", "01071165220", "01001531802",
                                         "01020407642", "01076336336", "01076472715", "01033883605", "01076566045",
                                         "01001768708", "01088006662", "01052616313", "01085830574", "01083453720",
                                         "01064372243", "01042357187", "01066364621", "01078838183", "01076528142",
                                         "01007600328", "01004871452", "01087552658", "01070344126", "01004683055",
                                         "01076750077", "01057384444", "01060456633", "01056066254", "01064353663",
                                         "01034273325", "01071003220", "01020206656", "01045563661", "01054751538",
                                         "01060700166", "01081545610", "01010868010", "01032882384", "01007424731",
                                         "01024722374", "01058365886", "01003525451", "01065136550", "01010221737",
                                         "01005134454", "01074681207", "01084464348", "01074470121", "01077280640",
                                         "01074586056", "01076160842", "01073833260", "01032263388", "01047607543",
                                         "01026521270", "01055880530", "01082282316", "01053661403", "01037412742",
                                         "01084242240", "01005335422", "01023721823", "01014108510", "01030885428",
                                         "01008781055", "01017738405", "01053584725", "01028443314", "01016307382",
                                         "01076187520", "01036018258", "01007787700", "01023318438", "01035213763",
                                         "01087247512", "01084464070", "01007235788", "01007247752", "01030680554",
                                         "01046746553", "01043282768", "01017457383", "01088715248", "01074813404",
                                         "01077804634", "01045766468", "01003858611", "01002132174", "01018616574" };

    bool gender[PEOPLE_NUM] = { 1,0,1,0,1,0,1,0,1,1,
                             1,1,1,1,1,0,0,0,0,0,
                             0,1,0,1,0,0,1,0,1,0,
                             0,1,1,0,1,0,1,0,1,0,
                             0,0,0,1,1,1,0,1,0,1,
                             1,0,0,1,0,0,1,1,1,0,
                             1,0,1,0,1,0,1,0,1,0,
                             0,1,0,1,0,1,0,1,0,1,
                             0,0,0,1,1,1,0,0,1,0,
                             1,0,1,0,1,0,1,0,1,1 };
    
    */
    //person info setting

    vector<string> aaa;
    ifstream fin("person.txt");
    if (!fin) {
        return 0;
    }

    fileRead(aaa, fin);
    fin.close();

    std::string copy;
    std::string name = "È«±æµ¿";
    std::string phonenumber = "01012345678";
    char gender;

    std::string *names=new string [PEOPLE_NUM];
    std::string *phonenumbers=new string [PEOPLE_NUM];
    bool *genders= new bool [PEOPLE_NUM];

    for (int i = 0; i < PEOPLE_NUM; i++) {
        copy = aaa[i];

        for (int j = 0; j < 3; j++) {
            name[j] = copy[j];
        }
        for (int k = 0; k < 11; k++) {
            phonenumber[k] = copy[k + 4];
        }
        gender = copy[16];

        names[i] = name;
        phonenumbers[i] = phonenumber;
        genders[i] = gender;
    }

    for (int i = 0; i < PEOPLE_NUM; i++) {
        people[i].setgender(genders[i]);
        people[i].setphonenumber(phonenumbers[i]);
        people[i].setname(names[i]);
    }

    int zone_count = 0, people_count = 0;
    for (int N = 0; N < ZONE_NUM; N++) {
        for (int M = 0; M < SCHEDULE_NUM; M++) {
            for (int k = 0; k < SEAT_ROW_NUM; k = k + 3) {
                for (int L = 0; L < SEAT_COL_NUM; L = L + 4) {
                    if (people_count < 24) {
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);       //24¸í±îÁö
                    }
                    else if (people_count == 24) {
                        zone_count++;
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);
                    }
                    else if (people_count < 48 && people_count>24) {
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);       //48¸í±îÁö
                    }
                    else if (people_count == 48) {
                        zone_count++;
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);
                    }
                    else if (people_count < 72 && people_count>48) {
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);       //72¸í±îÁö
                    }
                    else if (people_count == 72) {
                        zone_count++;
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);
                    }
                    else if (people_count < 96 && people_count>72) {
                        zones[zone_count].set_seat_info(k, L, M, people[people_count]);       //96¸í±îÁö
                    }
                    people_count++;
                }
            }
        }
    }
   

    CPerson_Info customer("ÀÓ¿¹¿ø", "01054462109", true, 50000);
    CReserve receptionist(zones, movies);
    CAnalyze status(zones, movies);
    Cinema cinema(zones, movies, people, customer, receptionist, movie_title, status);
    while (1) {
        cinema.m_chatbot.menu();
    }

    delete[] names;
    delete[] phonenumbers;
    delete[] genders;
    return 0;
}