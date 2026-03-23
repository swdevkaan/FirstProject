#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
void diyetfonksiyonu();
void vucuthesapfonksiyonu();
void ilerlemefonksiyonu();
void ilerlemefonksiyonu2();
void ornekprogram();
void aciklama();
void cikisfonksiyonu();

int main() {
    SetConsoleOutputCP(65001); // UTF-8 ÇIKIŞ
    SetConsoleCP(65001);       // UTF-8 GİRİŞ


    printf("\n================================================================||\n");
    printf("Okul                :Kahramanmaraş İstiklal Üniversitesi        ||\n");
    printf("Öğretim Üyesi       :Dr. Öğr. Üyesi İBRAHİM ARUK                ||\n");
    printf("Öğrenci Numarası    :25020091020                                ||\n");
    printf("Öğrenci İsim Soyisim:Mustafa Kaan Çelik                         ||\n");
    printf("Proje               :Fitness ve Beslenme Asistanı               ||\n");
    printf("================================================================||\n");
    printf("\n====================================================================================================================\n");
    printf("\n███████╗██ ████████╗███╗   ██╗███████╗███████╗███████╗   █████╗ ███████╗██╗███████╗████████╗ █████╗ ███╗   ██╗██╗");
    printf("\n██╔════╝██║╚══██╔══╝████╗  ██║██╔════╝██╔════╝██╔════╝  ██╔══██╗██╔════╝██║██╔════╝╚══██╔══╝██╔══██╗████╗  ██║██║");
    printf("\n█████╗  ██║   ██║   ██╔██╗ ██║█████╗  ███████╗███████╗  ███████║███████╗██║███████╗   ██║   ███████║██╔██╗ ██║██║");
    printf("\n██╔══╝  ██║   ██║   ██║╚██╗██║██╔══╝  ╚════██║╚════██║  ██╔══██║╚════██║██║╚════██║   ██║   ██╔══██║██║╚██╗██║██║");
    printf("\n██║     ██║   ██║   ██║ ╚████║███████╗███████║███████║  ██║  ██║███████║██║███████║   ██║   ██║  ██║██║ ╚████║██║");
    printf("\n╚═╝     ╚═╝   ╚═╝   ╚═╝  ╚═══╝╚══════╝╚══════╝╚══════╝  ╚═╝  ╚═╝╚══════╝╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝");
    printf("\n====================================================================================================================\n");

    while(1) {

        printf("\n============================================================\n");
        printf("           ***  Fitness ve Beslenme Asistanı  ***             \n");
        printf("============================================================\n");
        printf("1-Diyet Programi Belirleme\n");
        printf("2-BMI/BMR/BF Hesaplama\n");
        printf("3-Progressive Overload Hesaplama\n");
        printf("4-Maksimum Agirlik ve Antrenman Hacmi Hesaplama(1RM)\n");
        printf("5-Örnek Kuvvet ve Hipertrofi Programları \n");
        printf("6-Bilgi Paketi\n");
        printf("7-Cikis \n");
        printf("Seciminiz: ");

        int secim;
        scanf(" %d",&secim);
        switch (secim) {
            case 1:
                diyetfonksiyonu();
                continue;
            case 2:
                 vucuthesapfonksiyonu();
                continue;

                case 3:
                 ilerlemefonksiyonu();
                continue;

            case 4 :
                ilerlemefonksiyonu2();
                continue;

            case 5:
                 ornekprogram();
                continue;

            case 6:
                 aciklama();
                continue;

            case 7:
                printf("Çıkış yapılıyor...");

        }

        // YANLIŞ SAYI YAZILMASI DURUMUNDA DÖNGÜYE BAŞTAN DÖNME
        if (secim<=0 || secim>=8) {
            printf("Lütfen belirtilen aralığın içinde bir sayı seçiniz");
            continue;
        }
        break;

                return 0;
        }
    }

//CASE 1
void diyetfonksiyonu() {
    int kilo,ant,secenek;
    char cinsiyet;
    float proteinKal,karbKal,yagKal,yagGr,proteinGr,karbGr,bmr,kalori=0,su;

    printf("1-Kilo alma 2-Kiloyu koruma 3-Kilo verme ");
    scanf(" %d",&secenek);

    //BMR ÖĞRENME KISMI
    if (secenek==1) {
        printf("BMR Giriniz (Öğrenmek için Ana Menüye dönünüz(-1):");
        scanf(" %f",&bmr);
        if (bmr==-1) {
            printf("Ana Menüye Dönülüyor..");

        }

        //KİLO ALMA HESAPLAYICISI
        else {
            printf("Kilonuzu Giriniz:");
            scanf(" %d",&kilo);

            printf("Haftada Kaç Gün Antrenman yapıyorsunuz: ");
            scanf(" %d",&ant);
            //HAFTALIK ANTRENMAN SAYISINA GÖRE HESAPLAMA
            if (ant<=1) {
                kalori=(bmr*1.2)+500;

            }
            else if (ant>1 && ant<4) {
                kalori=(bmr*1.375)+500;
            }
            else if (ant>=4 && ant<6) {
                kalori=(bmr*1.55)+500;
            }
            else if (ant>=6 && ant<=7) {
                kalori=(bmr*1.725)+500;
            }
            //PROTEİN KARBONHİDRAT VE YAĞLARIN KALORİ VE GRAM CİNSİNDEN MAKRO HESABI
            /*KALORİ HESABI YAPILIRKEN YÜZDE VERİLMESİ İÇİN ÇARPANLAR VE KALORİLERİN BELİRLİ
            SAYILARA BÖLÜMÜYLE MAKRONUN HESAPLANMASI*/
            proteinKal=kalori*0.3;
            karbKal=kalori*0.5;
            yagKal=kalori*0.2;
            proteinGr=proteinKal/4;
            karbGr=karbKal/4;
            yagGr=yagKal/9;
            su=ceil(kilo*0.033);

            printf("\n========================================\n");
            printf("        GUNLUK BESIN DEGERLERI           \n");
            printf("========================================\n");
            printf("  Kalori        : %6.1f kcal\n", kalori);
            printf("  Protein       : %6.1f g\n", proteinGr);
            printf("  Karbonhidrat  : %6.1f g\n", karbGr);
            printf("  Yag           : %6.1f g\n", yagGr);
            printf("----------------------------------------\n");
            printf("  Kalsiyum      : 1000 mg\n");
            printf("  Sodyum        : 2000 mg\n");
            printf("  Magnezyum     : 350 mg\n");
            printf("----------------------------------------\n");
            printf("  Gunluk Su     : %6.1f litre\n", su);
            printf("========================================\n");


        }

        //KİLOYU KORUMA HESAPLAYICISI
    }
    if (secenek==2) {
        printf("BMR Giriniz (Öğrenmek için Ana Menüye Dönünüz(-1):");
        scanf(" %f",&bmr);
        if (bmr==-1) {
            printf("Ana Menüye Dönülüyor...");

        }
        else {
            printf("Kilonuzu Giriniz:");
            scanf(" %d",&kilo);

            printf("Haftada Kaç Gün Antrenman Yapıyorsunuz: ");
            scanf(" %d",&ant);
            if (ant<=1) {
                kalori=(bmr*1.2)+300;

            }
            else if (ant>1 && ant<4) {
                kalori=(bmr*1.375)+300;
            }
            else if (ant>=4 && ant<6) {
                kalori=(bmr*1.55)+300;
            }
            else if (ant>=6 && ant<=7) {
                kalori=(bmr*1.725)+300;
            }
            //PROTEİN KARBONHİDRAT VE YAĞLARIN KALORİ VE GRAM CİNSİNDEN MAKRO HESABI
            /*KALORİ HESABI YAPILIRKEN YÜZDE VERİLMESİ İÇİN ÇARPANLAR VE KALORİLERİN BELİRLİ
            SAYILARA BÖLÜMÜYLE MAKRONUN HESAPLANMASI*/
            proteinKal=kalori*0.4;
            karbKal=kalori*0.3;
            yagKal=kalori*0.3;
            proteinGr=proteinKal/4;
            karbGr=karbKal/4;
            yagGr=yagKal/9;
            su=ceil(kilo*0.033);

            printf("\n========================================\n");
            printf("        GUNLUK BESIN DEGERLERI           \n");
            printf("========================================\n");
            printf("  Kalori        : %6.1f kcal\n", kalori);
            printf("  Protein       : %6.1f g\n", proteinGr);
            printf("  Karbonhidrat  : %6.1f g\n", karbGr);
            printf("  Yag           : %6.1f g\n", yagGr);
            printf("----------------------------------------\n");
            printf("  Kalsiyum      : 1000 mg\n");
            printf("  Sodyum        : 2000 mg\n");
            printf("  Magnezyum     : 350 mg\n");
            printf("----------------------------------------\n");
            printf("  Gunluk Su     : %6.1f litre\n", su);
            printf("========================================\n");


        }

    }

    //KİLO VERME HESAPLAYICISI
    if (secenek==3) {
        printf("BMR Giriniz (Öğrenmek İçin Ana Menüye Dönünüz(-1):");
        scanf(" %f",&bmr);
        if (bmr==-1) {
            printf("Ana Menüye dönülüyor...");

        }
        else {
            printf("Kilonuzu Giriniz:");
            scanf(" %d",&kilo);

            printf("Haftada Kaç Gün Antrenman Yapıyorsunuz: ");
            scanf(" %d",&ant);
            if (ant<=1) {
                kalori=(bmr*1.2)+300;

            }
            else if (ant>1 && ant<4) {
                kalori=(bmr*1.375)+100;
            }
            else if (ant>=4 && ant<6) {
                kalori=(bmr*1.55)+100;
            }
            else if (ant>=6 && ant<=7) {
                kalori=(bmr*1.725)+100;
            }
            //PROTEİN KARBONHİDRAT VE YAĞLARIN KALORİ VE GRAM CİNSİNDEN MAKRO HESABI
            /*KALORİ HESABI YAPILIRKEN YÜZDE VERİLMESİ İÇİN ÇARPANLAR VE KALORİLERİN BELİRLİ
            SAYILARA BÖLÜMÜYLE MAKRONUN HESAPLANMASI*/
            proteinKal=kalori*0.4;
            karbKal=kalori*0.3;
            yagKal=kalori*0.3;
            proteinGr=proteinKal/4;
            karbGr=karbKal/4;
            yagGr=yagKal/9;
            su=ceil(kilo*0.033);

            printf("\n========================================\n");
            printf("        GUNLUK BESIN DEGERLERI           \n");
            printf("========================================\n");
            printf("  Kalori        : %6.1f kcal\n", kalori);
            printf("  Protein       : %6.1f g\n", proteinGr);
            printf("  Karbonhidrat  : %6.1f g\n", karbGr);
            printf("  Yag           : %6.1f g\n", yagGr);
            printf("----------------------------------------\n");
            printf("  Kalsiyum      : 1000 mg\n");
            printf("  Sodyum        : 2000 mg\n");
            printf("  Magnezyum     : 350 mg\n");
            printf("----------------------------------------\n");
            printf("  Gunluk Su     : %6.1f litre\n", su);
            printf("========================================\n");

        }
    }

}

//////////CASE 2
void  vucuthesapfonksiyonu() {
    int boyun,bel,secim3,boy3,kilo3,yas2;
    char cinsiyetsecim;
    float yagOrani,bmi,bmr1;
    printf("1-BMR 2-BMI 3-YAG ORANI");
    scanf("  %d",&secim3);

    printf("Yaşınızı giriniz: ");
    scanf("  %d",&yas2);

    printf("Cinsiyetinizi giriniz E/K : ");
    scanf("  %c",&cinsiyetsecim);

    printf("Boyunuzu giriniz(cm): ");
    scanf("  %d",&boy3);

    printf("Kilonuzu giriniz: ");
    scanf("  %d",&kilo3);

    printf("Boyun ve Bel Ölçülerini giriniz(cm): ");
    scanf("  %d %d",&boyun,&bel);

    if (secim3==1) {
        //CİNSİYET SEÇİM İÇİN KÜÇÜK BÜYÜK KONTROLÜ VE HER CİNSİYETE GÖRE HESAP KOŞULU
        if (cinsiyetsecim == 'E'||cinsiyetsecim=='e') {
            bmr1 = (10 * kilo3) + (6.25 * boy3) - (5 * yas2) + 5;
        }
        else if (cinsiyetsecim == 'K'||cinsiyetsecim=='k') {
            bmr1 = (10 * kilo3) + (6.25 * boy3) - (5 * yas2) - 161;
        }
        // HATA KONTROLÜ
        else {
            printf("Geçersiz cinsiyet girdiniz.");
        }

        printf("BMR sonucunuz: %.2f\n", bmr1);


    }
    // BMİ HESAPLAYICI
    else if (secim3==2) {

        float boy2=boy3/100.0;
        bmi=kilo3/((boy2)*(boy2));
        printf("BMI değeriniz: %f",bmi);

    }
    //YAG ORANI HESABI
    else if (secim3==3) {
        yagOrani=495/(1.0324-0.19077*log10(bel-boyun)+0.15456*log10(boy3))-450;// YAG ORANI HESAPLAMA FORMÜLÜ
        printf("Yağ oranınız: %.1f",yagOrani);
    }
}

// CASE 3

void ilerlemefonksiyonu() {
    float gecenHafta,buHafta,artisMiktari,artis;

    printf("Geçen hafta yaptığınızz ağırlığı giriniz: ");
    scanf(" %f",&gecenHafta);

    printf("Bu hafta yaptiginiz agirligi giriniz: ");
    scanf(" %f",&buHafta);

    artisMiktari=(buHafta-gecenHafta)/gecenHafta*100;// PO HESAPLAMA FORMÜLÜ
    printf("artis miktari %.1f%%\n",artisMiktari);

    if(artisMiktari>=2.5) {
        printf("Progressive overload var");
    }
    else{printf("Progressive overload yok");}

}

// CASE 4
void ilerlemefonksiyonu2() {



    int agirlik1,agirlik2,set,tekrar1,tekrar2,volume;
    float max;

    printf("Bir Tekrarınızı Öğrenmek İçin Ağırlığı ve Tekrar Sayısını giriniz");
    scanf(" %d %d",&agirlik1,&tekrar1);

    printf("Antrenman Hacmini Öğrenmek İçin Ağırlık,Set sayısı ve Tekrar yazınızz");
    scanf(" %d %d %d",&agirlik2,&set,&tekrar2);

    max = agirlik1 * (1 + tekrar1 / 30.0);//1RM HESAPLAMA FORMÜLÜ
    volume=agirlik2*set*tekrar2;// HACİM HESAPLAMA FORMÜLÜ

    printf("1 Tekrar Sayınız: %.2f\n",max);
    printf("Antrenman Hacminiz: %d",volume);

}


#include <stdio.h>
//CASE 5
void ornekprogram() {


 int amacSecim,i,amacSecim2,amacSecim3,j;

                 // BİRİNCİ HİPERTROFİ PROGRAMI
                char baslangicSeviyeH[3][6][50]={
        {"Birinci gün:","Bench Press–3×8"   ,"Inc.Dumbbell Press-3×10" ,"Chest Fly–3×12","Pushdown – 3×12" ,"Overhead Dumbbell Extension–3×10"},
        {"İkinci gün :" ,"Lat Pulldown–3×10" , "Seated Row–3×10"    ,"Back Extension–3×12", "Dumbbell Curl–3×10", "Hammer Curl–3×10"},
        {"Üçüncü gün :"  , "Shoulder Press-3×8", "Lateral Raise–3×12" ,"Squat (hafif)–3×8", "Leg Press–3×12", "Leg Curl–3×12"}
    };
            // İKİNCİ HİPERTROFİ PROGRAMI
    char ortaSeviyeH[4][6][50]={
        {"Birinci gün :","Bench Press–3×8","Inc.Dumbbell Press–3×10","Chest Fly–3×12","Pushdown–3×12","Overhead Dumbbell Extension–3×10"},
        {"İkinci gün  :","Barbell Row 4x8" , "Lat Pulldown-3x10","Dumbbell Row-3x10", "Barbell Curl-3x10"," Incline Dumbbell Curl-3x12" },
        {"Üçüncü gün  :","Squat–4×6","Leg Press–4×10","Romanian Deadlift–3×8","Leg Extension – 3×15","Calf Raise – 4×12"},
        {"Dördüncü gün:","Overhead Press–4×6", "Lateral Raise–4×12"," Rear Delt Fly-3×15", "Face Pull–3×12 Hanging Leg Raise–3×10"}
    };
                //ÜÇÜNCÜ HİPERTROFİ PROGRAMI
                char ileriSeviyeH[4][10][40]={
        {"Birinci gün :","Bench Press–5×5" ,"Inc.Dumbbell Press–4×8", "Weighted Dips–4×8", "Cable Fly–3×15(son set drop)","Triceps Rope–4×12"},
        {"İkinci gün  :","Deadlift–4×5", "Weighted Pull-up–4×6", "Barbell Row–4×8", "Cable Row–3×12", "EZ Bar Curl–3×10", "Hammer Curl–3×12"},
        {"Üçüncü gün  :","Squat–5×5" ,"Leg Press–4×12", "Bulgarian Split Squat–3×10", "Romanian Deadlift–4×8", "Leg Curl–3×15", "Calf Raise–5×15"},
        {"Dördüncü gün:","Overhead Press–5×5", "Lateral Raise–5×12" ,"Rear Delt Cable–4×15" ,"Arnold Press–3×10", "Chest Press (hafif)–3×12", "Plank–3×1 dk"}
    };

                // BİRİNİCİ KUVVET PROGRAMI
                char baslangicSeviyeK[4][10][40]={
        {"Gün 1:","Squat — 3×5"," Bench Press — 3×5 " ,"Barbell Row — 3×5" ,"Plank — 3×30sn"},
        {"Gün 2:","Deadlift — 1×5 ","Overhead Press — 3×5" ,"Lat Pulldown — 3×8" ,"Back Extension — 3×12"},
        {"Gün 3:", "Full Body A (tekrar)""Squat — 3×5" ,"Bench Press — 3×5" ,"Barbell Row — 3×5"},
        {"Gün 4:" ,"Full Body B (tekrar)Deadlift", "1×5 Overhead Press — 3×5" ,"Pull-up veya Pulldown — 3×6"}
    };
                // İKİNCİ KUVVET PROGRAMI
                char ortaSeviyeK[4][10][40]={
                {"Gün 1:" ,"Bench Press 5×5", "Barbell Row 4×5", "Hafif Overhead Press 3×5", "Dips 3×6"},
                {"Gün 2:" ," Squat 5×5", "Romanian Deadlift 4×6", "Leg Press 3×8", "Calf Raise 3×12"},
                {"Gün 3:" "Incline Bench 4×6", "Lat Pulldown 4×8", "Dumbbell Row 3×10", "Skull Crusher 3×8"},
                {"Gün 4:" "Deadlift 3×3", "Front Squat 4×5", "Leg Curl 3×10", "Hip Thrust 3×6"}
};
                    //ÜÇÜNCÜ KUVVET PROGRAMI
                char ileriSeviyeK[5][10][50]={
            {"Gün 1:", "Squat 5×3", "Hafif Bench Press 4×4 (%70)", "Pause Squat 3×3", "Calf Raise 4×12"},
               {"Gün 2:" ," Bench Press 5×3", "Hafif Deadlift 3×3 (%70–75)", "Barbell Row 4×5", "Close Grip Bench 3×5"},
            {"Gün 3:" ,"Deadlift 4×2", "Hafif Squat 4×4 (%60–65)", "RDL 3×5, Back Extension 3×12"},
            {"Gün 4:","Overhead Press 5×3", "Incline Bench 4×5", "Weighted Pull-up 4×3", "Face Pull 4×12"},
                {"--Yüzdeler 1RM ağırlığının yüzdeleridir--"}
        };


       // İÇ DÖNGÜDE ANA MENÜ
    printf("1-Hipertrofi programı\n");
    printf("2-Kuvvet kazanımı\n");
    printf("Seçiminiz:");
    scanf(" %d",&amacSecim);


    if (amacSecim == 1) {
        printf("Seviyenizi seçiniz\n");
        printf("1-Başlangıç 2-Orta 3-İleri\n");
        printf("Seçiminiz:");
        scanf(" %d",&amacSecim2);
        //HER ELEMANI VE ELEMANLARIN ELEMANINI BASMAK İÇİN İÇ İÇE FOR DÖNGÜLERİ
        if (amacSecim2 == 1) {
            for (i=0;i<3;i++){
                for (j=0;j<6;j++) {
                    printf(" %s",baslangicSeviyeH[i][j]);
                }
                printf("\n");
            }
        }
        else if (amacSecim2 == 2) {
            for (i=0;i<4;i++) {
                for (j=0;j<6;j++) {
                    printf(" %s",ortaSeviyeH[i][j]);
                }
                printf("\n");
            }
        }
        else if (amacSecim2 == 3) {
            for (i=0;i<4;i++) {
                for (j=0;j<6;j++) {
                    printf(" %s",ileriSeviyeH[i][j]);
                }
                printf("\n");
            }
        }
        else{printf("Geçersiz bir sayı girdiniz\n");}
    }



    else if (amacSecim== 2) {
        printf("1-Başlangıç seviyesi -Orta seviye 3-İleri seviye\n");
        printf("Seçiminiz:");
        scanf(" %d",&amacSecim3);
        //HER ELEMANI VE ELEMANLARIN ELEMANINI BASMAK İÇİN İÇ İÇE FOR DÖNGÜLERİ
        if (amacSecim3 == 1) {
            for (i=0;i<3;i++) {
                for (j=0;j<6;j++) {
                    printf(" %s",baslangicSeviyeK[i][j]);
                }
                printf("\n");
            }

        }

        else if (amacSecim3 ==2) {
            for (i=0;i<4;i++) {
                for (j=0;j<6;j++) {
                    printf(" %s",ortaSeviyeK[i][j]);
                }
                printf("\n");
            }
        }
        else if (amacSecim3 == 3) {
            for (i=0;i<5;i++) {
                for (j=0;j<6;j++) {
                    printf(" %s",ileriSeviyeK[i][j]);
                }
                printf("\n");
            }
        }
        else {
            (printf("Geçersiz sayı girdiniz"));
        }
    }

    else (printf("Geçersiz sayı girdiniz\n"));
}

#include <stdio.h>
//CASE 6
void aciklama() {


    char kelimeler[8][25] = {
        " ",
        "BMI",
        "BMR",
        "BF",
        "One Rap Max(1RM)",
        "Proggressive Overload",
        "Antrenman Hacmi",
        "Hipertrofi"
    };

    //  AÇIKLAMALAR
    char aciklama[8][100] = {
        " ",
        "Boy ve kiloya göre vücut kitle durumunu gösteren basit bir ölçüdür.",
        "Vücudun tamamen dinlenirken harcadığı minimum enerji miktarıdır.",
        "Vücuttaki yağ oranını yüzde olarak gösteren değerdir.",
        "Bir harekette çıkarabileceğin en ağır tek tekrar ağırlığıdır.",
        "Kasları geliştimek için ağırlığı veya hacmi düzenli artırma prensibidir.",
        "Antrenman hacmi, bir dönem boyunca yapılan toplam çalışma miktarını ölçer",
        "Mekanik gerilim veya kas hasarı sonucu kas kütlesi arttırımı"
    };


    int secim5,i;

    printf("----- Liste -----\n");
    for( i = 1; i <=7; i++) {
        printf("%d - %s\n", i, kelimeler[i]);
    }


    printf("\n Öğrenmek istediğiniz kelimeyi seçiniz: (1-7): ");
    scanf(" %d", &secim5);

    if(secim5 < 1 || secim5 > 9)     {      //HATA KONTROLÜ
        printf("Geçersiz seçim!\n");
    }


    printf("\nSeçilen Kelime: %s\n", kelimeler[secim5]);
    printf("Açıklama: %s\n", aciklama[secim5]);

}


