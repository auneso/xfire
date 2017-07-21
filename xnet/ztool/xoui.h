/*
** http://standards.ieee.org/develop/regauth/oui/oui.txt
** Organizationally Unique Identifier (OUI) is a 24-bit number
** 2011-12-07 HDS
** 2012-04-12 HDS update
** 2013-03-20 HDS update
*/
struct _mac_vendor {
  char *mac;
  char *vendor;
};
static struct _mac_vendor mac_vendor[] = {
{ "E043DB", "Shenzhen ViewAt Technology Co.,Ltd. " },
{ "2405F5", "Integrated Device Technology (Malaysia) Sdn. Bhd." },
{ "2C3033", "NETGEAR" },
{ "847E40", "Texas Instruments" },
{ "78C5E5", "Texas Instruments" },
{ "D494A1", "Texas Instruments" },
{ "3C3300", "Shenzhen Bilian electronic CO.,LTD" },
{ "3CD92B", "Hewlett Packard" },
{ "9C8E99", "Hewlett Packard" },
{ "B499BA", "Hewlett Packard" },
{ "1CC1DE", "Hewlett Packard" },
{ "3C3556", "Cognitec Systems GmbH" },
{ "0050BA", "D-Link Corporation" },
{ "00179A", "D-Link Corporation" },
{ "1CBDB9", "D-Link International" },
{ "9094E4", "D-Link International" },
{ "28107B", "D-Link International" },
{ "1C7EE5", "D-Link International" },
{ "C4A81D", "D-Link International" },
{ "18622C", "Sagemcom Broadband SAS" },
{ "7C03D8", "Sagemcom Broadband SAS" },
{ "E8F1B0", "Sagemcom Broadband SAS" },
{ "00F871", "DGS Denmark A/S" },
{ "D8543A", "Texas Instruments" },
{ "7C8EE4", "Texas Instruments" },
{ "BC0DA5", "Texas Instruments" },
{ "90D7EB", "Texas Instruments" },
{ "001832", "Texas Instruments" },
{ "20BB76", "COL GIOVANNI PAOLO SpA" },
{ "2C228B", "CTR SRL" },
{ "348AAE", "Sagemcom Broadband SAS" },
{ "C83E99", "Texas Instruments" },
{ "0017E5", "Texas Instruments" },
{ "0017EC", "Texas Instruments" },
{ "FC528D", "Technicolor CH USA" },
{ "BCEC23", "SHENZHEN CHUANGWEI-RGB ELECTRONICS CO.,LTD" },
{ "8CE748", "Private" },
{ "F09CE9", "Aerohive Networks Inc." },
{ "C413E2", "Aerohive Networks Inc." },
{ "AC06C7", "ServerNet S.r.l." },
{ "04BF6D", "ZyXEL Communications Corporation" },
{ "CC46D6", "Cisco Systems, Inc" },
{ "48AD08", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2CAB00", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00E0FC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "24DF6A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "009ACD", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0050C2", "IEEE Registration Authority" },
{ "00CDFE", "Apple, Inc." },
{ "38F23E", "Microsoft Mobile Oy" },
{ "58AC78", "Cisco Systems, Inc" },
{ "907F61", "Chicony Electronics Co., Ltd." },
{ "001DCE", "ARRIS Group, Inc." },
{ "001DD4", "ARRIS Group, Inc." },
{ "001DCD", "ARRIS Group, Inc." },
{ "CCA462", "ARRIS Group, Inc." },
{ "903EAB", "ARRIS Group, Inc." },
{ "28BC18", "SourcingOverseas Co. Ltd" },
{ "807ABF", "HTC Corporation" },
{ "409F87", "Jide Technology (Hong Kong) Limited" },
{ "544E45", "Private" },
{ "3C5AB4", "Google, Inc." },
{ "001A11", "Google, Inc." },
{ "D83C69", "Shenzhen TINNO Mobile Technology Corp." },
{ "74AC5F", "Qiku Internet Network Scientific (Shenzhen) Co., Ltd." },
{ "18AF61", "Apple, Inc." },
{ "BC83A7", "SHENZHEN CHUANGWEI-RGB ELECTRONICS CO.,LTD" },
{ "14CFE2", "ARRIS Group, Inc." },
{ "900DCB", "ARRIS Group, Inc." },
{ "207355", "ARRIS Group, Inc." },
{ "C83FB4", "ARRIS Group, Inc." },
{ "E0B70A", "ARRIS Group, Inc." },
{ "78719C", "ARRIS Group, Inc." },
{ "D40598", "ARRIS Group, Inc." },
{ "946269", "ARRIS Group, Inc." },
{ "8C7F3B", "ARRIS Group, Inc." },
{ "D039B3", "ARRIS Group, Inc." },
{ "0000C5", "ARRIS Group, Inc." },
{ "3C36E4", "ARRIS Group, Inc." },
{ "00ACE0", "ARRIS Group, Inc." },
{ "000347", "Intel Corporation" },
{ "001175", "Intel Corporation" },
{ "0013E8", "Intel Corporate" },
{ "001302", "Intel Corporate" },
{ "E4F89C", "Intel Corporate" },
{ "A402B9", "Intel Corporate" },
{ "4C3488", "Intel Corporate" },
{ "000D0B", "BUFFALO.INC" },
{ "000740", "BUFFALO.INC" },
{ "0024A5", "BUFFALO.INC" },
{ "DCFB02", "BUFFALO.INC" },
{ "F4CE46", "Hewlett Packard" },
{ "001CC4", "Hewlett Packard" },
{ "0025B3", "Hewlett Packard" },
{ "001871", "Hewlett Packard" },
{ "000BCD", "Hewlett Packard" },
{ "000E7F", "Hewlett Packard" },
{ "000F20", "Hewlett Packard" },
{ "00110A", "Hewlett Packard" },
{ "001321", "Hewlett Packard" },
{ "001635", "Hewlett Packard" },
{ "0017A4", "Hewlett Packard" },
{ "000802", "Hewlett Packard" },
{ "90E7C4", "HTC Corporation" },
{ "00265E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "00234E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "00234D", "Hon Hai Precision Ind. Co.,Ltd." },
{ "74A78E", "zte corporation" },
{ "D860B0", "bioMérieux Italia S.p.A." },
{ "8038BC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D440F0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "64A651", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E8CD2D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "ACE215", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "EC233D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "78F5FD", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "80B686", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "10C61F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "8853D4", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0C37DC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "BC7670", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "24DBAC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "BC3AEA", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "E8BBA8", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "0021E8", "Murata Manufacturing Co., Ltd." },
{ "006057", "Murata Manufacturing Co., Ltd." },
{ "0007D8", "Hitron Technologies. Inc" },
{ "0012F2", "Brocade Communications Systems, Inc." },
{ "001BED", "Brocade Communications Systems, Inc." },
{ "002438", "Brocade Communications Systems, Inc." },
{ "84742A", "zte corporation" },
{ "681AB2", "zte corporation" },
{ "001C25", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E005C5", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "A0F3C1", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "8C210A", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "EC172F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "EC888F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "14CF92", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "645601", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "14CC20", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "BC4699", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "0C45BA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "847778", "Cochlear Limited" },
{ "0453D5", "Sysorex Global Holdings" },
{ "CC4463", "Apple, Inc." },
{ "6C72E7", "Apple, Inc." },
{ "0016CF", "Hon Hai Precision Ind. Co.,Ltd." },
{ "4437E6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "F4B7E2", "Hon Hai Precision Ind. Co.,Ltd." },
{ "083E8E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "485AB6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "CCA223", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E8088B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "60E701", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "000883", "Hewlett Packard" },
{ "C4346B", "Hewlett Packard" },
{ "8CDCD4", "Hewlett Packard" },
{ "3464A9", "Hewlett Packard" },
{ "D4C9EF", "Hewlett Packard" },
{ "A45D36", "Hewlett Packard" },
{ "A0D3C1", "Hewlett Packard" },
{ "40A8F0", "Hewlett Packard" },
{ "6C3BE5", "Hewlett Packard" },
{ "082E5F", "Hewlett Packard" },
{ "28924A", "Hewlett Packard" },
{ "10604B", "Hewlett Packard" },
{ "308D99", "Hewlett Packard" },
{ "0030C1", "Hewlett Packard" },
{ "FC3FDB", "Hewlett Packard" },
{ "4CA161", "Rain Bird Corporation" },
{ "7C6193", "HTC Corporation" },
{ "001217", "Cisco-Linksys, LLC" },
{ "000C41", "Cisco-Linksys, LLC" },
{ "000F66", "Cisco-Linksys, LLC" },
{ "44E08E", "Cisco SPVTG" },
{ "185933", "Cisco SPVTG" },
{ "E448C7", "Cisco SPVTG" },
{ "24767D", "Cisco SPVTG" },
{ "2CABA4", "Cisco SPVTG" },
{ "0002C7", "ALPS ELECTRIC CO.,LTD." },
{ "04766E", "ALPS ELECTRIC CO.,LTD." },
{ "006B8E", "Shanghai Feixun Communication Co.,Ltd." },
{ "AC853D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "74882A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "78D752", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E0247F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00464B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "707BE8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "548998", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0819A6", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3CF808", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B41513", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "283152", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "DCD2FC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0012D2", "Texas Instruments" },
{ "080028", "Texas Instruments" },
{ "6CECEB", "Texas Instruments" },
{ "84EB18", "Texas Instruments" },
{ "D4F513", "Texas Instruments" },
{ "A0F6FD", "Texas Instruments" },
{ "209148", "Texas Instruments" },
{ "D0B5C2", "Texas Instruments" },
{ "F8A45F", "Xiaomi Communications Co Ltd" },
{ "8CBEBE", "Xiaomi Communications Co Ltd" },
{ "640980", "Xiaomi Communications Co Ltd" },
{ "98FAE3", "Xiaomi Communications Co Ltd" },
{ "185936", "Xiaomi Communications Co Ltd" },
{ "9C99A0", "Xiaomi Communications Co Ltd" },
{ "0003DD", "Comark Interactive Solutions" },
{ "00107B", "Cisco Systems, Inc" },
{ "00906D", "Cisco Systems, Inc" },
{ "0090BF", "Cisco Systems, Inc" },
{ "005080", "Cisco Systems, Inc" },
{ "D0E54D", "Pace plc" },
{ "FC8E7E", "Pace plc" },
{ "B4F2E8", "Pace plc" },
{ "7085C6", "Pace plc" },
{ "00E018", "ASUSTek COMPUTER INC." },
{ "000C6E", "ASUSTek COMPUTER INC." },
{ "001BFC", "ASUSTek COMPUTER INC." },
{ "001E8C", "ASUSTek COMPUTER INC." },
{ "0015F2", "ASUSTek COMPUTER INC." },
{ "002354", "ASUSTek COMPUTER INC." },
{ "001FC6", "ASUSTek COMPUTER INC." },
{ "60182E", "ShenZhen Protruly Electronic Ltd co." },
{ "F4CFE2", "Cisco Systems, Inc" },
{ "501CBF", "Cisco Systems, Inc" },
{ "285FDB", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "404D8E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "781DBA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001E10", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B0ADAA", "Avaya Inc" },
{ "10CDAE", "Avaya Inc" },
{ "50CD22", "Avaya Inc" },
{ "FCA841", "Avaya Inc" },
{ "3CB15B", "Avaya Inc" },
{ "C8F406", "Avaya Inc" },
{ "2CF4C5", "Avaya Inc" },
{ "7038EE", "Avaya Inc" },
{ "88F031", "Cisco Systems, Inc" },
{ "508789", "Cisco Systems, Inc" },
{ "381C1A", "Cisco Systems, Inc" },
{ "F40F1B", "Cisco Systems, Inc" },
{ "BC671C", "Cisco Systems, Inc" },
{ "A0ECF9", "Cisco Systems, Inc" },
{ "D46D50", "Cisco Systems, Inc" },
{ "1CE85D", "Cisco Systems, Inc" },
{ "C47295", "Cisco Systems, Inc" },
{ "A0554F", "Cisco Systems, Inc" },
{ "84B802", "Cisco Systems, Inc" },
{ "BCC493", "Cisco Systems, Inc" },
{ "001947", "Cisco SPVTG" },
{ "0022CE", "Cisco SPVTG" },
{ "F02929", "Cisco Systems, Inc" },
{ "ECE1A9", "Cisco Systems, Inc" },
{ "7C69F6", "Cisco Systems, Inc" },
{ "C08C60", "Cisco Systems, Inc" },
{ "C0255C", "Cisco Systems, Inc" },
{ "885A92", "Cisco Systems, Inc" },
{ "E4C722", "Cisco Systems, Inc" },
{ "C07BBC", "Cisco Systems, Inc" },
{ "005094", "Pace plc" },
{ "0090F2", "Cisco Systems, Inc" },
{ "00173B", "Cisco Systems, Inc" },
{ "00400B", "Cisco Systems, Inc" },
{ "006009", "Cisco Systems, Inc" },
{ "006047", "Cisco Systems, Inc" },
{ "0006C1", "Cisco Systems, Inc" },
{ "00E014", "Cisco Systems, Inc" },
{ "00E01E", "Cisco Systems, Inc" },
{ "ACF2C5", "Cisco Systems, Inc" },
{ "CCC760", "Apple, Inc." },
{ "087402", "Apple, Inc." },
{ "285AEB", "Apple, Inc." },
{ "28F076", "Apple, Inc." },
{ "84285A", "Saffron Solutions Inc" },
{ "80A1AB", "Intellisis" },
{ "CC79CF", "Shenzhen RF-LINK Elec&Technology Co.Ltd" },
{ "44D884", "Apple, Inc." },
{ "EC852F", "Apple, Inc." },
{ "286ABA", "Apple, Inc." },
{ "705681", "Apple, Inc." },
{ "7CD1C3", "Apple, Inc." },
{ "F0DCE2", "Apple, Inc." },
{ "B065BD", "Apple, Inc." },
{ "A82066", "Apple, Inc." },
{ "BC6778", "Apple, Inc." },
{ "68967B", "Apple, Inc." },
{ "848506", "Apple, Inc." },
{ "B4F0AB", "Apple, Inc." },
{ "10DDB1", "Apple, Inc." },
{ "04F7E4", "Apple, Inc." },
{ "34C059", "Apple, Inc." },
{ "F0D1A9", "Apple, Inc." },
{ "F82793", "Apple, Inc." },
{ "ACFDEC", "Apple, Inc." },
{ "D0E140", "Apple, Inc." },
{ "F832E4", "ASUSTek COMPUTER INC." },
{ "8C7C92", "Apple, Inc." },
{ "7831C1", "Apple, Inc." },
{ "F437B7", "Apple, Inc." },
{ "54AE27", "Apple, Inc." },
{ "6476BA", "Apple, Inc." },
{ "84B153", "Apple, Inc." },
{ "783A84", "Apple, Inc." },
{ "2CBE08", "Apple, Inc." },
{ "24E314", "Apple, Inc." },
{ "0010FF", "Cisco Systems, Inc" },
{ "34BDC8", "Cisco Systems, Inc" },
{ "54A274", "Cisco Systems, Inc" },
{ "5897BD", "Cisco Systems, Inc" },
{ "046C9D", "Cisco Systems, Inc" },
{ "60FEC5", "Apple, Inc." },
{ "00A040", "Apple, Inc." },
{ "BC3BAF", "Apple, Inc." },
{ "786C1C", "Apple, Inc." },
{ "041552", "Apple, Inc." },
{ "38484C", "Apple, Inc." },
{ "701124", "Apple, Inc." },
{ "C86F1D", "Apple, Inc." },
{ "685B35", "Apple, Inc." },
{ "380F4A", "Apple, Inc." },
{ "3010E4", "Apple, Inc." },
{ "04DB56", "Apple, Inc." },
{ "881FA1", "Apple, Inc." },
{ "04E536", "Apple, Inc." },
{ "109ADD", "Apple, Inc." },
{ "40A6D9", "Apple, Inc." },
{ "7CF05F", "Apple, Inc." },
{ "A4B197", "Apple, Inc." },
{ "0C74C2", "Apple, Inc." },
{ "403004", "Apple, Inc." },
{ "4860BC", "Apple, Inc." },
{ "50EAD6", "Apple, Inc." },
{ "28E02C", "Apple, Inc." },
{ "60C547", "Apple, Inc." },
{ "7C11BE", "Apple, Inc." },
{ "003EE1", "Apple, Inc." },
{ "68D93C", "Apple, Inc." },
{ "2CF0EE", "Apple, Inc." },
{ "84788B", "Apple, Inc." },
{ "6C94F8", "Apple, Inc." },
{ "703EAC", "Apple, Inc." },
{ "C01ADA", "Apple, Inc." },
{ "34363B", "Apple, Inc." },
{ "C81EE7", "Apple, Inc." },
{ "9CFC01", "Apple, Inc." },
{ "000D93", "Apple, Inc." },
{ "001CB3", "Apple, Inc." },
{ "64B9E8", "Apple, Inc." },
{ "34159E", "Apple, Inc." },
{ "58B035", "Apple, Inc." },
{ "F0B479", "Apple, Inc." },
{ "141357", "ATP Electronics, Inc." },
{ "F44B2A", "Cisco SPVTG" },
{ "3C8CF8", "TRENDnet, Inc." },
{ "78D6B2", "Toshiba" },
{ "C04A09", "Zhejiang Everbright Communication Equip. Co,. Ltd" },
{ "F00D5C", "JinQianMao  Technology Co.,Ltd." },
{ "2C081C", "OVH" },
{ "30E090", "Linctronix Ltd," },
{ "70BF3E", "Charles River Laboratories" },
{ "D848EE", "Hangzhou Xueji Technology Co., Ltd." },
{ "EC9BF3", "Samsung Electro Mechanics co., LTD." },
{ "88947E", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "88C242", "Poynt Co." },
{ "E8343E", "Beijing Infosec Technologies Co., LTD." },
{ "A8474A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "C4ADF1", "GOPEACE Inc." },
{ "58F496", "Source Chain" },
{ "80B709", "Viptela, Inc" },
{ "1C60DE", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "741865", "Shanghai DareGlobal Technologies Co.,Ltd" },
{ "0084ED", "Private" },
{ "DCDC07", "TRP Systems BV" },
{ "080A4E", "Planet Bingo® — 3rd Rock Gaming®" },
{ "0C1A10", "Acoustic Stream" },
{ "E4A387", "Control Solutions LLC" },
{ "DC82F6", "iPort" },
{ "C49E41", "G24 Power Limited" },
{ "D03E5C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C8A9FC", "Goyoo Networks Inc." },
{ "C49FF3", "Mciao Technologies, Inc." },
{ "80739F", "KYOCERA Corporation" },
{ "7C2BE1", "Shenzhen Ferex Electrical Co.,Ltd" },
{ "30FFF6", "HangZhou KuoHeng Technology Co.,ltd" },
{ "5853C0", "Beijing Guang Runtong Technology Development Company co.,Ltd" },
{ "5031AD", "ABB Global Industries and Services Private Limited" },
{ "30A243", "Shenzhen Prifox Innovation Technology Co., Ltd." },
{ "2CA539", "Parallel Wireless, Inc" },
{ "FC335F", "Polyera" },
{ "FCC233", "Private" },
{ "645D92", "SICHUAN TIANYI COMHEART TELECOMCO.,LTD" },
{ "A8C87F", "Roqos, Inc." },
{ "C025A2", "NEC Platforms, Ltd." },
{ "7853F2", "ROXTON Ltd." },
{ "384C90", "ARRIS Group, Inc." },
{ "ACBC32", "Apple, Inc." },
{ "94BBAE", "Husqvarna AB" },
{ "AC8995", "AzureWave Technology Inc." },
{ "F898B9", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D40AA9", "ARRIS Group, Inc." },
{ "1C497B", "Gemtek Technology Co., Ltd." },
{ "2CCF58", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "54FF82", "Davit Solution co." },
{ "D445E8", "Jiangxi Hongpai Technology Co., Ltd." },
{ "847973", "Shanghai Baud Data Communication Co.,Ltd." },
{ "906F18", "Private" },
{ "881B99", "SHENZHEN XIN FEI JIA ELECTRONIC CO. LTD." },
{ "681295", "Lupine Lighting Systems GmbH" },
{ "649A12", "P2 Mobile Technologies Limited" },
{ "E4C2D1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "DC3CF6", "Atomic Rules LLC" },
{ "441CA8", "Hon Hai Precision Ind. Co.,Ltd." },
{ "C4047B", "Shenzhen YOUHUA Technology Co., Ltd" },
{ "F895C7", "LG Electronics (Mobile Communications)" },
{ "3C3178", "Qolsys Inc." },
{ "F4573E", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "083A5C", "Junilab, Inc." },
{ "E8377A", "ZyXEL Communications Corporation" },
{ "4CAE31", "ShengHai Electronics (Shenzhen) Ltd" },
{ "C80E14", "AVM Audiovisuelles Marketing und Computersysteme GmbH" },
{ "F0D657", "ECHOSENS" },
{ "24693E", "innodisk Corporation" },
{ "E48D8C", "Routerboard.com" },
{ "C0DC6A", "Qingdao Eastsoft Communication Technology Co.,LTD" },
{ "6459F8", "Vodafone Omnitel B.V." },
{ "082CB0", "Network Instruments" },
{ "F0AB54", "MITSUMI ELECTRIC CO.,LTD." },
{ "485073", "Microsoft Corporation" },
{ "3CA31A", "Oilfind International LLC" },
{ "ACFD93", "Weifang GoerTek Electronics Co., Ltd." },
{ "A424DD", "Cambrionix Ltd" },
{ "88A2D7", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D89A34", "Beijing SHENQI Technology Co., Ltd." },
{ "1CADD1", "Bosung Electronics Co., Ltd." },
{ "24E5AA", "Philips Oral Healthcare, Inc." },
{ "741F4A", "Hangzhou H3C Technologies Co., Limited" },
{ "88CBA5", "Suzhou Torchstar Intelligent Technology Co.,Ltd" },
{ "184F32", "Hon Hai Precision Ind. Co.,Ltd." },
{ "20F41B", "Shenzhen Bilian electronic CO.,LTD" },
{ "046169", "MEDIA GLOBAL LINKS CO., LTD." },
{ "AC562C", "LAVA INTERNATIONAL(H.K) LIMITED" },
{ "3CCE15", "Mercedes-Benz USA, LLC" },
{ "84DF19", "Chuango Security Technology Corporation" },
{ "3C4711", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "245BF0", "Liteon, Inc." },
{ "FCFEC2", "Invensys Controls UK Limited" },
{ "E8F2E2", "LG Innotek" },
{ "AC676F", "Electrocompaniet A.S." },
{ "4CB82C", "Cambridge Mobile Telematics, Inc." },
{ "F0224E", "Esan electronic co." },
{ "B0411D", "ITTIM Technologies" },
{ "7CB25C", "Acacia Communications" },
{ "78EB39", "Instituto Nacional de Tecnología Industrial" },
{ "7CC95A", "EMC" },
{ "ECEED8", "ZTLX Network Technology Co.,Ltd" },
{ "F85B9C", "SB SYSTEMS Co.,Ltd" },
{ "7CA237", "King Slide Technology CO., LTD." },
{ "300EE3", "Aquantia Corporation" },
{ "847303", "Letv Mobile and Intelligent Information Technology (Beijing) Corporation Ltd." },
{ "B0495F", "OMRON HEALTHCARE Co., Ltd." },
{ "BC6E64", "Sony Mobile Communications AB" },
{ "8C8B83", "Texas Instruments" },
{ "90A210", "United Telecoms Ltd" },
{ "F44713", "Leading Public Performance Co., Ltd." },
{ "D4522A", "TangoWiFi.com" },
{ "B0ECE1", "Private" },
{ "407FE0", "Glory Star Technics (ShenZhen) Limited" },
{ "BC5C4C", "ELECOM CO.,LTD." },
{ "6C5940", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "6CA75F", "zte corporation" },
{ "C8C50E", "Shenzhen Primestone Network Technologies.Co., Ltd." },
{ "9CBEE0", "Biosoundlab Co., Ltd." },
{ "5C5B35", "Mist Systems, Inc." },
{ "E807BF", "SHENZHEN BOOMTECH INDUSTRY CO.,LTD" },
{ "E8162B", "IDEO Security Co., Ltd." },
{ "709F2D", "zte corporation" },
{ "5C6B4F", "Private" },
{ "ECE2FD", "SKG Electric Group(Thailand) Co., Ltd." },
{ "88E603", "Avotek corporation" },
{ "0C4885", "LG Electronics" },
{ "74E28C", "Microsoft Corporation" },
{ "94F19E", "HUIZHOU MAORONG INTELLIGENT TECHNOLOGY CO.,LTD" },
{ "C4924C", "KEISOKUKI CENTER CO.,LTD." },
{ "E4F939", "Minxon Hotel Technology INC." },
{ "38C70A", "WiFiSong" },
{ "60E6BC", "Sino-Telecom Technology Co.,Ltd." },
{ "3CCB7C", "TCT mobile ltd" },
{ "F09FC2", "Ubiquiti Networks, Inc." },
{ "44D9E7", "Ubiquiti Networks, Inc." },
{ "F8042E", "Samsung Electro Mechanics co., LTD." },
{ "1CA532", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "643AB1", "SICHUAN TIANYI COMHEART TELECOMCO.,LTD" },
{ "486EFB", "Davit System Technology Co., Ltd." },
{ "340A22", "TOP-ACCESS ELECTRONICS CO LTD" },
{ "B008BF", "Vital Connect, Inc." },
{ "7CF854", "Samsung Electronics" },
{ "485415", "NET RULES TECNOLOGIA EIRELI" },
{ "70C76F", "INNO S" },
{ "C48E8F", "Hon Hai Precision Ind. Co.,Ltd." },
{ "704E66", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "1008B1", "Hon Hai Precision Ind. Co.,Ltd." },
{ "409B0D", "Shenzhen Yourf Kwan Industrial Co., Ltd" },
{ "C40880", "Shenzhen UTEPO Tech Co., Ltd." },
{ "94C038", "Tallac Networks" },
{ "801967", "Shanghai Reallytek Information Technology  Co.,Ltd" },
{ "6836B5", "DriveScale, Inc." },
{ "2CF7F1", "Seeed Technology Inc." },
{ "F88479", "Yaojin Technology(Shenzhen)Co.,Ltd" },
{ "4C48DA", "Beijing Autelan Technology Co.,Ltd" },
{ "90179B", "Nanomegas" },
{ "3077CB", "Maike Industry(Shenzhen)CO.,LTD" },
{ "88C9D0", "LG Electronics" },
{ "3428F0", "ATN International Limited" },
{ "EC3C5A", "SHEN ZHEN HENG SHENG HUI DIGITAL TECHNOLOGY CO.,LTD" },
{ "8C0551", "Koubachi AG" },
{ "D88466", "Extreme Networks" },
{ "E887A3", "Loxley Public Company Limited" },
{ "10FACE", "Reacheng Communication Technology Co.,Ltd" },
{ "D8CB8A", "Micro-Star INTL CO., LTD." },
{ "A8D0E3", "Systech Electronics Ltd." },
{ "8463D6", "Microsoft Corporation" },
{ "78B3B9", "ShangHai sunup lighting CO.,LTD" },
{ "586AB1", "Hangzhou H3C Technologies Co., Limited" },
{ "F4EE14", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "186571", "Top Victory Electronics (Taiwan) Co., Ltd." },
{ "F8BC41", "Rosslare Enterprises Limited" },
{ "8486F3", "Greenvity Communications" },
{ "205CFA", "Yangzhou ChangLian Network Technology Co,ltd." },
{ "8C18D9", "Shenzhen RF Technology Co., Ltd" },
{ "6099D1", "Vuzix / Lenovo" },
{ "38B1DB", "Hon Hai Precision Ind. Co.,Ltd." },
{ "34F6D2", "Panasonic Taiwan Co.,Ltd." },
{ "DC2F03", "Step forward Group Co., Ltd." },
{ "582136", "KMB systems, s.r.o." },
{ "00AEFA", "Murata Manufacturing Co., Ltd." },
{ "5CAAFD", "Sonos, Inc." },
{ "8CDF9D", "NEC Corporation" },
{ "F8E903", "D-Link International" },
{ "F0B052", "Ruckus Wireless" },
{ "6828F6", "Vubiq Networks, Inc." },
{ "44356F", "Neterix" },
{ "742EFC", "DirectPacket Research, Inc," },
{ "20C06D", "SHENZHEN SPACETEK TECHNOLOGY CO.,LTD" },
{ "3CB792", "Hitachi Maxell, Ltd., Optronics Division" },
{ "7491BD", "Four systems Co.,Ltd." },
{ "D43266", "Fike Corporation" },
{ "948E89", "INDUSTRIAS UNIDAS SA DE CV" },
{ "9405B6", "Liling FullRiver Electronics & Technology Ltd" },
{ "382C4A", "ASUSTek COMPUTER INC." },
{ "74547D", "Cisco SPVTG" },
{ "D48F33", "Microsoft Corporation" },
{ "D84A87", "OI ELECTRIC CO.,LTD" },
{ "1CA2B1", "ruwido austria gmbh" },
{ "945493", "Rigado, LLC" },
{ "34B7FD", "Guangzhou Younghead Electronic Technology Co.,Ltd" },
{ "384B76", "AIRTAME ApS" },
{ "1C5216", "DONGGUAN HELE ELECTRONICS CO., LTD" },
{ "34029B", "CloudBerry Technologies Private Limited" },
{ "70AF25", "Nishiyama Industry Co.,LTD." },
{ "B47C29", "Shenzhen Guzidi Technology Co.,Ltd" },
{ "2C1A31", "Electronics Company Limited" },
{ "6C198F", "D-Link International" },
{ "60C1CB", "Fujian Great Power PLC Equipment Co.,Ltd" },
{ "686E48", "Prophet Electronic Technology Corp.,Ltd" },
{ "30F7D7", "Thread Technology Co., Ltd" },
{ "3808FD", "Silca Spa" },
{ "7C2587", "chaowifi.com" },
{ "2012D5", "Scientech Materials Corporation" },
{ "DC3979", "Skyport Systems" },
{ "EC1D7F", "zte corporation" },
{ "AC11D3", "Suzhou HOTEK  Video Technology Co. Ltd" },
{ "304225", "BURG-WÄCHTER KG" },
{ "1C4840", "IMS Messsysteme GmbH" },
{ "F42853", "Zioncom Electronics (Shenzhen) Ltd." },
{ "3C46D8", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "6C0273", "Shenzhen Jin Yun Video Equipment Co., Ltd." },
{ "2CFAA2", "Alcatel-Lucent" },
{ "F0761C", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "F42833", "MMPC Inc." },
{ "244F1D", "iRule LLC" },
{ "BC9CC5", "Beijing Huafei Technology Co., Ltd." },
{ "505065", "TAKT Corporation" },
{ "D00AAB", "Yokogawa Digital Computer Corporation" },
{ "A4A4D3", "Bluebank Communication Technology Co.Ltd" },
{ "74F413", "Maxwell Forest" },
{ "34F0CA", "Shenzhen Linghangyuan Digital Technology Co.,Ltd." },
{ "84183A", "Ruckus Wireless" },
{ "30B5F1", "Aitexin Technology Co., Ltd" },
{ "882950", "Dalian Netmoon Tech Develop Co.,Ltd" },
{ "08CD9B", "samtec automotive electronics & software GmbH" },
{ "28FCF6", "Shenzhen Xin KingBrand enterprises Co.,Ltd" },
{ "2C54CF", "LG Electronics" },
{ "4C26E7", "Welgate Co., Ltd." },
{ "94D60E", "shenzhen yunmao information technologies co., ltd" },
{ "7C6AC3", "GatesAir, Inc" },
{ "D8E56D", "TCT Mobile Limited" },
{ "3CCD5A", "Technische Alternative GmbH" },
{ "604826", "Newbridge Technologies Int. Ltd." },
{ "24D13F", "MEXUS CO.,LTD" },
{ "702C1F", "Wisol" },
{ "9CBD9D", "SkyDisk, Inc." },
{ "74C621", "Zhejiang Hite Renewable Energy Co.,LTD" },
{ "44C306", "SIFROM Inc." },
{ "54A31B", "Shenzhen Linkworld Technology Co,.LTD" },
{ "5CE7BF", "New Singularity International Technical Development Co.,Ltd" },
{ "1CEEE8", "Ilshin Elecom" },
{ "6C641A", "Penguin Computing" },
{ "E036E3", "Stage One International Co., Ltd." },
{ "34DE34", "zte corporation" },
{ "34466F", "HiTEM Engineering" },
{ "2C39C1", "Ciena Corporation" },
{ "6C2C06", "OOO NPP Systemotechnika-NN" },
{ "54EE75", "Wistron InfoComm(Kunshan)Co.,Ltd." },
{ "60812B", "Custom Control Concepts" },
{ "F86601", "Suzhou Chi-tek information technology Co., Ltd" },
{ "FC4AE9", "Castlenet Technology Inc." },
{ "34E42A", "Automatic Bar Controls Inc." },
{ "B87CF2", "Aerohive Networks Inc." },
{ "20A787", "Bointec Taiwan Corporation Limited" },
{ "6CAAB3", "Ruckus Wireless" },
{ "A481EE", "Nokia Corporation" },
{ "54C80F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D42122", "Sercomm Corporation" },
{ "EC1766", "Research Centre Module" },
{ "7CFF62", "Huizhou Super Electron Technology Co.,Ltd." },
{ "A0D12A", "AXPRO Technology Inc." },
{ "30C750", "MIC Technology Group" },
{ "442938", "NietZsche enterprise Co.Ltd." },
{ "D881CE", "AHN INC." },
{ "E0D31A", "EQUES Technology Co., Limited" },
{ "9C3EAA", "EnvyLogic Co.,Ltd." },
{ "909864", "Impex-Sat GmbH&amp;Co KG" },
{ "DCE578", "Experimental Factory of Scientific Engineering and Special Design Department" },
{ "949F3F", "Optek Digital Technology company limited" },
{ "987770", "Pep Digital Technology (Guangzhou) Co., Ltd" },
{ "4411C2", "Telegartner Karl Gartner GmbH" },
{ "9451BF", "Hyundai ESG" },
{ "4C7F62", "Nokia Corporation" },
{ "841766", "Weifang GoerTek Electronics Co., Ltd" },
{ "F03FF8", "R L Drake" },
{ "B0C554", "D-Link International" },
{ "54D163", "MAX-TECH,INC" },
{ "E41218", "ShenZhen Rapoo Technology Co., Ltd." },
{ "2C8A72", "HTC Corporation" },
{ "4486C1", "Siemens Low Voltage & Products" },
{ "C83168", "eZEX corporation" },
{ "843838", "Samsung Electro Mechanics co., LTD." },
{ "F84A73", "EUMTECH CO., LTD" },
{ "880F10", "Huami Information Technology Co.,Ltd." },
{ "24336C", "Private" },
{ "C46BB4", "myIDkey" },
{ "ECE512", "tado GmbH" },
{ "30918F", "Technicolor" },
{ "FC09F6", "GUANGDONG TONZE ELECTRIC CO.,LTD" },
{ "687848", "Westunitis Co., Ltd." },
{ "A8B9B3", "ESSYS" },
{ "64B370", "PowerComm Solutions LLC" },
{ "D86595", "Toy's Myth Inc." },
{ "C45006", "Samsung Electronics Co.,Ltd" },
{ "D8DD5F", "BALMUDA Inc." },
{ "88D962", "Canopus Systems US LLC" },
{ "24C848", "mywerk system GmbH" },
{ "805719", "Samsung Electronics Co.,Ltd" },
{ "B0DF3A", "Samsung Electronics Co.,Ltd" },
{ "2C18AE", "Trend Electronics Co., Ltd." },
{ "E097F2", "Atomax Inc." },
{ "90F3B7", "Kirisun Communications Co., Ltd." },
{ "DCAD9E", "GreenPriz" },
{ "B4827B", "AKG Acoustics GmbH" },
{ "908C44", "H.K ZONGMU TECHNOLOGY CO., LTD." },
{ "0C473D", "Hitron Technologies. Inc" },
{ "4C5E0C", "Routerboard.com" },
{ "9CF8DB", "shenzhen eyunmei technology co,.ltd" },
{ "644214", "Swisscom Energy Solutions AG" },
{ "00E3B2", "Samsung Electronics Co.,Ltd" },
{ "30D6C9", "Samsung Electronics Co.,Ltd" },
{ "107BEF", "ZyXEL Communications Corporation" },
{ "8CCDA2", "ACTP, Inc." },
{ "CC720F", "Viscount Systems Inc." },
{ "906717", "Alphion India Private Limited" },
{ "24050F", "MTN Electronic Co. Ltd" },
{ "40B6B1", "SUNGSAM CO,.Ltd" },
{ "98FF6A", "OTEC(Shanghai)Technology Co.,Ltd." },
{ "AC6BAC", "Jenny Science AG" },
{ "707C18", "ADATA Technology Co., Ltd" },
{ "FC4B1C", "INTERSENSOR S.R.L." },
{ "1879A2", "GMJ ELECTRIC LIMITED" },
{ "E0C86A", "SHENZHEN TW-SCIE Co., Ltd" },
{ "80BAE6", "Neets" },
{ "3C18A0", "Luxshare Precision Industry Co.,Ltd." },
{ "4CB81C", "SAM Electronics GmbH" },
{ "2C3731", "ShenZhen Yifang Digital Technology Co.,LTD" },
{ "041A04", "WaveIP" },
{ "50206B", "Emerson Climate Technologies Transportation Solutions" },
{ "C8EE75", "Pishion International Co. Ltd" },
{ "CC3429", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "407496", "aFUN TECHNOLOGY INC." },
{ "18C8E7", "Shenzhen Hualistone Technology Co.,Ltd" },
{ "3CF748", "Shenzhen Linsn Technology Development Co.,Ltd" },
{ "9C039E", "Beijing Winchannel Software Technology Co., Ltd" },
{ "F8A963", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "48A2B7", "Kodofon JSC" },
{ "443C9C", "Pintsch Tiefenbach GmbH" },
{ "F81CE5", "Telefonbau Behnke GmbH" },
{ "BC2D98", "ThinGlobal LLC" },
{ "7C72E4", "Unikey Technologies" },
{ "8048A5", "SICHUAN TIANYI COMHEART TELECOM CO.,LTD" },
{ "181BEB", "Actiontec Electronics, Inc" },
{ "CC7498", "Filmetrics Inc." },
{ "7C6AB3", "IBC TECHNOLOGIES INC." },
{ "309BAD", "BBK Electronics Corp., Ltd.," },
{ "F0321A", "Mita-Teknik A/S" },
{ "4CD7B6", "Helmer Scientific" },
{ "746F3D", "Contec GmbH" },
{ "483D32", "Syscor Controls &amp; Automation" },
{ "9031CD", "Onyx Healthcare Inc." },
{ "A0E453", "Sony Mobile Communications AB" },
{ "404A18", "Addrek Smart Solutions" },
{ "C4C0AE", "MIDORI ELECTRONIC CO., LTD." },
{ "08FD0E", "Samsung Electronics Co.,Ltd" },
{ "78A873", "Samsung Electronics Co.,Ltd" },
{ "54880E", "Samsung Electro Mechanics co., LTD." },
{ "90837A", "General Electric Water & Process Technologies" },
{ "089758", "Shenzhen Strong Rising Electronics Co.,Ltd DongGuan Subsidiary" },
{ "B424E7", "Codetek Technology Co.,Ltd" },
{ "44EE30", "Budelmann Elektronik GmbH" },
{ "38DBBB", "Sunbow Telecom Co., Ltd." },
{ "2493CA", "Voxtronic Technology Computer-Systeme GmbH" },
{ "688AB5", "EDP Servicos" },
{ "407A80", "Nokia Corporation" },
{ "F06130", "Advantage Pharmacy Services, LLC" },
{ "D481CA", "iDevices, LLC" },
{ "B898F7", "Gionee Communication Equipment Co,Ltd.ShenZhen" },
{ "C0F1C4", "Pacidal Corporation Ltd." },
{ "D858D7", "CZ.NIC, z.s.p.o." },
{ "BC307D", "Wistron Neweb Corp." },
{ "10B713", "Private" },
{ "E8E770", "Warp9 Tech Design, Inc." },
{ "78CA5E", "ELNO" },
{ "98FFD0", "Lenovo Mobile Communication Technology Ltd." },
{ "50A054", "Actineon" },
{ "48EE86", "UTStarcom (China) Co.,Ltd" },
{ "5056A8", "Jolla Ltd" },
{ "D09D0A", "LINKCOM" },
{ "C81479", "Samsung Electronics Co.,Ltd" },
{ "54FB58", "WISEWARE, Lda" },
{ "A42940", "Shenzhen YOUHUA Technology Co., Ltd" },
{ "C0A0BB", "D-Link International" },
{ "28A1EB", "ETEK TECHNOLOGY (SHENZHEN) CO.,LTD" },
{ "4CCBF5", "zte corporation" },
{ "F0F5AE", "Adaptrum Inc." },
{ "F42896", "SPECTO PAINEIS ELETRONICOS LTDA" },
{ "1C7B21", "Sony Mobile Communications AB" },
{ "BC9680", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "9C2840", "Discovery Technology,LTD.." },
{ "F89FB8", "YAZAKI Energy System Corporation" },
{ "F037A1", "Huike Electronics (SHENZHEN) CO., LTD." },
{ "6CD1B0", "WING SING ELECTRONICS HONG KONG LIMITED" },
{ "A4F522", "CHOFU SEISAKUSHO CO.,LTD" },
{ "7CE56B", "ESEN Optoelectronics Technology Co.,Ltd." },
{ "CC4703", "Intercon Systems Co., Ltd." },
{ "5C3327", "Spazio Italia srl" },
{ "BC8CCD", "Samsung Electro Mechanics co.,LTD." },
{ "F85BC9", "M-Cube Spa" },
{ "8005DF", "Montage Technology Group Limited" },
{ "78E8B6", "zte corporation" },
{ "041B94", "Host Mobility AB" },
{ "CC2A80", "Micro-Biz intelligence solutions Co.,Ltd" },
{ "3859F8", "MindMade Sp. z o.o." },
{ "F0728C", "Samsung Electronics Co.,Ltd" },
{ "5C026A", "Applied Vision Corporation" },
{ "94350A", "Samsung Electronics Co.,Ltd" },
{ "7CBD06", "AE REFUsol" },
{ "94BA56", "Shenzhen Coship Electronics Co., Ltd." },
{ "2894AF", "Samhwa Telecom" },
{ "740EDB", "Optowiz Co., Ltd" },
{ "00A2FF", "abatec group AG" },
{ "D095C7", "Pantech Co., Ltd." },
{ "D02C45", "littleBits Electronics, Inc." },
{ "5027C7", "TECHNART Co.,Ltd" },
{ "248000", "Westcontrol AS" },
{ "F84A7F", "Innometriks Inc" },
{ "58639A", "TPL SYSTEMES" },
{ "0C9B13", "Shanghai Magic Mobile Telecommunication Co.Ltd." },
{ "3C15EA", "TESCOM CO., LTD." },
{ "B4CCE9", "PROSYST" },
{ "34A3BF", "Terewave. Inc." },
{ "B0CE18", "Zhejiang shenghui lighting co.,Ltd" },
{ "503CC4", "Lenovo Mobile Communication Technology Ltd." },
{ "286D97", "SAMJIN Co., Ltd." },
{ "ACE42E", "SK hynix" },
{ "08EF3B", "MCS Logic Inc." },
{ "806C8B", "KAESER KOMPRESSOREN AG" },
{ "048C03", "ThinPAD Technology (Shenzhen)CO.,LTD" },
{ "84E629", "Bluwan SA" },
{ "34CD6D", "CommSky Technologies" },
{ "C47F51", "Inventek Systems" },
{ "E8D4E0", "Beijing BenyWave Technology Co., Ltd." },
{ "3889DC", "Opticon Sensors Europe B.V." },
{ "88124E", "Qualcomm Atheros" },
{ "681D64", "Sunwave Communications Co., Ltd" },
{ "F4CD90", "Vispiron Rotec GmbH" },
{ "400E85", "Samsung Electro Mechanics co.,LTD." },
{ "E438F2", "Advantage Controls" },
{ "24C9A1", "Ruckus Wireless" },
{ "C8F386", "Shenzhen Xiaoniao Technology Co.,Ltd" },
{ "E8CE06", "SkyHawke Technologies, LLC." },
{ "B0808C", "Laser Light Engines" },
{ "C419EC", "Qualisys AB" },
{ "981094", "Shenzhen Vsun communication technology Co.,ltd" },
{ "082719", "APS systems/electronic AG" },
{ "D4AC4E", "BODi rS, LLC" },
{ "B03850", "Nanjing CAS-ZDC IOT SYSTEM CO.,LTD" },
{ "C0DA74", "Hangzhou Sunyard Technology Co., Ltd." },
{ "34A843", "KYOCERA Display Corporation" },
{ "6C5779", "Aclima, Inc." },
{ "40BD9E", "Physio-Control, Inc" },
{ "BC79AD", "Samsung Electronics Co.,Ltd" },
{ "581CBD", "Affinegy" },
{ "649C81", "Qualcomm iSkoot, Inc." },
{ "F82BC8", "Jiangsu Switter Co., Ltd" },
{ "60C397", "2Wire Inc" },
{ "3065EC", "Wistron (ChongQing)" },
{ "5CA3EB", "Lokel s.r.o." },
{ "04DF69", "Car Connectivity Consortium" },
{ "28DB81", "Shanghai Guao Electronic Technology Co., Ltd" },
{ "9CB793", "Creatcomm Technology Inc." },
{ "C4438F", "LG Electronics" },
{ "A0B100", "ShenZhen Cando Electronics Co.,Ltd" },
{ "40560C", "In Home Displays Ltd" },
{ "9436E0", "Sichuan Bihong Broadcast &amp; Television New Technologies Co.,Ltd" },
{ "D4D50D", "Southwest Microwave, Inc" },
{ "B8CD93", "Penetek, Inc" },
{ "D8FEE3", "D-Link International" },
{ "F8516D", "Denwa Technology Corp." },
{ "1078CE", "Hanvit SI, Inc." },
{ "D8DA52", "APATOR S.A." },
{ "107A86", "U&U ENGINEERING INC." },
{ "980D2E", "HTC Corporation" },
{ "842F75", "Innokas Group" },
{ "D4BF7F", "UPVEL" },
{ "5061D6", "Indu-Sol GmbH" },
{ "68EC62", "YODO Technology Corp. Ltd." },
{ "10D542", "Samsung Electronics Co.,Ltd" },
{ "A0821F", "Samsung Electronics Co.,Ltd" },
{ "F07F0C", "Leopold Kostal GmbH &Co. KG" },
{ "5C22C4", "DAE EUN ELETRONICS CO., LTD" },
{ "08482C", "Raycore Taiwan Co., LTD." },
{ "F4B381", "WindowMaster A/S" },
{ "74F102", "Beijing HCHCOM Technology Co., Ltd" },
{ "080EA8", "Velex s.r.l." },
{ "041BBA", "Samsung Electronics Co.,Ltd" },
{ "5C3C27", "Samsung Electronics Co.,Ltd" },
{ "0086A0", "Private" },
{ "60FE1E", "China Palms Telecom.Ltd" },
{ "841E26", "KERNEL-I Co.,LTD" },
{ "349D90", "Heinzmann GmbH & CO. KG" },
{ "D4016D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "FC1186", "Logic3 plc" },
{ "50CD32", "NanJing Chaoran Science & Technology Co.,Ltd." },
{ "683EEC", "ERECA" },
{ "44619C", "FONsystem co. ltd." },
{ "BCBAE1", "AREC Inc." },
{ "18FA6F", "ISC applied systems corp" },
{ "9C9726", "Technicolor" },
{ "880905", "MTMCommunications" },
{ "C42628", "Airo Wireless" },
{ "745F00", "Samsung Semiconductor Inc." },
{ "541FD5", "Advantage Electronics" },
{ "90FF79", "Metro Ethernet Forum" },
{ "E08177", "GreenBytes, Inc." },
{ "48F230", "Ubizcore Co.,LTD" },
{ "B0C95B", "Beijing Symtech CO.,LTD" },
{ "881544", "Meraki, Inc." },
{ "DCA989", "MACANDC" },
{ "C05E6F", "V. Stonkaus firma Kodinis Raktas" },
{ "6CD146", "Smartek d.o.o." },
{ "E0C2B7", "Masimo Corporation" },
{ "F82EDB", "RTW GmbH & Co. KG" },
{ "60A44C", "ASUSTek COMPUTER INC." },
{ "045FA7", "Shenzhen Yichen Technology Development Co.,LTD" },
{ "983F9F", "China SSJ (Suzhou) Network Technology Inc." },
{ "F02329", "SHOWA DENKI CO.,LTD." },
{ "6499A0", "AG Elektronik AB" },
{ "A80180", "IMAGO Technologies GmbH" },
{ "044CEF", "Fujian Sanao Technology Co.,Ltd" },
{ "DC1DD4", "Microstep-MIS spol. s r.o." },
{ "E01877", "FUJITSU LIMITED" },
{ "149448", "BLU CASTLE S.A." },
{ "40516C", "Grandex International Corporation" },
{ "D0D471", "MVTECH co., Ltd" },
{ "34ADE4", "Shanghai Chint Power Systems Co., Ltd." },
{ "1853E0", "Hanyang Digitech Co.Ltd" },
{ "C4E032", "IEEE 1904.1 Working Group" },
{ "ACDBDA", "Shenzhen Geniatech Inc, Ltd" },
{ "A42C08", "Masterwork Automodules" },
{ "60B185", "ATH system" },
{ "504F94", "Loxone Electronics GmbH" },
{ "88329B", "Samsung Electro Mechanics co.,LTD." },
{ "8C078C", "FLOW DATA INC" },
{ "8887DD", "DarbeeVision Inc." },
{ "807B1E", "Corsair Components" },
{ "A0E25A", "Amicus SK, s.r.o." },
{ "F87B62", "FASTWEL INTERNATIONAL CO., LTD. Taiwan Branch" },
{ "B49842", "zte corporation" },
{ "9C9C1D", "Starkey Labs Inc." },
{ "90CC24", "Synaptics, Inc" },
{ "AC1702", "Fibar Group sp. z o.o." },
{ "7898FD", "Q9 Networks Inc." },
{ "3C57D5", "FiveCo" },
{ "4C2258", "cozybit, Inc." },
{ "10EA59", "Cisco SPVTG" },
{ "34FA40", "Guangzhou Robustel Technologies Co., Limited" },
{ "181725", "Cameo Communications, Inc." },
{ "E82E24", "Out of the Fog Research LLC" },
{ "1C52D6", "FLAT DISPLAY TECHNOLOGY CORPORATION" },
{ "40270B", "Mobileeco Co., Ltd" },
{ "ACE97F", "IoT Tech Limited" },
{ "301518", "Ubiquitous Communication Co. ltd." },
{ "101248", "ITG, Inc." },
{ "106FEF", "Ad-Sol Nissin Corp" },
{ "A036F0", "Comprehensive Power" },
{ "180CAC", "CANON INC." },
{ "00DB1E", "Albedo Telecom SL" },
{ "74943D", "AgJunction" },
{ "0CDA41", "Hangzhou H3C Technologies Co., Limited" },
{ "080C0B", "SysMik GmbH Dresden" },
{ "C8FB26", "Cisco SPVTG" },
{ "7CC8AB", "Acro Associates, Inc." },
{ "C4DA26", "NOBLEX SA" },
{ "1CC316", "MileSight Technology Co., Ltd." },
{ "C4E7BE", "SCSpro Co.,Ltd" },
{ "105F49", "Cisco SPVTG" },
{ "0418D6", "Ubiquiti Networks" },
{ "4495FA", "Qingdao Santong Digital Technology Co.Ltd" },
{ "60F2EF", "VisionVera International Co., Ltd." },
{ "B01266", "Futaba-Kikaku" },
{ "909DE0", "Newland Design + Assoc. Inc." },
{ "64D814", "Cisco Systems, Inc" },
{ "6CE4CE", "Villiger Security Solutions AG" },
{ "30F33A", "+plugg srl" },
{ "58CF4B", "Lufkin Industries" },
{ "C4393A", "SMC Networks Inc" },
{ "C4017C", "Ruckus Wireless" },
{ "D45C70", "Wi-Fi Alliance" },
{ "08EBED", "World Elite Technology Co.,LTD" },
{ "60BC4C", "EWM Hightec Welding GmbH" },
{ "F41E26", "Simon-Kaloi Engineering" },
{ "840B2D", "SAMSUNG ELECTRO-MECHANICS CO., LTD" },
{ "C44567", "SAMBON PRECISON and ELECTRONICS" },
{ "D0738E", "DONG OH PRECISION CO., LTD. " },
{ "E8718D", "Elsys Equipamentos Eletronicos Ltda" },
{ "3C83B5", "Advance Vision Electronics Co. Ltd." },
{ "808287", "ATCOM Technology Co.Ltd." },
{ "28A192", "GERP Solution" },
{ "A08C15", "Gerhard D. Wempe KG" },
{ "A02195", "Samsung Electronics Digital Imaging" },
{ "8CE081", "zte corporation" },
{ "485261", "SOREEL" },
{ "10FBF0", "KangSheng LTD." },
{ "3C57BD", "Kessler Crane Inc." },
{ "600F77", "SilverPlus, Inc" },
{ "6851B7", "PowerCloud Systems, Inc." },
{ "A44E2D", "Adaptive Wireless Solutions, LLC" },
{ "3CC12C", "AES Corporation" },
{ "0CCDFB", "EDIC Systems Inc." },
{ "3092F6", "SHANGHAI SUNMON COMMUNICATION TECHNOGY CO.,LTD" },
{ "2CE2A8", "DeviceDesign" },
{ "B49DB4", "Axion Technologies Inc." },
{ "D8182B", "Conti Temic Microelectronic GmbH" },
{ "304449", "PLATH GmbH" },
{ "94FD2E", "Shanghai Uniscope Technologies Co.,Ltd" },
{ "64A341", "Wonderlan (Beijing) Technology Co., Ltd." },
{ "8CAE4C", "Plugable Technologies" },
{ "D8D5B9", "Rainforest Automation, Inc." },
{ "C0A0E2", "Eden Innovations" },
{ "E8ABFA", "Shenzhen Reecam Tech.Ltd." },
{ "58874C", "LITE-ON CLEAN ENERGY TECHNOLOGY CORP." },
{ "E85BF0", "Imaging Diagnostics" },
{ "20DC93", "Cheetah Hi-Tech, Inc." },
{ "7846C4", "DAEHAP HYPER-TECH" },
{ "0CD9C1", "Visteon Corporation" },
{ "68AB8A", "RF IDeas" },
{ "70E24C", "SAE IT-systems GmbH & Co. KG" },
{ "88615A", "Siano Mobile Silicon Ltd." },
{ "30215B", "Shenzhen Ostar Display Electronic Co.,Ltd" },
{ "08D42B", "Samsung Electronics" },
{ "DC028E", "zte corporation" },
{ "DCB058", "Bürkert Werke GmbH" },
{ "641C67", "DIGIBRAS INDUSTRIA DO BRASILS/A" },
{ "C8E1A7", "Vertu Corporation Limited" },
{ "88D7BC", "DEP Company" },
{ "F49466", "CountMax,  ltd" },
{ "4CAB33", "KST technology" },
{ "5CE0F6", "NIC.br- Nucleo de Informacao e Coordenacao do Ponto BR" },
{ "00E666", "ARIMA Communications Corp." },
{ "F8E4FB", "Actiontec Electronics, Inc" },
{ "5887E2", "Shenzhen Coship Electronics Co., Ltd." },
{ "B4DFFA", "Litemax Electronics Inc." },
{ "48F8B3", "Cisco-Linksys, LLC" },
{ "681CA2", "Rosewill Inc." },
{ "7C092B", "Bekey A/S" },
{ "E892A4", "LG Electronics" },
{ "D808F5", "Arcadia Networks Co. Ltd. " },
{ "84DF0C", "NET2GRID BV" },
{ "3CB87A", "Private" },
{ "E425E9", "Color-Chip" },
{ "F44848", "Amscreen Group Ltd" },
{ "441319", "WKK TECHNOLOGY LTD." },
{ "088F2C", "Hills Sound Vision & Lighting" },
{ "3C9F81", "Shenzhen CATIC Bit Communications Technology Co.,Ltd" },
{ "18339D", "Cisco Systems, Inc" },
{ "642216", "Shandong Taixin Electronic co.,Ltd" },
{ "D43D7E", "Micro-Star Int'l Co, Ltd" },
{ "64517E", "LONG BEN (DONGGUAN) ELECTRONIC TECHNOLOGY CO.,LTD." },
{ "A816B2", "LG Electronics" },
{ "18E2C2", "Samsung Electronics" },
{ "0C57EB", "Mueller Systems" },
{ "48282F", "zte corporation" },
{ "745327", "COMMSEN CO., LIMITED" },
{ "E47185", "Securifi Ltd" },
{ "881036", "Panodic(ShenZhen) Electronics Limted" },
{ "18F87A", "i3 International Inc." },
{ "142DF5", "Amphitech" },
{ "C08ADE", "Ruckus Wireless" },
{ "90F72F", "Phillips Machine & Welding Co., Inc. " },
{ "B45570", "Borea" },
{ "5C5015", "Cisco Systems, Inc" },
{ "0CD2B5", "Binatone Telecommunication Pvt. Ltd" },
{ "1C62B8", "Samsung Electronics Co.,Ltd" },
{ "4846F1", "Uros Oy" },
{ "1CD40C", "Kriwan Industrie-Elektronik GmbH" },
{ "747B7A", "ETH Inc." },
{ "1C7C45", "Vitek Industrial Video Products, Inc." },
{ "FC94E3", "Technicolor USA Inc." },
{ "C8AE9C", "Shanghai TYD Elecronic Technology Co. Ltd" },
{ "A44C11", "Cisco Systems, Inc" },
{ "782544", "Omnima Limited" },
{ "D4DF57", "Alpinion Medical Systems" },
{ "5048EB", "BEIJING HAIHEJINSHENG NETWORK TECHNOLOGY CO. LTD." },
{ "40AC8D", "Data Management, Inc." },
{ "54466B", "Shenzhen CZTIC Electronic Technology Co., Ltd  " },
{ "08EDB9", "Hon Hai Precision Ind. Co.,Ltd." },
{ "1C3477", "Innovation Wireless" },
{ "4423AA", "Farmage Co., Ltd." },
{ "A0EF84", "Seine Image Int'l Co., Ltd" },
{ "AC7A42", "iConnectivity" },
{ "5869F9", "Fusion Transactive Ltd." },
{ "B0C83F", "Jiangsu Cynray IOT Co., Ltd." },
{ "CC14A6", "Yichun MyEnergy Domain, Inc" },
{ "98D686", "Chyi Lee industry Co., ltd." },
{ "20443A", "Schneider Electric Asia Pacific Ltd" },
{ "28C914", "Taimag Corporation" },
{ "4C7897", "Arrowhead Alarm Products Ltd" },
{ "AC0A61", "Labor S.r.L." },
{ "B482C5", "Relay2, Inc." },
{ "60D1AA", "Vishal Telecommunications Pvt Ltd" },
{ "CCC104", "Applied Technical Systems" },
{ "709BA5", "Shenzhen Y&D Electronics Co.,LTD." },
{ "EC42F0", "ADL Embedded Solutions, Inc." },
{ "10BD18", "Cisco Systems, Inc" },
{ "B0435D", "NuLEDs, Inc." },
{ "A82BD6", "Shina System Co., Ltd" },
{ "8CC7AA", "Radinet Communications Inc." },
{ "20014F", "Linea Research Ltd" },
{ "80D18B", "Hangzhou I'converge Technology Co.,Ltd" },
{ "B4A4B5", "Zen Eye Co.,Ltd" },
{ "489153", "Weinmann Geräte für Medizin GmbH + Co. KG" },
{ "549D85", "EnerAccess inc" },
{ "5CEE79", "Global Digitech Co LTD" },
{ "80F62E", "Hangzhou H3C Technologies Co., Limited" },
{ "9CE10E", "NCTech Ltd" },
{ "28F606", "Syes srl" },
{ "A0C3DE", "Triton Electronic Systems Ltd." },
{ "AC3FA4", "TAIYO YUDEN CO.,LTD" },
{ "0C130B", "Uniqoteq Ltd." },
{ "14CF8D", "OHSUNG ELECTRONICS CO., LTD." },
{ "808698", "Netronics Technologies Inc." },
{ "2C00F7", "XOS" },
{ "809393", "Xapt GmbH" },
{ "00DEFB", "Cisco Systems, Inc" },
{ "90AC3F", "BrightSign LLC" },
{ "7CACB2", "Bosch Software Innovations GmbH" },
{ "0043FF", "KETRON S.R.L." },
{ "745798", "TRUMPF Laser GmbH + Co. KG" },
{ "38E08E", "Mitsubishi Electric Corporation" },
{ "E4FA1D", "PAD Peripheral Advanced Design Inc." },
{ "4C9E80", "KYOKKO ELECTRIC Co., Ltd." },
{ "A826D9", "HTC Corporation" },
{ "F03A55", "Omega Elektronik AS" },
{ "24B88C", "Crenus Co.,Ltd." },
{ "98BC57", "SVA TECHNOLOGIES CO.LTD" },
{ "98FE03", "Ericsson - North America" },
{ "F0EEBB", "VIPAR GmbH" },
{ "54D0ED", "AXIM Communications" },
{ "A49005", "CHINA GREATWALL COMPUTER SHENZHEN CO.,LTD" },
{ "3055ED", "Trex Network LLC" },
{ "D4A02A", "Cisco Systems, Inc" },
{ "0463E0", "Nome Oy" },
{ "BCA4E1", "Nabto" },
{ "900A3A", "PSG Plastic Service GmbH" },
{ "FC5B26", "MikroBits" },
{ "5CC213", "Fr. Sauter AG" },
{ "581D91", "Advanced Mobile Telecom co.,ltd." },
{ "9CB008", "Ubiquitous Computing Technology Corporation" },
{ "00376D", "Murata Manufacturing Co., Ltd." },
{ "E0EF25", "Lintes Technology Co., Ltd." },
{ "CCEED9", "VAHLE DETO GmbH" },
{ "645EBE", "Yahoo! JAPAN" },
{ "CCC50A", "SHENZHEN DAJIAHAO TECHNOLOGY CO.,LTD" },
{ "D01AA7", "UniPrint" },
{ "B08E1A", "URadio Systems Co., Ltd" },
{ "40605A", "Hawkeye Tech Co. Ltd" },
{ "E05DA6", "Detlef Fink Elektronik & Softwareentwicklung" },
{ "0C7523", "BEIJING GEHUA CATV NETWORK CO.,LTD" },
{ "BC2C55", "Bear Flag Design, Inc." },
{ "04F4BC", "Xena Networks" },
{ "608C2B", "Hanson Technology" },
{ "EC1120", "FloDesign Wind Turbine Corporation" },
{ "D0F73B", "Helmut Mauell GmbH" },
{ "C495A2", "SHENZHEN WEIJIU INDUSTRY AND TRADE DEVELOPMENT CO., LTD" },
{ "0C9E91", "Sankosha Corporation" },
{ "F48771", "Infoblox" },
{ "04F021", "Compex Systems Pte Ltd" },
{ "8823FE", "TTTech Computertechnik AG" },
{ "98AAD7", "BLUE WAVE NETWORKING CO LTD" },
{ "20107A", "Gemtek Technology Co., Ltd." },
{ "502267", "PixeLINK" },
{ "9092B4", "Diehl BGT Defence GmbH & Co. KG" },
{ "806007", "RIM" },
{ "38A851", "Moog, Ing" },
{ "90185E", "Apex Tool Group GmbH & Co OHG" },
{ "14825B", "Hefei Radio Communication Technology Co., Ltd" },
{ "7CE9D3", "Hon Hai Precision Ind. Co.,Ltd." },
{ "8CC8CD", "Samsung Electronics Co., LTD" },
{ "649EF3", "Cisco Systems, Inc" },
{ "34D09B", "MobilMAX Technology Inc." },
{ "087572", "Obelux Oy" },
{ "9C1FDD", "Accupix Inc." },
{ "506441", "Greenlee" },
{ "80946C", "TOKYO RADAR CORPORATION" },
{ "00FA3B", "CLOOS ELECTRONIC GMBH" },
{ "28CD1C", "Espotel Oy" },
{ "D824BD", "Cisco Systems, Inc" },
{ "D878E5", "KUHN SA" },
{ "C49300", "8Devices" },
{ "4C3910", "Newtek Electronics co., Ltd." },
{ "5866BA", "Hangzhou H3C Technologies Co., Limited" },
{ "5808FA", "Fiber Optic & telecommunication INC." },
{ "7C94B2", "Philips Healthcare PCCI" },
{ "200505", "RADMAX COMMUNICATION PRIVATE LIMITED" },
{ "5848C0", "COFLEC" },
{ "C8F704", "Building Block Video" },
{ "C8AF40", "marco Systemanalyse und Entwicklung GmbH" },
{ "AC319D", "Shenzhen TG-NET Botone Technology Co.,Ltd." },
{ "08D09F", "Cisco Systems, Inc" },
{ "D0DFC7", "Samsung Electronics Co.,Ltd" },
{ "B81413", "Keen High Holding(HK) Ltd." },
{ "2037BC", "Kuipers Electronic Engineering BV" },
{ "A887ED", "ARC Wireless LLC" },
{ "983571", "Sub10 Systems Ltd" },
{ "B05CE5", "Nokia Corporation" },
{ "4813F3", "BBK Electronics Corp., Ltd." },
{ "CC6BF1", "Sound Masking Inc." },
{ "B82CA0", "Honeywell HomMed" },
{ "94AE61", "Alcatel Lucent" },
{ "7CA61D", "MHL, LLC" },
{ "5CCEAD", "CDYNE Corporation" },
{ "9CA3BA", "SAKURA Internet Inc." },
{ "709756", "Happyelectronics Co.,Ltd" },
{ "D4206D", "HTC Corporation" },
{ "1866E3", "Veros Systems, Inc." },
{ "00B338", "Kontron Design Manufacturing Services (M) Sdn. Bhd" },
{ "94DE0E", "SmartOptics AS" },
{ "A429B7", "bluesky" },
{ "700514", "LG Electronics" },
{ "7C6B33", "Tenyu Tech Co. Ltd." },
{ "CCB8F1", "EAGLE KINGDOM TECHNOLOGIES LIMITED" },
{ "DC2E6A", "HCT. Co., Ltd." },
{ "34255D", "Shenzhen Loadcom Technology Co.,Ltd" },
{ "1897FF", "TechFaith Wireless Technology Limited" },
{ "0CDFA4", "Samsung Electronics Co.,Ltd" },
{ "8C8E76", "taskit GmbH" },
{ "B4D8DE", "iota Computing, Inc." },
{ "54CDA7", "Fujian Shenzhou Electronic Co.,Ltd" },
{ "1000FD", "LaonPeople" },
{ "603553", "Buwon Technology" },
{ "B89BC9", "SMC Networks Inc" },
{ "48022A", "B-Link Electronic Limited" },
{ "48A6D2", "GJsun Optical Science and Tech Co.,Ltd." },
{ "186D99", "Adanis Inc." },
{ "047D7B", "Quanta Computer Inc." },
{ "D44B5E", "TAIYO YUDEN CO., LTD." },
{ "B40C25", "Palo Alto Networks" },
{ "40BF17", "Digistar Telecom. SA" },
{ "E4AFA1", "HES-SO" },
{ "58920D", "Kinetic Avionics Limited" },
{ "207600", "Actiontec Electronics, Inc" },
{ "84D32A", "IEEE 1905.1" },
{ "F8E7B5", "Tech Tecnologia LTDA" },
{ "0462D7", "ALSTOM HYDRO FRANCE" },
{ "CCC8D7", "CIAS Elettronica srl" },
{ "64AE0C", "Cisco Systems, Inc" },
{ "A446FA", "AmTRAN Video Corporation" },
{ "2804E0", "FERMAX ELECTRONICA S.A.U." },
{ "FC01CD", "FUNDACION TEKNIKER" },
{ "88E7A6", "iKnowledge Integration Corp." },
{ "98E79A", "Foxconn(NanJing) Communication Co.,Ltd." },
{ "54F5B6", "ORIENTAL PACIFIC INTERNATIONAL LIMITED" },
{ "34A55D", "TECHNOSOFT INTERNATIONAL SRL" },
{ "D0C282", "Cisco Systems, Inc" },
{ "449CB5", "Alcomp, Inc" },
{ "E4D53D", "Hon Hai Precision Ind. Co.,Ltd." },
{ "24E6BA", "JSC Zavod im. Kozitsky" },
{ "8C8A6E", "ESTUN AUTOMATION TECHNOLOY CO., LTD" },
{ "E0ED1A", "vastriver Technology Co., Ltd" },
{ "C83B45", "JRI-Maxant" },
{ "685E6B", "PowerRay Co., Ltd." },
{ "4C32D9", "M Rutty Holdings Pty. Ltd." },
{ "50A733", "Ruckus Wireless" },
{ "603FC5", "COX CO., LTD" },
{ "182B05", "8D Technologies" },
{ "54A9D4", "Minibar Systems" },
{ "4861A3", "Concern Axion JSC" },
{ "D89685", "GoPro" },
{ "08A12B", "ShenZhen EZL Technology Co., Ltd" },
{ "94319B", "Alphatronics BV" },
{ "08FC52", "OpenXS BV" },
{ "205B5E", "Shenzhen Wonhe Technology Co., Ltd" },
{ "3CC99E", "Huiyang Technology Co., Ltd" },
{ "C8A1BA", "Neul Ltd" },
{ "AC02EF", "Comsis" },
{ "C43A9F", "Siconix Inc." },
{ "0418B6", "Private" },
{ "D4024A", "Delphian Systems LLC" },
{ "84248D", "Zebra Technologies Inc" },
{ "24EC99", "ASKEY COMPUTER CORP" },
{ "9463D1", "Samsung Electronics Co.,Ltd" },
{ "B8621F", "Cisco Systems, Inc" },
{ "B45CA4", "Thing-talk Wireless Communication Technologies Corporation Limited" },
{ "AC8ACD", "ROGER D.Wensker, G.Wensker sp.j." },
{ "984246", "SOL INDUSTRY PTE., LTD" },
{ "28A574", "Miller Electric Mfg. Co." },
{ "3826CD", "ANDTEK" },
{ "C436DA", "Rusteletech Ltd." },
{ "00FC70", "Intrepid Control Systems, Inc." },
{ "A4EE57", "SEIKO EPSON CORPORATION" },
{ "D0AFB6", "Linktop Technology Co., LTD" },
{ "444F5E", "Pan Studios Co.,Ltd." },
{ "0C3956", "Observator instruments" },
{ "A49981", "FuJian Elite Power Tech CO.,LTD." },
{ "B83A7B", "Worldplay (Canada) Inc." },
{ "783F15", "EasySYNC Ltd." },
{ "F4B549", "Yeastar Technology Co., Ltd." },
{ "88B168", "Delta Control GmbH" },
{ "20B399", "Enterasys" },
{ "18B79E", "Invoxia" },
{ "147411", "RIM" },
{ "5C56ED", "3pleplay Electronics Private Limited" },
{ "0838A5", "Funkwerk plettac electronic GmbH" },
{ "BCCD45", "VOISMART" },
{ "78028F", "Adaptive Spectrum and Signal Alignment (ASSIA), Inc." },
{ "D4A425", "SMAX Technology Co., Ltd." },
{ "98F8DB", "Marini Impianti Industriali s.r.l." },
{ "140708", "Private" },
{ "24C9DE", "Genoray" },
{ "605464", "Eyedro Green Solutions Inc." },
{ "54055F", "Alcatel Lucent" },
{ "405539", "Cisco Systems, Inc" },
{ "B8BEBF", "Cisco Systems, Inc" },
{ "38FEC5", "Ellips B.V." },
{ "24C86E", "Chaney Instrument Co." },
{ "D4D898", "Korea CNO Tech Co., Ltd" },
{ "04180F", "Samsung Electronics Co.,Ltd" },
{ "5070E5", "He Shan World Fair Electronics Technology Limited" },
{ "28EE2C", "Frontline Test Equipment" },
{ "802275", "Beijing Beny Wave Technology Co Ltd" },
{ "BC8199", "BASIC Co.,Ltd." },
{ "000726", "Shenzhen Gongjin Electronics Co., Ltd." },
{ "24470E", "PentronicAB" },
{ "A4DB2E", "Kingspan Environmental Ltd" },
{ "F44EFD", "Actions Semiconductor Co.,Ltd.(Cayman Islands)" },
{ "34BCA6", "Beijing Ding Qing Technology, Ltd." },
{ "D4C1FC", "Nokia Corporation" },
{ "48DCFB", "Nokia Corporation" },
{ "CC051B", "Samsung Electronics Co.,Ltd" },
{ "688470", "eSSys Co.,Ltd" },
{ "3CBDD8", "LG ELECTRONICS INC" },
{ "F08BFE", "COSTEL.,CO.LTD" },
{ "5435DF", "Symeo GmbH" },
{ "F43D80", "FAG Industrial Services GmbH" },
{ "D4F0B4", "Napco Security Technologies" },
{ "40B3FC", "Logital Co. Limited " },
{ "D05FCE", "Hitachi Data Systems" },
{ "8C82A8", "Insigma Technology Co.,Ltd" },
{ "3C2763", "SLE quality engineering GmbH & Co. KG" },
{ "A44B15", "Sun Cupid Technology (HK) LTD" },
{ "508ACB", "SHENZHEN MAXMADE TECHNOLOGY CO., LTD." },
{ "7032D5", "Athena Wireless Communications Inc" },
{ "7CF0BA", "Linkwell Telesystems Pvt Ltd" },
{ "CCC62B", "Tri-Systems Corporation" },
{ "ACF97E", "ELESYS INC." },
{ "4C7367", "Genius Bytes Software Solutions GmbH" },
{ "DC2B66", "InfoBLOCK S.A. de C.V." },
{ "14F0C5", "Xtremio Ltd." },
{ "C027B9", "Beijing National Railway Research & Design Institute  of Signal & Communication Co., Ltd." },
{ "70A41C", "Advanced Wireless Dynamics S.L." },
{ "285132", "Shenzhen Prayfly Technology Co.,Ltd" },
{ "4C3B74", "VOGTEC(H.K.) Co., Ltd" },
{ "509772", "Westinghouse Digital" },
{ "D85D84", "CAx soft GmbH" },
{ "78A683", "Precidata" },
{ "BC6784", "Environics Oy" },
{ "B4E0CD", "Fusion-io, Inc" },
{ "50AF73", "Shenzhen Bitland Information Technology Co., Ltd." },
{ "488E42", "DIGALOG GmbH" },
{ "286046", "Lantech Communications Global, Inc." },
{ "A424B3", "FlatFrog Laboratories AB" },
{ "A4856B", "Q Electronics Ltd" },
{ "84EA99", "Vieworks" },
{ "DCCBA8", "Explora Technologies Inc" },
{ "58EECE", "Icon Time Systems" },
{ "90004E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A41BC0", "Fastec Imaging Corporation" },
{ "E01F0A", "Xslent Energy Technologies. LLC" },
{ "F40321", "BeNeXt B.V." },
{ "00B033", "OAO Izhevskiy radiozavod" },
{ "707EDE", "NASTEC LTD." },
{ "CCBE71", "OptiLogix BV" },
{ "D8B12A", "Panasonic Mobile Communications Co., Ltd." },
{ "7CDD90", "Shenzhen Ogemray Technology Co., Ltd." },
{ "C07E40", "SHENZHEN XDK COMMUNICATION EQUIPMENT CO.,LTD" },
{ "E44F29", "MA Lighting Technology GmbH" },
{ "6CAB4D", "Digital Payment Technologies" },
{ "60A10A", "Samsung Electronics Co.,Ltd" },
{ "60DA23", "Estech Co.,Ltd" },
{ "C0F8DA", "Hon Hai Precision Ind. Co.,Ltd." },
{ "28F358", "2C - Trifonov & Co" },
{ "304C7E", "Panasonic Electric Works Automation Controls Techno Co.,Ltd." },
{ "64D1A3", "Sitecom Europe BV" },
{ "3831AC", "WEG" },
{ "2C7ECF", "Onzo Ltd" },
{ "10E3C7", "Seohwa Telecom" },
{ "E84040", "Cisco Systems, Inc" },
{ "0C8112", "Private" },
{ "3822D6", "H3C Technologies Co., Limited" },
{ "7C7D41", "Jinmuyu Electronics Co., Ltd." },
{ "4C1480", "NOREGON SYSTEMS, INC" },
{ "8C71F8", "Samsung Electronics Co.,Ltd" },
{ "A07591", "Samsung Electronics Co.,Ltd" },
{ "60F673", "TERUMO CORPORATION" },
{ "E48AD5", "RF WINDOW CO., LTD." },
{ "24F0FF", "GHT Co., Ltd." },
{ "4C07C9", "COMPUTER OFFICE Co.,Ltd." },
{ "40F4EC", "Cisco Systems, Inc" },
{ "2872F0", "ATHENA" },
{ "9C807D", "SYSCABLE Korea Inc." },
{ "180B52", "Nanotron Technologies GmbH" },
{ "64DE1C", "Kingnetic Pte Ltd" },
{ "540496", "Gigawave LTD" },
{ "C8C126", "ZPM Industria e Comercio Ltda" },
{ "041D10", "Dream Ware Inc." },
{ "88DD79", "Voltaire" },
{ "4468AB", "JUIN COMPANY, LIMITED" },
{ "902E87", "LabJack" },
{ "C8208E", "Storagedata" },
{ "00B342", "MacroSAN Technologies Co., Ltd." },
{ "4CB9C8", "CONET CO., LTD." },
{ "0474A1", "Aligera Equipamentos Digitais Ltda" },
{ "1064E2", "ADFweb.com s.r.l." },
{ "CC34D7", "GEWISS S.P.A." },
{ "B4CFDB", "Shenzhen Jiuzhou Electric Co.,LTD" },
{ "C46354", "U-Raku, Inc." },
{ "20FEDB", "M2M Solution S.A.S." },
{ "405FBE", "RIM" },
{ "E05B70", "Innovid, Co., Ltd." },
{ "043604", "Gyeyoung I&T" },
{ "50CE75", "Measy Electronics Ltd" },
{ "34F968", "ATEK Products, LLC" },
{ "D0D0FD", "Cisco Systems, Inc" },
{ "706417", "ORBIS TECNOLOGIA ELECTRICA S.A." },
{ "64FC8C", "Zonar Systems" },
{ "28ED58", "JAG Jakob AG" },
{ "9873C4", "Sage Electronic Engineering LLC" },
{ "B8797E", "Secure Meters (UK) Limited" },
{ "2005E8", "OOO InProMedia" },
{ "E0D10A", "Katoudenkikougyousyo co ltd" },
{ "1C0656", "IDY Corporation" },
{ "C44B44", "Omniprint Inc." },
{ "6015C7", "IdaTech" },
{ "188ED5", "TP Vision Belgium N.V. - innovation site Brugge" },
{ "E81132", "Samsung Electronics CO., LTD" },
{ "8CE7B3", "Sonardyne International Ltd" },
{ "0034F1", "Radicom Research, Inc." },
{ "A8B0AE", "LEONI " },
{ "60893C", "Thermo Fisher Scientific P.O.A." },
{ "5C17D3", "LGE " },
{ "347877", "O-NET Communications(Shenzhen) Limited" },
{ "70A191", "Trendsetter Medical, LLC" },
{ "A49B13", "Burroughs Payment Systems, Inc." },
{ "58BC27", "Cisco Systems, Inc" },
{ "34D2C4", "RENA GmbH Print Systeme" },
{ "4C0F6E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E0A670", "Nokia Corporation" },
{ "E061B2", "HANGZHOU ZENOINTEL TECHNOLOGY CO., LTD" },
{ "4491DB", "Shanghai Huaqin Telecom Technology Co.,Ltd" },
{ "14D76E", "CONCH ELECTRONIC Co.,Ltd" },
{ "CC6B98", "Minetec Wireless Technologies" },
{ "C4CD45", "Beijing Boomsense Technology CO.,LTD." },
{ "D0BB80", "SHL Telemedicine International Ltd." },
{ "1C83B0", "Linked IP GmbH" },
{ "F065DD", "Primax Electronics Ltd." },
{ "706582", "Suzhou Hanming Technologies Co., Ltd." },
{ "94C7AF", "Raylios Technology" },
{ "6854F5", "enLighted Inc" },
{ "008C10", "Black Box Corp." },
{ "20A2E7", "Lee-Dickens Ltd" },
{ "8CDD8D", "Wifly-City System Inc." },
{ "EC98C1", "Beijing Risbo Network Technology Co.,Ltd" },
{ "ECC38A", "Accuenergy (CANADA) Inc" },
{ "D48FAA", "Sogecam Industrial, S.A." },
{ "38A95F", "Actifio Inc" },
{ "A0DDE5", "SHARP Corporation" },
{ "94A7BC", "BodyMedia, Inc." },
{ "6C9B02", "Nokia Corporation" },
{ "84DB2F", "Sierra Wireless Inc" },
{ "A45055", "busware.de" },
{ "2CD2E7", "Nokia Corporation" },
{ "C89383", "Embedded Automation, Inc." },
{ "D49E6D", "Wuhan Zhongyuan Huadian Science & Technology Co.," },
{ "94F720", "Tianjin Deviser Electronics Instrument Co., Ltd" },
{ "5C6D20", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E02A82", "Universal Global Scientific Industrial Co., Ltd." },
{ "EC2368", "IntelliVoice Co.,Ltd." },
{ "B45253", "Seagate Technology" },
{ "04DD4C", "Velocytech" },
{ "B4C810", "UMPI Elettronica" },
{ "38580C", "Panaccess Systems GmbH" },
{ "24AF54", "NEXGEN Mediatech Inc." },
{ "F0F9F7", "IES GmbH & Co. KG" },
{ "CC0CDA", "Miljovakt AS" },
{ "C01242", "Alpha Security Products" },
{ "90507B", "Advanced PANMOBIL Systems GmbH & Co. KG" },
{ "00B5D6", "Omnibit Inc." },
{ "F893F3", "VOLANS" },
{ "7C3E9D", "PATECH" },
{ "4C60D5", "airPointe of New Hampshire" },
{ "48F8E1", "Alcatel Lucent WT" },
{ "D45297", "nSTREAMS Technologies, Inc." },
{ "78EC22", "Shanghai Qihui Telecom Technology Co., LTD" },
{ "F8D756", "Simm Tronic Limited " },
{ "E087B1", "Nata-Info Ltd." },
{ "A8B1D4", "Cisco Systems, Inc" },
{ "4CBAA3", "Bison Electronics Inc." },
{ "EC7C74", "Justone Technologies Co., Ltd." },
{ "3C1A79", "Huayuan Technology CO.,LTD" },
{ "30E48E", "Vodafone UK" },
{ "08512E", "Orion Diagnostica Oy" },
{ "9CF61A", "UTC Fire and Security" },
{ "80A1D7", "Shanghai DareGlobal Technologies Co.,Ltd " },
{ "C802A6", "Beijing Newmine Technology" },
{ "C84C75", "Cisco Systems, Inc" },
{ "68EBAE", "Samsung Electronics Co.,Ltd" },
{ "284C53", "Intune Networks" },
{ "102D96", "Looxcie Inc." },
{ "3037A6", "Cisco Systems, Inc" },
{ "ACEA6A", "GENIX INFOCOMM CO., LTD." },
{ "7C2064", "Alcatel Lucent IPD" },
{ "5C35DA", "There Corporation Oy" },
{ "005218", "Wuxi Keboda Electron Co.Ltd" },
{ "C09134", "ProCurve Networking by HP" },
{ "F07BCB", "Hon Hai Precision Ind. Co.,Ltd." },
{ "08F2F4", "Net One Partners Co.,Ltd." },
{ "68EFBD", "Cisco Systems, Inc" },
{ "5CFF35", "Wistron Corporation" },
{ "183BD2", "BYD Precision Manufacture Company Ltd." },
{ "F45595", "HENGBAO Corporation LTD." },
{ "C08B6F", "S I Sistemas Inteligentes Eletrônicos Ltda" },
{ "BCA9D6", "Cyber-Rain, Inc." },
{ "0CDDEF", "Nokia Corporation" },
{ "80C63F", "Remec Broadband Wireless , LLC" },
{ "F09CBB", "RaonThink Inc." },
{ "FCE23F", "CLAY PAKY SPA" },
{ "B0E39D", "CAT SYSTEM CO.,LTD." },
{ "78A6BD", "DAEYEON Control&Instrument Co,.Ltd" },
{ "481249", "Luxcom Technologies Inc." },
{ "B43DB2", "Degreane Horizon" },
{ "C4823F", "Fujian Newland Auto-ID Tech. Co,.Ltd." },
{ "F4C795", "WEY Elektronik AG" },
{ "087695", "Auto Industrial Co., Ltd." },
{ "ACCE8F", "HWA YAO TECHNOLOGIES CO., LTD" },
{ "042F56", "ATOCS (Shenzhen) LTD" },
{ "084E1C", "H2A Systems, LLC" },
{ "A4B121", "Arantia 2010 S.L." },
{ "9889ED", "Anadem Information Inc." },
{ "147373", "TUBITAK UEKAE" },
{ "982D56", "Resolution Audio" },
{ "00A2DA", "INAT GmbH" },
{ "6C3E9C", "KE Knestel Elektronik GmbH" },
{ "F89D0D", "Control Technology Inc." },
{ "1010B6", "McCain Inc" },
{ "081FF3", "Cisco Systems, Inc" },
{ "5CE286", "Nortel Networks" },
{ "2CCD27", "Precor Inc" },
{ "6C5E7A", "Ubiquitous Internet Telecom Co., Ltd" },
{ "D828C9", "General Electric Consumer and Industrial" },
{ "C86C1E", "Display Systems Ltd" },
{ "EC6C9F", "Chengdu Volans Technology CO.,LTD" },
{ "CCCC4E", "Sun Fountainhead USA. Corp " },
{ "60D30A", "Quatius Limited" },
{ "BC9DA5", "DASCOM Europe GmbH" },
{ "60D0A9", "Samsung Electronics Co.,Ltd" },
{ "942E63", "Finsécur" },
{ "C8D2C1", "Jetlun (Shenzhen) Corporation" },
{ "F0BCC8", "MaxID (Pty) Ltd" },
{ "406186", "MICRO-STAR INT'L CO.,LTD" },
{ "74E537", "RADSPIN" },
{ "C417FE", "Hon Hai Precision Ind. Co.,Ltd." },
{ "7C08D9", "Shanghai B-Star Technology Co" },
{ "448E81", "VIG" },
{ "2046F9", "Advanced Network Devices (dba:AND)" },
{ "6CD68A", "LG Electronics Inc" },
{ "681FD8", "Advanced Telemetry" },
{ "0C8230", "SHENZHEN MAGNUS TECHNOLOGIES CO.,LTD" },
{ "049F81", "Netscout Systems, Inc." },
{ "50934F", "Gradual Tecnologia Ltda." },
{ "34EF8B", "NTT Communications Corporation" },
{ "38E98C", "Reco S.p.A." },
{ "F02408", "Talaris (Sweden) AB" },
{ "A06986", "Wellav Technologies Ltd" },
{ "F02FD8", "Bi2-Vision" },
{ "C86CB6", "Optcom Co., Ltd." },
{ "C45976", "Fugoo Coorporation" },
{ "B0C8AD", "People Power Company" },
{ "A8F274", "Samsung Electronics" },
{ "A870A5", "UniComm Inc." },
{ "80177D", "Nortel Networks" },
{ "E8DAAA", "VideoHome Technology Corp." },
{ "647D81", "YOKOTA INDUSTRIAL CO,.LTD" },
{ "8891DD", "Racktivity" },
{ "C4198B", "Dominion Voting Systems Corporation" },
{ "C83A35", "Tenda Technology Co., Ltd." },
{ "F4ACC1", "Cisco Systems, Inc" },
{ "584CEE", "Digital One Technologies, Limited" },
{ "E064BB", "DigiView S.r.l." },
{ "4C63EB", "Application Solutions (Electronics and Vision) Ltd" },
{ "C01E9B", "Pixavi AS" },
{ "64168D", "Cisco Systems, Inc" },
{ "24D2CC", "SmartDrive Systems Inc." },
{ "7C6C8F", "AMS NEVE LTD" },
{ "C4E17C", "U2S co." },
{ "A8C222", "TM-Research Inc." },
{ "50252B", "Nethra Imaging Incorporated" },
{ "A4DA3F", "Bionics Corp." },
{ "9C4E8E", "ALT Systems Ltd" },
{ "448312", "Star-Net" },
{ "687924", "ELS-GmbH & Co. KG" },
{ "38BB23", "OzVision America LLC" },
{ "003A99", "Cisco Systems, Inc" },
{ "04C05B", "Tigo Energy" },
{ "5C1437", "Thyssenkrupp Aufzugswerke GmbH" },
{ "9C55B4", "I.S.E. S.r.l." },
{ "DC2C26", "Iton Technology Limited" },
{ "4CC452", "Shang Hai Tyd. Electon Technology Ltd." },
{ "F0C24C", "Zhejiang FeiYue Digital Technology Co., Ltd" },
{ "08184C", "A. S. Thomas, Inc." },
{ "5CE223", "Delphin Technology AG" },
{ "FC6198", "NEC Personal Products, Ltd" },
{ "F871FE", "The Goldman Sachs Group, Inc." },
{ "D8C3FB", "DETRACOM" },
{ "201257", "Most Lucky Trading Ltd" },
{ "2021A5", "LG Electronics Inc" },
{ "D49C28", "JayBird LLC" },
{ "A03A75", "PSS Belgium N.V." },
{ "746B82", "MOVEK " },
{ "0C8411", "A.O. Smith Water Products" },
{ "F8E968", "Egker Kft." },
{ "E8DFF2", "PRF Co., Ltd." },
{ "006440", "Cisco Systems, Inc" },
{ "D0E40B", "Wearable Inc." },
{ "AC867E", "Create New Technology (HK) Limited Company" },
{ "58F67B", "Xia Men UnionCore Technology LTD." },
{ "A02EF3", "United Integrated Services Co., Led." },
{ "A8CE90", "CVC" },
{ "00271F", "MIPRO Electronics Co., Ltd" },
{ "00271A", "Geenovo Technology Ltd." },
{ "002714", "Grainmustards, Co,ltd." },
{ "002717", "CE Digital(Zhenjiang)Co.,Ltd" },
{ "002708", "Nordiag ASA" },
{ "002701", "INCOstartec GmbH" },
{ "002702", "SolarEdge Technologies" },
{ "0026FB", "AirDio Wireless, Inc." },
{ "0026F5", "XRPLUS Inc." },
{ "002632", "Instrumentation Technologies d.d." },
{ "00262D", "Wistron Corporation" },
{ "00262C", "IKT Advanced Technologies s.r.o." },
{ "002626", "Geophysical Survey Systems, Inc." },
{ "00261F", "SAE Magnetics (H.K.) Ltd." },
{ "002620", "ISGUS GmbH" },
{ "00261A", "Femtocomm System Technology Corp." },
{ "002613", "Engel Axil S.L." },
{ "00260D", "Mercury Systems, Inc." },
{ "0025D8", "KOREA MAINTENANCE" },
{ "0025CC", "Mobile Communications Korea Incorporated" },
{ "0025C5", "Star Link Communication Pvt. Ltd." },
{ "0025C6", "kasercorp, ltd" },
{ "0025C0", "ZillionTV Corporation" },
{ "0025B4", "Cisco Systems, Inc" },
{ "0025B9", "Cypress Solutions Inc" },
{ "0025AD", "Manufacturing Resources International" },
{ "002600", "TEAC Australia Pty Ltd." },
{ "002607", "Enabling Technology Pty Ltd" },
{ "0025FB", "Tunstall Healthcare A/S" },
{ "0025FA", "J&M Analytik AG" },
{ "0025F6", "netTALK.com, Inc." },
{ "0025EF", "I-TEC Co., Ltd." },
{ "0025E9", "i-mate Development, Inc." },
{ "0025DF", "Private" },
{ "002690", "I DO IT" },
{ "00268A", "Terrier SC Ltd" },
{ "002689", "General Dynamics Robotic Systems" },
{ "002684", "KISAN SYSTEM" },
{ "002683", "Ajoho Enterprise Co., Ltd." },
{ "00267D", "A-Max Technology Macao Commercial Offshore Company Limited" },
{ "002677", "DEIF A/S" },
{ "002671", "AUTOVISION Co., Ltd" },
{ "00266A", "ESSENSIUM NV" },
{ "0026EF", "Technology Advancement Group, Inc." },
{ "0026E9", "SP Corp" },
{ "0026E2", "LG Electronics" },
{ "0026DC", "Optical Systems Design" },
{ "0026D6", "Ningbo Andy Optoelectronic Co., Ltd." },
{ "0026CF", "DEKA R&D" },
{ "0026D0", "Semihalf" },
{ "0026CA", "Cisco Systems, Inc" },
{ "0026C9", "Proventix Systems, Inc." },
{ "0026C3", "Insightek Corp." },
{ "002664", "Core System Japan" },
{ "002658", "T-Platforms (Cyprus) Limited" },
{ "002645", "Circontrol S.A." },
{ "00263F", "LIOS Technology GmbH" },
{ "002639", "T.M. Electronics, Inc." },
{ "0026BD", "JTEC Card & Communication Co., Ltd." },
{ "0026B3", "Thales Communications Inc" },
{ "0026AD", "Arada Systems, Inc." },
{ "0026A9", "Strong Technologies Pty Ltd" },
{ "0026A3", "FQ Ingenieria Electronica S.A." },
{ "00269C", "ITUS JAPAN CO. LTD" },
{ "002696", "NOOLIX Co., Ltd" },
{ "002484", "Bang and Olufsen Medicom a/s" },
{ "002486", "DesignArt Networks" },
{ "00247F", "Nortel Networks" },
{ "002478", "Mag Tech Electronics Co Limited" },
{ "002471", "Fusion MultiSystems dba Fusion-io" },
{ "002473", "3COM EUROPE LTD" },
{ "002460", "Giaval Science Development Co. Ltd." },
{ "00245B", "RAIDON TECHNOLOGY, INC." },
{ "00244E", "RadChips, Inc." },
{ "002447", "Kaztek Systems" },
{ "002442", "Axona Limited" },
{ "00243D", "Emerson Appliance Motors and Controls" },
{ "002528", "Daido Signal Co., Ltd." },
{ "002523", "OCP Inc." },
{ "00251E", "ROTEL TECHNOLOGIES" },
{ "002519", "Viaas Inc" },
{ "002514", "PC Worth Int'l Co., Ltd." },
{ "00250D", "GZT Telkom-Telmor sp. z o.o." },
{ "002506", "A.I. ANTITACCHEGGIO ITALIA SRL" },
{ "002508", "Maquet Cardiopulmonary AG" },
{ "00257A", "CAMCO Produktions- und Vertriebs-GmbH für  Beschallungs- und Beleuchtungsanlagen" },
{ "00257F", "CallTechSolution Co.,Ltd" },
{ "002573", "ST Electronics (Info-Security) Pte Ltd" },
{ "002567", "Samsung Electronics" },
{ "00256E", "Van Breda B.V." },
{ "00256D", "Broadband Forum" },
{ "002560", "Ibridge Networks & Communications Ltd." },
{ "00255B", "CoachComm, LLC" },
{ "0024E2", "HASEGAWA ELECTRIC CO.,LTD." },
{ "0024DB", "Alcohol Monitoring Systems" },
{ "0024CF", "Inscape Data Corporation" },
{ "0024C8", "Broadband Solutions Group" },
{ "0024C3", "Cisco Systems, Inc" },
{ "0024C0", "NTI COMODO INC" },
{ "0024B6", "Seagate Technology" },
{ "0024BB", "CENTRAL Corporation" },
{ "0024B1", "Coulomb Technologies" },
{ "0024AA", "Dycor Technologies Ltd." },
{ "0024A3", "Sonim Technologies Inc" },
{ "00249E", "ADC-Elektronik GmbH" },
{ "00248B", "HYBUS CO., LTD." },
{ "002492", "Motorola, Broadband Solutions Group" },
{ "002497", "Cisco Systems, Inc" },
{ "002554", "Pixel8 Networks" },
{ "00254D", "Singapore Technologies Electronics Limited" },
{ "00254E", "Vertex Wireless Co., Ltd." },
{ "002537", "Runcom Technologies Ltd." },
{ "00253E", "Sensus Metering Systems" },
{ "002541", "Maquet Critical Care AB" },
{ "00252D", "Kiryung Electronics" },
{ "0025A6", "Central Network Solution Co., Ltd." },
{ "0025A1", "Enalasys" },
{ "00259A", "CEStronics GmbH" },
{ "002593", "DatNet Informatikai Kft." },
{ "002594", "Eurodesign BG LTD" },
{ "00258E", "The Weather Channel" },
{ "00258A", "Pole/Zero Corporation" },
{ "002589", "Hills Industries Limited" },
{ "002584", "Cisco Systems, Inc" },
{ "002501", "JSC Supertel" },
{ "0024FA", "Hilger u. Kern GMBH" },
{ "0024F5", "NDS Surgical Imaging" },
{ "0024EE", "Wynmax Inc." },
{ "0024E7", "Plaster Networks" },
{ "0023F2", "TVLogic" },
{ "0023E8", "Demco Corp." },
{ "0023E1", "Cavena Image Products AB" },
{ "0023DC", "Benein, Inc" },
{ "0023DB", "saxnet gmbh" },
{ "0023C9", "Sichuan Tianyi Information Science & Technology Stock CO.,LTD" },
{ "0023CE", "KITA DENSHI CORPORATION" },
{ "0023D5", "WAREMA electronic GmbH" },
{ "002421", "MICRO-STAR INT'L CO., LTD." },
{ "002414", "Cisco Systems, Inc" },
{ "002415", "Magnetic Autocontrol GmbH" },
{ "00240F", "Ishii Tool & Engineering Corporation" },
{ "002408", "Pacific Biosciences" },
{ "002402", "Op-Tection GmbH" },
{ "0023FC", "Ultra Stereo Labs, Inc" },
{ "0023CF", "CUMMINS-ALLISON CORP." },
{ "0023C2", "SAMSUNG Electronics. Co. LTD" },
{ "0023B6", "SECURITE COMMUNICATIONS / HONEYWELL" },
{ "0023BC", "EQ-SYS GmbH" },
{ "0023AA", "HFR, Inc." },
{ "0023A9", "Beijing Detianquan Electromechanical Equipment Co., Ltd" },
{ "002341", "Siemens AB, Infrastructure & Cities, Building Technologies Division, IC BT SSP SP BA PR" },
{ "00233C", "Alflex" },
{ "00233B", "C-Matic Systems Ltd" },
{ "002335", "Linkflex Co.,Ltd" },
{ "00232D", "SandForce" },
{ "002328", "ALCON TELECOMMUNICATIONS CO., LTD." },
{ "002321", "Avitech International Corp" },
{ "0022F8", "PIMA Electronic Systems Ltd." },
{ "00231F", "Guangda Electronic & Telecommunication Technology Development Co., Ltd." },
{ "0022E6", "Intelligent Data" },
{ "0022E0", "Atlantic Software Technologies S.r.L." },
{ "0022DF", "TAMUZ Monitors" },
{ "0022DA", "ANATEK, LLC" },
{ "0022D3", "Hub-Tech" },
{ "0022CD", "Ared Technology Co., Ltd." },
{ "0022C4", "epro GmbH" },
{ "0022C9", "Lenord, Bauer & Co GmbH" },
{ "0022BF", "SieAmp Group of Companies" },
{ "0022B9", "Analogix Seminconductor, Inc" },
{ "0022BA", "HUTH Elektronik Systeme GmbH" },
{ "00239D", "Mapower Electronics Co., Ltd" },
{ "002397", "Westell Technologies Inc." },
{ "002392", "Proteus Industries Inc." },
{ "00238D", "Techno Design Co., Ltd." },
{ "002389", "HANGZHOU H3C Technologies Co., Ltd." },
{ "002388", "V.T. Telematica S.p.a." },
{ "002383", "InMage Systems Inc" },
{ "00237C", "NEOTION" },
{ "002324", "G-PRO COMPUTER" },
{ "002431", "Uni-v co.,ltd" },
{ "00241B", "iWOW Communications Pte Ltd" },
{ "002422", "Knapp Logistik Automation GmbH" },
{ "002427", "SSI COMPUTER CORP" },
{ "002373", "GridIron Systems, Inc." },
{ "002367", "UniControls a.s." },
{ "00236E", "Burster GmbH & Co KG" },
{ "00236D", "ResMed Ltd" },
{ "002360", "Lookit Technology Co., Ltd" },
{ "00235B", "Gulfstream" },
{ "002316", "KISAN ELECTRONICS CO" },
{ "00230F", "Hirsch Electronics Corporation" },
{ "00230A", "ARBURG GmbH & Co KG" },
{ "002309", "Janam Technologies LLC" },
{ "002303", "LITE-ON IT Corporation" },
{ "0022F2", "SunPower Corp" },
{ "0022ED", "TSI Power Corporation" },
{ "00228D", "GBS Laboratories LLC" },
{ "002287", "Titan Wireless LLC" },
{ "002288", "Sagrad, Inc." },
{ "002281", "Daintree Networks Pty" },
{ "00227A", "Telecom Design" },
{ "00226B", "Cisco-Linksys, LLC" },
{ "002261", "Frontier Silicon Ltd" },
{ "00225D", "Digicable Network India Pvt. Ltd." },
{ "00225C", "Multimedia & Communication Technology" },
{ "00216F", "SymCom, Inc." },
{ "002169", "Prologix, LLC." },
{ "002162", "Nortel" },
{ "002156", "Cisco Systems, Inc" },
{ "002150", "EYEVIEW ELECTRONICS" },
{ "00214A", "Pixel Velocity, Inc" },
{ "0021A3", "Micromint" },
{ "002199", "Vacon Plc" },
{ "002195", "GWD Media Limited" },
{ "002194", "Ping Communication" },
{ "00218F", "Avantgarde Acoustic Lautsprechersysteme GmbH" },
{ "002188", "EMC Corporation" },
{ "002182", "SandLinks Systems, Ltd." },
{ "002175", "Pacific Satellite International Ltd." },
{ "00222A", "SoundEar A/S" },
{ "00221E", "Media Devices Co., Ltd." },
{ "002225", "Thales Avionics Ltd" },
{ "002218", "Verivue Inc." },
{ "002212", "CAI Networks, Inc." },
{ "00220B", "National Source Coding Center" },
{ "002205", "WeLink Solutions, Inc." },
{ "002206", "Cyberdyne Inc." },
{ "0022B3", "Sei S.p.A." },
{ "0022AC", "Hangzhou Siyuan Tech. Co., Ltd" },
{ "0022A7", "Tyco Electronics AMP GmbH" },
{ "0022A0", "Delphi Corporation" },
{ "00229A", "Lastar, Inc." },
{ "002299", "SeaMicro Inc." },
{ "002294", "Kyocera Corporation" },
{ "0021FA", "A4SP Technologies Ltd." },
{ "0021F4", "INRange Systems, Inc" },
{ "0021ED", "Telegesis" },
{ "0021E7", "Informatics Services Corporation" },
{ "0021DB", "Santachi Video Technology (Shenzhen) Co., Ltd." },
{ "0021E1", "Nortel Networks" },
{ "0021D5", "X2E GmbH" },
{ "0021DA", "Automation Products Group Inc." },
{ "0021CE", "NTC-Metrotek" },
{ "0021C8", "LOHUIS Networks" },
{ "0021C2", "GL Communications Inc" },
{ "0021BB", "Riken Keiki Co., Ltd." },
{ "0021B5", "Galvanic Ltd" },
{ "0021AF", "Radio Frequency Systems" },
{ "0021B6", "Triacta Power Technologies Inc." },
{ "0021A9", "Mobilink Telecom Co.,Ltd" },
{ "0021A8", "Telephonics Corporation" },
{ "00210D", "SAMSIN INNOTEC" },
{ "002141", "RADLIVE" },
{ "002137", "Bay Controls, LLC" },
{ "00212D", "SCIMOLEX CORPORATION" },
{ "002133", "Building B, Inc" },
{ "002121", "VRmagic GmbH" },
{ "002126", "Shenzhen Torch Equipment Co., Ltd." },
{ "002257", "3COM EUROPE LTD" },
{ "00224E", "SEEnergy Corp." },
{ "002247", "DAC ENGINEERING CO., LTD." },
{ "00223D", "JumpGen Systems, LLC" },
{ "002237", "Shinhint Group" },
{ "002238", "LOGIPLUS" },
{ "002231", "SMT&C Co., Ltd." },
{ "00222B", "Nucomm, Inc." },
{ "001EF6", "Cisco Systems, Inc" },
{ "001EEA", "Sensor Switch, Inc." },
{ "001EEF", "Cantronic International Limited" },
{ "001EDE", "BYD COMPANY LIMITED" },
{ "001EE3", "T&W Electronics (ShenZhen) Co.,Ltd" },
{ "001EDD", "WASKO S.A." },
{ "001ED9", "Mitsubishi Precision Co.,LTd." },
{ "001ED4", "Doble Engineering" },
{ "001ED3", "Dot Technology Int'l Co., Ltd." },
{ "001ECD", "KYLAND Technology Co. LTD" },
{ "001EC6", "Obvius Holdings LLC" },
{ "001F9D", "Cisco Systems, Inc" },
{ "001FA2", "Datron World Communications, Inc." },
{ "001F91", "DBS Lodging Technologies, LLC" },
{ "001F96", "APROTECH CO.LTD" },
{ "001F90", "Actiontec Electronics, Inc" },
{ "001F8F", "Shanghai Bellmann Digital Source Co.,Ltd." },
{ "001F85", "Apriva ISS, LLC" },
{ "001F87", "Skydigital Inc." },
{ "001F86", "digEcor" },
{ "001F80", "Lucas Holding bv" },
{ "001F3E", "RP-Technik e.K." },
{ "001F42", "Etherstack plc" },
{ "001F41", "Ruckus Wireless" },
{ "001F39", "Construcciones y Auxiliar de Ferrocarriles, S.A." },
{ "001F2B", "Orange Logic" },
{ "001F2C", "Starbridge Networks" },
{ "001F26", "Cisco Systems, Inc" },
{ "001F1A", "Prominvest" },
{ "001EC1", "3COM EUROPE LTD" },
{ "001EBA", "High Density Devices AS" },
{ "001EB3", "Primex Wireless" },
{ "001EB4", "UNIFAT TECHNOLOGY LTD." },
{ "001EAE", "Continental Automotive Systems" },
{ "001EA8", "Datang Mobile Communications Equipment CO.,LTD" },
{ "001E9C", "Fidustron INC" },
{ "001E95", "SIGMALINK" },
{ "001E96", "Sepura Plc" },
{ "001E8B", "Infra Access Korea Co., Ltd." },
{ "001FEF", "SHINSEI INDUSTRIES CO.,LTD" },
{ "001FE8", "KURUSUGAWA Electronics Industry Inc,." },
{ "001FDC", "Mobile Safe Track Ltd" },
{ "001FE3", "LG Electronics" },
{ "001FD7", "TELERAD SA" },
{ "001FCC", "Samsung Electronics Co.,Ltd" },
{ "001FCB", "NIW Solutions" },
{ "001FCD", "Samsung Electronics" },
{ "001F77", "HEOL DESIGN" },
{ "001F73", "Teraview Technology Co., Ltd." },
{ "001F6D", "Cisco Systems, Inc" },
{ "001F61", "Talent Communication Networks Inc." },
{ "001F66", "PLANAR LLC" },
{ "001F5A", "Beckwith Electric Co." },
{ "001F53", "GEMAC Gesellschaft für Mikroelektronikanwendung Chemnitz mbH" },
{ "001F4E", "ConMed Linvatec" },
{ "001F54", "Lorex Technology Inc." },
{ "001F47", "MCS Logic Inc." },
{ "001FD2", "COMMTECH TECHNOLOGY MACAO COMMERCIAL OFFSHORE LTD." },
{ "001FBF", "Fulhua Microelectronics Corp. Taiwan Branch" },
{ "001FBA", "BoYoung Tech. & Marketing, Inc." },
{ "001FAC", "Goodmill Systems Ltd" },
{ "00211A", "LInTech Corporation" },
{ "002113", "Padtec S/A" },
{ "002114", "Hylab Technology Inc." },
{ "00210E", "Orpak Systems L.T.D." },
{ "00210A", "byd:sign Corporation" },
{ "002104", "Gigaset Communications GmbH" },
{ "001FFB", "Green Packet Bhd" },
{ "001FF6", "PS Audio International" },
{ "001F19", "BEN-RI ELECTRONICA S.A." },
{ "001F13", "S.& A.S. Ltd." },
{ "001F0F", "Select Engineered Systems" },
{ "001F09", "JASTEC CO., LTD." },
{ "001EFD", "Microbit 2.0 AB" },
{ "001F02", "Pixelmetrix Corporation Pte Ltd" },
{ "001EF0", "Gigafin Networks" },
{ "001D2C", "Wavetrend Technologies (Pty) Limited" },
{ "001D27", "NAC-INTERCOM" },
{ "001D18", "Power Innovation GmbH" },
{ "001D13", "NextGTV" },
{ "001D0C", "MobileCompia" },
{ "001D06", "HM Electronics, Inc." },
{ "001D05", "Eaton Corporation" },
{ "001E62", "Siemon" },
{ "001E5D", "Holosys d.o.o." },
{ "001E56", "Bally Wulff Entertainment GmbH" },
{ "001E50", "BATTISTONI RESEARCH" },
{ "001E4A", "Cisco Systems, Inc" },
{ "001E40", "Shanghai DareGlobal Technologies  Co.,Ltd." },
{ "001D85", "Call Direct Cellular Solutions" },
{ "001D80", "Beijing Huahuan Eletronics Co.,Ltd" },
{ "001D68", "Thomson Telecom Belgium" },
{ "001D6F", "Chainzone Technology Co., Ltd" },
{ "001D76", "Eyeheight Ltd." },
{ "001D7B", "Ice Energy, Inc." },
{ "001D75", "Radioscape PLC" },
{ "001D63", "Miele & Cie. KG" },
{ "001D5C", "Tom Communication Industrial Co.,Ltd." },
{ "001D55", "ZANTAZ, Inc" },
{ "001DC8", "Navionics Research Inc., dba SCADAmetrics" },
{ "001DC1", "Audinate Pty L" },
{ "001DBB", "Dynamic System Electronics Corp." },
{ "001DAB", "SwissQual License AG" },
{ "001E86", "MEL Co.,Ltd." },
{ "001E7F", "CBM of America" },
{ "001E7A", "Cisco Systems, Inc" },
{ "001E79", "Cisco Systems, Inc" },
{ "001E75", "LG Electronics" },
{ "001E6F", "Magna-Power Electronics, Inc." },
{ "001E70", "Cobham Defence Communications Ltd" },
{ "001E69", "Thomson Inc." },
{ "001D56", "Kramer Electronics Ltd." },
{ "001D50", "SPINETIX SA" },
{ "001D4B", "Grid Connect Inc." },
{ "001D46", "Cisco Systems, Inc" },
{ "001D3F", "Mitron Pty Ltd" },
{ "001D39", "MOOHADIGITAL CO., LTD" },
{ "001D3A", "mh acoustics LLC" },
{ "001D33", "Maverick Systems Inc." },
{ "001E09", "ZEFATEK Co.,LTD" },
{ "001E04", "Hanson Research Corporation" },
{ "001DF7", "R. STAHL Schaltgeräte GmbH" },
{ "001DF8", "Webpro Vision Technology Corporation" },
{ "001DF1", "Intego Systems, Inc." },
{ "001DEA", "Commtest Instruments Ltd" },
{ "001DDB", "C-BEL Corporation" },
{ "001DE5", "Cisco Systems, Inc" },
{ "001DA4", "Hangzhou System Technology CO., LTD" },
{ "001D9F", "MATT   R.P.Traczynscy Sp.J." },
{ "001D92", "MICRO-STAR INT'L CO.,LTD." },
{ "001D91", "Digitize, Inc" },
{ "001D8C", "La Crosse Technology LTD" },
{ "001E39", "Comsys Communication Ltd." },
{ "001E34", "CryptoMetrics" },
{ "001E33", "Inventec Corporation" },
{ "001E2D", "STIM" },
{ "001E26", "Digifriends Co. Ltd" },
{ "001E21", "Qisda Co." },
{ "001E1A", "Best Source Taiwan Inc." },
{ "001E14", "Cisco Systems, Inc" },
{ "001E0A", "Syba Tech Limited" },
{ "001C61", "Galaxy  Microsystems LImited" },
{ "001C55", "Shenzhen Kaifa Technology Co." },
{ "001C5A", "Advanced Relay Corporation" },
{ "001C44", "Bosch Security Systems BV" },
{ "001C4B", "Gener8, Inc." },
{ "001C38", "Bio-Rad Laboratories, Inc." },
{ "001C3D", "WaveStorm" },
{ "001C3F", "International Police Technologies, Inc." },
{ "001C3E", "ECKey Corporation" },
{ "001C31", "Mobile XP Technology Co., LTD" },
{ "001C2C", "Synapse" },
{ "001CF9", "Cisco Systems, Inc" },
{ "001CF3", "EVS BROADCAST EQUIPMENT" },
{ "001CF4", "Media Technology Systems Inc" },
{ "001CED", "ENVIRONNEMENT SA" },
{ "001CE3", "Optimedical Systems" },
{ "001CDC", "Custom Computer Services, Inc." },
{ "001CD0", "Circleone Co.,Ltd." },
{ "001BF5", "Tellink Sistemas de Telecomunicación S.L." },
{ "001BF0", "Value Platforms Limited" },
{ "001BE8", "Ultratronik GmbH" },
{ "001BE1", "ViaLogy" },
{ "001BDC", "Vencer Co., Ltd." },
{ "001BD5", "Cisco Systems, Inc" },
{ "001BCE", "Measurement Devices Ltd" },
{ "001C94", "LI-COR Biosciences" },
{ "001C8E", "Alcatel-Lucent IPD" },
{ "001C8D", "Mesa Imaging" },
{ "001C88", "TRANSYSTEM INC." },
{ "001C7E", "Toshiba" },
{ "001C83", "New Level Telecom Co., Ltd." },
{ "001C7A", "Perfectone Netware Company Ltd" },
{ "001C7B", "Castlenet Technology Inc." },
{ "001C79", "Cohesive Financial Technologies LLC" },
{ "001C74", "Syswan Technologies Inc." },
{ "001C6D", "KYOHRITSU ELECTRONIC INDUSTRY CO., LTD." },
{ "001C68", "Anhui Sun Create Electronics Co., Ltd" },
{ "001CC9", "Kaise Electronic Technology Co., Ltd." },
{ "001CCA", "Shanghai Gaozhi Science & Technology Development Co." },
{ "001CBD", "Ezze Mobile Tech., Inc." },
{ "001CB8", "CBC Co., Ltd" },
{ "001CAD", "Wuhan Telecommunication Devices Co.,Ltd" },
{ "001CAE", "WiChorus, Inc." },
{ "001CA7", "International Quartz Limited" },
{ "001CA0", "Production Resource Group, LLC" },
{ "001C9B", "FEIG ELECTRONIC GmbH" },
{ "001B69", "Equaline Corporation" },
{ "001B64", "IsaacLandKorea Co., Ltd," },
{ "001B5D", "Vololink Pty Ltd" },
{ "001B56", "Tehuti Networks Ltd." },
{ "001B51", "Vector Technology Corp." },
{ "001B45", "ABB AS, Division Automation Products" },
{ "001B4A", "W&W Communications, Inc." },
{ "001B43", "Beijing DG Telecommunications equipment Co.,Ltd" },
{ "001B3E", "Curtis, Inc." },
{ "001B37", "Computec Oy" },
{ "001B32", "QLogic Corporation" },
{ "001B2B", "Cisco Systems, Inc" },
{ "001BC9", "FSN DISPLAY INC" },
{ "001BC2", "Integrated Control Technology Limitied" },
{ "001BBC", "Silver Peak Systems, Inc." },
{ "001BBD", "FMC Kongsberg Subsea AS" },
{ "001BB3", "Condalo GmbH" },
{ "001BB8", "BLUEWAY ELECTRONIC CO;LTD" },
{ "001BAC", "Curtiss Wright Controls Embedded Computing" },
{ "001BB1", "Wistron Neweb Corp." },
{ "001BB2", "Intellect International NV" },
{ "001BA5", "MyungMin Systems, Inc." },
{ "001BA0", "Awox" },
{ "001B99", "KS System GmbH" },
{ "001C14", "VMware, Inc" },
{ "001C1B", "Hyperstone GmbH" },
{ "001C0F", "Cisco Systems, Inc" },
{ "001C08", "Echo360, Inc." },
{ "001C02", "Pano Logic" },
{ "001C01", "ABB Oy Drives" },
{ "001C03", "Betty TV Technology AG" },
{ "001B92", "l-acoustics" },
{ "001B8D", "Electronic Computer Systems, Inc." },
{ "001B88", "Divinet Access Technologies Ltd" },
{ "001B83", "Finsoft Ltd" },
{ "001B7C", "A & R Cambridge" },
{ "001B76", "Ripcode, Inc." },
{ "001B75", "Hypermedia Systems" },
{ "001B70", "IRI Ubiteq, INC." },
{ "001A18", "Advanced Simulation Technology inc." },
{ "001A0A", "Adaptive Micro-Ware Inc." },
{ "001A05", "OPTIBASE LTD" },
{ "001A03", "Angel Electronics Co., Ltd." },
{ "0019FE", "SHENZHEN SEECOMM TECHNOLOGY CO.,LTD." },
{ "0019F9", "TDK-Lambda" },
{ "0019ED", "Axesstel Inc." },
{ "0019F4", "Convergens Oy Ltd" },
{ "001A79", "TELECOMUNICATION TECHNOLOGIES LTD." },
{ "001A99", "Smarty (HZ) Information Electronics Co., Ltd" },
{ "001A9B", "ADEC & Parter AG" },
{ "001A8A", "Samsung Electronics Co., Ltd." },
{ "001A8F", "Nortel" },
{ "001A94", "Votronic GmbH" },
{ "001A83", "Pegasus Technologies Inc." },
{ "001A7E", "LN Srithai Comm Ltd." },
{ "001AF1", "Embedded Artists AB" },
{ "001AF6", "Woven Systems, Inc." },
{ "001AEC", "Keumbee Electronics Co.,Ltd." },
{ "001AE0", "Mythology Tech Express Inc." },
{ "001AE5", "Mvox Technologies Inc." },
{ "001AD2", "Eletronica Nitron Ltda" },
{ "001AD9", "International Broadband Electric Communications, Inc." },
{ "001ACB", "Autocom Products Ltd" },
{ "001ACD", "Tidel Engineering LP" },
{ "001A46", "Digital Multimedia Technology Co., Ltd" },
{ "001A3A", "Dongahelecomm" },
{ "001A3F", "intelbras" },
{ "001A41", "INOCOVA Co.,Ltd" },
{ "001A2E", "Ziova Coporation" },
{ "001A33", "ASI Communications, Inc." },
{ "001A29", "Johnson Outdoors Marine Electronics, Inc" },
{ "001A1D", "PChome Online Inc." },
{ "001A24", "Galaxy Telecom Technologies Ltd" },
{ "0019A5", "RadarFind Corporation" },
{ "0019AC", "GSP SYSTEMS Inc." },
{ "0019B1", "Arrow7 Corporation" },
{ "00199E", "Nifty" },
{ "0019A0", "NIHON DATA SYSTENS, INC." },
{ "001994", "Jorjin Technologies Inc." },
{ "00198F", "Alcatel Bell N.V." },
{ "0019E1", "Nortel" },
{ "0019E8", "Cisco Systems, Inc" },
{ "0019DA", "Welltrans O&E Technology Co. , Ltd." },
{ "0019DC", "ENENSYS Technologies" },
{ "0019C9", "S&C ELECTRIC COMPANY" },
{ "0019CE", "Progressive Gaming International" },
{ "0019D5", "IP Innovations, Inc." },
{ "0019C4", "Infocrypt Inc." },
{ "0019BF", "Citiway technology Co.,ltd" },
{ "0019BD", "New Media Life" },
{ "0019B8", "Boundary Devices" },
{ "001B26", "RON-Telecom ZAO" },
{ "001B1C", "Coherent" },
{ "001B1A", "e-trees Japan, Inc." },
{ "001B15", "Voxtel, Inc." },
{ "001B09", "Matrix Telecom Pvt. Ltd." },
{ "001B0E", "InoTec GmbH Organisationssysteme" },
{ "001B07", "Mendocino Software" },
{ "001B02", "ED Co.Ltd" },
{ "001AFB", "Joby Inc." },
{ "001A74", "Procare International Co" },
{ "001A6D", "Cisco Systems, Inc" },
{ "001A68", "Weltec Enterprise Co., Ltd." },
{ "001A61", "PacStar Corp." },
{ "001A54", "Hip Shing Electronics Ltd." },
{ "001A59", "Ircona" },
{ "001A4D", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "001A52", "Meshlinx Wireless Inc." },
{ "001AC6", "Micro Control Designs" },
{ "001ABC", "U4EA Technologies Ltd" },
{ "001AC1", "3Com Ltd" },
{ "001AB0", "Signal Networks Pvt. Ltd.," },
{ "001AB5", "Home Network System" },
{ "001AA9", "FUJIAN STAR-NET COMMUNICATION CO.,LTD" },
{ "00183C", "Encore Software Limited" },
{ "001841", "High Tech Computer Corp" },
{ "001843", "Dawevision Ltd" },
{ "001837", "Universal ABIT Co., Ltd." },
{ "001826", "Cale Access AB" },
{ "00182B", "Softier" },
{ "001818", "Cisco Systems, Inc" },
{ "00181A", "AVerMedia Information Inc." },
{ "00181F", "Palmmicro Communications" },
{ "001804", "E-TEK DIGITAL TECHNOLOGY LIMITED" },
{ "001807", "Fanstel Corp." },
{ "00180C", "Optelian Access Networks" },
{ "0017FF", "PLAYLINE Co.,Ltd." },
{ "0017F1", "Renu Electronics Pvt Ltd" },
{ "0017F3", "Harris Corparation" },
{ "0017F8", "Motech Industries Inc." },
{ "0017D4", "Monsoon Multimedia, Inc" },
{ "0017D9", "AAI Corporation" },
{ "0017E0", "Cisco Systems, Inc" },
{ "001920", "KUME electric Co.,Ltd." },
{ "001925", "Intelicis Corporation" },
{ "001912", "Welcat Inc" },
{ "001914", "Winix Co., Ltd" },
{ "001919", "ASTEL Inc." },
{ "00190D", "IEEE 1394c" },
{ "001901", "F1MEDIA" },
{ "001906", "Cisco Systems, Inc" },
{ "0018F5", "Shenzhen Streaming Video Technology Company Limited" },
{ "0018F7", "Kameleon Technologies" },
{ "0018FC", "Altec Electronic AG" },
{ "001981", "Vivox Inc" },
{ "001983", "CCT R&D Limited" },
{ "001988", "Wi2Wi, Inc" },
{ "001975", "Beijing Huisen networks technology Inc" },
{ "00197C", "Riedel Communications GmbH" },
{ "001969", "Nortel" },
{ "001970", "Z-Com, Inc." },
{ "001964", "Doorking Inc." },
{ "00195F", "Valemount Networks Corporation" },
{ "001953", "Chainleader Communications Corp." },
{ "001958", "Bluetooth SIG, Inc." },
{ "00195A", "Jenaer Antriebstechnik GmbH" },
{ "0018F0", "JOYTOTO Co., Ltd." },
{ "0018E9", "Numata Corporation" },
{ "0018E4", "YIGUANG" },
{ "0018DD", "Silicondust Engineering Ltd" },
{ "0018D8", "ARCH METER Corporation" },
{ "0018D1", "Siemens Home & Office Comm. Devices" },
{ "0018D6", "Swirlnet A/S" },
{ "0018CC", "AXIOHM SAS" },
{ "0018C7", "Real Time Automation" },
{ "00186C", "Neonode AB" },
{ "001878", "Mackware GmbH" },
{ "001867", "Datalogic ADC" },
{ "00185B", "Network Chemistry, Inc" },
{ "001862", "Seagate Technology" },
{ "00184F", "8 Ways Technology Corp." },
{ "001854", "Argard Co., Ltd" },
{ "001856", "EyeFi, Inc" },
{ "001848", "Vecima Networks Inc." },
{ "001945", "RF COncepts, LLC" },
{ "00194C", "Fujian Stelcom information & Technology CO.,Ltd" },
{ "001940", "Rackable Systems" },
{ "001934", "TRENDON TOUCH TECHNOLOGY CORP." },
{ "001939", "Gigamips" },
{ "001931", "Balluff GmbH" },
{ "0018BB", "Eliwell Controls srl" },
{ "0018B9", "Cisco Systems, Inc" },
{ "0018B4", "Dawon Media Inc." },
{ "0018AD", "NIDEC SANKYO CORPORATION" },
{ "0018A8", "AnNeal Technology Inc." },
{ "00189C", "Weldex Corporation" },
{ "0018A1", "Tiqit Computers, Inc." },
{ "001897", "JESS-LINK PRODUCTS Co., LTD" },
{ "001892", "ads-tec GmbH" },
{ "001890", "RadioCOM, s.r.o." },
{ "001884", "Fon Technology S.L." },
{ "00187D", "Armorlink shanghai Co. Ltd" },
{ "00187F", "ZODIANET" },
{ "0016D1", "ZAT a.s." },
{ "0016C3", "BA Systems Inc" },
{ "0016CA", "Nortel" },
{ "0016BE", "INFRANET, Inc." },
{ "0016B7", "Seoul Commtech" },
{ "0016B2", "DriveCam Inc" },
{ "0016B0", "VK Corporation" },
{ "0016AB", "Dansensor A/S" },
{ "0016A6", "Dovado FZ-LLC" },
{ "0017C8", "KYOCERA Document Solutions Inc." },
{ "0017CA", "Qisda Corporation" },
{ "0017CF", "iMCA-GmbH" },
{ "0017C3", "KTF Technologies Inc." },
{ "0017B7", "Tonze Technology Co." },
{ "0017BC", "Touchtunes Music Corporation" },
{ "0017B5", "Peerless Systems Corporation" },
{ "001723", "Summit Data Communications" },
{ "00171C", "NT MicroSystems, Inc." },
{ "001710", "Casa Systems Inc." },
{ "001715", "Qstik" },
{ "001717", "Leica Geosystems AG" },
{ "00170B", "Contela, Inc." },
{ "0016FF", "Wamin Optocomm Mfg Corp" },
{ "001774", "Elesta GmbH" },
{ "001779", "QuickTel" },
{ "00177B", "Azalea Networks inc" },
{ "001764", "ATMedia GmbH" },
{ "001766", "Accense Technology, Inc." },
{ "00175F", "XENOLINK Communications Co., Ltd." },
{ "001751", "Online Corporation" },
{ "001753", "nFore Technology Inc." },
{ "001758", "ThruVision Ltd" },
{ "001745", "INNOTZ CO., Ltd" },
{ "00174C", "Millipore" },
{ "00179F", "Apricorn" },
{ "0017A9", "Sentivision" },
{ "001793", "Tigi Corporation" },
{ "00178C", "Independent Witness, Inc" },
{ "00178E", "Gunnebo Cash Automation AB" },
{ "001780", "Applied Biosystems B.V." },
{ "001787", "Brother, Brother & Sons ApS" },
{ "00176B", "Kiyon, Inc." },
{ "00BAC0", "Biometric Access Company" },
{ "001673", "Bury GmbH & Co. KG" },
{ "001671", "Symphox Information Co." },
{ "001665", "Cellon France" },
{ "00166A", "TPS" },
{ "00165E", "Precision I/O" },
{ "001657", "Aegate Ltd" },
{ "001659", "Z.M.P. RADWAG" },
{ "001658", "Fusiontech Technologies Inc." },
{ "001652", "Hoatech Technologies, Inc." },
{ "001646", "Cisco Systems, Inc" },
{ "00164B", "Quorion Data Systems GmbH" },
{ "001740", "Bluberi Gaming Technologies Inc" },
{ "001736", "iiTron Inc." },
{ "00172F", "NeuLion Incorporated" },
{ "001728", "Selex Communications" },
{ "00172A", "Proware Technology Corp.(By Unifosa)" },
{ "00169A", "Quadrics Ltd" },
{ "0016A1", "3Leaf Networks" },
{ "001693", "PowerLink Technology Inc." },
{ "001695", "AVC Technology (International) Limited" },
{ "00168E", "Vimicro corporation" },
{ "001682", "Pro Dex, Inc" },
{ "001687", "Chubb CSC-Vendor AP" },
{ "00167B", "Haver&Boecker" },
{ "0016F3", "CAST Information Co., Ltd" },
{ "0016EE", "Royaldigital Inc." },
{ "0016E7", "Dynamix Promotions Limited" },
{ "0016DB", "Samsung Electronics Co., Ltd." },
{ "0016E0", "3Com Ltd" },
{ "0016D6", "TDA Tech Pty Ltd" },
{ "00151E", "Ethernet Powerlink Standardization Group (EPSG)" },
{ "001525", "Chamberlain Access Solutions" },
{ "001519", "StoreAge Networking Technologies" },
{ "001518", "Shenzhen 10MOONS Technology Development CO.,Ltd" },
{ "001514", "Hu Zhou NAVA Networks&Electronics Ltd." },
{ "00150E", "OPENBRAIN TECHNOLOGIES CO., LTD." },
{ "00150F", "mingjong" },
{ "00150D", "Hoana Medical, Inc." },
{ "001508", "Global Target Enterprise Inc" },
{ "0014FC", "Extandon, Inc." },
{ "001501", "LexBox" },
{ "0014F5", "OSI Security Devices" },
{ "0014E9", "Nortech International" },
{ "0014EE", "Western Digital Technologies, Inc." },
{ "0014DF", "HI-P Tech Corporation" },
{ "0014E4", "infinias, LLC" },
{ "0014D3", "SEPSA" },
{ "0014D8", "bio-logic SA" },
{ "0014D2", "Kyuden Technosystems Corporation" },
{ "0015E0", "Ericsson" },
{ "0015DC", "KT&C Co., Ltd." },
{ "0015D5", "NICEVT" },
{ "0015D7", "Reti Corporation" },
{ "0015D6", "OSLiNK Sp. z o.o." },
{ "0015C4", "FLOVEL CO., LTD." },
{ "0015C9", "Gumstix, Inc" },
{ "0015BD", "Group 4 Technology Ltd" },
{ "0015B6", "ShinMaywa Industries, Ltd." },
{ "001581", "MAKUS Inc." },
{ "00156B", "Perfisans Networks Corp." },
{ "001570", "Zebra Technologies Inc" },
{ "00155D", "Microsoft Corporation" },
{ "00155F", "GreenPeak Technologies" },
{ "001564", "BEHRINGER Spezielle Studiotechnik GmbH" },
{ "00155E", "Morgan Stanley" },
{ "001558", "FOXCONN" },
{ "001551", "RadioPulse Inc." },
{ "001549", "Dixtal Biomedica Ind. Com. Ltda" },
{ "00154C", "Saunders Electronics" },
{ "00154A", "WANSHIH ELECTRONIC CO., LTD" },
{ "00153D", "ELIM PRODUCT CO." },
{ "001544", "coM.s.a.t. AG" },
{ "001531", "KOCOM" },
{ "001538", "RFID, Inc." },
{ "00152A", "Nokia GmbH" },
{ "00161D", "Innovative Wireless Technologies, Inc." },
{ "00161C", "e:cue" },
{ "00160C", "LPL  DEVELOPMENT S.A. DE C.V" },
{ "001611", "Altecon Srl" },
{ "001612", "Otsuka Electronics Co., Ltd." },
{ "001605", "YORKVILLE SOUND INC." },
{ "0015F9", "Cisco Systems, Inc" },
{ "001600", "CelleBrite Mobile Synchronization" },
{ "0015ED", "Fulcrum Microsystems, Inc." },
{ "0015E1", "Picochip Ltd" },
{ "0015E6", "MOBILE TECHNIKA Inc." },
{ "0015B1", "Ambient Corporation" },
{ "0015AC", "Capelon AB" },
{ "0015A7", "Robatech AG" },
{ "001599", "Samsung Electronics Co., LTD" },
{ "00159B", "Nortel" },
{ "001594", "BIXOLON CO.,LTD" },
{ "00158D", "Jennic Ltd" },
{ "001588", "Salutica Allied Solutions Sdn Bhd" },
{ "0014CC", "Zetec, Inc." },
{ "0014D1", "TRENDnet" },
{ "0014C0", "Symstream Technology Group Ltd" },
{ "0014C5", "Alive Technologies Pty Ltd" },
{ "0014B9", "MSTAR SEMICONDUCTOR" },
{ "0014AF", "Datasym POS Inc." },
{ "0014A8", "Cisco Systems, Inc" },
{ "001641", "Universal Global Scientific Industrial Co., Ltd." },
{ "00163C", "Rebox B.V." },
{ "00162E", "Space Shuttle Hi-Tech Co., Ltd." },
{ "001629", "Nivus GmbH" },
{ "001622", "BBH SYSTEMS GMBH" },
{ "001616", "BROWAN COMMUNICATION INC." },
{ "00161B", "Micronet Corporation" },
{ "00135B", "PanelLink Cinema, LLC" },
{ "001362", "ShinHeung Precision Co., Ltd." },
{ "001351", "Niles Audio Corporation" },
{ "001345", "Eaton Corporation" },
{ "00134A", "Engim, Inc." },
{ "00133E", "MetaSwitch" },
{ "00132B", "Phoenix Digital" },
{ "001332", "Beijing Topsec Network Security Technology Co., Ltd." },
{ "001337", "Orient Power Home Network Ltd." },
{ "001338", "FRESENIUS-VIAL" },
{ "00137A", "Netvox Technology Co., Ltd." },
{ "001381", "CHIPS & Systems, Inc." },
{ "001386", "ABB Inc./Totalflow" },
{ "001374", "Atheros Communications, Inc." },
{ "00136E", "Techmetro Corp." },
{ "001373", "BLwave Electronics Co., Ltd" },
{ "001367", "Narayon. Co., Ltd." },
{ "001361", "Biospace Co., Ltd." },
{ "001357", "Soyal Technology Co., Ltd." },
{ "001326", "ECM Systems Ltd" },
{ "001325", "Cortina Systems Inc" },
{ "00131B", "BeCell Innovations Corp." },
{ "00131C", "LiteTouch, Inc." },
{ "001309", "Ocean Broadband Networks" },
{ "00130E", "Focusrite Audio Engineering Limited" },
{ "0012FC", "PLANET System Co.,LTD" },
{ "0012FB", "Samsung Electronics" },
{ "0012F6", "MDK CO.,LTD." },
{ "0012F1", "IFOTEC" },
{ "00143E", "AirLink Communications, Inc." },
{ "001437", "GSTeletech Co.,Ltd." },
{ "001430", "ViPowER, Inc" },
{ "00142B", "Edata Communication Inc." },
{ "001424", "Merry Electrics CO., LTD." },
{ "00141F", "SunKwang Electronics Co., Ltd" },
{ "00141A", "DEICY CORPORATION" },
{ "001413", "Trebing & Himstedt Prozeßautomation GmbH & Co. KG" },
{ "001415", "Intec Automation inc." },
{ "001414", "Jumpnode Systems LLC." },
{ "00140E", "Nortel" },
{ "001405", "OpenIB, Inc." },
{ "00140B", "FIRST INTERNATIONAL COMPUTER, INC." },
{ "0013FE", "GRANDTEC ELECTRONIC CORP." },
{ "0013F9", "Cavera Systems" },
{ "0013F2", "Klas Ltd" },
{ "0013EC", "Netsnapper Technologies SARL" },
{ "0013E1", "Iprobe AB" },
{ "0013E2", "GeoVision Inc." },
{ "0013D5", "RuggedCom" },
{ "0013DC", "IBTEK INC." },
{ "0013D0", "t+ Medical Ltd" },
{ "0013CB", "Zenitel Norway AS" },
{ "0013C6", "OpenGear, Inc" },
{ "0013C5", "LIGHTRON FIBER-OPTIC DEVICES INC." },
{ "0013BB", "Smartvue Corporation" },
{ "0013BF", "Media System Planning Corp." },
{ "0013B5", "Wavesat" },
{ "0013AE", "Radiance Technologies, Inc." },
{ "0013A2", "MaxStream, Inc" },
{ "00139B", "ioIMAGE Ltd." },
{ "00139C", "Exavera Technologies, Inc." },
{ "001396", "Acbel Polytech Inc." },
{ "00138A", "QINGDAO GOERTEK ELECTRONICS CO.,LTD." },
{ "001389", "Redes de Telefonía Móvil S.A." },
{ "00149C", "HF Company" },
{ "0014A3", "Vitelec BV" },
{ "001497", "ZHIYUAN Eletronics co.,ltd." },
{ "001496", "Phonic Corp." },
{ "001490", "ASP Corporation" },
{ "001489", "B15402100 - JANDEI, S.L." },
{ "001484", "Cermate Technologies Inc." },
{ "00147F", "Thomson Telecom Belgium" },
{ "00147A", "Eubus GmbH" },
{ "001473", "Bookham Inc" },
{ "001467", "ArrowSpan Inc." },
{ "001460", "Kyocera Wireless Corp." },
{ "00145B", "SeekerNet Inc." },
{ "00145A", "Neratec Solutions AG" },
{ "001459", "Moram Co., Ltd." },
{ "001454", "Symwave" },
{ "001443", "Consultronics Europe Ltd" },
{ "00144A", "Taiwan Thick-Film Ind. Corp." },
{ "0011C4", "Terminales de Telecomunicacion Terrestre, S.L." },
{ "0011C9", "MTT Corporation" },
{ "0011BF", "AESYS S.p.A." },
{ "0011B8", "Liebherr - Elektronik GmbH" },
{ "0011AC", "Simtec Electronics" },
{ "0011B1", "BlueExpert Technology Corp." },
{ "0011B2", "2001 Technology Inc." },
{ "0011A0", "Vtech Engineering Canada Ltd" },
{ "0011A5", "Fortuna Electronic Corp." },
{ "001276", "CG Power Systems Ireland Limited" },
{ "00126F", "Rayson Technology Co., Ltd." },
{ "001270", "NGES Denro Systems" },
{ "00126A", "OPTOELECTRONICS Co., Ltd." },
{ "001263", "Data Voice Technologies GmbH" },
{ "00125E", "CAEN" },
{ "00125D", "CyberNet Inc." },
{ "001259", "THERMO ELECTRON KARLSRUHE" },
{ "001254", "Spectra Technologies Holdings Company Ltd" },
{ "001253", "AudioDev AB" },
{ "00129D", "First International Computer do Brasil" },
{ "001291", "KWS Computersysteme GmbH" },
{ "001296", "Addlogix" },
{ "00128F", "Montilio" },
{ "001282", "Qovia" },
{ "001289", "Advance Sterilization Products" },
{ "00127D", "MobileAria" },
{ "0011F4", "woori-net" },
{ "0011EE", "Estari, Inc." },
{ "0011ED", "802 Global" },
{ "0011E8", "Tixi.Com" },
{ "0011DB", "Land-Cellular Corporation" },
{ "0011DC", "Glunz & Jensen" },
{ "0011E1", "Arcelik A.S" },
{ "0011CE", "Ubisense Limited" },
{ "0011D5", "Hangzhou Sunyard System Engineering Co.,Ltd." },
{ "001246", "T.O.M TECHNOLOGY INC.." },
{ "00124D", "Inducon BV" },
{ "001241", "a2i marketing center" },
{ "00123A", "Posystech Inc., Co." },
{ "001234", "Camille Bauer" },
{ "00122A", "VTech Telecommunications Ltd." },
{ "00122E", "Signal Technology - AISD" },
{ "001233", "JRC TOKKI Co.,Ltd." },
{ "001199", "2wcom Systems GmbH" },
{ "00118F", "EUTECH INSTRUMENTS PTE. LTD." },
{ "001183", "Datalogic ADC, Inc." },
{ "00117C", "e-zy.net" },
{ "001176", "Intellambda Systems, Inc." },
{ "0012C0", "HotLava Systems, Inc." },
{ "0012B5", "Vialta, Inc." },
{ "0012BC", "Echolab LLC" },
{ "0012B6", "Santa Barbara Infrared, Inc." },
{ "0012B0", "Efore Oyj   (Plc)" },
{ "0012A4", "ThingMagic, LLC" },
{ "0012A9", "3Com Ltd" },
{ "0012A3", "Trust International B.V." },
{ "001224", "NexQL Corporation" },
{ "001229", "BroadEasy Technologies Co.,Ltd" },
{ "00121D", "Netfabric Corporation" },
{ "001211", "Protechna Herbst GmbH & Co. KG" },
{ "001218", "ARUZE Corporation" },
{ "001205", "Terrasat Communications, Inc." },
{ "00120A", "Emerson Climate Technologies GmbH" },
{ "0011FE", "Keiyo System Research, Inc." },
{ "0011F8", "AIRAYA Corp" },
{ "0012EC", "Movacolor b.v." },
{ "0012E5", "Time America, Inc." },
{ "0012E0", "Codan Limited" },
{ "0012DF", "Novomatic AG" },
{ "0012D9", "Cisco Systems, Inc" },
{ "0012C6", "TGC America, Inc" },
{ "0012CD", "ASEM SpA" },
{ "000FE9", "GW TECHNOLOGIES CO.,LTD." },
{ "000FDD", "SORDIN AB" },
{ "000FE2", "Hangzhou H3C Technologies Co., Ltd." },
{ "000FD6", "Sarotech Co., Ltd" },
{ "002654", "3Com Corporation" },
{ "000FD0", "ASTRI" },
{ "000FCF", "DataWind Research" },
{ "000FC3", "PalmPalm Technology, Inc." },
{ "001144", "Assurance Technology Corp" },
{ "00113E", "JL Corporation" },
{ "001131", "UNATECH. CO.,LTD" },
{ "001137", "AICHI ELECTRIC CO., LTD." },
{ "00112D", "iPulse Systems" },
{ "111111", "Private" },
{ "001123", "Appointech, Inc." },
{ "00111D", "Hectrix Limited" },
{ "000F6C", "ADDI-DATA GmbH" },
{ "000F6B", "GateWare Communications GmbH" },
{ "000F5F", "Nicety Technologies Inc. (NTS)" },
{ "000F59", "Phonak Communications AG" },
{ "000F5A", "Peribit Networks" },
{ "000F53", "Solarflare Communications Inc" },
{ "000F47", "ROBOX SPA" },
{ "000F4C", "Elextech INC" },
{ "001170", "GSC SRL" },
{ "001169", "EMS Satcom" },
{ "001164", "ACARD Technology Corp." },
{ "00115F", "ITX Security Co., Ltd." },
{ "00115A", "Ivoclar Vivadent AG" },
{ "001159", "MATISSE NETWORKS INC" },
{ "001153", "Trident Tek, Inc." },
{ "001150", "Belkin Corporation" },
{ "001151", "Mykotronx" },
{ "00114A", "KAYABA INDUSTRY Co,.Ltd." },
{ "001110", "Maxanna Technology Co., Ltd." },
{ "001117", "CESNET" },
{ "001104", "TELEXY" },
{ "00110B", "Franklin Technology Systems" },
{ "001100", "Schneider Electric" },
{ "000FFE", "G-PRO COMPUTER" },
{ "000FEF", "Thales e-Transactions GmbH" },
{ "000FF0", "Sunray Co. Ltd." },
{ "000FF5", "GN&S company" },
{ "000FCA", "A-JIN TECHLINE CO, LTD" },
{ "000FBD", "MRV Communications (Networks) LTD" },
{ "000FBE", "e-w/you Inc." },
{ "000FB7", "Cavium" },
{ "000FA4", "Sprecher Automation GmbH" },
{ "000FAB", "Kyushu Electronics Systems Inc." },
{ "000F9D", "DisplayLink (UK) Ltd" },
{ "000F98", "Avamax Co. Ltd." },
{ "000F8B", "Orion MultiSystems Inc" },
{ "000F8C", "Gigawavetech Pte Ltd" },
{ "000F91", "Aerotelecom Co.,Ltd." },
{ "000F7E", "Ablerex Electronics Co., LTD" },
{ "000F85", "ADDO-Japan Corporation" },
{ "000F72", "Sandburst" },
{ "000F79", "Bluetooth Interest Group Inc." },
{ "000F19", "Boston Scientific" },
{ "000F0D", "Hunt Electronic Co., Ltd." },
{ "000F06", "Nortel Networks" },
{ "000F01", "DIGITALKS INC" },
{ "000EFA", "Optoway Technology Incorporation" },
{ "000EF4", "Kasda Networks Inc" },
{ "000EF3", "Smarthome" },
{ "000EEE", "Muco Industrie BV" },
{ "000EE7", "AAC ELECTRONICS CORP." },
{ "000F38", "Netstar" },
{ "000F40", "Optical Internetworking Forum" },
{ "000F33", "DUALi Inc." },
{ "000F2C", "Uplogix, Inc." },
{ "000F26", "WorldAccxx  LLC" },
{ "000F25", "AimValley B.V." },
{ "000F13", "Nisca corporation" },
{ "000F14", "Mindray Co., Ltd." },
{ "000EE1", "ExtremeSpeed Inc." },
{ "000EDB", "XiNCOM Corp." },
{ "000EE2", "Custom Engineering" },
{ "000ED5", "COPAN Systems Inc." },
{ "000EC9", "YOKO Technology Corp." },
{ "000ED0", "Privaris, Inc." },
{ "000ED7", "Cisco Systems, Inc" },
{ "000EC4", "Iskra Transmission d.d." },
{ "000EC3", "Logic Controls, Inc." },
{ "000EB6", "Riverbed Technology, Inc." },
{ "000EBD", "Burdick, a Quinton Compny" },
{ "000EB1", "Newcotech,Ltd" },
{ "000DAA", "S.A.Tehnology co.,Ltd." },
{ "000DA0", "NEDAP N.V." },
{ "000D9F", "RF Micro Devices" },
{ "000D9A", "INFOTEC LTD" },
{ "000D8D", "Prosoft Technology, Inc" },
{ "000D8E", "Koden Electronics Co., Ltd." },
{ "000D84", "Makus Inc." },
{ "000D83", "Sanmina-SCI Hungary  Ltd." },
{ "000D76", "Hokuto Denshi Co,. Ltd." },
{ "000D7D", "Afco Systems" },
{ "000E51", "tecna elettronica srl" },
{ "000E4C", "Bermai Inc." },
{ "000E4B", "atrium c and i" },
{ "000E3E", "Sun Optronics Inc" },
{ "000E45", "Beijing Newtry Electronic Technology Ltd" },
{ "000E39", "Cisco Systems, Inc" },
{ "000E32", "Kontron Medical" },
{ "000E2B", "Safari Technologies" },
{ "000E2C", "Netcodec co." },
{ "000E1F", "TCL Networks Equipment Co., Ltd." },
{ "000E26", "Gincom Technology Corp." },
{ "000E1A", "JPS Communications" },
{ "000E19", "LogicaCMG Pty Ltd" },
{ "000E13", "Accu-Sort Systems inc." },
{ "000E0F", "ERMME" },
{ "000E05", "WIRELESS MATRIX CORP." },
{ "000E06", "Team Simoco Ltd" },
{ "000E0B", "Netac Technology Co., Ltd." },
{ "000DF8", "ORGA Kartensysteme GmbH" },
{ "000DFF", "CHENMING MOLD INDUSTRY CORP." },
{ "000DEC", "Cisco Systems, Inc" },
{ "000DF3", "Asmax Solutions" },
{ "000DE6", "YOUNGBO ENGINEERING CO.,LTD" },
{ "000DE5", "Samsung Thales" },
{ "000DE0", "ICPDAS Co.,LTD" },
{ "000DD3", "SAMWOO Telecommunication Co.,Ltd." },
{ "000DD4", "Symantec Corporation" },
{ "000DD9", "Anton Paar GmbH" },
{ "000DCD", "GROUPE TXCOM" },
{ "000EAA", "Scalent Systems, Inc." },
{ "000E9E", "Topfield Co., Ltd" },
{ "000EA3", "CNCR-IT CO.,LTD,HangZhou P.R.CHINA" },
{ "000EA4", "Certance Inc." },
{ "000E92", "Open Telecom" },
{ "000E97", "Ultracker Technology CO., Inc" },
{ "000E91", "Navico Auckland Ltd" },
{ "000E8B", "Astarte Technology Co, Ltd." },
{ "000E84", "Cisco Systems, Inc" },
{ "000D6A", "Redwood Technologies LTD" },
{ "000D71", "boca systems" },
{ "000D5E", "NEC Personal Products" },
{ "000D63", "DENT Instruments, Inc." },
{ "000D64", "COMAG Handels AG" },
{ "000D57", "Fujitsu I-Network Systems Limited." },
{ "000D52", "Comart system" },
{ "000D51", "DIVR Systems, Inc." },
{ "000D47", "Collex" },
{ "000DC1", "SafeWeb Inc" },
{ "000DC6", "DigiRose Technology Co., Ltd." },
{ "000DBA", "Océ Document Technologies GmbH" },
{ "000DB4", "NETASQ" },
{ "000DB3", "SDO Communication Corperation" },
{ "000DAE", "SAMSUNG HEAVY INDUSTRIES CO., LTD." },
{ "000DA6", "Universal Switching Corporation" },
{ "000E78", "Amtelco" },
{ "000E70", "in2 Networks" },
{ "000E6B", "Janitza electronics GmbH" },
{ "000E64", "Elphel, Inc" },
{ "000E5D", "Triple Play Technologies A/S" },
{ "000E5E", "Raisecom Technology" },
{ "000E58", "Sonos, Inc." },
{ "000BE2", "Lumenera Corporation" },
{ "000BE7", "COMFLUX TECHNOLOGY INC." },
{ "000BD6", "Paxton Access Ltd" },
{ "000BD2", "Remopro Technology Inc." },
{ "000BC6", "ISAC, Inc." },
{ "000BCB", "Fagor Automation , S. Coop" },
{ "000BBF", "Cisco Systems, Inc" },
{ "000BBA", "Harmonic, Inc" },
{ "000BB3", "RiT technologies Ltd." },
{ "000C38", "TelcoBridges Inc." },
{ "000C3F", "Cogent Defence & Security Networks," },
{ "000C30", "Cisco Systems, Inc" },
{ "000C26", "Weintek Labs. Inc." },
{ "000C2E", "Openet information technology(shenzhen) Co., Ltd." },
{ "000C25", "Allied Telesis Labs, Inc. " },
{ "000C1F", "Glimmerglass Networks" },
{ "000C24", "ANATOR" },
{ "000C1B", "ORACOM Co, Ltd." },
{ "000C19", "Telio Communications GmbH" },
{ "000C7A", "DaTARIUS Technologies GmbH" },
{ "000C67", "OYO ELECTRIC CO.,LTD" },
{ "000C4F", "UDTech Japan Corporation" },
{ "000C54", "Pedestal Networks, Inc" },
{ "000C5B", "HANWANG TECHNOLOGY CO.,LTD" },
{ "000C60", "ACM Systems" },
{ "000C62", "ABB AB, Cewe-Control " },
{ "000C48", "QoStek Corporation" },
{ "000C4D", "Curtiss-Wright Controls Avionics & Electronics" },
{ "000C14", "Diagnostic Instruments, Inc." },
{ "000C07", "Iftest AG" },
{ "000C06", "Nixvue Systems  Pte Ltd" },
{ "000C08", "HUMEX Technologies Corp." },
{ "000C0D", "Communications & Power Industries / Satcom Division" },
{ "000BF5", "Shanghai Sibo Telecom Technology Co.,Ltd" },
{ "000BFA", "EXEMYS SRL" },
{ "000C01", "Abatron AG" },
{ "000BEE", "inc.jet, Incorporated" },
{ "000CE6", "Meru Networks Inc" },
{ "000CEB", "CNMP Networks, Inc." },
{ "000CE2", "Rolls-Royce" },
{ "000CEC", "Spectracom Corp." },
{ "000CD7", "Nallatech Ltd" },
{ "000CDE", "ABB STOTZ-KONTAKT GmbH" },
{ "000CD2", "Schaffner EMV AG" },
{ "000CD8", "M. K. Juchheim GmbH & Co" },
{ "000CC6", "Ka-Ro electronics GmbH" },
{ "000CCB", "Design Combus Ltd" },
{ "000CC5", "Nextlink Co., Ltd." },
{ "000CB3", "ROUND Co.,Ltd." },
{ "000CB8", "MEDION AG" },
{ "000CBF", "Holy Stone Ent. Co., Ltd." },
{ "000A07", "WebWayOne Ltd" },
{ "000CA1", "SIGMACOM Co., LTD." },
{ "000CA6", "Mintera Corporation" },
{ "000CA8", "Garuda Networks Corporation" },
{ "000CAD", "BTU International" },
{ "000C95", "PrimeNet" },
{ "000C9A", "Hitech Electronics Corp." },
{ "000C8E", "Mentor Engineering Inc" },
{ "000C93", "Xeline Co., Ltd." },
{ "000C7F", "synertronixx GmbH" },
{ "000C82", "NETWORK TECHNOLOGIES INC" },
{ "000C87", "AMD" },
{ "000C73", "TELSON ELECTRONICS CO., LTD" },
{ "000D1D", "HIGH-TEK HARNESS ENT. CO., LTD." },
{ "000D1E", "Control Techniques" },
{ "000D0C", "MDI Security Systems" },
{ "000D11", "DENTSPLY - Gendex" },
{ "000D05", "cybernet manufacturing inc." },
{ "000CF9", "Xylem Water Solutions" },
{ "000CFE", "Grand Electronic Co., Ltd" },
{ "000CF2", "GAMESA Eólica" },
{ "000D43", "DRS Tactical Systems Inc." },
{ "000D37", "WIPLUG" },
{ "000D3E", "APLUX Communications Ltd." },
{ "000D3D", "Hammerhead Systems, Inc." },
{ "000D30", "IceFyre Semiconductor" },
{ "000D2B", "Racal Instruments" },
{ "000D24", "SENTEC E&E CO., LTD." },
{ "000D18", "Mega-Trend Electronics CO., LTD." },
{ "000BA4", "Shiron Satellite Communications Ltd. (1996)" },
{ "000BA9", "CloudShield Technologies, Inc." },
{ "000BA3", "Siemens AG, I&S" },
{ "000B91", "Aglaia Gesellschaft für Bildverarbeitung und Kommunikation mbH" },
{ "000B96", "Innotrac Diagnostics Oy" },
{ "000B9D", "TwinMOS Technologies Inc." },
{ "000B8A", "MITEQ Inc." },
{ "000B7E", "SAGINOMIYA Seisakusho Inc." },
{ "000B83", "DATAWATT B.V." },
{ "000AAD", "Stargames Corporation" },
{ "000AB2", "Fresnel Wireless Systems" },
{ "000AB4", "ETIC Telecommunications" },
{ "000AB9", "Astera Technologies Corp." },
{ "000AA1", "V V S Limited" },
{ "000AA6", "Hochiki Corporation" },
{ "000A8E", "Invacom Ltd" },
{ "000A9F", "Pannaway Technologies, Inc." },
{ "000A99", "Calamp Wireless Networks Inc" },
{ "000A93", "W2 Networks, Inc." },
{ "000A7F", "Teradon Industries, Inc" },
{ "000A86", "Lenze" },
{ "000A8B", "Cisco Systems, Inc" },
{ "000B15", "Platypus Technology" },
{ "000B10", "11wave Technonlogy Co.,Ltd" },
{ "000B09", "Ifoundry Systems Singapore" },
{ "000B04", "Volktek Corporation" },
{ "000AFD", "Kentec Electronics" },
{ "000B02", "Dallmeier electronic" },
{ "000AF1", "Clarity Design, Inc." },
{ "000AF6", "Emerson Climate Technologies Retail Solutions, Inc." },
{ "000AEB", "Shenzhen Tp-Link Technology Co; Ltd." },
{ "000AE4", "Wistron Corp." },
{ "000A0E", "Invivo Research Inc." },
{ "000A13", "Honeywell Video Systems" },
{ "000A04", "3Com Ltd" },
{ "0009FD", "Ubinetics Limited" },
{ "0009F4", "Alcon Laboratories, Inc." },
{ "0009E7", "ADC Techonology" },
{ "0009EE", "MEIKYO ELECTRIC CO.,LTD" },
{ "0009F3", "WELL Communication Corp." },
{ "0009E2", "Sinbon Electronics Co., Ltd." },
{ "0009DB", "eSpace" },
{ "000B6B", "Wistron Neweb Corp." },
{ "000B70", "Load Technology, Inc." },
{ "000B72", "Lawo AG" },
{ "000B77", "Cogent Systems, Inc." },
{ "000B71", "Litchfield Communications Inc." },
{ "000B5F", "Cisco Systems, Inc" },
{ "000B64", "Kieback & Peter GmbH & Co KG" },
{ "000B5B", "Rincon Research Corporation" },
{ "000B56", "Cybernetics" },
{ "000B4E", "VertexRSI, General Dynamics SatCOM Technologies, Inc." },
{ "000B53", "INITIUM Co., Ltd." },
{ "000A35", "Xilinx" },
{ "000A3A", "J-THREE INTERNATIONAL Holding Co., Ltd." },
{ "000A3C", "Enerpoint Ltd." },
{ "000A41", "Cisco Systems, Inc" },
{ "000A48", "Albatron Technology" },
{ "000A2E", "MAPLE NETWORKS CO., LTD" },
{ "000A26", "CEIA S.p.A." },
{ "000A28", "Motorola" },
{ "000A21", "Integra Telecom Co. Ltd" },
{ "000A1A", "Imerge Ltd" },
{ "000A15", "Silicon Data, Inc" },
{ "000B42", "commax Co., Ltd." },
{ "000B47", "Advanced Energy" },
{ "000B34", "ShangHai Broadband Technologies CO.LTD" },
{ "000B36", "Productivity Systems, Inc." },
{ "000B28", "Quatech Inc." },
{ "000B2F", "bplan GmbH" },
{ "000B1C", "SIBCO bv" },
{ "000B21", "G-Star Communications Inc." },
{ "000B23", "Siemens Subscriber Networks" },
{ "000A7A", "Kyoritsu Electric Co., Ltd." },
{ "000A6E", "Harmonic, Inc" },
{ "000A73", "Scientific Atlanta" },
{ "000A60", "Autostar Technology Pte Ltd" },
{ "000A67", "OngCorp" },
{ "000A6C", "Walchem Corporation" },
{ "000A5B", "Power-One as" },
{ "000A59", "HW server" },
{ "000A54", "Laguna Hills, Inc." },
{ "000A4D", "Noritz Corporation" },
{ "000ADF", "Gennum Corporation" },
{ "000AD8", "IPCserv Technology Corp." },
{ "000ACC", "Winnow Networks, Inc." },
{ "000AD1", "MWS" },
{ "000AD3", "INITECH Co., Ltd" },
{ "000AC0", "Fuyoh Video Industry CO., LTD." },
{ "000AC5", "Color Kinetics" },
{ "00097B", "Cisco Systems, Inc" },
{ "000982", "Loewe Opta GmbH" },
{ "000976", "Datasoft ISDN Systems GmbH" },
{ "000969", "Meret Optical Communications" },
{ "000963", "Dominion Lasercom Inc." },
{ "00096A", "Cloverleaf Communications Inc." },
{ "00096F", "Beijing Zhongqing Elegant Tech. Corp.,Limited" },
{ "00095D", "Dialogue Technology Corp." },
{ "00095F", "Telebyte, Inc." },
{ "000958", "INTELNET S.A." },
{ "00094C", "Communication Weaver Co.,Ltd." },
{ "000951", "Apogee Imaging Systems" },
{ "00094B", "FillFactory NV" },
{ "0009AE", "OKANO ELECTRIC CO.,LTD" },
{ "0009AD", "HYUNDAI SYSCOMM, INC." },
{ "0009B4", "KISAN TELECOM CO., LTD." },
{ "0009A8", "Eastmode Pte Ltd" },
{ "00099B", "Western Telematic Inc." },
{ "00099C", "Naval Research Laboratory" },
{ "0009A1", "Telewise Communications, Inc." },
{ "000995", "Castle Technology Ltd" },
{ "000989", "VividLogic Inc." },
{ "00098E", "ipcas GmbH" },
{ "00097C", "Cisco Systems, Inc" },
{ "0009C8", "SINAGAWA TSUSHIN KEISOU SERVICE" },
{ "0009CF", "iAd GmbH" },
{ "0009D4", "Transtech Networks" },
{ "0009BB", "MathStar, Inc." },
{ "0009C0", "6WIND" },
{ "000807", "Access Devices Limited" },
{ "000801", "HighSpeed Surfing Inc." },
{ "000808", "PPT Vision, Inc." },
{ "0007F7", "Galtronics" },
{ "0007FE", "Rigaku Corporation" },
{ "0007F8", "ITDevices, Inc." },
{ "0007EB", "Cisco Systems, Inc" },
{ "0007F1", "TeraBurst Networks Inc." },
{ "0007E5", "Coup Corporation" },
{ "0007DF", "Vbrick Systems Inc." },
{ "0007DE", "eCopilt AB" },
{ "0007CF", "Anoto AB" },
{ "0007D2", "Logopak Systeme GmbH & Co. KG" },
{ "0008AA", "KARAM" },
{ "0008A4", "Cisco Systems, Inc" },
{ "000898", "Gigabit Optics Corporation" },
{ "00089D", "UHD-Elektronik" },
{ "000890", "AVILINKS SA" },
{ "000889", "Echostar Technologies Corp" },
{ "000884", "Index Braille AB" },
{ "000877", "Liebert-Hiross Spa" },
{ "08006B", "ACCEL TECHNOLOGIES INC." },
{ "000871", "NORTHDATA Co., Ltd." },
{ "00087D", "Cisco Systems, Inc" },
{ "000876", "SDSystem" },
{ "0008E6", "Littlefeet" },
{ "0008D9", "Mitadenshi Co.,LTD" },
{ "0008D4", "IneoQuest Technologies, Inc" },
{ "0008CD", "With-Net Inc" },
{ "0008D3", "Hercules Technologies S.A.S." },
{ "0008C3", "Contex A/S" },
{ "0008BD", "TEPG-US" },
{ "0008BC", "Ilevo AB" },
{ "0008B7", "HIT Incorporated" },
{ "0008B0", "BKtel communications GmbH" },
{ "00086A", "Securiton Gmbh" },
{ "000864", "Fasy S.p.A." },
{ "00085E", "PCO AG" },
{ "000851", "Canadian Bank Note Company, Ltd." },
{ "000852", "Davolink Co. Inc." },
{ "000857", "Polaris Networks, Inc." },
{ "00081B", "Windigo Systems" },
{ "000822", "InPro Comm" },
{ "00082E", "Multitone Electronics PLC" },
{ "00081C", "@pos.com" },
{ "000828", "Koei Engineering Ltd." },
{ "000816", "Bluelon ApS" },
{ "000815", "CATS Co., Ltd." },
{ "00091A", "Macat Optics & Electronics Co., Ltd." },
{ "000919", "MDS Gateways" },
{ "000913", "SystemK Corporation" },
{ "00090C", "Mayekawa Mfg. Co. Ltd." },
{ "000907", "Chrysalis Development" },
{ "000900", "TMT" },
{ "0008F8", "UTC CCS" },
{ "0008F3", "WANY" },
{ "0008EC", "Optical Zonu Corporation" },
{ "0008E0", "ATO Technology Ltd." },
{ "0008E5", "IDK Corporation" },
{ "000945", "Palmmicro Communications Inc" },
{ "00093E", "C&I Technologies" },
{ "000932", "Omnilux" },
{ "000939", "ShibaSoku Co.,Ltd." },
{ "000926", "YODA COMMUNICATIONS, INC." },
{ "00092B", "iQstor Networks, Inc." },
{ "00092C", "Hitpoint Inc." },
{ "00091F", "A&D Co., Ltd." },
{ "000751", "m-u-t AG" },
{ "000750", "Cisco Systems, Inc" },
{ "000746", "TURCK, Inc." },
{ "00074A", "Carl Valentin GmbH" },
{ "00073A", "Inventel Systemes" },
{ "000734", "ONStor, Inc." },
{ "000739", "Scotty Group Austria Gmbh" },
{ "00072D", "CNSystems" },
{ "000727", "Zi Corporation (HK) Ltd." },
{ "000717", "Wieland Electric GmbH" },
{ "00071E", "Tri-M Engineering / Nupak Dev. Corp." },
{ "000723", "ELCON Systemtechnik GmbH" },
{ "00071D", "Satelsa Sistemas Y Aplicaciones De Telecomunicaciones, S.A." },
{ "000632", "Mesco Engineering GmbH" },
{ "000625", "The Linksys Group, Inc." },
{ "00062C", "Bivio Networks" },
{ "000624", "Gentner Communications Corp." },
{ "00061B", "Notebook Development Lab.  Lenovo Japan Ltd." },
{ "000622", "Chung Fu Chen Yeh Enterprise Corp." },
{ "00061C", "Hoshino Metal Industries, Ltd." },
{ "000621", "Hinox, Co., Ltd." },
{ "00060B", "Artesyn Embedded Technologies" },
{ "000611", "Zeus Wireless, Inc." },
{ "000615", "Kimoto Electric Co., Ltd." },
{ "000605", "Inncom International, Inc." },
{ "0005E3", "LightSand Communications, Inc." },
{ "0005EF", "ADOIR Digital Technology" },
{ "0005F6", "Young Chang Co. Ltd." },
{ "0005E9", "Unicess Network, Inc." },
{ "0005F0", "SATEC" },
{ "0005FC", "Schenck Pegasus Corp." },
{ "0005E0", "Empirix Corp." },
{ "0005D6", "L-3 Linkabit" },
{ "0005C4", "Telect, Inc." },
{ "0005D0", "Solinet Systems" },
{ "0005CA", "Hitron Technology, Inc." },
{ "0005BD", "ROAX BV" },
{ "0005BE", "Kongsberg Seatex AS" },
{ "0005C3", "Pacific Instruments, Inc." },
{ "00059D", "Daniel Computing Systems, Inc." },
{ "000796", "LSI Systems, Inc." },
{ "000790", "Tri-M Technologies (s) Limited" },
{ "000784", "Cisco Systems, Inc" },
{ "000789", "DONGWON SYSTEMS" },
{ "000783", "SynCom Network, Inc." },
{ "00078A", "Mentor Data System Inc." },
{ "00077A", "Infoware System Co., Ltd." },
{ "00076D", "Flexlight Networks" },
{ "000769", "Italiana Macchi SpA" },
{ "000773", "Ascom Powerline Communications Ltd." },
{ "00075D", "Celleritas Inc." },
{ "000763", "Sunniwell Cyber Tech. Co., Ltd." },
{ "000756", "Juyoung Telecom" },
{ "0007C9", "Technol Seven Co., Ltd." },
{ "00047B", "Schlumberger" },
{ "0007C3", "Thomson" },
{ "0007BD", "Radionet Ltd." },
{ "0007B0", "Office Details, Inc." },
{ "0007B7", "Samurai Ind. Prods Eletronicos Ltda" },
{ "0007B6", "Telecom Technology Ltd." },
{ "0007A3", "Ositis Software, Inc." },
{ "0007A9", "Novasonics" },
{ "0007AC", "Eolring" },
{ "00079C", "Golden Electronics Technology Co., Ltd." },
{ "0006AB", "W-Link Systems, Inc." },
{ "0006A5", "PINON Corp." },
{ "0006A1", "Celsian Technologies, Inc." },
{ "000694", "Mobillian Corporation" },
{ "00069B", "AVT Audio Video Technologies GmbH" },
{ "00068E", "HID Corporation" },
{ "000688", "Telways Communication Co., Ltd." },
{ "000682", "Convedia" },
{ "000681", "Goepel Electronic GmbH" },
{ "000655", "Yipee, Inc." },
{ "00D05F", "VALCOM, INC." },
{ "000674", "Spectrum Control, Inc." },
{ "000678", "Marantz Brand Company" },
{ "000661", "NIA Home Technologies Corp." },
{ "000668", "Vicon Industries Inc." },
{ "000667", "Tripp Lite" },
{ "00066E", "Delta Electronics, Inc." },
{ "00064E", "Broad Net Technology Inc." },
{ "00064F", "PRO-NETS Technology Corporation" },
{ "000642", "Genetel Systems Inc." },
{ "00063E", "Opthos Inc." },
{ "000648", "Seedsware, Inc." },
{ "000638", "Sungjin C&C Co., Ltd." },
{ "00070B", "Novabase SGPS, SA" },
{ "000710", "Adax, Inc." },
{ "000700", "Zettamedia Korea" },
{ "0006F9", "Mitsui Zosen Systems Research Inc." },
{ "000703", "CSEE Transport" },
{ "000706", "Sanritz Corporation" },
{ "0006E8", "Optical Network Testing, Inc." },
{ "0006EE", "Shenyang Neu-era Information & Technology Stock Co., Ltd" },
{ "0006E2", "Ceemax Technology Co., Ltd." },
{ "0006D8", "Maple Optical Systems" },
{ "0006D4", "Interactive Objects, Inc." },
{ "0006CE", "DATENO" },
{ "0006B7", "TELEM GmbH" },
{ "0006BE", "Baumer Optronic GmbH" },
{ "0006B8", "Bandspeed Pty Ltd" },
{ "0006BD", "BNTECHNOLOGY Co., Ltd." },
{ "0006C2", "Smartmatic Corporation" },
{ "0006C7", "RFNET Technologies Pte Ltd (S)" },
{ "0006B1", "Sonicwall" },
{ "000475", "3 Com Corporation" },
{ "00046F", "Digitel S/A Industria Eletronica" },
{ "000468", "Vivity, Inc." },
{ "00045C", "Mobiwave Pte Ltd" },
{ "000463", "Bosch Security Systems" },
{ "000462", "DAKOS Data & Communication Co., Ltd." },
{ "000455", "ANTARA.net" },
{ "000456", "Cambium Networks Limited" },
{ "000450", "DMD Computers SRL" },
{ "000446", "CYZENTECH Co., Ltd." },
{ "00044B", "NVIDIA" },
{ "0005AD", "Topspin Communications, Inc." },
{ "0005B1", "ASB Technology BV" },
{ "0005B7", "Arbor Technology Corp." },
{ "0005A3", "QEI, Inc." },
{ "000597", "Eagle Traffic Control Systems" },
{ "000591", "Active Silicon Ltd" },
{ "00058A", "Netcom Co., Ltd." },
{ "000590", "Swissvoice Ltd." },
{ "00057E", "Eckelmann Steuerungstechnik GmbH" },
{ "000578", "Private" },
{ "000584", "AbsoluteValue Systems, Inc." },
{ "00052E", "Cinta Networks" },
{ "00053A", "Willowglen Services Pte Ltd" },
{ "000528", "New Focus, Inc." },
{ "000527", "SJ Tek Co. Ltd" },
{ "000521", "Control Microsystems" },
{ "000515", "Nuark Co., Ltd." },
{ "00051B", "Magic Control Technology Corporation" },
{ "000511", "Complementary Technologies Ltd" },
{ "00050B", "SICOM Systems, Inc." },
{ "000501", "Cisco Systems, Inc" },
{ "000505", "Systems Integration Solutions, Inc." },
{ "000504", "Naray Information & Communication Enterprise" },
{ "0004FB", "Commtech, Inc." },
{ "000574", "Cisco Systems, Inc" },
{ "000567", "Etymonic Design, Inc." },
{ "00056E", "National Enhance Technology, Inc." },
{ "00056D", "Pacific Corporation" },
{ "000561", "nac Image Technology, Inc." },
{ "00055B", "Charles Industries, Ltd." },
{ "000554", "Rangestar Wireless" },
{ "000555", "Japan Cash Machine Co., Ltd." },
{ "000547", "Starent Networks" },
{ "00054E", "Philips" },
{ "000540", "FAST Corporation" },
{ "000541", "Advanced Systems Co., Ltd." },
{ "000534", "Northstar Engineering Ltd." },
{ "0004F4", "Infinite Electronics Inc." },
{ "0004EE", "Lincoln Electric Company" },
{ "0004E8", "IER, Inc." },
{ "008086", "COMPUTER GENERATION INC." },
{ "0004DE", "Cisco Systems, Inc" },
{ "0004E4", "Daeryung Ind., Inc." },
{ "0004D7", "Omitec Instrumentation Ltd." },
{ "0004D8", "IPWireless, Inc." },
{ "0004D2", "Adcon Telemetry GmbH" },
{ "0004D1", "Drew Technologies, Inc." },
{ "0004CB", "Tdsoft Communication, Ltd." },
{ "0004BF", "VersaLogic Corp." },
{ "0004C5", "ASE Technologies, USA" },
{ "00043F", "ESTeem Wireless Modems, Inc" },
{ "000439", "Rosco Entertainment Technology, Inc." },
{ "000433", "Cyberboard A/S" },
{ "00042C", "Minet, Inc." },
{ "000427", "Cisco Systems, Inc" },
{ "000426", "Autosys" },
{ "000420", "Slim Devices, Inc." },
{ "000413", "SNOM Technology AG" },
{ "000418", "Teltronic S.A.U." },
{ "000412", "WaveSmith Networks, Inc." },
{ "00040C", "Kanno Works, Ltd." },
{ "000370", "NXTV, Inc." },
{ "000405", "ACN Technologies" },
{ "000406", "Fa. Metabox AG" },
{ "0003FB", "ENEGATE Co.,Ltd." },
{ "0003FC", "Intertex Data AB" },
{ "0003EF", "Oneline AG" },
{ "0003F6", "Allegro Networks, Inc." },
{ "0003EA", "Mega System Technologies, Inc." },
{ "0003E9", "Akara Canada, Inc." },
{ "0003E4", "Cisco Systems, Inc" },
{ "0003D8", "iMPath Networks, Inc." },
{ "0003D5", "Advanced Communications Co., Ltd." },
{ "0003CC", "Momentum Computer, Inc." },
{ "0003D1", "Takaya Corporation" },
{ "0003C5", "Mobotix AG" },
{ "0003BE", "Netility" },
{ "0003B9", "Hualong Telecom Co., Ltd." },
{ "0003B7", "ZACCESS Systems" },
{ "0003B3", "IA Link Systems Co., Ltd." },
{ "0003A7", "Unixtar Technology, Inc." },
{ "0003AE", "Allied Advanced Manufacturing Pte, Ltd." },
{ "0003A0", "Cisco Systems, Inc" },
{ "000398", "WISI" },
{ "00039B", "NetChip Technology, Inc." },
{ "000394", "Connect One" },
{ "00038D", "PCS Revenue Control Systems, Inc." },
{ "000385", "Actelis Networks, Inc." },
{ "000388", "Fastfame Technology Co., Ltd." },
{ "00037F", "Atheros Communications, Inc." },
{ "0004B8", "Kumahira Co., Ltd." },
{ "0004B2", "ESSEGI SRL" },
{ "0004AE", "Sullair Corporation" },
{ "0004AB", "Comverse Network Systems, Inc." },
{ "00049F", "Freescale Semiconductor" },
{ "0004A4", "NetEnabled, Inc." },
{ "00049E", "Wirelink Co., Ltd." },
{ "000498", "Mahi Networks" },
{ "000491", "Technovision, Inc." },
{ "00048C", "Nayna Networks, Inc." },
{ "000492", "Hive Internet, Ltd." },
{ "000485", "PicoLight" },
{ "000307", "Secure Works, Inc." },
{ "000300", "Barracuda Networks, Inc." },
{ "0002F8", "SEAKR Engineering, Inc." },
{ "00D024", "Cognex Corporation" },
{ "0002F4", "PCTEL, Inc." },
{ "0002FB", "Baumuller Aulugen-Systemtechnik GmbH" },
{ "0002E9", "CS Systemes De Securite - C3S" },
{ "0002DD", "Bromax Communications, Ltd." },
{ "0002E2", "NDC Infared Engineering" },
{ "0002DA", "ExiO Communications, Inc." },
{ "0002D6", "NICE Systems" },
{ "0002CA", "EndPoints, Inc." },
{ "0002CF", "ZyGate Communications, Inc." },
{ "0001CD", "ARtem" },
{ "0001D2", "inXtron, Inc. " },
{ "0001C9", "Cisco Systems, Inc" },
{ "0001C7", "Cisco Systems, Inc" },
{ "0001C2", "ARK Research Corp." },
{ "0001BE", "Gigalink Co., Ltd." },
{ "0001BC", "Brains Corporation" },
{ "0001AC", "Sitara Networks, Inc." },
{ "0001A9", "BMW AG" },
{ "0001B0", "Fulltek Technology Co., Ltd." },
{ "000179", "WIRELESS TECHNOLOGY, INC." },
{ "000185", "Hitachi Aloka Medical, Ltd." },
{ "00018C", "Mega Vision" },
{ "000192", "Texas Digital Systems" },
{ "00019E", "ESS Technology, Inc." },
{ "001095", "Thomson Inc." },
{ "000278", "Samsung Electro-Mechanics Co., Ltd." },
{ "00025A", "Catena Networks" },
{ "000271", "Zhone Technologies" },
{ "00026C", "Philips CFT" },
{ "00026A", "Cocess Telecom Co., Ltd." },
{ "000266", "Thermalogic Corporation" },
{ "00025F", "Nortel Networks" },
{ "000256", "Alpha Processor, Inc." },
{ "000251", "Soma Networks, Inc." },
{ "00024A", "Cisco Systems, Inc" },
{ "00024D", "Mannesman Dematic Colby Pty. Ltd." },
{ "000245", "Lampus Co, Ltd." },
{ "00023E", "Selta Telematica S.p.a" },
{ "00023B", "Ericsson" },
{ "000237", "Cosmo Research Corp." },
{ "000234", "Imperial Technology, Inc." },
{ "000228", "Necsom, Ltd." },
{ "000224", "C-COR" },
{ "00020D", "Micronpc.com" },
{ "000220", "CANON FINETECH INC." },
{ "000378", "HUMAX Co., Ltd." },
{ "00036C", "Cisco Systems, Inc" },
{ "000373", "Aselsan A.S" },
{ "000368", "Embedone Co., Ltd." },
{ "000366", "ASM Pacific Technology" },
{ "000365", "Kira Information & Communications, Ltd." },
{ "000360", "PAC Interactive Technology, Inc." },
{ "00035D", "Bosung Hi-Net Co., Ltd." },
{ "00031A", "Beijing Broad Telecom Ltd., China" },
{ "000359", "DigitalSis" },
{ "000354", "Fiber Logic Communications" },
{ "000352", "Colubris Networks" },
{ "00034E", "Pos Data Company, Ltd." },
{ "000342", "Nortel Networks" },
{ "0002C3", "Arelnet Ltd." },
{ "0002BE", "Totsu Engineering, Inc." },
{ "0002BA", "Cisco Systems, Inc" },
{ "0002B2", "Cablevision" },
{ "0002B5", "Avnet, Inc." },
{ "0002AE", "Scannex Electronics Ltd." },
{ "0002A7", "Vivace Networks" },
{ "0002A2", "Hilscher GmbH" },
{ "000297", "C-COR.net" },
{ "00028E", "Rapid 5 Networks, Inc." },
{ "000293", "Solid Data Systems" },
{ "0001FA", "HOROSCAS" },
{ "000284", "AREVA T&D" },
{ "00027D", "Cisco Systems, Inc" },
{ "00033F", "BigBand Networks, Ltd." },
{ "000336", "Zetes Technologies" },
{ "00033B", "TAMI Tech Co., Ltd." },
{ "000328", "Mace Group, Inc." },
{ "00032F", "Global Sun Technology, Inc." },
{ "000320", "Xpeed, Inc." },
{ "000323", "Cornet Technology, Inc." },
{ "00029F", "L-3 Communication Aviation Recorders" },
{ "00031F", "Condev Ltd." },
{ "000317", "Merlin Systems, Inc." },
{ "00030E", "Core Communications Co., Ltd." },
{ "000313", "Access Media SPA" },
{ "0001A5", "Nextcomm, Inc." },
{ "0001A1", "Mag-Tek, Inc." },
{ "000195", "Sena Technologies, Inc." },
{ "00017D", "ThermoQuest" },
{ "000189", "Refraction Technology, Inc." },
{ "00308B", "Brix Networks" },
{ "00014F", "ADTRAN INC" },
{ "00015A", "Digital Video Broadcasting" },
{ "000166", "TC GROUP A/S" },
{ "00016D", "CarrierComm Inc." },
{ "00015F", "DIGITAL DESIGN GmbH" },
{ "000214", "DTVRO" },
{ "000210", "Fenecom" },
{ "000208", "Unify Networks, Inc." },
{ "000201", "IFM Electronic gmbh" },
{ "0001F5", "ERIM S.A." },
{ "0001FD", "Digital Voice Systems, Inc." },
{ "0001E5", "Supernet, Inc." },
{ "0001E8", "Force10 Networks, Inc." },
{ "0001D9", "Sigma, Inc." },
{ "0001E0", "Fast Systems, Inc." },
{ "0001D5", "HAEDONG INFO & COMM CO., LTD" },
{ "000118", "EZ Digital Co., Ltd." },
{ "000124", "Acer Incorporated" },
{ "000101", "Private" },
{ "00010D", "CORECO, INC." },
{ "000114", "KANDA TSUSHIN KOGYO CO., LTD." },
{ "000111", "iDigm Inc." },
{ "000105", "Beckhoff Automation GmbH" },
{ "00029C", "3COM" },
{ "00B009", "Grass Valley, A Belden Brand" },
{ "00B0B3", "Xstreamis PLC" },
{ "00B09D", "Point Grey Research Inc." },
{ "00B094", "Alaris, Inc." },
{ "00B048", "Marconi Communications Inc." },
{ "00B0C7", "Tellabs Operations, Inc." },
{ "003060", "Powerfile, Inc." },
{ "00301C", "ALTVATER AIRDATA SYSTEMS" },
{ "003015", "CP CLARE CORP." },
{ "0030E6", "Draeger Medical Systems, Inc." },
{ "003091", "TAIWAN FIRST LINE ELEC. CORP." },
{ "003080", "Cisco Systems, Inc" },
{ "0030AD", "SHANGHAI COMMUNICATION" },
{ "00305B", "Toko Inc." },
{ "003024", "Cisco Systems, Inc" },
{ "00301F", "OPTICAL NETWORKS, INC." },
{ "0030D9", "DATACORE SOFTWARE CORP." },
{ "00D0FF", "Cisco Systems, Inc" },
{ "003058", "API MOTION" },
{ "0030C6", "CONTROL SOLUTIONS, INC." },
{ "003036", "RMP ELEKTRONIKSYSTEME GMBH" },
{ "00308A", "NICOTRA SISTEMI S.P.A" },
{ "00302C", "SYLANTRO SYSTEMS CORPORATION" },
{ "003006", "SUPERPOWER COMPUTER" },
{ "003079", "CQOS, INC." },
{ "003059", "KONTRON COMPACT COMPUTERS AG" },
{ "0030B9", "ECTEL" },
{ "00303A", "MAATEL" },
{ "0030A3", "Cisco Systems, Inc" },
{ "003040", "Cisco Systems, Inc" },
{ "003064", "ADLINK TECHNOLOGY, INC." },
{ "003097", "AB Regin" },
{ "0030EB", "TURBONET COMMUNICATIONS, INC." },
{ "0030C8", "GAD LINE, LTD." },
{ "0030C9", "LuxN, N" },
{ "00B01E", "Rantic Labs, Inc." },
{ "00B064", "Cisco Systems, Inc" },
{ "0030A2", "Lightner Engineering" },
{ "0030DE", "WAGO Kontakttechnik GmbH" },
{ "00309E", "WORKBIT CORPORATION." },
{ "003057", "QTelNet, Inc." },
{ "00305C", "SMAR Laboratories Corp." },
{ "003082", "TAIHAN ELECTRIC WIRE CO., LTD." },
{ "0030AE", "Times N System, Inc." },
{ "00300D", "MMC Technology, Inc." },
{ "003075", "ADTECH" },
{ "0030E7", "CNF MOBILE SOLUTIONS, INC." },
{ "003019", "Cisco Systems, Inc" },
{ "003052", "ELASTIC NETWORKS" },
{ "003011", "HMS Industrial Networks   " },
{ "00304A", "Fraunhofer IPMS" },
{ "003014", "DIVIO, INC." },
{ "003029", "OPICOM" },
{ "0030BD", "BELKIN COMPONENTS" },
{ "0030BA", "AC&T SYSTEM CO., LTD." },
{ "00301D", "SKYSTREAM, INC." },
{ "003049", "BRYANT TECHNOLOGY, LTD." },
{ "003041", "SAEJIN T & M CO., LTD." },
{ "00308C", "Quantum Corporation" },
{ "00D04F", "BITRONICS, INC." },
{ "00D0EF", "IGT" },
{ "00D022", "INCREDIBLE TECHNOLOGIES, INC." },
{ "00D0C8", "Prevas A/S" },
{ "00D052", "ASCEND COMMUNICATIONS, INC." },
{ "00D0B1", "OMEGA ELECTRONICS SA" },
{ "00D0C1", "HARMONIC DATA SYSTEMS, LTD." },
{ "00D0F0", "CONVISION TECHNOLOGY GMBH" },
{ "00D00E", "PLURIS, INC." },
{ "00D055", "KATHREIN-WERKE KG" },
{ "00D095", "Alcatel-Lucent, Enterprise Business Group" },
{ "00D000", "FERRAN SCIENTIFIC, INC." },
{ "00D005", "ZHS ZEITMANAGEMENTSYSTEME" },
{ "00D019", "DAINIPPON SCREEN CORPORATE" },
{ "00D053", "CONNECTED SYSTEMS" },
{ "00D097", "Cisco Systems, Inc" },
{ "00016A", "ALITEC" },
{ "000176", "Orient Silver Enterprises" },
{ "000158", "Electro Industries/Gauge Tech" },
{ "00012D", "Komodo Technology" },
{ "000139", "Point Multimedia Systems" },
{ "000140", "Sendtek Corporation" },
{ "00014C", "Berkeley Process Control" },
{ "000135", "KDC Corp." },
{ "00013C", "TIW SYSTEMS" },
{ "000148", "X-traWeb Inc." },
{ "000120", "OSCILLOQUARTZ S.A." },
{ "000127", "OPEN Networks Pty Ltd" },
{ "00309C", "Timing Applications, Inc." },
{ "003086", "Transistor Devices, Inc." },
{ "0030B5", "Tadiran Microwave Networks" },
{ "003070", "1Net Corporation" },
{ "003044", "CradlePoint, Inc" },
{ "00307E", "Redflex Communication Systems" },
{ "00307A", "Advanced Technology & Systems" },
{ "0030B7", "Teletrol Systems, Inc." },
{ "0030B3", "San Valley Systems, Inc." },
{ "00303B", "PowerCom Technology" },
{ "0030BC", "Optronic AG" },
{ "003071", "Cisco Systems, Inc" },
{ "009003", "APLIO" },
{ "0090D7", "NetBoost Corp." },
{ "009093", "NANAO CORPORATION" },
{ "0090B4", "WILLOWBROOK TECHNOLOGIES" },
{ "009083", "TURBO COMMUNICATION, INC." },
{ "0090BD", "OMNIA COMMUNICATIONS, INC." },
{ "009094", "OSPREY TECHNOLOGIES, INC." },
{ "0090DD", "MIHARU COMMUNICATIONS Inc" },
{ "009028", "NIPPON SIGNAL CO., LTD." },
{ "00908C", "ETREND ELECTRONICS, INC." },
{ "00905D", "NETCOM SICHERHEITSTECHNIK GMBH" },
{ "009068", "DVT CORP." },
{ "009030", "HONEYWELL-DATING" },
{ "0090D3", "GIESECKE & DEVRIENT GmbH" },
{ "005081", "MURATA MACHINERY, LTD." },
{ "0050CB", "JETTER" },
{ "00500E", "CHROMATIS NETWORKS, INC." },
{ "0050FD", "VISIONCOMM CO., LTD." },
{ "0050FE", "PCTVnet ASA" },
{ "0050AB", "NALTEC, Inc." },
{ "005006", "TAC AB" },
{ "0050BF", "Metalligence Technology Corp." },
{ "005089", "SAFETY MANAGEMENT SYSTEMS" },
{ "005066", "AtecoM GmbH advanced telecomunication modules" },
{ "0050D9", "ENGETRON-ENGENHARIA ELETRONICA IND. e COM. LTDA" },
{ "005043", "MARVELL SEMICONDUCTOR, INC." },
{ "005018", "AMIT, Inc." },
{ "005059", "iBAHN" },
{ "00506A", "EDEVA, INC." },
{ "00502E", "CAMBEX CORPORATION" },
{ "005070", "CHAINTECH COMPUTER CO., LTD." },
{ "00503B", "MEDIAFIRE CORPORATION" },
{ "005084", "ATL PRODUCTS" },
{ "005055", "DOMS A/S" },
{ "00504B", "BARCONET N.V." },
{ "005046", "MENICX INTERNATIONAL CO., LTD." },
{ "00502C", "SOYO COMPUTER, INC." },
{ "005060", "TANDBERG TELECOM AS" },
{ "0050DD", "SERRA SOLDADURA, S.A." },
{ "00503F", "ANCHOR GAMES" },
{ "0050EE", "TEK DIGITEL CORPORATION" },
{ "005004", "3COM CORPORATION" },
{ "005072", "CORVIS CORPORATION" },
{ "005012", "CBL - GMBH" },
{ "0050E8", "NOMADIX INC." },
{ "0050F2", "MICROSOFT CORP." },
{ "005052", "TIARA NETWORKS, INC." },
{ "005064", "CAE ELECTRONICS" },
{ "0050B4", "SATCHWELL CONTROL SYSTEMS, LTD" },
{ "3C39E7", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "885D90", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "0050B2", "BRODEL GmbH" },
{ "78C2C0", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "C88ED1", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "E4956E", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "64FB81", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "00D081", "RTD Embedded Technologies, Inc." },
{ "00D011", "PRISM VIDEO, INC." },
{ "00D09B", "SPECTEL LTD." },
{ "00D031", "INDUSTRIAL LOGIC CORPORATION" },
{ "00D021", "REGENT ELECTRONICS CORP." },
{ "00D0DF", "KUZUMI ELECTRONICS, INC." },
{ "00D0B4", "KATSUJIMA CO., LTD." },
{ "00D079", "Cisco Systems, Inc" },
{ "00D0E2", "MRT MICRO, INC." },
{ "00D039", "UTILICOM, INC." },
{ "00504F", "OLENCOM ELECTRONICS" },
{ "0050A0", "DELTA COMPUTER SYSTEMS, INC." },
{ "005007", "SIEMENS TELECOMMUNICATION SYSTEMS LIMITED" },
{ "005015", "BRIGHT STAR ENGINEERING" },
{ "005031", "AEROFLEX LABORATORIES, INC." },
{ "0050DF", "AirFiber, Inc." },
{ "0050F3", "GLOBAL NET INFORMATION CO., Ltd." },
{ "005038", "DAIN TELECOM CO., LTD." },
{ "00D0E1", "AVIONITEK ISRAEL INC." },
{ "00D01B", "MIMAKI ENGINEERING CO., LTD." },
{ "00D06E", "TRENDVIEW RECORDERS LTD." },
{ "00D075", "ALARIS MEDICAL SYSTEMS, INC." },
{ "00509D", "THE INDUSTREE B.V." },
{ "00501E", "Grass Valley, A Belden Brand" },
{ "00502B", "GENRAD LTD." },
{ "00500A", "IRIS TECHNOLOGIES, INC." },
{ "00D027", "APPLIED AUTOMATION, INC." },
{ "00D0F6", "Alcatel Canada" },
{ "00D0F1", "SEGA ENTERPRISES, LTD." },
{ "00D009", "HSING TECH. ENTERPRISE CO. LTD" },
{ "00D080", "EXABYTE CORPORATION" },
{ "00D084", "NEXCOMM SYSTEMS, INC." },
{ "00D0B2", "XIOTECH CORPORATION" },
{ "00D0E6", "IBOND INC." },
{ "00D099", "Elcard Wireless Systems Oy" },
{ "0090AF", "J. MORITA MFG. CORP." },
{ "009088", "BAXALL SECURITY LTD." },
{ "0090E0", "SYSTRAN CORP." },
{ "00903E", "N.V. PHILIPS INDUSTRIAL ACTIVITIES" },
{ "0090B9", "BERAN INSTRUMENTS LTD." },
{ "00901A", "UNISPHERE SOLUTIONS" },
{ "0090AE", "ITALTEL S.p.A." },
{ "009082", "FORCE INSTITUTE" },
{ "00906A", "TURNSTONE SYSTEMS, INC." },
{ "0001FE", "DIGITAL EQUIPMENT CORPORATION" },
{ "009077", "ADVANCED FIBRE COMMUNICATIONS" },
{ "0090B2", "AVICI SYSTEMS INC." },
{ "009095", "UNIVERSAL AVIONICS" },
{ "009012", "GLOBESPAN SEMICONDUCTOR, INC." },
{ "0090B6", "FIBEX SYSTEMS" },
{ "0090F4", "LIGHTNING INSTRUMENTATION" },
{ "00904F", "ABB POWER T&D COMPANY, INC." },
{ "00905A", "DEARBORN GROUP, INC." },
{ "009066", "Troika Networks, Inc." },
{ "00907A", "Spectralink, Inc" },
{ "0090F0", "Harmonic Video Systems Ltd." },
{ "001047", "ECHO ELETRIC CO. LTD." },
{ "00100C", "ITO CO., LTD." },
{ "0010D0", "WITCOM, LTD." },
{ "001006", "Thales Contact Solutions Ltd." },
{ "0010D6", "Exelis" },
{ "001076", "EUREM GmbH" },
{ "00103F", "TOLLGRADE COMMUNICATIONS, INC." },
{ "001034", "GNP Computers" },
{ "001012", "PROCESSOR SYSTEMS (I) PVT LTD" },
{ "0010C8", "COMMUNICATIONS ELECTRONICS SECURITY GROUP" },
{ "0010D1", "Top Layer Networks, Inc." },
{ "0010F0", "RITTAL-WERK RUDOLF LOH GmbH & Co." },
{ "00106A", "DIGITAL MICROWAVE CORPORATION" },
{ "001030", "EION Inc." },
{ "0010A4", "XIRCOM" },
{ "001050", "RION CO., LTD." },
{ "00109C", "M-SYSTEM CO., LTD." },
{ "001064", "DNPG, LLC" },
{ "001020", "Hand Held Products Inc" },
{ "00106E", "TADIRAN COM. LTD." },
{ "00105B", "NET INSIGHT AB" },
{ "001002", "ACTIA" },
{ "0010A0", "INNOVEX TECHNOLOGIES, INC." },
{ "001074", "ATEN INTERNATIONAL CO., LTD." },
{ "001057", "Rebel.com, Inc." },
{ "0010BC", "Aastra Telecom" },
{ "001033", "ACCESSLAN COMMUNICATIONS, INC." },
{ "0004AC", "IBM Corp" },
{ "0010B4", "ATMOSPHERE NETWORKS" },
{ "0010F9", "UNIQUE SYSTEMS, INC." },
{ "001038", "MICRO RESEARCH INSTITUTE, INC." },
{ "00100A", "WILLIAMS COMMUNICATIONS GROUP" },
{ "001080", "METAWAVE COMMUNICATIONS" },
{ "0010AB", "KOITO ELECTRIC INDUSTRIES, LTD." },
{ "00903C", "ATLANTIC NETWORK SYSTEMS" },
{ "0090CE", "TETRA GmbH" },
{ "0090E3", "AVEX ELECTRONICS INC." },
{ "00900B", "LANNER ELECTRONICS, INC." },
{ "0090C8", "WAVERIDER COMMUNICATIONS (CANADA) INC." },
{ "0090B7", "DIGITAL LIGHTWAVE, INC." },
{ "009037", "ACUCOMM, INC." },
{ "009059", "TELECOM DEVICE K.K." },
{ "00E003", "NOKIA WIRELESS BUSINESS COMMUN" },
{ "00E0F3", "WebSprint Communications, Inc." },
{ "00E013", "EASTERN ELECTRONIC CO., LTD." },
{ "001063", "STARGUIDE DIGITAL NETWORKS" },
{ "0010A7", "UNEX TECHNOLOGY CORPORATION" },
{ "001039", "Vectron Systems AG" },
{ "0010C3", "CSI-CONTROL SYSTEMS" },
{ "00107F", "CRESTRON ELECTRONICS, INC." },
{ "00102C", "Lasat Networks A/S" },
{ "0010B7", "COYOTE TECHNOLOGIES, LLC" },
{ "006064", "NETCOMM LIMITED" },
{ "0060CB", "HITACHI ZOSEN CORPORATION" },
{ "006090", "Artiza Networks Inc" },
{ "0060A9", "GESYTEC MBH" },
{ "0060F2", "LASERGRAPHICS, INC." },
{ "006031", "HRK SYSTEMS" },
{ "0060A6", "PARTICLE MEASURING SYSTEMS" },
{ "006082", "NOVALINK TECHNOLOGIES, INC." },
{ "006012", "POWER COMPUTING CORPORATION" },
{ "00604D", "MMC NETWORKS, INC." },
{ "006048", "EMC CORPORATION" },
{ "00600F", "WESTELL, INC." },
{ "0060E5", "FUJI AUTOMATION CO., LTD." },
{ "006010", "NETWORK MACHINES, INC." },
{ "006044", "LITTON/POLY-SCIENTIFIC" },
{ "00609B", "ASTRO-MED, INC." },
{ "0060BE", "WEBTRONICS" },
{ "006052", "PERIPHERALS ENTERPRISE CO., Ltd." },
{ "00E03F", "JATON CORPORATION" },
{ "00E0EB", "DIGICOM SYSTEMS, INCORPORATED" },
{ "00E00E", "AVALON IMAGING SYSTEMS, INC." },
{ "00E0CD", "SAAB SENSIS CORPORATION" },
{ "00E0CB", "RESON, INC." },
{ "00E048", "SDL COMMUNICATIONS, INC." },
{ "00E083", "JATO TECHNOLOGIES, INC." },
{ "00E03D", "FOCON ELECTRONIC SYSTEMS A/S" },
{ "00E0FA", "TRL TECHNOLOGY, LTD." },
{ "00E02C", "AST COMPUTER" },
{ "00E00B", "ROOFTOP COMMUNICATIONS CORP." },
{ "00E067", "eac AUTOMATION-CONSULTING GmbH" },
{ "00E058", "PHASE ONE DENMARK A/S" },
{ "00E089", "ION Networks, Inc." },
{ "00E03B", "PROMINET CORPORATION" },
{ "006017", "TOKIMEC INC." },
{ "0060E6", "SHOMITI SYSTEMS INCORPORATED" },
{ "006053", "TOYODA MACHINE WORKS, LTD." },
{ "0060A0", "SWITCHED NETWORK TECHNOLOGIES, INC." },
{ "006019", "Roche Diagnostics" },
{ "006033", "ACUITY IMAGING, INC." },
{ "0060EE", "APOLLO" },
{ "006022", "VICOM SYSTEMS, INC." },
{ "006013", "NETSTAL MASCHINEN AG" },
{ "0060F4", "ADVANCED COMPUTER SOLUTIONS, Inc." },
{ "006011", "CRYSTAL SEMICONDUCTOR CORP." },
{ "00600E", "WAVENET INTERNATIONAL, INC." },
{ "0060C0", "Nera Networks AS" },
{ "00E062", "HOST ENGINEERING" },
{ "00E033", "E.E.P.D. GmbH" },
{ "00E079", "A.T.N.R." },
{ "00E09C", "MII" },
{ "00E075", "Verilink Corporation" },
{ "00E07A", "MIKRODIDAKT AB" },
{ "00E03E", "ALFATECH, INC." },
{ "00E09A", "Positron Inc." },
{ "0060D7", "ECOLE POLYTECHNIQUE FEDERALE DE LAUSANNE (EPFL)" },
{ "006087", "KANSAI ELECTRIC CO., LTD." },
{ "00E029", "STANDARD MICROSYSTEMS CORP." },
{ "00606B", "Synclayer Inc." },
{ "006073", "REDCREEK COMMUNICATIONS, INC." },
{ "006039", "SanCom Technology, Inc." },
{ "0060A5", "PERFORMANCE TELECOM CORP." },
{ "0060B3", "Z-COM, INC." },
{ "006089", "XATA" },
{ "00603C", "HAGIWARA SYS-COM CO., LTD." },
{ "00602E", "CYCLADES CORPORATION" },
{ "006075", "PENTEK, INC." },
{ "00601C", "TELXON CORPORATION" },
{ "006016", "CLARIION" },
{ "0060AD", "MegaChips Corporation" },
{ "0060B6", "LAND COMPUTER CO., LTD." },
{ "006055", "CORNELL UNIVERSITY" },
{ "006015", "NET2NET CORPORATION" },
{ "00A01D", "Red Lion Controls, LP" },
{ "00A071", "VIDEO LOTTERY TECHNOLOGIES,INC" },
{ "00A052", "STANILITE ELECTRONICS PTY. LTD" },
{ "00A0EA", "ETHERCOM CORP." },
{ "00A02E", "BRAND COMMUNICATIONS, LTD." },
{ "00A0E2", "Keisokugiken Corporation" },
{ "00A0C5", "ZyXEL Communications Corporation" },
{ "00A058", "GLORY, LTD." },
{ "00E093", "ACKFIN NETWORKS" },
{ "00E0E3", "SK-ELEKTRONIK GMBH" },
{ "00E066", "ProMax Systems, Inc." },
{ "00E0DB", "ViaVideo Communications, Inc." },
{ "00E0DF", "KEYMILE GmbH" },
{ "00E00D", "RADIANT SYSTEMS" },
{ "00E008", "AMAZING CONTROLS! INC." },
{ "00E086", "Emerson Network Power, Avocent Division" },
{ "00E0E1", "G2 NETWORKS, INC." },
{ "00E042", "Pacom Systems Ltd." },
{ "00E08E", "UTSTARCOM" },
{ "00E095", "ADVANCED-VISION TECHNOLGIES CORP." },
{ "006006", "SOTEC CO., LTD" },
{ "00603D", "3CX" },
{ "006029", "CARY PERIPHERALS INC." },
{ "006043", "iDirect, INC." },
{ "0060D1", "CASCADE COMMUNICATIONS" },
{ "0060CD", "VideoServer, Inc." },
{ "006094", "IBM Corp" },
{ "0060D9", "TRANSYS NETWORKS INC." },
{ "0060AA", "INTELLIGENT DEVICES INC. (IDI)" },
{ "00605A", "CELCORE, INC." },
{ "006065", "BERNECKER & RAINER INDUSTRIE-ELEKTRONIC GmbH" },
{ "00E07B", "BAY NETWORKS" },
{ "00E077", "WEBGEAR, INC." },
{ "00E0D2", "VERSANET COMMUNICATIONS, INC." },
{ "00E04E", "SANYO DENKI CO., LTD." },
{ "00E0DD", "ZENITH ELECTRONICS CORPORATION" },
{ "00E0D0", "NETSPEED, INC." },
{ "00E02A", "TANDBERG TELEVISION AS" },
{ "00E05B", "WEST END SYSTEMS CORP." },
{ "00E051", "TALX CORPORATION" },
{ "00A0F0", "TORONTO MICROELECTRONICS INC." },
{ "00A049", "DIGITECH INDUSTRIES, INC." },
{ "00A027", "FIREPOWER SYSTEMS, INC." },
{ "00A0FF", "TELLABS OPERATIONS, INC." },
{ "00A001", "DRS Signal Solutions" },
{ "00A0F1", "MTI" },
{ "00A046", "SCITEX CORP. LTD." },
{ "00A0D9", "CONVEX COMPUTER CORPORATION" },
{ "00A0B5", "3H TECHNOLOGY" },
{ "00A0AC", "GILAT SATELLITE NETWORKS, LTD." },
{ "00A057", "LANCOM Systems GmbH" },
{ "00A086", "AMBER WAVE SYSTEMS, INC." },
{ "00A083", "ASIMMPHONY TURKEY" },
{ "00A091", "APPLICOM INTERNATIONAL" },
{ "00A004", "NETPOWER, INC." },
{ "00A081", "ALCATEL DATA NETWORKS" },
{ "00A0D5", "SIERRA WIRELESS INC." },
{ "00200F", "EBRAINS Inc" },
{ "0020C7", "AKAI Professional M.I. Corp." },
{ "0020EB", "CINCINNATI MICROWAVE, INC." },
{ "0020E3", "MCD KENCOM CORPORATION" },
{ "002013", "DIVERSIFIED TECHNOLOGY, INC." },
{ "0020C1", "SAXA, Inc." },
{ "002087", "MEMOTEC, INC." },
{ "0020F9", "PARALINK NETWORKS, INC." },
{ "00A0F9", "BINTEC COMMUNICATIONS GMBH" },
{ "00A0BC", "VIASAT, INCORPORATED" },
{ "00A003", "Siemens Switzerland Ltd., I B T HVP" },
{ "00A09E", "ICTV" },
{ "00A026", "TELDAT, S.A." },
{ "00201A", "MRV Communications, Inc." },
{ "002023", "T.C. TECHNOLOGIES PTY. LTD" },
{ "0020F3", "RAYNET CORPORATION" },
{ "002039", "SCINETS" },
{ "002038", "VME MICROSYSTEMS INTERNATIONAL CORPORATION" },
{ "00203E", "LogiCan Technologies, Inc." },
{ "002055", "ALTECH CO., LTD." },
{ "0020D9", "PANASONIC TECHNOLOGIES, INC./MIECO-US" },
{ "002080", "SYNERGY (UK) LTD." },
{ "002026", "AMKLY SYSTEMS, INC." },
{ "00203D", "Honeywell ECC" },
{ "002019", "OHLER GMBH" },
{ "002057", "TITZE DATENTECHNIK GmbH" },
{ "0020BE", "LAN ACCESS CORP." },
{ "002022", "NMS Communications" },
{ "0020AA", "Ericsson Television Limited" },
{ "00208E", "CHEVIN SOFTWARE ENG. LTD." },
{ "00203B", "WISDM LTD." },
{ "002044", "GENITECH PTY LTD" },
{ "0020F5", "PANDATEL AG" },
{ "002021", "ALGORITHMS SOFTWARE PVT. LTD." },
{ "002074", "SUNGWOON SYSTEMS" },
{ "0020CE", "LOGICAL DESIGN GROUP, INC." },
{ "002082", "ONEAC CORPORATION" },
{ "0020BF", "AEHR TEST SYSTEMS" },
{ "0020F1", "ALTOS INDIA LIMITED" },
{ "00205D", "NANOMATIC OY" },
{ "0020E1", "ALAMAR ELECTRONICS" },
{ "0020CC", "DIGITAL SERVICES, LTD." },
{ "00202C", "WELLTRONIX CO., LTD." },
{ "0020B3", "Tattile SRL " },
{ "00A048", "QUESTECH, LTD." },
{ "00A0C4", "CRISTIE ELECTRONICS LTD." },
{ "00A089", "XPOINT TECHNOLOGIES, INC." },
{ "00A0D1", "INVENTEC CORPORATION" },
{ "00A0AE", "NUCOM SYSTEMS, INC." },
{ "00A02B", "TRANSITIONS RESEARCH CORP." },
{ "00A0A1", "EPIC DATA INC." },
{ "00A0C3", "UNICOMPUTER GMBH" },
{ "00A042", "SPUR PRODUCTS CORP." },
{ "00C007", "PINNACLE DATA SYSTEMS, INC." },
{ "00C0F8", "ABOUT COMPUTING INC." },
{ "00C06F", "KOMATSU LTD." },
{ "00C08E", "NETWORK INFORMATION TECHNOLOGY" },
{ "00C05A", "SEMAPHORE COMMUNICATIONS CORP." },
{ "00C0EB", "SEH COMPUTERTECHNIK GMBH" },
{ "00C0C7", "SPARKTRUM MICROSYSTEMS, INC." },
{ "00C0D8", "UNIVERSAL DATA SYSTEMS" },
{ "00C068", "HME Clear-Com LTD." },
{ "0040DB", "ADVANCED TECHNICAL SOLUTIONS" },
{ "00405B", "FUNASSET LIMITED" },
{ "00401B", "PRINTER SYSTEMS CORP." },
{ "0040EB", "MARTIN MARIETTA CORPORATION" },
{ "0040CD", "TERA MICROSYSTEMS, INC." },
{ "0040E5", "SYBUS CORPORATION" },
{ "0040F9", "COMBINET" },
{ "004039", "OPTEC DAIICHI DENKO CO., LTD." },
{ "0040FE", "SYMPLEX COMMUNICATIONS" },
{ "0020F0", "UNIVERSAL MICROELECTRONICS CO." },
{ "0020EF", "USC CORPORATION" },
{ "002016", "SHOWA ELECTRIC WIRE & CABLE CO" },
{ "00201F", "BEST POWER TECHNOLOGY, INC." },
{ "002045", "ION Networks, Inc." },
{ "0020B6", "AGILE NETWORKS, INC." },
{ "00208A", "SONIX COMMUNICATIONS, LTD." },
{ "00204C", "MITRON COMPUTER PTE LTD." },
{ "002002", "SERITECH ENTERPRISE CO., LTD." },
{ "00204B", "AUTOCOMPUTER CO., LTD." },
{ "0020AF", "3COM CORPORATION" },
{ "002048", "Marconi Communications" },
{ "002008", "CABLE & COMPUTER TECHNOLOGY" },
{ "00C023", "TUTANKHAMON ELECTRONICS" },
{ "00C0F3", "NETWORK COMMUNICATIONS CORP." },
{ "00C043", "STRATACOM" },
{ "00C0B3", "COMSTAT DATACOMM CORPORATION" },
{ "00C0B5", "CORPORATE NETWORK SYSTEMS,INC." },
{ "00403E", "RASTER OPS CORPORATION" },
{ "0040AE", "DELTA CONTROLS, INC." },
{ "0040C6", "FIBERNET RESEARCH, INC." },
{ "004092", "ASP COMPUTER PRODUCTS, INC." },
{ "004054", "CONNECTION MACHINES SERVICES" },
{ "0040D8", "OCEAN OFFICE AUTOMATION LTD." },
{ "0040C0", "VISTA CONTROLS CORPORATION" },
{ "004088", "MOBIUS TECHNOLOGIES, INC." },
{ "00803B", "APT COMMUNICATIONS, INC." },
{ "0080BA", "SPECIALIX (ASIA) PTE, LTD" },
{ "00BB01", "OCTOTHORPE CORP." },
{ "00C01F", "S.E.R.C.E.L." },
{ "00C094", "VMX INC." },
{ "00C075", "XANTE CORPORATION" },
{ "00C0F9", "Artesyn Embedded Technologies" },
{ "00C039", "Teridian Semiconductor Corporation" },
{ "00C077", "DAEWOO TELECOM LTD." },
{ "00C02F", "OKUMA CORPORATION" },
{ "00C0F1", "SHINKO ELECTRIC CO., LTD." },
{ "00C0DE", "ZCOMM, INC." },
{ "0040AF", "DIGITAL PRODUCTS, INC." },
{ "00404F", "SPACE & NAVAL WARFARE SYSTEMS" },
{ "00407B", "SCIENTIFIC ATLANTA" },
{ "00404E", "FLUENT, INC." },
{ "00C0F7", "ENGAGE COMMUNICATION, INC." },
{ "00C030", "INTEGRATED ENGINEERING B. V." },
{ "00C04A", "GROUP 2000 AG" },
{ "00C0A6", "EXICOM AUSTRALIA PTY. LTD" },
{ "00C053", "Aspect Software Inc." },
{ "00C0CF", "IMATRAN VOIMA OY" },
{ "00C029", "Nexans Deutschland GmbH - ANS" },
{ "00C0A4", "UNIGRAF OY" },
{ "00C060", "ID SCANDINAVIA AS" },
{ "00C082", "MOORE PRODUCTS CO." },
{ "00C008", "SECO SRL" },
{ "00C0BB", "FORVAL CREATIVE, INC." },
{ "00C0E0", "DSC COMMUNICATION CORP." },
{ "00C05E", "VARI-LITE, INC." },
{ "00C031", "DESIGN RESEARCH SYSTEMS, INC." },
{ "00C07C", "HIGHTECH INFORMATION" },
{ "00C0AE", "TOWERCOM CO. INC. DBA PC HOUSE" },
{ "00C0D6", "J1 SYSTEMS, INC." },
{ "00C0AA", "SILICON VALLEY COMPUTER" },
{ "00C04E", "COMTROL CORPORATION" },
{ "00C00A", "MICRO CRAFT" },
{ "00C02A", "OHKURA ELECTRIC CO., LTD." },
{ "00C0F2", "TRANSITION NETWORKS" },
{ "00C01D", "GRAND JUNCTION NETWORKS, INC." },
{ "00C0AD", "MARBEN COMMUNICATION SYSTEMS" },
{ "00C024", "EDEN SISTEMAS DE COMPUTACAO SA" },
{ "00C0E9", "OAK SOLUTIONS, LTD." },
{ "00C0C5", "SID INFORMATICA" },
{ "00C001", "DIATEK PATIENT MANAGMENT" },
{ "00C07E", "KUBOTA CORPORATION ELECTRONIC" },
{ "008012", "INTEGRATED MEASUREMENT SYSTEMS" },
{ "008039", "ALCATEL STC AUSTRALIA" },
{ "008023", "INTEGRATED BUSINESS NETWORKS" },
{ "0080CA", "NETCOM RESEARCH INCORPORATED" },
{ "00804D", "CYCLONE MICROSYSTEMS, INC." },
{ "0080D6", "NUVOTECH, INC." },
{ "0080ED", "IQ TECHNOLOGIES, INC." },
{ "0080C1", "LANEX CORPORATION" },
{ "008049", "NISSIN ELECTRIC CO., LTD." },
{ "00807C", "FIBERCOM, INC." },
{ "008079", "MICROBUS DESIGNS LTD." },
{ "0080DE", "GIPSI S.A." },
{ "008004", "ANTLOW COMMUNICATIONS, LTD." },
{ "008078", "PRACTICAL PERIPHERALS, INC." },
{ "008040", "JOHN FLUKE MANUFACTURING CO." },
{ "0000F8", "DIGITAL EQUIPMENT CORPORATION" },
{ "0080CE", "BROADCAST TELEVISION SYSTEMS" },
{ "00801A", "BELL ATLANTIC" },
{ "00803F", "TATUNG COMPANY" },
{ "0080D4", "CHASE RESEARCH LTD." },
{ "0080CB", "FALCO DATA PRODUCTS" },
{ "008075", "PARSYTEC GMBH" },
{ "0080EB", "COMPCONTROL B.V." },
{ "008099", "Eaton Industries GmbH" },
{ "0080E4", "NORTHWEST DIGITAL SYSTEMS, INC" },
{ "008041", "VEB KOMBINAT ROBOTRON" },
{ "0080C8", "D-LINK SYSTEMS, INC." },
{ "008036", "REFLEX MANUFACTURING SYSTEMS" },
{ "0040F0", "MicroBrain,Inc." },
{ "0040A7", "ITAUTEC PHILCO S.A." },
{ "0040D3", "KIMPSION INTERNATIONAL CORP." },
{ "004065", "GTE SPACENET" },
{ "0040CB", "LANWAN TECHNOLOGIES" },
{ "004041", "FUJIKURA LTD." },
{ "004053", "AMPRO COMPUTERS" },
{ "008032", "ACCESS CO., LTD." },
{ "0080CF", "EMBEDDED PERFORMANCE INC." },
{ "008031", "BASYS, CORP." },
{ "00803A", "VARITYPER, INC." },
{ "00807E", "SOUTHERN PACIFIC LTD." },
{ "008029", "EAGLE TECHNOLOGY, INC." },
{ "00802F", "NATIONAL INSTRUMENTS CORP." },
{ "008051", "FIBERMUX" },
{ "0080FD", "EXSCEED CORPRATION" },
{ "004008", "A PLUS INFO CORPORATION" },
{ "0040E9", "ACCORD SYSTEMS, INC." },
{ "0040B5", "VIDEO TECHNOLOGY COMPUTERS LTD" },
{ "004012", "WINDATA, INC." },
{ "00401C", "AST RESEARCH, INC." },
{ "004067", "OMNIBYTE CORPORATION" },
{ "004035", "OPCOM" },
{ "0040EA", "PLAIN TREE SYSTEMS INC" },
{ "0040EF", "HYPERCOM, INC." },
{ "004093", "PAXDATA NETWORKS LTD." },
{ "0040EC", "MIKASA SYSTEM ENGINEERING" },
{ "0080B9", "ARCHE TECHNOLIGIES INC." },
{ "0080A7", "Honeywell International Inc" },
{ "0040DA", "TELSPEC LTD" },
{ "004083", "TDA INDUSTRIA DE PRODUTOS" },
{ "0040C8", "MILAN TECHNOLOGY CORPORATION" },
{ "0040BC", "ALGORITHMICS LTD." },
{ "00402F", "XLNT DESIGNS INC." },
{ "00405D", "STAR-TEK, INC." },
{ "00405F", "AFE COMPUTERS LTD." },
{ "004043", "Nokia Siemens Networks GmbH & Co. KG." },
{ "00800D", "VOSSWINKEL F.U." },
{ "0080D1", "KIMTRON CORPORATION" },
{ "00805D", "CANSTAR" },
{ "008094", "ALFA LAVAL AUTOMATION AB" },
{ "008047", "IN-NET CORP." },
{ "008064", "WYSE TECHNOLOGY LLC" },
{ "0080C5", "NOVELLCO DE MEXICO" },
{ "0080AC", "IMLOGIX, DIVISION OF GENESYS" },
{ "00808C", "NetScout Systems, Inc." },
{ "000052", "Intrusion.com, Inc." },
{ "0000BD", "MITSUBISHI CABLE COMPANY" },
{ "000037", "OXFORD METRICS LIMITED" },
{ "00003F", "SYNTREX, INC." },
{ "08007C", "VITALINK COMMUNICATIONS CORP." },
{ "080076", "PC LAN TECHNOLOGIES" },
{ "080072", "XEROX CORP UNIV GRANT PROGRAM" },
{ "080070", "MITSUBISHI ELECTRIC CORP." },
{ "080068", "RIDGE COMPUTERS" },
{ "080062", "General Dynamics" },
{ "080057", "Evans & Sutherland" },
{ "000010", "SYTEK INC." },
{ "000033", "EGAN MACHINERY COMPANY" },
{ "000080", "CRAY COMMUNICATIONS A/S" },
{ "0000FD", "HIGH LEVEL HARDWARE" },
{ "08008C", "NETWORK RESEARCH CORPORATION" },
{ "080089", "Kinetics" },
{ "080087", "XYPLEX" },
{ "080084", "TOMEN ELECTRONICS CORP." },
{ "00000D", "FIBRONICS LTD." },
{ "00004F", "LOGICRAFT, INC." },
{ "000015", "DATAPOINT CORPORATION" },
{ "0000C7", "ARIX CORPORATION" },
{ "00001C", "BELL TECHNOLOGIES" },
{ "00001A", "ADVANCED MICRO DEVICES" },
{ "000082", "LECTRA SYSTEMES SA" },
{ "0000DA", "ATEX" },
{ "0000DB", "British Telecommunications plc" },
{ "0000C1", "Madge Ltd." },
{ "0000F6", "APPLIED MICROSYSTEMS CORP." },
{ "080023", "Panasonic Communications Co., Ltd." },
{ "080022", "NBI INC." },
{ "080019", "GENERAL ELECTRIC CORPORATION" },
{ "08004D", "CORVUS SYSTEMS INC." },
{ "08003E", "CODEX CORPORATION" },
{ "080033", "BAUSCH & LOMB" },
{ "08002F", "PRIME COMPUTER INC." },
{ "080032", "TIGAN INCORPORATED" },
{ "08002E", "METAPHOR COMPUTER SYSTEMS" },
{ "0000D2", "SBE, INC." },
{ "00006B", "SILICON GRAPHICS INC./MIPS" },
{ "0000CC", "DENSAN CO., LTD." },
{ "0000CE", "MEGADATA CORP." },
{ "0000EF", "KTI" },
{ "00000F", "NEXT, INC." },
{ "0000C6", "EON SYSTEMS" },
{ "0000D5", "MICROGNOSIS INTERNATIONAL" },
{ "000078", "LABTAM LIMITED" },
{ "0000EB", "MATSUSHITA COMM. IND. CO. LTD." },
{ "00009C", "ROLM MIL-SPEC COMPUTERS" },
{ "000032", "Marconi plc" },
{ "000069", "CONCORD COMMUNICATIONS INC" },
{ "00008B", "INFOTRON" },
{ "0000BE", "THE NTI GROUP" },
{ "00004C", "NEC CORPORATION" },
{ "00003B", "i Controls, Inc." },
{ "0000FE", "ANNAPOLIS MICRO SYSTEMS" },
{ "080013", "Exxon" },
{ "02BB01", "OCTOTHORPE CORP." },
{ "0000A6", "NETWORK GENERAL CORPORATION" },
{ "00DD06", "UNGERMANN-BASS INC." },
{ "00DD0B", "UNGERMANN-BASS INC." },
{ "000007", "XEROX CORPORATION" },
{ "080014", "EXCELAN" },
{ "08000F", "MITEL CORPORATION" },
{ "0000D7", "DARTMOUTH COLLEGE" },
{ "00DD00", "UNGERMANN-BASS INC." },
{ "08000A", "NESTAR SYSTEMS INCORPORATED" },
{ "08001C", "KDD-KOKUSAI DEBNSIN DENWA CO." },
{ "02AA3C", "OLIVETTI TELECOMM SPA (OLTECO)" },
{ "08001D", "ABLE COMMUNICATIONS INC." },
{ "080018", "PIRELLI FOCOM NETWORKS" },
{ "080015", "STC BUSINESS SYSTEMS" },
{ "00DD03", "UNGERMANN-BASS INC." },
{ "00801F", "KRUPP ATLAS ELECTRONIK GMBH" },
{ "00408E", "Tattile SRL " },
{ "00800F", "STANDARD MICROSYSTEMS" },
{ "080065", "GENRAD INC." },
{ "002275", "Belkin International Inc." },
{ "149182", "Belkin International Inc." },
{ "70106F", "Hewlett Packard Enterprise" },
{ "988B5D", "Sagemcom Broadband SAS" },
{ "94FEF4", "Sagemcom Broadband SAS" },
{ "C8CD72", "Sagemcom Broadband SAS" },
{ "E8BE81", "Sagemcom Broadband SAS" },
{ "28FAA0", "vivo Mobile Communication Co., Ltd." },
{ "3CA348", "vivo Mobile Communication Co., Ltd." },
{ "F42981", "vivo Mobile Communication Co., Ltd." },
{ "C4282D", "Embedded Intellect Pty Ltd" },
{ "002348", "Sagemcom Broadband SAS" },
{ "B870F4", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "000FB0", "COMPAL ELECTRONICS, INC." },
{ "1C7508", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "8C0EE3", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "A44F29", "IEEE Registration Authority" },
{ "800A80", "IEEE Registration Authority" },
{ "141FBA", "IEEE Registration Authority" },
{ "A0BB3E", "IEEE Registration Authority" },
{ "884AEA", "Texas Instruments" },
{ "3829DD", "ONvocal Inc" },
{ "F81897", "2Wire Inc" },
{ "ECF4BB", "Dell Inc." },
{ "D067E5", "Dell Inc." },
{ "18A99B", "Dell Inc." },
{ "F8DB88", "Dell Inc." },
{ "18FB7B", "Dell Inc." },
{ "001495", "2Wire Inc" },
{ "74E6E2", "Dell Inc." },
{ "109836", "Dell Inc." },
{ "44A842", "Dell Inc." },
{ "34E6D7", "Dell Inc." },
{ "000BDB", "Dell Inc." },
{ "001143", "Dell Inc." },
{ "00188B", "Dell Inc." },
{ "D4BED9", "Dell Inc." },
{ "002650", "2Wire Inc" },
{ "00217C", "2Wire Inc" },
{ "001FB3", "2Wire Inc" },
{ "640F28", "2Wire Inc" },
{ "001AA0", "Dell Inc." },
{ "002170", "Dell Inc." },
{ "0026B9", "Dell Inc." },
{ "A4BADB", "Dell Inc." },
{ "001E4F", "Dell Inc." },
{ "5CF9DD", "Dell Inc." },
{ "907AF1", "Wally" },
{ "28101B", "MagnaCom" },
{ "00065B", "Dell Inc." },
{ "448723", "HOYA SERVICE CORPORATION" },
{ "806C1B", "Motorola Mobility LLC, a Lenovo Company" },
{ "A470D6", "Motorola Mobility LLC, a Lenovo Company" },
{ "3407FB", "Ericsson AB" },
{ "001B21", "Intel Corporate" },
{ "001B77", "Intel Corporate" },
{ "18FF0F", "Intel Corporate" },
{ "58A839", "Intel Corporate" },
{ "A434D9", "Intel Corporate" },
{ "00215D", "Intel Corporate" },
{ "001676", "Intel Corporate" },
{ "984FEE", "Intel Corporate" },
{ "E82AEA", "Intel Corporate" },
{ "605718", "Intel Corporate" },
{ "C4D987", "Intel Corporate" },
{ "B4B676", "Intel Corporate" },
{ "8C705A", "Intel Corporate" },
{ "9C4E36", "Intel Corporate" },
{ "541473", "Wingtech Group (HongKong）Limited" },
{ "14144B", "FUJIAN STAR-NET COMMUNICATION CO.,LTD" },
{ "001C50", "TCL Technoly Electronics (Huizhou) Co., Ltd." },
{ "00AA01", "Intel Corporation" },
{ "5C36B8", "TCL King Electrical Appliances (Huizhou) Co., Ltd" },
{ "009027", "Intel Corporation" },
{ "A08869", "Intel Corporate" },
{ "00C2C6", "Intel Corporate" },
{ "B88A60", "Intel Corporate" },
{ "00A0C9", "Intel Corporation" },
{ "7C7A91", "Intel Corporate" },
{ "AC7BA1", "Intel Corporate" },
{ "AC7289", "Intel Corporate" },
{ "606C66", "Intel Corporate" },
{ "4C8093", "Intel Corporate" },
{ "BC7737", "Intel Corporate" },
{ "A088B4", "Intel Corporate" },
{ "00270E", "Intel Corporate" },
{ "001DE0", "Intel Corporate" },
{ "0024D6", "Intel Corporate" },
{ "D8FC93", "Intel Corporate" },
{ "E8B1FC", "Intel Corporate" },
{ "186472", "Aruba Networks" },
{ "00246C", "Aruba Networks" },
{ "64D954", "Taicang T&W Electronics" },
{ "74C63B", "AzureWave Technology Inc." },
{ "CC1FC4", "InVue" },
{ "A0D37A", "Intel Corporate" },
{ "985FD3", "Microsoft Corporation" },
{ "00D0AC", "Commscope, Inc" },
{ "0025D3", "AzureWave Technology Inc." },
{ "742F68", "AzureWave Technology Inc." },
{ "DC85DE", "AzureWave Technology Inc." },
{ "E0B9A5", "AzureWave Technology Inc." },
{ "E04136", "MitraStar Technology Corp." },
{ "E0B2F1", "FN-LINK TECHNOLOGY LIMITED" },
{ "0026FC", "AcSiP Technology Corp." },
{ "B8616F", "Accton Technology Corp" },
{ "0010B5", "Accton Technology Corp" },
{ "00A02F", "ADB Broadband Italia" },
{ "6487D7", "ADB Broadband Italia" },
{ "00E098", "AboCom" },
{ "F0A225", "Private" },
{ "0000B1", "Alpha Micro" },
{ "001577", "Allied Telesis, Inc." },
{ "ACE010", "Liteon Technology Corporation" },
{ "EC086B", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "00159A", "ARRIS Group, Inc." },
{ "00192C", "ARRIS Group, Inc." },
{ "2421AB", "Sony Mobile Communications AB" },
{ "6C23B9", "Sony Mobile Communications AB" },
{ "58170C", "Sony Mobile Communications AB" },
{ "B8F934", "Sony Mobile Communications AB" },
{ "205476", "Sony Mobile Communications AB" },
{ "303926", "Sony Mobile Communications AB" },
{ "00EB2D", "Sony Mobile Communications AB" },
{ "B00594", "Liteon Technology Corporation" },
{ "40F02F", "Liteon Technology Corporation" },
{ "E8617E", "Liteon Technology Corporation" },
{ "28E347", "Liteon Technology Corporation" },
{ "18CF5E", "Liteon Technology Corporation" },
{ "D0DF9A", "Liteon Technology Corporation" },
{ "90B134", "ARRIS Group, Inc." },
{ "3C438E", "ARRIS Group, Inc." },
{ "E86D52", "ARRIS Group, Inc." },
{ "0015D0", "ARRIS Group, Inc." },
{ "0013A9", "Sony Corporation" },
{ "00219E", "Sony Mobile Communications AB" },
{ "001E45", "Sony Mobile Communications AB" },
{ "001813", "Sony Mobile Communications AB" },
{ "00080E", "ARRIS Group, Inc." },
{ "0050E3", "ARRIS Group, Inc." },
{ "94CCB9", "ARRIS Group, Inc." },
{ "40B7F3", "ARRIS Group, Inc." },
{ "20E564", "ARRIS Group, Inc." },
{ "F87B7A", "ARRIS Group, Inc." },
{ "0023A3", "ARRIS Group, Inc." },
{ "64ED57", "ARRIS Group, Inc." },
{ "0023EE", "ARRIS Group, Inc." },
{ "002143", "ARRIS Group, Inc." },
{ "5856E8", "ARRIS Group, Inc." },
{ "0025F1", "ARRIS Group, Inc." },
{ "0023AF", "ARRIS Group, Inc." },
{ "001ADE", "ARRIS Group, Inc." },
{ "001E46", "ARRIS Group, Inc." },
{ "0018C0", "ARRIS Group, Inc." },
{ "001A66", "ARRIS Group, Inc." },
{ "002163", "ASKEY COMPUTER CORP" },
{ "E839DF", "ASKEY COMPUTER CORP" },
{ "00138F", "Asiarock Technology Limited" },
{ "2CB05D", "NETGEAR" },
{ "00146C", "NETGEAR" },
{ "1C69A5", "BlackBerry RTS" },
{ "003067", "BIOSTAR Microtech Int'l Corp." },
{ "246511", "AVM GmbH" },
{ "002308", "Arcadyan Technology Corporation" },
{ "880355", "Arcadyan Technology Corporation" },
{ "A42B8C", "NETGEAR" },
{ "04A151", "NETGEAR" },
{ "28C68E", "NETGEAR" },
{ "5CDC96", "Arcadyan Technology Corporation" },
{ "504A6E", "NETGEAR" },
{ "D0D04B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001D00", "Brivo Systems, LLC" },
{ "0010E7", "Breezecom, Ltd." },
{ "5C9656", "AzureWave Technology Inc." },
{ "0881F4", "Juniper Networks" },
{ "A8D0E5", "Juniper Networks" },
{ "648788", "Juniper Networks" },
{ "28C0DA", "Juniper Networks" },
{ "80711F", "Juniper Networks" },
{ "00239C", "Juniper Networks" },
{ "001DB5", "Juniper Networks" },
{ "7C4CA5", "BSkyB Ltd" },
{ "902106", "BSkyB Ltd" },
{ "A4C7DE", "Cambridge Industries(Group) Co.,Ltd." },
{ "343759", "zte corporation" },
{ "00402A", "Canoga Perkins Corporation" },
{ "382DE8", "Samsung Electronics Co.,Ltd" },
{ "D087E2", "Samsung Electronics Co.,Ltd" },
{ "205531", "Samsung Electronics Co.,Ltd" },
{ "5440AD", "Samsung Electronics Co.,Ltd" },
{ "842E27", "Samsung Electronics Co.,Ltd" },
{ "50F0D3", "Samsung Electronics Co.,Ltd" },
{ "84119E", "Samsung Electronics Co.,Ltd" },
{ "08ECA9", "Samsung Electronics Co.,Ltd" },
{ "10D38A", "Samsung Electronics Co.,Ltd" },
{ "382DD1", "Samsung Electronics Co.,Ltd" },
{ "E0CBEE", "Samsung Electronics Co.,Ltd" },
{ "64B853", "Samsung Electronics Co.,Ltd" },
{ "988389", "Samsung Electronics Co.,Ltd" },
{ "244B03", "Samsung Electronics Co.,Ltd" },
{ "FC8F90", "Samsung Electronics Co.,Ltd" },
{ "1816C9", "Samsung Electronics Co.,Ltd" },
{ "F4428F", "Samsung Electronics Co.,Ltd" },
{ "188331", "Samsung Electronics Co.,Ltd" },
{ "8455A5", "Samsung Electronics Co.,Ltd" },
{ "A87C01", "Samsung Electronics Co.,Ltd" },
{ "C01173", "Samsung Electronics Co.,Ltd" },
{ "BCE63F", "Samsung Electronics Co.,Ltd" },
{ "B857D8", "Samsung Electronics Co.,Ltd" },
{ "94B10A", "Samsung Electronics Co.,Ltd" },
{ "E458B8", "Samsung Electronics Co.,Ltd" },
{ "088C2C", "Samsung Electronics Co.,Ltd" },
{ "B86CE8", "Samsung Electronics Co.,Ltd" },
{ "9C65B0", "Samsung Electronics Co.,Ltd" },
{ "C8A823", "Samsung Electronics Co.,Ltd" },
{ "C44202", "Samsung Electronics Co.,Ltd" },
{ "D059E4", "Samsung Electronics Co.,Ltd" },
{ "64B310", "Samsung Electronics Co.,Ltd" },
{ "78ABBB", "Samsung Electronics Co.,Ltd" },
{ "000B3B", "devolo AG" },
{ "001D20", "Comtrend Corporation" },
{ "6C38A1", "Ubee Interactive Corp." },
{ "140C76", "FREEBOX SAS" },
{ "0024D4", "FREEBOX SAS" },
{ "A089E4", "Skyworth Digital Technology(Shenzhen) Co.,Ltd" },
{ "001A9A", "Skyworth Digital Technology(Shenzhen) Co.,Ltd" },
{ "AC3A7A", "Roku, Inc." },
{ "CC6DA0", "Roku, Inc." },
{ "000D4B", "Roku, Inc." },
{ "001999", "Fujitsu Technology Solutions GmbH" },
{ "0009E1", "Gemtek Technology Co., Ltd." },
{ "C477AB", "Beijing ASU Tech Co.,Ltd" },
{ "182A7B", "Nintendo Co., Ltd." },
{ "0024F3", "Nintendo Co., Ltd." },
{ "A45C27", "Nintendo Co., Ltd." },
{ "001DBC", "Nintendo Co., Ltd." },
{ "001F32", "Nintendo Co., Ltd." },
{ "D8FB5E", "ASKEY COMPUTER CORP" },
{ "544408", "Nokia Corporation" },
{ "0017B0", "Nokia Danmark A/S" },
{ "001BEE", "Nokia Danmark A/S" },
{ "1886AC", "Nokia Danmark A/S" },
{ "0021FE", "Nokia Danmark A/S" },
{ "002266", "Nokia Danmark A/S" },
{ "DCB3B4", "Honeywell Environmental & Combustion Controls (Tianjin) Co., Ltd." },
{ "C8D10B", "Nokia Corporation" },
{ "C8979F", "Nokia Corporation" },
{ "F4F5A5", "Nokia Corporation" },
{ "3CC243", "Nokia Corporation" },
{ "0015A0", "Nokia Danmark A/S" },
{ "001A16", "Nokia Danmark A/S" },
{ "0022FC", "Nokia Danmark A/S" },
{ "002548", "Nokia Danmark A/S" },
{ "001DFD", "Nokia Danmark A/S" },
{ "001EA3", "Nokia Danmark A/S" },
{ "001D98", "Nokia Danmark A/S" },
{ "00119F", "Nokia Danmark A/S" },
{ "18A6F7", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "246968", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "8CA2FD", "Starry, Inc." },
{ "14BB6E", "Samsung Electronics Co.,Ltd" },
{ "AC61EA", "Apple, Inc." },
{ "38B54D", "Apple, Inc." },
{ "90A62F", "NAVER" },
{ "F4ED5F", "SHENZHEN KTC TECHNOLOGY GROUP " },
{ "9476B7", "Samsung Electronics Co.,Ltd" },
{ "8C1ABF", "Samsung Electronics Co.,Ltd" },
{ "B47443", "Samsung Electronics Co.,Ltd" },
{ "000BA2", "Sumitomo Electric Industries,Ltd" },
{ "30CBF8", "Samsung Electronics Co.,Ltd" },
{ "2C4D79", "GoerTek Inc." },
{ "40D357", "Ison Technology Co., Ltd." },
{ "A4F1E8", "Apple, Inc." },
{ "F03404", "TCT mobile ltd" },
{ "FC0FE6", "Sony Computer Entertainment Inc." },
{ "709E29", "Sony Computer Entertainment Inc." },
{ "AC9B0A", "Sony Computer Entertainment Inc." },
{ "00351A", "Cisco Systems, Inc" },
{ "00A0B8", "NetApp" },
{ "9CD48B", "Innolux Technology Europe BV" },
{ "545AA6", "Espressif Inc." },
{ "DCE838", "CK Telecom (Shenzhen) Limited" },
{ "B0754D", "Alcatel-Lucent" },
{ "BC8D0E", "Alcatel-Lucent" },
{ "E48184", "Alcatel-Lucent" },
{ "94E98C", "Alcatel-Lucent" },
{ "84262B", "Alcatel-Lucent" },
{ "98B039", "Alcatel-Lucent" },
{ "A47B2C", "Alcatel-Lucent" },
{ "BC6B4D", "Alcatel-Lucent" },
{ "00CCFC", "Cisco Systems, Inc" },
{ "2C9662", "Invenit BV" },
{ "DC2DCB", "Beijing Unis HengYue Technology Co., Ltd." },
{ "5CF286", "IEEE Registration Authority" },
{ "3810D5", "AVM Audiovisuelles Marketing und Computersysteme GmbH" },
{ "44AAF5", "Pace plc" },
{ "1C5F2B", "D-Link International" },
{ "D8803C", "Anhui Huami Information Technology Company Limited" },
{ "001FA7", "Sony Computer Entertainment Inc." },
{ "001315", "Sony Computer Entertainment Inc." },
{ "A8E3EE", "Sony Computer Entertainment Inc." },
{ "703C03", "RadiAnt Co.,Ltd" },
{ "F0D2F1", "Amazon Technologies Inc." },
{ "583277", "Reliance Communications LLC" },
{ "CCD3E2", "Jiangsu Yinhe  Electronics Co.,Ltd." },
{ "182195", "Samsung Electronics Co.,Ltd" },
{ "A88195", "Samsung Electronics Co.,Ltd" },
{ "88ADD2", "Samsung Electronics Co.,Ltd" },
{ "008E73", "Cisco Systems, Inc" },
{ "B805AB", "zte corporation" },
{ "9C52F8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "900325", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "DC094C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "DCEE06", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "AC44F2", "YAMAHA CORPORATION" },
{ "508965", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "808C97", "Kaonmedia CO., LTD." },
{ "30B49E", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "349971", "Quanta Storage Inc." },
{ "24615A", "China Mobile Group Device Co.,Ltd." },
{ "B0E2E5", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "AC0D1B", "LG Electronics (Mobile Communications)" },
{ "A0043E", "Parker Hannifin Manufacturing Germany GmbH & Co. KG" },
{ "5CC7D7", "AZROAD TECHNOLOGY COMPANY LIMITED" },
{ "001706", "Techfaithwireless Communication Technology Limited." },
{ "30F6B9", "Ecocentric Energy" },
{ "1C3ADE", "Samsung Electronics Co.,Ltd" },
{ "004268", "Cisco Systems, Inc" },
{ "00BD82", "Shenzhen YOUHUA Technology Co., Ltd" },
{ "603ECA", "Cambridge Medical Robotics Ltd" },
{ "E4A1E6", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "54489C", "CDOUBLES ELECTRONICS CO. LTD." },
{ "54BEF7", "PEGATRON CORPORATION" },
{ "0C54A5", "PEGATRON CORPORATION" },
{ "202564", "PEGATRON CORPORATION" },
{ "600292", "PEGATRON CORPORATION" },
{ "84002D", "PEGATRON CORPORATION" },
{ "8019FE", "JianLing Technology CO., LTD" },
{ "58605F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001188", "Enterasys" },
{ "1078D2", "Elitegroup Computer Systems Co.,Ltd." },
{ "001E90", "Elitegroup Computer Systems Co.,Ltd." },
{ "002465", "Elentec" },
{ "001CD7", "Harman/Becker Automotive Systems GmbH" },
{ "0016EC", "Elitegroup Computer Systems Co.,Ltd." },
{ "000D87", "Elitegroup Computer Systems Co.,Ltd." },
{ "000AE6", "Elitegroup Computer Systems Co.,Ltd." },
{ "945089", "SimonsVoss Technologies GmbH" },
{ "001F1F", "Edimax Technology Co. Ltd." },
{ "0016FA", "ECI Telecom Ltd." },
{ "003A7D", "Cisco Systems, Inc" },
{ "844076", "Drivenets" },
{ "0010E0", "Oracle Corporation " },
{ "00144F", "Oracle Corporation " },
{ "E80959", "Guoguang Electric Co.,Ltd" },
{ "541379", "Hon Hai Precision Ind. Co.,Ltd." },
{ "0C6F9C", "Shaw Communications Inc." },
{ "1801E3", "Bittium Wireless Ltd" },
{ "C0AC54", "Sagemcom Broadband SAS" },
{ "40F201", "Sagemcom Broadband SAS" },
{ "C891F9", "Sagemcom Broadband SAS" },
{ "4CFF12", "Fuze Entertainment Co., ltd" },
{ "0059AC", "KPN. B.V." },
{ "AC9A22", "NXP Semiconductors" },
{ "006037", "NXP Semiconductors" },
{ "546009", "Google, Inc." },
{ "A47733", "Google, Inc." },
{ "94EB2C", "Google, Inc." },
{ "28BC56", "EMAC, Inc." },
{ "287CDB", "Hefei  Toycloud Technology Co.,ltd" },
{ "D0B33F", "Shenzhen TINNO Mobile Technology Corp." },
{ "00738D", "Shenzhen TINNO Mobile Technology Corp." },
{ "A8CA7B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "ACCF85", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0CD746", "Apple, Inc." },
{ "440010", "Apple, Inc." },
{ "2435CC", "Zhongshan Scinan Internet of Things Co.,Ltd." },
{ "2C27D7", "Hewlett Packard" },
{ "000F3D", "D-Link Corporation" },
{ "001195", "D-Link Corporation" },
{ "0015E9", "D-Link Corporation" },
{ "0CFD37", "SUSE Linux GmbH" },
{ "2CFF65", "Oki Electric Industry Co., Ltd." },
{ "001CF0", "D-Link Corporation" },
{ "00265A", "D-Link Corporation" },
{ "ACF1DF", "D-Link International" },
{ "FC7516", "D-Link International" },
{ "E0D7BA", "Texas Instruments" },
{ "B8FFFE", "Texas Instruments" },
{ "78DEE4", "Texas Instruments" },
{ "00182F", "Texas Instruments" },
{ "001834", "Texas Instruments" },
{ "0017E3", "Texas Instruments" },
{ "0017EA", "Texas Instruments" },
{ "001783", "Texas Instruments" },
{ "7C18CD", "E-TRON Co.,Ltd." },
{ "C8665D", "Aerohive Networks Inc." },
{ "3897D6", "Hangzhou H3C Technologies Co., Limited" },
{ "C8478C", "Beken Corporation" },
{ "E498D6", "Apple, Inc." },
{ "606944", "Apple, Inc." },
{ "08952A", "Technicolor CH USA" },
{ "001977", "Aerohive Networks Inc." },
{ "4018B1", "Aerohive Networks Inc." },
{ "8896B6", "Global Fire Equipment S.A." },
{ "188796", "HTC Corporation" },
{ "945330", "Hon Hai Precision Ind. Co.,Ltd." },
{ "00242C", "Hon Hai Precision Ind. Co.,Ltd." },
{ "00242B", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D87988", "Hon Hai Precision Ind. Co.,Ltd." },
{ "AC2A0C", "CSR ZHUZHOU INSTITUTE CO.,LTD." },
{ "601971", "ARRIS Group, Inc." },
{ "F4CA24", "FreeBit Co., Ltd." },
{ "001DD1", "ARRIS Group, Inc." },
{ "001DD6", "ARRIS Group, Inc." },
{ "000A57", "Hewlett Packard" },
{ "643150", "Hewlett Packard" },
{ "002376", "HTC Corporation" },
{ "0007E9", "Intel Corporation" },
{ "B46D83", "Intel Corporate" },
{ "E4FAFD", "Intel Corporate" },
{ "DC5360", "Intel Corporate" },
{ "780CB8", "Intel Corporate" },
{ "484520", "Intel Corporate" },
{ "004026", "BUFFALO.INC" },
{ "0002A5", "Hewlett Packard" },
{ "A02BB8", "Hewlett Packard" },
{ "6CC217", "Hewlett Packard" },
{ "3863BB", "Hewlett Packard" },
{ "CC3E5F", "Hewlett Packard" },
{ "7446A0", "Hewlett Packard" },
{ "443192", "Hewlett Packard" },
{ "FC15B4", "Hewlett Packard" },
{ "EC9A74", "Hewlett Packard" },
{ "80C16E", "Hewlett Packard" },
{ "D07E28", "Hewlett Packard" },
{ "7403BD", "BUFFALO.INC" },
{ "101F74", "Hewlett Packard" },
{ "001A4B", "Hewlett Packard" },
{ "001F29", "Hewlett Packard" },
{ "00215A", "Hewlett Packard" },
{ "000F61", "Hewlett Packard" },
{ "001185", "Hewlett Packard" },
{ "001279", "Hewlett Packard" },
{ "001708", "Hewlett Packard" },
{ "306023", "ARRIS Group, Inc." },
{ "ACB313", "ARRIS Group, Inc." },
{ "14ABF0", "ARRIS Group, Inc." },
{ "0CF893", "ARRIS Group, Inc." },
{ "8461A0", "ARRIS Group, Inc." },
{ "E83381", "ARRIS Group, Inc." },
{ "44E137", "ARRIS Group, Inc." },
{ "1C1B68", "ARRIS Group, Inc." },
{ "2832C5", "HUMAX Co., Ltd." },
{ "EC4D47", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "88CF98", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "6CE3B6", "Nera Telecommunications Ltd." },
{ "8030DC", "Texas Instruments" },
{ "CC78AB", "Texas Instruments" },
{ "A4D578", "Texas Instruments" },
{ "942CB3", "HUMAX Co., Ltd." },
{ "0452F3", "Apple, Inc." },
{ "241EEB", "Apple, Inc." },
{ "F431C3", "Apple, Inc." },
{ "C4F57C", "Brocade Communications Systems, Inc." },
{ "8C7CFF", "Brocade Communications Systems, Inc." },
{ "000CDB", "Brocade Communications Systems, Inc." },
{ "006069", "Brocade Communications Systems, Inc." },
{ "C87B5B", "zte corporation" },
{ "98F537", "zte corporation" },
{ "001E73", "zte corporation" },
{ "0019C6", "zte corporation" },
{ "0015EB", "zte corporation" },
{ "A051C6", "Avaya Inc" },
{ "24D921", "Avaya Inc" },
{ "848371", "Avaya Inc" },
{ "7052C5", "Avaya Inc" },
{ "001B4F", "Avaya Inc" },
{ "F0EBD0", "Shanghai Feixun Communication Co.,Ltd." },
{ "D8490B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "888603", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F8E811", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E09796", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "CCCC81", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "101B54", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "7054F5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00197E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "78DD08", "Hon Hai Precision Ind. Co.,Ltd." },
{ "9CD21E", "Hon Hai Precision Ind. Co.,Ltd." },
{ "8096CA", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D07AB5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C40528", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3CDFBD", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "14B968", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "80717A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F49FF3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2C5BB8", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "B0AA36", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "784B87", "Murata Manufacturing Co., Ltd." },
{ "28A183", "ALPS ELECTRIC CO.,LTD." },
{ "5CF8A1", "Murata Manufacturing Co., Ltd." },
{ "6021C0", "Murata Manufacturing Co., Ltd." },
{ "84DBAC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C07009", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E0191D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B8BC1B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "241FA0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "50A72B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C85195", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00F81C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F4559C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "283CE4", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "64A5C3", "Apple, Inc." },
{ "001D0F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "5C63BF", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "B0487A", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "388345", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "14E6E4", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "647002", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "6466B3", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "6CE873", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "08E84F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "04BD70", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "18C58A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "405FC2", "Texas Instruments" },
{ "20CD39", "Texas Instruments" },
{ "D8DDFD", "Texas Instruments" },
{ "544A16", "Texas Instruments" },
{ "EC1127", "Texas Instruments" },
{ "247189", "Texas Instruments" },
{ "987BF3", "Texas Instruments" },
{ "04C06F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "5C4CA9", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4C5499", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00259E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001882", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D4EA0E", "Avaya Inc" },
{ "B4475E", "Avaya Inc" },
{ "90FB5B", "Avaya Inc" },
{ "14F65A", "Xiaomi Communications Co Ltd" },
{ "0C1DAF", "Xiaomi Communications Co Ltd" },
{ "28E31F", "Xiaomi Communications Co Ltd" },
{ "F0B429", "Xiaomi Communications Co Ltd" },
{ "00906F", "Cisco Systems, Inc" },
{ "0090A6", "Cisco Systems, Inc" },
{ "0090AB", "Cisco Systems, Inc" },
{ "7426AC", "Cisco Systems, Inc" },
{ "B000B4", "Cisco Systems, Inc" },
{ "2834A2", "Cisco Systems, Inc" },
{ "641225", "Cisco Systems, Inc" },
{ "544A00", "Cisco Systems, Inc" },
{ "5067AE", "Cisco Systems, Inc" },
{ "BC16F5", "Cisco Systems, Inc" },
{ "6899CD", "Cisco Systems, Inc" },
{ "F44E05", "Cisco Systems, Inc" },
{ "0CF5A4", "Cisco Systems, Inc" },
{ "5CFC66", "Cisco Systems, Inc" },
{ "D0A5A6", "Cisco Systems, Inc" },
{ "3C5EC3", "Cisco Systems, Inc" },
{ "64F69D", "Cisco Systems, Inc" },
{ "74A2E6", "Cisco Systems, Inc" },
{ "204C9E", "Cisco Systems, Inc" },
{ "A055DE", "Pace plc" },
{ "0026D9", "Pace plc" },
{ "00112F", "ASUSTek COMPUTER INC." },
{ "0011D8", "ASUSTek COMPUTER INC." },
{ "001731", "ASUSTek COMPUTER INC." },
{ "0018F3", "ASUSTek COMPUTER INC." },
{ "485B39", "ASUSTek COMPUTER INC." },
{ "F46D04", "ASUSTek COMPUTER INC." },
{ "3085A9", "ASUSTek COMPUTER INC." },
{ "00900C", "Cisco Systems, Inc" },
{ "001079", "Cisco Systems, Inc" },
{ "00102F", "Cisco Systems, Inc" },
{ "000E08", "Cisco-Linksys, LLC" },
{ "00602F", "Cisco Systems, Inc" },
{ "006070", "Cisco Systems, Inc" },
{ "006083", "Cisco Systems, Inc" },
{ "00067C", "Cisco Systems, Inc" },
{ "C8D719", "Cisco-Linksys, LLC" },
{ "CC08E0", "Apple, Inc." },
{ "5855CA", "Apple, Inc." },
{ "8C7B9D", "Apple, Inc." },
{ "88C663", "Apple, Inc." },
{ "C82A14", "Apple, Inc." },
{ "9803D8", "Apple, Inc." },
{ "8C5877", "Apple, Inc." },
{ "3451C9", "Apple, Inc." },
{ "E0B9BA", "Apple, Inc." },
{ "D023DB", "Apple, Inc." },
{ "B88D12", "Apple, Inc." },
{ "B817C2", "Apple, Inc." },
{ "68A86D", "Apple, Inc." },
{ "78A3E4", "Apple, Inc." },
{ "54781A", "Cisco Systems, Inc" },
{ "58971E", "Cisco Systems, Inc" },
{ "CCD539", "Cisco Systems, Inc" },
{ "20BBC0", "Cisco Systems, Inc" },
{ "4C4E35", "Cisco Systems, Inc" },
{ "7CAD74", "Cisco Systems, Inc" },
{ "10F311", "Cisco Systems, Inc" },
{ "08CC68", "Cisco Systems, Inc" },
{ "D0C789", "Cisco Systems, Inc" },
{ "F84F57", "Cisco Systems, Inc" },
{ "34DBFD", "Cisco Systems, Inc" },
{ "5CA48A", "Cisco Systems, Inc" },
{ "AC7A4D", "ALPS ELECTRIC CO.,LTD." },
{ "FC62B9", "ALPS ELECTRIC CO.,LTD." },
{ "0010A6", "Cisco Systems, Inc" },
{ "E86549", "Cisco Systems, Inc" },
{ "84B517", "Cisco Systems, Inc" },
{ "046273", "Cisco Systems, Inc" },
{ "9C57AD", "Cisco Systems, Inc" },
{ "00223A", "Cisco SPVTG" },
{ "001839", "Cisco-Linksys, LLC" },
{ "001EE5", "Cisco-Linksys, LLC" },
{ "38C85C", "Cisco SPVTG" },
{ "F45FD4", "Cisco SPVTG" },
{ "002306", "ALPS ELECTRIC CO.,LTD." },
{ "001E3D", "ALPS ELECTRIC CO.,LTD." },
{ "0019C1", "ALPS ELECTRIC CO.,LTD." },
{ "BC926B", "Apple, Inc." },
{ "0050E4", "Apple, Inc." },
{ "003065", "Apple, Inc." },
{ "000A27", "Apple, Inc." },
{ "001451", "Apple, Inc." },
{ "0019E3", "Apple, Inc." },
{ "002312", "Apple, Inc." },
{ "002332", "Apple, Inc." },
{ "002436", "Apple, Inc." },
{ "00254B", "Apple, Inc." },
{ "0026BB", "Apple, Inc." },
{ "E80688", "Apple, Inc." },
{ "985AEB", "Apple, Inc." },
{ "2078F0", "Apple, Inc." },
{ "78D75F", "Apple, Inc." },
{ "E0ACCB", "Apple, Inc." },
{ "98E0D9", "Apple, Inc." },
{ "C0CECD", "Apple, Inc." },
{ "70E72C", "Apple, Inc." },
{ "D03311", "Apple, Inc." },
{ "847D50", "Holley Metering Limited" },
{ "6C4A39", "BITA" },
{ "C8B5B7", "Apple, Inc." },
{ "A8BBCF", "Apple, Inc." },
{ "90B21F", "Apple, Inc." },
{ "B8E856", "Apple, Inc." },
{ "1499E2", "Apple, Inc." },
{ "04214C", "Insight Energy Ventures LLC" },
{ "B418D1", "Apple, Inc." },
{ "80006E", "Apple, Inc." },
{ "60D9C7", "Apple, Inc." },
{ "C8F650", "Apple, Inc." },
{ "1C1AC0", "Apple, Inc." },
{ "E06678", "Apple, Inc." },
{ "5C8D4E", "Apple, Inc." },
{ "64A3CB", "Apple, Inc." },
{ "44FB42", "Apple, Inc." },
{ "F41BA1", "Apple, Inc." },
{ "3CE072", "Apple, Inc." },
{ "E88D28", "Apple, Inc." },
{ "CC785F", "Apple, Inc." },
{ "AC3C0B", "Apple, Inc." },
{ "88CB87", "Apple, Inc." },
{ "EC3586", "Apple, Inc." },
{ "F0C1F1", "Apple, Inc." },
{ "F4F951", "Apple, Inc." },
{ "18AF8F", "Apple, Inc." },
{ "C0F2FB", "Apple, Inc." },
{ "00F76F", "Apple, Inc." },
{ "AC87A3", "Apple, Inc." },
{ "48437C", "Apple, Inc." },
{ "34A395", "Apple, Inc." },
{ "9CF387", "Apple, Inc." },
{ "A85B78", "Apple, Inc." },
{ "908D6C", "Apple, Inc." },
{ "0C1539", "Apple, Inc." },
{ "BC4CC4", "Apple, Inc." },
{ "0CBC9F", "Apple, Inc." },
{ "A45E60", "Apple, Inc." },
{ "680927", "Apple, Inc." },
{ "60FACD", "Apple, Inc." },
{ "1CABA7", "Apple, Inc." },
{ "8CFABA", "Apple, Inc." },
{ "5C95AE", "Apple, Inc." },
{ "E0C97A", "Apple, Inc." },
{ "BC52B7", "Apple, Inc." },
{ "14109F", "Apple, Inc." },
{ "542696", "Apple, Inc." },
{ "D8D1CB", "Apple, Inc." },
{ "4C8ECC", "SILKAN SA" },
{ "3CEF8C", "ZHEJIANG DAHUA TECHNOLOGY CO.,LTD." },
{ "64BC0C", "LG Electronics" },
{ "98F428", "zte corporation" },
{ "7C5A67", "JNC Systems, Inc." },
{ "5C4979", "AVM Audiovisuelles Marketing und Computersysteme GmbH" },
{ "C4BBEA", "Pakedge Device and Software Inc" },
{ "84100D", "Motorola Mobility LLC, a Lenovo Company" },
{ "D88B4C", "KingTing Tech." },
{ "E81363", "Comstock RD, Inc." },
{ "6C9354", "Yaojin Technology (Shenzhen) Co., LTD." },
{ "4054E4", "Wearsafe Labs Inc" },
{ "8CE2DA", "Circle Media Inc" },
{ "74D7CA", "Panasonic Corporation Automotive" },
{ "1CCDE5", "Shanghai Wind Technologies Co.,Ltd" },
{ "20896F", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "D494E8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B078F0", "Beijing HuaqinWorld Technology Co.,Ltd." },
{ "3029BE", "Shanghai MRDcom Co.,Ltd" },
{ "7011AE", "Music Life LTD" },
{ "ECB870", "Beijing Heweinet Technology Co.,Ltd." },
{ "3095E3", "SHANGHAI SIMCOM LIMITED" },
{ "401B5F", "Weifang GoerTek Electronics Co., Ltd." },
{ "BC307E", "Wistron Neweb Corp" },
{ "4040A7", "Sony Mobile Communications AB" },
{ "54BE53", "zte corporation" },
{ "588BF3", "ZyXEL Communications Corporation" },
{ "A01E0B", "MINIX Technology Limited" },
{ "D48304", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "385F66", "Cisco SPVTG" },
{ "544E90", "Apple, Inc." },
{ "28C87A", "Pace plc" },
{ "58FC73", "Arria Live Media, Inc." },
{ "2C1BC8", "Hunan Topview Network System CO.,LTD" },
{ "5CADCF", "Apple, Inc." },
{ "006D52", "Apple, Inc." },
{ "D888CE", "RF Technology Pty Ltd" },
{ "D4F4BE", "Palo Alto Networks" },
{ "B88687", "Liteon Technology Corporation" },
{ "68F956", "Objetivos y Servicio de Valor Añadido" },
{ "58B633", "Ruckus Wireless" },
{ "AC60B6", "Ericsson AB" },
{ "F4E926", "Tianjin Zanpu Technology Inc." },
{ "D03742", "Yulong Computer Telecommunication Scientific(shenzhen)Co.,Lt" },
{ "04C23E", "HTC Corporation" },
{ "2CFCE4", "CTEK Sweden AB" },
{ "A8A795", "Hon Hai Precision Ind. Co.,Ltd." },
{ "10868C", "ARRIS Group, Inc." },
{ "C0B713", "Beijing Xiaoyuer Technology Co. Ltd." },
{ "DCA3AC", "RBcloudtech" },
{ "44656A", "Mega Video Electronic(HK) Industry Co., Ltd" },
{ "0C9160", "Hui Zhou Gaoshengda Technology Co.,LTD" },
{ "ECA9FA", "GUANGDONG GENIUS TECHNOLOGY CO.,LTD." },
{ "300C23", "zte corporation" },
{ "EC1F72", "Samsung Electro Mechanics co., LTD." },
{ "445F8C", "Intercel Group Limited" },
{ "A48D3B", "Vizio, Inc" },
{ "1005B1", "ARRIS Group, Inc." },
{ "0C756C", "Anaren Microwave, Inc." },
{ "5C5188", "Motorola Mobility LLC, a Lenovo Company" },
{ "A039F7", "LG Electronics (Mobile Communications)" },
{ "689AB7", "Atelier Vision Corporation" },
{ "640DE6", "Petra Systems" },
{ "283713", "Shenzhen 3Nod Digital Technology Co., Ltd." },
{ "7CAB25", "MESMO TECHNOLOGY INC." },
{ "74042B", "Lenovo Mobile Communication (Wuhan) Company Limited" },
{ "4455B1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "A45602", "fenglian Technology Co.,Ltd." },
{ "D06A1F", "BSE CO.,LTD." },
{ "A88038", "ShenZhen MovingComm Technology Co., Limited" },
{ "805067", "W & D TECHNOLOGY CORPORATION" },
{ "402814", "RFI Engineering" },
{ "102C83", "XIMEA" },
{ "D468BA", "Shenzhen Sundray Technologies Company Limited" },
{ "A47B85", "ULTIMEDIA Co Ltd," },
{ "CC37AB", "Edgecore Networks Corportation" },
{ "F80D60", "CANON INC." },
{ "E02CB2", "Lenovo Mobile Communication (Wuhan) Company Limited" },
{ "DC15DB", "Ge Ruili Intelligent Technology ( Beijing ) Co., Ltd." },
{ "E8508B", "Samsung Electro Mechanics co., LTD." },
{ "30F335", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E89120", "Motorola Mobility LLC, a Lenovo Company" },
{ "546172", "ZODIAC AEROSPACE SAS" },
{ "AC620D", "Jabil Circuit (Wuxi) Co. LTD" },
{ "54CD10", "Panasonic Mobile Communications Co.,Ltd." },
{ "A4A1E4", "Innotube, Inc." },
{ "706879", "Saijo Denki International Co., Ltd." },
{ "343D98", "JinQianMao Technology Co.,Ltd." },
{ "5804CB", "Tianjin Huisun Technology Co.,Ltd." },
{ "1CB72C", "ASUSTek COMPUTER INC." },
{ "40B89A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "40B837", "Sony Mobile Communications AB" },
{ "287610", "IgniteNet" },
{ "68A378", "FREEBOX SAS" },
{ "746A3A", "Aperi Corporation" },
{ "1844E6", "zte corporation" },
{ "A8D409", "USA 111 Inc" },
{ "3089D3", "HONGKONG UCLOUDLINK NETWORK TECHNOLOGY LIMITED" },
{ "4CB76D", "Novi Security" },
{ "906CAC", "Fortinet, Inc." },
{ "00323A", "so-logic" },
{ "64DB81", "Syszone Co., Ltd." },
{ "FC6FB7", "Pace plc" },
{ "C4BAA3", "Beijing Winicssec Technologies Co., Ltd." },
{ "A013CB", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "20635F", "Abeeway" },
{ "E00370", "ShenZhen Continental Wireless Technology Co., Ltd." },
{ "709C8F", "Nero AG" },
{ "807459", "K's Co.,Ltd." },
{ "CC9635", "LVS Co.,Ltd." },
{ "700136", "FATEK Automation Corporation" },
{ "E03560", "Challenger Supply Holdings, LLC" },
{ "0CB5DE", "Alcatel Lucent" },
{ "04C9D9", "EchoStar Technologies Corp" },
{ "E4CE70", "Health & Life co., Ltd." },
{ "EC5A86", "Yulong Computer Telecommunication Scientific (Shenzhen) Co.,Ltd" },
{ "802AA8", "Ubiquiti Networks, Inc." },
{ "F87AEF", "Rosonix Technology, Inc." },
{ "10E878", "Alcatel-Lucent" },
{ "BC6010", "Qingdao Hisense Communications Co.,Ltd" },
{ "C43ABE", "Sony Mobile Communications AB" },
{ "18B169", "Sonicwall" },
{ "D4684D", "Ruckus Wireless" },
{ "1CC72D", "Shenzhen Huapu Digital CO.,Ltd" },
{ "38D82F", "zte corporation" },
{ "C8D779", "Qingdao Haier Telecom Co.，Ltd" },
{ "A0C562", "Pace plc" },
{ "2CA2B4", "Fortify Technologies, LLC" },
{ "D87495", "zte corporation" },
{ "8C873B", "Leica Camera AG" },
{ "28E476", "Pi-Coral" },
{ "9C685B", "Octonion SA" },
{ "ACABBF", "AthenTek Inc." },
{ "5C41E7", "Wiatec International Ltd." },
{ "DC0914", "Talk-A-Phone Co." },
{ "142971", "NEMOA ELECTRONICS (HK) CO. LTD" },
{ "C0BDD1", "Samsung Electro Mechanics co., LTD." },
{ "346895", "Hon Hai Precision Ind. Co.,Ltd." },
{ "B47356", "Hangzhou Treebear Networking Co., Ltd." },
{ "D88D5C", "Elentec" },
{ "50ADD5", "Dynalec Corporation" },
{ "28D98A", "Hangzhou Konke Technology Co.,Ltd." },
{ "BC4DFB", "Hitron Technologies. Inc" },
{ "6C25B9", "BBK Electronics Corp., Ltd.," },
{ "7429AF", "Hon Hai Precision Ind. Co.,Ltd." },
{ "40EACE", "FOUNDER BROADBAND NETWORK SERVICE CO.,LTD" },
{ "10C67E", "SHENZHEN JUCHIN TECHNOLOGY CO., LTD" },
{ "3C4937", "ASSMANN Electronic GmbH" },
{ "904506", "Tokyo Boeki Medisys Inc." },
{ "80A85D", "Osterhout Design Group" },
{ "9C6C15", "Microsoft Corporation" },
{ "EC74BA", "Hirschmann Automation and Control GmbH" },
{ "683C7D", "Magic Intelligence Technology Limited" },
{ "60128B", "CANON INC." },
{ "ECBAFE", "GIROPTIC" },
{ "E8447E", "Bitdefender SRL" },
{ "84C3E8", "Vaillant GmbH" },
{ "B88EC6", "Stateless Networks" },
{ "146B72", "Shenzhen Fortune Ship Technology Co., Ltd." },
{ "40A5EF", "Shenzhen Four Seas Global Link Network Technology Co., Ltd." },
{ "7C7A53", "Phytrex Technology Corp." },
{ "4886E8", "Microsoft Corporation" },
{ "78FC14", "B Communications Pty Ltd" },
{ "88E161", "Art Beijing Science and Technology Development Co., Ltd." },
{ "B4A9FE", "GHIA Technology (Shenzhen) LTD" },
{ "700FC7", "SHENZHEN IKINLOOP TECHNOLOGY CO.,LTD." },
{ "EC8009", "NovaSparks" },
{ "64002D", "Powerlinq Co., LTD" },
{ "486B2C", "BBK Electronics Corp., Ltd.," },
{ "101218", "Korins Inc." },
{ "EC0EC4", "Hon Hai Precision Ind. Co.,Ltd." },
{ "B04515", "mira fitness,LLC." },
{ "307512", "Sony Mobile Communications AB" },
{ "A49D49", "Ketra, Inc." },
{ "C09879", "Acer Inc." },
{ "1C9ECB", "Beijing Nari Smartchip Microelectronics Company Limited" },
{ "D48DD9", "Meld Technology, Inc" },
{ "2C3796", "CYBO CO.,LTD." },
{ "9470D2", "WINFIRM TECHNOLOGY" },
{ "2C2997", "Microsoft Corporation" },
{ "4CE2F1", "sclak srl" },
{ "344DEA", "zte corporation" },
{ "908C09", "Total Phase" },
{ "1C7E51", "3bumen.com" },
{ "E41D2D", "Mellanox Technologies, Inc." },
{ "60C798", "Verifone, Inc." },
{ "380E7B", "V.P.S. Thai Co., Ltd" },
{ "38F33F", "TATSUNO CORPORATION" },
{ "28A5EE", "Shenzhen SDGI CATV Co., Ltd" },
{ "94CE31", "CTS Limited" },
{ "4CBB58", "Chicony Electronics Co., Ltd." },
{ "C40006", "Lipi Data Systems Ltd." },
{ "789CE7", "Shenzhen Aikede Technology Co., Ltd" },
{ "64899A", "LG Electronics" },
{ "5C2ED2", "ABC(XiSheng) Electronics Co.,Ltd" },
{ "D8F710", "Libre Wireless Technologies Inc." },
{ "68F728", "LCFC(HeFei) Electronics Technology co., ltd" },
{ "DCEC06", "Heimi Network Technology Co., Ltd." },
{ "8870EF", "SC Professional Trading Co., Ltd." },
{ "102F6B", "Microsoft Corporation" },
{ "ACB74F", "METEL s.r.o." },
{ "CCF538", "3isysnetworks" },
{ "04DEDB", "Rockport Networks Inc" },
{ "68F06D", "ALONG INDUSTRIAL CO., LIMITED" },
{ "54F876", "ABB AG" },
{ "4857DD", "Facebook" },
{ "84930C", "InCoax Networks Europe AB" },
{ "D47B35", "NEO Monitors AS" },
{ "D8FB11", "AXACORE" },
{ "C8D019", "Shanghai Tigercel Communication Technology Co.,Ltd" },
{ "18A958", "PROVISION THAI CO., LTD." },
{ "D8DECE", "ISUNG CO.,LTD" },
{ "2053CA", "Risk Technology Ltd" },
{ "142BD6", "Guangdong Appscomm Co.,Ltd" },
{ "C8BA94", "Samsung Electro Mechanics co., LTD." },
{ "B025AA", "Private" },
{ "408256", "Continental Automotive GmbH" },
{ "D866EE", "BOXIN COMMUNICATION CO.,LTD." },
{ "3C189F", "Nokia Corporation" },
{ "2829CC", "Corsa Technology Incorporated" },
{ "FC790B", "Hitachi High Technologies America, Inc." },
{ "28E6E9", "SIS Sat Internet Services GmbH" },
{ "BC4E5D", "ZhongMiao Technology Co., Ltd." },
{ "08F728", "GLOBO Multimedia Sp. z o.o. Sp.k." },
{ "70720D", "Lenovo Mobile Communication Technology Ltd." },
{ "8401A7", "Greyware Automation Products, Inc" },
{ "C4C9EC", "Gugaoo   HK Limited" },
{ "F406A5", "Hangzhou Bianfeng Networking Technology Co., Ltd." },
{ "4C3909", "HPL Electric & Power Private Limited" },
{ "7CFE4E", "Shenzhen Safe vision Technology Co.,LTD" },
{ "54EF92", "Shenzhen Elink Technology Co., LTD" },
{ "800E24", "ForgetBox" },
{ "FCE186", "A3M Co., LTD" },
{ "CCB691", "NECMagnusCommunications" },
{ "40167E", "ASUSTek COMPUTER INC." },
{ "C89F1D", "SHENZHEN COMMUNICATION TECHNOLOGIES CO.,LTD" },
{ "983713", "PT.Navicom Indonesia" },
{ "ACA919", "TrekStor GmbH" },
{ "84850A", "Hella Sonnen- und Wetterschutztechnik GmbH" },
{ "183009", "Woojin Industrial Systems Co., Ltd." },
{ "6081F9", "Helium Systems, Inc" },
{ "34C5D0", "Hagleitner Hygiene International GmbH" },
{ "74DBD1", "Ebay Inc" },
{ "3431C4", "AVM GmbH" },
{ "DC537C", "Compal Broadband Networks, Inc." },
{ "A00627", "NEXPA System" },
{ "303335", "Boosty" },
{ "18D5B6", "SMG Holdings LLC" },
{ "C8FF77", "Dyson Limited" },
{ "C03D46", "Shanghai Mochui Network Technology Co., Ltd" },
{ "DCF110", "Nokia Corporation" },
{ "54DF00", "Ulterius Technologies, LLC" },
{ "E01D38", "Beijing HuaqinWorld Technology Co.,Ltd" },
{ "D80CCF", "C.G.V. S.A.S." },
{ "143DF2", "Beijing Shidai Hongyuan Network Communication Co.,Ltd" },
{ "B0D59D", "Shenzhen Zowee Technology Co., Ltd" },
{ "C4913A", "Shenzhen Sanland Electronic Co., ltd." },
{ "A46032", "MRV Communications (Networks) LTD" },
{ "205A00", "Coval" },
{ "0C2026", "noax Technologies AG" },
{ "240A11", "TCT Mobile Limited" },
{ "880FB6", "Jabil Circuits India Pvt Ltd,-EHTP unit" },
{ "C4626B", "ZPT Vigantice" },
{ "74F85D", "Berkeley Nucleonics Corp" },
{ "08D833", "Shenzhen RF Technology Co,.Ltd" },
{ "48EE07", "Silver Palm Technologies LLC" },
{ "9CFBF1", "MESOMATIC GmbH & Co.KG" },
{ "94C014", "Sorter Sp. j. Konrad Grzeszczyk MichaA, Ziomek" },
{ "1027BE", "TVIP" },
{ "2087AC", "AES motomation" },
{ "A824EB", "ZAO NPO Introtest" },
{ "447E76", "Trek Technology (S) Pte Ltd" },
{ "E8FC60", "ELCOM Innovations Private Limited" },
{ "1CFCBB", "Realfiction ApS" },
{ "B0EC8F", "GMX SAS" },
{ "C40E45", "ACK Networks,Inc." },
{ "5C254C", "Avire Global Pte Ltd" },
{ "7C1A03", "8Locations Co., Ltd." },
{ "481842", "Shanghai Winaas Co. Equipment Co. Ltd." },
{ "E817FC", "NIFTY Corporation" },
{ "D09C30", "Foster Electric Company, Limited" },
{ "78FEE2", "Shanghai Diveo Technology Co., Ltd" },
{ "386C9B", "Ivy Biomedical" },
{ "E44C6C", "Shenzhen Guo Wei Electronic Co,. Ltd." },
{ "008B43", "RFTECH" },
{ "2C957F", "zte corporation" },
{ "242642", "SHARP Corporation." },
{ "282246", "Beijing Sinoix Communication Co., LTD" },
{ "FC1607", "Taian Technology(Wuxi) Co.,Ltd." },
{ "CC89FD", "Nokia Corporation" },
{ "E86183", "Black Diamond Advanced Technology, LLC" },
{ "C4824E", "Changzhou Uchip Electronics Co., LTD." },
{ "24A87D", "Panasonic Automotive Systems Asia Pacific(Thailand)Co.,Ltd." },
{ "78EC74", "Kyland-USA" },
{ "28C825", "DellKing Industrial Co., Ltd" },
{ "64E892", "Morio Denki Co., Ltd." },
{ "086DF2", "Shenzhen MIMOWAVE Technology Co.,Ltd" },
{ "64EB8C", "Seiko Epson Corporation" },
{ "48D0CF", "Universal Electronics, Inc." },
{ "AC3613", "Samsung Electronics Co.,Ltd" },
{ "DCC793", "Nokia Corporation" },
{ "E03F49", "ASUSTek COMPUTER INC." },
{ "D8EE78", "Moog Protokraft" },
{ "F4B6E5", "TerraSem Co.,Ltd" },
{ "28BB59", "RNET Technologies, Inc." },
{ "7C8D91", "Shanghai Hongzhuo Information Technology co.,LTD" },
{ "A881F1", "BMEYE B.V." },
{ "241148", "Entropix, LLC" },
{ "30B5C2", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F85C45", "IC Nexus Co. Ltd." },
{ "88F7C7", "Technicolor USA Inc." },
{ "04DB8A", "Suntech International Ltd." },
{ "083F76", "Intellian Technologies, Inc." },
{ "0CC47A", "Super Micro Computer, Inc." },
{ "D0634D", "Meiko Maschinenbau GmbH &amp; Co. KG" },
{ "24DBED", "Samsung Electronics Co.,Ltd" },
{ "88C626", "Logitech - Ultimate Ears" },
{ "889CA6", "BTB Korea INC" },
{ "F025B7", "Samsung Electro Mechanics co., LTD." },
{ "B0DA00", "CERA ELECTRONIQUE" },
{ "447098", "MING HONG TECHNOLOGY (SHEN ZHEN) LIMITED" },
{ "54E2E0", "Pace plc" },
{ "00EEBD", "HTC Corporation" },
{ "48B5A7", "Glory Horse Industries Ltd." },
{ "DC5E36", "Paterson Technology" },
{ "50E0C7", "TurControlSystme AG" },
{ "9CD643", "D-Link International" },
{ "28FC51", "The Electric Controller and Manufacturing Co., LLC" },
{ "34A5E1", "Sensorist ApS" },
{ "A4E9A3", "Honest Technology Co., Ltd" },
{ "C4E92F", "AB Sciex" },
{ "9C216A", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F862AA", "xn systems" },
{ "A4059E", "STA Infinity LLP" },
{ "6C15F9", "Nautronix Limited" },
{ "680AD7", "Yancheng Kecheng Optoelectronic Technology Co., Ltd" },
{ "BC8893", "VILLBAU Ltd." },
{ "643F5F", "Exablaze" },
{ "E8F226", "MILLSON CUSTOM SOLUTIONS INC." },
{ "7060DE", "LaVision GmbH" },
{ "FCFE77", "Hitachi Reftechno, Inc." },
{ "24E271", "Qingdao Hisense Communications Co.,Ltd" },
{ "70533F", "Alfa Instrumentos Eletronicos Ltda." },
{ "448A5B", "Micro-Star INT'L CO., LTD." },
{ "68193F", "Digital Airways" },
{ "5CD61F", "Qardio, Inc" },
{ "902083", "General Engine Management Systems Ltd." },
{ "14B126", "Industrial Software Co" },
{ "C03580", "A&R TECH" },
{ "1446E4", "AVISTEL" },
{ "907990", "Benchmark Electronics Romania SRL" },
{ "C49380", "Speedytel technology" },
{ "B4A82B", "Histar Digital Electronics Co., Ltd." },
{ "60A9B0", "Merchandising Technologies, Inc" },
{ "007DFA", "Volkswagen Group of America" },
{ "6024C1", "Jiangsu Zhongxun Electronic Technology Co., Ltd" },
{ "6C5AB5", "TCL Technoly Electronics (Huizhou) Co., Ltd." },
{ "88789C", "Game Technologies SA" },
{ "18AA45", "Fon Technology" },
{ "0073E0", "Samsung Electronics Co.,Ltd" },
{ "549359", "SHENZHEN TWOWING TECHNOLOGIES CO.,LTD." },
{ "BC4486", "Samsung Electronics Co.,Ltd" },
{ "284430", "GenesisTechnical Systems (UK) Ltd" },
{ "9843DA", "INTERTECH" },
{ "8056F2", "Hon Hai Precision Ind. Co.,Ltd." },
{ "285767", "Echostar Technologies Corp" },
{ "B07908", "Cummings Engineering" },
{ "04CB1D", "Traka plc" },
{ "B87AC9", "Siemens Ltd." },
{ "B0989F", "LG CNS" },
{ "3C300C", "Dewar Electronics Pty Ltd" },
{ "78B5D2", "Ever Treasure Industrial Limited" },
{ "A409CB", "Alfred Kaercher GmbH &amp; Co KG" },
{ "C445EC", "Shanghai Yali Electron Co.,LTD" },
{ "380B40", "Samsung Electronics Co.,Ltd" },
{ "E8611F", "Dawning Information Industry Co.,Ltd" },
{ "0CA694", "Sunitec Enterprise Co.,Ltd" },
{ "146080", "zte corporation" },
{ "986CF5", "zte corporation" },
{ "78491D", "The Will-Burt Company" },
{ "74D435", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "840F45", "Shanghai GMT Digital Technologies Co., Ltd" },
{ "58A2B5", "LG Electronics" },
{ "D8270C", "MaxTronic International Co., Ltd." },
{ "E80410", "Private" },
{ "8C088B", "Remote Solution" },
{ "A47760", "Nokia Corporation" },
{ "24A495", "Thales Canada Inc." },
{ "70188B", "Hon Hai Precision Ind. Co.,Ltd." },
{ "3C77E6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "5CDD70", "Hangzhou H3C Technologies Co., Limited" },
{ "883612", "SRC Computers, LLC" },
{ "E0A198", "NOJA Power Switchgear Pty Ltd" },
{ "CC7B35", "zte corporation" },
{ "04D437", "ZNV" },
{ "CCF407", "EUKREA ELECTROMATIQUE SARL" },
{ "BC2BD7", "Revogi Innovation Co., Ltd." },
{ "3C404F", "Guangdong Pisen Electronics Co. Ltd." },
{ "24ECD6", "CSG Science & Technology Co.,Ltd.Hefei" },
{ "102279", "ZeroDesktop, Inc." },
{ "CC4AE1", "fourtec -Fourier Technologies" },
{ "A4895B", "ARK INFOSOLUTIONS PVT LTD" },
{ "38EC11", "Novatek Microelectronics Corp." },
{ "A8CCC5", "Saab AB (publ)" },
{ "988E4A", "NOXUS(BEIJING) TECHNOLOGY CO.,LTD" },
{ "1C4158", "Gemalto M2M GmbH" },
{ "ACD657", "Shaanxi Guolian Digital TV Technology Co., Ltd." },
{ "541B5D", "Techno-Innov" },
{ "78CB33", "DHC Software Co.,Ltd" },
{ "507691", "Tekpea, Inc." },
{ "C421C8", "KYOCERA Corporation" },
{ "A4C0C7", "ShenZhen Hitom Communication Technology Co..LTD" },
{ "EC2257", "JiangSu NanJing University Electronic Information Technology Co.,Ltd" },
{ "0C84DC", "Hon Hai Precision Ind. Co.,Ltd." },
{ "341A4C", "SHENZHEN WEIBU ELECTRONICS CO.,LTD." },
{ "A09BBD", "Total Aviation Solutions Pty Ltd" },
{ "E8481F", "Advanced Automotive Antennas" },
{ "18D6CF", "Kurth Electronic GmbH" },
{ "E07F88", "EVIDENCE Network SIA" },
{ "1C7CC7", "Coriant GmbH" },
{ "542CEA", "PROTECTRON" },
{ "00C5DB", "Datatech Sistemas Digitales Avanzados SL" },
{ "109AB9", "Tosibox Oy" },
{ "F842FB", "Yasuda Joho Co.,ltd." },
{ "887398", "K2E Tekpoint" },
{ "68EE96", "Cisco SPVTG" },
{ "FC6018", "Zhejiang Kangtai Electric Co., Ltd." },
{ "303EAD", "Sonavox Canada Inc" },
{ "444A65", "Silverflare Ltd." },
{ "50A0BF", "Alba Fiber Systems Inc." },
{ "3C977E", "IPS Technology Limited" },
{ "F02405", "OPUS High Technology Corporation" },
{ "D8B04C", "Jinan USR IOT Technology Co., Ltd." },
{ "646EEA", "Iskratel d.o.o." },
{ "043D98", "ChongQing QingJia Electronics CO.,LTD" },
{ "E8BB3D", "Sino Prime-Tech Limited" },
{ "E492FB", "Samsung Electronics Co.,Ltd" },
{ "98CDB4", "Virident Systems, Inc." },
{ "54E3B0", "JVL Industri Elektronik" },
{ "640B4A", "Digital Telecom Technology Limited" },
{ "F42012", "Cuciniale GmbH" },
{ "4C21D0", "Sony Mobile Communications AB" },
{ "18104E", "CEDINT-UPM" },
{ "2C7B84", "OOO Petr Telegin" },
{ "540536", "Vivago Oy" },
{ "2CE6CC", "Ruckus Wireless" },
{ "E0FAEC", "Platan sp. z o.o. sp. k." },
{ "F08EDB", "VeloCloud Networks" },
{ "B8DC87", "IAI Corporation" },
{ "7C6FF8", "ShenZhen ACTO Digital Video Technology Co.,Ltd." },
{ "8C4B59", "3D Imaging & Simulations Corp" },
{ "A4FB8D", "Hangzhou Dunchong Technology Co.Ltd" },
{ "0075E1", "Ampt, LLC" },
{ "CC04B4", "Select Comfort" },
{ "284FCE", "Liaoning Wontel Science and Technology Development Co.,Ltd." },
{ "1449E0", "Samsung Electro Mechanics co.,LTD." },
{ "0CC81F", "Summer Infant, Inc." },
{ "D86960", "Steinsvik" },
{ "442AFF", "E3 Technology, Inc." },
{ "E440E2", "Samsung Electronics Co.,Ltd" },
{ "0C9301", "PT. Prasimax Inovasi Teknologi" },
{ "1CAF05", "Samsung Electronics Co.,Ltd" },
{ "60699B", "isepos GmbH" },
{ "B830A8", "Road-Track Telematics Development" },
{ "542160", "Resolution Products" },
{ "88462A", "Telechips Inc." },
{ "A897DC", "IBM" },
{ "E8DE27", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "FC229C", "Han Kyung I Net Co.,Ltd." },
{ "148692", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "1832A2", "LAON TECHNOLOGY CO., LTD." },
{ "6854ED", "Alcatel-Lucent - Nuage" },
{ "985C93", "SBG Systems SAS" },
{ "64E599", "EFM Networks" },
{ "F499AC", "WEBER Schraubautomaten GmbH" },
{ "8CC7D0", "zhejiang ebang communication co.,ltd" },
{ "70820E", "as electronics GmbH" },
{ "DC2BCA", "Zera GmbH" },
{ "508D6F", "CHAHOO Limited" },
{ "68831A", "Pandora Mobility Corporation" },
{ "D4223F", "Lenovo Mobile Communication Technology Ltd." },
{ "0868D0", "Japan System Design" },
{ "103DEA", "HFC Technology (Beijing) Ltd. Co." },
{ "E8E875", "iS5 Communications Inc." },
{ "2C7B5A", "Milper Ltd" },
{ "185AE8", "Zenotech.Co.,Ltd" },
{ "E0AEED", "LOENK" },
{ "D4EE07", "HIWIFI Co., Ltd." },
{ "908260", "IEEE 1904.1 Working Group" },
{ "FCAD0F", "QTS NETWORKS" },
{ "984C04", "Zhangzhou Keneng Electrical Equipment Co Ltd" },
{ "CC047C", "G-WAY Microwave" },
{ "44F849", "Union Pacific Railroad" },
{ "1CFA68", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D0BE2C", "CNSLink Co., Ltd." },
{ "281878", "Microsoft Corporation" },
{ "E457A8", "Stuart Manufacturing, Inc." },
{ "2481AA", "KSH International Co., Ltd." },
{ "789966", "Musilab Electronics (DongGuan)Co.,Ltd." },
{ "D8B02E", "Guangzhou Zonerich Business Machine Co., Ltd" },
{ "EC2C49", "University of Tokyo" },
{ "CC5D57", "Information  System Research Institute,Inc." },
{ "1C37BF", "Cloudium Systems Ltd." },
{ "249504", "SFR" },
{ "308999", "Guangdong East Power Co.," },
{ "D4A499", "InView Technology Corporation" },
{ "AC4122", "Eclipse Electronic Systems Inc." },
{ "A073FC", "Rancore Technologies Private Limited" },
{ "846223", "Shenzhen Coship Electronics Co., Ltd." },
{ "A4E991", "SISTEMAS AUDIOVISUALES ITELSIS S.L." },
{ "84F493", "OMS spol. s.r.o." },
{ "386793", "Asia Optical Co., Inc." },
{ "BCD177", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "C8B373", "Cisco-Linksys, LLC" },
{ "983071", "DAIKYUNG VASCOM" },
{ "0C0400", "Jantar d.o.o." },
{ "C04301", "Epec Oy" },
{ "687CD5", "Y Soft Corporation, a.s." },
{ "E07C62", "Whistle Labs, Inc." },
{ "FC4499", "Swarco LEA d.o.o." },
{ "0C8484", "Zenovia Electronics Inc." },
{ "5CF370", "CC&C Technologies, Inc" },
{ "A01C05", "NIMAX TELECOM CO.,LTD." },
{ "F80DEA", "ZyCast Technology Inc." },
{ "1800DB", "Fitbit Inc." },
{ "50A715", "Aboundi, Inc." },
{ "FC35E6", "Visteon corp" },
{ "D866C6", "Shenzhen Daystar Technology Co.,ltd" },
{ "1836FC", "Elecsys International Corporation" },
{ "F48139", "CANON INC." },
{ "D40BB9", "Solid Semecs bv." },
{ "748E08", "Bestek Corp." },
{ "B8C855", "Shanghai GBCOM Communication Technology Co.,Ltd." },
{ "54A619", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "C47DFE", "A.N. Solutions GmbH" },
{ "E031D0", "SZ Telstar CO., LTD" },
{ "70C6AC", "Bosch Automotive Aftermarket" },
{ "2C69BA", "RF Controls, LLC" },
{ "DC5726", "Power-One" },
{ "2C245F", "Babolat VS" },
{ "D464F7", "CHENGDU USEE DIGITAL TECHNOLOGY CO., LTD" },
{ "A47ACF", "VIBICOM COMMUNICATIONS INC." },
{ "CC3C3F", "SA.S.S. Datentechnik AG" },
{ "905692", "Autotalks Ltd." },
{ "0C2AE7", "Beijing General Research Institute of Mining and Metallurgy" },
{ "4439C4", "Universal Global Scientific Industrial Co.,Ltd" },
{ "DCD52A", "Sunny Heart Limited" },
{ "C4C755", "Beijing HuaqinWorld Technology Co.,Ltd" },
{ "9C79AC", "Suntec Software(Shanghai) Co., Ltd." },
{ "6488FF", "Sichuan Changhong Electric Ltd." },
{ "F8DFA8", "zte corporation" },
{ "ACA430", "Peerless AV" },
{ "B4AB2C", "MtM Technology Corporation" },
{ "74372F", "Tongfang Shenzhen Cloudcomputing Technology Co.,Ltd" },
{ "BC51FE", "Swann communications Pty Ltd" },
{ "789ED0", "Samsung Electronics" },
{ "D40FB2", "Applied Micro Electronics AME bv" },
{ "74FE48", "ADVANTECH CO., LTD." },
{ "D0B498", "Robert Bosch LLC Automotive Electronics" },
{ "80B95C", "ELFTECH Co., Ltd." },
{ "E85AA7", "LLC Emzior" },
{ "242FFA", "Toshiba Global Commerce Solutions" },
{ "A0BAB8", "Pixon Imaging" },
{ "9CE1D6", "Junger Audio-Studiotechnik GmbH" },
{ "E4E409", "LEIFHEIT AG" },
{ "004D32", "Andon Health Co.,Ltd." },
{ "8C04FF", "Technicolor USA Inc." },
{ "C46DF1", "DataGravity" },
{ "28D244", "LCFC(HeFei) Electronics Technology Co., Ltd." },
{ "ACE87E", "Bytemark Computer Consulting Ltd" },
{ "60CDC5", "Taiwan Carol Electronics., Ltd" },
{ "1489FD", "Samsung Electronics" },
{ "60C5A8", "Beijing LT Honway Technology Co.,Ltd" },
{ "B4DF3B", "Chromlech" },
{ "A46E79", "DFT System Co.Ltd" },
{ "94DE80", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "C88A83", "Dongguan HuaHong Electronics Co.,Ltd" },
{ "0CC655", "Wuxi YSTen Technology Co.,Ltd." },
{ "D410CF", "Huanshun Network Science and Technology Co., Ltd." },
{ "B80415", "Bayan Audio" },
{ "84C8B1", "Incognito Software Systems Inc." },
{ "645A04", "Chicony Electronics Co., Ltd." },
{ "5C89D4", "Beijing Banner Electric Co.,Ltd" },
{ "984CD3", "Mantis Deposition" },
{ "8C4CDC", "PLANEX COMMUNICATIONS INC." },
{ "10683F", "LG Electronics" },
{ "D063B4", "SolidRun Ltd." },
{ "2C3BFD", "Netstor Technology Co., Ltd." },
{ "F073AE", "PEAK-System Technik" },
{ "684CA8", "Shenzhen Herotel Tech. Co., Ltd." },
{ "F4472A", "Nanjing Rousing Sci. and Tech. Industrial Co., Ltd" },
{ "185253", "Pixord Corporation" },
{ "A41731", "Hon Hai Precision Ind. Co.,Ltd." },
{ "FCA9B0", "MIARTECH (SHANGHAI),INC." },
{ "80D733", "QSR Automations, Inc." },
{ "8C3330", "EmFirst Co., Ltd." },
{ "8C0C90", "Ruckus Wireless" },
{ "08E5DA", "NANJING FUJITSU COMPUTER PRODUCTS CO.,LTD. " },
{ "5884E4", "IP500 Alliance e.V." },
{ "04E9E5", "PJRC.COM, LLC" },
{ "703811", "Invensys Rail" },
{ "ACE64B", "Shenzhen Baojia Battery Technology Co., Ltd." },
{ "303294", "W-IE-NE-R Plein & Baus GmbH" },
{ "EC473C", "Redwire, LLC" },
{ "5481AD", "Eagle Research Corporation" },
{ "7C822D", "Nortec" },
{ "745FAE", "TSL PPL" },
{ "8462A6", "EuroCB (Phils), Inc." },
{ "80FA5B", "CLEVO CO." },
{ "E4F365", "Time-O-Matic, Inc." },
{ "18550F", "Cisco SPVTG" },
{ "1C9179", "Integrated System Technologies Ltd" },
{ "38F597", "home2net GmbH" },
{ "386645", "OOSIC Technology CO.,Ltd" },
{ "D0DFB2", "Genie Networks Limited" },
{ "808B5C", "Shenzhen Runhuicheng Technology Co., Ltd" },
{ "04586F", "Sichuan Whayer information industry Co.,LTD" },
{ "449B78", "The Now Factory" },
{ "D052A8", "Physical Graph Corporation" },
{ "EC43F6", "ZyXEL Communications Corporation" },
{ "34F62D", "SHARP Corporation" },
{ "C4EBE3", "RRCN SAS" },
{ "4C1A95", "Novakon Co., Ltd." },
{ "C04A00", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "9C3178", "Foshan Huadian Intelligent Communications Teachnologies Co.,Ltd" },
{ "48BE2D", "Symanitron" },
{ "38E595", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "B86091", "Onnet Technologies and Innovations LLC" },
{ "201A06", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "D4CA6E", "u-blox AG" },
{ "C011A6", "Fort-Telecom ltd." },
{ "B8DAF1", "Strahlenschutz- Entwicklungs- und Ausruestungsgesellschaft mbH" },
{ "1C11E1", "Wartsila Finland Oy" },
{ "50465D", "ASUSTek COMPUTER INC." },
{ "74BFA1", "HYUNTECK" },
{ "FCF528", "ZyXEL Communications Corporation" },
{ "F8AA8A", "Axview Technology (Shenzhen) Co.,Ltd" },
{ "60F494", "Hon Hai Precision Ind. Co.,Ltd." },
{ "5894CF", "Vertex Standard LMR, Inc." },
{ "2C5AA3", "PROMATE ELECTRONIC CO.LTD" },
{ "9852B1", "Samsung Electronics" },
{ "B4009C", "CableWorld Ltd." },
{ "803FD6", "bytes at work AG" },
{ "645FFF", "Nicolet Neuro" },
{ "2829D9", "GlobalBeiMing technology (Beijing)Co. Ltd" },
{ "189A67", "CSE-Servelec Limited" },
{ "38A5B6", "SHENZHEN MEGMEET ELECTRICAL CO.,LTD" },
{ "E43FA2", "Wuxi DSP Technologies Inc." },
{ "00FD4C", "NEVATEC" },
{ "E09DB8", "PLANEX COMMUNICATIONS INC." },
{ "6045BD", "Microsoft" },
{ "9C54CA", "Zhengzhou VCOM Science and Technology Co.,Ltd" },
{ "388AB7", "ITC Networks" },
{ "BCC23A", "Thomson Video Networks" },
{ "00BF15", "Genetec Inc." },
{ "20F85E", "Delta Electronics" },
{ "68CE4E", "L-3 Communications Infrared Products" },
{ "68B6FC", "Hitron Technologies. Inc" },
{ "7C160D", "Saia-Burgess Controls AG" },
{ "A4D18F", "Shenzhen Skyee Optical Fiber Communication Technology Ltd. " },
{ "0C565C", "HyBroad Vision (Hong Kong) Technology Co Ltd" },
{ "647C34", "Ubee Interactive Corp." },
{ "649FF7", "Kone OYj" },
{ "B86B23", "Toshiba" },
{ "4C068A", "Basler Electric Company" },
{ "E0A30F", "Pevco" },
{ "5C1737", "I-View Now, LLC." },
{ "049C62", "BMT Medical Technology s.r.o." },
{ "C4BA99", "I+ME Actia Informatik und Mikro-Elektronik GmbH" },
{ "0C2A69", "electric imp, incorporated" },
{ "BC811F", "Ingate Systems" },
{ "34E0CF", "zte corporation" },
{ "801DAA", "Avaya Inc" },
{ "6C40C6", "Nimbus Data Systems, Inc." },
{ "503F56", "Syncmold Enterprise Corp" },
{ "D04CC1", "SINTRONES Technology Corp." },
{ "DC9FA4", "Nokia Corporation" },
{ "44C39B", "OOO RUBEZH NPO" },
{ "58C232", "NEC Corporation" },
{ "D8C691", "Hichan Technology Corp." },
{ "8CFDF0", "QUALCOMM Incorporated" },
{ "7C02BC", "Hansung Electronics Co. LTD" },
{ "1848D8", "Fastback Networks" },
{ "C819F7", "Samsung Electronics Co.,Ltd" },
{ "702393", "fos4X GmbH" },
{ "C4731E", "Samsung Eletronics Co., Ltd" },
{ "D8AFF1", "Panasonic Appliances Company" },
{ "58ECE1", "Newport Corporation" },
{ "14358B", "Mediabridge Products, LLC." },
{ "34996F", "VPI Engineering" },
{ "241064", "Shenzhen Ecsino Tecnical Co. Ltd" },
{ "10D1DC", "INSTAR Deutschland GmbH" },
{ "844BF5", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D8160A", "Nippon Electro-Sensory Devices" },
{ "58696C", "Fujian Ruijie Networks co, ltd" },
{ "F45433", "Rockwell Automation" },
{ "EC9327", "MEMMERT GmbH + Co. KG" },
{ "1C43EC", "JAPAN CIRCUIT CO.,LTD" },
{ "BC28D6", "Rowley Associates Limited" },
{ "F05F5A", "Getriebebau NORD GmbH and Co. KG" },
{ "009569", "LSD Science and Technology Co.,Ltd." },
{ "34C803", "Nokia Corporation" },
{ "5011EB", "SilverNet Ltd" },
{ "5CD41B", "UCZOON Technology Co., LTD" },
{ "783CE3", "Kai-EE" },
{ "0868EA", "EITO ELECTRONICS CO., LTD." },
{ "5C4A26", "Enguity Technology Corp" },
{ "289EDF", "Danfoss Turbocor Compressors, Inc" },
{ "50053D", "CyWee Group Ltd" },
{ "4C64D9", "Guangdong Leawin Group Co., Ltd" },
{ "7CB03E", "OSRAM GmbH" },
{ "14B1C8", "InfiniWing, Inc." },
{ "C0493D", "MAITRISE TECHNOLOGIQUE" },
{ "34A7BA", "Fischer International Systems Corporation" },
{ "ACD364", "ABB SPA, ABB SACE DIV." },
{ "38F8B7", "V2COM PARTICIPACOES S.A." },
{ "B48255", "Research Products Corporation" },
{ "C84544", "Shanghai Enlogic Electric Technology Co., Ltd." },
{ "2C750F", "Shanghai Dongzhou-Lawton Communication Technology Co. Ltd." },
{ "B40418", "Smartchip Integrated Inc." },
{ "F4EA67", "Cisco Systems, Inc" },
{ "D0AEEC", "Alpha Networks Inc." },
{ "3C98BF", "Quest Controls, Inc." },
{ "D05785", "Pantech Co., Ltd." },
{ "045C06", "Zmodo Technology Corporation" },
{ "504A5E", "Masimo Corporation" },
{ "38BF33", "NEC CASIO Mobile Communications" },
{ "A041A7", "NL Ministry of Defense" },
{ "342F6E", "Anywire corporation" },
{ "E86D6E", "voestalpine SIGNALING Fareham Ltd." },
{ "F8D462", "Pumatronix Equipamentos Eletronicos Ltda." },
{ "5453ED", "Sony Corporation" },
{ "940070", "Nokia Corporation" },
{ "6C3A84", "Shenzhen Aero-Startech. Co.Ltd" },
{ "C0143D", "Hon Hai Precision Ind. Co.,Ltd." },
{ "442B03", "Cisco Systems, Inc" },
{ "781C5A", "SHARP Corporation" },
{ "E4C6E6", "Mophie, LLC" },
{ "502D1D", "Nokia Corporation" },
{ "BCEA2B", "CityCom GmbH" },
{ "944444", "LG Innotek" },
{ "E4C806", "Ceiec Electric Technology Inc." },
{ "18B591", "I-Storm" },
{ "A45630", "Cisco Systems, Inc" },
{ "CCFE3C", "Samsung Electronics" },
{ "002AAF", "LARsys-Automation GmbH" },
{ "60F3DA", "Logic Way GmbH" },
{ "A06D09", "Intelcan Technosystems Inc." },
{ "BC1401", "Hitron Technologies. Inc" },
{ "68D925", "ProSys Development Services" },
{ "B41DEF", "Internet Laboratories, Inc." },
{ "284121", "OptiSense Network, LLC" },
{ "5057A8", "Cisco Systems, Inc" },
{ "38458C", "MyCloud Technology corporation" },
{ "0C9D56", "Consort Controls Ltd" },
{ "3CCE73", "Cisco Systems, Inc" },
{ "A47C14", "ChargeStorm AB" },
{ "F4600D", "Panoptic Technology, Inc" },
{ "ACCF23", "Hi-flying electronics technology Co.,Ltd" },
{ "C08170", "Effigis GeoSolutions" },
{ "78C4AB", "Shenzhen Runsil Technology Co.,Ltd" },
{ "709A0B", "Italian Institute of Technology" },
{ "240917", "Devlin Electronics Limited" },
{ "DC37D2", "Hunan HKT Electronic Technology Co., Ltd" },
{ "048B42", "Skspruce Technology Limited" },
{ "5076A6", "Ecil Informatica Ind. Com. Ltda" },
{ "B431B8", "Aviwest" },
{ "241125", "Hutek Co., Ltd." },
{ "0036FE", "SuperVision" },
{ "CC187B", "Manzanita Systems, Inc." },
{ "38B12D", "Sonotronic Nagel GmbH" },
{ "E006E6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "8020AF", "Trade FIDES, a.s." },
{ "50D274", "Steffes Corporation" },
{ "48D54C", "Jeda Networks" },
{ "3497FB", "ADVANCED RF TECHNOLOGIES INC" },
{ "C46413", "Cisco Systems, Inc" },
{ "143AEA", "Dynapower Company LLC" },
{ "9CA134", "Nike, Inc." },
{ "B4D8A9", "BetterBots" },
{ "7CC8D7", "Damalisk" },
{ "0091FA", "Synapse Product Development" },
{ "A05AA4", "Grand Products Nevada, Inc." },
{ "24C0B3", "RSF" },
{ "E00B28", "Inovonics" },
{ "500B32", "Foxda Technology Industrial(ShenZhen)Co.,LTD" },
{ "E8039A", "Samsung Electronics CO., LTD" },
{ "302DE8", "JDA, LLC (JDA Systems)" },
{ "70CA9B", "Cisco Systems, Inc" },
{ "2C3F38", "Cisco Systems, Inc" },
{ "803F5D", "Winstars Technology Ltd" },
{ "780738", "Z.U.K. Elzab S.A." },
{ "640E36", "TAZTAG" },
{ "70EE50", "Netatmo" },
{ "EC63E5", "ePBoard Design LLC" },
{ "60B606", "Phorus" },
{ "F4E6D7", "Solar Power Technologies, Inc." },
{ "78DDD6", "c-scape" },
{ "984A47", "CHG Hospital Beds" },
{ "3C6A7D", "Niigata Power Systems Co., Ltd." },
{ "FC455F", "JIANGXI SHANSHUI OPTOELECTRONIC TECHNOLOGY CO.,LTD" },
{ "3C7059", "MakerBot Industries" },
{ "F8FE5C", "Reciprocal Labs Corp" },
{ "6C9CED", "Cisco Systems, Inc" },
{ "94E0D0", "HealthStream Taiwan Inc." },
{ "DCF858", "Lorent Networks, Inc." },
{ "589396", "Ruckus Wireless" },
{ "A05E6B", "MELPER Co., Ltd." },
{ "30B3A2", "Shenzhen Heguang Measurement & Control Technology Co.,Ltd" },
{ "F0007F", "Janz - Contadores de Energia, SA" },
{ "CC944A", "Pfeiffer Vacuum GmbH" },
{ "0C8525", "Cisco Systems, Inc" },
{ "BCE59F", "WATERWORLD Technology Co.,LTD" },
{ "1C5C55", "PRIMA Cinema, Inc" },
{ "082522", "ADVANSEE" },
{ "4C2F9D", "ICM Controls" },
{ "E467BA", "Danish Interpretation Systems A/S" },
{ "642737", "Hon Hai Precision Ind. Co.,Ltd." },
{ "BCFE8C", "Altronic, LLC" },
{ "24BBC1", "Absolute Analysis" },
{ "7CDD11", "Chongqing MAS SCI&TECH.Co.,Ltd" },
{ "C43C3C", "CYBELEC SA" },
{ "00D632", "GE Energy" },
{ "C40ACB", "Cisco Systems, Inc" },
{ "7463DF", "VTS GmbH" },
{ "3828EA", "Fujian Netcom Technology Co., LTD" },
{ "2CEE26", "Petroleum Geo-Services" },
{ "DC3E51", "Solberg & Andersen AS" },
{ "D8B90E", "Triple Domain Vision Co.,Ltd." },
{ "7C4B78", "Red Sun Synthesis Pte Ltd" },
{ "28D1AF", "Nokia Corporation" },
{ "68BC0C", "Cisco Systems, Inc" },
{ "2C9EFC", "CANON INC." },
{ "98C845", "PacketAccess" },
{ "988217", "Disruptive Ltd" },
{ "80FFA8", "UNIDIS" },
{ "489BE2", "SCI Innovations Ltd" },
{ "B0E50E", "NRG SYSTEMS INC" },
{ "4C5FD2", "Alcatel-Lucent" },
{ "E878A1", "BEOVIEW INTERCOM DOO" },
{ "3057AC", "IRLAB LTD." },
{ "9002A9", "ZHEJIANG DAHUA TECHNOLOGY CO.,LTD" },
{ "28AF0A", "Sirius XM Radio Inc" },
{ "2486F4", "Ctek, Inc." },
{ "3CE5B4", "KIDASEN INDUSTRIA E COMERCIO DE ANTENAS LTDA" },
{ "A85BF3", "Audivo GmbH" },
{ "344F69", "EKINOPS SAS" },
{ "2C4401", "Samsung Electronics Co.,Ltd" },
{ "C02973", "Audyssey Laboratories Inc." },
{ "30168D", "ProLon" },
{ "B451F9", "NB Software" },
{ "30688C", "Reach Technology Inc." },
{ "88F488", "cellon communications technology(shenzhen)Co.,Ltd." },
{ "0041B4", "Wuxi Zhongxing Optoelectronics Technology Co.,Ltd." },
{ "0007AB", "Samsung Electronics Co.,Ltd" },
{ "D453AF", "VIGO System S.A." },
{ "1CE192", "Qisda Corporation" },
{ "20C8B3", "SHENZHEN BUL-TECH CO.,LTD." },
{ "60D819", "Hon Hai Precision Ind. Co.,Ltd." },
{ "945103", "Samsung Electronics" },
{ "58B0D4", "ZuniData Systems Inc." },
{ "64557F", "NSFOCUS Information Technology Co., Ltd." },
{ "406AAB", "RIM" },
{ "248707", "SEnergy Corporation" },
{ "EC3F05", "Institute 706, The Second Academy China Aerospace Science & Industry Corp" },
{ "C4C19F", "National Oilwell Varco Instrumentation, Monitoring, and Optimization (NOV IMO)" },
{ "68CD0F", "U Tek Company Limited" },
{ "D4CEB8", "Enatel LTD" },
{ "ECF236", "NEOMONTANA ELECTRONICS" },
{ "E4A5EF", "TRON LINK ELECTRONICS CO., LTD." },
{ "AC4AFE", "Hisense Broadband Multimedia Technology Co.,Ltd." },
{ "2C1EEA", "AERODEV" },
{ "FC6C31", "LXinstruments GmbH" },
{ "3C6F45", "Fiberpro Inc." },
{ "B4FC75", "SEMA Electronics(HK) CO.,LTD" },
{ "5C16C7", "Big Switch Networks" },
{ "B0BF99", "WIZITDONGDO" },
{ "147DB3", "JOA TELECOM.CO.,LTD" },
{ "3CD16E", "Telepower Communication Co., Ltd" },
{ "00077D", "Cisco Systems, Inc" },
{ "D0176A", "Samsung Electronics Co.,Ltd" },
{ "1045BE", "Norphonic AS" },
{ "A0E295", "DAT System Co.,Ltd" },
{ "40F14C", "ISE Europe SPRL" },
{ "98293F", "Fujian Start Computer Equipment Co.,Ltd" },
{ "70D4F2", "RIM" },
{ "9067F3", "Alcatel Lucent" },
{ "64D912", "Solidica, Inc." },
{ "8C5CA1", "d-broad,INC" },
{ "C8F981", "Seneca s.r.l." },
{ "8C7712", "Samsung Electronics Co.,Ltd" },
{ "703187", "ACX GmbH" },
{ "14307A", "Avermetrics" },
{ "8C7EB3", "Lytro, Inc." },
{ "587675", "Beijing ECHO Technologies Co.,Ltd" },
{ "78EF4C", "Unetconvergence Co., Ltd." },
{ "E8DA96", "Zhuhai Tianrui Electrical Power Tech. Co., Ltd." },
{ "6CA780", "Nokia Corporation" },
{ "04888C", "Eifelwerk Butler Systeme GmbH" },
{ "1013EE", "Justec International Technology INC." },
{ "704642", "CHYNG HONG ELECTRONIC CO., LTD." },
{ "78BEB6", "Enhanced Vision" },
{ "ECEA03", "DARFON LIGHTING CORP" },
{ "C8903E", "Pakton Technologies" },
{ "7465D1", "Atlinks" },
{ "301A28", "Mako Networks Ltd" },
{ "D4945A", "COSMO CO., LTD" },
{ "5CF207", "Speco Technologies" },
{ "B01B7C", "Ontrol A.S." },
{ "D47B75", "HARTING Electronics GmbH" },
{ "70E843", "Beijing C&W Optical Communication Technology Co.,Ltd." },
{ "08ACA5", "Benu Video, Inc." },
{ "D89DB9", "eMegatech International Corp." },
{ "405A9B", "ANOVO" },
{ "ACCA54", "Telldus Technologies AB" },
{ "CC1EFF", "Metrological Group BV" },
{ "941673", "Point Core SARL" },
{ "6C5D63", "ShenZhen Rapoo Technology Co., Ltd." },
{ "E4D71D", "Oraya Therapeutics" },
{ "C8FE30", "Bejing DAYO Mobile Communication Technology Ltd." },
{ "64B64A", "ViVOtech, Inc." },
{ "DCA7D9", "Compressor Controls Corp" },
{ "C455A6", "Cadac Holdings Ltd" },
{ "BCBBC9", "Kellendonk Elektronik GmbH" },
{ "781DFD", "Jabil Inc" },
{ "103711", "Simlink AS" },
{ "601199", "Siama Systems Inc" },
{ "300B9C", "Delta Mobile Systems, Inc." },
{ "90EA60", "SPI Lasers Ltd " },
{ "D46F42", "WAXESS USA Inc" },
{ "B0A72A", "Ensemble Designs, Inc." },
{ "50795B", "Interexport Telecomunicaciones S.A." },
{ "E8C229", "H-Displays (MSC) Bhd" },
{ "3C6200", "Samsung electronics CO., LTD" },
{ "B0BDA1", "ZAKLAD ELEKTRONICZNY SIMS" },
{ "8C4435", "Shanghai BroadMobi Communication Technology Co., Ltd." },
{ "24B8D2", "Opzoon Technology Co.,Ltd." },
{ "24CBE7", "MYK, Inc." },
{ "88BFD5", "Simple Audio Ltd" },
{ "948B03", "EAGET Innovation and Technology Co., Ltd." },
{ "802DE1", "Solarbridge Technologies" },
{ "F081AF", "IRZ AUTOMATION TECHNOLOGIES LTD" },
{ "14EB33", "BSMediasoft Co., Ltd." },
{ "AC8674", "Open Mesh, Inc." },
{ "14A9E3", "MST CORPORATION" },
{ "589835", "Technicolor" },
{ "50D6D7", "Takahata Precision" },
{ "B4A5A9", "MODI GmbH" },
{ "D09B05", "Emtronix" },
{ "98EC65", "Cosesy ApS" },
{ "900917", "Far-sighted mobile" },
{ "88F077", "Cisco Systems, Inc" },
{ "AC4723", "Genelec" },
{ "20B7C0", "OMICRON electronics GmbH" },
{ "D42C3D", "Sky Light Digital Limited" },
{ "806CBC", "NET New Electronic Technology GmbH" },
{ "1C184A", "ShenZhen RicherLink Technologies Co.,LTD" },
{ "2013E0", "Samsung Electronics Co.,Ltd" },
{ "04E662", "Acroname Inc." },
{ "F0BF97", "Sony Corporation" },
{ "C44AD0", "FIREFLIES SYSTEMS" },
{ "88E0A0", "Shenzhen VisionSTOR Technologies Co., Ltd" },
{ "6879ED", "SHARP Corporation" },
{ "9CC0D2", "Conductix-Wampfler GmbH" },
{ "408BF6", "Shenzhen TCL New Technology Co; Ltd." },
{ "447E95", "Alpha and Omega, Inc" },
{ "E8B748", "Cisco Systems, Inc" },
{ "DC16A2", "Medtronic Diabetes" },
{ "78CA04", "Nokia Corporation" },
{ "2C8BF2", "Hitachi Metals America Ltd" },
{ "58F98E", "SECUDOS GmbH" },
{ "2826A6", "PBR electronics GmbH" },
{ "CC7669", "SEETECH" },
{ "E437D7", "HENRI DEPAEPE S.A.S." },
{ "582F42", "Universal Electric Corporation" },
{ "AC20AA", "DMATEK Co., Ltd." },
{ "E0A1D7", "SFR" },
{ "28852D", "Touch Networks" },
{ "F02A61", "Waldo Networks, Inc." },
{ "B8415F", "ASP AG" },
{ "2CB69D", "RED Digital Cinema" },
{ "988E34", "ZHEJIANG BOXSAM ELECTRONIC CO.,LTD" },
{ "D44C24", "Vuppalamritha Magnetic Components LTD" },
{ "4CB4EA", "HRD (S) PTE., LTD." },
{ "34BDF9", "Shanghai WDK Industrial Co.,Ltd." },
{ "74CE56", "Packet Force Technology Limited Company" },
{ "A89B10", "inMotion Ltd." },
{ "888C19", "Brady Corp Asia Pacific Ltd" },
{ "747DB6", "Aliwei Communications, Inc" },
{ "B41489", "Cisco Systems, Inc" },
{ "AC6F4F", "Enspert Inc" },
{ "8886A0", "Simton Technologies, Ltd." },
{ "F0C88C", "LeddarTech Inc." },
{ "68EBC5", "Angstrem Telecom" },
{ "448C52", "KTIS CO., Ltd" },
{ "686359", "Advanced Digital Broadcast SA" },
{ "B8E779", "9Solutions Oy" },
{ "4018D7", "Smartronix, Inc." },
{ "18922C", "Virtual Instruments" },
{ "F80F84", "Natural Security SAS" },
{ "FCA13E", "Samsung Electronics" },
{ "BC4760", "Samsung Electronics Co.,Ltd" },
{ "EC9ECD", "Artesyn Embedded Technologies" },
{ "303955", "Shenzhen Jinhengjia Electronic Co., Ltd." },
{ "FC5B24", "Weibel Scientific A/S" },
{ "34B571", "PLDS" },
{ "A862A2", "JIWUMEDIA CO., LTD." },
{ "984E97", "Starlight Marketing (H. K.) Ltd." },
{ "E4E0C5", "Samsung Electronics Co., LTD" },
{ "7C6ADB", "SafeTone Technology Co.,Ltd" },
{ "EC986C", "Lufft Mess- und Regeltechnik GmbH" },
{ "B0518E", "Holl technology CO.Ltd." },
{ "DCDECA", "Akyllor" },
{ "A071A9", "Nokia Corporation" },
{ "8065E9", "BenQ Corporation" },
{ "845DD7", "Shenzhen Netcom Electronics Co.,Ltd" },
{ "447DA5", "VTION INFORMATION TECHNOLOGY (FUJIAN) CO.,LTD" },
{ "0CCDD3", "EASTRIVER TECHNOLOGY CO., LTD." },
{ "B8E589", "Payter BV" },
{ "C89C1D", "Cisco Systems, Inc" },
{ "503DE5", "Cisco Systems, Inc" },
{ "801440", "Sunlit System Technology Corp" },
{ "948D50", "Beamex Oy Ab" },
{ "94E226", "D. ORtiz Consulting, LLC" },
{ "74A722", "LG Electronics" },
{ "78D6F0", "Samsung Electro Mechanics" },
{ "E8E732", "Alcatel-Lucent" },
{ "386E21", "Wasion Group Ltd." },
{ "D8C99D", "EA DISPLAY LIMITED" },
{ "CCFC6D", "RIZ TRANSMITTERS" },
{ "AC80D6", "Hexatronic AB" },
{ "9CF938", "AREVA NP GmbH" },
{ "500E6D", "TrafficCast International" },
{ "1CFEA7", "IDentytech Solutins Ltd." },
{ "D0B53D", "SEPRO ROBOTIQUE" },
{ "A0DE05", "JSC Irbis-T" },
{ "8895B9", "Unified Packet Systems Crop" },
{ "78593E", "RAFI GmbH & Co.KG" },
{ "684352", "Bhuu Limited" },
{ "3CC0C6", "d&b audiotechnik GmbH" },
{ "F8DAF4", "Taishan Online Technology Co., Ltd." },
{ "D8E3AE", "CIRTEC MEDICAL SYSTEMS" },
{ "A83944", "Actiontec Electronics, Inc" },
{ "FC1FC0", "EURECAM" },
{ "4891F6", "Shenzhen Reach software technology CO.,LTD" },
{ "EC14F6", "BioControl AS" },
{ "B8D06F", "GUANGZHOU HKUST FOK YING TUNG RESEARCH INSTITUTE" },
{ "B4C44E", "VXL eTech Pvt Ltd" },
{ "F0933A", "NxtConect" },
{ "6052D0", "FACTS Engineering " },
{ "8C278A", "Vocollect Inc" },
{ "FCAF6A", "Qulsar Inc" },
{ "ECE555", "Hirschmann Automation" },
{ "DCD0F7", "Bentek Systems Ltd." },
{ "D0574C", "Cisco Systems, Inc" },
{ "8818AE", "Tamron Co., Ltd" },
{ "20D607", "Nokia Corporation" },
{ "58DB8D", "Fast Co., Ltd." },
{ "18EF63", "Cisco Systems, Inc" },
{ "CCCE40", "Janteq Corp" },
{ "8C4DEA", "Cerio Corporation" },
{ "ECFAAA", "The IMS Company" },
{ "CC55AD", "RIM" },
{ "F0F7B3", "Phorm" },
{ "E8757F", "FIRS Technologies(Shenzhen) Co., Ltd" },
{ "C83EA7", "KUNBUS GmbH" },
{ "A8D3C8", "Wachendorff Elektronik  GmbH & Co. KG" },
{ "E0CF2D", "Gemintek Corporation" },
{ "68BDAB", "Cisco Systems, Inc" },
{ "9CADEF", "Obihai Technology, Inc." },
{ "D08999", "APCON, Inc." },
{ "4454C0", "Thompson Aerospace" },
{ "B4A4E3", "Cisco Systems, Inc" },
{ "90903C", "TRISON TECHNOLOGY CORPORATION" },
{ "94DD3F", "A+V Link Technologies, Corp." },
{ "C8EE08", "TANGTOP TECHNOLOGY CO.,LTD" },
{ "7472F2", "Chipsip Technology Co., Ltd." },
{ "C0CB38", "Hon Hai Precision Ind. Co.,Ltd." },
{ "5CD998", "D-Link Corporation" },
{ "D46CDA", "CSM GmbH" },
{ "60EB69", "Quanta computer Inc." },
{ "C4F464", "Spica international" },
{ "74911A", "Ruckus Wireless" },
{ "544A05", "wenglor sensoric gmbh" },
{ "5CCA32", "Theben AG" },
{ "84C7A9", "C3PO S.A." },
{ "F8AC6D", "Deltenna Ltd" },
{ "641084", "HEXIUM Technical Development Co., Ltd." },
{ "C416FA", "Prysm Inc" },
{ "E0C286", "Aisai Communication Technology Co., Ltd." },
{ "D84B2A", "Cognitas Technologies, Inc." },
{ "684B88", "Galtronics Telemetry Inc." },
{ "842914", "EMPORIA TELECOM Produktions- und VertriebsgesmbH & Co KG" },
{ "4C8B55", "Grupo Digicon" },
{ "04A3F3", "Emicon" },
{ "F866F2", "Cisco Systems, Inc" },
{ "7C55E7", "YSI, Inc." },
{ "C02BFC", "iNES. applied informatics GmbH" },
{ "AC34CB", "Shanhai GBCOM Communication Technology Co. Ltd" },
{ "D4A928", "GreenWave Reality Inc" },
{ "9CFFBE", "OTSL Inc." },
{ "2CD1DA", "Sanjole, Inc." },
{ "100E2B", "NEC CASIO Mobile Communications" },
{ "445EF3", "Tonalite Holding B.V." },
{ "100C24", "pomdevices, LLC" },
{ "58F6BF", "Kyoto University" },
{ "B407F9", "SAMSUNG ELECTRO-MECHANICS" },
{ "7CED8D", "Microsoft" },
{ "1880F5", "Alcatel-Lucent Shanghai Bell Co., Ltd " },
{ "54FDBF", "Scheidt & Bachmann GmbH" },
{ "B40EDC", "LG-Ericsson Co.,Ltd." },
{ "A4D1D1", "ECOtality North America" },
{ "C8D5FE", "Shenzhen Zowee Technology Co., Ltd" },
{ "C49313", "100fio networks technology llc" },
{ "A4A80F", "Shenzhen Coship Electronics Co., Ltd." },
{ "B8921D", "BG T&A" },
{ "48FCB8", "Woodstream Corporation" },
{ "548922", "Zelfy Inc" },
{ "F8C091", "Highgates Technology" },
{ "6C5CDE", "SunReports, Inc." },
{ "241F2C", "Calsys, Inc." },
{ "284846", "GridCentric Inc." },
{ "58B9E1", "Crystalfontz America, Inc." },
{ "646707", "Beijing Omnific Technology, Ltd." },
{ "D4000D", "Phoenix Broadband Technologies, LLC." },
{ "E87AF3", "S5 Tech S.r.l." },
{ "40C7C9", "Naviit Inc." },
{ "A0A763", "Polytron Vertrieb GmbH" },
{ "D496DF", "SUNGJIN C&T CO.,LTD" },
{ "D07DE5", "Forward Pay Systems, Inc." },
{ "7CEF18", "Creative Product Design Pty. Ltd." },
{ "FCD4F6", "Messana Air.Ray Conditioning s.r.l." },
{ "0CD696", "Amimon Ltd" },
{ "B43741", "Consert, Inc." },
{ "F8FB2F", "Santur Corporation" },
{ "2CCD43", "Summit Technology Group" },
{ "6C8D65", "Wireless Glue Networks, Inc." },
{ "CCFCB1", "Wireless Technology, Inc." },
{ "CC5C75", "Weightech Com. Imp. Exp. Equip. Pesagem Ltda" },
{ "A098ED", "Shandong Intelligent Optical Communication Development Co., Ltd." },
{ "34C69A", "Enecsys Ltd" },
{ "502A8B", "Telekom Research and Development Sdn Bhd" },
{ "F88DEF", "Tenebraex" },
{ "EC43E6", "AWCER Ltd." },
{ "F0EC39", "Essec" },
{ "5849BA", "Chitai Electronic Corp." },
{ "181714", "DAEWOOIS" },
{ "80B289", "Forworld Electronics Ltd." },
{ "14A62C", "S.M. Dezac S.A." },
{ "C80AA9", "Quanta Computer Inc." },
{ "A8F470", "Fujian Newland Communication Science Technologies Co.,Ltd." },
{ "DC1D9F", "U & B tech" },
{ "081651", "SHENZHEN SEA STAR TECHNOLOGY CO.,LTD" },
{ "DC49C9", "CASCO SIGNAL LTD" },
{ "B09134", "Taleo" },
{ "A863DF", "DISPLAIRE CORPORATION" },
{ "104369", "Soundmax Electronic Limited " },
{ "C06C0F", "Dobbs Stanford" },
{ "5475D0", "Cisco Systems, Inc" },
{ "BC6A16", "tdvine" },
{ "C8EF2E", "Beijing Gefei Tech. Co., Ltd " },
{ "98DCD9", "UNITEC Co., Ltd." },
{ "30525A", "NST Co., LTD" },
{ "6089B7", "KAEL MÜHENDİSLİK ELEKTRONİK TİCARET SANAYİ LİMİTED ŞİRKETİ" },
{ "2CA780", "True Technologies Inc." },
{ "545FA9", "Teracom Limited" },
{ "ECC882", "Cisco Systems, Inc" },
{ "A0B9ED", "Skytap" },
{ "502DF4", "Phytec Messtechnik GmbH" },
{ "38E8DF", "b gmbh medien + datenbanken" },
{ "10189E", "Elmo Motion Control" },
{ "88FD15", "LINEEYE CO., LTD" },
{ "10445A", "Shaanxi Hitech Electronic Co., LTD" },
{ "60B3C4", "Elber Srl" },
{ "04C880", "Samtec Inc" },
{ "884B39", "Siemens AG, Healthcare Sector" },
{ "44C233", "Guangzhou Comet Technology Development Co.Ltd" },
{ "B482FE", "ASKEY COMPUTER CORP" },
{ "307C30", "RIM" },
{ "BC4E3C", "CORE STAFF CO., LTD." },
{ "80BAAC", "TeleAdapt Ltd" },
{ "FC4463", "Universal Audio, Inc" },
{ "F06853", "Integrated Corporation" },
{ "10E6AE", "Source Technologies, LLC" },
{ "A4ADB8", "Vitec Group, Camera Dynamics Ltd" },
{ "90A2DA", "GHEO SA" },
{ "C41ECE", "HMI Sources Ltd." },
{ "BCD5B6", "d2d technologies" },
{ "1C8F8A", "Phase Motion Control SpA" },
{ "A4B1EE", "H. ZANDER GmbH & Co. KG" },
{ "486FD2", "StorSimple Inc" },
{ "D4F143", "IPROAD.,Inc" },
{ "CC5459", "OnTime Networks AS" },
{ "3CB17F", "Wattwatchers Pty Ld" },
{ "00DB45", "THAMWAY CO.,LTD." },
{ "A0231B", "TeleComp R&D Corp." },
{ "94C4E9", "PowerLayer Microsystems HongKong Limited" },
{ "8843E1", "Cisco Systems, Inc" },
{ "B4ED19", "Pie Digital, Inc." },
{ "888717", "CANON INC." },
{ "E0271A", "TTC Next-generation Home Network System WG" },
{ "84C727", "Gnodal Ltd" },
{ "E4AB46", "UAB Selteka" },
{ "D479C3", "Cameronet GmbH & Co. KG" },
{ "945B7E", "TRILOBIT LTDA." },
{ "E85B5B", "LG ELECTRONICS INC" },
{ "20D906", "Iota, Inc." },
{ "404022", "ZIV" },
{ "70F395", "Universal Global Scientific Industrial Co., Ltd." },
{ "74F726", "Neuron Robotics" },
{ "18FC9F", "Changhe Electronics Co., Ltd." },
{ "A438FC", "Plastic Logic" },
{ "601D0F", "Midnite Solar" },
{ "50A6E3", "David Clark Company" },
{ "549A16", "Uzushio Electric Co.,Ltd." },
{ "4001C6", "3COM EUROPE LTD" },
{ "608D17", "Sentrus Government Systems Division, Inc" },
{ "24BF74", "Private" },
{ "80912A", "Lih Rong electronic Enterprise Co., Ltd." },
{ "8038FD", "LeapFrog Enterprises, Inc." },
{ "7072CF", "EdgeCore Networks" },
{ "803B9A", "ghe-ces electronic ag" },
{ "9CCD82", "CHENG UEI PRECISION INDUSTRY CO.,LTD" },
{ "C8AACC", "Private" },
{ "008CFA", "Inventec Corporation" },
{ "003D41", "Hatteland Computer AS" },
{ "087618", "ViE Technologies Sdn. Bhd." },
{ "A4AD00", "Ragsdale Technology" },
{ "2C1984", "IDN Telecom, Inc." },
{ "3863F6", "3NOD MULTIMEDIA(SHENZHEN)CO.,LTD" },
{ "DCE2AC", "Lumens Digital Optics Inc." },
{ "98D88C", "Nortel Networks" },
{ "C8873B", "Net Optics" },
{ "6CBEE9", "Alcatel-Lucent-IPD" },
{ "B0E97E", "Advanced Micro Peripherals" },
{ "D44CA7", "Informtekhnika & Communication, LLC" },
{ "202CB7", "Kong Yue Electronics & Information Industry (Xinhui) Ltd." },
{ "68CC9C", "Mine Site Technologies" },
{ "04B466", "BSP Co., Ltd." },
{ "E41F13", "IBM Corp" },
{ "00271B", "Alec Sicherheitssysteme GmbH" },
{ "002718", "Suzhou NEW SEAUNION Video Technology Co.,Ltd" },
{ "002713", "Universal Global Scientific Industrial Co., Ltd." },
{ "00270C", "Cisco Systems, Inc" },
{ "00270B", "Adura Technologies" },
{ "002705", "Sectronic" },
{ "002706", "YOISYS" },
{ "0026F9", "S.E.M. srl" },
{ "0026F3", "SMC Networks" },
{ "688540", "IGI Mobile, Inc." },
{ "6465C0", "Nuvon, Inc" },
{ "F0DE71", "Shanghai EDO Technologies Co.,Ltd." },
{ "A00798", "Samsung Electronics" },
{ "28FBD3", "Ragentek Technology Group" },
{ "7C1EB3", "2N TELEKOMUNIKACE a.s." },
{ "146E0A", "Private" },
{ "1045F8", "LNT-Automation GmbH" },
{ "644F74", "LENUS Co., Ltd." },
{ "787F62", "GiK mbH" },
{ "D4AAFF", "MICRO WORLD " },
{ "C4FCE4", "DishTV NZ Ltd" },
{ "0CD7C2", "Axium Technologies, Inc." },
{ "40F52E", "Leica Microsystems (Schweiz) AG" },
{ "C02250", "Private" },
{ "64BC11", "CombiQ AB" },
{ "4097D1", "BK Electronics cc" },
{ "68AAD2", "DATECS LTD.," },
{ "0026EC", "Legrand Home Systems, Inc" },
{ "0026E6", "Visionhitech Co., Ltd." },
{ "0026E0", "ASITEQ" },
{ "0026DA", "Universal Media Corporation /Slovakia/ s.r.o." },
{ "0026D3", "Zeno Information System" },
{ "0026D4", "IRCA SpA" },
{ "0026CD", "PurpleComm, Inc." },
{ "10880F", "Daruma Telecomunicações e Informática S.A." },
{ "4C4B68", "Mobile Device, Inc. " },
{ "94BA31", "Visiontec da Amazônia Ltda." },
{ "F45FF7", "DQ Technology Inc." },
{ "60F13D", "JABLOCOM s.r.o." },
{ "0CEF7C", "AnaCom Inc" },
{ "E08FEC", "REPOTEC CO., LTD." },
{ "D0D286", "Beckman Coulter K.K." },
{ "1C0FCF", "Sypro Optics GmbH" },
{ "0025AB", "AIO LCD PC BU / TPV" },
{ "0025A4", "EuroDesign embedded technologies GmbH" },
{ "00259D", "Private" },
{ "002598", "Zhong Shan City Litai Electronic Industrial Co. Ltd" },
{ "002591", "NEXTEK, Inc." },
{ "00258C", "ESUS ELEKTRONIK SAN. VE DIS. TIC. LTD. STI." },
{ "002587", "Vitality, Inc." },
{ "002581", "x-star networks Inc." },
{ "002582", "Maksat Technologies (P) Ltd" },
{ "002578", "JSC Concern Sozvezdie" },
{ "00257D", "PointRed Telecom Private Ltd." },
{ "002577", "D-BOX Technologies" },
{ "002571", "Zhejiang Tianle Digital Electric Co.,Ltd" },
{ "00256A", "inIT - Institut Industrial IT" },
{ "002565", "Vizimax Inc." },
{ "00255E", "Shanghai Dare Technologies Co.,Ltd." },
{ "002558", "MPEDIA" },
{ "002635", "Bluetechnix GmbH" },
{ "00262F", "HAMAMATSU TOA ELECTRONICS" },
{ "002623", "JRD Communication Inc" },
{ "002628", "companytec automação e controle ltda." },
{ "00261C", "NEOVIA INC." },
{ "002615", "Teracom Limited" },
{ "002616", "Rosemount Inc." },
{ "002610", "Apacewave Technologies" },
{ "002609", "Phyllis Co., Ltd." },
{ "00268C", "StarLeaf Ltd." },
{ "002692", "Mitsubishi Electric Co." },
{ "002686", "Quantenna Communcations, Inc." },
{ "002680", "SIL3 Pty.Ltd" },
{ "00267F", "Zenterio AB" },
{ "00267A", "wuhan hongxin telecommunication technologies co.,ltd" },
{ "002679", "Euphonic Technologies, Inc." },
{ "002673", "RICOH COMPANY,LTD." },
{ "00266D", "MobileAccess Networks" },
{ "0025D6", "The Kroger Co." },
{ "0025CA", "LS Research, LLC" },
{ "0025C3", "Nortel Networks" },
{ "0025BE", "Tektrap Systems Inc." },
{ "0025BD", "Italdata Ingegneria dell'Idea S.p.A." },
{ "0025B7", "Costar  electronics, inc.," },
{ "0025B0", "Schmartz Inc" },
{ "002552", "VXI CORPORATION" },
{ "002546", "Cisco Systems, Inc" },
{ "002545", "Cisco Systems, Inc" },
{ "002535", "Minimax GmbH & Co KG" },
{ "002532", "Digital Recorders" },
{ "00252B", "Stirling Energy Systems" },
{ "0025FD", "OBR Centrum Techniki Morskiej S.A." },
{ "002603", "Shenzhen Wistar Technology Co., Ltd" },
{ "0025F3", "Nordwestdeutsche Zählerrevision" },
{ "0025EC", "Humanware" },
{ "0025E2", "Everspring Industry Co., Ltd." },
{ "0025DD", "SUNNYTEK INFORMATION CO., LTD." },
{ "002667", "CARECOM CO.,LTD." },
{ "002660", "Logiways" },
{ "002656", "Sansonic Electronics USA" },
{ "002653", "DaySequerra Corporation" },
{ "00264C", "Shanghai DigiVision Technology Co., Ltd." },
{ "002647", "WFE TECHNOLOGY CORP." },
{ "00263B", "Onbnetech" },
{ "0026C1", "ARTRAY CO., LTD." },
{ "0026B5", "ICOMM Tele Ltd" },
{ "0026AF", "Duelco A/S" },
{ "0026AB", "SEIKO EPSON CORPORATION" },
{ "0026A5", "MICROROBOT.CO.,LTD" },
{ "00269F", "Private" },
{ "002699", "Cisco Systems, Inc" },
{ "002489", "Vodafone Omnitel N.V." },
{ "00248E", "Infoware ZRt." },
{ "002490", "Samsung Electronics Co.,LTD" },
{ "002482", "Ruckus Wireless" },
{ "002476", "TAP.tv" },
{ "00246F", "Onda Communication spa" },
{ "00246A", "Solid Year Co., Ltd." },
{ "0023FA", "RG Nets, Inc." },
{ "0023FF", "Beijing HTTC Technology Ltd." },
{ "0023F4", "Masternaut" },
{ "0023EA", "Cisco Systems, Inc" },
{ "0023E4", "IPnect co. ltd." },
{ "0023DE", "Ansync Inc." },
{ "0023D1", "TRG" },
{ "0023CB", "Shenzhen Full-join Technology Co.,Ltd" },
{ "0023D2", "Inhand Electronics, Inc." },
{ "0023D7", "Samsung Electronics" },
{ "0024B4", "ESCATRONIC GmbH" },
{ "0024AF", "EchoStar Technologies" },
{ "0024A8", "ProCurve Networking by HP" },
{ "0024AD", "Adolf Thies Gmbh & Co. KG" },
{ "00249C", "Bimeng Comunication System Co. Ltd" },
{ "002526", "Genuine Technologies Co., Ltd." },
{ "002525", "CTERA Networks Ltd." },
{ "002520", "SMA Railway Technology GmbH" },
{ "00251B", "Philips CareServant" },
{ "002516", "Integrated Design Tools, Inc." },
{ "00250F", "On-Ramp Wireless, Inc." },
{ "002503", "IBM Corp" },
{ "00250A", "Security Expert Co. Ltd" },
{ "0024DD", "Centrak, Inc." },
{ "0024D8", "IlSung Precision" },
{ "0024CC", "Fascinations Toys and Gifts, Inc." },
{ "0024D1", "Thomson Inc." },
{ "0024CA", "Tobii Technology AB" },
{ "0024C5", "Meridian Audio Limited" },
{ "0024B9", "Wuhan Higheasy Electronic Technology Development Co.Ltd" },
{ "002425", "Shenzhenshi chuangzhicheng Technology Co.,Ltd" },
{ "002419", "Private" },
{ "002412", "Benign Technologies Co, Ltd." },
{ "00240C", "DELEC GmbH" },
{ "002406", "Pointmobile" },
{ "0023F9", "Double-Take Software, INC." },
{ "002463", "Phybridge Inc" },
{ "002459", "ABB Automation products GmbH" },
{ "00245E", "Hivision Co.,ltd" },
{ "002451", "Cisco Systems, Inc" },
{ "00244C", "Solartron Metrology Ltd" },
{ "002445", "CommScope Canada Inc." },
{ "00243F", "Storwize, Inc." },
{ "002440", "Halo Monitoring, Inc." },
{ "00243B", "CSSI (S) Pte Ltd" },
{ "0024FC", "QuoPin Co., Ltd." },
{ "0024F7", "Cisco Systems, Inc" },
{ "0024F0", "Seanodes" },
{ "0024E9", "Samsung Electronics Co., Ltd., Storage System Division" },
{ "0024EB", "ClearPath Networks, Inc." },
{ "0024E4", "Withings" },
{ "002435", "WIDE CORPORATION" },
{ "00242F", "Micron" },
{ "00241F", "DCT-Delta GmbH" },
{ "0023C5", "Radiation Safety and Control Services Inc" },
{ "0023C4", "Lux Lumen" },
{ "0023B8", "Sichuan Jiuzhou Electronic Technology Co.,Ltd" },
{ "0023BF", "Mainpine, Inc." },
{ "0023B2", "Intelligent Mechatronic Systems Inc" },
{ "0023AC", "Cisco Systems, Inc" },
{ "0023A0", "Hana CNS Co., LTD." },
{ "0023A5", "SageTV, LLC" },
{ "0022B6", "Superflow Technologies Group" },
{ "0022A3", "California Eastern Laboratories" },
{ "00229E", "Social Aid Research Co., Ltd." },
{ "002291", "Cisco Systems, Inc" },
{ "002292", "Cinetal" },
{ "002297", "XMOS Semiconductor" },
{ "00228B", "Kensington Computer Products Group" },
{ "002284", "DESAY A&V SCIENCE AND TECHNOLOGY CO.,LTD" },
{ "00227F", "Ruckus Wireless" },
{ "002277", "NEC Australia Pty Ltd" },
{ "00226D", "Shenzhen GIEC Electronics Co., Ltd." },
{ "002263", "Koos Technical Services, Inc." },
{ "002267", "Nortel Networks" },
{ "002259", "Guangzhou New Postcom Equipment Co.,Ltd." },
{ "0022E4", "APASS TECHNOLOGY CO., LTD." },
{ "0022DD", "Protecta Electronics Ltd" },
{ "0022D8", "Shenzhen GST Security and Safety Technology Limited" },
{ "0022D1", "Albrecht Jung GmbH & Co. KG" },
{ "0022C3", "Zeeport Technology Inc." },
{ "0022C7", "SEGGER Microcontroller GmbH & Co. KG" },
{ "0022BD", "Cisco Systems, Inc" },
{ "002344", "Objective Interface Systems, Inc." },
{ "002343", "TEM AG" },
{ "00233E", "Alcatel-Lucent-IPD" },
{ "002337", "Global Star Solutions ULC" },
{ "00232B", "IRD A/S" },
{ "00231C", "Fourier Systems Ltd." },
{ "00231B", "Danaher Motion - Kollmorgen" },
{ "00239F", "Institut für Prüftechnik" },
{ "002399", "VD Division, Samsung Electronics Co." },
{ "002393", "AJINEXTEK" },
{ "00238F", "NIDEC COPAL CORPORATION" },
{ "00238B", "Quanta Computer Inc." },
{ "002385", "ANTIPODE" },
{ "00237E", "ELSTER GMBH" },
{ "00237F", "PLANTRONICS, INC." },
{ "002379", "Union Business Machines Co. Ltd." },
{ "002253", "Entorian Technologies" },
{ "002250", "Point Six Wireless, LLC" },
{ "002249", "HOME MULTIENERGY SL" },
{ "00224A", "RAYLASE AG" },
{ "002240", "Universal Telecom S/A" },
{ "00222D", "SMC Networks Inc." },
{ "00222E", "maintech GmbH" },
{ "002363", "Zhuhai RaySharp Technology Co., Ltd." },
{ "002364", "Power Instruments Pte Ltd" },
{ "002369", "Cisco-Linksys, LLC" },
{ "002370", "Snell" },
{ "00235D", "Cisco Systems, Inc" },
{ "002356", "Packet Forensics LLC" },
{ "00234A", "Private" },
{ "002313", "Qool Technologies Ltd." },
{ "00230D", "Nortel Networks" },
{ "002301", "Witron Technology Limited" },
{ "0022F7", "Conceptronic" },
{ "0022EA", "Rustelcom Inc." },
{ "0022F0", "3 Greens Aviation Limited" },
{ "0022E9", "ProVision Communications" },
{ "00211C", "Cisco Systems, Inc" },
{ "002117", "Tellord" },
{ "002110", "Clearbox Systems" },
{ "002106", "RIM Testing Services" },
{ "001FFF", "Respironics, Inc." },
{ "001FFE", "HPN Supply Chain" },
{ "001FF8", "Siemens AG, Sector Industry, Drive Technologies, Motion Control Systems" },
{ "001FFD", "Indigo Mobile Technologies Corp." },
{ "002221", "ITOH DENKI CO,LTD." },
{ "00221B", "Morega Systems" },
{ "002220", "Mitac Technology Corp" },
{ "002227", "uv-electronic GmbH" },
{ "002214", "RINNAI KOREA" },
{ "00220E", "Indigo Security Co., Ltd." },
{ "002208", "Certicom Corp" },
{ "002201", "Aksys Networks Inc" },
{ "0021F7", "HPN Supply Chain" },
{ "0021A0", "Cisco Systems, Inc" },
{ "00219C", "Honeywld Technology Corp." },
{ "002192", "Baoding Galaxy Electronic Technology  Co.,Ltd" },
{ "00218C", "TopControl GMBH" },
{ "002186", "Universal Global Scientific Industrial Co., Ltd" },
{ "00217F", "Intraco Technology Pte Ltd" },
{ "00217A", "Sejin Electron, Inc." },
{ "002179", "IOGEAR, Inc." },
{ "002173", "Ion Torrent Systems, Inc." },
{ "001FC3", "SmartSynch, Inc" },
{ "001FC8", "Up-Today Industrial Co., Ltd." },
{ "001FC1", "Hanlong Technology Co.,LTD" },
{ "001FC2", "Jow Tong Technology Co Ltd" },
{ "001FBC", "EVGA Corporation" },
{ "001FB0", "TimeIPS, Inc." },
{ "001FB5", "I/O Interconnect Inc." },
{ "001FA9", "Atlanta DTH, Inc." },
{ "0021F1", "Tutus Data AB" },
{ "0021F2", "EASY3CALL Technology Limited" },
{ "0021EB", "ESP SYSTEMS, LLC" },
{ "0021E5", "Display Solution AG" },
{ "0021E4", "I-WIN" },
{ "0021DF", "Martin Christ GmbH" },
{ "0021D2", "Samsung Electronics Co.,Ltd" },
{ "0021D8", "Cisco Systems, Inc" },
{ "0021CC", "Flextronics International" },
{ "001FF1", "Paradox Hellas S.A." },
{ "001FEC", "Synapse Électronique" },
{ "001FE5", "In-Circuit GmbH" },
{ "001FD9", "RSD Communications Ltd" },
{ "001FD4", "4IPNET, INC." },
{ "001FCF", "MSI Technology GmbH" },
{ "00213F", "A-Team Technology Ltd." },
{ "002139", "Escherlogic Inc." },
{ "002134", "Brandywine Communications" },
{ "00212F", "Phoebe Micro Inc." },
{ "002129", "Cisco-Linksys, LLC" },
{ "00212A", "Audiovox Corporation" },
{ "002123", "Aerosat Avionics" },
{ "00216D", "Soltech Co., Ltd." },
{ "00216C", "ODVA" },
{ "002167", "HWA JIN T&I Corp." },
{ "002160", "Hidea Solutions Co. Ltd." },
{ "002154", "D-TACQ Solutions Ltd" },
{ "00214D", "Guangzhou Skytone Transmission Technology Com. Ltd." },
{ "002148", "Kaco Solar Korea" },
{ "0021C5", "3DSP Corp" },
{ "0021BF", "Hitachi High-Tech Control Systems Corporation" },
{ "0021C0", "Mobile Appliance, Inc." },
{ "0021B9", "Universal Devices Inc." },
{ "0021B3", "Ross Controls" },
{ "0021B2", "Fiberblaze A/S" },
{ "0021AD", "Nordic ID Oy" },
{ "0021A6", "Videotec Spa" },
{ "001F16", "Wistron Corporation" },
{ "001F11", "OPENMOKO, INC." },
{ "001F0B", "Federal State Unitary Enterprise Industrial UnionElectropribor" },
{ "001EFF", "Mueller-Elektronik GmbH & Co. KG" },
{ "001F06", "Integrated Dispatch Solutions" },
{ "001F05", "iTAS Technology Corp." },
{ "001EF3", "From2" },
{ "001EF8", "Emfinity Inc." },
{ "001F7A", "WiWide Inc." },
{ "001F70", "Botik Technologies LTD" },
{ "001F75", "GiBahn Media" },
{ "001F64", "Beijing Autelan Technology Inc." },
{ "001F6B", "LG Electronics" },
{ "001F5E", "Dyna Technology Co.,Ltd." },
{ "001F58", "EMH Energiemesstechnik GmbH" },
{ "001F4C", "Roseman Engineering Ltd" },
{ "001F51", "HD Communications Corp" },
{ "001F4B", "Lineage Power" },
{ "001F9F", "Thomson Telecom Belgium" },
{ "001F93", "Xiotech Corporation" },
{ "001F98", "DAIICHI-DENTSU LTD." },
{ "001F8C", "CCS Inc." },
{ "001F8A", "Ellion Digital Inc." },
{ "001F83", "Teleplan Technology Services Sdn Bhd" },
{ "001E37", "Universal Global Scientific Industrial Co., Ltd." },
{ "001E30", "Shireen Inc" },
{ "001E2B", "Radio Systems Design, Inc." },
{ "001E24", "Zhejiang Bell Technology Co.,ltd" },
{ "001E18", "Radio Activity srl" },
{ "001E1D", "East Coast Datacom, Inc." },
{ "001E1E", "Honeywell Life Safety" },
{ "001E13", "Cisco Systems, Inc" },
{ "001E0E", "MAXI VIEW HOLDINGS LIMITED" },
{ "001E60", "Digital Lighting Systems, Inc" },
{ "001E59", "Silicon Turnkey Express, LLC" },
{ "001E54", "TOYO ELECTRIC Corporation" },
{ "001E4D", "Welkin Sciences, LLC" },
{ "001E48", "Wi-Links" },
{ "001E43", "AISIN AW CO.,LTD." },
{ "001E3E", "KMW Inc." },
{ "001EC3", "Kozio, Inc." },
{ "001EBC", "WINTECH AUTOMATION CO.,LTD." },
{ "001EB7", "TBTech, Co., Ltd." },
{ "001EB0", "ImesD Electronica S.L." },
{ "001EA5", "ROBOTOUS, Inc." },
{ "001EAB", "TeleWell Oy" },
{ "001E9E", "ddm hopt + schuler Gmbh + Co. KG" },
{ "001E99", "Vantanol Industrial Corporation" },
{ "001F36", "Bellwin Information Co. Ltd.," },
{ "001F35", "AIR802 LLC" },
{ "001F30", "Travelping" },
{ "001F23", "Interacoustics" },
{ "001F24", "DIGITVIEW TECHNOLOGY CO., LTD." },
{ "001F1D", "Atlas Material Testing Technology LLC" },
{ "001E92", "JEULIN S.A." },
{ "001E89", "CRFS Limited" },
{ "001E84", "Pika Technologies Inc." },
{ "001E7D", "Samsung Electronics Co.,Ltd" },
{ "001E83", "LAN/MAN Standards Association (LMSC)" },
{ "001E6C", "Opaque Systems" },
{ "001EE6", "Shenzhen Advanced Video Info-Tech Co., Ltd." },
{ "001EE0", "Urmet Domus SpA" },
{ "001EDB", "Giken Trastem Co., Ltd." },
{ "001ED6", "Alentec & Orion AB" },
{ "001ECF", "PHILIPS ELECTRONICS UK LTD" },
{ "001ECA", "Nortel" },
{ "001C96", "Linkwise Technology Pte Ltd" },
{ "001C91", "Gefen Inc." },
{ "001C8A", "Cirrascale Corporation" },
{ "001C84", "STL Solution Co.,Ltd." },
{ "001C80", "New Business Division/Rhea-Information CO., LTD." },
{ "001C76", "The Wandsworth Group Ltd" },
{ "001C6F", "Emfit Ltd" },
{ "001C71", "Emergent Electronics" },
{ "001C70", "NOVACOMM LTDA" },
{ "001C6A", "Weiss Engineering Ltd." },
{ "001D59", "Mitra Energy & Infrastructure" },
{ "001D52", "Defzone B.V." },
{ "001D4C", "Alcatel-Lucent" },
{ "001D48", "Sensor-Technik Wiedemann GmbH" },
{ "001D41", "Hardy Instruments" },
{ "001D42", "Nortel" },
{ "001D3C", "Muscle Corporation" },
{ "001D30", "YX Wireless S.A." },
{ "001D35", "Viconics Electronics Inc." },
{ "001D2F", "QuantumVision Corporation" },
{ "001CD3", "ZP Engineering SEL" },
{ "001CCE", "By Techdesign" },
{ "001CC7", "Rembrandt Technologies, LLC d/b/a REMSTREAM" },
{ "001CC2", "Part II Research, Inc." },
{ "001CBB", "MusicianLink" },
{ "001CB1", "Cisco Systems, Inc" },
{ "001CB7", "USC DigiArk Corporation" },
{ "001CA3", "Terra" },
{ "001CA5", "Zygo Corporation" },
{ "001CAA", "Bellon Pty Ltd" },
{ "001C9D", "Liecthi AG" },
{ "001DCA", "PAV Electronics Limited" },
{ "001DC4", "AIOI Systems Co., Ltd." },
{ "001DC3", "RIKOR TV, Ltd" },
{ "001DB1", "Crescendo Networks" },
{ "001DB2", "HOKKAIDO ELECTRIC ENGINEERING CO.,LTD." },
{ "001DB7", "Tendril Networks, Inc." },
{ "001DAD", "Sinotech Engineering Consultants, Inc.  Geotechnical Enginee" },
{ "001DA8", "Takahata Electronics Co.,Ltd" },
{ "001DA7", "Seamless Internet" },
{ "001DA1", "Cisco Systems, Inc" },
{ "001D9A", "GODEX INTERNATIONAL CO., LTD" },
{ "001D95", "Flash, Inc." },
{ "001D8E", "Alereon, Inc." },
{ "001D87", "VigTech Labs Sdn Bhd" },
{ "001D88", "Clearwire" },
{ "001D7E", "Cisco-Linksys, LLC" },
{ "001D7D", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "001D6C", "ClariPhy Communications, Inc." },
{ "001D71", "Cisco Systems, Inc" },
{ "001D78", "Invengo Information Technology Co.,Ltd" },
{ "001D65", "Microwave Radio Communications" },
{ "001D5E", "COMING MEDIA CORP." },
{ "001D29", "Doro AB" },
{ "001D22", "Foss Analytical A/S" },
{ "001D1D", "Inter-M Corporation" },
{ "001D16", "SFR" },
{ "001D10", "LightHaus Logic, Inc." },
{ "001D0A", "Davis Instruments, Inc." },
{ "001D03", "Design Solutions Inc." },
{ "001CFE", "Quartics Inc" },
{ "001CFD", "Universal Electronics" },
{ "001CF7", "AudioScience" },
{ "001CEB", "Nortel" },
{ "001CE6", "INNES" },
{ "001CE1", "INDRA SISTEMAS, S.A." },
{ "001CDA", "Exegin Technologies Limited" },
{ "001E07", "Winy Technology Co., Ltd." },
{ "001E02", "Sougou Keikaku Kougyou Co.,Ltd." },
{ "001E01", "Renesas Technology Sales Co., Ltd." },
{ "001DFB", "NETCLEUS Systems Corporation" },
{ "001DF4", "Magellan Technology Pty Limited" },
{ "001DEF", "TRIMM, INC." },
{ "001DE8", "Nikko Denki Tsushin Corporation(NDTC)" },
{ "001DE3", "Intuicom" },
{ "001DDD", "DAT H.K. LIMITED" },
{ "001AF8", "Copley Controls Corporation" },
{ "001AF3", "Samyoung Electronics" },
{ "001AEE", "Shenztech Ltd" },
{ "001AE2", "Cisco Systems, Inc" },
{ "001AE7", "Aztek Networks, Inc." },
{ "001AD4", "iPOX Technology Co., Ltd." },
{ "001AD6", "JIAGNSU AETNA ELECTRIC CO.,LTD" },
{ "001B97", "Violin Technologies" },
{ "001B9C", "SATEL sp. z o.o." },
{ "001B90", "Cisco Systems, Inc" },
{ "001B86", "Bosch Access Systems GmbH" },
{ "001B8B", "NEC Platforms, Ltd." },
{ "001B7F", "TMN Technologies Telecomunicacoes Ltda" },
{ "001B81", "DATAQ Instruments, Inc." },
{ "001B80", "LORD Corporation" },
{ "001B73", "DTL Broadcast Ltd" },
{ "001B6E", "Anue Systems, Inc." },
{ "001B67", "Cisco Systems Inc" },
{ "001B60", "NAVIGON AG" },
{ "001B54", "Cisco Systems, Inc" },
{ "001B48", "Shenzhen Lantech Electronics Co., Ltd." },
{ "001B4D", "Areca Technology Corporation" },
{ "001B41", "General Infinity Co.,Ltd." },
{ "001B3C", "Software Technologies Group,Inc." },
{ "001B35", "ChongQing JINOU Science & Technology Development CO.,Ltd" },
{ "001B2E", "Sinkyo Electron Inc" },
{ "001B30", "Solitech Inc." },
{ "001BC7", "StarVedia Technology Inc." },
{ "001BC6", "Strato Rechenzentrum AG" },
{ "001BC5", "IEEE REGISTRATION AUTHORITY  - Please see OUI36/MA-S public listing for more information." },
{ "001BBB", "RFTech Co.,Ltd" },
{ "001BB6", "Bird Electronic Corp." },
{ "001BAA", "XenICs nv" },
{ "001BA3", "Flexit Group GmbH" },
{ "001C63", "TRUEN" },
{ "001C57", "Cisco Systems, Inc" },
{ "001C5E", "ASTON France" },
{ "001C46", "QTUM" },
{ "001C4D", "Aplix IP Holdings Corporation" },
{ "001C3A", "Element Labs, Inc." },
{ "001C41", "scemtec Transponder Technology GmbH" },
{ "001C34", "HUEY CHIAO INTERNATIONAL CO., LTD." },
{ "001C33", "Sutron" },
{ "001BF7", "Lund IP Products AB" },
{ "001BF9", "Intellitect Water Ltd" },
{ "001BF8", "Digitrax Inc." },
{ "001BF2", "KWORLD COMPUTER CO., LTD" },
{ "001BEB", "DMP Electronics INC." },
{ "001BE6", "VR AG" },
{ "001BDF", "Iskra Sistemi d.d." },
{ "001BD3", "Panasonic Corp. AVC Company" },
{ "001BD8", "DVTel LTD" },
{ "001BCC", "KINGTEK CCTV ALLIANCE CO., LTD." },
{ "001AC8", "ISL (Instrumentation Scientifique de Laboratoire)" },
{ "001ACF", "C.T. ELETTRONICA" },
{ "001AC3", "Scientific-Atlanta, Inc" },
{ "001AB9", "PMC" },
{ "001ABE", "COMPUTER HI-TECH INC." },
{ "001AAB", "eWings s.r.l." },
{ "001AB2", "Cyber Solutions Inc." },
{ "001AB7", "Ethos Networks LTD." },
{ "001C2E", "HPN Supply Chain" },
{ "001C27", "Sunell Electronics Co." },
{ "001C22", "Aeris Elettronica s.r.l." },
{ "001C1D", "CHENZHOU GOSPELL DIGITAL TECHNOLOGY CO.,LTD" },
{ "001C18", "Sicert S.r.L." },
{ "001C0A", "Shenzhen AEE Technology Co.,Ltd." },
{ "001C05", "Nonin Medical Inc." },
{ "001BFE", "Zavio Inc." },
{ "001B29", "Avantis.Co.,Ltd" },
{ "001B23", "SimpleComTools" },
{ "001B1E", "HART Communication Foundation" },
{ "001B12", "Apprion" },
{ "001B17", "Palo Alto Networks" },
{ "001B0B", "Phidgets Inc." },
{ "001B10", "ShenZhen Kang Hui Technology Co.,ltd" },
{ "001B04", "Affinity International S.p.a" },
{ "001AFF", "Wizyoung Tech." },
{ "001AFD", "EVOLIS" },
{ "00191C", "Sensicast Systems" },
{ "00191E", "Beyondwiz Co., Ltd." },
{ "001923", "Phonex Korea Co., LTD." },
{ "00192A", "Antiope Associates" },
{ "001910", "Knick Elektronische Messgeraete GmbH & Co. KG" },
{ "001917", "Posiflex Inc." },
{ "001909", "DEVI - Danfoss A/S" },
{ "00190B", "Southern Vision Systems, Inc." },
{ "001904", "WB Electronics Sp. z o.o." },
{ "0018FF", "PowerQuattro Co." },
{ "0018FA", "Yushin Precision Equipment Co.,Ltd." },
{ "001955", "Cisco Systems, Inc" },
{ "00194E", "Ultra Electronics - TCS (Tactical Communication Systems)" },
{ "001950", "Harman Multimedia" },
{ "001949", "TENTEL  COMTECH CO., LTD." },
{ "001942", "ON SOFTWARE INTERNATIONAL LIMITED" },
{ "00193D", "GMC Guardian Mobility Corp." },
{ "001936", "STERLITE OPTICAL TECHNOLOGIES LIMITED" },
{ "00193B", "Wilibox Deliberant Group LLC" },
{ "00192F", "Cisco Systems, Inc" },
{ "001A20", "CMOTECH Co. Ltd." },
{ "001A22", "eQ-3 Entwicklung GmbH" },
{ "001A14", "Xin Hua Control Engineering Co.,Ltd." },
{ "001A0D", "HandHeld entertainment, Inc." },
{ "001A0F", "Sistemas Avanzados de Control, S.A." },
{ "001A08", "Simoco Ltd." },
{ "001A01", "Smiths Medical" },
{ "0019FC", "PT. Ufoakses Sukses Luarbiasa" },
{ "0019EF", "SHENZHEN LINNKING ELECTRONICS CO.,LTD" },
{ "0019F1", "Star Communication Network Technology Co.,Ltd" },
{ "0019F6", "Acconet (PTE) Ltd" },
{ "001A76", "SDT information Technology Co.,LTD." },
{ "001A6F", "MI.TEL s.r.l." },
{ "001A6A", "Tranzas, Inc." },
{ "001A63", "Elster Solutions, LLC," },
{ "001A5E", "Thincom Technology Co.,Ltd" },
{ "001A57", "Matrix Design Group, LLC" },
{ "001A5C", "Euchner GmbH+Co. KG" },
{ "001A50", "PheeNet Technology Corp." },
{ "001A9D", "Skipper Wireless, Inc." },
{ "001AA2", "Cisco Systems, Inc" },
{ "001A91", "FusionDynamic Ltd." },
{ "001A96", "ECLER S.A." },
{ "001A90", "Trópico Sistemas e Telecomunicações da Amazônia LTDA. " },
{ "001A8C", "Sophos Ltd" },
{ "001A85", "NV Michel Van de Wiele" },
{ "001A87", "Canhold International Limited" },
{ "001A86", "AdvancedIO Systems Inc" },
{ "0019B5", "Famar Fueguina S.A." },
{ "0019BA", "Paradox Security Systems Ltd" },
{ "0019A2", "ORDYN TECHNOLOGIES" },
{ "0019AE", "Hopling Technologies b.v." },
{ "0019A7", "ITU-T" },
{ "001996", "TurboChef Technologies Inc." },
{ "00199B", "Diversified Technical Systems, Inc." },
{ "001991", "avinfo" },
{ "00198A", "Northrop Grumman Systems Corp." },
{ "00198C", "iXSea" },
{ "001985", "IT Watchdogs, Inc" },
{ "001972", "Plexus (Xiamen) Co.,ltd" },
{ "00196B", "Danpex Corporation" },
{ "001966", "Asiarock Technology Limited" },
{ "00195C", "Innotech Corporation" },
{ "001961", "Blaupunkt  Embedded Systems GmbH" },
{ "0019DE", "MOBITEK" },
{ "0019EA", "TeraMage Technologies Co., Ltd." },
{ "0019CB", "ZyXEL Communications Corporation" },
{ "0019D0", "Cathexis" },
{ "0019D7", "FORTUNETEK CO., LTD" },
{ "0019B3", "Stanford Research Systems" },
{ "001A44", "JWTrading Co., Ltd" },
{ "001A49", "Micro Vision Co.,LTD" },
{ "001A3D", "Ajin Vision Co.,Ltd" },
{ "001A31", "SCAN COIN Industries AB" },
{ "001A38", "Sanmina-SCI" },
{ "001A2C", "SATEC Co.,LTD" },
{ "001A27", "Ubistar" },
{ "0017AE", "GAI-Tronics" },
{ "0017A2", "Camrivox Ltd." },
{ "0017A7", "Mobile Computing Promotion Consortium" },
{ "00179D", "Kelman Limited" },
{ "001791", "LinTech GmbH" },
{ "001796", "Rittmeyer AG" },
{ "001798", "Azonic Technology Co., LTD" },
{ "00178A", "DARTS TECHNOLOGIES CORP." },
{ "00177E", "Meshcom Technologies Inc." },
{ "001785", "Sparr Electronics Ltd" },
{ "001809", "CRESYN" },
{ "00180E", "Avega Systems" },
{ "001810", "IPTrade S.A." },
{ "0017F6", "Pyramid Meriden Inc." },
{ "0017FB", "FA" },
{ "0017FD", "Amulet Hotkey" },
{ "0017EF", "IBM Corp" },
{ "0017D7", "ION Geophysical Corporation Inc." },
{ "0017DC", "DAEMYUNG ZERO1" },
{ "0017DE", "Advantage Six Ltd" },
{ "0018C3", "CS Corporation" },
{ "0018CA", "Viprinet GmbH" },
{ "0018BE", "ANSA Corporation" },
{ "0018B2", "ADEUNIS RF" },
{ "0018B7", "D3 LED, LLC" },
{ "0018AB", "BEIJING LHWT MICROELECTRONICS INC." },
{ "0018A6", "Persistent Systems, LLC" },
{ "001895", "Hansun Technologies Inc." },
{ "00189A", "HANA Micron Inc." },
{ "0018E7", "Cameo Communications, INC." },
{ "0018EE", "Videology Imaging Solutions, Inc." },
{ "0018E2", "Topdata Sistemas de Automacao Ltda" },
{ "0018DB", "EPL Technology Ltd" },
{ "0018E0", "ANAVEO" },
{ "0018CF", "Baldor Electric Company" },
{ "0018D4", "Unified Display Interface SIG" },
{ "00184A", "Catcher, Inc." },
{ "00184C", "Bogen Communications" },
{ "001845", "Pulsar-Telecom LLC." },
{ "00183E", "Digilent, Inc" },
{ "001828", "e2v technologies (UK) ltd." },
{ "00182D", "Artec Design" },
{ "001821", "SINDORICOH" },
{ "001815", "GZ Technologies, Inc." },
{ "00181C", "Exterity Limited" },
{ "001772", "ASTRO Strobel Kommunikationssysteme GmbH" },
{ "001777", "Obsidian Research Corporation" },
{ "00176E", "DUCATI SISTEMI" },
{ "001762", "Solar Technology, Inc." },
{ "001769", "Cymphonix Corp" },
{ "00175D", "Dongseo system." },
{ "00175B", "ACS Solutions Switzerland Ltd." },
{ "001756", "Vinci Labs Oy" },
{ "00174F", "iCatch Inc." },
{ "0017CD", "CEC Wireless R&D Ltd." },
{ "0017D2", "THINLINX PTY LTD" },
{ "0017C6", "Cross Match Technologies Inc" },
{ "0017BA", "SEDO CO., LTD." },
{ "0017BF", "Coherent Research Limited" },
{ "0017C1", "CM Precision Technology LTD." },
{ "0017B3", "Aftek Infosys Limited" },
{ "00186A", "Global Link Digital Technology Co,.LTD" },
{ "00186F", "Setha Industria Eletronica LTDA" },
{ "001876", "WowWee Ltd." },
{ "001869", "KINGJIM" },
{ "001864", "Eaton Corporation" },
{ "00185D", "TAIGUEN TECHNOLOGY (SHEN-ZHEN) CO., LTD." },
{ "001851", "SWsoft" },
{ "001858", "TagMaster AB" },
{ "00189F", "Lenntek Corporation" },
{ "00188E", "Ekahau, Inc." },
{ "001887", "Metasystem SpA" },
{ "001889", "WinNet Solutions Limited" },
{ "00187B", "4NSYS Co. Ltd." },
{ "001661", "Novatium Solutions (P) Ltd" },
{ "001663", "KBT Mobile" },
{ "001668", "Eishin Electronics" },
{ "001662", "Liyuh Technology Ltd." },
{ "00165C", "Trackflow Ltd" },
{ "001655", "FUHO TECHNOLOGY Co., LTD" },
{ "001650", "Herley General Microwave Israel. " },
{ "0015E4", "Zimmer Elektromedizin" },
{ "0015DA", "IRITEL A.D." },
{ "0015DF", "Clivet S.p.A." },
{ "0015D3", "Pantech&Curitel Communications, Inc." },
{ "0015C7", "Cisco Systems, Inc" },
{ "0015C0", "DIGITAL TELEMEDIA CO.,LTD." },
{ "0015BA", "iba AG" },
{ "00174A", "SOCOMEC" },
{ "001743", "Deck Srl" },
{ "00173D", "Neology" },
{ "00173E", "LeucotronEquipamentos Ltda." },
{ "001738", "International Business Machines" },
{ "00172C", "TAEJIN INFOTECH" },
{ "001720", "Image Sensing Systems, Inc." },
{ "001725", "Liquid Computing" },
{ "001701", "KDE, Inc." },
{ "001703", "MOSDAN Internation Co.,Ltd" },
{ "0016FC", "TOHKEN CO.,LTD." },
{ "0016F0", "Dell" },
{ "0016F5", "Dalian Golden Hualu Digital Technology Co.,Ltd" },
{ "0016E9", "Tiba Medical Inc" },
{ "0016E4", "VANGUARD SECURITY ENGINEERING CORP." },
{ "0016DD", "Gigabeam Corporation" },
{ "0016E2", "American Fibertek, Inc." },
{ "0016D3", "Wistron Corporation" },
{ "0016D8", "Senea AB" },
{ "00169C", "Cisco Systems, Inc" },
{ "00169E", "TV One Ltd" },
{ "0016A3", "Ingeteam Transmission&Distribution, S.A." },
{ "001690", "J-TEK INCORPORATION" },
{ "001697", "NEC Corporation" },
{ "001689", "Pilkor Electronics Co., Ltd" },
{ "00168B", "Paralan Corporation" },
{ "001684", "Donjin Co.,Ltd." },
{ "00167D", "Sky-Line Information Co., Ltd." },
{ "001678", "SHENZHEN BAOAN GAOKE ELECTRONICS CO., LTD" },
{ "001649", "SetOne GmbH" },
{ "00163F", "CReTE SYSTEMS Inc." },
{ "001638", "TECOM Co., Ltd." },
{ "001633", "Oxford Diagnostics Ltd." },
{ "00162C", "Xanboo" },
{ "001627", "embedded-logic DESIGN AND MORE GmbH" },
{ "001619", "Lancelan Technologies S.L." },
{ "001614", "Picosecond Pulse Labs" },
{ "001719", "Audiocodes USA, Inc" },
{ "00171E", "Theo Benning GmbH & Co. KG" },
{ "001712", "ISCO International" },
{ "00170D", "Dust Networks Inc." },
{ "00160F", "BADGER METER INC" },
{ "00160A", "SWEEX Europe BV" },
{ "001603", "COOLKSKY Co., LTD" },
{ "0015FC", "Littelfuse Startco" },
{ "0015F7", "Wintecronics Ltd." },
{ "0015F0", "EGO BV" },
{ "0015EA", "Tellumat (Pty) Ltd" },
{ "0016C5", "Shenzhen Xing Feng Industry Co.,Ltd" },
{ "0016C7", "Cisco Systems, Inc" },
{ "0016CC", "Xcute Mobile Corp." },
{ "0016C0", "Semtech Corporation" },
{ "0016B9", "ProCurve Networking" },
{ "0016B4", "Private" },
{ "0016A8", "CWT CO., LTD." },
{ "0016AD", "BT-Links Company Limited" },
{ "001553", "Cytyc Corporation" },
{ "001555", "DFM GmbH" },
{ "00154E", "IEC" },
{ "001547", "AiZen Solutions Inc." },
{ "001542", "MICROHARD S.R.L." },
{ "00153B", "EMH metering GmbH & Co. KG" },
{ "001534", "A Beltrónica-Companhia de Comunicações, Lda" },
{ "001440", "ATOMIC Corporation" },
{ "001439", "Blonder Tongue Laboratories, Inc." },
{ "001434", "Keri Systems, Inc" },
{ "00142D", "Toradex AG" },
{ "001426", "NL Technology" },
{ "001421", "Total Wireless Technologies Pte. Ltd." },
{ "00141C", "Cisco Systems, Inc" },
{ "001583", "IVT corporation" },
{ "00157E", "Weidmüller Interface GmbH & Co. KG" },
{ "001579", "Lunatone Industrielle Elektronik GmbH" },
{ "001574", "Horizon Semiconductors Ltd." },
{ "00156D", "Ubiquiti Networks Inc." },
{ "001566", "A-First Technology Co., Ltd." },
{ "001561", "JJPlus Corporation" },
{ "00155A", "DAINIPPON PHARMACEUTICAL CO., LTD." },
{ "001554", "Atalum Wireless S.A." },
{ "001528", "Beacon Medical Products LLC d.b.a. BeaconMedaes" },
{ "001521", "Horoquartz" },
{ "001523", "Meteor Communications Corporation" },
{ "001522", "Dea Security" },
{ "00151C", "LENECO" },
{ "001512", "Zurich University of Applied Sciences" },
{ "00150B", "SAGE INFOTECH LTD." },
{ "001506", "Neo Photonics" },
{ "0014FF", "Precise Automation, Inc." },
{ "0014F8", "Scientific Atlanta" },
{ "0014F3", "ViXS Systems Inc" },
{ "0014E7", "Stolinx,. Inc" },
{ "0014EC", "Acro Telecom" },
{ "0014E2", "datacom systems inc." },
{ "0014D6", "Jeongmin Electronics Co.,Ltd." },
{ "0014DB", "Elma Trenew Electronic GmbH" },
{ "0014DD", "Covergence Inc." },
{ "0014DC", "Communication System Design & Manufacturing (CSDM)" },
{ "0014CF", "INVISIO Communications" },
{ "0014CA", "Key Radio Systems Limited" },
{ "0014C3", "Seagate Technology" },
{ "0014BC", "SYNECTIC TELECOM EXPORTS PVT. LTD." },
{ "0014B7", "AR Infotek Inc." },
{ "0014AD", "Gassner Wiege- und Meßtechnik GmbH" },
{ "0014B2", "mCubelogics Corporation" },
{ "0014A6", "Teranetics, Inc." },
{ "00149F", "System and Chips, Inc." },
{ "0014A1", "Synchronous Communication Corp" },
{ "001470", "Prokom Software SA" },
{ "001469", "Cisco Systems, Inc" },
{ "001462", "Digiwell Technology, inc" },
{ "00145D", "WJ Communications, Inc." },
{ "001450", "Heim Systems GmbH" },
{ "001456", "Edge Products" },
{ "00144C", "General Meters Corp." },
{ "001445", "Telefon-Gradnja d.o.o." },
{ "001447", "BOAZ Inc." },
{ "001446", "SuperVision Solutions LLC" },
{ "0015B3", "Caretech AB" },
{ "0015A9", "KWANG WOO I&C CO.,LTD" },
{ "00159D", "Tripp Lite " },
{ "001591", "RLW Inc." },
{ "00158A", "SURECOM Technology Corp." },
{ "00158F", "NTT Advanced Technology Corporation" },
{ "001590", "Hectronic GmbH" },
{ "0014A0", "Accsense, Inc." },
{ "001493", "Systimax Solutions" },
{ "00148E", "Tele Power Inc." },
{ "001487", "American Technology Integrators" },
{ "001482", "Aurora Networks" },
{ "001481", "Multilink Inc" },
{ "00147C", "3Com Ltd" },
{ "001475", "Wiline Networks, Inc." },
{ "0012E7", "Projectek Networking Electronics Corp." },
{ "0012E8", "Fraunhofer IMS" },
{ "0012DB", "ZIEHL industrie-elektronik GmbH + Co KG" },
{ "0012E2", "ALAXALA Networks Corporation" },
{ "0012D6", "Jiangsu Yitong High-Tech Co.,Ltd" },
{ "0012D5", "Motion Reality Inc." },
{ "0012C3", "WIT S.A." },
{ "0013E5", "TENOSYS, INC." },
{ "0013EA", "Kamstrup A/S" },
{ "0013DE", "Adapt4, LLC" },
{ "0013D7", "SPIDCOM Technologies SA" },
{ "0013D8", "Princeton Instruments" },
{ "0013CF", "4Access Communications" },
{ "0013D2", "PAGE IBERICA, S.A." },
{ "0013C9", "Beyond Achieve Enterprises Ltd." },
{ "0013C2", "WACOM Co.,Ltd" },
{ "0013BD", "HYMATOM SA" },
{ "0013B8", "RyCo Electronic Systems Limited" },
{ "00134E", "Valox Systems, Inc." },
{ "001353", "HYDAC Filtertechnik GMBH" },
{ "00134D", "Inepro BV" },
{ "001347", "Red Lion Controls, LP" },
{ "00133B", "Speed Dragon Multimedia Limited" },
{ "001340", "AD.EL s.r.l." },
{ "00132E", "ITian Coporation" },
{ "001328", "Westech Korea Inc.," },
{ "00132D", "iWise Communications" },
{ "001334", "Arkados, Inc." },
{ "0013B3", "Ecom Communications Technology Co., Ltd." },
{ "0013AC", "Sunmyung Electronics Co., LTD" },
{ "0013A6", "Extricom Ltd" },
{ "0013A5", "General Solutions, LTD." },
{ "0013A0", "ALGOSYSTEM Co., Ltd." },
{ "001399", "STAC Corporation." },
{ "001393", "Panta Systems, Inc." },
{ "001394", "Infohand Co.,Ltd" },
{ "00138D", "Kinghold" },
{ "0012C8", "Perfect tech" },
{ "0012B9", "Fusion Digital Technology" },
{ "0012BE", "Astek Corporation" },
{ "0012AC", "ONTIMETEK INC." },
{ "0012AB", "WiLife, Inc." },
{ "0012B2", "AVOLITES LTD." },
{ "0012A6", "Dolby Australia" },
{ "001378", "Qsan Technology, Inc." },
{ "00137D", "Dynalab, Inc." },
{ "001384", "Advanced Motion Controls" },
{ "00137E", "CorEdge Networks, Inc." },
{ "00136C", "TomTom" },
{ "001365", "Nortel" },
{ "00136B", "E-TEC" },
{ "001359", "ProTelevision Technologies A/S" },
{ "00135E", "EAB/RWI/K" },
{ "00129F", "RAE Systems" },
{ "001299", "Ktech Telecommunications Inc" },
{ "00129A", "IRT Electronics Pty Ltd" },
{ "00128C", "Woodward Governor" },
{ "001293", "GE Energy" },
{ "001287", "Digital Everywhere Unterhaltungselektronik GmbH" },
{ "001280", "Cisco Systems, Inc" },
{ "00131E", "Peiker acustic GmbH & Co. KG" },
{ "001323", "Cap Co., Ltd." },
{ "00130B", "Mextal B.V." },
{ "001312", "Amedia Networks Inc." },
{ "0012F8", "WNI Resources, LLC" },
{ "0012FF", "Lely Industries N.V." },
{ "001304", "Flaircomm Technologies Co. LTD" },
{ "001410", "Suzhou Keda Technology CO.,Ltd" },
{ "001417", "RSE Informations Technologie GmbH" },
{ "001408", "Eka Systems Inc." },
{ "001402", "kk-electronic a/s" },
{ "001401", "Rivertree Networks Corp." },
{ "0013FB", "RKC INSTRUMENT INC." },
{ "0013F4", "Psitek (Pty) Ltd" },
{ "0013EF", "Kingjon Digital Technology Co.,Ltd" },
{ "0011F7", "Shenzhen Forward Industry Co., Ltd" },
{ "0011F2", "Institute of Network Technologies" },
{ "0011EB", "Innovative Integration" },
{ "0011E6", "Scientific Atlanta" },
{ "0011E5", "KCodes Corporation" },
{ "0011DF", "Current Energy" },
{ "0011D3", "NextGenTel Holding ASA" },
{ "00110E", "Tsurusaki Sealand Transportation Co. Ltd." },
{ "001115", "EPIN Technologies, Inc." },
{ "001114", "EverFocus Electronics Corp." },
{ "001107", "RGB Networks Inc." },
{ "001108", "Orbital Data Corporation" },
{ "001102", "Aurora Multimedia Corp." },
{ "000FFC", "Merit Li-Lin Ent." },
{ "000FDA", "YAZAKI CORPORATION" },
{ "000FF3", "Jung Myoung Communications&Technology" },
{ "0011A2", "Manufacturing Technology Inc" },
{ "00119B", "Telesynergy Research Inc." },
{ "00118C", "Missouri Department of Transportation" },
{ "001191", "CTS-Clima Temperatur Systeme GmbH" },
{ "00118B", "Alcatel-Lucent, Enterprise Business Group" },
{ "001196", "Actuality Systems, Inc." },
{ "00117E", "Progeny, A division of Midmark Corp" },
{ "001179", "Singular Technology Co. Ltd." },
{ "001172", "COTRON CORPORATION" },
{ "001166", "Taelim Electronics Co., Ltd." },
{ "00116B", "Digital Data Communications Asia Co.,Ltd" },
{ "00116C", "Nanwang Multimedia Inc.,Ltd" },
{ "001162", "STAR MICRONICS CO.,LTD." },
{ "001161", "NetStreams, LLC" },
{ "001155", "Sevis Systems" },
{ "00115C", "Cisco Systems, Inc" },
{ "001147", "Secom-Industry co.LTD." },
{ "00114C", "caffeina applied research ltd." },
{ "001274", "NIT lab" },
{ "00127A", "Sanyu Industry Co.,Ltd." },
{ "00126D", "University of California, Berkeley" },
{ "001268", "IPS d.o.o." },
{ "001267", "Panasonic Corporation" },
{ "001261", "Adaptix, Inc" },
{ "001257", "LeapComm Communication Technologies Inc." },
{ "001222", "Skardin (UK) Ltd" },
{ "001227", "Franklin Electric Co., Inc." },
{ "00121B", "Sound Devices, LLC" },
{ "001221", "B.Braun Melsungen AG" },
{ "001214", "Koenig & Bauer AG" },
{ "00120F", "IEEE 802.3" },
{ "001208", "Gantner Instruments GmbH" },
{ "001201", "Cisco Systems, Inc" },
{ "001202", "Decrane Aerospace - Audio International Inc." },
{ "0011FC", "HARTING Electric Gmbh & Co.KG" },
{ "0011C7", "Raymarine UK Ltd" },
{ "0011CC", "Guangzhou Jinpeng Group Co.,Ltd." },
{ "0011B5", "Shenzhen Powercom Co.,Ltd" },
{ "0011BA", "Elexol Pty Ltd" },
{ "0011C1", "4P MOBILE DATA PROCESSING" },
{ "0011A8", "Quest Technologies" },
{ "0011A7", "Infilco Degremont Inc." },
{ "001250", "Tokyo Aircaft Instrument Co., Ltd." },
{ "00124B", "Texas Instruments" },
{ "001244", "Cisco Systems, Inc" },
{ "001238", "SetaBox Technology Co., Ltd." },
{ "00123D", "GES Co, Ltd" },
{ "00123E", "ERUNE technology Co., Ltd." },
{ "00122C", "Soenen Controls N.V." },
{ "001231", "Motion Control Systems, Inc." },
{ "001146", "Telecard-Pribor Ltd" },
{ "001140", "Nanometrics Inc." },
{ "001139", "STOEBER ANTRIEBSTECHNIK GmbH + Co. KG." },
{ "00113A", "SHINBORAM" },
{ "001134", "MediaCell, Inc." },
{ "001127", "TASI, Inc" },
{ "00112A", "Niko NV" },
{ "001121", "Cisco Systems, Inc" },
{ "000EBB", "Everbee Networks" },
{ "000EB4", "GUANGZHOU GAOKE COMMUNICATIONS TECHNOLOGY CO.LTD." },
{ "000EAE", "GAWELL TECHNOLOGIES CORP." },
{ "000EA8", "United Technologists Europe Limited" },
{ "000EAD", "Metanoia Technologies, Inc." },
{ "000EA1", "Formosa Teletek Corporation" },
{ "000E9C", "Benchmark Electronics " },
{ "000E9B", "Ambit Microsystems Corporation" },
{ "000E8E", "SparkLAN Communications, Inc." },
{ "000E95", "Fujiya Denki Seisakusho Co.,Ltd." },
{ "000FC1", "WAVE Corporation" },
{ "000FC8", "Chantry Networks" },
{ "000FC7", "Dionica R&D Ltd." },
{ "000FBA", "Tevebox AB" },
{ "000FA7", "Raptor Networks Technology" },
{ "000FAE", "E2O Communications" },
{ "000FA8", "Photometrics, Inc." },
{ "000F9A", "Synchrony, Inc." },
{ "000FA2", "2xWireless" },
{ "000E89", "CLEMATIC" },
{ "000E82", "Commtech Wireless" },
{ "000E7C", "Televes S.A." },
{ "000E76", "GEMSOC INNOVISION INC." },
{ "000E7B", "Toshiba" },
{ "000E6E", "MAT S.A. (Mircrelec Advanced Technology)" },
{ "000E72", "CTS electronics" },
{ "000E68", "E-TOP Network Technology Inc." },
{ "000E67", "Eltis Microelectronics Ltd." },
{ "000E62", "Nortel Networks" },
{ "000FE7", "Lutron Electronics Co., Inc." },
{ "000FEC", "ARKUS Inc." },
{ "000FE0", "NComputing Co.,Ltd." },
{ "000FD4", "Soundcraft" },
{ "000FD9", "FlexDSL Telecommunications AG" },
{ "000FCD", "Nortel Networks" },
{ "000EEA", "Shadong Luneng Jicheng Electronics,Co.,Ltd" },
{ "000EDD", "SHURE INCORPORATED" },
{ "000EE4", "BOE TECHNOLOGY GROUP CO.,LTD" },
{ "000ED8", "Positron Access Solutions Corp" },
{ "000ECD", "SKOV A/S" },
{ "000ECE", "S.I.T.T.I. S.p.A." },
{ "000ED3", "Epicenter, Inc." },
{ "000EC0", "Nortel Networks" },
{ "000EC7", "Motorola Korea" },
{ "000F93", "Landis+Gyr Ltd." },
{ "000F94", "Genexis BV" },
{ "000F8E", "DONGYANG TELECOM CO.,LTD." },
{ "000F87", "Maxcess International" },
{ "000F82", "Mortara Instrument, Inc." },
{ "000F81", "PAL Pacific Inc." },
{ "000F74", "Qamcom Technology AB" },
{ "000F7B", "Arce Sistemas, S.A." },
{ "000F68", "Vavic Network Technology, Inc." },
{ "000F6F", "FTA Communication Technologies" },
{ "000F62", "Alcatel Bell Space N.V." },
{ "000F5C", "Day One Digital Media Limited" },
{ "000F55", "Datawire Communication Networks Inc." },
{ "000F49", "Northover Solutions Limited" },
{ "000F50", "StreamScale Limited" },
{ "000F42", "Xalyo Systems" },
{ "000F1C", "DigitAll World Co., Ltd" },
{ "000F0A", "Clear Edge Networks" },
{ "000F09", "Private" },
{ "000F03", "COM&C CO., LTD" },
{ "000EF7", "Vulcan Portals Inc" },
{ "000EFC", "JTAG Technologies B.V." },
{ "000EE9", "WayTech Development, Inc." },
{ "000EF0", "Festo AG & Co. KG" },
{ "000F4F", "Cadmus Technology Ltd" },
{ "000F35", "Cisco Systems, Inc" },
{ "000F2E", "Megapower International Corp." },
{ "000F29", "Augmentix Corporation" },
{ "000F22", "Helius, Inc." },
{ "000F0F", "Real ID Technology Co., Ltd." },
{ "000F16", "JAY HOW TECHNOLOGY CO.," },
{ "000F1B", "Ego Systems Inc." },
{ "000D74", "Sand Network Systems, Inc." },
{ "000D7B", "Consensys Computers Inc." },
{ "000D6E", "K-Patents Oy" },
{ "000D68", "Vinci Systems, Inc." },
{ "000D6D", "K-Tech Devices Corp." },
{ "000D5B", "Smart Empire Investments Limited" },
{ "000D5C", "Robert Bosch GmbH, VT-ATMO" },
{ "000D61", "Giga-Byte Technology Co., Ltd." },
{ "000D55", "SANYCOM Technology Co.,Ltd" },
{ "000D49", "Triton Systems of Delaware, Inc." },
{ "000D4E", "NDR Co.,LTD." },
{ "000E5B", "ParkerVision - Direct2Data" },
{ "000E55", "AUVITRAN" },
{ "000E56", "4G Systems GmbH & Co. KG" },
{ "000E4F", "Trajet GmbH" },
{ "000E48", "Lipman TransAction Solutions" },
{ "000E43", "G-Tek Electronics Sdn. Bhd." },
{ "000E34", "NexGen City, LP" },
{ "000E3B", "Hawking Technologies, Inc." },
{ "000E2F", "Roche Diagnostics GmbH" },
{ "000DFB", "Komax AG" },
{ "000DE9", "Napatech Aps" },
{ "000DEE", "Andrew RF Power Amplifier Group" },
{ "000DE2", "CMZ Sistemi Elettronici" },
{ "000DDC", "VAC" },
{ "000DD6", "ITI    LTD" },
{ "000DDB", "AIRWAVE TECHNOLOGIES INC." },
{ "000DCA", "Tait Electronics" },
{ "000DCF", "Cidra Corp." },
{ "000E28", "Dynamic Ratings P/L" },
{ "000E22", "Private" },
{ "000E21", "MTU Friedrichshafen GmbH" },
{ "000E15", "Tadlys LTD" },
{ "000E1C", "Hach Company" },
{ "000E0D", "Hesch Schröder GmbH" },
{ "000E10", "C-guys, Inc." },
{ "000DF5", "Teletronics International Inc." },
{ "000DFC", "ITFOR Inc." },
{ "000E01", "ASIP Technologies Inc." },
{ "000CF0", "M & N GmbH" },
{ "000CF5", "InfoExpress" },
{ "000CE0", "Trek Diagnostics Inc." },
{ "000CE4", "NeuroCom International, Inc." },
{ "000CE9", "BLOOMBERG L.P." },
{ "000CCE", "Cisco Systems, Inc" },
{ "000CD4", "Positron Public Safety Systems inc." },
{ "000CCD", "IEC - TC57" },
{ "000D15", "Voipac s.r.o." },
{ "000D16", "UHS Systems Pty Ltd" },
{ "000D1B", "Kyoto Electronics Manufacturing Co., Ltd." },
{ "000D0F", "Finlux Ltd" },
{ "000D03", "Matrics, Inc." },
{ "000D08", "AboveCable, Inc." },
{ "000CFC", "S2io Technologies Corp" },
{ "000CF6", "Sitecom Europe BV" },
{ "000DA3", "Emerging Technologies Limited" },
{ "000D9C", "Elan GmbH & Co KG" },
{ "000D96", "Vtera Technology Inc." },
{ "000D95", "Opti-cell, Inc." },
{ "000D90", "Factum Electronics AB" },
{ "000D89", "Bils Technology Inc" },
{ "000D80", "Online Development Inc" },
{ "000DC9", "THALES Elektronik Systeme GmbH" },
{ "000DC3", "First Communication, Inc." },
{ "000DBC", "Cisco Systems, Inc" },
{ "000DB7", "SANKO ELECTRIC CO,.LTD" },
{ "000DB0", "Olym-tech Co.,Ltd." },
{ "000DA8", "Teletronics Technology Corporation" },
{ "000D41", "Siemens AG ICM MP UC RD IT KLF1" },
{ "000D3A", "Microsoft Corp." },
{ "000D35", "PAC International Ltd" },
{ "000D2E", "Matsushita Avionics Systems Corporation" },
{ "000D28", "Cisco Systems, Inc" },
{ "000D22", "Unitronics LTD" },
{ "000D27", "MICROPLEX Printware AG" },
{ "000C21", "Faculty of Science and Technology, Keio University" },
{ "000C11", "NIPPON DEMPA CO.,LTD." },
{ "000C10", "PNI Corporation" },
{ "000C12", "Micro-Optronic-Messtechnik GmbH" },
{ "000C17", "AJA Video Systems Inc" },
{ "000C04", "Tecnova" },
{ "000C0B", "Broadbus Technologies" },
{ "000BF8", "Infinera" },
{ "000BFF", "Berkeley Camera Engineering" },
{ "000BEC", "NIPPON ELECTRIC INSTRUMENT, INC." },
{ "000BB8", "Kihoku Electronic Co." },
{ "000BBD", "Connexionz Limited" },
{ "000BAD", "PC-PoS Inc." },
{ "000BA0", "T&L Information Inc." },
{ "000BA7", "Maranti Networks" },
{ "000BAC", "3Com Ltd" },
{ "000B93", "Ritter Elektronik" },
{ "000B98", "NiceTechVision" },
{ "000B9B", "Sirius System Co, Ltd." },
{ "000B8C", "Flextronics" },
{ "000BF1", "LAP Laser Applikations" },
{ "000BDF", "Shenzhen RouterD Networks Limited" },
{ "000BDE", "TELDIX GmbH" },
{ "000BE0", "SercoNet Ltd." },
{ "000BE5", "HIMS International Corporation" },
{ "000BD9", "General Hydrogen" },
{ "000BAE", "Vitals System Inc." },
{ "000BD0", "XiMeta Technology Americas Inc." },
{ "000BD5", "Nvergence, Inc." },
{ "000BC4", "BIOTRONIK GmbH & Co" },
{ "000BC9", "Electroline Equipment" },
{ "000BB1", "Super Star Technology Co., Ltd." },
{ "000BB6", "Metalligence Technology Corp." },
{ "000B79", "X-COM, Inc." },
{ "000B80", "Lycium Networks" },
{ "000B87", "American Reliance Inc." },
{ "000B6D", "SOLECTRON JAPAN NAKANIIDA" },
{ "000B74", "Kingwave Technology Co., Ltd." },
{ "000B67", "Topview Technology Corporation" },
{ "000B61", "Friedrich Lütze GmbH & Co. KG" },
{ "000B66", "Teralink Communications" },
{ "000B68", "Addvalue Communications Pte Ltd" },
{ "000B58", "Astronautics C.A  LTD" },
{ "000B50", "Oxygnet" },
{ "000B44", "Concord IDea Corp." },
{ "000B49", "RF-Link System Inc." },
{ "000B4B", "VISIOWAVE SA" },
{ "000B31", "Yantai ZhiYang Scientific and technology industry CO., LTD" },
{ "000B3D", "CONTAL OK Ltd." },
{ "000B38", "Knürr GmbH" },
{ "000B2A", "HOWTEL Co., Ltd." },
{ "000B2C", "Eiki Industrial Co. Ltd." },
{ "000C97", "NV ADB TTV Technologies SA" },
{ "000C9C", "Chongho information & communications" },
{ "000C9E", "MemoryLink Corp." },
{ "000C89", "AC Electric Vehicles, Ltd." },
{ "000C8B", "Connect Tech Inc" },
{ "000C90", "Octasic Inc." },
{ "000C84", "Eazix, Inc." },
{ "000C75", "Oriental integrated electronics. LTD" },
{ "000C77", "Life Racing Ltd" },
{ "000C7C", "Internet Information Image Inc." },
{ "000C43", "Ralink Technology, Corp." },
{ "000C45", "Animation Technologies Inc." },
{ "000C29", "VMware, Inc." },
{ "000C3C", "MediaChorus, Inc." },
{ "000C32", "Avionic Design Development GmbH" },
{ "000C35", "KaVo Dental GmbH & Co. KG" },
{ "000C2B", "ELIAS Technology, Inc." },
{ "000C28", "RIFATRON" },
{ "000C1C", "MicroWeb Co., Ltd." },
{ "000C64", "X2 MSA Group" },
{ "000C69", "National Radio Astronomy Observatory" },
{ "000C70", "ACC GmbH" },
{ "000C51", "Scientific Technologies Inc." },
{ "000C56", "Megatel Computer (1986) Corp." },
{ "000C58", "M&S Systems" },
{ "000C5D", "CHIC TECHNOLOGY (CHINA) CORP." },
{ "000C4A", "Cygnus Microsystems (P) Limited" },
{ "000CC8", "Xytronix Research & Design, Inc." },
{ "000CBB", "ISKRAEMECO" },
{ "000CB5", "Premier Technolgies, Inc" },
{ "000CBC", "Iscutum" },
{ "000CA3", "Rancho Technology, Inc." },
{ "000CAA", "Cubic Transportation Systems Inc" },
{ "000A38", "Apani Networks" },
{ "000A3F", "Data East Corporation" },
{ "000A44", "Avery Dennison Deutschland GmbH" },
{ "000A46", "ARO WELDING TECHNOLOGIES SAS" },
{ "000A33", "Emulex Corporation" },
{ "000A31", "HCV Consulting" },
{ "000A2C", "Active Tchnology Corporation" },
{ "004252", "RLX Technologies" },
{ "000A2A", "QSI Systems Inc." },
{ "000A1E", "Red-M Products Limited" },
{ "000A23", "Parama Networks Inc" },
{ "000A17", "NESTAR COMMUNICATIONS, INC" },
{ "000A1C", "Bridge Information Co., Ltd." },
{ "000B19", "Vernier Networks, Inc." },
{ "000B1E", "KAPPA opto-electronics GmbH" },
{ "000B25", "Aeluros" },
{ "000B17", "MKS Instruments" },
{ "000B12", "NURI Telecom Co., Ltd." },
{ "000B0B", "Corrent Corporation" },
{ "000AFA", "Traverse Technologies Australia" },
{ "000AFF", "Kilchherr Elektronik AG" },
{ "000AF3", "Cisco Systems, Inc" },
{ "000AF8", "American Telecare Inc." },
{ "000AEE", "GCD Hard- & Software GmbH" },
{ "000A06", "Teledex LLC" },
{ "000A09", "TaraCom Integrated Products, Inc." },
{ "000A0B", "Sealevel Systems, Inc." },
{ "000A10", "FAST media integrations AG" },
{ "0009F7", "SED, a division of Calian" },
{ "000A01", "SOHOware, Inc." },
{ "0009E9", "Cisco Systems, Inc" },
{ "0009F0", "Shimizu Technology Inc." },
{ "0009EA", "YEM Inc." },
{ "0009E4", "K Tech Infosystem Inc." },
{ "0009D8", "Fält Communications AB" },
{ "0009DD", "Mavin Technology Inc." },
{ "0009B1", "Kanematsu Electronics, Ltd." },
{ "0009A3", "Leadfly Techologies Corp. Ltd." },
{ "0009AA", "Data Comm for Business, Inc." },
{ "0009A4", "HARTEC Corporation" },
{ "00099E", "Testech, Inc." },
{ "000992", "InterEpoch Technology,INC." },
{ "000997", "Nortel Networks" },
{ "000991", "GE Fanuc Automation Manufacturing, Inc." },
{ "00098B", "Entropic Communications, Inc." },
{ "000AAB", "Toyota Technical Development Corporation" },
{ "000AB0", "LOYTEC electronics GmbH" },
{ "000AB7", "Cisco Systems, Inc" },
{ "000AA4", "SHANGHAI SURVEILLANCE TECHNOLOGY CO,LTD" },
{ "000AA9", "Brooks Automation GmbH" },
{ "000A91", "HemoCue AB" },
{ "000A9D", "King Young Technology Co. Ltd." },
{ "000A8C", "Guardware Systems Ltd." },
{ "000A97", "SONICblue, Inc." },
{ "000A7D", "Valo, Inc." },
{ "000A84", "Rainsun Enterprise Co., Ltd." },
{ "000A89", "Creval Systems, Inc." },
{ "0009D7", "DC Security Products" },
{ "0009CA", "iMaxNetworks(Shenzhen)Limited." },
{ "0009D1", "SERANOA NETWORKS INC" },
{ "0009C5", "KINGENE Technology Corporation" },
{ "0009BD", "Epygi Technologies, Ltd." },
{ "0009B6", "Cisco Systems, Inc" },
{ "00097F", "Vsecure 2000 LTD." },
{ "000984", "MyCasa Network Inc." },
{ "000971", "Time Management, Inc." },
{ "000978", "AIJI System Co., Ltd." },
{ "000972", "Securebase,Inc" },
{ "00096C", "Imedia Semiconductor Corp." },
{ "000965", "HyunJu Computer Co., Ltd." },
{ "000960", "YOZAN Inc." },
{ "000956", "Network Systems Group, Ltd. (NSG)" },
{ "000955", "Young Generation International Corp." },
{ "000AE9", "AirVast Technology Inc." },
{ "000ADB", "SkyPilot Network, Inc" },
{ "000ADD", "Allworx Corp." },
{ "000AE2", "Binatone Electronics International, Ltd" },
{ "000ACA", "YOKOYAMA SHOKAI CO.,Ltd." },
{ "000ACF", "PROVIDEO Multimedia Co. Ltd." },
{ "000AD6", "BeamReach Networks" },
{ "000ABC", "Seabridge Ltd." },
{ "000ABE", "OPNET Technologies CO., LTD." },
{ "000AC3", "eM Technics Co., Ltd." },
{ "000A78", "OLITEC" },
{ "000A71", "Avrio Technologies, Inc" },
{ "000A76", "Beida Jade Bird Huaguang Technology Co.,Ltd" },
{ "000A63", "DHD GmbH" },
{ "000A65", "GentechMedia.co.,ltd." },
{ "000A6A", "SVM Microwaves s.r.o." },
{ "000A5E", "3COM Corporation" },
{ "000A52", "AsiaRF Ltd." },
{ "000A4B", "DataPower Technology, Inc." },
{ "00075A", "Air Products and Chemicals, Inc." },
{ "000754", "Xyterra Computing, Inc." },
{ "00074E", "IPFRONT Inc" },
{ "00074D", "Zebra Technologies Corp." },
{ "000742", "Ormazabal" },
{ "000748", "The Imaging Source Europe" },
{ "000736", "Data Video Technologies Co., Ltd." },
{ "00073D", "Nanjing Postel Telecommunications Co., Ltd." },
{ "00073C", "Telecom Design" },
{ "00072A", "Innovance Networks" },
{ "00072F", "Intransa, Inc." },
{ "000730", "Hutchison OPTEL Telecom Technology Co., Ltd." },
{ "000725", "Bematech International Corp." },
{ "000818", "Pixelworks, Inc." },
{ "000812", "GM-2 Corporation" },
{ "000811", "VOIX Corporation" },
{ "00080B", "Birka BPA Informationssystem AB" },
{ "000805", "Techno-Holon Corporation" },
{ "00080C", "VDA Elettronica spa" },
{ "0007FB", "Giga Stream UMTS Technologies GmbH" },
{ "0007F5", "Bridgeco Co AG" },
{ "0007E8", "EdgeWave" },
{ "0007EF", "Lockheed Martin Tactical Systems" },
{ "0007E2", "Bitworks, Inc." },
{ "0007D6", "Commil Ltd." },
{ "0007DC", "Atek Co, Ltd." },
{ "000923", "Heaman System Co., Ltd" },
{ "00091D", "Proteam Computer Corporation" },
{ "000924", "Telebau GmbH" },
{ "000911", "Cisco Systems, Inc" },
{ "000916", "Listman Home Technologies, Inc." },
{ "00090A", "SnedFar Technology Co., Ltd." },
{ "000904", "MONDIAL electronic" },
{ "000903", "Panasas, Inc" },
{ "0008FE", "UNIK C&C Co.,Ltd." },
{ "0008FA", "Karl E.Brinkmann GmbH" },
{ "0008EE", "Logic Product Development" },
{ "0008F0", "Next Generation Systems, Inc." },
{ "000948", "Vista Control Systems, Corp." },
{ "00094F", "elmegt GmbH & Co. KG" },
{ "000943", "Cisco Systems, Inc" },
{ "00093C", "Jacques Technologies P/L" },
{ "000936", "Ipetronik GmbH & Co. KG" },
{ "000935", "Sandvine Incorporated" },
{ "000929", "Sanyo Industries (UK) Limited" },
{ "000930", "AeroConcierge Inc." },
{ "0008E9", "NextGig" },
{ "0008DC", "Wiznet" },
{ "0008E2", "Cisco Systems, Inc" },
{ "0008DB", "Corrigent Systems" },
{ "0008D6", "HASSNET Inc." },
{ "0008CF", "Nippon Koei Power Systems Co., Ltd." },
{ "0008C0", "ASA SYSTEMS" },
{ "0008C5", "Liontech Co., Ltd." },
{ "0008C9", "TechniSat Digital GmbH" },
{ "0008CA", "TwinHan Technology Co.,Ltd" },
{ "0008BF", "Aptus Elektronik AB" },
{ "0008B9", "KAON MEDIA Co., Ltd." },
{ "0008B3", "Fastwel" },
{ "0008B2", "SHENZHEN COMPASS TECHNOLOGY DEVELOPMENT CO.,LTD" },
{ "0008A6", "Multiware & Image Co., Ltd." },
{ "0008AD", "Toyo-Linx Co., Ltd." },
{ "00089A", "Alcatel Microelectronics" },
{ "0008A0", "Stotz Feinmesstechnik GmbH" },
{ "000892", "EM Solutions" },
{ "000896", "Printronix, Inc." },
{ "00088C", "Quanta Network Systems Inc." },
{ "000886", "Hansung Teliann, Inc." },
{ "000873", "DapTechnology B.V." },
{ "00087A", "Wipotec GmbH" },
{ "00087F", "SPAUN electronic GmbH & Co. KG" },
{ "02608C", "3COM CORPORATION" },
{ "0007D0", "Automat Engenharia de Automação Ltda." },
{ "0007CD", "Kumoh Electronic Co, Ltd" },
{ "0007C7", "Synectics Systems Limited" },
{ "00047D", "Pelco" },
{ "0007BA", "UTStarcom, Inc." },
{ "00047E", "Siqura B.V." },
{ "0007C1", "Overture Networks, Inc." },
{ "0007C0", "NetZerver Inc." },
{ "0007AE", "Britestream Networks, Inc." },
{ "0007B4", "Cisco Systems, Inc" },
{ "0007A6", "Home Automation, Inc." },
{ "00079A", "Verint Systems Inc" },
{ "0007A0", "e-Watch Inc." },
{ "000794", "Simple Devices, Inc." },
{ "000793", "Shin Satellite Public Company Limited" },
{ "00078D", "NetEngines Ltd." },
{ "00078E", "Garz & Friche GmbH" },
{ "000781", "Itron Inc." },
{ "000787", "Idea System Co., Ltd." },
{ "000777", "Motah Ltd." },
{ "000771", "Embedded System Corporation" },
{ "00075B", "Gibson Guitars" },
{ "000760", "TOMIS Information & Telecom Corp." },
{ "000767", "Yuxing Electronics Company Limited" },
{ "000879", "CEM Corporation" },
{ "00086C", "Plasmon LMS" },
{ "00086D", "Missouri FreeNet" },
{ "000867", "Uptime Devices" },
{ "000860", "LodgeNet Entertainment Corp." },
{ "000854", "Netronix, Inc." },
{ "00085A", "IntiGate Inc." },
{ "00081E", "Repeatit AB" },
{ "00082B", "Wooksung Electronics, Inc." },
{ "000824", "Nuance Document Imaging" },
{ "0005BA", "Area Netwoeks, Inc." },
{ "0005B9", "Airvana, Inc." },
{ "0005C0", "Digital Network Alacarte Co., Ltd." },
{ "000599", "DRS Test and Energy Management or DRS-TEM" },
{ "0005A0", "MOBILINE Kft." },
{ "0005A9", "Princeton Networks, Inc." },
{ "0005AA", "Moore Industries International Inc." },
{ "0005AF", "InnoScan Computing A/S" },
{ "0005B3", "Asahi-Engineering Co., Ltd." },
{ "00059F", "Yotta Networks, Inc." },
{ "0005A6", "Extron Electronics" },
{ "0005B4", "Aceex Corporation" },
{ "00058D", "Lynx Photonic Networks, Inc." },
{ "000587", "Locus, Incorporated" },
{ "000593", "Grammar Engine Inc." },
{ "000586", "Lucent Technologies" },
{ "00057A", "Overture Networks" },
{ "00063C", "Intrinsyc Software International Inc." },
{ "00062F", "Pivotech Systems Inc." },
{ "000636", "Jedai Broadband Networks" },
{ "000635", "PacketAir Networks, Inc." },
{ "000628", "Cisco Systems, Inc" },
{ "00061F", "Vision Components GmbH" },
{ "000619", "Connection Technology Systems" },
{ "00060D", "Wave7 Optics" },
{ "000613", "Kawasaki Microelectronics Incorporated" },
{ "00060E", "IGYS Systems, Inc." },
{ "0005EC", "Mosaic Systems Inc." },
{ "0005D3", "eProduction Solutions, Inc." },
{ "000608", "At-Sky SAS" },
{ "000607", "Omni Directional Control Technology Inc." },
{ "0005E6", "Egenera, Inc." },
{ "000580", "FibroLAN Ltd." },
{ "000576", "NSM Technology Ltd." },
{ "000570", "Baydel Ltd." },
{ "00056A", "Heuft Systemtechnik GmbH" },
{ "000563", "J-Works, Inc." },
{ "00055D", "D-LINK SYSTEMS, INC." },
{ "000564", "Tsinghua Bitway Co., Ltd." },
{ "000557", "Agile TV Corporation" },
{ "000551", "F & S Elektronik Systeme GmbH" },
{ "00054B", "Eaton Automation AG" },
{ "00054A", "Ario Data Networks, Inc." },
{ "000544", "Valley Technologies, Inc." },
{ "00053E", "KID Systeme GmbH" },
{ "000531", "Cisco Systems, Inc" },
{ "000538", "Merilus, Inc." },
{ "000532", "Cisco Systems, Inc" },
{ "000525", "Puretek Industrial Co., Ltd." },
{ "00052B", "HORIBA, Ltd." },
{ "00051F", "Taijin Media Co., Ltd." },
{ "000519", "Siemens Building Technologies AG," },
{ "000518", "Jupiters Technology" },
{ "00050E", "3ware, Inc." },
{ "00050F", "Tanaka S/S Ltd." },
{ "000508", "Inetcam, Inc." },
{ "0004FE", "Pelago Networks" },
{ "000671", "Softing AG" },
{ "000672", "Netezza" },
{ "00067B", "Toplink C&C Corporation" },
{ "000665", "Sunny Giken, Inc." },
{ "00066B", "Sysmex Corporation" },
{ "000652", "Cisco Systems, Inc" },
{ "000659", "EAL (Apeldoorn) B.V." },
{ "000658", "Helmut Fischer GmbH Institut für Elektronik und Messtechnik" },
{ "000646", "ShenZhen XunBao Network Technology Co Ltd" },
{ "000640", "White Rock Networks" },
{ "00064C", "Invicta Networks, Inc." },
{ "0006B5", "Source Photonics, Inc." },
{ "0006A8", "KC Technology, Inc." },
{ "00069E", "UNIQA, Inc." },
{ "000698", "egnite GmbH" },
{ "000692", "Intruvert Networks, Inc." },
{ "00068C", "3COM CORPORATION" },
{ "000685", "NetNearU Corporation" },
{ "00068B", "AirRunner Technologies, Inc." },
{ "000686", "ZARDCOM Co., Ltd." },
{ "00067F", "Digeo, Inc." },
{ "0006DE", "Flash Technology" },
{ "0006E4", "Citel Technologies Ltd." },
{ "0006D1", "Tahoe Networks, Inc." },
{ "0006DA", "ITRAN Communications Ltd." },
{ "0006CB", "Jotron Electronics A/S" },
{ "0006CC", "JMI Electronics Co., Ltd." },
{ "0006BB", "ATI Technologies Inc." },
{ "0006C5", "INNOVI Technologies Limited" },
{ "0006AF", "Xalted Networks" },
{ "000719", "Mobiis Co., Ltd." },
{ "000720", "Trutzschler GmbH & Co. KG" },
{ "000713", "IP One, Inc." },
{ "00070D", "Cisco Systems, Inc" },
{ "000714", "Brightcom" },
{ "0006F1", "Optillion" },
{ "0006F0", "Digeo, Inc." },
{ "0006FB", "Hitachi Printing Solutions, Ltd." },
{ "0006EB", "Global Data" },
{ "0005F2", "Power R, Inc." },
{ "0005FE", "Traficon N.V." },
{ "0005E5", "Renishaw PLC" },
{ "0005F8", "Real Time Access, Inc." },
{ "0005FF", "SNS Solutions, Inc." },
{ "0005DD", "Cisco Systems, Inc" },
{ "0005D9", "Techno Valley, Inc." },
{ "0005C6", "Triz Communications" },
{ "0005CC", "Sumtel Communications, Inc." },
{ "00044C", "JENOPTIK" },
{ "000448", "Polaroid Corporation" },
{ "00043C", "SONOS Co., Ltd." },
{ "000441", "Half Dome Systems, Inc." },
{ "000435", "Comptek International, Inc." },
{ "00042F", "International Communications Products, Inc." },
{ "000429", "Pixord Corporation" },
{ "000422", "Gordon Kapes, Inc." },
{ "00041C", "ipDialog, Inc." },
{ "00041D", "Corega of America" },
{ "000416", "Parks S/A Comunicacoes Digitais" },
{ "000410", "Spinnaker Networks, Inc." },
{ "00040F", "Asus Network Technologies, Inc." },
{ "00040A", "Sage Systems" },
{ "000403", "Nexsi Corporation" },
{ "0004F8", "QUALICABLE TV Industria E Com., Ltda" },
{ "0004F2", "Polycom" },
{ "0004EB", "Paxonet Communications, Inc." },
{ "0004EC", "Memobox SA" },
{ "0004E6", "Banyan Network Private Limited" },
{ "0004DC", "Nortel Networks" },
{ "0004E1", "Infinior Microsystems" },
{ "0004DB", "Tellus Group Corp." },
{ "0004E2", "SMC Networks, Inc." },
{ "0004D5", "Hitachi Information & Communication Engineering, Ltd." },
{ "0004CF", "Seagate Technology" },
{ "0004C9", "Micro Electron Co., Ltd." },
{ "000487", "Cogency Semiconductor, Inc." },
{ "000482", "Medialogic Corp." },
{ "000478", "G. Star Technology Corporation" },
{ "000471", "IPrad" },
{ "00046B", "Palm Wireless, Inc." },
{ "000465", "i.s.t isdn-support technik GmbH" },
{ "000459", "Veristar Corporation" },
{ "00045E", "PolyTrax Information Technology AG" },
{ "000458", "Fusion X Co., Ltd." },
{ "000452", "RocketLogix, Inc." },
{ "000442", "NACT" },
{ "0003F9", "Pleiades Communications, Inc." },
{ "0003E2", "Comspace Corporation" },
{ "0003F4", "NetBurner" },
{ "0003F3", "Dazzle Multimedia, Inc." },
{ "0003ED", "Shinkawa Electric Co., Ltd." },
{ "0003E7", "Logostek Co. Ltd." },
{ "0003DF", "Desana Systems" },
{ "0003DB", "Apogee Electronics Corp." },
{ "0003D6", "RADVision, Ltd." },
{ "0003CF", "Muxcom, Inc." },
{ "0003C8", "CML Emergency Services" },
{ "0003C3", "Micronik Multimedia" },
{ "0003C0", "RFTNC Co., Ltd." },
{ "0003BC", "COT GmbH" },
{ "0003B1", "Hospira Inc." },
{ "0003A5", "Medea Corporation" },
{ "0003AA", "Watlow" },
{ "0003A2", "Catapult Communications" },
{ "000397", "Watchfront Limited" },
{ "00039E", "Tera System Co., Ltd." },
{ "000392", "Hyundai Teletek Co., Ltd." },
{ "00038F", "Weinschel Corporation" },
{ "00038B", "PLUS-ONE I&T, Inc." },
{ "000386", "Ho Net, Inc." },
{ "00037D", "Stellcom" },
{ "000382", "A-One Co., Ltd." },
{ "00037A", "Taiyo Yuden Co., Ltd." },
{ "000376", "Graphtec Technology, Inc." },
{ "000369", "Nippon Antenna Co., Ltd." },
{ "00036F", "Telsey SPA" },
{ "000363", "Miraesys Co., Ltd." },
{ "00035E", "Metropolitan Area Networks, Inc." },
{ "000357", "Intervoice-Brite, Inc." },
{ "00034C", "Shanghai DigiVision Technology Co., Ltd." },
{ "000351", "Diebold, Inc." },
{ "000311", "Micro Technology Co., Ltd." },
{ "00030A", "Argus Technologies" },
{ "000302", "Charles Industries, Ltd." },
{ "000305", "MSC Vertriebs GmbH" },
{ "0002FE", "Viditec, Inc." },
{ "0002F2", "eDevice, Inc." },
{ "0002F7", "ARM" },
{ "0002EC", "Maschoff Design Engineering" },
{ "0002E4", "JC HYUN Systems, Inc." },
{ "0002E7", "CAB GmbH & Co KG" },
{ "0002E0", "ETAS GmbH" },
{ "0002D9", "Reliable Controls" },
{ "0002D4", "PDA Peripherals, Inc." },
{ "0002D1", "Vivotek, Inc." },
{ "0002CD", "TeleDream, Inc." },
{ "000349", "Vidicode Datacommunicatie B.V." },
{ "000340", "Floware Wireless Systems, Ltd." },
{ "008037", "Ericsson Group" },
{ "000332", "Cisco Systems, Inc" },
{ "000339", "Eurologic Systems, Ltd." },
{ "00032A", "UniData Communication Systems, Inc." },
{ "00032D", "IBASE Technology, Inc." },
{ "000326", "Iwasaki Information Systems Co., Ltd." },
{ "00031D", "Taiwan Commate Computer, Inc." },
{ "000318", "Cyras Systems, Inc." },
{ "0004C2", "Magnipix, Inc." },
{ "0004B6", "Stratex Networks, Inc." },
{ "0004BC", "Giantec, Inc." },
{ "0004B0", "ELESIGN Co., Ltd." },
{ "0004A9", "SandStream Technologies, Inc." },
{ "0004A8", "Broadmax Technologies, Inc." },
{ "0004A2", "L.S.I. Japan Co., Ltd." },
{ "00049B", "Cisco Systems, Inc" },
{ "00049C", "Surgient Networks, Inc." },
{ "000496", "Extreme Networks" },
{ "00048F", "TD Systems Corporation" },
{ "000488", "Eurotherm Controls" },
{ "000281", "Madge Ltd." },
{ "009064", "Thomson Inc." },
{ "00027F", "ask-technologies.com" },
{ "00027A", "IOI Technology Corporation" },
{ "000273", "Coriolis Networks" },
{ "00026E", "NeGeN Access, Inc." },
{ "000263", "UPS Manufacturing SRL" },
{ "00025C", "SCI Systems (Kunshan) Co., Ltd." },
{ "000253", "Televideo, Inc." },
{ "00024C", "SiByte, Inc." },
{ "00024E", "Datacard Group" },
{ "00012F", "Twinhead International Corp" },
{ "00023C", "Creative Technology, Ltd." },
{ "000240", "Seedek Co., Ltd." },
{ "000247", "Great Dragon Information Technology (Group) Co., Ltd." },
{ "000243", "Raysis Co., Ltd." },
{ "000239", "Visicom" },
{ "000236", "INIT GmbH" },
{ "000231", "Ingersoll-Rand" },
{ "00022A", "Asound Electronic" },
{ "00022D", "Agere Systems" },
{ "000219", "Paralon Technologies" },
{ "000186", "Uwe Disch" },
{ "00017B", "Heidelberger Druckmaschinen AG" },
{ "000182", "DICA TECHNOLOGIES AG" },
{ "00018E", "Logitec Corporation" },
{ "00019B", "Kyoto Microcomputer Co., Ltd." },
{ "000194", "Capital Equipment Corporation" },
{ "000197", "Cisco Systems, Inc" },
{ "0001A3", "GENESYS LOGIC, INC." },
{ "00014E", "WIN Enterprises, Inc." },
{ "0030AC", "Systeme Lauer GmbH & Co., Ltd." },
{ "00013E", "Ascom Tateco AB" },
{ "000145", "WINSYSTEMS, INC." },
{ "000126", "PAC Labs" },
{ "00011A", "Hoffmann und Burmeister GbR" },
{ "00011D", "Centillium Communications" },
{ "000129", "DFI Inc." },
{ "000107", "Leiser GmbH" },
{ "00010E", "Bri-Link Technologies Co., Ltd" },
{ "000116", "Netspect Technologies, Inc." },
{ "000103", "3COM CORPORATION" },
{ "00062B", "INTRASERVER TECHNOLOGY" },
{ "0002C1", "Innovative Electronic Designs, Inc." },
{ "0002C8", "Technocom Communications Technology (pte) Ltd" },
{ "0002A9", "RACOM, s.r.o." },
{ "0002B8", "WHI KONSULT AB" },
{ "0002AC", "3PAR data" },
{ "0002B1", "Anritsu, Ltd." },
{ "00029A", "Storage Apps" },
{ "0002A0", "Flatstack Ltd." },
{ "000295", "IP.Access Limited" },
{ "000294", "Tokyo Sokushin Co., Ltd." },
{ "000290", "Woorigisool, Inc." },
{ "000286", "Occam Networks" },
{ "00028B", "VDSL Systems OY" },
{ "000222", "Chromisys, Inc." },
{ "00021D", "Data General Communication Ltd." },
{ "00020A", "Gefran Spa" },
{ "000216", "Cisco Systems, Inc" },
{ "000206", "Telital R&D Denmark A/S" },
{ "000203", "Woonsang Telecom, Inc." },
{ "0001F7", "Image Display Systems, Inc." },
{ "0001EE", "Comtrol Europe, Ltd." },
{ "0001E2", "Ando Electric Corporation" },
{ "0001F1", "Innovative Concepts, Inc." },
{ "00B06D", "Jones Futurex Inc." },
{ "0030FE", "DSA GmbH" },
{ "00305E", "Abelko Innovation" },
{ "00301E", "3COM EUROPE LTD." },
{ "00304D", "ESI" },
{ "003046", "Controlled Electronic Manageme" },
{ "00307B", "Cisco Systems, Inc" },
{ "0001D6", "manroland AG" },
{ "0001DB", "Freecom Technologies GmbH" },
{ "0001DE", "Trango Systems, Inc." },
{ "0001CF", "Alpha Data Parallel Systems, Ltd." },
{ "0001CB", "EVR" },
{ "0001C4", "NeoWave, Inc." },
{ "0001C0", "CompuLab, Ltd." },
{ "0001B9", "SKF Condition Monitoring" },
{ "0001B5", "Turin Networks, Inc." },
{ "00017F", "Experience Music Project" },
{ "00016C", "FOXCONN" },
{ "000173", "AMCC" },
{ "00015C", "CADANT INC." },
{ "000163", "Cisco Systems, Inc" },
{ "00010A", "CIS TECHNOLOGY INC." },
{ "00016F", "Inkel Corp." },
{ "000155", "Promise Technology, Inc." },
{ "000151", "Ensemble Communications" },
{ "000142", "Cisco Systems, Inc" },
{ "000132", "Dranetz - BMI" },
{ "00D07D", "COSINE COMMUNICATIONS" },
{ "00D0CA", "Intrinsyc Software International Inc." },
{ "00D058", "Cisco Systems, Inc" },
{ "00D067", "CAMPIO COMMUNICATIONS" },
{ "00D023", "INFORTREND TECHNOLOGY, INC." },
{ "00D02A", "Voxent Systems Ltd." },
{ "00D068", "IWILL CORPORATION" },
{ "00D09D", "VERIS INDUSTRIES" },
{ "00D09A", "FILANET CORPORATION" },
{ "00D00A", "LANACCESS TELECOM S.A." },
{ "00D04A", "PRESENCE TECHNOLOGY GMBH" },
{ "00D0C3", "VIVID TECHNOLOGY PTE, LTD." },
{ "00D0F8", "FUJIAN STAR TERMINAL" },
{ "00D096", "3COM EUROPE LTD." },
{ "00D003", "COMDA ENTERPRISES CORP." },
{ "00D029", "WAKEFERN FOOD CORPORATION" },
{ "00D0F5", "ORANGE MICRO, INC." },
{ "00D0F7", "NEXT NETS CORPORATION" },
{ "00D078", "Eltex of Sweden AB" },
{ "00D0AF", "CUTLER-HAMMER, INC." },
{ "00D026", "HIRSCHMANN AUSTRIA GMBH" },
{ "00D037", "Pace France" },
{ "00D010", "CONVERGENT NETWORKS, INC." },
{ "00D074", "TAQUA SYSTEMS, INC." },
{ "00D0D5", "GRUNDIG AG" },
{ "00D034", "ORMEC SYSTEMS CORP." },
{ "00D08C", "GENOA TECHNOLOGY, INC." },
{ "00D059", "AMBIT MICROSYSTEMS CORP." },
{ "005020", "MEDIASTAR CO., LTD." },
{ "00503E", "Cisco Systems, Inc" },
{ "00D02B", "JETCELL, INC." },
{ "005017", "RSR S.R.L." },
{ "00D0CC", "TECHNOLOGIES LYRE INC." },
{ "00506D", "VIDEOJET SYSTEMS" },
{ "005077", "PROLIFIC TECHNOLOGY, INC." },
{ "0050D4", "JOOHONG INFORMATION &" },
{ "00505E", "DIGITEK MICROLOGIC S.A." },
{ "0050E7", "PARADISE INNOVATIONS (ASIA)" },
{ "0050B9", "XITRON TECHNOLOGIES, INC." },
{ "00D049", "IMPRESSTEK CO., LTD." },
{ "00D04D", "DIV OF RESEARCH & STATISTICS" },
{ "00D035", "BEHAVIOR TECH. COMPUTER CORP." },
{ "00D02D", "ADEMCO" },
{ "00D07C", "KOYO ELECTRONICS INC. CO.,LTD." },
{ "00D05B", "ACROLOOP MOTION CONTROL" },
{ "00D0C6", "THOMAS & BETTS CORP." },
{ "00D02E", "COMMUNICATION AUTOMATION CORP." },
{ "00D0DA", "TAICOM DATA SYSTEMS CO., LTD." },
{ "00D0E8", "MAC SYSTEM CO., LTD." },
{ "00D03C", "Vieo, Inc." },
{ "00D09F", "NOVTEK TEST SYSTEMS" },
{ "00D07E", "KEYCORP LTD." },
{ "00D0EA", "NEXTONE COMMUNICATIONS, INC." },
{ "00D020", "AIM SYSTEM, INC." },
{ "00D064", "MULTITEL" },
{ "00D072", "BROADLOGIC" },
{ "00309B", "Smartware" },
{ "0030AF", "Honeywell GmbH" },
{ "003074", "EQUIINET LTD." },
{ "003090", "CYRA TECHNOLOGIES, INC." },
{ "003030", "HARMONIX CORPORATION" },
{ "00307C", "ADID SA" },
{ "003063", "SANTERA SYSTEMS, INC." },
{ "00309F", "AMBER NETWORKS" },
{ "0030A8", "OL'E COMMUNICATIONS, INC." },
{ "00304C", "APPIAN COMMUNICATIONS, INC." },
{ "0030EF", "NEON TECHNOLOGY, INC." },
{ "00306F", "SEYEON TECH. CO., LTD." },
{ "003031", "LIGHTWAVE COMMUNICATIONS, INC." },
{ "003035", "Corning Incorporated" },
{ "00302B", "INALP NETWORKS, INC." },
{ "00305F", "Hasselblad" },
{ "00302D", "QUANTUM BRIDGE COMMUNICATIONS" },
{ "003025", "CHECKOUT COMPUTER SYSTEMS, LTD" },
{ "00D01F", "Senetas Security" },
{ "003012", "DIGITAL ENGINEERING LTD." },
{ "003077", "ONPREM NETWORKS" },
{ "0030D4", "AAE Systems, Inc." },
{ "00D00F", "SPEECH DESIGN GMBH" },
{ "00D0CF", "MORETON BAY" },
{ "00D073", "ACN ADVANCED COMMUNICATIONS" },
{ "00D030", "Safetran Systems Corp" },
{ "00D057", "ULTRAK, INC." },
{ "00D03B", "VISION PRODUCTS PTY. LTD." },
{ "00D0BF", "PIVOTAL TECHNOLOGIES" },
{ "00D050", "ISKRATEL" },
{ "00D0CB", "DASAN CO., LTD." },
{ "00D0D3", "Cisco Systems, Inc" },
{ "00D08E", "Grass Valley, A Belden Brand" },
{ "00D0A3", "VOCAL DATA, INC." },
{ "00D0E0", "DOOIN ELECTRONICS CO." },
{ "003054", "CASTLENET TECHNOLOGY, INC." },
{ "003039", "SOFTBOOK PRESS" },
{ "003017", "BlueArc UK Ltd" },
{ "003076", "Akamba Corporation" },
{ "00305D", "DIGITRA SYSTEMS, INC." },
{ "0030F7", "RAMIX INC." },
{ "003033", "ORIENT TELECOM CO., LTD." },
{ "003083", "Ivron Systems" },
{ "003007", "OPTI, INC." },
{ "0030DD", "INDIGITA CORPORATION" },
{ "0030F2", "Cisco Systems, Inc" },
{ "003020", "TSI, Inc.." },
{ "003089", "Spectrapoint Wireless, LLC" },
{ "003022", "Fong Kai Industrial Co., Ltd." },
{ "0030F8", "Dynapro Systems, Inc." },
{ "0030C2", "COMONE" },
{ "003056", "Beck IPC GmbH" },
{ "0030D2", "WIN TECHNOLOGIES, CO., LTD." },
{ "003050", "Versa Technology" },
{ "0030B8", "RiverDelta Networks" },
{ "00904D", "SPEC S.A." },
{ "009079", "ClearOne, Inc." },
{ "00908F", "AUDIO CODES LTD." },
{ "0090D5", "EUPHONIX, INC." },
{ "0090A7", "CLIENTEC CORPORATION" },
{ "00907F", "WatchGuard Technologies, Inc." },
{ "00907E", "VETRONIX CORP." },
{ "00902F", "NETCORE SYSTEMS, INC." },
{ "00900D", "Overland Storage Inc." },
{ "009044", "ASSURED DIGITAL, INC." },
{ "009078", "MER TELEMANAGEMENT SOLUTIONS, LTD." },
{ "009009", "I Controls, Inc." },
{ "009015", "CENTIGRAM COMMUNICATIONS CORP." },
{ "0090F3", "ASPECT COMMUNICATIONS" },
{ "0090A8", "NineTiles Networks, Ltd." },
{ "00507A", "XPEED, INC." },
{ "005002", "OMNISEC AG" },
{ "00508D", "ABIT COMPUTER CORPORATION" },
{ "0050CD", "DIGIANSWER A/S" },
{ "0050C5", "ADS Technologies, Inc" },
{ "00502F", "TollBridge Technologies, Inc." },
{ "005028", "AVAL COMMUNICATIONS" },
{ "00505B", "KAWASAKI LSI U.S.A., INC." },
{ "0050F8", "ENTREGA TECHNOLOGIES, INC." },
{ "00506F", "G-CONNECT" },
{ "0050CC", "XYRATEX" },
{ "0050D5", "AD SYSTEMS CORP." },
{ "0050AA", "KONICA MINOLTA HOLDINGS, INC." },
{ "00509C", "BETA RESEARCH" },
{ "005027", "GENICOM CORPORATION" },
{ "005010", "NovaNET Learning, Inc." },
{ "00509E", "Les Technologies SoftAcoustik Inc." },
{ "00505F", "BRAND INNOVATORS" },
{ "005095", "PERACOM NETWORKS" },
{ "005026", "COSYSTEMS, INC." },
{ "0050EF", "SPE Systemhaus GmbH" },
{ "005093", "BOEING" },
{ "0050D8", "UNICORN COMPUTER CORP." },
{ "90C682", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "0055DA", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "DC4427", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "A03E6B", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "009034", "IMAGIC, INC." },
{ "009073", "GAIO TECHNOLOGY" },
{ "0090C9", "DPAC Technologies" },
{ "0090E7", "HORSCH ELEKTRONIK AG" },
{ "009001", "NISHIMU ELECTRONICS INDUSTRIES CO., LTD." },
{ "0090FB", "PORTWELL, INC." },
{ "009070", "NEO NETWORKS, INC." },
{ "0090EF", "INTEGRIX, INC." },
{ "0090B0", "VADEM" },
{ "0090D1", "LEICHU ENTERPRISE CO., LTD." },
{ "0050D7", "TELSTRAT" },
{ "0050F1", "Intel Corporation" },
{ "00501B", "ABL CANADA, INC." },
{ "005036", "NETCAM, LTD." },
{ "0050C9", "MASPRO DENKOH CORP." },
{ "005009", "PHILIPS BROADBAND NETWORKS" },
{ "0050C4", "IMD" },
{ "0050A3", "TransMedia Communications, Inc." },
{ "005099", "3COM EUROPE, LTD." },
{ "0050A4", "IO TECH, INC." },
{ "0050B3", "VOICEBOARD CORPORATION" },
{ "0050B7", "BOSER TECHNOLOGY CO., LTD." },
{ "005056", "VMware, Inc." },
{ "00908D", "VICKERS ELECTRONICS SYSTEMS" },
{ "009042", "ECCS, Inc." },
{ "009051", "ULTIMATE TECHNOLOGY CORP." },
{ "0090FF", "TELLUS TECHNOLOGY INC." },
{ "009018", "ITO ELECTRIC INDUSTRY CO, LTD." },
{ "009002", "ALLGON AB" },
{ "009016", "ZAC" },
{ "009005", "PROTECH SYSTEMS CO., LTD." },
{ "00901E", "Selesta Ingegneria S.p.A." },
{ "009090", "I-BUS" },
{ "0090AA", "INDIGO ACTIVE VISION SYSTEMS LIMITED" },
{ "00903A", "NIHON MEDIA TOOL INC." },
{ "009055", "PARKER HANNIFIN CORPORATION COMPUMOTOR DIVISION" },
{ "00909F", "DIGI-DATA CORPORATION" },
{ "0090E4", "NEC AMERICA, INC." },
{ "009013", "SAMSAN CORP." },
{ "0090CC", "Planex Communications" },
{ "009004", "3COM EUROPE LTD." },
{ "0090E1", "TELENA S.P.A." },
{ "00504A", "ELTECO A.S." },
{ "00504C", "Galil Motion Control" },
{ "005021", "EIS INTERNATIONAL, INC." },
{ "00506E", "CORDER ENGINEERING CORPORATION" },
{ "00507E", "NEWER TECHNOLOGY" },
{ "0050E6", "HAKUSAN CORPORATION" },
{ "0050AE", "FDK Co., Ltd" },
{ "00109D", "CLARINET SYSTEMS, INC." },
{ "0010D2", "NITTO TSUSHINKI CO., LTD" },
{ "001045", "Nortel Networks" },
{ "00106B", "SONUS NETWORKS, INC." },
{ "0010EC", "RPCG, LLC" },
{ "001092", "NETCORE INC." },
{ "0010E2", "ArrayComm, Inc." },
{ "001071", "ADVANET INC." },
{ "001069", "HELIOSS COMMUNICATIONS, INC." },
{ "0010FD", "COCOM A/S" },
{ "0010AC", "IMCI TECHNOLOGIES" },
{ "0010EF", "DBTEL INCORPORATED" },
{ "001017", "Bosch Access Systems GmbH" },
{ "001024", "NAGOYA ELECTRIC WORKS CO., LTD" },
{ "0010DD", "ENABLE SEMICONDUCTOR, INC." },
{ "0010C9", "MITSUBISHI ELECTRONICS LOGISTIC SUPPORT CO." },
{ "001085", "POLARIS COMMUNICATIONS, INC." },
{ "001044", "InnoLabs Corporation" },
{ "001056", "SODICK CO., LTD." },
{ "001099", "InnoMedia, Inc." },
{ "001061", "HOSTLINK CORP." },
{ "001093", "CMS COMPUTERS, LTD." },
{ "0010CD", "INTERFACE CONCEPT" },
{ "0010F3", "Nexcom International Co., Ltd." },
{ "001005", "UEC COMMERCIAL" },
{ "001066", "ADVANCED CONTROL SYSTEMS, INC." },
{ "0010E4", "NSI CORPORATION" },
{ "001062", "NX SERVER, ILNC." },
{ "0010B9", "MAXTOR CORP." },
{ "00108B", "LASERANIMATION SOLLINGER GMBH" },
{ "00105C", "QUANTUM DESIGNS (H.K.) LTD." },
{ "001042", "Alacritech, Inc." },
{ "001060", "BILLIONTON SYSTEMS, INC." },
{ "0010DE", "INTERNATIONAL DATACASTING CORPORATION" },
{ "00105D", "Draeger Medical" },
{ "0010E1", "S.I. TECH, INC." },
{ "001091", "NO WIRES NEEDED BV" },
{ "0010F5", "AMHERST SYSTEMS, INC." },
{ "001090", "CIMETRICS, INC." },
{ "001070", "CARADON TREND LTD." },
{ "0010BA", "MARTINHO-DAVIS SYSTEMS, INC." },
{ "00107C", "P-COM, INC." },
{ "0010AE", "SHINKO ELECTRIC INDUSTRIES CO." },
{ "001040", "INTERMEC CORPORATION" },
{ "0010B0", "MERIDIAN TECHNOLOGY CORP." },
{ "001077", "SAF DRIVE SYSTEMS, LTD." },
{ "0010F4", "Vertical Communications" },
{ "001065", "RADYNE CORPORATION" },
{ "00104A", "The Parvus Corporation" },
{ "0010B3", "NOKIA MULTIMEDIA TERMINALS" },
{ "001037", "CYQ've Technology Co., Ltd." },
{ "0010CA", "Telco Systems, Inc. " },
{ "001051", "CMICRO CORPORATION" },
{ "0010DC", "MICRO-STAR INTERNATIONAL CO., LTD." },
{ "0010EE", "CTI PRODUCTS, INC." },
{ "00101B", "CORNET TECHNOLOGY, INC." },
{ "001032", "ALTA TECHNOLOGY" },
{ "001025", "Grayhill, Inc" },
{ "001009", "HORO QUARTZ" },
{ "0010F8", "TEXIO TECHNOLOGY CORPORATION" },
{ "00104D", "SURTEC INDUSTRIES, INC." },
{ "00E0E0", "SI ELECTRONICS, LTD." },
{ "00E00F", "SHANGHAI BAUD DATA" },
{ "00E0D1", "TELSIS LIMITED" },
{ "00E005", "TECHNICAL CORP." },
{ "00E072", "LYNK" },
{ "00E0C1", "MEMOREX TELEX JAPAN, LTD." },
{ "00E0AD", "EES TECHNOLOGY, LTD." },
{ "00E025", "dit Co., Ltd." },
{ "00E0B1", "Alcatel-Lucent, Enterprise Business Group" },
{ "00E0E4", "FANUC ROBOTICS NORTH AMERICA, Inc." },
{ "00E031", "HAGIWARA ELECTRIC CO., LTD." },
{ "00E0A5", "ComCore Semiconductor, Inc." },
{ "00E044", "LSICS CORPORATION" },
{ "00E05D", "UNITEC CO., LTD." },
{ "00E0B3", "EtherWAN Systems, Inc." },
{ "00E053", "CELLPORT LABS, INC." },
{ "00E07D", "NETRONIX, INC." },
{ "00E0ED", "SILICOM, LTD." },
{ "00E0B4", "TECHNO SCOPE CO., LTD." },
{ "00E0C6", "LINK2IT, L.L.C." },
{ "00E06D", "COMPUWARE CORPORATION" },
{ "00E0E6", "INCAA DATACOM B.V." },
{ "00E074", "TIERNAN COMMUNICATIONS, INC." },
{ "00E059", "CONTROLLED ENVIRONMENTS, LTD." },
{ "00E006", "SILICON INTEGRATED SYS. CORP." },
{ "00E0F8", "DICNA CONTROL AB" },
{ "00E004", "PMC-SIERRA, INC." },
{ "00E0DE", "DATAX NV" },
{ "00E078", "BERKELEY NETWORKS" },
{ "00E041", "CSPI" },
{ "00E0E2", "INNOVA CORP." },
{ "00E009", "MARATHON TECHNOLOGIES CORP." },
{ "00E02F", "MCNS HOLDINGS, L.P." },
{ "00E04C", "REALTEK SEMICONDUCTOR CORP." },
{ "00E047", "InFocus Corporation" },
{ "00E092", "ADMTEK INCORPORATED" },
{ "00E0FF", "SECURITY DYNAMICS TECHNOLOGIES, Inc." },
{ "08BBCC", "AK-NORD EDV VERTRIEBSGES. mbH" },
{ "0060B2", "PROCESS CONTROL CORP." },
{ "006004", "COMPUTADORES MODULARES SA" },
{ "0060D6", "NovAtel Wireless Technologies Ltd." },
{ "006000", "XYCOM INC." },
{ "00A019", "NEBULA CONSULTANTS, INC." },
{ "00A0ED", "Brooks Automation, Inc." },
{ "00A0A9", "NAVTEL COMMUNICATIONS INC." },
{ "00A0E1", "WESTPORT RESEARCH ASSOCIATES, INC." },
{ "00A0D6", "SBE, Inc." },
{ "00A05E", "MYRIAD LOGIC INC." },
{ "00A078", "Marconi Communications" },
{ "00A00B", "COMPUTEX CO., LTD." },
{ "00A09A", "NIHON KOHDEN AMERICA" },
{ "00A095", "ACACIA NETWORKS, INC." },
{ "00A0F2", "INFOTEK COMMUNICATIONS, INC." },
{ "00A0EF", "LUCIDATA LTD." },
{ "00A03F", "COMPUTER SOCIETY MICROPROCESSOR & MICROPROCESSOR STANDARDS C" },
{ "00A067", "NETWORK SERVICES GROUP" },
{ "00A0A7", "VORAX CORPORATION" },
{ "00A02D", "1394 Trade Association" },
{ "00A0E6", "DIALOGIC CORPORATION" },
{ "00A04A", "NISSHIN ELECTRIC CO., LTD." },
{ "00A05B", "MARQUIP, INC." },
{ "00A08D", "JACOMO CORPORATION" },
{ "00A06F", "THE APPCON GROUP, INC." },
{ "00A08E", "Check Point Software Technologies" },
{ "00E0AA", "ELECTROSONIC LTD." },
{ "00E085", "GLOBAL MAINTECH, INC." },
{ "00E05A", "GALEA NETWORK SECURITY" },
{ "00E022", "Analog Devices Inc." },
{ "00E0E7", "RAYTHEON E-SYSTEMS, INC." },
{ "00E00C", "MOTOROLA" },
{ "00E04A", "ZX Technologies, Inc" },
{ "00E00A", "DIBA, INC." },
{ "00E0B9", "BYAS SYSTEMS" },
{ "00E054", "KODAI HITEC CO., LTD." },
{ "00E0AF", "GENERAL DYNAMICS INFORMATION SYSTEMS" },
{ "00605B", "IntraServer Technology, Inc." },
{ "00604B", "Safe-com GmbH & Co. KG" },
{ "00A0CD", "DR. JOHANNES HEIDENHAIN GmbH" },
{ "00A0DA", "INTEGRATED SYSTEMS Technology, Inc." },
{ "00A03C", "EG&G NUCLEAR INSTRUMENTS" },
{ "00A038", "EMAIL ELECTRONICS" },
{ "00A0BE", "INTEGRATED CIRCUIT SYSTEMS, INC. COMMUNICATIONS GROUP" },
{ "00605D", "SCANIVALVE CORP." },
{ "0060E4", "COMPUSERVE, INC." },
{ "00600A", "SORD COMPUTER CORPORATION" },
{ "0060C4", "SOLITON SYSTEMS K.K." },
{ "0060C8", "KUKA WELDING SYSTEMS & ROBOTS" },
{ "006030", "VILLAGE TRONIC ENTWICKLUNG" },
{ "0060E7", "RANDATA" },
{ "00602A", "SYMICRON COMPUTER COMMUNICATIONS, LTD." },
{ "00601E", "SOFTLAB, INC." },
{ "0060F8", "Loran International Technologies Inc." },
{ "006088", "WHITE MOUNTAIN DSP, INC." },
{ "00609A", "NJK TECHNO CO." },
{ "0060CC", "EMTRAK, INCORPORATED" },
{ "006036", "AIT Austrian Institute of Technology GmbH" },
{ "0060B9", "NEC Platforms, Ltd" },
{ "0060CE", "ACCLAIM COMMUNICATIONS" },
{ "0060F5", "ICON WEST, INC." },
{ "0060A4", "GEW Technologies (PTY)Ltd" },
{ "0060CA", "HARMONIC SYSTEMS INCORPORATED" },
{ "006024", "GRADIENT TECHNOLOGIES, INC." },
{ "0060FB", "PACKETEER, INC." },
{ "0060BC", "KeunYoung Electronics & Communication Co., Ltd." },
{ "0060B8", "CORELIS Inc." },
{ "0060FE", "LYNX SYSTEM DEVELOPERS, INC." },
{ "006001", "InnoSys, Inc." },
{ "00607D", "SENTIENT NETWORKS INC." },
{ "00606E", "DAVICOM SEMICONDUCTOR, INC." },
{ "00607E", "GIGALABS, INC." },
{ "0060CF", "ALTEON NETWORKS, INC." },
{ "006026", "VIKING Modular Solutions" },
{ "006003", "TERAOKA WEIGH SYSTEM PTE, LTD." },
{ "006059", "TECHNICAL COMMUNICATIONS CORP." },
{ "006066", "LACROIX Trafic" },
{ "0060DA", "Red Lion Controls, LP" },
{ "006042", "TKS (USA), INC." },
{ "00A023", "APPLIED CREATIVE TECHNOLOGY, INC." },
{ "00A00F", "Broadband Technologies" },
{ "00A032", "GES SINGAPORE PTE. LTD." },
{ "002034", "ROTEC INDUSTRIEAUTOMATION GMBH" },
{ "0020B2", "GKD Gesellschaft Fur Kommunikation Und Datentechnik" },
{ "002004", "YAMATAKE-HONEYWELL CO., LTD." },
{ "0020FE", "TOPWARE INC. / GRAND COMPUTER" },
{ "002073", "FUSION SYSTEMS CORPORATION" },
{ "00207A", "WiSE Communications, Inc." },
{ "00205C", "InterNet Systems of Florida, Inc." },
{ "00207E", "FINECOM CO., LTD." },
{ "00205A", "COMPUTER IDENTICS" },
{ "0020E4", "HSING TECH ENTERPRISE CO., LTD" },
{ "00A000", "CENTILLION NETWORKS, INC." },
{ "00A07B", "DAWN COMPUTER INCORPORATION" },
{ "00A05C", "INVENTORY CONVERSION, INC./" },
{ "00206F", "FLOWPOINT CORPORATION" },
{ "0020DF", "KYOSAN ELECTRIC MFG. CO., LTD." },
{ "002010", "JEOL SYSTEM TECHNOLOGY CO. LTD" },
{ "002020", "MEGATRON COMPUTER INDUSTRIES PTY, LTD." },
{ "002037", "SEAGATE TECHNOLOGY" },
{ "0020A0", "OA LABORATORY CO., LTD." },
{ "00C0A3", "DUAL ENTERPRISES CORPORATION" },
{ "00C095", "ZNYX" },
{ "0070B0", "M/A-COM INC. COMPANIES" },
{ "009D8E", "CARDIAC RECORDERS, INC." },
{ "006086", "LOGIC REPLACEMENT TECH. LTD." },
{ "001C7C", "PERQ SYSTEMS CORPORATION" },
{ "00C059", "DENSO CORPORATION" },
{ "00C0A9", "BARRON MCCANN LTD." },
{ "00C069", "Axxcelera Broadband Wireless" },
{ "00C019", "LEAP TECHNOLOGY, INC." },
{ "00A062", "AES PRODATA" },
{ "00A008", "NETCORP" },
{ "00A01B", "PREMISYS COMMUNICATIONS, INC." },
{ "00A04B", "TFL LAN INC." },
{ "00A015", "WYLE" },
{ "00A011", "MUTOH INDUSTRIES LTD." },
{ "00A0B6", "SANRITZ AUTOMATION CO., LTD." },
{ "00A0DD", "AZONIX CORPORATION" },
{ "00A00A", "Airspan" },
{ "00A03B", "TOSHIN ELECTRIC CO., LTD." },
{ "00A0F3", "STAUBLI" },
{ "00A097", "JC INFORMATION SYSTEMS" },
{ "00A082", "NKT ELEKTRONIK A/S" },
{ "00A072", "OVATION SYSTEMS LTD." },
{ "00A0B2", "SHIMA SEIKI" },
{ "00A0E5", "NHC COMMUNICATIONS" },
{ "00A0D3", "INSTEM COMPUTER SYSTEMS, LTD." },
{ "00A0BA", "PATTON ELECTRONICS CO." },
{ "00A0B4", "TEXAS MICROSYSTEMS, INC." },
{ "00A0AF", "WMS INDUSTRIES" },
{ "00A0FE", "BOSTON TECHNOLOGY, INC." },
{ "00202F", "ZETA COMMUNICATIONS, LTD." },
{ "002060", "ALCATEL ITALIA S.p.A." },
{ "00209A", "THE 3DO COMPANY" },
{ "00205E", "CASTLE ROCK, INC." },
{ "00207C", "AUTEC GMBH" },
{ "002075", "MOTOROLA COMMUNICATION ISRAEL" },
{ "002015", "ACTIS COMPUTER SA" },
{ "0020E9", "DANTEL" },
{ "00204A", "PRONET GMBH" },
{ "002029", "TELEPROCESSING PRODUCTS, INC." },
{ "002051", "Verilink Corporation" },
{ "0020A1", "DOVATRON" },
{ "002024", "PACIFIC COMMUNICATION SCIENCES" },
{ "00209D", "LIPPERT AUTOMATIONSTECHNIK" },
{ "002041", "DATA NET" },
{ "002076", "REUDO CORPORATION" },
{ "00206E", "XACT, INC." },
{ "0020CA", "DIGITAL OCEAN" },
{ "002085", "Eaton Corporation" },
{ "0020CD", "HYBRID NETWORKS, INC." },
{ "0020E7", "B&W NUCLEAR SERVICE COMPANY" },
{ "0020AC", "INTERFLEX DATENSYSTEME GMBH" },
{ "0020F6", "NET TEK  AND KARLNET, INC." },
{ "0020D3", "OST (OUEST STANDARD TELEMATIQU" },
{ "0020D8", "Nortel Networks" },
{ "002017", "ORBOTECH" },
{ "002025", "CONTROL TECHNOLOGY, INC." },
{ "00C08B", "RISQ MODULAR SYSTEMS, INC." },
{ "00C0CD", "COMELTA, S.A." },
{ "00C04B", "CREATIVE MICROSYSTEMS" },
{ "00C0A1", "TOKYO DENSHI SEKEI CO." },
{ "00C03E", "FA. GEBR. HELLER GMBH" },
{ "00C0E1", "SONIC SOLUTIONS" },
{ "00C047", "UNIMICRO SYSTEMS, INC." },
{ "00C046", "Blue Chip Technology Ltd" },
{ "00C00D", "ADVANCED LOGIC RESEARCH, INC." },
{ "00C0FA", "CANARY COMMUNICATIONS, INC." },
{ "00C0B7", "AMERICAN POWER CONVERSION CORP" },
{ "00C0BA", "NETVANTAGE" },
{ "00C0B6", "Overland Storage, Inc." },
{ "00C048", "BAY TECHNICAL ASSOCIATES" },
{ "00C03F", "STORES AUTOMATED SYSTEMS, INC." },
{ "00C00E", "PSITECH, INC." },
{ "00C036", "RAYTECH ELECTRONIC CORP." },
{ "00C009", "KT TECHNOLOGY (S) PTE LTD" },
{ "00C0EA", "ARRAY TECHNOLOGY LTD." },
{ "00C03A", "MEN-MIKRO ELEKTRONIK GMBH" },
{ "00C040", "ECCI" },
{ "00C04C", "DEPARTMENT OF FOREIGN AFFAIRS" },
{ "00C01C", "INTERLINK COMMUNICATIONS LTD." },
{ "00C017", "Fluke Corporation" },
{ "00C086", "THE LYNK CORPORATION" },
{ "00C08D", "TRONIX PRODUCT DEVELOPMENT" },
{ "00C0AB", "Telco Systems, Inc." },
{ "00C0A2", "INTERMEDIUM A/S" },
{ "00C070", "SECTRA SECURE-TRANSMISSION AB" },
{ "00C057", "MYCO ELECTRONICS" },
{ "00C0DF", "KYE Systems Corp." },
{ "00C0F6", "CELAN TECHNOLOGY INC." },
{ "00C08F", "Panasonic Electric Works Co., Ltd." },
{ "00C012", "NETSPAN CORPORATION" },
{ "00C0C4", "COMPUTER OPERATIONAL" },
{ "00C0C2", "INFINITE NETWORKS LTD." },
{ "00C0D3", "OLYMPUS IMAGE SYSTEMS, INC." },
{ "00C0B0", "GCC TECHNOLOGIES,INC." },
{ "00C0F4", "INTERLINK SYSTEM CO., LTD." },
{ "00C0E2", "CALCOMP, INC." },
{ "00C0CA", "ALFA, INC." },
{ "00C07B", "ASCEND COMMUNICATIONS, INC." },
{ "00C052", "BURR-BROWN" },
{ "00C0BE", "ALCATEL - SEL" },
{ "00408F", "WM-DATA MINFO AB" },
{ "0040B7", "STEALTH COMPUTER SYSTEMS" },
{ "004057", "LOCKHEED - SANDERS" },
{ "004017", "Silex Technology America" },
{ "004087", "UBITREX CORPORATION" },
{ "00400E", "MEMOTEC, INC." },
{ "00C09E", "CACHE COMPUTERS, INC." },
{ "00C093", "ALTA RESEARCH CORP." },
{ "00C034", "TRANSACTION NETWORK" },
{ "004034", "BUSTEK CORPORATION" },
{ "004097", "DATEX DIVISION OF" },
{ "00401E", "ICC" },
{ "00407C", "QUME CORPORATION" },
{ "004060", "COMENDEC LTD" },
{ "004056", "MCM JAPAN LTD." },
{ "004095", "R.P.T. INTERGROUPS INT'L LTD." },
{ "0040C3", "FISCHER AND PORTER CO." },
{ "0040F1", "CHUO ELECTRONICS CO., LTD." },
{ "004061", "DATATECH ENTERPRISES CO., LTD." },
{ "00408B", "RAYLAN CORPORATION" },
{ "004020", "CommScope Inc" },
{ "00406E", "COROLLARY, INC." },
{ "004066", "Hitachi Metals, Ltd." },
{ "004016", "ADC - Global Connectivity Solutions Division" },
{ "004086", "MICHELS & KLEBERHOFF COMPUTER" },
{ "0040DC", "TRITEC ELECTRONIC GMBH" },
{ "004074", "CABLE AND WIRELESS" },
{ "004084", "HONEYWELL ACS" },
{ "0040B8", "IDEA ASSOCIATES" },
{ "004058", "KRONOS, INC." },
{ "0040A8", "IMF INTERNATIONAL LTD." },
{ "0080BB", "HUGHES LAN SYSTEMS" },
{ "00C0A0", "ADVANCE MICRO RESEARCH, INC." },
{ "00C0D7", "TAIWAN TRADING CENTER DBA" },
{ "00C037", "DYNATEM" },
{ "00C05F", "FINE-PAL COMPANY LIMITED" },
{ "0040CE", "NET-SOURCE, INC." },
{ "004080", "ATHENIX CORPORATION" },
{ "0040BB", "GOLDSTAR CABLE CO., LTD." },
{ "0040B1", "CODONICS INC." },
{ "00402E", "PRECISION SOFTWARE, INC." },
{ "00C0CE", "CEI SYSTEMS & ENGINEERING PTE" },
{ "00409B", "HAL COMPUTER SYSTEMS INC." },
{ "004073", "BASS ASSOCIATES" },
{ "10005A", "IBM Corp" },
{ "004005", "ANI COMMUNICATIONS INC." },
{ "004099", "NEWGEN SYSTEMS CORP." },
{ "0040E1", "MARNER INTERNATIONAL, INC." },
{ "0080DD", "GMX INC/GIMIX" },
{ "0080B7", "STELLAR COMPUTER" },
{ "008002", "SATELCOM (UK) LTD" },
{ "00805C", "AGILIS CORPORATION" },
{ "0080C7", "XIRCOM" },
{ "0080E7", "LYNWOOD SCIENTIFIC DEV. LTD." },
{ "008070", "COMPUTADORAS MICRON" },
{ "00808F", "C. ITOH ELECTRONICS, INC." },
{ "000091", "ANRITSU CORPORATION" },
{ "000094", "ASANTE TECHNOLOGIES" },
{ "000090", "MICROCOM" },
{ "000047", "NICOLET INSTRUMENTS CORP." },
{ "0000FB", "RECHNER ZUR KOMMUNIKATION" },
{ "0000A3", "NETWORK APPLICATION TECHNOLOGY" },
{ "00008F", "Raytheon" },
{ "00007E", "CLUSTRIX CORPORATION" },
{ "00000A", "OMRON TATEISI ELECTRONICS CO." },
{ "000063", "BARCO CONTROL ROOMS GMBH" },
{ "00004E", "AMPEX CORPORATION" },
{ "0000C2", "INFORMATION PRESENTATION TECH." },
{ "000034", "NETWORK RESOURCES CORPORATION" },
{ "000049", "APRICOT COMPUTERS, LTD" },
{ "0000E2", "ACER TECHNOLOGIES CORP." },
{ "000097", "EMC Corporation" },
{ "0000D4", "PURE DATA LTD." },
{ "0000E1", "GRID SYSTEMS" },
{ "000031", "QPSX COMMUNICATIONS PTY LTD" },
{ "000044", "CASTELLE CORPORATION" },
{ "000027", "JAPAN RADIO COMPANY" },
{ "004049", "Roche Diagnostics International Ltd." },
{ "004029", "Compex" },
{ "008038", "DATA RESEARCH & APPLICATIONS" },
{ "008090", "MICROTEK INTERNATIONAL, INC." },
{ "0080C3", "BICC INFORMATION SYSTEMS & SVC" },
{ "00805A", "TULIP COMPUTERS INTERNAT'L B.V" },
{ "0080F0", "Panasonic Communications Co., Ltd." },
{ "008043", "NETWORLD, INC." },
{ "0080B0", "ADVANCED INFORMATION" },
{ "008066", "ARCOM CONTROL SYSTEMS, LTD." },
{ "004051", "GRACILIS, INC." },
{ "004064", "KLA INSTRUMENTS CORPORATION" },
{ "004028", "NETCOMM LIMITED" },
{ "004013", "NTT DATA COMM. SYSTEMS CORP." },
{ "0040A0", "GOLDSTAR CO., LTD." },
{ "0040B2", "SYSTEMFORSCHUNG" },
{ "004071", "ATM COMPUTER GMBH" },
{ "0080F7", "ZENITH ELECTRONICS" },
{ "0080BF", "TAKAOKA ELECTRIC MFG. CO. LTD." },
{ "0080F6", "SYNERGY MICROSYSTEMS" },
{ "00001F", "Telco Systems, Inc." },
{ "000058", "RACORE COMPUTER PRODUCTS INC." },
{ "000050", "RADISYS CORPORATION" },
{ "008082", "PEP MODULAR COMPUTERS GMBH" },
{ "008096", "HUMAN DESIGNED SYSTEMS, INC." },
{ "0080D5", "CADRE TECHNOLOGIES" },
{ "00803E", "SYNERNETICS" },
{ "00809A", "NOVUS NETWORKS LTD" },
{ "0080B3", "AVAL DATA CORPORATION" },
{ "0080A3", "Lantronix" },
{ "00803C", "TVS ELECTRONICS LTD" },
{ "008061", "LITTON SYSTEMS, INC." },
{ "0080AD", "CNET TECHNOLOGY, INC." },
{ "008081", "KENDALL SQUARE RESEARCH CORP." },
{ "008019", "DAYNA COMMUNICATIONS, INC." },
{ "00808B", "DACOLL LIMITED" },
{ "008097", "CENTRALP AUTOMATISMES" },
{ "0080FC", "AVATAR CORPORATION" },
{ "008076", "MCNC" },
{ "008080", "DATAMEDIA CORPORATION" },
{ "0000E6", "APTOR PRODUITS DE COMM INDUST" },
{ "000084", "SUPERNET" },
{ "0000FF", "CAMTEC ELECTRONICS LTD." },
{ "00007B", "RESEARCH MACHINES" },
{ "000056", "DR. B. STRUCK" },
{ "0000BB", "TRI-DATA" },
{ "080025", "CONTROL DATA" },
{ "080020", "Oracle Corporation" },
{ "027001", "RACAL-DATACOM" },
{ "080006", "SIEMENS AG" },
{ "08007E", "AMALGAMATED WIRELESS(AUS) LTD" },
{ "080075", "DANSK DATA ELECTRONIK" },
{ "080073", "TECMAR INC." },
{ "080069", "SILICON GRAPHICS INC." },
{ "080061", "JAROGATE LTD." },
{ "08005D", "GOULD INC." },
{ "080051", "EXPERDATA" },
{ "08004E", "3COM EUROPE LTD." },
{ "08004A", "BANYAN SYSTEMS INC." },
{ "08004C", "HYDRA COMPUTER SYSTEMS INC." },
{ "080043", "PIXEL COMPUTER INC." },
{ "08003A", "ORCATECH INC." },
{ "080035", "MICROFIVE CORPORATION" },
{ "080036", "INTERGRAPH CORPORATION" },
{ "08002D", "LAN-TEC INC." },
{ "000025", "RAMTEK CORP." },
{ "00003A", "CHYRON CORPORATION" },
{ "000077", "INTERPHASE CORPORATION" },
{ "000096", "MARCONI ELECTRONICS LTD." },
{ "000076", "ABEKAS VIDEO SYSTEM" },
{ "0000EA", "UPNOD AB" },
{ "000074", "RICOH COMPANY LTD." },
{ "00006A", "COMPUTER CONSOLES INC." },
{ "0000C4", "WATERS DIV. OF MILLIPORE" },
{ "000006", "XEROX CORPORATION" },
{ "0001C8", "THOMAS CONRAD CORP." },
{ "02E6D3", "NIXDORF COMPUTER CORPORATION" },
{ "00DD0E", "UNGERMANN-BASS INC." },
{ "08008D", "XYVISION INC." },
{ "080059", "A/S MYCRON" },
{ "021C7C", "PERQ SYSTEMS CORPORATION" },
{ "100000", "Private" },
{ "080004", "CROMEMCO INCORPORATED" },
{ "00DD07", "UNGERMANN-BASS INC." },
{ "00003E", "SIMPACT" },
{ "04E0C4", "TRIUMPH-ADLER AG" },
{ "040AE0", "XMIT AG COMPUTER NETWORKS" },
{ "080016", "BARRISTER INFO SYS CORP" },
{ "080012", "BELL ATLANTIC INTEGRATED SYST." },
{ "0001C8", "CONRAD CORP." },
{ "0000F9", "QUOTRON SYSTEMS INC." },
{ "0000BF", "SYMMETRIC COMPUTER SYSTEMS" },
{ "000085", "CANON INC." },
{ "000028", "PRODIGY SYSTEMS CORPORATION" },
{ "000012", "INFORMATION TECHNOLOGY LIMITED" },
{ "080085", "ELXSI" },
{ "00005B", "ELTEC ELEKTRONIK AG" },
{ "000054", "Schneider Electric" },
{ "0000A9", "NETWORK SYSTEMS CORP." },
{ "000059", "Hellige GMBH" },
{ "000099", "MTX, INC." },
{ "0000E9", "ISICAD, INC." },
{ "08003F", "FRED KOSCHARA ENTERPRISES" },
{ "080002", "BRIDGE COMMUNICATIONS INC." },
{ "08008B", "PYRAMID TECHNOLOGY CORP." },
{ "000002", "XEROX CORPORATION" },
{ "84F6FA", "Miovision Technologies Incorporated" },
{ "CC3B3E", "Lester Electrical" },
{ "C05627", "Belkin International Inc." },
{ "88074B", "LG Electronics (Mobile Communications)" },
{ "4065A3", "Sagemcom Broadband SAS" },
{ "00789E", "Sagemcom Broadband SAS" },
{ "44E9DD", "Sagemcom Broadband SAS" },
{ "10F681", "vivo Mobile Communication Co., Ltd." },
{ "B888E3", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "002622", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "001EEC", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "DC0EA1", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "FC4596", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "208984", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "247C4C", "Herman Miller" },
{ "100723", "IEEE Registration Authority" },
{ "ACDE48", "Private" },
{ "00A085", "Private" },
{ "180373", "Dell Inc." },
{ "F8B156", "Dell Inc." },
{ "1C4024", "Dell Inc." },
{ "F8BC12", "Dell Inc." },
{ "001B5B", "2Wire Inc" },
{ "002456", "2Wire Inc" },
{ "002351", "2Wire Inc" },
{ "00253C", "2Wire Inc" },
{ "0022A4", "2Wire Inc" },
{ "C0830A", "2Wire Inc" },
{ "D0431E", "Dell Inc." },
{ "246E96", "Dell Inc." },
{ "204747", "Dell Inc." },
{ "4C7625", "Dell Inc." },
{ "B8AC6F", "Dell Inc." },
{ "001EC9", "Dell Inc." },
{ "E09861", "Motorola Mobility LLC, a Lenovo Company" },
{ "F4F1E1", "Motorola Mobility LLC, a Lenovo Company" },
{ "74C99A", "Ericsson AB" },
{ "3C197D", "Ericsson AB" },
{ "60BEB5", "Motorola Mobility LLC, a Lenovo Company" },
{ "7845C4", "Dell Inc." },
{ "B4E1C4", "Microsoft Mobile Oy" },
{ "D86C02", "Huaqin Telecom Technology Co.,Ltd" },
{ "0019D2", "Intel Corporate" },
{ "7C5CF8", "Intel Corporate" },
{ "001E67", "Intel Corporate" },
{ "001F3C", "Intel Corporate" },
{ "0022FA", "Intel Corporate" },
{ "001517", "Intel Corporate" },
{ "00166F", "Intel Corporate" },
{ "A44E31", "Intel Corporate" },
{ "6C8814", "Intel Corporate" },
{ "F81654", "Intel Corporate" },
{ "3413E8", "Intel Corporate" },
{ "34E6AD", "Intel Corporate" },
{ "FCF8AE", "Intel Corporate" },
{ "648099", "Intel Corporate" },
{ "002314", "Intel Corporate" },
{ "4025C2", "Intel Corporate" },
{ "8CA982", "Intel Corporate" },
{ "D07E35", "Intel Corporate" },
{ "685D43", "Intel Corporate" },
{ "90E2BA", "Intel Corporate" },
{ "0026C7", "Intel Corporate" },
{ "8086F2", "Intel Corporate" },
{ "78FF57", "Intel Corporate" },
{ "20934D", "FUJIAN STAR-NET COMMUNICATION CO.,LTD" },
{ "00AA00", "Intel Corporation" },
{ "6CF37F", "Aruba Networks" },
{ "605BB4", "AzureWave Technology Inc." },
{ "9C0E4A", "Shenzhen Vastking Electronic Co.,Ltd." },
{ "ACE5F0", "Doppler Labs" },
{ "00F28B", "Cisco Systems, Inc" },
{ "5414FD", "Orbbec 3D Technology International" },
{ "1C4BD6", "AzureWave Technology Inc." },
{ "94DBC9", "AzureWave Technology Inc." },
{ "40E230", "AzureWave Technology Inc." },
{ "00006E", "Artisoft Inc." },
{ "A0F459", "FN-LINK TECHNOLOGY LIMITED" },
{ "0C6AE6", "Stanley Security Solutions" },
{ "E874E6", "ADB Broadband Italia" },
{ "00247B", "Actiontec Electronics, Inc" },
{ "689C5E", "AcSiP Technology Corp." },
{ "0012CF", "Accton Technology Corp" },
{ "0030D3", "Agilent Technologies, Inc." },
{ "38229D", "ADB Broadband Italia" },
{ "002233", "ADB Broadband Italia" },
{ "D4D184", "ADB Broadband Italia" },
{ "34C3D2", "FN-LINK TECHNOLOGY LIMITED" },
{ "38E3C5", "Taicang T&W Electronics" },
{ "D0E44A", "Murata Manufacturing Co., Ltd." },
{ "9433DD", "Taco Inc" },
{ "948815", "Infinique Worldwide Inc" },
{ "3010B3", "Liteon Technology Corporation" },
{ "001802", "Alpha Networks Inc." },
{ "ECCD6D", "Allied Telesis, Inc." },
{ "74C246", "Amazon Technologies Inc." },
{ "F0272D", "Amazon Technologies Inc." },
{ "00225F", "Liteon Technology Corporation" },
{ "0018A4", "ARRIS Group, Inc." },
{ "001311", "ARRIS Group, Inc." },
{ "0015A2", "ARRIS Group, Inc." },
{ "001596", "ARRIS Group, Inc." },
{ "0000CA", "ARRIS Group, Inc." },
{ "983B16", "AMPAK Technology, Inc." },
{ "402BA1", "Sony Mobile Communications AB" },
{ "0025E7", "Sony Mobile Communications AB" },
{ "D05162", "Sony Mobile Communications AB" },
{ "94CE2C", "Sony Mobile Communications AB" },
{ "001A80", "Sony Corporation" },
{ "0024BE", "Sony Corporation" },
{ "001620", "Sony Mobile Communications AB" },
{ "0012EE", "Sony Mobile Communications AB" },
{ "20689D", "Liteon Technology Corporation" },
{ "446D57", "Liteon Technology Corporation" },
{ "000F9F", "ARRIS Group, Inc." },
{ "0011AE", "ARRIS Group, Inc." },
{ "002040", "ARRIS Group, Inc." },
{ "0015CE", "ARRIS Group, Inc." },
{ "001626", "ARRIS Group, Inc." },
{ "00111A", "ARRIS Group, Inc." },
{ "00152F", "ARRIS Group, Inc." },
{ "000B06", "ARRIS Group, Inc." },
{ "44EE02", "MTI Ltd." },
{ "001C11", "ARRIS Group, Inc." },
{ "001CC1", "ARRIS Group, Inc." },
{ "001D6B", "ARRIS Group, Inc." },
{ "001E5A", "ARRIS Group, Inc." },
{ "001DBE", "ARRIS Group, Inc." },
{ "001371", "ARRIS Group, Inc." },
{ "C8AA21", "ARRIS Group, Inc." },
{ "2C9E5F", "ARRIS Group, Inc." },
{ "002495", "ARRIS Group, Inc." },
{ "002642", "ARRIS Group, Inc." },
{ "A4ED4E", "ARRIS Group, Inc." },
{ "0024A1", "ARRIS Group, Inc." },
{ "002375", "ARRIS Group, Inc." },
{ "001ADB", "ARRIS Group, Inc." },
{ "00149A", "ARRIS Group, Inc." },
{ "001A1B", "ARRIS Group, Inc." },
{ "001F7E", "ARRIS Group, Inc." },
{ "0026B6", "ASKEY COMPUTER CORP" },
{ "B4EEB4", "ASKEY COMPUTER CORP" },
{ "FCB4E6", "ASKEY COMPUTER CORP" },
{ "F05C19", "Aruba Networks" },
{ "C43DC7", "NETGEAR" },
{ "000FB5", "NETGEAR" },
{ "00095B", "NETGEAR" },
{ "F87394", "NETGEAR" },
{ "70AAB2", "BlackBerry RTS" },
{ "0026FF", "BlackBerry RTS" },
{ "406F2A", "BlackBerry RTS" },
{ "002557", "BlackBerry RTS" },
{ "0024FE", "AVM GmbH" },
{ "745AAA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "7C1CF1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C0FFD4", "NETGEAR" },
{ "405D82", "NETGEAR" },
{ "803773", "NETGEAR" },
{ "00264D", "Arcadyan Technology Corporation" },
{ "74A528", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3C8AB0", "Juniper Networks" },
{ "4C9614", "Juniper Networks" },
{ "88E0F3", "Juniper Networks" },
{ "2C2172", "Juniper Networks" },
{ "7819F7", "Juniper Networks" },
{ "5C5EAB", "Juniper Networks" },
{ "009069", "Juniper Networks" },
{ "B0C69A", "Juniper Networks" },
{ "88A25E", "Juniper Networks" },
{ "001BC0", "Juniper Networks" },
{ "30A220", "ARG Telecom" },
{ "F4B52F", "Juniper Networks" },
{ "783E53", "BSkyB Ltd" },
{ "4CF2BF", "Cambridge Industries(Group) Co.,Ltd." },
{ "70D931", "Cambridge Industries(Group) Co.,Ltd." },
{ "00E063", "Cabletron Systems, Inc." },
{ "E01D3B", "Cambridge Industries(Group) Co.,Ltd." },
{ "D476EA", "zte corporation" },
{ "0040FB", "CASCADE COMMUNICATIONS" },
{ "F05A09", "Samsung Electronics Co.,Ltd" },
{ "503275", "Samsung Electronics Co.,Ltd" },
{ "28CC01", "Samsung Electronics Co.,Ltd" },
{ "B46293", "Samsung Electronics Co.,Ltd" },
{ "04FE31", "Samsung Electronics Co.,Ltd" },
{ "845181", "Samsung Electronics Co.,Ltd" },
{ "D831CF", "Samsung Electronics Co.,Ltd" },
{ "F8D0BD", "Samsung Electronics Co.,Ltd" },
{ "FCC734", "Samsung Electronics Co.,Ltd" },
{ "E4B021", "Samsung Electronics Co.,Ltd" },
{ "B0EC71", "Samsung Electronics Co.,Ltd" },
{ "3CBBFD", "Samsung Electronics Co.,Ltd" },
{ "24F5AA", "Samsung Electronics Co.,Ltd" },
{ "2CAE2B", "Samsung Electronics Co.,Ltd" },
{ "C488E5", "Samsung Electronics Co.,Ltd" },
{ "7C9122", "Samsung Electronics Co.,Ltd" },
{ "E8B4C8", "Samsung Electronics Co.,Ltd" },
{ "18895B", "Samsung Electronics Co.,Ltd" },
{ "E0DB10", "Samsung Electronics Co.,Ltd" },
{ "E09971", "Samsung Electronics Co.,Ltd" },
{ "6077E2", "Samsung Electronics Co.,Ltd" },
{ "680571", "Samsung Electronics Co.,Ltd" },
{ "6C2F2C", "Samsung Electronics Co.,Ltd" },
{ "5056BF", "Samsung Electronics Co.,Ltd" },
{ "000136", "CyberTAN Technology Inc." },
{ "F88E85", "Comtrend Corporation" },
{ "300D43", "Microsoft Mobile Oy" },
{ "6C2779", "Microsoft Mobile Oy" },
{ "607EDD", "Microsoft Mobile Oy" },
{ "F88096", "Elsys Equipamentos Eletrônicos Ltda" },
{ "E0B9E5", "Technicolor" },
{ "0CBF15", "Genetec Inc." },
{ "000B5D", "FUJITSU LIMITED" },
{ "F4CAE5", "FREEBOX SAS" },
{ "002100", "Gemtek Technology Co., Ltd." },
{ "002147", "Nintendo Co., Ltd." },
{ "0022AA", "Nintendo Co., Ltd." },
{ "0022D7", "Nintendo Co., Ltd." },
{ "002331", "Nintendo Co., Ltd." },
{ "00241E", "Nintendo Co., Ltd." },
{ "78A2A0", "Nintendo Co., Ltd." },
{ "001B7A", "Nintendo Co., Ltd." },
{ "40F407", "Nintendo Co., Ltd." },
{ "B8AE6E", "Nintendo Co., Ltd." },
{ "60A8FE", "Nokia" },
{ "546751", "Compal Broadband Networks, Inc." },
{ "84BA3B", "CANON INC." },
{ "0018C5", "Nokia Danmark A/S" },
{ "80501B", "Nokia Corporation" },
{ "347E39", "Nokia Danmark A/S" },
{ "A87E33", "Nokia Danmark A/S" },
{ "00247D", "Nokia Danmark A/S" },
{ "001BAF", "Nokia Danmark A/S" },
{ "001C35", "Nokia Danmark A/S" },
{ "001CD4", "Nokia Danmark A/S" },
{ "001979", "Nokia Danmark A/S" },
{ "9C1874", "Nokia Danmark A/S" },
{ "0021FC", "Nokia Danmark A/S" },
{ "001F5D", "Nokia Danmark A/S" },
{ "0025CF", "Nokia Danmark A/S" },
{ "0025D0", "Nokia Danmark A/S" },
{ "001FDE", "Nokia Danmark A/S" },
{ "907282", "Sagemcom Broadband SAS" },
{ "006CFD", "Sichuan Changhong Electric Ltd." },
{ "1C234F", "EDMI  Europe Ltd" },
{ "A444D1", "Wingtech Group (HongKong）Limited" },
{ "1C9E46", "Apple, Inc." },
{ "005058", "Sangoma Technologies" },
{ "3482DE", "Kiio Inc" },
{ "0008F6", "Sumitomo Electric Industries,Ltd" },
{ "00005F", "Sumitomo Electric Industries,Ltd" },
{ "A0C589", "Intel Corporate" },
{ "204E71", "Juniper Networks" },
{ "74BFB7", "Nusoft Corporation" },
{ "50DA00", "Hangzhou H3C Technologies Co., Limited" },
{ "9C2A83", "Samsung Electronics Co.,Ltd" },
{ "E45D75", "Samsung Electronics Co.,Ltd" },
{ "3CBEE1", "NIKON CORPORATION" },
{ "047E4A", "moobox CO., Ltd." },
{ "104FA8", "Sony Computer Entertainment Inc." },
{ "F01B6C", "vivo Mobile Communication Co., Ltd." },
{ "E0C767", "Apple, Inc." },
{ "2C09CB", "COBS AB" },
{ "60ACC8", "KunTeng Inc." },
{ "0404EA", "Valens Semiconductor Ltd." },
{ "800DD7", "Latticework, Inc" },
{ "402E28", "MiXTelematics" },
{ "18C501", "SHENZHEN GONGJIN ELECTRONICS CO.,LT" },
{ "546D52", "TOPVIEW OPTRONICS CORP." },
{ "CCB3AB", "shenzhen Biocare Bio-Medical Equipment Co.,Ltd." },
{ "4CC94F", "Alcatel-Lucent" },
{ "48F7F1", "Alcatel-Lucent" },
{ "E4B318", "Intel Corporate" },
{ "00C88B", "Cisco Systems, Inc" },
{ "A85EE4", "12Sided Technology, LLC" },
{ "000CC1", "Eaton Corporation" },
{ "0090F9", "Imagine Communications" },
{ "04C103", "Clover Network, Inc." },
{ "F877B8", "Samsung Electronics Co.,Ltd" },
{ "1C553A", "QianGua Corp." },
{ "E4A7A0", "Intel Corporate" },
{ "E4FAED", "Samsung Electronics Co.,Ltd" },
{ "789682", "zte corporation" },
{ "F02745", "F-Secure Corporation" },
{ "54D0B4", "Xiamen Four-Faith Communication Technology Co.,Ltd" },
{ "D017C2", "ASUSTek COMPUTER INC." },
{ "10DA43", "NETGEAR" },
{ "001625", "Impinj, Inc." },
{ "1CEA1B", "Alcatel-Lucent" },
{ "DC1AC5", "vivo Mobile Communication Co., Ltd. " },
{ "60EE5C", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "BC60A7", "Sony Computer Entertainment Inc." },
{ "58D67A", "TCPlink" },
{ "00A0DE", "YAMAHA CORPORATION" },
{ "081F71", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "986D35", "IEEE Registration Authority" },
{ "2C2D48", "bct electronic GesmbH" },
{ "E4A471", "Intel Corporate" },
{ "60B617", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "18A3E8", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "741E93", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "F0C77F", "Texas Instruments" },
{ "00A0F4", "GE" },
{ "00CAE5", "Cisco Systems, Inc" },
{ "4883C7", "Sagemcom Broadband SAS" },
{ "7050AF", "BSkyB Ltd" },
{ "F4EF9E", "SGSG SCIENCE & TECHNOLOGY CO. LTD" },
{ "DC9C9F", "Shenzhen YOUHUA Technology Co., Ltd" },
{ "0CBF3F", "Shenzhen Lencotion Technology Co.,Ltd" },
{ "84FEDC", "Borqs Beijing Ltd." },
{ "F03E90", "Ruckus Wireless" },
{ "D8D723", "IDS, Inc" },
{ "703A0E", "Aruba Networks" },
{ "7054D2", "PEGATRON CORPORATION" },
{ "7C0507", "PEGATRON CORPORATION" },
{ "C07CD1", "PEGATRON CORPORATION" },
{ "94DBDA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "384C4F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E4A8B6", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "244C07", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E840F2", "PEGATRON CORPORATION" },
{ "F0D1B8", "LEDVANCE" },
{ "60B387", "Synergics Technologies GmbH" },
{ "7085C2", "ASRock Incorporation" },
{ "C825E1", "Lemobile Information Technology (Beijing) Co., Ltd" },
{ "0022B1", "Elbit Systems Ltd." },
{ "0000B4", "Edimax Technology Co. Ltd." },
{ "00065F", "ECI Telecom Ltd." },
{ "001F45", "Enterasys" },
{ "0090FA", "Emulex Corporation" },
{ "50C971", "GN Netcom A/S" },
{ "001D82", "GN Netcom A/S" },
{ "001317", "GN Netcom A/S" },
{ "749781", "zte corporation" },
{ "B4B15A", "Siemens AG Energy Management Division" },
{ "E0B6F5", "IEEE Registration Authority" },
{ "A86BAD", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D80F99", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A8D828", "Ascensia Diabetes Care" },
{ "F08261", "Sagemcom Broadband SAS" },
{ "D084B0", "Sagemcom Broadband SAS" },
{ "5846E1", "Baxter International Inc" },
{ "00D0BD", "Lattice Semiconductor Corp. (LPA)" },
{ "001F3A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "647BD4", "Texas Instruments" },
{ "102EAF", "Texas Instruments" },
{ "CC8CE3", "Texas Instruments" },
{ "B4EED4", "Texas Instruments" },
{ "D08CB5", "Texas Instruments" },
{ "0030C5", "CADENCE DESIGN SYSTEMS, INC." },
{ "00FEC8", "Cisco Systems, Inc" },
{ "BC5436", "Apple, Inc." },
{ "0CC731", "Currant, Inc." },
{ "00142F", "Savvius" },
{ "70CA4D", "Shenzhen lnovance Technology Co.,Ltd." },
{ "DCC0EB", "ASSA ABLOY CÔTE PICARDE" },
{ "047863", "Shanghai MXCHIP Information Technology Co., Ltd." },
{ "24BA13", "RISO KAGAKU CORPORATION" },
{ "24DA11", "NO NDA Inc" },
{ "BCD1D3", "Shenzhen TINNO Mobile Technology Corp." },
{ "BC4434", "Shenzhen TINNO Mobile Technology Corp." },
{ "0041D2", "Cisco Systems, Inc" },
{ "4CFB45", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "A4BA76", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3871DE", "Apple, Inc." },
{ "2CDDA3", "Point Grey Research Inc." },
{ "24FD5B", "SmartThings, Inc." },
{ "2876CD", "Funshion Online Technologies Co.,Ltd" },
{ "F4F5D8", "Google, Inc." },
{ "F4F5E8", "Google, Inc." },
{ "F88FCA", "Google, Inc." },
{ "14D64D", "D-Link International" },
{ "C8BE19", "D-Link International" },
{ "BCF685", "D-Link International" },
{ "CCB255", "D-Link International" },
{ "84C9B2", "D-Link International" },
{ "EC2280", "D-Link International" },
{ "78E3B5", "Hewlett Packard" },
{ "984BE1", "Hewlett Packard" },
{ "68B599", "Hewlett Packard" },
{ "0C47C9", "Amazon Technologies Inc." },
{ "001831", "Texas Instruments" },
{ "0023D4", "Texas Instruments" },
{ "3C2DB7", "Texas Instruments" },
{ "40984E", "Texas Instruments" },
{ "3C7DB1", "Texas Instruments" },
{ "505663", "Texas Instruments" },
{ "B0B448", "Texas Instruments" },
{ "0017E6", "Texas Instruments" },
{ "0017E8", "Texas Instruments" },
{ "9059AF", "Texas Instruments" },
{ "E0C79D", "Texas Instruments" },
{ "003676", "Pace plc" },
{ "58DC6D", "Exceptional Innovation, Inc." },
{ "00092D", "HTC Corporation" },
{ "F8DB7F", "HTC Corporation" },
{ "E899C4", "HTC Corporation" },
{ "28565A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "40490F", "Hon Hai Precision Ind. Co.,Ltd." },
{ "7CB15D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "002269", "Hon Hai Precision Ind. Co.,Ltd." },
{ "18686A", "zte corporation" },
{ "0C0535", "Juniper Systems" },
{ "E0885D", "Technicolor CH USA" },
{ "8CF228", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "08EA44", "Aerohive Networks Inc." },
{ "78F882", "LG Electronics (Mobile Communications)" },
{ "C8CBB8", "Hewlett Packard" },
{ "9457A5", "Hewlett Packard" },
{ "0001E7", "Hewlett Packard" },
{ "080009", "Hewlett Packard" },
{ "0080A0", "Hewlett Packard" },
{ "D48564", "Hewlett Packard" },
{ "3C4A92", "Hewlett Packard" },
{ "0080E1", "STMicroelectronics SRL" },
{ "2C6E85", "Intel Corporate" },
{ "00D0B7", "Intel Corporation" },
{ "0015D1", "ARRIS Group, Inc." },
{ "001DD3", "ARRIS Group, Inc." },
{ "001735", "Intel Wireless Network Group" },
{ "9CDFB1", "Shenzhen Crave Communication Co., LTD" },
{ "5CF938", "Apple, Inc." },
{ "001D73", "BUFFALO.INC" },
{ "001601", "BUFFALO.INC" },
{ "106F3F", "BUFFALO.INC" },
{ "8857EE", "BUFFALO.INC" },
{ "009C02", "Hewlett Packard" },
{ "78E7D1", "Hewlett Packard" },
{ "001B78", "Hewlett Packard" },
{ "001E0B", "Hewlett Packard" },
{ "0002B3", "Intel Corporation" },
{ "001111", "Intel Corporation" },
{ "001320", "Intel Corporate" },
{ "0012F0", "Intel Corporate" },
{ "9049FA", "Intel Corporate" },
{ "C8348E", "Intel Corporate" },
{ "780AC7", "Baofeng TV Co., Ltd." },
{ "00508B", "Hewlett Packard" },
{ "784859", "Hewlett Packard" },
{ "1458D0", "Hewlett Packard" },
{ "5065F3", "Hewlett Packard" },
{ "A0481C", "Hewlett Packard" },
{ "A01D48", "Hewlett Packard" },
{ "8851FB", "Hewlett Packard" },
{ "AC162D", "Hewlett Packard" },
{ "A0B3CC", "Hewlett Packard" },
{ "E4115B", "Hewlett Packard" },
{ "E8892C", "ARRIS Group, Inc." },
{ "E83EFC", "ARRIS Group, Inc." },
{ "083E0C", "ARRIS Group, Inc." },
{ "8C09F4", "ARRIS Group, Inc." },
{ "3CDFA9", "ARRIS Group, Inc." },
{ "C005C2", "ARRIS Group, Inc." },
{ "6455B1", "ARRIS Group, Inc." },
{ "DCD321", "HUMAX Co., Ltd." },
{ "CC4EEC", "HUMAX Co., Ltd." },
{ "88C255", "Texas Instruments" },
{ "DC330D", "Qingdao Haier Telecom Co.，Ltd" },
{ "94B2CC", "PIONEER CORPORATION" },
{ "887F03", "Comper Technology Investment Limited" },
{ "50FA84", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F483CD", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "882593", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "808917", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "5C899A", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "A81B5A", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "E422A5", "PLANTRONICS, INC." },
{ "1C994C", "Murata Manufacturing Co., Ltd." },
{ "F02765", "Murata Manufacturing Co., Ltd." },
{ "88308A", "Murata Manufacturing Co., Ltd." },
{ "44A7CF", "Murata Manufacturing Co., Ltd." },
{ "44322A", "Avaya Inc" },
{ "FC8399", "Avaya Inc" },
{ "00040D", "Avaya Inc" },
{ "D842AC", "Shanghai Feixun Communication Co.,Ltd." },
{ "34CDBE", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D46AA8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "5439DF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4846FB", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "200BC7", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "104780", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "30D17E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "9C28EF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E06066", "Sercomm Corporation" },
{ "0019E0", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "0023CD", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "002719", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "40169F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "940C6D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "74EA3A", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "90F652", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "10FEED", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "C46E1F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "68A0F6", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "5CF96A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B43052", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "88CEFA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "582AF7", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F48E92", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "40CBA8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "087A4C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D46E5C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2469A5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C8D15E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F83DFF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0013E0", "Murata Manufacturing Co., Ltd." },
{ "748EF8", "Brocade Communications Systems, Inc." },
{ "00E052", "Brocade Communications Systems, Inc." },
{ "000480", "Brocade Communications Systems, Inc." },
{ "000088", "Brocade Communications Systems, Inc." },
{ "344B50", "zte corporation" },
{ "FCC897", "zte corporation" },
{ "9CD24B", "zte corporation" },
{ "C864C7", "zte corporation" },
{ "D0154A", "zte corporation" },
{ "001FE2", "Hon Hai Precision Ind. Co.,Ltd." },
{ "001DD9", "Hon Hai Precision Ind. Co.,Ltd." },
{ "0016CE", "Hon Hai Precision Ind. Co.,Ltd." },
{ "0014A4", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D02788", "Hon Hai Precision Ind. Co.,Ltd." },
{ "300ED5", "Hon Hai Precision Ind. Co.,Ltd." },
{ "543530", "Hon Hai Precision Ind. Co.,Ltd." },
{ "90489A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "88E3AB", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00664B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "7C6097", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "60DE44", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3400A3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "643E8C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0012D1", "Texas Instruments" },
{ "70FF76", "Texas Instruments" },
{ "B4994C", "Texas Instruments" },
{ "507224", "Texas Instruments" },
{ "308730", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "002568", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D47856", "Avaya Inc" },
{ "C057BC", "Avaya Inc" },
{ "38BB3C", "Avaya Inc" },
{ "E45D52", "Avaya Inc" },
{ "A4251B", "Avaya Inc" },
{ "6CA849", "Avaya Inc" },
{ "048A15", "Avaya Inc" },
{ "D4970B", "Xiaomi Communications Co Ltd" },
{ "F48B32", "Xiaomi Communications Co Ltd" },
{ "20A783", "miControl GmbH" },
{ "005053", "Cisco Systems, Inc" },
{ "00500F", "Cisco Systems, Inc" },
{ "0050A2", "Cisco Systems, Inc" },
{ "0498F3", "ALPS ELECTRIC CO.,LTD." },
{ "38C096", "ALPS ELECTRIC CO.,LTD." },
{ "E0750A", "ALPS ELECTRIC CO.,LTD." },
{ "B05947", "Shenzhen Qihu Intelligent Technology Company Limited" },
{ "00E04F", "Cisco Systems, Inc" },
{ "001011", "Cisco Systems, Inc" },
{ "0010F6", "Cisco Systems, Inc" },
{ "80E01D", "Cisco Systems, Inc" },
{ "80E86F", "Cisco Systems, Inc" },
{ "E4AA5D", "Cisco Systems, Inc" },
{ "203A07", "Cisco Systems, Inc" },
{ "34A84E", "Cisco Systems, Inc" },
{ "E4D3F1", "Cisco Systems, Inc" },
{ "1CE6C7", "Cisco Systems, Inc" },
{ "E02F6D", "Cisco Systems, Inc" },
{ "8478AC", "Cisco Systems, Inc" },
{ "4403A7", "Cisco Systems, Inc" },
{ "6886A7", "Cisco Systems, Inc" },
{ "B4E9B0", "Cisco Systems, Inc" },
{ "000832", "Cisco Systems, Inc" },
{ "B0FAEB", "Cisco Systems, Inc" },
{ "500604", "Cisco Systems, Inc" },
{ "70105C", "Cisco Systems, Inc" },
{ "C067AF", "Cisco Systems, Inc" },
{ "64E950", "Cisco Systems, Inc" },
{ "B0AA77", "Cisco Systems, Inc" },
{ "78BAF9", "Cisco Systems, Inc" },
{ "0016B6", "Cisco-Linksys, LLC" },
{ "0018F8", "Cisco-Linksys, LLC" },
{ "00252E", "Cisco SPVTG" },
{ "A4A24A", "Cisco SPVTG" },
{ "602AD0", "Cisco SPVTG" },
{ "001BFB", "ALPS ELECTRIC CO.,LTD." },
{ "0016FE", "ALPS ELECTRIC CO.,LTD." },
{ "3C08F6", "Cisco Systems, Inc" },
{ "D072DC", "Cisco Systems, Inc" },
{ "28C7CE", "Cisco Systems, Inc" },
{ "6CFA89", "Cisco Systems, Inc" },
{ "58F39C", "Cisco Systems, Inc" },
{ "346288", "Cisco Systems, Inc" },
{ "881DFC", "Cisco Systems, Inc" },
{ "000389", "PLANTRONICS, INC." },
{ "0CE0E4", "PLANTRONICS, INC." },
{ "7CFADF", "Apple, Inc." },
{ "101C0C", "Apple, Inc." },
{ "001124", "Apple, Inc." },
{ "001D4F", "Apple, Inc." },
{ "001E52", "Apple, Inc." },
{ "001F5B", "Apple, Inc." },
{ "001FF3", "Apple, Inc." },
{ "0021E9", "Apple, Inc." },
{ "00236C", "Apple, Inc." },
{ "002500", "Apple, Inc." },
{ "60FB42", "Apple, Inc." },
{ "F81EDF", "Apple, Inc." },
{ "90840D", "Apple, Inc." },
{ "D8A25E", "Apple, Inc." },
{ "C8BCC8", "Apple, Inc." },
{ "28E7CF", "Apple, Inc." },
{ "D89E3F", "Apple, Inc." },
{ "040CCE", "Apple, Inc." },
{ "A4D1D2", "Apple, Inc." },
{ "406C8F", "Apple, Inc." },
{ "00C610", "Apple, Inc." },
{ "70DEE2", "Apple, Inc." },
{ "0050F0", "Cisco Systems, Inc" },
{ "00905F", "Cisco Systems, Inc" },
{ "00902B", "Cisco Systems, Inc" },
{ "00100B", "Cisco Systems, Inc" },
{ "00100D", "Cisco Systems, Inc" },
{ "001014", "Cisco Systems, Inc" },
{ "00E08F", "Cisco Systems, Inc" },
{ "189C5D", "Cisco Systems, Inc" },
{ "000EA6", "ASUSTek COMPUTER INC." },
{ "0013D4", "ASUSTek COMPUTER INC." },
{ "002618", "ASUSTek COMPUTER INC." },
{ "00248C", "ASUSTek COMPUTER INC." },
{ "14DAE9", "ASUSTek COMPUTER INC." },
{ "182032", "Apple, Inc." },
{ "6CC26B", "Apple, Inc." },
{ "1040F3", "Apple, Inc." },
{ "FC253F", "Apple, Inc." },
{ "183451", "Apple, Inc." },
{ "C0847A", "Apple, Inc." },
{ "64200C", "Apple, Inc." },
{ "74E1B6", "Apple, Inc." },
{ "0C771A", "Apple, Inc." },
{ "00F4B9", "Apple, Inc." },
{ "C8334B", "Apple, Inc." },
{ "B8F6B1", "Apple, Inc." },
{ "C09F42", "Apple, Inc." },
{ "189EFC", "Apple, Inc." },
{ "6C3E6D", "Apple, Inc." },
{ "8C2DAA", "Apple, Inc." },
{ "444C0C", "Apple, Inc." },
{ "84FCFE", "Apple, Inc." },
{ "E48B7F", "Apple, Inc." },
{ "94E96A", "Apple, Inc." },
{ "AC293A", "Apple, Inc." },
{ "10417F", "Apple, Inc." },
{ "7014A6", "Apple, Inc." },
{ "A8667F", "Apple, Inc." },
{ "D02598", "Apple, Inc." },
{ "CC29F5", "Apple, Inc." },
{ "802994", "Technicolor CH USA" },
{ "D4B8FF", "Home Control Singapore Pte Ltd" },
{ "C8E0EB", "Apple, Inc." },
{ "A88808", "Apple, Inc." },
{ "907240", "Apple, Inc." },
{ "0C4DE9", "Apple, Inc." },
{ "D89695", "Apple, Inc." },
{ "0C3021", "Apple, Inc." },
{ "F0F61C", "Apple, Inc." },
{ "B03495", "Apple, Inc." },
{ "848E0C", "Apple, Inc." },
{ "6C709F", "Apple, Inc." },
{ "0C3E9F", "Apple, Inc." },
{ "34E2FD", "Apple, Inc." },
{ "609217", "Apple, Inc." },
{ "8863DF", "Apple, Inc." },
{ "80E650", "Apple, Inc." },
{ "006171", "Apple, Inc." },
{ "90FD61", "Apple, Inc." },
{ "5C97F3", "Apple, Inc." },
{ "6C4008", "Apple, Inc." },
{ "24A074", "Apple, Inc." },
{ "F02475", "Apple, Inc." },
{ "20A2E4", "Apple, Inc." },
{ "5CF5DA", "Apple, Inc." },
{ "649ABE", "Apple, Inc." },
{ "5C969D", "Apple, Inc." },
{ "A8FAD8", "Apple, Inc." },
{ "949426", "Apple, Inc." },
{ "E0F5C6", "Apple, Inc." },
{ "28E14C", "Apple, Inc." },
{ "54E43A", "Apple, Inc." },
{ "90DFFB", "HOMERIDER SYSTEMS" },
{ "3C831E", "CKD Corporation" },
{ "381C23", "Hilan Technology CO.,LTD" },
{ "AC6462", "zte corporation" },
{ "C08488", "Finis Inc" },
{ "8C99E6", "TCT Mobile Limited" },
{ "3CB72B", "PLUMgrid Inc" },
{ "243184", "SHARP Corporation" },
{ "24DA9B", "Motorola Mobility LLC, a Lenovo Company" },
{ "7467F7", "Zebra Technologoes" },
{ "3891D5", "Hangzhou H3C Technologies Co., Limited" },
{ "68E8EB", "Linktel Technologies Co.,Ltd" },
{ "20C3A4", "RetailNext" },
{ "B844D9", "Apple, Inc." },
{ "DC2B2A", "Apple, Inc." },
{ "8C10D4", "Sagemcom Broadband SAS" },
{ "B8B2EB", "Googol Technology (HK) Limited" },
{ "C40049", "Kamama" },
{ "50A9DE", "Smartcom - Bulgaria AD" },
{ "C02DEE", "Cuff" },
{ "54A3FA", "BQT Solutions (Australia)Pty Ltd" },
{ "30F772", "Hon Hai Precision Ind. Co.,Ltd." },
{ "9023EC", "Availink, Inc." },
{ "203D66", "ARRIS Group, Inc." },
{ "B83A9D", "FIVE INTERACTIVE, LLC" },
{ "089B4B", "iKuai Networks" },
{ "780541", "Queclink Wireless Solutions Co., Ltd" },
{ "3C7873", "Airsonics" },
{ "3052CB", "Liteon Technology Corporation" },
{ "54AB3A", "QUANTA COMPUTER INC." },
{ "8809AF", "Masimo Corp." },
{ "E8DED6", "Intrising Networks, Inc." },
{ "E03676", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C8F9C8", "NewSharp Technology(SuZhou)Co,Ltd" },
{ "3C5CC3", "Shenzhen First Blue Chip Technology Ltd" },
{ "A8741D", "PHOENIX CONTACT Electronics GmbH" },
{ "F4C613", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "D404CD", "ARRIS Group, Inc." },
{ "EC0133", "TRINUS SYSTEMS INC." },
{ "90D8F3", "zte corporation" },
{ "D84710", "Sichuan Changhong Electric Ltd." },
{ "444CA8", "Arista Networks" },
{ "A4C138", "Telink Semiconductor (Taipei) Co. Ltd." },
{ "683E34", "Meizu Technology Co., LTD" },
{ "48E244", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D8EFCD", "Nokia" },
{ "BC5FF6", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "1C56FE", "Motorola Mobility LLC, a Lenovo Company" },
{ "7CA23E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "501AA5", "GN Netcom A/S" },
{ "F09A51", "Shanghai Viroyal Electronic Technology Company Limited" },
{ "9870E8", "INNATECH SDN BHD" },
{ "50DF95", "Lytx" },
{ "584925", "E3 Enterprise" },
{ "94F278", "Elma Electronic" },
{ "E8BDD1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "307CB2", "ANOV FRANCE" },
{ "BC6A2F", "Henge Docks LLC" },
{ "E4907E", "Motorola Mobility LLC, a Lenovo Company" },
{ "48066A", "Tempered Networks, Inc." },
{ "1CF03E", "Wearhaus Inc." },
{ "BCF811", "Xiamen DNAKE Technology Co.,Ltd" },
{ "A8827F", "CIBN Oriental Network(Beijing) CO.,Ltd" },
{ "609C9F", "Brocade Communications Systems, Inc." },
{ "249EAB", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "DC56E6", "Shenzhen Bococom Technology Co.,LTD" },
{ "5CA178", "TableTop Media (dba Ziosk)" },
{ "A0B437", "GENERAL DYNAMICS C4 SYSEMS" },
{ "B89ACD", "ELITE OPTOELECTRONIC(ASIA)CO.,LTD" },
{ "800184", "HTC Corporation" },
{ "38FACA", "Skyworth Digital Technology(Shenzhen) Co.,Ltd" },
{ "44C69B", "Wuhan Feng Tian Information Network CO.,LTD" },
{ "C02567", "Nexxt Solutions" },
{ "B46D35", "Dalian Seasky Automation Co;Ltd" },
{ "FCE33C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "68EDA4", "Shenzhen Seavo Technology Co.,Ltd" },
{ "B899B0", "Cohere Technologies" },
{ "2CC5D3", "Ruckus Wireless" },
{ "80C5E6", "Microsoft Corporation" },
{ "D85DEF", "Busch-Jaeger Elektro GmbH" },
{ "10DF8B", "Shenzhen CareDear Communication Technology Co.,Ltd" },
{ "00A784", "ITX security" },
{ "3481F4", "SST Taiwan Ltd." },
{ "F4B8A7", "zte corporation" },
{ "58F102", "BLU Products Inc." },
{ "B869C2", "Sunitec Enterprise Co., Ltd." },
{ "2CC548", "IAdea Corporation" },
{ "84DBFC", "Alcatel-Lucent" },
{ "DCDB70", "Tonfunk Systementwicklung und Service GmbH" },
{ "C47D46", "FUJITSU LIMITED" },
{ "702A7D", "EpSpot AB" },
{ "B8B3DC", "DEREK (SHAOGUAN) LIMITED" },
{ "347A60", "Pace plc" },
{ "C4EA1D", "Technicolor" },
{ "900A39", "Wiio, Inc." },
{ "C4693E", "Turbulence Design Inc." },
{ "1C8341", "Hefei Bitland Information Technology Co.Ltd" },
{ "6C1E70", "Guangzhou YBDS IT Co.,Ltd" },
{ "C8E130", "Milkyway Group Ltd" },
{ "20E407", "Spark srl" },
{ "887384", "Toshiba" },
{ "8833BE", "Ivenix, Inc." },
{ "34CC28", "Nexpring Co. LTD.," },
{ "144146", "Honeywell (China) Co., LTD" },
{ "F41563", "F5 Networks, Inc." },
{ "4011DC", "Sonance" },
{ "749CE3", "Art2Wave Canada Inc." },
{ "B856BD", "ITT LLC" },
{ "107873", "Shenzhen Jinkeyi Communication Co., Ltd." },
{ "7CC709", "Shenzhen RF-LINK Elec&Technology.,Ltd" },
{ "3C8C40", "Hangzhou H3C Technologies Co., Limited" },
{ "D45556", "Fiber Mountain Inc." },
{ "F01E34", "ORICO Technologies Co., Ltd" },
{ "74A063", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "A89008", "Beijing Yuecheng Technology Co. Ltd." },
{ "183864", "CAP-TECH INTERNATIONAL CO., LTD." },
{ "08D34B", "Techman Electronics (Changshu) Co., Ltd." },
{ "C808E9", "LG Electronics" },
{ "589B0B", "Shineway Technologies, Inc." },
{ "78ACBF", "Igneous Systems" },
{ "206274", "Microsoft Corporation" },
{ "5CCCFF", "Techroutes Network Pvt Ltd" },
{ "844BB7", "Beijing Sankuai Online Technology Co.,Ltd" },
{ "148F21", "Garmin International" },
{ "1C7D22", "Fuji Xerox Co., Ltd." },
{ "ACD1B8", "Hon Hai Precision Ind. Co.,Ltd." },
{ "3C6A9D", "Dexatek Technology LTD." },
{ "14893E", "VIXTEL TECHNOLOGIES LIMTED" },
{ "60F189", "Murata Manufacturing Co., Ltd." },
{ "241C04", "SHENZHEN JEHE TECHNOLOGY DEVELOPMENT CO., LTD." },
{ "F8CFC5", "Motorola Mobility LLC, a Lenovo Company" },
{ "7C11CD", "QianTang Technology" },
{ "0492EE", "iway AG" },
{ "B04519", "TCT mobile ltd" },
{ "1436C6", "Lenovo Mobile Communication Technology Ltd." },
{ "04C09C", "Tellabs Inc." },
{ "2C337A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "844464", "ServerU Inc" },
{ "78312B", "zte corporation" },
{ "74A34A", "ZIMI CORPORATION" },
{ "98F5A9", "OHSUNG ELECTRONICS CO.,LTD." },
{ "D89341", "General Electric Global Research" },
{ "F4645D", "Toshiba" },
{ "30D587", "Samsung Electronics Co.,Ltd" },
{ "A48CDB", "Lenovo" },
{ "4062B6", "Tele system communication" },
{ "3C2C94", "HangZhou Delan Technology Co.,Ltd）" },
{ "48A9D2", "Wistron Neweb Corp." },
{ "F02A23", "Creative Next Design" },
{ "584704", "Shenzhen Webridge Technology Co.,Ltd" },
{ "1C14B3", "Pinyon Technologies" },
{ "A0E4CB", "ZyXEL Communications Corporation" },
{ "307350", "Inpeco SA" },
{ "E8CC18", "D-Link International" },
{ "B09137", "ISis ImageStream Internet Solutions, Inc" },
{ "745C9F", "TCT mobile ltd." },
{ "3C1E13", "HANGZHOU SUNRISE TECHNOLOGY CO., LTD" },
{ "B4A828", "Shenzhen Concox Information Technology Co., Ltd" },
{ "50F43C", "Leeo Inc" },
{ "FCDBB3", "Murata Manufacturing Co., Ltd." },
{ "B8186F", "ORIENTAL MOTOR CO., LTD." },
{ "1C9C26", "Zoovel Technologies" },
{ "9C3583", "Nipro Diagnostics, Inc" },
{ "C456FE", "Lava International Ltd." },
{ "B89BE4", "ABB Power Systems Power Generation" },
{ "C0EEFB", "OnePlus Tech (Shenzhen) Ltd" },
{ "E00DB9", "Private" },
{ "A41242", "NEC Platforms, Ltd." },
{ "8CF813", "ORANGE POLSKA" },
{ "B479A7", "Samsung Electro Mechanics co., LTD." },
{ "B8F317", "iSun Smasher Communications Private Limited" },
{ "2442BC", "Alinco,incorporated" },
{ "C401CE", "PRESITION (2000) CO., LTD." },
{ "D01242", "BIOS Corporation" },
{ "6CBFB5", "Noon Technology Co., Ltd" },
{ "2CA30E", "POWER DRAGON DEVELOPMENT LIMITED" },
{ "4CF5A0", "Scalable Network Technologies Inc" },
{ "84E058", "Pace plc" },
{ "084656", "VEO-LABS" },
{ "4488CB", "Camco Technologies NV" },
{ "5014B5", "Richfit Information Technology Co., Ltd" },
{ "CC3080", "VAIO Corporation" },
{ "F82441", "Yeelink" },
{ "108A1B", "RAONIX Inc." },
{ "94B40F", "Aruba Networks" },
{ "4C2C83", "Zhejiang KaNong Network Technology Co.,Ltd." },
{ "BCC342", "Panasonic System Networks Co., Ltd." },
{ "E89606", "testo Instruments (Shenzhen) Co., Ltd." },
{ "CC3F1D", "Intesis Software SL" },
{ "902181", "Shanghai Huaqin Telecom Technology Co.,Ltd" },
{ "D062A0", "China Essence Technology (Zhumadian) Co., Ltd." },
{ "CC10A3", "Beijing Nan Bao Technology Co., Ltd." },
{ "B43934", "Pen Generations, Inc." },
{ "C03896", "Hon Hai Precision Ind. Co.,Ltd." },
{ "DCC622", "BUHEUNG SYSTEM" },
{ "5C2BF5", "Vivint" },
{ "6C0B84", "Universal Global Scientific Industrial Co.,Ltd." },
{ "600417", "POSBANK CO.,LTD" },
{ "489D18", "Flashbay Limited" },
{ "8CB094", "Airtech I&C Co., Ltd" },
{ "70F196", "Actiontec Electronics, Inc" },
{ "6C6EFE", "Core Logic Inc." },
{ "E4C62B", "Airware" },
{ "80F8EB", "RayTight" },
{ "F409D8", "Samsung Electro Mechanics co., LTD." },
{ "C035C5", "Prosoft Systems LTD" },
{ "F8B2F3", "GUANGZHOU BOSMA TECHNOLOGY CO.,LTD" },
{ "8C9109", "Toyoshima Electric Technoeogy(Suzhou) Co.,Ltd." },
{ "A44AD3", "ST Electronics(Shanghai) Co.,Ltd" },
{ "2497ED", "Techvision Intelligent Technology Limited" },
{ "104E07", "Shanghai Genvision Industries Co.,Ltd" },
{ "4C11BF", "ZHEJIANG DAHUA TECHNOLOGY CO.,LTD." },
{ "FCD5D9", "Shenzhen SDMC Technology Co., Ltd." },
{ "007532", "INID BV" },
{ "A002DC", "Amazon Technologies Inc." },
{ "907EBA", "UTEK TECHNOLOGY (SHENZHEN) CO.,LTD" },
{ "488244", "Life Fitness / Div. of Brunswick" },
{ "D85DFB", "Private" },
{ "7CC4EF", "Devialet" },
{ "A8E539", "Moimstone Co.,Ltd" },
{ "98F170", "Murata Manufacturing Co., Ltd." },
{ "04C991", "Phistek INC." },
{ "404EEB", "Higher Way Electronic Co., Ltd." },
{ "50BD5F", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "147590", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "ECB907", "CloudGenix Inc" },
{ "5CF9F0", "Atomos Engineering P/L" },
{ "581F67", "Open-m technology limited" },
{ "BC25F0", "3D Display Technologies Co., Ltd." },
{ "94AEE3", "Belden Hirschmann Industries (Suzhou) Ltd." },
{ "44666E", "IP-LINE" },
{ "705B2E", "M2Communication Inc." },
{ "0C8C8F", "Kamo Technology Limited" },
{ "3CD9CE", "Eclipse WiFi" },
{ "C80210", "LG Innotek" },
{ "702DD1", "Newings Communication CO., LTD." },
{ "44746C", "Sony Mobile Communications AB" },
{ "F4F646", "Dediprog Technology Co. Ltd." },
{ "ECD9D1", "Shenzhen TG-NET Botone Technology Co.,Ltd." },
{ "748F4D", "MEN Mikro Elektronik GmbH" },
{ "F4FD2B", "ZOYI Company" },
{ "FCAA14", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "50FEF2", "Sify Technologies Ltd" },
{ "7CE524", "Quirky, Inc." },
{ "7CD30A", "INVENTEC Corporation" },
{ "3481C4", "AVM GmbH" },
{ "885BDD", "Aerohive Networks Inc." },
{ "A47E39", "zte corporation" },
{ "0C63FC", "Nanjing Signway Technology Co., Ltd" },
{ "ACA9A0", "Audioengine, Ltd." },
{ "A8A668", "zte corporation" },
{ "A8F7E0", "PLANET Technology Corporation" },
{ "2C5BE1", "Centripetal Networks, Inc" },
{ "D87EB1", "x.o.ware, inc." },
{ "4045DA", "Spreadtrum Communications (Shanghai) Co., Ltd." },
{ "98BE94", "IBM" },
{ "D4B43E", "Messcomp Datentechnik GmbH" },
{ "48D18E", "Metis Communication Co.,Ltd" },
{ "A49F85", "Lyve Minds, Inc" },
{ "888914", "All Components Incorporated" },
{ "D8150D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "A06518", "VNPT TECHNOLOGY" },
{ "748F1B", "MasterImage 3D" },
{ "684898", "Samsung Electronics Co.,Ltd" },
{ "E4121D", "Samsung Electronics Co.,Ltd" },
{ "D82A15", "Leitner SpA" },
{ "C4291D", "KLEMSAN ELEKTRIK ELEKTRONIK SAN.VE TIC.AS." },
{ "704E01", "KWANGWON TECH CO., LTD." },
{ "848433", "Paradox Engineering SA" },
{ "D4319D", "Sinwatec" },
{ "DC052F", "National Products Inc." },
{ "CC398C", "Shiningtek" },
{ "6C5F1C", "Lenovo Mobile Communication Technology Ltd." },
{ "B42C92", "Zhejiang Weirong Electronic Co., Ltd" },
{ "FC1349", "Global Apps Corp." },
{ "8C41F2", "RDA Technologies Ltd." },
{ "FC07A0", "LRE Medical GmbH" },
{ "AC02CA", "HI Solutions, Inc." },
{ "F490CA", "Tensorcom" },
{ "2C534A", "Shenzhen Winyao Electronic Limited" },
{ "CC856C", "SHENZHEN MDK DIGITAL TECHNOLOGY CO.,LTD" },
{ "60FFDD", "C.E. ELECTRONICS, INC" },
{ "FCBBA1", "Shenzhen Minicreate Technology Co.,Ltd" },
{ "50B695", "Micropoint Biotechnologies,Inc." },
{ "B48547", "Amptown System Company GmbH" },
{ "085700", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "60E327", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "E4D332", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "A0DA92", "Nanjing Glarun Atten Technology Co. Ltd." },
{ "6828BA", "Dejai" },
{ "407875", "IMBEL - Industria de Material Belico do Brasil" },
{ "0C4F5A", "ASA-RT s.r.l." },
{ "B4B542", "Hubbell Power Systems, Inc." },
{ "54CDEE", "ShenZhen Apexis Electronic Co.,Ltd" },
{ "F8F005", "Newport Media Inc." },
{ "98C0EB", "Global Regency Ltd" },
{ "D4224E", "Alcatel Lucent" },
{ "28DEF6", "bioMerieux Inc." },
{ "88E8F8", "YONG TAI ELECTRONIC (DONGGUAN) LTD." },
{ "2C073C", "DEVLINE LIMITED" },
{ "F015A0", "KyungDong One Co., Ltd." },
{ "ECF72B", "HD DIGITAL TECH CO., LTD." },
{ "D8B6D6", "Blu Tether Limited" },
{ "847207", "I&C Technology" },
{ "3C25D7", "Nokia Corporation" },
{ "1889DF", "CerebrEX Inc." },
{ "30A8DB", "Sony Mobile Communications AB" },
{ "CC9F35", "Transbit Sp. z o.o." },
{ "8C569D", "Imaging Solutions Group" },
{ "A43A69", "Vers Inc" },
{ "387B47", "AKELA, Inc." },
{ "7CCD11", "MS-Magnet" },
{ "94FBB2", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "4CE1BB", "Zhuhai HiFocus Technology Co., Ltd." },
{ "8CDE99", "Comlab Inc." },
{ "085AE0", "Recovision Technology Co., Ltd." },
{ "7CE4AA", "Private" },
{ "1820A6", "Sage Co., Ltd." },
{ "BCF61C", "Geomodeling Wuxi Technology Co. Ltd." },
{ "083F3E", "WSH GmbH" },
{ "6C09D6", "Digiquest Electronics LTD" },
{ "F03A4B", "Bloombase, Inc." },
{ "2C9AA4", "NGI SpA" },
{ "B46698", "Zealabs srl" },
{ "283B96", "Cool Control LTD" },
{ "80D433", "LzLabs GmbH" },
{ "687CC8", "Measurement Systems S. de R.L." },
{ "38BF2F", "Espec Corp." },
{ "182012", "Aztech Associates Inc." },
{ "34BE00", "Samsung Electronics Co.,Ltd" },
{ "343111", "Samsung Electronics Co.,Ltd" },
{ "0CBD51", "TCT Mobile Limited" },
{ "C0F991", "GME Standard Communications P/L" },
{ "14EDA5", "Wächter GmbH Sicherheitssysteme" },
{ "E056F4", "AxesNetwork Solutions inc." },
{ "B8C1A2", "Dragon Path Technologies Co., Limited" },
{ "50ED78", "Changzhou Yongse Infotech Co.,Ltd" },
{ "8CB7F7", "Shenzhen UniStrong Science & Technology Co., Ltd" },
{ "085240", "EbV Elektronikbau- und Vertriebs GmbH" },
{ "80F25E", "Kyynel" },
{ "94DF4E", "Wistron InfoComm(Kunshan)Co.,Ltd." },
{ "E0AEB2", "Bender GmbH &amp; Co.KG" },
{ "2C553C", "Gainspeed, Inc." },
{ "B43E3B", "Viableware, Inc" },
{ "F854AF", "ECI Telecom Ltd." },
{ "7C0623", "Ultra Electronics, CIS" },
{ "2464EF", "CYG SUNRI CO.,LTD." },
{ "50B888", "wi2be Tecnologia S/A" },
{ "844F03", "Ablelink Electronics Ltd" },
{ "94B9B4", "Aptos Technology" },
{ "D0B523", "Bestcare Cloucal Corp." },
{ "783D5B", "TELNET Redes Inteligentes S.A." },
{ "D0C42F", "Tamagawa Seiki Co.,Ltd." },
{ "5CFFFF", "Shenzhen Kezhonglong Optoelectronic Technology Co., Ltd" },
{ "F0D3A7", "CobaltRay Co., Ltd" },
{ "20D390", "Samsung Electronics Co.,Ltd" },
{ "847616", "Addat s.r.o." },
{ "D46867", "Neoventus Design Group" },
{ "68692E", "Zycoo Co.,Ltd" },
{ "1C63B7", "OpenProducts 237 AB" },
{ "A0A23C", "GPMS" },
{ "A03B1B", "Inspire Tech" },
{ "3C6E63", "Mitron OY" },
{ "502E5C", "HTC Corporation" },
{ "20D21F", "Wincal Technology Corp." },
{ "FC1E16", "IPEVO corp" },
{ "6C4B7F", "Vossloh-Schwabe Deutschland GmbH" },
{ "0CCB8D", "ASCO Numatics GmbH" },
{ "FC019E", "VIEVU" },
{ "34AA8B", "Samsung Electronics Co.,Ltd" },
{ "F45F69", "Matsufu Electronics distribution Company" },
{ "F4A294", "EAGLE WORLD DEVELOPMENT CO., LIMITED" },
{ "2CCD69", "Aqavi.com" },
{ "947C3E", "Polewall Norge AS" },
{ "385AA8", "Beijing Zhongdun Security Technology Development Co." },
{ "FC3FAB", "Henan Lanxin Technology Co., Ltd" },
{ "2847AA", "Nokia Corporation" },
{ "682DDC", "Wuhan Changjiang Electro-Communication Equipment CO.,LTD" },
{ "FCB0C4", "Shanghai DareGlobal Technologies Co., Ltd" },
{ "9CBB98", "Shen Zhen RND Electronic Co.,LTD" },
{ "345C40", "Cargt Holdings LLC" },
{ "34885D", "Logitech Far East" },
{ "708D09", "Nokia Corporation" },
{ "FCE1D9", "Stable Imaging Solutions LLC" },
{ "38B74D", "Fijowave Limited" },
{ "A0E5E9", "enimai Inc" },
{ "A88D7B", "SunDroid Global limited." },
{ "6064A1", "RADiflow Ltd." },
{ "8079AE", "ShanDong Tecsunrise  Co.,Ltd" },
{ "2C7155", "HiveMotion" },
{ "909916", "ELVEES NeoTek OJSC" },
{ "FC1BFF", "V-ZUG AG" },
{ "AC5036", "Pi-Coral Inc" },
{ "BCEE7B", "ASUSTek COMPUTER INC." },
{ "8C3AE3", "LG Electronics" },
{ "FC09D8", "ACTEON Group" },
{ "0C1262", "zte corporation" },
{ "A875E2", "Aventura Technologies, Inc." },
{ "E0D1E6", "Aliph dba Jawbone" },
{ "28C671", "Yota Devices OY" },
{ "DC1792", "Captivate Network" },
{ "7C8306", "Glen Dimplex Nordic as" },
{ "84253F", "Silex Technology, Inc" },
{ "907A0A", "Gebr. Bode GmbH & Co KG" },
{ "306112", "PAV GmbH" },
{ "A0C6EC", "ShenZhen ANYK Technology Co.,LTD" },
{ "6405BE", "NEW LIGHT LED" },
{ "F8FF5F", "Shenzhen Communication Technology Co.,Ltd" },
{ "DCC422", "Systembase Limited" },
{ "F4BD7C", "Chengdu jinshi communication Co., LTD" },
{ "C8F36B", "Yamato Scale Co.,Ltd." },
{ "6C90B1", "SanLogic Inc" },
{ "845C93", "Chabrier Services" },
{ "D44C9C", "Shenzhen YOOBAO Technology Co.Ltd" },
{ "68E166", "Private" },
{ "60FEF9", "Thomas & Betts" },
{ "FC4BBC", "Sunplus Technology Co., Ltd." },
{ "142D8B", "Incipio Technologies, Inc" },
{ "CCE8AC", "SOYEA Technology Co.,Ltd." },
{ "78D38D", "HONGKONG YUNLINK TECHNOLOGY LIMITED" },
{ "1C48F9", "GN Netcom A/S" },
{ "744BE9", "EXPLORER HYPERTECH CO.,LTD" },
{ "B836D8", "Videoswitch" },
{ "F835DD", "Gemtek Technology Co., Ltd." },
{ "0CF019", "Malgn Technology Co., Ltd." },
{ "D46A91", "Snap AV" },
{ "E8519D", "Yeonhab Precision Co.,LTD" },
{ "00B78D", "Nanjing Shining Electric Automation Co., Ltd" },
{ "882364", "Watchnet DVR Inc" },
{ "A05B21", "ENVINET GmbH" },
{ "50B8A2", "ImTech Technologies LLC," },
{ "A41566", "Wei Fang Goertek Electronics Co.,Ltd" },
{ "B04C05", "Fresenius Medical Care Deutschland GmbH" },
{ "A0EC80", "zte corporation" },
{ "9046B7", "Vadaro Pte Ltd" },
{ "1C08C1", "Lg Innotek" },
{ "201D03", "Elatec GmbH" },
{ "C06C6D", "MagneMotion, Inc." },
{ "E03E4A", "Cavanagh Group International" },
{ "D890E8", "Samsung Electronics Co.,Ltd" },
{ "24C696", "Samsung Electronics Co.,Ltd" },
{ "30766F", "LG Electronics" },
{ "6CB350", "Anhui comhigher tech co.,ltd" },
{ "A42305", "Open Networking Laboratory" },
{ "1C86AD", "MCT CO., LTD." },
{ "28D93E", "Telecor Inc." },
{ "C80258", "ITW GSE ApS" },
{ "1001CA", "Ashley Butterworth" },
{ "246AAB", "IT-IS International" },
{ "28F532", "ADD-Engineering BV" },
{ "78FE41", "Socus networks" },
{ "083571", "CASwell INC." },
{ "DCF755", "SITRONIK" },
{ "E42D02", "TCT Mobile Limited" },
{ "ACCA8E", "ODA Technologies" },
{ "74CA25", "Calxeda, Inc." },
{ "181EB0", "Samsung Electronics Co.,Ltd" },
{ "CCBD35", "Steinel GmbH" },
{ "9498A2", "Shanghai LISTEN TECH.LTD" },
{ "2CB693", "Radware" },
{ "88685C", "Shenzhen ChuangDao & Perpetual Eternal Technology Co.,Ltd" },
{ "B4FE8C", "Centro Sicurezza Italia SpA" },
{ "D82916", "Ascent Communication Technology" },
{ "6472D8", "GooWi Technology Co.,Limited" },
{ "3C081E", "Beijing Yupont Electric Power Technology Co.,Ltd" },
{ "7CA15D", "GN ReSound A/S" },
{ "B4DD15", "ControlThings Oy Ab" },
{ "F8FEA8", "Technico Japan Corporation" },
{ "A8154D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D05099", "ASRock Incorporation" },
{ "78A106", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "A49EDB", "AutoCrib, Inc." },
{ "282CB2", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D43A65", "IGRS Engineering Lab Ltd." },
{ "D0EB03", "Zhehua technology limited" },
{ "A0861D", "Chengdu Fuhuaxin Technology co.,Ltd" },
{ "888964", "GSI Electronics Inc." },
{ "4C82CF", "Echostar Technologies" },
{ "9CA577", "Osorno Enterprises Inc." },
{ "C0C3B6", "Automatic Systems" },
{ "A8294C", "Precision Optical Transceivers, Inc." },
{ "3C86A8", "Sangshin elecom .co,, LTD" },
{ "FCDD55", "Shenzhen WeWins wireless Co.,Ltd" },
{ "CC0DEC", "Cisco SPVTG" },
{ "68B094", "INESA ELECTRON CO.,LTD" },
{ "40E730", "DEY Storage Systems, Inc." },
{ "F05DC8", "Duracell Powermat" },
{ "6C8686", "Technonia" },
{ "4432C8", "Technicolor USA Inc." },
{ "78521A", "Samsung Electronics Co.,Ltd" },
{ "68DB67", "Nantong Coship Electronics Co., Ltd" },
{ "BC261D", "HONG KONG TECON TECHNOLOGY" },
{ "10B9FE", "Lika srl" },
{ "D42751", "Infopia Co., Ltd" },
{ "A895B0", "Aker Subsea Ltd" },
{ "5C20D0", "Asoni Communication Co., Ltd." },
{ "E0C3F3", "zte corporation" },
{ "30CDA7", "Samsung Electronics ITS, Printer division" },
{ "104D77", "Innovative Computer Engineering" },
{ "788DF7", "Hitron Technologies. Inc" },
{ "6CECA1", "SHENZHEN CLOU ELECTRONICS CO. LTD." },
{ "D862DB", "Eno Inc." },
{ "A8D236", "Lightware Visual Engineering" },
{ "48F925", "Maestronic" },
{ "C0885B", "SnD Tech Co., Ltd." },
{ "64C667", "Barnes&Noble" },
{ "C47DCC", "Zebra Technologies Inc" },
{ "64535D", "Frauscher Sensortechnik" },
{ "105F06", "Actiontec Electronics, Inc" },
{ "00B56D", "David Electronics Co., LTD." },
{ "B461FF", "Lumigon A/S" },
{ "9038DF", "Changzhou Tiannengbo System Co. Ltd." },
{ "CC593E", "TOUMAZ LTD" },
{ "84E714", "Liang Herng Enterprise,Co.Ltd." },
{ "303D08", "GLINTT TES S.A." },
{ "E496AE", "ALTOGRAPHICS Inc." },
{ "F80BD0", "Datang Telecom communication terminal (Tianjin) Co., Ltd." },
{ "48B9C2", "Teletics Inc." },
{ "D046DC", "Southwest Research Institute" },
{ "F8F082", "Orion Networks International, Inc" },
{ "046E49", "TaiYear Electronic Technology (Suzhou) Co., Ltd" },
{ "08606E", "ASUSTek COMPUTER INC." },
{ "BC39A6", "CSUN System Technology Co.,LTD" },
{ "ECB541", "SHINANO E and E Co.Ltd." },
{ "D40057", "MC Technologies GmbH" },
{ "B85AF7", "Ouya, Inc" },
{ "E0D9A2", "Hippih aps" },
{ "B0C4E7", "Samsung Electronics" },
{ "F0F669", "Motion Analysis Corporation" },
{ "F0219D", "Cal-Comp Electronics & Communications Company Ltd." },
{ "F8D7BF", "REV Ritter GmbH" },
{ "AC5D10", "Pace Americas" },
{ "88F490", "Jetmobile Pte Ltd" },
{ "AC8D14", "Smartrove Inc" },
{ "18673F", "Hanover Displays Limited" },
{ "A00ABF", "Wieson Technologies Co., Ltd." },
{ "2091D9", "I'M SPA" },
{ "744D79", "Arrive Systems Inc." },
{ "C83D97", "Nokia Corporation" },
{ "38192F", "Nokia Corporation" },
{ "141BF0", "Intellimedia Systems Ltd" },
{ "101D51", "ON-Q LLC dba ON-Q Mesh Networks" },
{ "34C99D", "EIDOLON COMMUNICATIONS TECHNOLOGY CO. LTD." },
{ "8C4AEE", "GIGA TMS INC" },
{ "F46DE2", "zte corporation" },
{ "B838CA", "Kyokko Tsushin System CO.,LTD" },
{ "380FE4", "Dedicated Network Partners Oy" },
{ "847A88", "HTC Corporation" },
{ "0808C2", "Samsung Electronics" },
{ "5461EA", "Zaplox AB" },
{ "78324F", "Millennium Group, Inc." },
{ "38B5BD", "E.G.O. Elektro-Ger" },
{ "841715", "GP Electronics (HK) Ltd." },
{ "087999", "AIM GmbH" },
{ "84C2E4", "Jiangsu Qinheng Co., Ltd." },
{ "C0B8B1", "BitBox Ltd" },
{ "0C722C", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "B01408", "LIGHTSPEED INTERNATIONAL CO." },
{ "84ACA4", "Beijing Novel Super Digital TV Technology Co., Ltd" },
{ "3C6FF7", "EnTek Systems, Inc." },
{ "48B8DE", "HOMEWINS TECHNOLOGY CO.,LTD." },
{ "20D5BF", "Samsung Eletronics Co., Ltd" },
{ "6CD032", "LG Electronics" },
{ "1065CF", "IQSIM" },
{ "B877C3", "Decagon Devices, Inc." },
{ "849DC5", "Centera Photonics Inc." },
{ "580943", "Private" },
{ "547FA8", "TELCO systems, s.r.o." },
{ "5474E6", "Webtech Wireless" },
{ "E8A364", "Signal Path International / Peachtree Audio" },
{ "D0D6CC", "Wintop" },
{ "FC1F19", "SAMSUNG ELECTRO-MECHANICS CO., LTD." },
{ "9C541C", "Shenzhen My-power Technology Co.,Ltd" },
{ "90187C", "Samsung Electro Mechanics co., LTD." },
{ "10F3DB", "Gridco Systems, Inc." },
{ "B01203", "Dynamics Hong Kong Limited" },
{ "7093F8", "Space Monkey, Inc." },
{ "305D38", "Beissbarth " },
{ "FCD6BD", "Robert Bosch GmbH" },
{ "044A50", "Ramaxel Technology (Shenzhen) limited company" },
{ "A4466B", "EOC Technology" },
{ "7C386C", "Real Time Logic" },
{ "D8AF3B", "Hangzhou Bigbright Integrated communications system Co.,Ltd" },
{ "78D34F", "Pace-O-Matic, Inc." },
{ "D857EF", "Samsung Electronics" },
{ "647657", "Innovative Security Designs" },
{ "60455E", "Liptel s.r.o." },
{ "944A09", "BitWise Controls" },
{ "E8102E", "Really Simple Software, Inc" },
{ "D48CB5", "Cisco Systems, Inc" },
{ "24A43C", "Ubiquiti Networks, INC" },
{ "D41E35", "TOHO Electronics INC." },
{ "700BC0", "Dewav Technology Company" },
{ "3CF392", "Virtualtek. Co. Ltd" },
{ "889676", "TTC MARCONI s.r.o." },
{ "149FE8", "Lenovo Mobile Communication Technology Ltd." },
{ "70B599", "Embedded Technologies s.r.o." },
{ "547398", "Toyo Electronics Corporation" },
{ "E0AAB0", "GENERAL VISION ELECTRONICS CO. LTD." },
{ "68B43A", "WaterFurnace International, Inc." },
{ "543968", "Edgewater Networks Inc" },
{ "C041F6", "LG Electronics Inc" },
{ "985E1B", "ConversDigital Co., Ltd." },
{ "9C0DAC", "Tymphany HK Limited" },
{ "8CD3A2", "VisSim AS" },
{ "24EE3A", "Chengdu Yingji Electronic Hi-tech Co Ltd" },
{ "F82285", "Cypress Technology CO., LTD." },
{ "8482F4", "Beijing Huasun Unicreate Technology Co., Ltd" },
{ "0CC47E", "EUCAST Co., Ltd." },
{ "CCE798", "My Social Stuff" },
{ "50724D", "BEG Brueck Electronic GmbH" },
{ "B898B0", "Atlona Inc." },
{ "1C66AA", "Samsung Electronics" },
{ "2C625A", "Finest Security Systems Co., Ltd" },
{ "2074CF", "Shenzhen Voxtech Co.,Ltd" },
{ "ACBD0B", "IMAC CO.,LTD" },
{ "D8D27C", "JEMA ENERGY, SA" },
{ "60CBFB", "AirScape Inc." },
{ "4C5427", "Linepro Sp. z o.o." },
{ "3CEAFB", "NSE AG" },
{ "3476C5", "I-O DATA DEVICE, INC." },
{ "407074", "Life Technology (China) Co., Ltd" },
{ "58BFEA", "Cisco Systems, Inc" },
{ "E856D6", "NCTech Ltd" },
{ "4088E0", "Beijing Ereneben Information Technology Limited Shenzhen Branch" },
{ "1CF4CA", "Private" },
{ "EC4C4D", "ZAO NPK RoTeK" },
{ "E8D483", "ULTIMATE Europe Transportation Equipment GmbH" },
{ "089E01", "QUANTA COMPUTER INC." },
{ "ACD9D6", "tci GmbH" },
{ "7493A4", "Zebra Technologies Corp." },
{ "58C38B", "Samsung Electronics" },
{ "2CD444", "FUJITSU LIMITED" },
{ "EC1A59", "Belkin International Inc." },
{ "04F8C2", "Flaircomm Microelectronics, Inc." },
{ "0C93FB", "BNS Solutions" },
{ "E45614", "Suttle Apparatus" },
{ "784405", "FUJITU(HONG KONG) ELECTRONIC Co.,LTD." },
{ "C03F2A", "Biscotti, Inc." },
{ "5001BB", "Samsung Electronics" },
{ "A40BED", "Carry Technology Co.,Ltd" },
{ "0CD996", "Cisco Systems, Inc" },
{ "D82DE1", "Tricascade Inc." },
{ "C438D3", "TAGATEC CO.,LTD" },
{ "842BBC", "Modelleisenbahn GmbH" },
{ "B8B7D7", "2GIG Technologies" },
{ "1048B1", "Beijing Duokan Technology Limited" },
{ "005D03", "Xilinx, Inc" },
{ "20FABB", "Cambridge Executive Limited" },
{ "1C0B52", "EPICOM S.A" },
{ "747E2D", "Beijing Thomson CITIC Digital Technology Co. LTD." },
{ "E80C75", "Syncbak, Inc." },
{ "BC8B55", "NPP ELIKS America Inc. DBA T&M Atlantic" },
{ "D8EB97", "TRENDnet, Inc." },
{ "202598", "Teleview" },
{ "44B382", "Kuang-chi Institute of Advanced Technology" },
{ "D80DE3", "FXI TECHNOLOGIES AS" },
{ "1CE165", "Marshal Corporation" },
{ "0CC0C0", "MAGNETI MARELLI SISTEMAS ELECTRONICOS MEXICO" },
{ "AC40EA", "C&T Solution Inc. " },
{ "F47F35", "Cisco Systems, Inc" },
{ "A0F419", "Nokia Corporation" },
{ "BCC168", "DinBox Sverige AB" },
{ "6CAE8B", "IBM Corporation" },
{ "A4F7D0", "LAN Accessories Co., Ltd." },
{ "D4EC0C", "Harley-Davidson Motor Company" },
{ "5C0A5B", "SAMSUNG ELECTRO-MECHANICS CO., LTD." },
{ "6CA96F", "TransPacket AS" },
{ "AC0142", "Uriel Technologies SIA" },
{ "A007B6", "Advanced Technical Support, Inc." },
{ "542A9C", "LSY Defense, LLC." },
{ "D487D8", "Samsung Electronics" },
{ "F89955", "Fortress Technology Inc" },
{ "008DDA", "Link One Co., Ltd." },
{ "08B4CF", "Abicom International" },
{ "445F7A", "Shihlin Electric & Engineering Corp." },
{ "28BA18", "NextNav, LLC" },
{ "2C36F8", "Cisco Systems, Inc" },
{ "AC3D05", "Instorescreen Aisa" },
{ "F48E09", "Nokia Corporation" },
{ "882012", "LMI Technologies" },
{ "800A06", "COMTEC co.,ltd" },
{ "B827EB", "Raspberry Pi Foundation" },
{ "E88DF5", "ZNYX Networks, Inc." },
{ "48EA63", "Zhejiang Uniview Technologies Co., Ltd." },
{ "0CE5D3", "DH electronics GmbH" },
{ "C47130", "Fon Technology S.L." },
{ "90CF7D", "Qingdao Hisense Electric Co.,Ltd." },
{ "48D7FF", "BLANKOM Antennentechnik GmbH" },
{ "18D66A", "Inmarsat" },
{ "C85645", "Intermas France" },
{ "F490EA", "Deciso B.V." },
{ "942197", "Stalmart Technology Limited" },
{ "AC9403", "Envision Peripherals Inc" },
{ "A865B2", "DONGGUAN YISHANG ELECTRONIC TECHNOLOGY CO., LIMITED" },
{ "60B982", "RO.VE.R. Laboratories S.p.A." },
{ "B46238", "Exablox" },
{ "40704A", "Power Idea Technology Limited" },
{ "F0FDA0", "Acurix Networks LP" },
{ "D8BF4C", "Victory Concept Electronics Limited" },
{ "C0DF77", "Conrad Electronic SE" },
{ "C86000", "ASUSTek COMPUTER INC." },
{ "645299", "The Chamberlain Group, Inc" },
{ "BC125E", "Beijing  WisVideo  INC." },
{ "C80718", "TDSi" },
{ "48ED80", "daesung eltec" },
{ "A086EC", "SAEHAN HITEC Co., Ltd" },
{ "BC4B79", "SensingTek" },
{ "2818FD", "Aditya Infotech Ltd." },
{ "9003B7", "PARROT" },
{ "844915", "vArmour Networks, Inc." },
{ "A04CC1", "Helixtech Corp." },
{ "1CB243", "TDC A/S" },
{ "1C51B5", "Techaya LTD" },
{ "80DB31", "Power Quotient International Co., Ltd." },
{ "8C604F", "Cisco Systems, Inc" },
{ "74FF7D", "Wren Sound Systems, LLC" },
{ "380A94", "Samsung Electronics Co.,Ltd" },
{ "2CC260", "Ravello Systems" },
{ "30B216", "Hytec Geraetebau GmbH" },
{ "34FC6F", "ALCEA" },
{ "C0B357", "Yoshiki Electronics Industry Ltd." },
{ "642DB7", "SEUNGIL ELECTRONICS" },
{ "A898C6", "Shinbo Co., Ltd." },
{ "006BA0", "SHENZHEN UNIVERSAL INTELLISYS PTE LTD" },
{ "502690", "FUJITSU LIMITED" },
{ "B4211D", "Beijing GuangXin Technology Co., Ltd" },
{ "E039D7", "Plexxi, Inc." },
{ "FC946C", "UBIVELOX" },
{ "B4944E", "WeTelecom Co., Ltd." },
{ "345B11", "EVI HEAT AB" },
{ "988BAD", "Corintech Ltd." },
{ "4050E0", "Milton Security Group LLC" },
{ "E42C56", "Lilee Systems, Ltd." },
{ "50008C", "Hong Kong Telecommunications (HKT) Limited" },
{ "DCA8CF", "New Spin Golf, LLC." },
{ "34BA9A", "Asiatelco Technologies Co." },
{ "D443A8", "Changzhou Haojie Electric Co., Ltd." },
{ "BCB852", "Cybera, Inc." },
{ "70D6B6", "Metrum Technologies" },
{ "28D576", "Premier Wireless, Inc." },
{ "C87CBC", "Valink Co., Ltd. " },
{ "409FC7", "BAEKCHUN I&C Co., Ltd." },
{ "C87D77", "Shenzhen Kingtech Communication Equipment Co.,Ltd" },
{ "A078BA", "Pantech Co., Ltd." },
{ "20BBC6", "Jabil Circuit Hungary Ltd." },
{ "2C9717", "I.C.Y. B.V." },
{ "64E84F", "Serialway Communication Technology Co. Ltd" },
{ "6CE907", "Nokia Corporation" },
{ "94DF58", "IJ Electron CO.,Ltd." },
{ "8C0CA3", "Amper" },
{ "28940F", "Cisco Systems, Inc" },
{ "5CEB4E", "R. STAHL HMI Systems GmbH" },
{ "B8DAF7", "Advanced Photonics, Inc." },
{ "2C36A0", "Capisco Limited" },
{ "B06CBF", "3ality Digital Systems GmbH" },
{ "20AA4B", "Cisco-Linksys, LLC" },
{ "080D84", "GECO, Inc." },
{ "88E712", "Whirlpool Corporation" },
{ "644BF0", "CalDigit, Inc" },
{ "2838CF", "Gen2wave" },
{ "50FC30", "Treehouse Labs" },
{ "70704C", "Purple Communications, Inc" },
{ "F47ACC", "SolidFire, Inc." },
{ "F8D3A9", "AXAN Networks" },
{ "5CD4AB", "Zektor" },
{ "F8462D", "SYNTEC Incorporation" },
{ "58677F", "Clare Controls Inc." },
{ "CCA374", "Guangdong Guanglian Electronic Technology Co.Ltd" },
{ "50F61A", "Kunshan JADE Technologies co., Ltd." },
{ "941D1C", "TLab West Systems AB" },
{ "40667A", "mediola - connected living AG" },
{ "64808B", "VG Controls, Inc." },
{ "7C6B52", "Tigaro Wireless" },
{ "48C1AC", "PLANTRONICS, INC." },
{ "D826B9", "Guangdong Coagent Electronics S &T Co., Ltd." },
{ "24BC82", "Dali Wireless, Inc." },
{ "F80CF3", "LG Electronics" },
{ "64C5AA", "South African Broadcasting Corporation" },
{ "64ED62", "WOORI SYSTEMS Co., Ltd" },
{ "C4237A", "WhizNets Inc." },
{ "8430E5", "SkyHawke Technologies, LLC" },
{ "046D42", "Bryston Ltd." },
{ "50CCF8", "Samsung Electro Mechanics" },
{ "D0CF5E", "Energy Micro AS" },
{ "644D70", "dSPACE GmbH" },
{ "807693", "Newag SA" },
{ "2C002C", "UNOWHY" },
{ "0481AE", "Clack Corporation" },
{ "C09132", "Patriot Memory" },
{ "AC81F3", "Nokia Corporation" },
{ "94C6EB", "NOVA electronics, Inc." },
{ "10F9EE", "Nokia Corporation" },
{ "80971B", "Altenergy Power System,Inc." },
{ "1071F9", "Cloud Telecomputers, LLC" },
{ "B8B42E", "Gionee Communication Equipment Co,Ltd.ShenZhen" },
{ "A84041", "Dragino Technology Co., Limited" },
{ "DCF05D", "Letta Teknoloji" },
{ "D05A0F", "I-BT DIGITAL CO.,LTD" },
{ "FC2E2D", "Lorom Industrial Co.LTD." },
{ "E84E06", "EDUP INTERNATIONAL (HK) CO., LTD" },
{ "B4C799", "Zebra Technologies Inc" },
{ "70B921", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "C47B2F", "Beijing JoinHope Image Technology Ltd." },
{ "18F650", "Multimedia Pacific Limited" },
{ "38DE60", "Mohlenhoff GmbH" },
{ "2839E7", "Preceno Technology Pte.Ltd." },
{ "28D997", "Yuduan Mobile Co., Ltd." },
{ "886B76", "CHINA HOPEFUL GROUP HOPEFUL ELECTRIC CO.,LTD" },
{ "A0CF5B", "Cisco Systems, Inc" },
{ "18C451", "Tucson Embedded Systems" },
{ "582EFE", "Lighting Science Group" },
{ "D4507A", "CEIVA Logic, Inc" },
{ "184617", "Samsung Electronics" },
{ "9CC7D1", "SHARP Corporation" },
{ "AC9CE4", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "00B9F6", "Shenzhen Super Rich Electronics Co.,Ltd" },
{ "9C5C8D", "FIREMAX INDÚSTRIA E COMÉRCIO DE PRODUTOS ELETRÔNICOS  LTDA" },
{ "E01E07", "Anite Telecoms  US. Inc" },
{ "64D989", "Cisco Systems, Inc" },
{ "44D3CA", "Cisco Systems, Inc" },
{ "24DAB6", "Sistemas de Gestión Energética S.A. de C.V" },
{ "B8F5E7", "WayTools, LLC" },
{ "980C82", "Samsung Electro Mechanics" },
{ "148A70", "ADS GmbH" },
{ "FC0012", "Toshiba Samsung Storage Technolgoy Korea Corporation " },
{ "F44450", "BND Co., Ltd." },
{ "644346", "GuangDong Quick Network Computer CO.,LTD" },
{ "FCE892", "Hangzhou Lancable Technology Co.,Ltd" },
{ "FC1794", "InterCreative Co., Ltd" },
{ "181420", "TEB SAS" },
{ "D03110", "Ingenic Semiconductor Co.,Ltd" },
{ "48C862", "Simo Wireless,Inc." },
{ "3C26D5", "Sotera Wireless" },
{ "704AAE", "Xstream Flow (Pty) Ltd" },
{ "9C934E", "Xerox Corporation" },
{ "9439E5", "Hon Hai Precision Ind. Co.,Ltd." },
{ "7CDD20", "IOXOS Technologies S.A." },
{ "A0E9DB", "Ningbo FreeWings Technologies Co.,Ltd" },
{ "9C7BD2", "NEOLAB Convergence" },
{ "900D66", "Digimore Electronics Co., Ltd" },
{ "BC35E5", "Hydro Systems Company" },
{ "283410", "Enigma Diagnostics Limited" },
{ "28CCFF", "Corporacion Empresarial Altra SL" },
{ "14B73D", "ARCHEAN Technologies" },
{ "A433D1", "Fibrlink Communications Co.,Ltd." },
{ "84DE3D", "Crystal Vision Ltd" },
{ "F87B8C", "Amped Wireless" },
{ "44D2CA", "Anvia TV Oy" },
{ "4C1A3A", "PRIMA Research And Production Enterprise Ltd." },
{ "AC0613", "Senselogix Ltd" },
{ "B4AA4D", "Ensequence, Inc." },
{ "040A83", "Alcatel-Lucent" },
{ "B42A39", "ORBIT MERRET, spol. s r. o." },
{ "B80B9D", "ROPEX Industrie-Elektronik GmbH" },
{ "18AEBB", "Siemens Convergence Creators GmbH&Co.KG" },
{ "3891FB", "Xenox Holding BV" },
{ "50FAAB", "L-tek d.o.o." },
{ "547F54", "INGENICO" },
{ "A8E018", "Nokia Corporation" },
{ "44AAE8", "Nanotec Electronic GmbH & Co. KG" },
{ "D8DF0D", "beroNet GmbH" },
{ "D8C068", "Netgenetech.co.,ltd." },
{ "3C9157", "Hangzhou Yulong Conmunication Co.,Ltd" },
{ "50E549", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "A8FCB7", "Consolidated Resource Imaging" },
{ "6400F1", "Cisco Systems, Inc" },
{ "04C5A4", "Cisco Systems, Inc" },
{ "E4DD79", "En-Vision America, Inc." },
{ "60190C", "RRAMAC" },
{ "34A709", "Trevil srl" },
{ "F80332", "Khomp" },
{ "C40F09", "Hermes electronic GmbH" },
{ "908D1D", "GH Technologies" },
{ "CCB55A", "Fraunhofer ITWM" },
{ "587521", "CJSC RTSoft" },
{ "948FEE", "Hughes Telematics, Inc." },
{ "E8C320", "Austco Communication Systems Pty Ltd" },
{ "D8973B", "Artesyn Embedded Technologies" },
{ "0C6E4F", "PrimeVOLT Co., Ltd." },
{ "685B36", "POWERTECH INDUSTRIAL CO., LTD." },
{ "983000", "Beijing KEMACOM Technologies Co., Ltd." },
{ "F81D93", "Longdhua(Beijing) Controls Technology Co.,Ltd" },
{ "CC5D4E", "ZyXEL Communications Corporation" },
{ "D0EB9E", "Seowoo Inc." },
{ "BC99BC", "FonSee Technology Inc." },
{ "986022", "EMW Co., Ltd." },
{ "80B32A", "Alstom Grid" },
{ "803457", "OT Systems Limited" },
{ "B83D4E", "Shenzhen Cultraview Digital Technology Co.,Ltd Shanghai Branch" },
{ "3CA72B", "MRV Communications (Networks) LTD" },
{ "EC55F9", "Hon Hai Precision Ind. Co.,Ltd." },
{ "F4D9FB", "Samsung Electronics CO., LTD" },
{ "584C19", "Chongqing Guohong Technology Development Company Limited" },
{ "8C5FDF", "Beijing Railway Signal Factory" },
{ "586D8F", "Cisco-Linksys, LLC" },
{ "14C21D", "Sabtech Industries" },
{ "74B00C", "Network Video Technologies, Inc" },
{ "C88439", "Sunrise Technologies" },
{ "44E4D9", "Cisco Systems, Inc" },
{ "0054AF", "Continental Automotive Systems Inc." },
{ "EC7D9D", "MEI" },
{ "9C95F8", "SmartDoor Systems, LLC" },
{ "D075BE", "Reno A&E" },
{ "7C6C39", "PIXSYS SRL" },
{ "9C5D95", "VTC Electronics Corp." },
{ "0CF3EE", "EM Microelectronic" },
{ "F0C27C", "Mianyang Netop Telecom Equipment Co.,Ltd." },
{ "008D4E", "CJSC NII STT" },
{ "10C586", "BIO SOUND LAB CO., LTD." },
{ "E8BA70", "Cisco Systems, Inc" },
{ "6473E2", "Arbiter Systems, Inc." },
{ "00A1DE", "ShenZhen ShiHua Technology CO.,LTD" },
{ "04E1C8", "IMS Soluções em Energia Ltda." },
{ "DC05ED", "Nabtesco  Corporation" },
{ "FC8329", "Trei technics" },
{ "94E848", "FYLDE MICRO LTD" },
{ "AC5E8C", "Utillink" },
{ "CCF3A5", "Chi Mei Communication Systems, Inc" },
{ "C4242E", "Galvanic Applied Sciences Inc" },
{ "549B12", "Samsung Electronics" },
{ "CC7EE7", "Panasonic AVC Networks Company" },
{ "58E476", "CENTRON COMMUNICATIONS TECHNOLOGIES FUJIAN CO.,LTD" },
{ "B435F7", "Zhejiang Pearmain Electronics Co.ltd." },
{ "346F92", "White Rodgers Division" },
{ "8CDB25", "ESG Solutions" },
{ "641A22", "Heliospectra AB" },
{ "BC20BA", "Inspur (Shandong) Electronic Information Co., Ltd" },
{ "249442", "OPEN ROAD SOLUTIONS , INC." },
{ "E0F379", "Vaddio" },
{ "B09AE2", "STEMMER IMAGING GmbH" },
{ "E441E6", "Ottec Technology GmbH" },
{ "10E2D5", "Qi Hardware Inc." },
{ "7CDA84", "Dongnian Networks Inc." },
{ "A036FA", "Ettus Research LLC" },
{ "EC836C", "RM Tech Co., Ltd." },
{ "BC71C1", "XTrillion, Inc." },
{ "0C469D", "MS Sedco" },
{ "E0E8E8", "Olive Telecommunication Pvt. Ltd" },
{ "0C3C65", "Dome Imaging Inc" },
{ "40B2C8", "Nortel Networks" },
{ "486B91", "Fleetwood Group Inc." },
{ "F43814", "Shanghai Howell Electronic Co.,Ltd" },
{ "20AA25", "IP-NET LLC" },
{ "ECBBAE", "Digivoice Tecnologia em Eletronica Ltda" },
{ "DC2008", "ASD Electronics Ltd " },
{ "088DC8", "Ryowa Electronics Co.,Ltd" },
{ "D491AF", "Electroacustica General Iberica, S.A." },
{ "CCF67A", "Ayecka Communication Systems LTD" },
{ "00BB8E", "HME Co., Ltd." },
{ "C0A26D", "Abbott Point of Care" },
{ "205B2A", "Private" },
{ "18B430", "Nest Labs Inc." },
{ "F8769B", "Neopis Co., Ltd." },
{ "08E672", "JEBSEE ELECTRONICS CO.,LTD." },
{ "D41296", "Anobit Technologies Ltd." },
{ "B8FF6F", "Shanghai Typrotech Technology Co.Ltd" },
{ "DC9C52", "Sapphire Technology Limited." },
{ "68122D", "Special Instrument Development Co., Ltd." },
{ "649B24", "V Technology Co., Ltd." },
{ "0475F5", "CSST" },
{ "10A13B", "FUJIKURA RUBBER LTD." },
{ "F4E142", "Delta Elektronika BV" },
{ "F00248", "SmarteBuilding" },
{ "2CDD0C", "Discovergy GmbH" },
{ "CCD811", "Aiconn Technology Corporation" },
{ "78D004", "Neousys Technology Inc." },
{ "78A051", "iiNet Labs Pty Ltd " },
{ "58A76F", "iD corporation" },
{ "44599F", "Criticare Systems, Inc" },
{ "3C2F3A", "SFORZATO Corp." },
{ "C0C520", "Ruckus Wireless" },
{ "6083B2", "GkWare e.K." },
{ "80D019", "Embed, Inc" },
{ "ECE90B", "SISTEMA SOLUCOES ELETRONICAS LTDA - EASYTECH" },
{ "A08C9B", "Xtreme Technologies Corp" },
{ "607688", "Velodyne" },
{ "980EE4", "Private" },
{ "E828D5", "Cots Technology" },
{ "08D5C0", "Seers Technology Co., Ltd" },
{ "8CB64F", "Cisco Systems, Inc" },
{ "6C33A9", "Magicjack LP" },
{ "08B7EC", "Wireless Seismic" },
{ "30142D", "Piciorgros GmbH" },
{ "942053", "Nokia Corporation" },
{ "D49C8E", "University of FUKUI" },
{ "3C8BFE", "Samsung Electronics" },
{ "2CB0DF", "Soliton Technologies Pvt Ltd" },
{ "5CF3FC", "IBM Corp" },
{ "D01CBB", "Beijing Ctimes Digital Technology Co., Ltd." },
{ "9481A4", "Azuray Technologies" },
{ "BCE09D", "Eoslink" },
{ "D0A311", "Neuberger Gebäudeautomation GmbH" },
{ "3C5A37", "Samsung Electronics" },
{ "EC9233", "Eddyfi NDT Inc" },
{ "0C8D98", "TOP EIGHT IND CORP" },
{ "30493B", "Nanjing Z-Com Wireless Co.,Ltd" },
{ "785712", "Mobile Integration Workgroup" },
{ "380A0A", "Sky-City Communication and Electronics Limited Company" },
{ "38521A", "Alcatel-Lucent 7705" },
{ "C8A1B6", "Shenzhen Longway Technologies Co., Ltd" },
{ "641E81", "Dowslake Microsystems" },
{ "88ACC1", "Generiton Co., Ltd. " },
{ "700258", "01DB-METRAVIB" },
{ "D4E8B2", "Samsung Electronics" },
{ "20FDF1", "3COM EUROPE LTD" },
{ "389592", "Beijing Tendyron Corporation" },
{ "705EAA", "Action Target, Inc." },
{ "141BBD", "Volex Inc." },
{ "78C6BB", "Innovasic, Inc." },
{ "DC4EDE", "SHINYEI TECHNOLOGY CO., LTD." },
{ "888B5D", "Storage Appliance Corporation " },
{ "F0F842", "KEEBOX, Inc." },
{ "78A714", "Amphenol" },
{ "F0DEF1", "Wistron InfoComm (Kunshan)Co" },
{ "F450EB", "Telechips Inc" },
{ "988EDD", "TE Connectivity Limerick" },
{ "98FC11", "Cisco-Linksys, LLC" },
{ "A40CC3", "Cisco Systems, Inc" },
{ "34E0D7", "DONGGUAN QISHENG ELECTRONICS INDUSTRIAL CO., LTD" },
{ "40520D", "Pico Technology" },
{ "8C7CB5", "Hon Hai Precision Ind. Co.,Ltd." },
{ "543131", "Raster Vision Ltd" },
{ "90E0F0", "IEEE 1722a Working Group" },
{ "1C6F65", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "F0AD4E", "Globalscale Technologies, Inc." },
{ "903D5A", "Shenzhen Wision Technology Holding Limited" },
{ "609AA4", "GVI SECURITY INC." },
{ "F0ED1E", "Bilkon Bilgisayar Kontrollu Cih. Im.Ltd." },
{ "206A8A", "Wistron InfoComm Manufacturing(Kunshan)Co.,Ltd." },
{ "F80F41", "Wistron InfoComm(ZhongShan) Corporation" },
{ "1CDF0F", "Cisco Systems, Inc" },
{ "34DF2A", "Fujikon Industrial Co.,Limited" },
{ "C88447", "Beautiful Enterprise Co., Ltd" },
{ "C88B47", "Nolangroup S.P.A con Socio Unico" },
{ "24BA30", "Technical Consumer Products, Inc." },
{ "74D675", "WYMA Tecnologia" },
{ "D43D67", "Carma Industries Inc." },
{ "78818F", "Server Racks Australia Pty Ltd" },
{ "E0589E", "Laerdal Medical" },
{ "44D63D", "Talari Networks" },
{ "58FD20", "Bravida Sakerhet AB" },
{ "9835B8", "Assembled Products Corporation" },
{ "240B2A", "Viettel Group" },
{ "68E41F", "Unglaube Identech GmbH" },
{ "84F64C", "Cross Point BV" },
{ "180C77", "Westinghouse Electric Company, LLC" },
{ "ACA016", "Cisco Systems, Inc" },
{ "78E400", "Hon Hai Precision Ind. Co.,Ltd." },
{ "905446", "TES ELECTRONIC SOLUTIONS" },
{ "DC7B94", "Cisco Systems, Inc" },
{ "68234B", "Nihon Dengyo Kousaku" },
{ "18422F", "Alcatel Lucent" },
{ "A4BE61", "EutroVision System, Inc." },
{ "E06290", "Jinan Jovision Science & Technology Co., Ltd." },
{ "68DB96", "OPWILL Technologies CO .,LTD" },
{ "00F860", "PT. Panggung Electric Citrabuana" },
{ "FCEDB9", "Arrayent" },
{ "44ED57", "Longicorn, inc." },
{ "90513F", "Elettronica Santerno SpA" },
{ "7CA29B", "D.SignT GmbH & Co. KG" },
{ "34AAEE", "Mikrovisatos Servisas UAB" },
{ "7866AE", "ZTEC Instruments, Inc." },
{ "24AF4A", "Alcatel-Lucent-IPD" },
{ "00BD27", "Exar Corp." },
{ "C8A729", "SYStronics Co., Ltd." },
{ "6C9CE9", "Nimble Storage" },
{ "7812B8", "ORANTEK LIMITED" },
{ "F0B6EB", "Poslab Technology Co., Ltd." },
{ "FCCCE4", "Ascon Ltd." },
{ "34862A", "Heinz Lackmann GmbH & Co KG" },
{ "842141", "Shenzhen Ginwave Technologies Ltd." },
{ "B4ED54", "Wohler Technologies" },
{ "544249", "Sony Corporation" },
{ "24DBAD", "ShopperTrak RCT Corporation" },
{ "CC69B0", "Global Traffic Technologies, LLC" },
{ "2872C5", "Smartmatic Corp" },
{ "E4AD7D", "SCL Elements" },
{ "40D40E", "Biodata Ltd" },
{ "7C051E", "RAFAEL LTD." },
{ "58570D", "Danfoss Solar Inverters" },
{ "E47CF9", "Samsung Electronics Co., LTD" },
{ "0C826A", "Wuhan Huagong Genuine Optics Technology Co., Ltd" },
{ "5C0E8B", "Zebra Technologies Inc" },
{ "38C7BA", "CS Services Co.,Ltd." },
{ "70D57E", "Scalar Corporation" },
{ "24A937", "PURE Storage" },
{ "348302", "iFORCOM Co., Ltd" },
{ "949C55", "Alta Data Technologies" },
{ "70D5E7", "Wellcore Corporation" },
{ "3CF72A", "Nokia Corporation" },
{ "FCE192", "Sichuan Jinwangtong Electronic Science&Technology Co,.Ltd" },
{ "F8912A", "GLP German Light Products GmbH" },
{ "E02630", "Intrigue Technologies, Inc." },
{ "8C9236", "Aus.Linx Technology Co., Ltd." },
{ "F445ED", "Portable Innovation Technology Ltd." },
{ "6C32DE", "Indieon Technologies Pvt. Ltd." },
{ "FCCF62", "IBM Corp" },
{ "D8E72B", "NetScout Systems, Inc." },
{ "B8A3E0", "BenRui Technology Co.,Ltd" },
{ "B8F732", "Aryaka Networks Inc" },
{ "0CD502", "Westell" },
{ "70828E", "OleumTech Corporation" },
{ "502A7E", "Smart electronic GmbH" },
{ "F0264C", "Dr. Sigrist AG" },
{ "3C1CBE", "JADAK LLC" },
{ "506313", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A8995C", "aizo ag" },
{ "4012E4", "Compass-EOS" },
{ "F8DC7A", "Variscite LTD" },
{ "EC4476", "Cisco Systems, Inc" },
{ "9CEBE8", "BizLink (Kunshan) Co.,Ltd" },
{ "A01859", "Shenzhen Yidashi Electronics Co Ltd" },
{ "042234", "Wireless Standard Extensions" },
{ "B09074", "Fulan Electronics Limited" },
{ "2CA835", "RIM" },
{ "3CE5A6", "Hangzhou H3C Technologies Co., Ltd." },
{ "94F692", "Geminico co.,Ltd." },
{ "8C736E", "FUJITSU LIMITED" },
{ "30EFD1", "Alstom Strongwish (Shenzhen) Co., Ltd." },
{ "7C2CF3", "Secure Electrans Ltd" },
{ "304174", "ALTEC LANSING LLC" },
{ "7830E1", "UltraClenz, LLC" },
{ "FCFBFB", "Cisco Systems, Inc" },
{ "1C129D", "IEEE PES PSRC/SUB     " },
{ "B40832", "TC Communications" },
{ "B42CBE", "Direct Payment Solutions Limited" },
{ "F47626", "Viltechmeda UAB " },
{ "003A9C", "Cisco Systems, Inc" },
{ "E8E776", "Shenzhen Kootion Technology Co., Ltd" },
{ "702F97", "Aava Mobile Oy" },
{ "9018AE", "Shanghai Meridian Technologies, Co. Ltd." },
{ "0494A1", "CATCH THE WIND INC" },
{ "2C3427", "ERCO & GENER" },
{ "389F83", "OTN Systems N.V." },
{ "8C541D", "LGE " },
{ "601283", "Soluciones Tecnologicas para la Salud y el Bienestar SA" },
{ "003A9D", "NEC Platforms, Ltd." },
{ "C835B8", "Ericsson, EAB/RWI/K" },
{ "243C20", "Dynamode Group" },
{ "E09153", "XAVi Technologies Corp." },
{ "CC0080", "BETTINI SRL" },
{ "644BC3", "Shanghai WOASiS Telecommunications Ltd., Co." },
{ "0CE709", "Fox Crypto B.V." },
{ "002720", "NEW-SOL COM" },
{ "00271C", "MERCURY CORPORATION" },
{ "002712", "MaxVision LLC" },
{ "00270F", "Envisionnovation Inc" },
{ "002703", "Testech Electronics Pte Ltd" },
{ "88ED1C", "Cudo Communication Co., Ltd." },
{ "B05B1F", "THERMO FISHER SCIENTIFIC S.P.A." },
{ "404A03", "ZyXEL Communications Corporation" },
{ "743256", "NT-ware Systemprg GmbH" },
{ "003AAF", "BlueBit Ltd." },
{ "C0BAE6", "Application Solutions (Electronics and Vision) Ltd" },
{ "20BFDB", "DVL" },
{ "C87E75", "Samsung Electronics Co.,Ltd" },
{ "889821", "TERAON" },
{ "0026FD", "Interactive Intelligence" },
{ "0026F6", "Military Communication Institute" },
{ "0026F0", "cTrixs International GmbH." },
{ "0026EA", "Cheerchip Electronic Technology (ShangHai) Co., Ltd." },
{ "0026E3", "DTI" },
{ "0026DD", "Fival Science & Technology Co.,Ltd." },
{ "0026DE", "FDI MATELEC" },
{ "0026D7", "KM Electornic Technology Co., Ltd." },
{ "0026D1", "S Squared Innovations Inc." },
{ "54B620", "SUHDOL E&C Co.Ltd." },
{ "C4AAA1", "SUMMIT DEVELOPMENT, spol.s r.o." },
{ "78C40E", "H&D Wireless" },
{ "9C5B96", "NMR Corporation" },
{ "E4FFDD", "ELECTRON INDIA" },
{ "6C8CDB", "Otus Technologies Ltd" },
{ "B4417A", "ShenZhen Gongjin Electronics Co.,Ltd" },
{ "401597", "Protect America, Inc." },
{ "F852DF", "VNL Europe AB" },
{ "1CF061", "SCAPS GmbH" },
{ "A893E6", "JIANGXI JINGGANGSHAN CKING COMMUNICATION TECHNOLOGY CO.,LTD" },
{ "7825AD", "SAMSUNG ELECTRONICS CO., LTD." },
{ "0026CB", "Cisco Systems, Inc" },
{ "0026C4", "Cadmos microsystems S.r.l." },
{ "0026BE", "Schoonderbeek Elektronica Systemen B.V." },
{ "0026B2", "Setrix GmbH" },
{ "0026AC", "Shanghai LUSTER Teraband photonic Co., Ltd." },
{ "0026B1", "Navis Auto Motive Systems, Inc." },
{ "0026A8", "DAEHAP HYPER-TECH" },
{ "0026A7", "CONNECT SRL" },
{ "60391F", "ABB Ltd" },
{ "A07332", "Cashmaster International Limited" },
{ "7C7BE4", "Z'SEDAI KENKYUSHO CORPORATION" },
{ "40EF4C", "Fihonest communication co.,Ltd" },
{ "24CF21", "Shenzhen State Micro Technology Co., Ltd" },
{ "04B3B6", "Seamap (UK) Ltd" },
{ "10BAA5", "GANA I&C CO., LTD" },
{ "586ED6", "Private" },
{ "CC5076", "Ocom Communications, Inc." },
{ "705812", "Panasonic AVC Networks Company" },
{ "002648", "Emitech Corp." },
{ "002644", "Thomson Telecom Belgium" },
{ "00263E", "Trapeze Networks" },
{ "002638", "Xia Men Joyatech Co., Ltd." },
{ "00263D", "MIA Corporation" },
{ "002631", "COMMTACT LTD" },
{ "00262B", "Wongs Electronics Co. Ltd." },
{ "002625", "MediaSputnik" },
{ "00261E", "QINGBANG ELEC(SZ) CO., LTD" },
{ "002619", "FRC" },
{ "0025BA", "Alcatel-Lucent IPD" },
{ "0025B5", "Cisco Systems, Inc" },
{ "0025AE", "Microsoft Corporation" },
{ "0025A8", "Kontron (BeiJing) Technology Co.,Ltd" },
{ "0025A7", "Comverge, Inc." },
{ "0025A2", "Alta Definicion LINCEO S.L." },
{ "002596", "GIGAVISION srl" },
{ "00259B", "Beijing PKUNITY Microsystems Technology Co., Ltd" },
{ "002595", "Northwest Signal Supply, Inc" },
{ "002542", "Pittasoft" },
{ "002530", "Aetas Systems Inc." },
{ "002529", "COMELIT GROUP S.P.A" },
{ "002522", "ASRock Incorporation" },
{ "00251D", "DSA Encore, LLC" },
{ "002518", "Power PLUS Communications AG" },
{ "002513", "CXP DIGITAL BV" },
{ "0026A1", "Megger" },
{ "0026A2", "Instrumentation Technology Systems" },
{ "00269B", "SOKRAT Ltd." },
{ "002695", "ZT Group Int'l Inc" },
{ "00268F", "MTA SpA" },
{ "00267C", "Metz-Werke GmbH & Co KG" },
{ "00255C", "NEC Corporation" },
{ "002550", "Riverbed Technology" },
{ "002555", "Visonic Technologies 1993 Ltd" },
{ "00254F", "ELETTROLAB Srl" },
{ "002549", "Jeorich Tech. Co.,Ltd." },
{ "002538", "Samsung Electronics Co., Ltd., Memory Division" },
{ "002676", "COMMidt AS" },
{ "00266F", "Coordiwise Technology Corp." },
{ "002670", "Cinch Connectors" },
{ "002663", "Shenzhen Huitaiwei Tech. Ltd, co." },
{ "00265D", "Samsung Electronics" },
{ "00264F", "Krüger &Gothe GmbH" },
{ "0025E0", "CeedTec Sdn Bhd" },
{ "0025DA", "Secura Key" },
{ "0025D9", "DataFab Systems Inc." },
{ "0025D4", "Fortress Technologies" },
{ "0025CD", "Skylane Optics" },
{ "0025C8", "S-Access GmbH" },
{ "0025C7", "altek Corporation" },
{ "0025C1", "Nawoo Korea Corp." },
{ "002612", "Space Exploration Technologies" },
{ "00260B", "Cisco Systems, Inc" },
{ "00260C", "Dataram" },
{ "0025FF", "CreNova Multimedia Co., Ltd" },
{ "002606", "RAUMFELD GmbH" },
{ "0025F9", "GMK electronic design GmbH" },
{ "0025F5", "DVS Korea, Co., Ltd" },
{ "0025F0", "Suga Electronics Limited" },
{ "0025EA", "Iphion BV" },
{ "0025E4", "OMNI-WiFi, LLC" },
{ "00258F", "Trident Microsystems, Inc." },
{ "00258B", "Mellanox Technologies Ltd" },
{ "002585", "KOKUYO S&T Co., Ltd." },
{ "00257B", "STJ  ELECTRONICS  PVT  LTD" },
{ "002574", "KUNIMI MEDIA DEVICE Co., Ltd." },
{ "00256F", "Dantherm Power" },
{ "002562", "interbro Co. Ltd." },
{ "002561", "ProCurve Networking by HP" },
{ "0023F7", "Private" },
{ "0023FD", "AFT Atlas Fahrzeugtechnik GmbH" },
{ "0023F6", "Softwell Technology Co., Ltd." },
{ "0023EC", "Algorithmix GmbH" },
{ "0023E7", "Hinke A/S" },
{ "0023E0", "INO Therapeutics LLC" },
{ "0024C2", "Asumo Co.,Ltd." },
{ "0024BC", "HuRob Co.,Ltd" },
{ "0024B7", "GridPoint, Inc." },
{ "0024AB", "A7 Engineering, Inc." },
{ "0024A6", "TELESTAR DIGITAL GmbH" },
{ "00249A", "Beijing Zhongchuang Telecommunication Test Co., Ltd." },
{ "00249F", "RIM Testing Services" },
{ "00246D", "Weinzierl Engineering GmbH" },
{ "002474", "Autronica Fire And Securirty" },
{ "002468", "Sumavision Technologies Co.,Ltd" },
{ "002466", "Unitron nv" },
{ "002461", "Shin Wang Tech." },
{ "00245C", "Design-Com Technologies Pty. Ltd." },
{ "00244F", "Asantron Technologies Ltd." },
{ "002454", "Samsung Electronics CO., LTD" },
{ "002448", "SpiderCloud Wireless, Inc" },
{ "00244A", "Voyant International" },
{ "002449", "Shen Zhen Lite Star Electronics Technology Co., Ltd" },
{ "00250C", "Enertrac" },
{ "002505", "eks Engel GmbH & Co. KG" },
{ "0024F9", "Cisco Systems, Inc" },
{ "0024F2", "Uniphone Telecommunication Co., Ltd." },
{ "0024F4", "Kaminario Technologies Ltd." },
{ "0024ED", "YT Elec. Co,.Ltd." },
{ "0024E6", "In Motion Technology Inc." },
{ "0024E1", "Convey Computer Corp." },
{ "0024DF", "Digitalbox Europe GmbH" },
{ "0024DA", "Innovar Systems Limited" },
{ "0024CE", "Exeltech Inc" },
{ "0024D3", "QUALICA Inc." },
{ "0024C7", "Mobilarm Ltd" },
{ "002429", "MK MASTER INC." },
{ "00241C", "FuGang Electronic (DG) Co.,Ltd" },
{ "002428", "EnergyICT" },
{ "002416", "Any Use" },
{ "002410", "NUETEQ Technology,Inc." },
{ "002409", "The Toro Company" },
{ "002487", "Blackboard Inc." },
{ "002498", "Cisco Systems, Inc" },
{ "002485", "ConteXtream Ltd" },
{ "002480", "Meteocontrol GmbH" },
{ "002479", "Optec Displays, Inc." },
{ "002443", "Nortel Networks" },
{ "002439", "Digital Barriers Advanced Technologies" },
{ "002432", "Neostar Technology Co.,LTD" },
{ "0023DA", "Industrial Computer Source (Deutschland)GmbH" },
{ "0023C8", "TEAM-R" },
{ "0023C7", "AVSystem" },
{ "0023C1", "Securitas Direct AB" },
{ "0023BB", "Schmitt Industries" },
{ "0023BA", "Chroma" },
{ "0023B5", "ORTANA LTD" },
{ "002381", "Lengda Technology(Xiamen) Co.,Ltd." },
{ "002382", "Lih Rong Electronic Enterprise Co., Ltd." },
{ "00237B", "WHDI LLC" },
{ "002372", "MORE STAR INDUSTRIAL GROUP LIMITED" },
{ "002366", "Beijing Siasun Electronic System Co.,Ltd." },
{ "00236B", "Xembedded, Inc." },
{ "002359", "Benchmark Electronics ( Thailand ) Public Company Limited" },
{ "00235F", "Silicon Micro Sensors GmbH" },
{ "002353", "F E T Elettronica snc" },
{ "002347", "ProCurve Networking by HP" },
{ "00234C", "KTC AB" },
{ "00233A", "Samsung Electronics Co.,Ltd" },
{ "002339", "Samsung Electronics" },
{ "002334", "Cisco Systems, Inc" },
{ "00232E", "Kedah Electronics Engineering, LLC" },
{ "002329", "DDRdrive LLC" },
{ "002322", "KISS Teknical Solutions, Inc." },
{ "002325", "IOLAN Holding" },
{ "002319", "Sielox LLC" },
{ "002270", "ABK North America, LLC" },
{ "002317", "Lasercraft Inc" },
{ "002310", "LNC Technology Co., Ltd." },
{ "002304", "Cisco Systems, Inc" },
{ "002236", "VECTOR SP. Z O.O." },
{ "002230", "FutureLogic Inc." },
{ "002229", "Compumedics Ltd" },
{ "00221D", "Freegene Technology LTD" },
{ "002224", "Good Will Instrument Co., Ltd." },
{ "002223", "TimeKeeping Systems, Inc." },
{ "002216", "SHIBAURA VENDING MACHINE CORPORATION" },
{ "002217", "Neat Electronics" },
{ "002211", "Rohati Systems" },
{ "00220A", "OnLive, Inc" },
{ "002295", "SGM Technology for lighting spa" },
{ "00228E", "TV-NUMERIC" },
{ "002289", "Optosecurity Inc." },
{ "002282", "8086 Consultancy" },
{ "00227C", "Woori SMT Co.,ltd" },
{ "002279", "Nippon Conlux Co., Ltd." },
{ "002273", "Techway" },
{ "002274", "FamilyPhone AB" },
{ "00226F", "3onedata Technology Co. Ltd." },
{ "00226A", "Honeywell" },
{ "0022F3", "SHARP Corporation" },
{ "0022EE", "Algo Communication Products Ltd" },
{ "0022E7", "WPS Parking Systems" },
{ "0022E1", "ZORT Labs, LLC." },
{ "0022E2", "WABTEC Transit Division" },
{ "0022DB", "Translogic Corporation" },
{ "0022CF", "PLANEX Communications INC" },
{ "0022D4", "ComWorth Co., Ltd." },
{ "0022CA", "Anviz Biometric Tech. Co., Ltd." },
{ "0022C5", "INFORSON Co,Ltd." },
{ "002260", "AFREEY Inc." },
{ "00225B", "Teradici Corporation" },
{ "002256", "Cisco Systems, Inc" },
{ "002255", "Cisco Systems, Inc" },
{ "00224D", "MITAC INTERNATIONAL CORP." },
{ "002252", "ZOLL Lifecor Corporation" },
{ "002246", "Evoc Intelligent Technology Co.,Ltd." },
{ "00223C", "RATIO Entwicklungen GmbH" },
{ "0022C0", "Shenzhen Forcelink Electronic Co, Ltd" },
{ "0022BB", "beyerdynamic GmbH & Co. KG" },
{ "0022AE", "Mattel Inc." },
{ "0022AD", "TELESIS TECHNOLOGIES, INC." },
{ "0022A8", "Ouman Oy" },
{ "0022A1", "Huawei Symantec Technologies Co.,Ltd." },
{ "00229B", "AverLogic Technologies, Inc." },
{ "00229C", "Verismo Networks Inc" },
{ "0023A8", "Marshall Electronics" },
{ "00239B", "Elster Solutions, LLC" },
{ "002396", "ANDES TECHNOLOGY CORPORATION" },
{ "002391", "Maxian" },
{ "00238C", "Private" },
{ "002387", "ThinkFlood, Inc." },
{ "0021D6", "LXI Consortium" },
{ "0021CF", "The Crypto Group" },
{ "0021C9", "Wavecom Asia Pacific Limited" },
{ "0021CA", "ART System Co., Ltd." },
{ "0021C3", "CORNELL Communications, Inc." },
{ "0021BC", "ZALA COMPUTER" },
{ "0021B7", "Lexmark International Inc." },
{ "002152", "General Satellite Research & Development Limited" },
{ "002157", "National Datacast, Inc." },
{ "00214B", "Shenzhen HAMP Science & Technology Co.,Ltd" },
{ "002145", "Semptian Technologies Ltd." },
{ "002144", "SS Telecoms" },
{ "00213C", "AliphCom" },
{ "00213B", "Berkshire Products, Inc" },
{ "002132", "Masterclock, Inc." },
{ "00212C", "SemIndia System Private Limited" },
{ "002131", "Blynke Inc." },
{ "001FD1", "OPTEX CO.,LTD." },
{ "001FCA", "Cisco Systems, Inc" },
{ "001FBE", "Shenzhen Mopnet Industrial Co.,Ltd" },
{ "001FB9", "Paltronics" },
{ "001FB7", "WiMate Technologies Corp." },
{ "001FB8", "Universal Remote Control, Inc." },
{ "001FB2", "Sontheim Industrie Elektronik GmbH" },
{ "00211F", "SHINSUNG DELTATECH CO.,LTD." },
{ "002120", "Sequel Technologies" },
{ "002125", "KUK JE TONG SHIN Co.,LTD" },
{ "002119", "Samsung Electro-Mechanics" },
{ "002112", "WISCOM SYSTEM CO.,LTD" },
{ "002103", "GHI Electronics, LLC" },
{ "0021B0", "Tyco Telecommunications" },
{ "0021A4", "Dbii Networks" },
{ "00219A", "Cambridge Visual Networks Ltd" },
{ "002196", "Telsey  S.p.A." },
{ "002190", "Goliath Solutions" },
{ "002189", "AppTech, Inc." },
{ "002184", "POWERSOFT SRL" },
{ "002183", "VATECH HYDRO" },
{ "001FFA", "Coretree, Co, Ltd" },
{ "001FF5", "Kongsberg Defence & Aerospace" },
{ "001FF4", "Power Monitors, Inc." },
{ "001FEE", "ubisys technologies GmbH" },
{ "001FE7", "Simet" },
{ "001FDB", "Network Supply Corp.," },
{ "00217D", "PYXIS S.R.L." },
{ "002177", "W. L. Gore & Associates" },
{ "002176", "YMax Telecom Ltd." },
{ "002171", "Wesung TNC Co., Ltd." },
{ "002164", "Special Design Bureau for Seismic Instrumentation" },
{ "00215E", "IBM Corp" },
{ "002151", "Millinet Co., Ltd." },
{ "002204", "KORATEK" },
{ "0021FF", "Cyfrowy Polsat SA" },
{ "0021FB", "LG Electronics" },
{ "0021F5", "Western Engravers Supply, Inc." },
{ "0021EF", "Kapsys" },
{ "0021EE", "Full Spectrum Inc." },
{ "0021DC", "TECNOALARM S.r.l." },
{ "0021E2", "Creative Electronic GmbH" },
{ "001FAB", "I.S HIGH TECH.INC" },
{ "001FA6", "Stilo srl" },
{ "001FA1", "Gtran Inc" },
{ "001F9C", "LEDCO" },
{ "001F8E", "Metris USA Inc." },
{ "001E41", "Microwave Communication & Component, Inc." },
{ "001E2E", "SIRTI S.p.A." },
{ "001E27", "SBN TECH Co.,Ltd." },
{ "001E28", "Lumexis Corporation" },
{ "001E22", "ARVOO Imaging Products BV" },
{ "001E1B", "Digital Stream Technology, Inc." },
{ "001E16", "Keytronix" },
{ "001E15", "Beech Hill Electronics" },
{ "001E11", "ELELUX INTERNATIONAL LTD" },
{ "001E05", "Xseed Technologies & Computing" },
{ "001E0C", "Sherwood Information Partners, Inc." },
{ "001DFE", "Palm, Inc" },
{ "001DF9", "Cybiotronics (Far East) Limited" },
{ "001DF2", "Netflix, Inc." },
{ "001DEB", "DINEC International" },
{ "001DEC", "Marusys" },
{ "001F88", "FMS Force Measuring Systems AG" },
{ "001F81", "Accel Semiconductor Corp" },
{ "001B58", "ACE CAD Enterprise Co., Ltd." },
{ "001F78", "Blue Fox Porini Textile" },
{ "001F6E", "Vtech Engineering Corporation" },
{ "001F68", "Martinsson Elektronik AB" },
{ "001F62", "JSC Stilsoft" },
{ "001F67", "Hitachi,Ltd." },
{ "001F55", "Honeywell Security (China) Co., Ltd." },
{ "001E9B", "San-Eisha, Ltd." },
{ "001E94", "SUPERCOM TECHNOLOGY CORPORATION" },
{ "001E8F", "CANON INC." },
{ "001E87", "Realease Limited" },
{ "001E80", "Last Mile Ltd." },
{ "001E7B", "R.I.CO. S.r.l." },
{ "001E76", "Thermo Fisher Scientific" },
{ "001E6A", "Beijing Bluexon Technology Co.,Ltd" },
{ "001F56", "DIGITAL FORECAST" },
{ "001F4F", "Thinkware Co. Ltd." },
{ "001F48", "Mojix Inc." },
{ "001F43", "ENTES ELEKTRONIK" },
{ "001F2E", "Triangle Research Int'l Pte Ltd" },
{ "001F2D", "Electro-Optical Imaging, Inc." },
{ "001F27", "Cisco Systems, Inc" },
{ "001EF5", "Hitek Automated Inc." },
{ "001EFB", "Trio Motion Technology Ltd" },
{ "001EE9", "Stoneridge Electronics AB" },
{ "001EEE", "ETL Systems Ltd" },
{ "001EE2", "Samsung Electronics Co.,Ltd" },
{ "001ED8", "Digital United Inc." },
{ "001ED2", "Ray Shine Video Technology Inc" },
{ "001ED1", "Keyprocessor B.V." },
{ "001ECC", "CDVI" },
{ "001EC5", "Middle Atlantic Products Inc" },
{ "001EC0", "Microchip Technology Inc." },
{ "001EBF", "Haas Automation Inc." },
{ "001EB9", "Sing Fai Technology Limited" },
{ "001EB2", "LG innotek" },
{ "001EAD", "Wingtech Group Limited" },
{ "001EA2", "Symx Systems, Inc." },
{ "001EA7", "Actiontec Electronics, Inc" },
{ "001EA1", "Brunata a/s" },
{ "001F20", "Logitech Europe SA" },
{ "001F14", "NexG" },
{ "001F1B", "RoyalTek Company Ltd." },
{ "001F0D", "L3 Communications - Telemetry West" },
{ "001F0E", "Japan Kyastem Co., Ltd" },
{ "001EFC", "JSC MASSA-K" },
{ "001F08", "RISCO LTD" },
{ "001E71", "MIrcom Group of Companies" },
{ "001E63", "Vibro-Meter SA" },
{ "001E5E", "COmputime Ltd." },
{ "001E57", "ALCOMA, spol. s r.o." },
{ "001E51", "Converter Industry Srl" },
{ "001E4B", "City Theatrical" },
{ "001E47", "PT. Hariff Daya Tunggal Engineering" },
{ "001D37", "Thales-Panda Transportation System" },
{ "001D38", "Seagate Technology" },
{ "001D32", "Longkay Communication & Technology (Shanghai) Co. Ltd" },
{ "001D2B", "Wuhan Pont Technology CO. , LTD" },
{ "001D1F", "Siauliu Tauro Televizoriai, JSC" },
{ "001D26", "Rockridgesound Technology Co." },
{ "001D25", "Samsung Electronics Co.,Ltd" },
{ "001D1A", "OvisLink S.A." },
{ "001D14", "SPERADTONE INFORMATION TECHNOLOGY LIMITED" },
{ "001CDD", "COWBELL ENGINEERING CO., LTD." },
{ "001CDE", "Interactive Multimedia eXchange Inc." },
{ "001CD8", "BlueAnt Wireless" },
{ "001CD1", "Waves Audio LTD" },
{ "001CCB", "Forth Corporation Public Company Limited" },
{ "001CC5", "3Com Ltd" },
{ "001CB9", "KWANG SUNG ELECTRONICS CO., LTD." },
{ "001CAF", "Plato Networks Inc." },
{ "001CB4", "Iridium Satellite LLC" },
{ "001C6C", "Jabil Circuit (Guangzhou) Limited" },
{ "001C65", "JoeScan, Inc." },
{ "001C67", "Pumpkin Networks, Inc." },
{ "001C66", "UCAMP CO.,LTD" },
{ "001C60", "CSP Frontier Technologies,Inc." },
{ "001C54", "Hillstone Networks Inc" },
{ "001C59", "DEVON IT" },
{ "001C4F", "MACAB AB" },
{ "001C43", "Samsung Electronics Co.,Ltd" },
{ "001C37", "Callpod, Inc." },
{ "001C3C", "Seon Design Inc." },
{ "001DE6", "Cisco Systems, Inc" },
{ "001DDA", "Mikroelektronika spol. s r. o." },
{ "001DDF", "Sunitec Enterprise Co., Ltd." },
{ "001DCC", "Hetra Secure Solutions" },
{ "001DC7", "L-3 Communications Geneva Aerospace" },
{ "001DC0", "Enphase Energy" },
{ "001DB9", "Wellspring Wireless" },
{ "001D08", "JIANGSU YINHE ELECTRONICS CO., LTD" },
{ "001D07", "Shenzhen Sang Fei Consumer Communications Co.,Ltd" },
{ "001D01", "Neptune Digital" },
{ "001CFA", "Alarm.com" },
{ "001CEE", "SHARP Corporation" },
{ "001CF5", "Wiseblue Technology Limited" },
{ "001CE8", "Cummins Inc" },
{ "001CE4", "EleSy JSC" },
{ "001C9F", "Razorstream, LLC" },
{ "001C99", "Shunra Software Ltd." },
{ "001C8C", "DIAL TECHNOLOGY LTD." },
{ "001C93", "ExaDigm Inc" },
{ "001C87", "Uriver Inc." },
{ "001C82", "Genew Technologies" },
{ "001C7D", "Excelpoint Manufacturing Pte Ltd" },
{ "001C73", "Arista Networks, Inc." },
{ "001C78", "WYPLAY SAS" },
{ "001D62", "InPhase Technologies" },
{ "001D61", "BIJ Corporation" },
{ "001D5B", "Tecvan Informática Ltda" },
{ "001D54", "Sunnic Technology & Merchandise INC." },
{ "001D4A", "Carestream Health, Inc." },
{ "001D45", "Cisco Systems, Inc" },
{ "001D3E", "SAKA TECHNO SCIENCE CO.,LTD" },
{ "001D90", "EMCO Flow Systems" },
{ "001D84", "Gateway, Inc." },
{ "001D67", "AMEC" },
{ "001D7A", "Wideband Semiconductor, Inc." },
{ "001D74", "Tianjin China-Silicon Microelectronics Co., Ltd." },
{ "001DB4", "KUMHO ENG CO.,LTD" },
{ "001DAF", "Nortel" },
{ "001D9E", "AXION TECHNOLOGIES" },
{ "001DA3", "SabiOso" },
{ "001D9D", "ARTJOY INTERNATIONAL LIMITED" },
{ "001D97", "Alertus Technologies LLC" },
{ "001BA6", "intotech inc." },
{ "001BA1", "mic AB" },
{ "001B93", "JC Decaux SA DNT" },
{ "001B95", "VIDEO SYSTEMS SRL" },
{ "001B9A", "Apollo Fire Detectors Ltd" },
{ "001B94", "T.E.M.A. S.p.A." },
{ "001B8E", "Hulu Sweden AB" },
{ "001B89", "EMZA Visual Sense Ltd." },
{ "001B8A", "2M Electronic A/S" },
{ "001B84", "Scan Engineering Telecom" },
{ "001B7D", "CXR Anderson Jacobson" },
{ "001B71", "Telular Corp." },
{ "001B6A", "Powerwave Technologies Sweden AB" },
{ "001B65", "China Gridcom Co., Ltd" },
{ "001B5E", "BPL Limited" },
{ "001B57", "SEMINDIA SYSTEMS PRIVATE LIMITED" },
{ "001B46", "Blueone Technology Co.,Ltd" },
{ "001B4B", "SANION Co., Ltd." },
{ "001B3F", "ProCurve Networking by HP" },
{ "001BCF", "Dataupia Corporation" },
{ "001BD0", "IDENTEC SOLUTIONS" },
{ "001BCA", "Beijing Run Technology LTD. Company" },
{ "001BC3", "Mobisolution Co.,Ltd" },
{ "001BBE", "ICOP Digital" },
{ "001BB4", "Airvod Limited" },
{ "001BAD", "iControl Incorporated" },
{ "001AD1", "FARGO CO., LTD." },
{ "001AD8", "AlsterAero GmbH" },
{ "001ACA", "Tilera Corporation" },
{ "001ACC", "Celestial Semiconductor, Ltd" },
{ "001AC5", "BreakingPoint Systems, Inc." },
{ "001ABB", "Fontal Technology Incorporation" },
{ "001AC0", "JOYBIEN TECHNOLOGIES CO., LTD." },
{ "001AB4", "FFEI Ltd." },
{ "001AAF", "BLUSENS TECHNOLOGY" },
{ "001C07", "Cwlinux Limited" },
{ "001C00", "Entry Point, LLC" },
{ "001BF4", "KENWIN INDUSTRIAL(HK) LTD." },
{ "001BEF", "Blossoms Digital Technology Co.,Ltd." },
{ "001BE2", "AhnLab,Inc." },
{ "001BD1", "SOGESTMATIC" },
{ "001BD6", "Kelvin Hughes Ltd" },
{ "001C30", "Mode Lighting (UK ) Ltd." },
{ "001C2B", "Alertme.com Limited" },
{ "001C2A", "Envisacor Technologies Inc." },
{ "001C29", "CORE DIGITAL ELECTRONICS CO., LTD" },
{ "001C24", "Formosa Wireless Systems Corp." },
{ "001C1F", "Quest Retail Technology Pty Ltd" },
{ "001C1A", "Thomas Instrumentation, Inc" },
{ "001C0E", "Cisco Systems, Inc" },
{ "001C13", "OPTSYS TECHNOLOGY CO., LTD." },
{ "001B3A", "SIMS Corp." },
{ "001B2C", "ATRON electronic GmbH" },
{ "001B27", "Merlin CSI" },
{ "001B25", "Nortel" },
{ "001B20", "TPine Technology" },
{ "001B19", "IEEE I&M Society TC9" },
{ "001B14", "Carex Lighting Equipment Factory" },
{ "001B0D", "Cisco Systems, Inc" },
{ "001AA8", "Mamiya Digital Imaging Co., Ltd." },
{ "001A9F", "A-Link Ltd" },
{ "001AA6", "Telefunken Radio Communication Systems GmbH &CO.KG" },
{ "001A93", "ERCO Leuchten GmbH" },
{ "001A98", "Asotel Communication Limited Taiwan Branch" },
{ "001A8E", "3Way Networks Ltd" },
{ "001B06", "Ateliers R. LAUMONIER" },
{ "001B08", "Danfoss Drives A/S" },
{ "001B01", "Applied Radio Technologies" },
{ "001AF5", "PENTAONE. CO., LTD." },
{ "001AFA", "Welch Allyn, Inc." },
{ "001AF0", "Alcatel - IPD" },
{ "001AE4", "Medicis Technologies Corporation" },
{ "001ADD", "PePWave Ltd" },
{ "001933", "Strix Systems, Inc." },
{ "001938", "UMB Communications Co., Ltd." },
{ "00192D", "Nokia Corporation" },
{ "001926", "BitsGen Co., Ltd." },
{ "001928", "Siemens AG, Transportation Systems" },
{ "00190E", "Atech Technology Co., Ltd." },
{ "001913", "Chuang-Yi Network Equipment Co.Ltd." },
{ "001915", "TECOM Co., Ltd." },
{ "00191A", "IRLINK" },
{ "00199D", "VIZIO, Inc." },
{ "00198E", "Oticon A/S" },
{ "001980", "Gridpoint Systems" },
{ "001987", "Panasonic Mobile Communications Co., Ltd." },
{ "00197B", "Picotest Corp." },
{ "001968", "Digital Video Networks(Shanghai) CO. LTD." },
{ "00196D", "Raybit Systems Korea, Inc" },
{ "00196F", "SensoPart GmbH" },
{ "001952", "ACOGITO Co., Ltd" },
{ "001957", "Saafnet Canada Inc." },
{ "001946", "Cianet Industria e Comercio S/A" },
{ "001944", "Fossil Partners, L.P." },
{ "00193F", "RDI technology(Shenzhen) Co.,LTD" },
{ "001A7D", "cyber-blue(HK)Ltd" },
{ "001A82", "PROBA Building Automation Co.,LTD" },
{ "001A7C", "Hirschmann Multimedia B.V." },
{ "001A78", "ubtos" },
{ "001A7B", "Teleco, Inc." },
{ "001A71", "Diostech Co., Ltd." },
{ "001A6C", "Cisco Systems, Inc" },
{ "001A65", "Seluxit" },
{ "001A60", "Wave Electronics Co.,Ltd." },
{ "001A55", "ACA-Digital Corporation" },
{ "001A5A", "Korea Electric Power Data Network  (KDN) Co., Ltd" },
{ "001A4E", "NTI AG / LinMot" },
{ "001A53", "Zylaya" },
{ "001A42", "Techcity Technology co., Ltd." },
{ "001A47", "Agami Systems, Inc." },
{ "001A3B", "Doah Elecom Inc." },
{ "001A2F", "Cisco Systems, Inc" },
{ "001A34", "Konka Group Co., Ltd." },
{ "001A36", "Aipermon GmbH & Co. KG" },
{ "001A25", "DELTA DORE" },
{ "0019C3", "Qualitrol" },
{ "0019BE", "Altai Technologies Limited" },
{ "0019BC", "ELECTRO CHANCE SRL" },
{ "0019A4", "Austar Technology (hang zhou) Co.,Ltd" },
{ "0019A9", "Cisco Systems, Inc" },
{ "0019AB", "Raycom CO ., LTD" },
{ "0019B0", "HanYang System" },
{ "001993", "Changshu Switchgear MFG. Co.,Ltd. (Former Changshu Switchgea" },
{ "001998", "SATO CORPORATION" },
{ "001A17", "Teak Technologies, Inc." },
{ "001A19", "Computer Engineering Limited" },
{ "001A12", "Essilor" },
{ "001A0B", "BONA TECHNOLOGY INC." },
{ "001A06", "OpVista, Inc." },
{ "0019FA", "Cable Vision Electronics CO., LTD." },
{ "0019FF", "Finnzymes" },
{ "001902", "Cambridge Consultants Ltd" },
{ "001907", "Cisco Systems, Inc" },
{ "0018FD", "Optimal Technologies International Inc." },
{ "0018F1", "Chunichi Denshi Co.,LTD." },
{ "0018EA", "Alltec GmbH" },
{ "0018EC", "Welding Technology Corporation" },
{ "0018E5", "Adhoco AG" },
{ "0018CD", "Erae Electronics Industry Co., Ltd" },
{ "0018D2", "High-Gain Antennas LLC" },
{ "0019EC", "Sagamore Systems, Inc." },
{ "0019F3", "Cetis, Inc" },
{ "0019F8", "Embedded Systems Design, Inc." },
{ "0019E5", "Lynx Studio Technology, Inc." },
{ "0019E7", "Cisco Systems, Inc" },
{ "0019CD", "Chengdu ethercom information technology Ltd." },
{ "0019D4", "ICX Technologies" },
{ "0019D9", "Zeutschel GmbH" },
{ "0019C8", "AnyDATA Corporation" },
{ "001817", "D. E. Shaw Research, LLC" },
{ "00181E", "GDX Technologies Ltd." },
{ "001812", "Beijing Xinwei Telecom Technology Co., Ltd." },
{ "001806", "Hokkei Industries Co., Ltd." },
{ "00180B", "Brilliant Telecommunications" },
{ "001805", "Beijing InHand Networking Technology Co.,Ltd." },
{ "0017F4", "ZERON ALLIANCE" },
{ "0017F9", "Forcom Sp. z o.o." },
{ "001800", "UNIGRAND LTD" },
{ "0017B1", "ACIST Medical Systems, Inc." },
{ "0017AA", "elab-experience inc." },
{ "0017AC", "O'Neil Product Development Inc." },
{ "0017A5", "Ralink Technology Corp" },
{ "0017A0", "RoboTech srl" },
{ "00179B", "Chant Sincere CO., LTD." },
{ "00178F", "NINGBO YIDONG ELECTRONIC CO.,LTD." },
{ "001794", "Cisco Systems, Inc" },
{ "00178D", "Checkpoint Systems, Inc." },
{ "0018D7", "Javad Navigation Systems Inc." },
{ "0018D9", "Santosha Internatonal, Inc" },
{ "0018C1", "Almitec Informática e Comércio" },
{ "0018C8", "ISONAS Inc." },
{ "0018BC", "ZAO NVP Bolid" },
{ "0018B5", "Magna Carta" },
{ "0018B0", "Nortel" },
{ "0018AE", "TVT CO.,LTD" },
{ "0018A2", "XIP Technology AB" },
{ "0018A9", "Ethernet Direct Corporation" },
{ "00177C", "Smartlink Network Systems Limited" },
{ "001781", "Greystone Data System, Inc." },
{ "001788", "Philips Lighting BV" },
{ "00176C", "Pivot3, Inc." },
{ "001770", "Arti Industrial Electronics Ltd." },
{ "001775", "TTE Germany GmbH" },
{ "001760", "Naito Densei Machida MFG.CO.,LTD" },
{ "001765", "Nortel" },
{ "001767", "Earforce AS" },
{ "001759", "Cisco Systems, Inc" },
{ "001880", "Maxim Integrated Products" },
{ "00186D", "Zhenjiang Sapphire Electronic Industry CO." },
{ "001872", "Expertise Engineering" },
{ "001874", "Cisco Systems, Inc" },
{ "001879", "dSys" },
{ "00185A", "uControl, Inc." },
{ "00185F", "TAC Inc." },
{ "001861", "Ooma, Inc." },
{ "001866", "Leutron Vision" },
{ "001853", "Atera Networks LTD." },
{ "00184E", "Lianhe Technologies, Inc." },
{ "001847", "AceNet Technology Inc." },
{ "00183B", "CENITS Co., Ltd." },
{ "001840", "3 Phoenix, Inc." },
{ "001842", "Nokia Danmark A/S" },
{ "001825", "Private" },
{ "00182A", "Taiwan Video & Monitor" },
{ "001836", "Reliance Electric Limited" },
{ "001823", "Delta Electronics, Inc." },
{ "001754", "Arkino HiTOP Corporation Limited" },
{ "001746", "Freedom9 Inc." },
{ "001748", "Neokoros Brasil Ltda" },
{ "00174D", "DYNAMIC NETWORK FACTORY, INC." },
{ "001741", "DEFIDEV" },
{ "001733", "SFR" },
{ "00173A", "Reach Systems Inc." },
{ "00172E", "FXC Inc." },
{ "0017ED", "WooJooIT Ltd." },
{ "0017D5", "Samsung Electronics Co., Ltd." },
{ "0017DA", "Spans Logic" },
{ "0017E1", "DACOS Technologies Co., Ltd." },
{ "0017C9", "Samsung Electronics Co., Ltd." },
{ "0017D0", "Opticom Communications, LLC" },
{ "0017C4", "Quanta Microsystems, INC." },
{ "0017B8", "NOVATRON CO., LTD." },
{ "0017BD", "Tibetsystem" },
{ "00189D", "Navcast Inc." },
{ "001893", "SHENZHEN PHOTON BROADBAND TECHNOLOGY CO.,LTD" },
{ "001898", "KINGSTATE ELECTRONICS CORPORATION" },
{ "001891", "Zhongshan General K-mate Electronics Co., Ltd" },
{ "001885", "Avigilon Corporation" },
{ "00188C", "Mobile Action Technology Inc." },
{ "00167F", "Bluebird Soft Inc." },
{ "001681", "Vector Informatik GmbH" },
{ "00167A", "Skyworth Overseas Dvelopment Ltd." },
{ "001674", "EuroCB (Phils.), Inc." },
{ "00166B", "Samsung Electronics" },
{ "00166D", "Yulong Computer Telecommunication Scientific(shenzhen)Co.,Lt" },
{ "001672", "Zenway enterprise ltd" },
{ "00166C", "Samsung Electonics Digital Video System Division" },
{ "001666", "Quantier Communication Inc." },
{ "00165F", "Fairmount Automation" },
{ "00165A", "Harman Specialty Group" },
{ "001653", "LEGO System A/S IE Electronics Division" },
{ "0016DF", "Lundinova AB" },
{ "0016DA", "Futronic Technology Co. Ltd." },
{ "0016D5", "Synccom Co., Ltd" },
{ "0016C9", "NAT Seattle, Inc." },
{ "0016D0", "ATech elektronika d.o.o." },
{ "0016BD", "ATI Industrial Automation" },
{ "0016C2", "Avtec Systems Inc" },
{ "0016BB", "Law-Chain Computer Technology Co Ltd" },
{ "0016AA", "Kei Communication Technology Inc." },
{ "0016AF", "Shenzhen Union Networks Equipment Co.,Ltd." },
{ "00162A", "Antik computers & communications s.r.o." },
{ "001623", "Interval Media" },
{ "001617", "MSI" },
{ "00161E", "Woojinnet" },
{ "00160D", "Be Here Corporation" },
{ "001606", "Ideal Industries" },
{ "0015FA", "Cisco Systems, Inc" },
{ "0015F5", "Sustainable Energy Systems" },
{ "0015F4", "Eventide" },
{ "001705", "Methode Electronics" },
{ "00170A", "INEW DIGITAL COMPANY" },
{ "0016F9", "CETRTA POT, d.o.o., Kranj" },
{ "0016F2", "Dmobile System Co., Ltd." },
{ "0016F7", "L-3 Communications, Aviation Recorders" },
{ "0016E6", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "00164C", "PLANET INT Co., Ltd" },
{ "001647", "Cisco Systems, Inc" },
{ "001642", "Pangolin" },
{ "00163D", "Tsinghua Tongfang Legend Silicon Tech. Co., Ltd." },
{ "001636", "Quanta Computer Inc." },
{ "001631", "Xteam" },
{ "00162F", "Geutebrück GmbH" },
{ "001630", "Vativ Technologies" },
{ "0016A5", "Tandberg Storage ASA" },
{ "001699", "Tonic DVB Marketing Ltd" },
{ "0016A0", "Auto-Maskin" },
{ "001692", "Scientific-Atlanta, Inc." },
{ "001694", "Sennheiser Communications A/S" },
{ "00168D", "KORWIN CO., Ltd." },
{ "001686", "Karl Storz Imaging" },
{ "0015EE", "Omnex Control Systems" },
{ "0015F3", "PELTOR AB" },
{ "0015E7", "Quantec Tontechnik" },
{ "0015E2", "Dr.Ing. Herbert Knauer GmbH" },
{ "0015DD", "IP Control Systems Ltd." },
{ "0015D8", "Interlink Electronics" },
{ "0015CA", "TeraRecon, Inc." },
{ "0015BC", "Develco" },
{ "0015B5", "CI Network Corp." },
{ "0015B0", "AUTOTELENET CO.,LTD" },
{ "0015AB", "PRO CO SOUND INC" },
{ "0015A6", "Digital Electronics Products Ltd." },
{ "00159F", "Terascala, Inc." },
{ "001598", "Kolektor group" },
{ "001727", "Thermo Ramsey Italia s.r.l." },
{ "001722", "Hanazeder Electronic GmbH" },
{ "00171B", "Innovation Lab Corp." },
{ "001714", "BR Controls Nederland bv" },
{ "001716", "Qno Technology Inc." },
{ "00170F", "Cisco Systems, Inc" },
{ "0014AA", "Ashly Audio, Inc." },
{ "00149D", "Sound ID Inc." },
{ "001498", "Viking Design Technology" },
{ "00148A", "Elin Ebg Traction Gmbh" },
{ "001491", "Daniels Electronics Ltd. dbo Codan Rado Communications" },
{ "001485", "Giga-Byte" },
{ "00147E", "InnerWireless" },
{ "001478", "ShenZhen TP-LINK Technologies Co., Ltd." },
{ "001532", "Consumer Technologies Group, LLC" },
{ "001539", "Technodrive srl" },
{ "00152B", "Cisco Systems, Inc" },
{ "00152D", "TenX Networks, LLC" },
{ "00152C", "Cisco Systems, Inc" },
{ "00151F", "Multivision Intelligent Surveillance (Hong Kong) Ltd" },
{ "001526", "Remote Technologies Inc" },
{ "00151A", "Hunter Engineering Company" },
{ "001515", "Leipold+Co.GmbH" },
{ "001510", "Techsphere Co., Ltd" },
{ "001502", "BETA tech" },
{ "001509", "Plus Technology Co., Ltd" },
{ "00144E", "SRISA" },
{ "001442", "ATTO CORPORATION" },
{ "001449", "Sichuan Changhong Electric Ltd." },
{ "00143D", "Aevoe Inc." },
{ "00143C", "Rheinmetall Canada Inc." },
{ "00143B", "Sensovation AG" },
{ "001436", "Qwerty Elektronik AB" },
{ "001423", "J-S Co. NEUROCOM" },
{ "001593", "U4EA Technologies Inc." },
{ "00158C", "Liab ApS" },
{ "001586", "Xiamen Overseas Chinese Electronic Co., Ltd." },
{ "001585", "Aonvision Technolopy Corp." },
{ "001587", "Takenaka Seisakusho Co.,Ltd" },
{ "001580", "U-WAY CORPORATION" },
{ "00157B", "Leuze electronic GmbH + Co. KG" },
{ "001576", "LABiTec - Labor Biomedical Technologies GmbH" },
{ "00156A", "DG2L Technologies Pvt. Ltd." },
{ "00156F", "Xiranet Communications GmbH" },
{ "001563", "Cisco Systems, Inc" },
{ "0014FD", "Thecus Technology Corp." },
{ "0014EF", "TZero Technologies, Inc." },
{ "0014F1", "Cisco Systems, Inc" },
{ "0014F0", "Business Security OL AB" },
{ "0014EA", "S Digm Inc. (Safe Paradigm Inc.)" },
{ "0014E5", "Alticast" },
{ "0014E6", "AIM Infrarotmodule GmbH" },
{ "0014E0", "LET'S Corporation" },
{ "0014D4", "K Technology Corporation" },
{ "0014D9", "IP Fabrics, Inc." },
{ "0014CD", "DigitalZone Co., Ltd." },
{ "0014C1", "U.S. Robotics Corporation" },
{ "0014C6", "Quixant Ltd" },
{ "0014BA", "Carvers SA de CV" },
{ "0014B5", "PHYSIOMETRIX,INC" },
{ "0014AB", "Senhai Electronic Technology Co., Ltd." },
{ "0014B0", "Naeil Community" },
{ "0014B4", "General Dynamics United Kingdom Ltd" },
{ "0014A9", "Cisco Systems, Inc" },
{ "001557", "Olivetti" },
{ "00155C", "Dresser Wayne" },
{ "00154B", "Wonde Proud Technology Co., Ltd" },
{ "001550", "Nits Technology Inc" },
{ "001545", "SEECODE Co., Ltd." },
{ "00153E", "Q-Matic Sweden AB" },
{ "001477", "Nertec  Inc." },
{ "001472", "China Broadband Wireless IP Standard Group" },
{ "001466", "Kleinhenz Elektronik GmbH" },
{ "00146B", "Anagran, Inc." },
{ "00145F", "ADITEC CO. LTD" },
{ "001458", "HS Automatic ApS" },
{ "001453", "ADVANTECH TECHNOLOGIES CO.,LTD" },
{ "001419", "SIDSA" },
{ "001412", "S-TEC electronics AG" },
{ "00140D", "Nortel" },
{ "001409", "MAGNETI MARELLI   S.E. S.p.A." },
{ "00140A", "WEPIO Co., Ltd." },
{ "0013FD", "Nokia Danmark A/S" },
{ "0013F8", "Dex Security Solutions" },
{ "0013F1", "AMOD Technology Co., Ltd." },
{ "00135C", "OnSite Systems, Inc." },
{ "001355", "TOMEN Cyber-business Solutions, Inc." },
{ "001356", "FLIR Radiation Inc" },
{ "001350", "Silver Spring Networks, Inc" },
{ "001344", "Fargo Electronics Inc." },
{ "001349", "ZyXEL Communications Corporation" },
{ "001343", "Matsushita Electronic Components (Europe) GmbH" },
{ "00133D", "Micro Memory Curtiss Wright Co" },
{ "00132A", "Sitronics Telecom Solutions" },
{ "001331", "CellPoint Connect" },
{ "001336", "Tianjin 712 Communication Broadcasting co., ltd." },
{ "001284", "Lab33 Srl" },
{ "00127E", "Digital Lifestyles Group, Inc." },
{ "001277", "Korenix Technologies Co., Ltd." },
{ "001272", "Redux Communications Ltd." },
{ "001271", "Measurement Computing Corp" },
{ "00126B", "Ascalade Communications Limited" },
{ "001264", "daum electronic gmbh" },
{ "00125A", "Microsoft Corporation" },
{ "0012FA", "THX LTD" },
{ "001301", "IronGate S.L." },
{ "001307", "Paravirtual Corporation" },
{ "0012F5", "Imarda New Zealand Limited" },
{ "0012EB", "PDH Solutions, LLC" },
{ "0012DE", "Radio Components Sweden AB" },
{ "0012DD", "Shengqu Information Technology (Shanghai) Co., Ltd." },
{ "0012E4", "ZIEHL industrie-electronik GmbH + Co KG" },
{ "0012D8", "International Games System Co., Ltd." },
{ "0013B6", "Sling Media, Inc." },
{ "0013AF", "NUMA Technology,Inc." },
{ "0013B0", "Jablotron" },
{ "0013AA", "ALS  & TEC Ltd." },
{ "0013A3", "Siemens Com CPE Devices" },
{ "00139E", "Ciara Technologies Inc." },
{ "00139D", "Marvell Hispana S.L." },
{ "0012A8", "intec GmbH" },
{ "0012A2", "VITA" },
{ "0012A1", "BluePacket Communications Co., Ltd." },
{ "00129C", "Yulinet" },
{ "001290", "KYOWA Electric & Machinery Corp." },
{ "001295", "Aiware Inc." },
{ "001283", "Nortel Networks" },
{ "00138B", "Phantom Technologies LLC" },
{ "001390", "Termtek Computer Co., Ltd" },
{ "001376", "Tabor Electronics Ltd." },
{ "00137B", "Movon Corporation" },
{ "001382", "Cetacea Networks Corporation" },
{ "001387", "27M Technologies AB" },
{ "00136F", "PacketMotion, Inc." },
{ "001375", "American Security Products Co." },
{ "001363", "Verascape, Inc." },
{ "001368", "Saab Danmark A/S" },
{ "0013F7", "SMC Networks, Inc." },
{ "0013E7", "Halcro" },
{ "0013DB", "SHOEI Electric Co.,Ltd" },
{ "0013CC", "Tall Maple Systems" },
{ "0013C7", "IONOS Co.,Ltd." },
{ "0013C0", "Trix Tecnologia Ltda." },
{ "0012CB", "CSS Inc." },
{ "0012C5", "V-Show  Technology (China) Co.,Ltd" },
{ "0012CC", "Bitatek CO., LTD" },
{ "0012B4", "Work Microwave GmbH" },
{ "0012BB", "Telecommunications Industry Association TR-41 Committee" },
{ "0012AF", "ELPRO Technologies" },
{ "001324", "Schneider Electric Ultra Terminal" },
{ "001314", "Asiamajor Inc." },
{ "001319", "Cisco Systems, Inc" },
{ "00131A", "Cisco Systems, Inc" },
{ "00130D", "GALILEO AVIONICA" },
{ "001308", "Nuvera Fuel Cells" },
{ "001181", "InterEnergy Co.Ltd," },
{ "00117B", "Büchi  Labortechnik AG" },
{ "00116F", "Netforyou Co., LTD." },
{ "001168", "HomeLogic LLC" },
{ "00115E", "ProMinent Dosiertechnik GmbH" },
{ "001157", "Oki Electric Industry Co., Ltd." },
{ "001158", "Nortel Networks" },
{ "001152", "Eidsvoll Electronics AS" },
{ "0011A4", "JStream Technologies Inc." },
{ "001198", "Prism Media Products Limited" },
{ "00119D", "Diginfo Technology Corporation" },
{ "00119E", "Solectron Brazil" },
{ "00118E", "Halytech Mace" },
{ "001193", "Cisco Systems, Inc" },
{ "001187", "Category Solutions, Inc" },
{ "001182", "IMI Norgren Ltd" },
{ "0011FF", "Digitro Tecnologia Ltda" },
{ "0011FA", "Rane Corporation" },
{ "0011F9", "Nortel Networks" },
{ "0011F0", "Wideful Limited" },
{ "0011EF", "Conitec Datensysteme GmbH" },
{ "0011E9", "STARNEX CO., LTD." },
{ "0011DD", "FROMUS TEC. Co., Ltd." },
{ "0011E2", "Hua Jung Components Co., Ltd." },
{ "000FFA", "Optinel Systems, Inc." },
{ "000FFF", "Control4" },
{ "000FF1", "nex-G Systems Pte.Ltd" },
{ "000FE4", "Pantech Co.,Ltd" },
{ "000FEA", "Giga-Byte Technology Co.,LTD." },
{ "000FE3", "Damm Cellular Systems A/S" },
{ "000FD7", "Harman Music Group" },
{ "001235", "Andrew Corporation" },
{ "00122B", "Virbiage Pty Ltd" },
{ "001212", "PLUS  Corporation" },
{ "001219", "Ahead Communication Systems Inc" },
{ "001206", "iQuest (NZ) Ltd" },
{ "00120B", "Chinasys Technologies Limited" },
{ "00120C", "CE-Infosys Pte Ltd" },
{ "001130", "Allied Telesis (Hong Kong) Ltd." },
{ "00111E", "EPSG (Ethernet Powerlink Standardization Group)" },
{ "00111F", "Doremi Labs, Inc." },
{ "001112", "Honeywell CMSS" },
{ "001118", "BLX IC Design Corp., Ltd." },
{ "001105", "Sunplus Technology Co., Ltd." },
{ "00110C", "Atmark Techno, Inc." },
{ "000FF9", "Valcretec, Inc." },
{ "0011CF", "Thrane & Thrane A/S" },
{ "0011D6", "HandEra, Inc." },
{ "0011D0", "Tandberg Data ASA" },
{ "0011CA", "Long Range Systems, Inc." },
{ "0011C3", "Transceiving System Technology Corporation" },
{ "0011B7", "Octalix B.V." },
{ "0011BE", "AGP Telecom Co. Ltd" },
{ "0011BD", "Bombardier Transportation" },
{ "0011AB", "TRUSTABLE TECHNOLOGY CO.,LTD." },
{ "0011B0", "Fortelink Inc." },
{ "00125F", "AWIND Inc." },
{ "001255", "NetEffect Incorporated" },
{ "00124E", "XAC AUTOMATION CORP." },
{ "001247", "Samsung Electronics Co., Ltd." },
{ "001248", "EMC Corporation (Kashya)" },
{ "001242", "Millennial Net" },
{ "001236", "ConSentry Networks" },
{ "00123B", "KeRo Systems ApS" },
{ "00122F", "Sanei Electric Inc." },
{ "00114F", "US Digital Television, Inc" },
{ "001149", "Proliphix Inc." },
{ "001142", "e-SMARTCOM  INC." },
{ "00113D", "KN SOLTEC CO.,LTD." },
{ "00113C", "Micronas GmbH" },
{ "001136", "Goodrich Sensor Systems" },
{ "00112C", "IZT GmbH" },
{ "000F77", "DENTUM CO.,LTD" },
{ "000F71", "Sanmei Electronics Co.,Ltd" },
{ "000F78", "Datacap Systems Inc" },
{ "000F6A", "Nortel Networks" },
{ "000F65", "icube Corp." },
{ "000F5E", "Veo" },
{ "000F58", "Adder Technology Limited" },
{ "000F52", "YORK Refrigeration, Marine & Controls" },
{ "000F57", "CABLELOGIC Co., Ltd." },
{ "000F45", "Stretch, Inc." },
{ "000F46", "SINAR AG" },
{ "000F4B", "Oracle Corporation" },
{ "000F37", "Xambala Incorporated" },
{ "000F3F", "Big Bear Networks" },
{ "000F3B", "Fuji System Machines Co., Ltd." },
{ "000F31", "Allied Vision Technologies Canada Inc" },
{ "000F32", "Lootom Telcovideo Network Wuxi Co Ltd" },
{ "000F2B", "GREENBELL SYSTEMS" },
{ "000E93", "Milénio 3 Sistemas Electrónicos, Lda." },
{ "000E8C", "Siemens AG A&D ET" },
{ "000E86", "Alcatel North America" },
{ "000E80", "Thomson Technology Inc" },
{ "000E85", "Catalyst Enterprises, Inc." },
{ "000E74", "Solar Telecom. Tech" },
{ "000E79", "Ample Communications Inc." },
{ "000E71", "Gemstar Technology Development Ltd." },
{ "000E6C", "Device Drivers Limited" },
{ "000EB8", "Iiga co.,Ltd" },
{ "000EB7", "Knovative, Inc." },
{ "000EBE", "B&B Electronics Manufacturing Co." },
{ "000EB2", "Micro-Research Finland Oy" },
{ "000EAB", "Cray Inc" },
{ "000EA5", "BLIP Systems" },
{ "000E9F", "TEMIC SDS GmbH" },
{ "000E98", "HME Clear-Com LTD." },
{ "000F24", "Cisco Systems, Inc" },
{ "000F12", "Panasonic Europe Ltd." },
{ "000F18", "Industrial Control Systems" },
{ "000F11", "Prodrive B.V." },
{ "000F0C", "SYNCHRONIC ENGINEERING" },
{ "000EFF", "Megasolution,Inc." },
{ "000F00", "Legra Systems, Inc." },
{ "000F05", "3B SYSTEM INC." },
{ "000EF9", "REA Elektronik GmbH" },
{ "000FAC", "IEEE 802.11" },
{ "000F9C", "Panduit Corp" },
{ "000FA0", "CANON KOREA BUSINESS SOLUTIONS INC." },
{ "000F97", "Avanex Corporation" },
{ "000F8A", "WideView" },
{ "000F89", "Winnertec System Co., Ltd." },
{ "000F90", "Cisco Systems, Inc" },
{ "000F7D", "Xirrus" },
{ "000F84", "Astute Networks, Inc." },
{ "000FD1", "Applied Wireless Identifications Group, Inc." },
{ "000FD2", "EWA Technologies, Inc." },
{ "000FC4", "NST co.,LTD." },
{ "000FCB", "3Com Ltd" },
{ "000FBF", "DGT Sp. z o.o." },
{ "000FB8", "CallURL Inc." },
{ "000FB2", "Broadband Pacenet (India) Pvt. Ltd." },
{ "000FA5", "BWA Technology GmbH" },
{ "000FB1", "Cognio Inc." },
{ "000E65", "TransCore" },
{ "000E5F", "activ-net GmbH & Co. KG" },
{ "000E60", "360SUN Digital Broadband Corporation" },
{ "000E52", "Optium Corporation" },
{ "000E46", "Niigata Seimitsu Co.,Ltd." },
{ "000E4D", "Numesa Inc." },
{ "000E40", "Nortel Networks" },
{ "000E3F", "Soronti, Inc." },
{ "000EF2", "Infinico Corporation" },
{ "000EE0", "Mcharge" },
{ "000EDF", "PLX Technology" },
{ "000EE6", "Adimos Systems LTD" },
{ "000ECA", "WTSS Inc" },
{ "000ED1", "Osaka Micro Computer." },
{ "000EDA", "C-TECH UNITED CORP." },
{ "000ED6", "Cisco Systems, Inc" },
{ "000EC5", "Digital Multitools Inc" },
{ "000DB2", "Ammasso, Inc." },
{ "000DAD", "Dataprobe, Inc." },
{ "000D9E", "TOKUDEN OHIZUMI SEISAKUSYO Co.,Ltd." },
{ "000DA5", "Fabric7 Systems, Inc" },
{ "000D99", "Orbital Sciences Corp.; Launch Systems Group" },
{ "000D8C", "Shanghai Wedone Digital Ltd. CO." },
{ "000D8B", "T&D Corporation" },
{ "000D85", "Tapwave, Inc." },
{ "000D86", "Huber + Suhner AG" },
{ "000DD8", "BBN" },
{ "000DCC", "NEOSMART Corp." },
{ "000DBF", "TekTone Sound & Signal Mfg., Inc." },
{ "000DC0", "Spagat AS" },
{ "000DC5", "EchoStar Global B.V. " },
{ "000DB9", "PC Engines GmbH" },
{ "000D4C", "Outline Electronics Ltd." },
{ "000D53", "Beijing 5w Communication Corp." },
{ "000D3F", "VTI Instruments Corporation" },
{ "000D44", "Audio BU - Logitech" },
{ "000D38", "NISSIN INC." },
{ "000D32", "DispenseSource, Inc." },
{ "000D31", "Compellent Technologies, Inc." },
{ "000E04", "CMA/Microdialysis AB" },
{ "000DF7", "Space Dynamics Lab" },
{ "000DFE", "Hauppauge Computer Works, Inc." },
{ "000DF1", "IONIX INC." },
{ "000DEB", "CompXs Limited" },
{ "000DF2", "Private" },
{ "000DE4", "DIGINICS, Inc." },
{ "000DDF", "Japan Image & Network Inc." },
{ "000DD2", "Simrad Optronics ASA" },
{ "000DD1", "Stryker Corporation" },
{ "000D2C", "Patapsco Designs Ltd" },
{ "000D25", "SANDEN CORPORATION" },
{ "000D1F", "AV Digital" },
{ "000D19", "ROBE Show lighting" },
{ "000D20", "ASAHIKASEI TECHNOSYSTEM CO.,LTD." },
{ "000D0D", "ITSupported, LLC" },
{ "000D12", "AXELL Corporation" },
{ "000D00", "Seaway Networks Inc." },
{ "000D06", "Compulogic Limited" },
{ "000CD1", "SFOM Technology Corp." },
{ "000CD6", "PARTNER TECH" },
{ "000CDD", "AOS technologies AG" },
{ "000CCA", "HGST a Western Digital Company" },
{ "000CC4", "Tiptel AG" },
{ "000CB1", "Salland Engineering (Europe) BV" },
{ "000E37", "Harms & Wende GmbH & Co.KG" },
{ "000E38", "Cisco Systems, Inc" },
{ "000E31", "Olympus Soft Imaging Solutions GmbH" },
{ "000E2A", "Private" },
{ "000E1E", "QLogic Corporation" },
{ "000E25", "Hannae Technology Co., Ltd" },
{ "000E18", "MyA Technology" },
{ "000E17", "Private" },
{ "000E0E", "ESA elettronica S.P.A." },
{ "000E0A", "SAKUMA DESIGN OFFICE" },
{ "000E12", "Adaptive Micro Systems Inc." },
{ "000D7E", "Axiowave Networks, Inc." },
{ "000D78", "Engineering & Security" },
{ "000D77", "FalconStor Software" },
{ "000D6B", "Mita-Teknik A/S" },
{ "000D65", "Cisco Systems, Inc" },
{ "000D5F", "Minds Inc" },
{ "000D66", "Cisco Systems, Inc" },
{ "000D58", "Private" },
{ "000CFA", "Digital Systems Corp" },
{ "000CFF", "MRO-TEK LIMITED" },
{ "000CED", "Real Digital Media" },
{ "000CEE", "jp-embedded" },
{ "000CF3", "CALL IMAGE SA" },
{ "000CE7", "MediaTek Inc." },
{ "000CE3", "Option International N.V." },
{ "000B8F", "AKITA ELECTRONICS SYSTEMS CO.,LTD." },
{ "000B89", "Top Global Technology, Ltd." },
{ "000B8E", "Ascent Corporation" },
{ "000B90", "ADVA Optical Networking Ltd." },
{ "000B7D", "SOLOMON EXTREME INTERNATIONAL LTD." },
{ "000B82", "Grandstream Networks, Inc." },
{ "000B6F", "Media Streaming Networks Inc" },
{ "000B76", "ET&T Technology Co. Ltd." },
{ "000B5E", "Audio Engineering Society Inc." },
{ "000B63", "Kaleidescape" },
{ "000C7E", "Tellium Incorporated" },
{ "000C86", "Cisco Systems, Inc" },
{ "000C81", "Schneider Electric (Australia) " },
{ "000C72", "Tempearl Industrial Co., Ltd." },
{ "000C79", "Extel Communications P/L" },
{ "000C66", "Pronto Networks Inc" },
{ "000C6B", "Kurz Industrie-Elektronik GmbH" },
{ "000C6D", "Edwards Ltd." },
{ "000C4E", "Winbest Technology CO,LT" },
{ "000C53", "Private" },
{ "000C5A", "IBSmm Embedded Electronics Consulting" },
{ "000C5F", "Avtec, Inc." },
{ "000C47", "SK Teletech(R&D Planning Team)" },
{ "000C4C", "Arcor AG&Co." },
{ "000C3E", "Crest Audio" },
{ "000C37", "Geomation, Inc." },
{ "000C2D", "FullWave Technology Co., Ltd." },
{ "000C1A", "Quest Technical Solutions Inc." },
{ "000B2E", "Cal-Comp Electronics (Thailand) Public Company Limited Taipe" },
{ "000B1B", "Systronix, Inc." },
{ "000B20", "Hirata corporation" },
{ "000B22", "Environmental Systems and Services" },
{ "000B14", "ViewSonic Corporation" },
{ "000B0D", "Air2U, Inc." },
{ "000B0F", "Bosch Rexroth" },
{ "000B08", "Pillar Data Systems" },
{ "000AFC", "Core Tec Communications, LLC" },
{ "000B01", "DAIICHI ELECTRONICS CO., LTD." },
{ "000B55", "ADInstruments" },
{ "000B5A", "HyperEdge" },
{ "000B52", "JOYMAX ELECTRONICS CO. LTD." },
{ "000B4D", "Emuzed" },
{ "000B41", "Ing. Büro Dr. Beutlhauser" },
{ "000B46", "Cisco Systems, Inc" },
{ "000B33", "Vivato Technologies" },
{ "000B3A", "QuStream Corporation" },
{ "000B3F", "Anthology Solutions Inc." },
{ "000B27", "Scion Corporation" },
{ "000C1E", "Global Cache" },
{ "000C23", "Beijing Lanchuan Tech. Co., Ltd." },
{ "000C0E", "XtremeSpectrum, Inc." },
{ "000C15", "CyberPower Systems, Inc." },
{ "000C09", "Hitachi IE Systems Co., Ltd" },
{ "000BF6", "Nitgen Co., Ltd" },
{ "000BFB", "D-NET International Corporation" },
{ "000C02", "ABB Oy" },
{ "000BC7", "ICET S.p.A." },
{ "000BCE", "Free2move AB" },
{ "000BC2", "Corinex Communication Corp." },
{ "000BBB", "Etin Systems Co., Ltd" },
{ "000BC0", "China IWNComm Co., Ltd." },
{ "000BAF", "WOOJU COMMUNICATIONS Co,.Ltd" },
{ "000BB4", "RDC Semiconductor Inc.," },
{ "000BA5", "Quasar Cipta Mandiri, PT" },
{ "000BAA", "Aiphone co.,Ltd" },
{ "000B9E", "Yasing Technology Corp." },
{ "000B95", "eBet Gaming Systems Pty Ltd" },
{ "000CB7", "Nanjing Huazhuo Electronics Co., Ltd." },
{ "000CBE", "Innominate Security Technologies AG" },
{ "000CC3", "BeWAN systems" },
{ "000CB2", "UNION co., ltd." },
{ "000CA5", "Naman NZ LTd" },
{ "000CAC", "Citizen Watch Co., Ltd." },
{ "000C94", "United Electronic Industries, Inc. (EUI)" },
{ "000C99", "HITEL LINK Co.,Ltd" },
{ "000CA0", "StorCase Technology, Inc." },
{ "000C8D", "MATRIX VISION GmbH" },
{ "000C92", "WolfVision Gmbh" },
{ "000BEA", "Zultys Technologies" },
{ "000BEF", "Code Corporation" },
{ "000BE3", "Key Stream Co., Ltd." },
{ "000BE8", "AOIP" },
{ "000BE9", "Actel Corporation" },
{ "000BD7", "DORMA Time + Access GmbH" },
{ "000BDC", "AKCP" },
{ "000BD3", "cd3o" },
{ "000AF0", "SHIN-OH ELECTRONICS CO., LTD. R&D" },
{ "000AF5", "Airgo Networks, Inc." },
{ "000AEC", "Koatsu Gas Kogyo Co., Ltd." },
{ "000AE5", "ScottCare Corporation" },
{ "000AE7", "ELIOP S.A." },
{ "000AE0", "Fujitsu Softek" },
{ "000AC8", "ZPSYS CO.,LTD. (Planning&Management)" },
{ "000ACD", "Sunrich Technology Limited" },
{ "000AD4", "CoreBell Systems Inc." },
{ "000AC1", "Futuretel" },
{ "000AC6", "Overture Networks." },
{ "000994", "Cronyx Engineering" },
{ "000999", "CP GEORGES RENAULT" },
{ "000987", "NISHI NIPPON ELECTRIC WIRE & CABLE CO.,LTD." },
{ "000988", "Nudian Electron Co., Ltd." },
{ "00098D", "Velocity Semiconductor" },
{ "000981", "Newport Networks" },
{ "000975", "fSONA Communications Corporation" },
{ "00097A", "Louis Design Labs." },
{ "000968", "TECHNOVENTURE, INC." },
{ "000962", "Sonitor Technologies AS" },
{ "000967", "Tachyon, Inc" },
{ "00096E", "GIANT ELECTRONICS LTD." },
{ "0009C3", "NETAS" },
{ "0009B9", "Action Imaging Solutions" },
{ "0009BA", "MAKU Informationstechik GmbH" },
{ "0009AC", "LANVOICE" },
{ "0009B3", "MCM Systems Ltd" },
{ "0009A7", "Bang & Olufsen A/S" },
{ "00099A", "ELMO COMPANY, LIMITED" },
{ "0009A0", "Microtechno Corporation" },
{ "000A80", "Telkonet Inc." },
{ "000A82", "TATSUTA SYSTEM ELECTRONICS CO.,LTD." },
{ "000A87", "Integrated Micromachines Inc." },
{ "000A7B", "Cornelius Consult" },
{ "000A6D", "EKS Elektronikservice GmbH" },
{ "000A6F", "ZyFLEX Technologies Inc" },
{ "000A74", "Manticom Networks Inc." },
{ "000A61", "Cellinx Systems Inc." },
{ "000A68", "SolarFlare Communications, Inc." },
{ "000A5C", "Carel s.p.a." },
{ "0009E6", "Cyber Switching Inc." },
{ "0009E0", "XEMICS S.A." },
{ "0009DA", "Control Module Inc." },
{ "0009DF", "Vestel Komunikasyon Sanayi ve Ticaret A.S." },
{ "0009CD", "HUDSON SOFT CO.,LTD." },
{ "0009C7", "Movistec" },
{ "0009CE", "SpaceBridge Semiconductor Corp." },
{ "0009D3", "Western DataCom Co., Inc." },
{ "000AAE", "Rosemount Process Analytical" },
{ "000AB3", "Fa. GIRA" },
{ "000AB5", "Digital Electronic Network" },
{ "000ABA", "Arcon Technology Limited" },
{ "000AA2", "SYSTEK INC." },
{ "000AA7", "FEI Electron Optics" },
{ "000A8F", "Aska International Inc." },
{ "000A94", "ShangHai cellink CO., LTD" },
{ "000A9B", "TB Group Inc" },
{ "000A9A", "Aiptek International Inc" },
{ "000A50", "REMOTEK CORPORATION" },
{ "000A55", "MARKEM Corporation" },
{ "000A4E", "UNITEK Electronics INC." },
{ "000A42", "Cisco Systems, Inc" },
{ "000A49", "F5 Networks, Inc." },
{ "000A36", "Synelec Telecom Multimedia" },
{ "000A3B", "GCT Semiconductor, Inc" },
{ "000A3D", "Elo Sistemas Eletronicos S.A." },
{ "000A2F", "Artnix Inc." },
{ "000A20", "SVA Networks, Inc." },
{ "000A25", "CERAGON NETWORKS" },
{ "000A14", "TECO a.s." },
{ "000A19", "Valere Power, Inc." },
{ "000A0D", "FCI Deutschland GmbH" },
{ "000A12", "Azylex Technology, Inc" },
{ "0009F9", "ART JAPAN CO., LTD." },
{ "0009FC", "IPFLEX Inc." },
{ "000A03", "ENDESA SERVICIOS, S.L." },
{ "0009ED", "CipherOptics" },
{ "0009F2", "Cohu, Inc., Electronics Division" },
{ "00095E", "Masstech Group Inc." },
{ "000959", "Sitecsoft" },
{ "00094D", "Braintree Communications Pty Ltd" },
{ "000952", "Auerswald GmbH & Co. KG" },
{ "000946", "Cluster Labs GmbH" },
{ "000940", "AGFEO GmbH & Co. KG" },
{ "00093F", "Double-Win Enterpirse CO., LTD" },
{ "00093A", "Molex Fiber Optics" },
{ "000933", "Ophit Co.Ltd." },
{ "00072C", "Fabricom" },
{ "000733", "DANCONTROL Engineering" },
{ "000732", "AAEON Technology Inc." },
{ "000716", "J & S Marine Ltd." },
{ "00071B", "CDVI Americas Ltd" },
{ "000722", "The Nielsen Company" },
{ "00071C", "AT&T Fixed Wireless Services" },
{ "00070A", "Unicom Automation Co., Ltd." },
{ "00070F", "Fujant, Inc." },
{ "000709", "Westerstrand Urfabrik AB" },
{ "000702", "Varian Medical Systems" },
{ "0006F3", "AcceLight Networks" },
{ "0006F4", "Prime Electronics & Satellitics Inc." },
{ "000705", "Endress & Hauser GmbH & Co" },
{ "0006F8", "The Boeing Company" },
{ "0006FF", "Sheba Systems Co., Ltd." },
{ "0006FD", "Comjet Information Systems Corp." },
{ "00082D", "Indus Teqsite Private Limited" },
{ "000821", "Cisco Systems, Inc" },
{ "000814", "TIL Technologies" },
{ "00081A", "Sanrad Intelligence Storage Communications (2000) Ltd." },
{ "00080F", "Proximion Fiber Optics AB" },
{ "000809", "Systemonic AG" },
{ "000803", "Cos Tron" },
{ "0007FF", "Gluon Networks" },
{ "0007F9", "Sensaphone" },
{ "0007F3", "Thinkengine Networks" },
{ "0007EC", "Cisco Systems, Inc" },
{ "0007F2", "IOA Corporation" },
{ "0007B2", "Transaccess S.A." },
{ "0007A4", "GN Netcom Ltd." },
{ "0007AA", "Quantum Data Inc." },
{ "00079D", "Musashi Co., Ltd." },
{ "00079E", "Ilinx Co., Ltd." },
{ "000774", "GuangZhou Thinker Technology Co. Ltd." },
{ "000791", "International Data Communications, Inc." },
{ "000798", "Selea SRL" },
{ "000797", "Netpower Co., Ltd." },
{ "00078B", "Wegener Communications, Inc." },
{ "000785", "Cisco Systems, Inc" },
{ "00077B", "Millimetrix Broadband Networks" },
{ "00077E", "Elrest GmbH" },
{ "00076F", "Synoptics Limited" },
{ "000888", "OULLIM Information Technology Inc,." },
{ "000882", "SIGMA CORPORATION" },
{ "00087C", "Cisco Systems, Inc" },
{ "000875", "Acorp Electronics Corp." },
{ "000870", "Rasvia Systems, Inc." },
{ "00086F", "Resources Computer Network Ltd." },
{ "000869", "Command-e Technology Co.,Ltd." },
{ "000863", "Entrisphere Inc." },
{ "00085D", "Aastra" },
{ "000862", "NEC Eluminant Technologies, Inc." },
{ "000850", "Arizona Instrument Corp." },
{ "000856", "Gamatronic Electronic Industries Ltd." },
{ "000927", "TOYOKEIKI CO.,LTD." },
{ "00092E", "B&Tech System Inc." },
{ "000920", "EpoX COMPUTER CO.,LTD." },
{ "00091B", "Digital Generation Inc." },
{ "000914", "COMPUTROLS INC." },
{ "00090E", "Helix Technology Inc." },
{ "000908", "VTech Technology Corp." },
{ "00090D", "LEADER ELECTRONICS CORP." },
{ "000901", "Shenzhen Shixuntong Information & Technoligy Co" },
{ "0007E6", "edgeflow Canada Inc." },
{ "0007E0", "Palm Inc." },
{ "0007D9", "Splicecom" },
{ "0007DA", "Neuro Telecom Co., Ltd." },
{ "0007D3", "SPGPrints B.V." },
{ "0007CA", "Creatix Polymedia Ges Fur Kommunikaitonssysteme" },
{ "0007C4", "JEAN Co. Ltd." },
{ "0007BE", "DataLogic SpA" },
{ "0007B1", "Equator Technologies" },
{ "0007B8", "Corvalent Corporation" },
{ "00076E", "Sinetica Corporation Limited" },
{ "00076A", "NEXTEYE Co., Ltd." },
{ "00075E", "Ametek Power Instruments" },
{ "000765", "Jade Quantum Technologies, Inc." },
{ "000764", "YoungWoo Telecom Co. Ltd." },
{ "000757", "Topcall International AG" },
{ "000758", "Dragonwave" },
{ "000752", "Rhythm Watch Co., Ltd." },
{ "00074B", "Daihen Corporation" },
{ "000745", "Radlan Computer Communications Ltd." },
{ "000738", "Young Technology Co., Ltd." },
{ "00073F", "Woojyun Systec Co., Ltd." },
{ "0008BB", "NetExcell" },
{ "0008B5", "TAI GUEN ENTERPRISE CO., LTD" },
{ "0008B6", "RouteFree, Inc." },
{ "0008AF", "Novatec Corporation" },
{ "0008A9", "SangSang Technology, Inc." },
{ "0008A8", "Systec Co., Ltd." },
{ "0008A3", "Cisco Systems, Inc" },
{ "00089C", "Elecs Industry Co., Ltd." },
{ "000894", "InnoVISION Multimedia Ltd." },
{ "00088F", "ADVANCED DIGITAL TECHNOLOGY" },
{ "0008FC", "Gigaphoton Inc." },
{ "0008F9", "Artesyn Embedded Technologies" },
{ "0008F4", "Bluetake Technology Co., Ltd." },
{ "0008EB", "ROMWin Co.,Ltd." },
{ "0008E4", "Envenergy Inc" },
{ "0008DF", "Alistel Inc." },
{ "0008D8", "Dowkey Microwave" },
{ "0008D2", "ZOOM Networks Inc." },
{ "0008CC", "Remotec, Inc." },
{ "0008D1", "KAREL INC." },
{ "0008C2", "Cisco Systems, Inc" },
{ "00068F", "Telemonitor, Inc." },
{ "000689", "yLez Technologies Pte Ltd" },
{ "000683", "Bravara Communications, Inc." },
{ "00D0B9", "MICROTEK INTERNATIONAL, INC." },
{ "00067D", "Takasago Ltd." },
{ "000675", "Banderacom, Inc." },
{ "000679", "Konami Corporation" },
{ "000663", "Human Technology Co., Ltd." },
{ "00066F", "Korea Data Systems" },
{ "000662", "MBM Technology Ltd." },
{ "000669", "Datasound Laboratories Ltd" },
{ "00055A", "Power Dsine Ltd." },
{ "00065C", "Malachite Technologies, Inc." },
{ "000650", "Tiburon Networks, Inc." },
{ "000656", "Tactel AB" },
{ "00060A", "Blue2space" },
{ "000604", "@Track Communications, Inc." },
{ "00CBBD", "Cambridge Broadband Networks Ltd." },
{ "000603", "Baker Hughes Inc." },
{ "A06A00", "Verilink Corporation" },
{ "0005EE", "Siemens AB, Infrastructure & Cities, Building Technologies Division, IC BT SSP SP BA PR" },
{ "0005F5", "Geospace Technologies" },
{ "000601", "Otanikeiki Co., Ltd." },
{ "0005E8", "TurboWave, Inc." },
{ "0005F4", "System Base Co., Ltd." },
{ "0005FB", "ShareGate, Inc." },
{ "0005DB", "PSI Nentec GmbH" },
{ "0005DF", "Electronic Innovation, Inc." },
{ "0005CF", "Thunder River Technologies, Inc." },
{ "0005C9", "LG Innotek Co., Ltd." },
{ "0006E7", "Bit Blitz Communications Inc." },
{ "0006ED", "Inara Networks" },
{ "0006DC", "Syabas Technology (Amquest)" },
{ "0006E1", "Techno Trade s.a" },
{ "0006E6", "DongYang Telecom Co., Ltd." },
{ "0006CF", "Thales Avionics In-Flight Systems, LLC" },
{ "0006D6", "Cisco Systems, Inc" },
{ "0006D5", "Diamond Systems Corp." },
{ "0006C9", "Technical Marketing Research, Inc." },
{ "0006C3", "Schindler Elevator Ltd." },
{ "0006C8", "Sumitomo Metal Micro Devices, Inc." },
{ "0005D5", "Speedcom Wireless" },
{ "0005BC", "Resource Data Management Ltd" },
{ "0005C2", "Soronti, Inc." },
{ "0005B0", "Korea Computer Technology Co., Ltd." },
{ "00059C", "Kleinknecht GmbH, Ing. Büro" },
{ "0005B6", "INSYS Microelectronics GmbH" },
{ "0005A2", "CELOX Networks" },
{ "0005AC", "Northern Digital, Inc." },
{ "000589", "National Datacomputer" },
{ "000595", "Alesis Corporation" },
{ "00058F", "CLCsoft co." },
{ "000596", "Genotech Co., Ltd." },
{ "000506", "Reddo Networks AB" },
{ "0004FC", "Stratus Computer (DE), Inc." },
{ "0004F6", "Amphus" },
{ "0004F5", "SnowShore Networks, Inc." },
{ "0004E9", "Infiniswitch Corporation" },
{ "0004F0", "International Computers, Ltd" },
{ "0004EF", "Polestar Corp." },
{ "0004DF", "Teracom Telematica Ltda." },
{ "0004E5", "Glonet Systems, Inc." },
{ "0004D9", "Titan Electronics, Inc." },
{ "00062D", "TouchStar Technologies, L.L.C." },
{ "000649", "3M Deutschland GmbH" },
{ "000643", "SONO Computer Co., Ltd." },
{ "00064A", "Honeywell Co., Ltd. (KOREA)" },
{ "00063F", "Everex Communications Inc." },
{ "000639", "Newtec" },
{ "000633", "Cross Match Technologies GmbH" },
{ "000626", "MWE GmbH" },
{ "00061D", "MIP Telecom, Inc." },
{ "000623", "MGE UPS Systems France" },
{ "000610", "Abeona Networks Inc" },
{ "000616", "Tel Net Co., Ltd." },
{ "00054D", "Brans Technologies, Inc." },
{ "000542", "Otari, Inc." },
{ "00053C", "XIRCOM" },
{ "00052F", "Leviton Network Solutions" },
{ "00053B", "Harbour Networks Ltd., Co. Beijing" },
{ "000535", "Chip PC Ltd." },
{ "000529", "Shanghai Broadan Communication Technology Co., Ltd" },
{ "000523", "AVL List GmbH" },
{ "000522", "LEA*D Corporation, Inc." },
{ "00051C", "Xnet Technology Corp." },
{ "000516", "SMART Modular Technologies" },
{ "00050C", "Network Photonics, Inc." },
{ "000512", "Zebra Technologies Inc" },
{ "0006BF", "Accella Technologies Co., Ltd." },
{ "0006B9", "A5TEK Corp." },
{ "0006B2", "Linxtek Co." },
{ "0006AC", "Intersoft Co." },
{ "0006A6", "Artistic Licence Engineering Ltd" },
{ "0006A2", "Microtune, Inc." },
{ "000695", "Ensure Technologies, Inc." },
{ "00069C", "Transmode Systems AB" },
{ "000696", "Advent Networks" },
{ "000690", "Euracom Communication GmbH" },
{ "00057D", "Sun Communications, Inc." },
{ "00057C", "RCO Security AB" },
{ "000583", "ImageCom Limited" },
{ "000573", "Cisco Systems, Inc" },
{ "000572", "Deonet Co., Ltd." },
{ "00056C", "Hung Chang Co., Ltd." },
{ "000566", "Secui.com Corporation" },
{ "000560", "LEADER COMM.CO., LTD" },
{ "000559", "Intracom S.A." },
{ "000553", "DVC Company, Inc." },
{ "000548", "Disco Corporation" },
{ "0003D2", "Crossbeam Systems, Inc." },
{ "0003CD", "Clovertech, Inc." },
{ "0003CA", "MTS Systems Corp." },
{ "0003C6", "ICUE Systems, Inc." },
{ "0003BF", "Centerpoint Broadband Technologies, Inc." },
{ "0003BA", "Oracle Corporation" },
{ "0003AF", "Paragea Communications" },
{ "0003B4", "Macrotek International Corp." },
{ "0003AC", "Fronius Schweissmaschinen" },
{ "0003A8", "IDOT Computers, Inc." },
{ "0003A1", "HIPER Information & Communication, Inc." },
{ "00044E", "Cisco Systems, Inc" },
{ "00044F", "Schubert System Elektronik Gmbh" },
{ "000454", "Quadriga UK" },
{ "000445", "LMS Skalar Instruments GmbH" },
{ "00044A", "iPolicy Networks, Inc." },
{ "000444", "Western Multiplex Corporation" },
{ "00043E", "Telencomm" },
{ "000438", "Nortel Networks" },
{ "000432", "Voyetra Turtle Beach, Inc." },
{ "000437", "Powin Information Technology, Inc." },
{ "00042B", "IT Access Co., Ltd." },
{ "000425", "Atmel Corporation" },
{ "000419", "Fibercycle Networks, Inc." },
{ "00041A", "Ines Test and Measurement GmbH & CoKG" },
{ "000399", "Dongju Informations & Communications Co., Ltd." },
{ "00039C", "OptiMight Communications, Inc." },
{ "000390", "Digital Video Communications, Inc." },
{ "000395", "California Amplifier" },
{ "000380", "SSH Communications Security Corp." },
{ "000374", "Control Microsystems" },
{ "0002F0", "AME Optimedia Technology Co., Ltd." },
{ "000379", "Proscend Communications, Inc." },
{ "000371", "Acomz Networks Corp." },
{ "00036D", "Runtop, Inc." },
{ "000361", "Widcomm, Inc." },
{ "0002DE", "Astrodesign, Inc." },
{ "0002DB", "NETSEC" },
{ "0002D7", "EMPEG Ltd" },
{ "0002D2", "Workstation AG" },
{ "000223", "ClickTV" },
{ "0002CB", "TriState Ltd." },
{ "0002C4", "Vector International BVBA" },
{ "0002BF", "dotRocket, Inc." },
{ "0002BB", "Continuous Computing Corp" },
{ "0002BC", "LVL 7 Systems, Inc." },
{ "0002B6", "Acrosser Technology Co., Ltd." },
{ "0002AF", "TeleCruz Technology, Inc." },
{ "0002AA", "PLcom Co., Ltd." },
{ "0002A3", "ABB Switzerland Ltd, Power Systems" },
{ "00035A", "Photron Limited" },
{ "000355", "TeraBeam Internet Systems" },
{ "000353", "Mitac, Inc." },
{ "00034F", "Sur-Gard Security" },
{ "00034A", "RIAS Corporation" },
{ "000346", "Hitachi Kokusai Electric, Inc." },
{ "000344", "Tietech.Co., Ltd." },
{ "000343", "Martin Professional A/S" },
{ "000334", "Newport Electronics" },
{ "000337", "Vaone, Inc." },
{ "00033C", "Daiden Co., Ltd." },
{ "000329", "F3, Inc." },
{ "000330", "Imagenics, Co., Ltd." },
{ "000321", "Reco Research Co., Ltd." },
{ "000324", "SANYO Consumer Electronics Co., Ltd." },
{ "00031B", "Cellvision Systems, Inc." },
{ "0001A8", "Welltech Computer Co., Ltd." },
{ "00030F", "Digital China (Shanghai) Networks Ltd." },
{ "000314", "Teleware Network Systems" },
{ "00030C", "Telesoft Technologies Ltd." },
{ "000308", "AM Communications, Inc." },
{ "0002FC", "Cisco Systems, Inc" },
{ "000301", "EXFO" },
{ "0002F9", "MIMOS Berhad" },
{ "0002F5", "VIVE Synergies, Inc." },
{ "0002EA", "Focus Enhancements" },
{ "0002E3", "LITE-ON Communications, Inc." },
{ "0004D3", "Toyokeiki Co., Ltd." },
{ "0004CC", "Peek Traffic B.V." },
{ "0004C0", "Cisco Systems, Inc" },
{ "0004B9", "S.I. Soubou, Inc." },
{ "0004BA", "KDD Media Will Corporation" },
{ "0004AF", "Digital Fountain, Inc." },
{ "0004B4", "CIAC" },
{ "0004B3", "Videotek, Inc." },
{ "0004A6", "SAF Tehnika Ltd." },
{ "0004A0", "Verity Instruments, Inc." },
{ "0004A5", "Barco Projection Systems NV" },
{ "000499", "Chino Corporation" },
{ "00048D", "Teo Technologies, Inc" },
{ "000493", "Tsinghua Unisplendour Co., Ltd." },
{ "000484", "Amann GmbH" },
{ "00048A", "Temia Vertriebs GmbH" },
{ "00047A", "AXXESSIT ASA" },
{ "000474", "LEGRAND" },
{ "00046E", "Cisco Systems, Inc" },
{ "000473", "Photonex Corporation" },
{ "000467", "Wuhan Research Institute of MII" },
{ "000461", "EPOX Computer Co., Ltd." },
{ "00045B", "Techsan Electronics Co., Ltd." },
{ "000414", "Umezawa Musen Denki Co., Ltd." },
{ "000407", "Topcon Positioning Systems, Inc." },
{ "0003F7", "Plast-Control GmbH" },
{ "0003FE", "Cisco Systems, Inc" },
{ "0003FD", "Cisco Systems, Inc" },
{ "000401", "Osaki Electric Co., Ltd." },
{ "0003F0", "Redfern Broadband Networks" },
{ "0003EB", "Atrica" },
{ "0003E5", "Hermstedt SG" },
{ "0003D9", "Secheron SA" },
{ "00022F", "P-Cube, Ltd." },
{ "000227", "ESD Electronic System Design GmbH" },
{ "00021F", "Aculab PLC" },
{ "00021B", "Kollmorgen-Servotronix" },
{ "00020C", "Metro-Optix" },
{ "000218", "Advanced Scientific Corp" },
{ "000213", "S.D.E.L." },
{ "00020F", "AATR" },
{ "0001F9", "TeraGlobal Communications Corp." },
{ "000200", "Net & Sys Co., Ltd." },
{ "00015E", "BEST TECHNOLOGY CO., LTD." },
{ "000162", "Cygnet Technologies, Inc." },
{ "000169", "Celestix Networks Pte Ltd." },
{ "000175", "Radiant Communications Corp." },
{ "000159", "S1 Corporation" },
{ "000165", "AirSwitch Corporation" },
{ "000171", "Allied Data Technologies" },
{ "000157", "SYSWAVE CO., LTD" },
{ "000153", "ARCHTEK TELECOM CORPORATION" },
{ "000144", "EMC Corporation" },
{ "00014B", "Ennovate Networks, Inc." },
{ "00012C", "Aravox Technologies, Inc." },
{ "000138", "XAVi Technologies Corp." },
{ "00010C", "System Talks Inc." },
{ "000113", "OLYMPUS CORPORATION" },
{ "000100", "EQUIP'TRANS" },
{ "00B0AC", "SIAE-Microelettronica S.p.A." },
{ "00B017", "InfoGear Technology Corp." },
{ "0030F0", "Uniform Industrial Corp." },
{ "00B0CE", "TECHNOLOGY RESCUE" },
{ "00B080", "Mannesmann Ipulsys B.V." },
{ "00B09A", "Morrow Technologies Corp." },
{ "00B091", "Transmeta Corp." },
{ "0030BE", "City-Net Technology, Inc." },
{ "00303E", "Radcom Ltd." },
{ "0030D7", "Innovative Systems, L.L.C." },
{ "0030FC", "Terawave Communications, Inc." },
{ "00300F", "IMT - Information Management T" },
{ "003004", "LEADTEK RESEARCH INC." },
{ "003018", "Jetway Information Co., Ltd." },
{ "003088", "Ericsson" },
{ "0030CA", "Discovery Com" },
{ "00304F", "PLANET Technology Corporation" },
{ "0001FC", "Keyence Corporation" },
{ "0001F3", "QPS, Inc." },
{ "0001E4", "Sitera, Inc." },
{ "0001EB", "C-COM Corporation" },
{ "0001F0", "Tridium, Inc." },
{ "0001D4", "Leisure Time, Inc." },
{ "0001D8", "Teltronics, Inc." },
{ "0001C6", "Quarry Technologies" },
{ "0001CC", "Japan Total Design Communication Co., Ltd." },
{ "0001D1", "CoNet Communications, Inc." },
{ "0001B3", "Precision Electronic Manufacturing" },
{ "0001B1", "General Bandwidth" },
{ "0001BB", "Frequentis" },
{ "00025E", "High Technology Ltd" },
{ "000261", "Tilgin AB" },
{ "000259", "Tsann Kuen China (Shanghai)Enterprise Co., Ltd. IT Group" },
{ "000255", "IBM Corp" },
{ "000249", "Aviv Infocom Co, Ltd." },
{ "000250", "Geyser Networks, Inc." },
{ "000242", "Videoframe Systems" },
{ "000244", "SURECOM Technology Co." },
{ "00022C", "ABB Bomem, Inc." },
{ "00023A", "ZSK Stickmaschinen GmbH" },
{ "000233", "Mantra Communications, Inc." },
{ "0001B7", "Centos, Inc." },
{ "0001AF", "Artesyn Embedded Technologies" },
{ "0001AB", "Main Street Networks" },
{ "000191", "SYRED Data Systems" },
{ "00019D", "E-Control Systems, Inc." },
{ "0001A4", "Microlink Corporation" },
{ "000199", "HeiSei Electronics" },
{ "0001A0", "Infinilink Corporation" },
{ "00017C", "AG-E GmbH" },
{ "000188", "LXCO Technologies ag" },
{ "000178", "MARGI Systems, Inc." },
{ "00018B", "NetLinks Co., Ltd." },
{ "0030F5", "Wild Lab. Ltd." },
{ "000184", "SIEB & MEYER AG" },
{ "000160", "ELMEX Co., LTD." },
{ "000298", "Broadframe Corporation" },
{ "000292", "Logic Innovations, Inc." },
{ "00028D", "Movita Technologies, Inc." },
{ "000283", "Spectrum Controls, Inc." },
{ "000277", "Cash Systemes Industrie" },
{ "00027C", "Trilithic, Inc." },
{ "000275", "SMART Technologies, Inc." },
{ "000270", "Crewave Co., Ltd." },
{ "000269", "Nadatel Co., Ltd" },
{ "000265", "Virditech Co. Ltd." },
{ "000134", "Selectron Systems AG" },
{ "00013B", "BNA SYSTEMS" },
{ "000147", "Zhone Technologies" },
{ "00012B", "TELENET Co., Ltd." },
{ "00011C", "Universal Talkware Corporation" },
{ "000123", "DIGITAL ELECTRONICS CORP." },
{ "00011F", "RC Networks, Inc." },
{ "000104", "DVICO Co., Ltd." },
{ "000110", "Gotham Networks" },
{ "00D05A", "SYMBIONICS, LTD." },
{ "00D01A", "URMET  TLC S.P.A." },
{ "00D0F3", "SOLARI DI UDINE SPA" },
{ "00D089", "DYNACOLOR, INC." },
{ "00D08D", "PHOENIX GROUP, INC." },
{ "00D09C", "KAPADIA COMMUNICATIONS" },
{ "00D0FE", "ASTRAL POINT" },
{ "00D0DC", "MODULAR MINING SYSTEMS, INC." },
{ "00D062", "DIGIGRAM" },
{ "00D0A7", "TOKYO SOKKI KENKYUJO CO., LTD." },
{ "00D032", "YANO ELECTRIC CO., LTD." },
{ "00D054", "SAS INSTITUTE INC." },
{ "00D0EB", "LIGHTERA NETWORKS, INC." },
{ "00D01E", "PINGTEL CORP." },
{ "00D0A9", "SHINANO KENSHI CO., LTD." },
{ "00D0F2", "MONTEREY NETWORKS" },
{ "0030DB", "Mindready Solutions, Inc." },
{ "00306A", "PENTA MEDIA CO., LTD." },
{ "003021", "HSING TECH. ENTERPRISE CO.,LTD" },
{ "0030EA", "TeraForce Technology Corporation" },
{ "0030F4", "STARDOT TECHNOLOGIES" },
{ "003087", "VEGA GRIESHABER KG" },
{ "003000", "ALLWELL TECHNOLOGY CORP." },
{ "003034", "SET ENGINEERING" },
{ "00308D", "Pinnacle Systems, Inc." },
{ "00304B", "ORBACOM SYSTEMS, INC." },
{ "0030FA", "TELICA, INC." },
{ "0030E9", "GMA COMMUNICATION MANUFACT'G" },
{ "003027", "KERBANGO, INC." },
{ "00D0B8", "Iomega Corporation" },
{ "005045", "RIOWORKS SOLUTIONS, INC." },
{ "00507C", "VIDEOCON AG" },
{ "005065", "TDK-Lambda Corporation" },
{ "0050C7", "Private" },
{ "0050F4", "SIGMATEK GMBH & CO. KG" },
{ "005076", "IBM Corp" },
{ "005075", "KESTREL SOLUTIONS" },
{ "005090", "DCTRI" },
{ "0050ED", "ANDA NETWORKS" },
{ "005096", "SALIX TECHNOLOGIES, INC." },
{ "00509B", "SWITCHCORE AB" },
{ "0050A9", "MOLDAT WIRELESS TECHNOLGIES" },
{ "00503C", "TSINGHUA NOVEL ELECTRONICS" },
{ "0050B6", "GOOD WAY IND. CO., LTD." },
{ "0050FF", "HAKKO ELECTRONICS CO., LTD." },
{ "005032", "PICAZO COMMUNICATIONS, INC." },
{ "0030F6", "SECURELOGIX CORPORATION" },
{ "0030B6", "Cisco Systems, Inc" },
{ "0030B2", "L-3 Sonoma EO" },
{ "0030D6", "MSC VERTRIEBS GMBH" },
{ "003008", "AVIO DIGITAL, INC." },
{ "00306D", "LUCENT TECHNOLOGIES" },
{ "0030E4", "CHIYODA SYSTEM RIKEN" },
{ "00301A", "SMARTBRIDGES PTE. LTD." },
{ "0030CD", "CONEXANT SYSTEMS, INC." },
{ "003001", "SMP" },
{ "0030E1", "Network Equipment Technologies, Inc." },
{ "0030D8", "SITEK" },
{ "003062", "IP Video Networks Inc" },
{ "003081", "ALTOS C&C" },
{ "00D066", "WINTRISS ENGINEERING CORP." },
{ "00D06F", "KMC CONTROLS" },
{ "00D04B", "LA CIE GROUP S.A." },
{ "00D060", "Panasonic Europe Ltd." },
{ "00D002", "DITECH CORPORATION" },
{ "00D0A6", "LANBIRD TECHNOLOGY CO., LTD." },
{ "00D0DE", "PHILIPS MULTIMEDIA NETWORK" },
{ "00D083", "INVERTEX, INC." },
{ "00D038", "FIVEMERE, LTD." },
{ "00D00C", "SNIJDER MICRO SYSTEMS" },
{ "00D086", "FOVEON, INC." },
{ "00D03F", "AMERICAN COMMUNICATION" },
{ "00D033", "DALIAN DAXIAN NETWORK" },
{ "00D0CE", "ASYST ELECTRONIC" },
{ "00D090", "Cisco Systems, Inc" },
{ "00D0B6", "CRESCENT NETWORKS, INC." },
{ "00D0D2", "EPILOG CORPORATION" },
{ "00D071", "ECHELON CORP." },
{ "00D07B", "COMCAM INTERNATIONAL INC" },
{ "00D05D", "INTELLIWORXX, INC." },
{ "00D00D", "MICROMERITICS INSTRUMENT" },
{ "00D04C", "EUROTEL TELECOM LTD." },
{ "00D0FD", "OPTIMA TELE.COM, INC." },
{ "0050A7", "Cisco Systems, Inc" },
{ "00D0EE", "DICTAPHONE CORPORATION" },
{ "00D0B0", "BITSWITCH LTD." },
{ "00D044", "ALIDIAN NETWORKS, INC." },
{ "00D004", "PENTACOM LTD." },
{ "00D045", "KVASER AB" },
{ "00D0D0", "ZHONGXING TELECOM LTD." },
{ "00D03E", "ROCKETCHIPS, INC." },
{ "003045", "Village Networks, Inc. (VNI)" },
{ "0030BB", "CacheFlow, Inc." },
{ "003053", "Basler AG" },
{ "003072", "Intellibyte Inc." },
{ "0030B1", "TrunkNet" },
{ "0030A7", "SCHWEITZER ENGINEERING" },
{ "003038", "XCP, INC." },
{ "2C6A6F", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "1CCAE3", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "549A11", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "B8D812", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "1C21D1", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "7419F8", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "B437D1", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "BC3400", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "00902C", "DATA & CONTROL EQUIPMENT LTD." },
{ "009049", "ENTRIDIA CORPORATION" },
{ "009043", "Tattile SRL " },
{ "009076", "FMT AIRCRAFT GATE SUPPORT SYSTEMS AB" },
{ "009017", "Zypcom, Inc" },
{ "00907B", "E-TECH, INC." },
{ "00909D", "NovaTech Process Solutions, LLC" },
{ "009038", "FOUNTAIN TECHNOLOGIES, INC." },
{ "00501F", "MRG SYSTEMS, LTD." },
{ "005092", "Rigaku Corporation Osaka Plant" },
{ "00501C", "JATOM SYSTEMS, INC." },
{ "00505C", "TUNDO CORPORATION" },
{ "005068", "ELECTRONIC INDUSTRIES ASSOCIATION" },
{ "00501A", "IQinVision" },
{ "005063", "OY COMSEL SYSTEM AB" },
{ "0050DE", "SIGNUM SYSTEMS CORP." },
{ "00507B", "MERLOT COMMUNICATIONS" },
{ "005078", "MEGATON HOUSE, LTD." },
{ "00508F", "ASITA TECHNOLOGIES INT'L LTD." },
{ "005057", "BROADBAND ACCESS SYSTEMS" },
{ "005087", "TERASAKI ELECTRIC CO., LTD." },
{ "005088", "AMANO CORPORATION" },
{ "0050A8", "OpenCon Systems, Inc." },
{ "005062", "KOUWELL ELECTRONICS CORP.  **" },
{ "0050B1", "GIDDINGS & LEWIS" },
{ "00500C", "e-Tek Labs, Inc." },
{ "005091", "NETACCESS, INC." },
{ "005097", "MMC-EMBEDDED COMPUTERTECHNIK GmbH" },
{ "0050AF", "INTERGON, INC." },
{ "0050EB", "ALPHA-TOP CORPORATION" },
{ "0050BC", "HAMMER STORAGE SOLUTIONS" },
{ "2CD141", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "80E4DA", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "00900F", "KAWASAKI HEAVY INDUSTRIES, LTD" },
{ "009036", "ens, inc." },
{ "0090E9", "JANZ COMPUTER AG" },
{ "009032", "PELCOMBE GROUP LTD." },
{ "0090B8", "ROHDE & SCHWARZ GMBH & CO. KG" },
{ "009058", "Ultra Electronics Ltd., Command and Control Systems" },
{ "0090BE", "IBC/INTEGRATED BUSINESS COMPUTERS" },
{ "009062", "ICP VORTEX COMPUTERSYSTEME GmbH" },
{ "0090C3", "TOPIC SEMICONDUCTOR CORP." },
{ "0090EC", "PYRESCOM" },
{ "00903B", "TriEMS Research Lab, Inc." },
{ "009074", "ARGON NETWORKS, INC." },
{ "0090C1", "Peco II, Inc." },
{ "0010D3", "GRIPS ELECTRONIC GMBH" },
{ "001087", "Xstreamis PLC" },
{ "0010ED", "SUNDANCE TECHNOLOGY, INC." },
{ "001023", "Network Equipment Technologies" },
{ "00104E", "CEOLOGIC" },
{ "0010FB", "ZIDA TECHNOLOGIES LIMITED" },
{ "0010AD", "SOFTRONICS USB, INC." },
{ "0010D5", "IMASDE CANARIAS, S.A." },
{ "0010E5", "SOLECTRON TEXAS" },
{ "00102A", "ZF MICROSYSTEMS, INC." },
{ "00107D", "AURORA COMMUNICATIONS, LTD." },
{ "00101C", "OHM TECHNOLOGIES INTL, LLC" },
{ "0090C5", "INTERNET MAGIC, INC." },
{ "0090AD", "ASPECT ELECTRONICS, INC." },
{ "009097", "Sycamore Networks" },
{ "009008", "HanA Systems Inc." },
{ "0090D4", "BindView Development Corp." },
{ "009089", "SOFTCOM MICROSYSTEMS, INC." },
{ "0090C4", "JAVELIN SYSTEMS, INC." },
{ "009014", "ROTORK INSTRUMENTS, LTD." },
{ "0090B5", "NIKON CORPORATION" },
{ "0090C6", "OPTIM SYSTEMS, INC." },
{ "00909B", "MARKEM-IMAJE" },
{ "00905B", "RAYMOND AND LAE ENGINEERING" },
{ "0090E8", "MOXA TECHNOLOGIES CORP., LTD." },
{ "0090A1", "Flying Pig Systems/High End Systems Inc." },
{ "0090FD", "CopperCom, Inc." },
{ "0090AC", "OPTIVISION, INC." },
{ "00902A", "COMMUNICATION DEVICES, INC." },
{ "009098", "SBC DESIGNS, INC." },
{ "0090CF", "NORTEL" },
{ "0050DA", "3COM CORPORATION" },
{ "0050F9", "Sensormatic Electronics LLC" },
{ "0050F6", "PAN-INTERNATIONAL INDUSTRIAL CORP." },
{ "00506C", "Beijer Electronics Products AB" },
{ "0050A5", "CAPITOL BUSINESS SYSTEMS, LTD." },
{ "005000", "NEXO COMMUNICATIONS, INC." },
{ "005030", "FUTURE PLUS SYSTEMS" },
{ "005037", "KOGA ELECTRONICS CO." },
{ "00106C", "EDNT GmbH" },
{ "0010D4", "STORAGE COMPUTER CORPORATION" },
{ "0010BF", "InterAir Wireless" },
{ "001036", "INTER-TEL INTEGRATED SYSTEMS" },
{ "001026", "ACCELERATED NETWORKS, INC." },
{ "00104B", "3COM CORPORATION" },
{ "000629", "IBM Corp" },
{ "001004", "THE BRANTLEY COILE COMPANY,INC" },
{ "00103A", "DIAMOND NETWORK TECH" },
{ "0010D8", "CALISTA" },
{ "001031", "OBJECTIVE COMMUNICATIONS, INC." },
{ "00103D", "PHASECOM, LTD." },
{ "0010C2", "WILLNET, INC." },
{ "00107A", "AmbiCom, Inc." },
{ "0010C4", "MEDIA GLOBAL LINKS CO., LTD." },
{ "0010EB", "SELSIUS SYSTEMS, INC." },
{ "0010FE", "DIGITAL EQUIPMENT CORPORATION" },
{ "00102E", "NETWORK SYSTEMS & TECHNOLOGIES PVT. LTD." },
{ "0010C1", "OI ELECTRIC CO., LTD." },
{ "00103E", "NETSCHOOLS CORPORATION" },
{ "001049", "ShoreTel, Inc" },
{ "00105E", "Spirent plc, Service Assurance Broadband" },
{ "0010B1", "FOR-A CO., LTD." },
{ "001041", "BRISTOL BABCOCK, INC." },
{ "0010F7", "IRIICHI TECHNOLOGIES Inc." },
{ "00E0FD", "A-TREND TECHNOLOGY CO., LTD." },
{ "00E0FB", "LEIGHTRONIX, INC." },
{ "00E0D3", "DATENTECHNIK GmbH" },
{ "00E05E", "JAPAN AVIATION ELECTRONICS INDUSTRY, LTD." },
{ "00E0E5", "CINCO NETWORKS, INC." },
{ "00E0CF", "INTEGRATED DEVICE TECHNOLOGY, INC." },
{ "00E0A1", "HIMA PAUL HILDEBRANDT GmbH Co. KG" },
{ "00E028", "APTIX CORPORATION" },
{ "00E0F2", "ARLOTTO COMNET, INC." },
{ "00E020", "TECNOMEN OY" },
{ "00E046", "BENTLY NEVADA CORP." },
{ "00E015", "HEIWA CORPORATION" },
{ "00E065", "OPTICAL ACCESS INTERNATIONAL" },
{ "00E069", "JAYCOR" },
{ "00E05C", "Panasonic Healthcare Co., Ltd." },
{ "00E087", "LeCroy - Networking Productions Division" },
{ "00E049", "MICROWI ELECTRONIC GmbH" },
{ "00E050", "EXECUTONE INFORMATION SYSTEMS, INC." },
{ "00E064", "SAMSUNG ELECTRONICS" },
{ "00E012", "PLUTO TECHNOLOGIES INTERNATIONAL INC." },
{ "00E0D8", "LANBit Computer, Inc." },
{ "00108F", "RAPTOR SYSTEMS" },
{ "001089", "WebSonic" },
{ "001086", "ATTO Technology, Inc." },
{ "001027", "L-3 COMMUNICATIONS EAST" },
{ "0010B8", "ISHIGAKI COMPUTER SYSTEM CO." },
{ "00104C", "Teledyne LeCroy, Inc" },
{ "001001", "Citel" },
{ "0010CF", "FIBERLANE COMMUNICATIONS" },
{ "001068", "COMOS TELECOM" },
{ "001067", "Ericsson" },
{ "0010F1", "I-O CORPORATION" },
{ "001073", "TECHNOBOX, INC." },
{ "00107E", "BACHMANN ELECTRONIC GmbH" },
{ "0010C0", "ARMA, Inc." },
{ "001016", "T.SQWARE" },
{ "00E02D", "InnoMediaLogic, Inc." },
{ "00E0A9", "FUNAI ELECTRIC CO., LTD." },
{ "00E035", "Artesyn Embedded Technologies" },
{ "00E060", "SHERWOOD" },
{ "00E0A2", "MICROSLATE INC." },
{ "00E06C", "Ultra Electronics Limited (AEP Networks)" },
{ "00E0CE", "ARN" },
{ "00E091", "LG ELECTRONICS, INC." },
{ "00E05F", "e-Net, Inc." },
{ "00E02B", "EXTREME NETWORKS" },
{ "00E0C7", "EUROTECH SRL" },
{ "00E0C4", "HORNER ELECTRIC, INC." },
{ "0010E6", "APPLIED INTELLIGENT SYSTEMS, INC." },
{ "00101E", "MATSUSHITA ELECTRONIC INSTRUMENTS CORP." },
{ "0010F2", "ANTEC" },
{ "0010BE", "MARCH NETWORKS CORPORATION" },
{ "00E0C5", "BCOM ELECTRONICS INC." },
{ "00E0EE", "MAREL HF" },
{ "00E0AC", "MIDSCO, INC." },
{ "00E002", "CROSSROADS SYSTEMS, INC." },
{ "00E057", "HAN MICROTELECOM. CO., LTD." },
{ "00E0F0", "ABLER TECHNOLOGY, INC." },
{ "00E0B7", "PI GROUP, LTD." },
{ "00E0C0", "SEIWA ELECTRIC MFG. CO., LTD." },
{ "006098", "HT COMMUNICATIONS" },
{ "0060F7", "DATAFUSION SYSTEMS" },
{ "0060DE", "Kayser-Threde GmbH" },
{ "0060D0", "SNMP RESEARCH INCORPORATED" },
{ "006079", "Mainstream Data, Inc." },
{ "006020", "PIVOTAL NETWORKING, INC." },
{ "0005A8", "WYLE ELECTRONICS" },
{ "0060B7", "CHANNELMATIC, INC." },
{ "0060A3", "CONTINUUM TECHNOLOGY CORP." },
{ "006050", "INTERNIX INC." },
{ "0060E0", "AXIOM TECHNOLOGY CO., LTD." },
{ "0060A8", "TIDOMAT AB" },
{ "00608E", "HE ELECTRONICS, TECHNOLOGIE & SYSTEMTECHNIK GmbH" },
{ "0060F0", "JOHNSON & JOHNSON MEDICAL, INC" },
{ "00A022", "CENTRE FOR DEVELOPMENT OF ADVANCED COMPUTING" },
{ "00A087", "Microsemi Corporation" },
{ "00A007", "APEXX TECHNOLOGY, INC." },
{ "00A066", "ISA CO., LTD." },
{ "00A0AB", "NETCS INFORMATIONSTECHNIK GMBH" },
{ "00A0D8", "SPECTRA - TEK" },
{ "00A01A", "BINAR ELEKTRONIK AB" },
{ "00A0E8", "REUTERS HOLDINGS PLC" },
{ "00A076", "CARDWARE LAB, INC." },
{ "00A0A3", "RELIABLE POWER METERS" },
{ "00A055", "Data Device Corporation" },
{ "00A065", "Symantec Corporation" },
{ "00A044", "NTT IT CO., LTD." },
{ "00A05F", "BTG Electronics Design BV" },
{ "00A094", "COMSAT CORPORATION" },
{ "00A010", "SYSLOGIC DATENTECHNIK AG" },
{ "00A012", "Telco Systems, Inc." },
{ "00A063", "JRL SYSTEMS, INC." },
{ "00A08F", "DESKNET SYSTEMS, INC." },
{ "00A0CC", "LITE-ON COMMUNICATIONS, INC." },
{ "00A090", "TimeStep Corporation" },
{ "00A0F7", "V.I COMPUTER CORP." },
{ "00A09C", "Xyplex, Inc." },
{ "00A0A0", "COMPACT DATA, LTD." },
{ "0060C6", "DCS AG" },
{ "00609E", "ASC X3 - INFORMATION TECHNOLOGY STANDARDS SECRETARIATS" },
{ "006084", "DIGITAL VIDEO" },
{ "00602D", "ALERTON TECHNOLOGIES, INC." },
{ "006093", "VARIAN" },
{ "0060E2", "QUEST ENGINEERING & DEVELOPMENT" },
{ "00A039", "ROSS TECHNOLOGY, INC." },
{ "00A06D", "MANNESMANN TALLY CORPORATION" },
{ "00A056", "MICROPROSS" },
{ "00A051", "ANGIA COMMUNICATIONS. INC." },
{ "00A0A6", "M.I. SYSTEMS, K.K." },
{ "00A0B0", "I-O DATA DEVICE, INC." },
{ "0060D2", "LUCENT TECHNOLOGIES TAIWAN TELECOMMUNICATIONS CO., LTD." },
{ "006077", "PRISA NETWORKS" },
{ "0060AB", "LARSCOM INCORPORATED" },
{ "0060E9", "ATOP TECHNOLOGIES, INC." },
{ "00608B", "ConferTech International" },
{ "0060C3", "NETVISION CORPORATION" },
{ "006051", "QUALITY SEMICONDUCTOR" },
{ "00605E", "LIBERTY TECHNOLOGY NETWORKING" },
{ "006058", "COPPER MOUNTAIN COMMUNICATIONS, INC." },
{ "00601B", "MESA ELECTRONICS" },
{ "0060FF", "QuVis, Inc." },
{ "006056", "NETWORK TOOLS, INC." },
{ "0060D8", "ELMIC SYSTEMS, INC." },
{ "00607A", "DVS GMBH" },
{ "006097", "3COM CORPORATION" },
{ "0060E3", "ARBIN INSTRUMENTS" },
{ "006008", "3COM CORPORATION" },
{ "0060EF", "FLYTECH TECHNOLOGY CO., LTD." },
{ "00E04D", "INTERNET INITIATIVE JAPAN, INC" },
{ "00607F", "AURORA TECHNOLOGIES, INC." },
{ "00E039", "PARADYNE CORP." },
{ "006091", "FIRST PACIFIC NETWORKS, INC." },
{ "006002", "SCREEN SUBTITLING SYSTEMS, LTD" },
{ "006061", "WHISTLE COMMUNICATIONS CORP." },
{ "0060BD", "HUBBELL-PULSECOM" },
{ "006074", "QSC AUDIO PRODUCTS" },
{ "00A024", "3COM CORPORATION" },
{ "00A0FD", "SCITEX DIGITAL PRINTING, INC." },
{ "00A0F5", "RADGUARD LTD." },
{ "00201B", "NORTHERN TELECOM/NETWORK" },
{ "0020C0", "PULSE ELECTRONICS, INC." },
{ "00208D", "CMD TECHNOLOGY" },
{ "0020DD", "Cybertec Pty Ltd" },
{ "0020BD", "NIOBRARA R & D CORPORATION" },
{ "0020E6", "LIDKOPING MACHINE TOOLS AB" },
{ "002047", "STEINBRECHER CORP." },
{ "0020B5", "YASKAWA ELECTRIC CORPORATION" },
{ "002072", "WORKLINK INNOVATIONS" },
{ "0020B8", "PRIME OPTION, INC." },
{ "002092", "CHESS ENGINEERING B.V." },
{ "0020B9", "METRICOM, INC." },
{ "00206B", "KONICA MINOLTA HOLDINGS, INC." },
{ "0020FC", "MATROX" },
{ "002035", "IBM Corp" },
{ "0020E2", "INFORMATION RESOURCE ENGINEERING" },
{ "002058", "ALLIED SIGNAL INC." },
{ "00208C", "GALAXY NETWORKS, INC." },
{ "002063", "WIPRO INFOTECH LTD." },
{ "0020DC", "DENSITRON TAIWAN LTD." },
{ "002078", "RUNTOP, INC." },
{ "002042", "DATAMETRICS CORP." },
{ "0020F8", "CARRERA COMPUTERS, INC." },
{ "00200C", "ADASTRA SYSTEMS CORP." },
{ "0020C4", "INET,INC." },
{ "00C003", "GLOBALNET COMMUNICATIONS" },
{ "00C0C3", "ACUSON COMPUTED SONOGRAPHY" },
{ "00C04D", "MITEC, INC." },
{ "00C055", "MODULAR COMPUTING TECHNOLOGIES" },
{ "00A0DB", "FISHER & PAYKEL PRODUCTION" },
{ "00A0A5", "TEKNOR MICROSYSTEME, INC." },
{ "00A018", "CREATIVE CONTROLLERS, INC." },
{ "00A09F", "COMMVISION CORP." },
{ "00A06B", "DMS DORSCH MIKROSYSTEM GMBH" },
{ "00209F", "MERCURY COMPUTER SYSTEMS, INC." },
{ "0020B7", "NAMAQUA COMPUTERWARE" },
{ "00C005", "LIVINGSTON ENTERPRISES, INC." },
{ "00C064", "GENERAL DATACOMM IND. INC." },
{ "00C0C8", "MICRO BYTE PTY. LTD." },
{ "00C090", "PRAIM S.R.L." },
{ "00C011", "INTERACTIVE COMPUTING DEVICES" },
{ "00C0FD", "PROSUM" },
{ "00C041", "DIGITAL TRANSMISSION SYSTEMS" },
{ "00C00F", "QUANTUM SOFTWARE SYSTEMS LTD." },
{ "00C076", "I-DATA INTERNATIONAL A-S" },
{ "00C0C6", "PERSONAL MEDIA CORP." },
{ "00C03B", "MULTIACCESS COMPUTING CORP." },
{ "00C099", "YOSHIKI INDUSTRIAL CO.,LTD." },
{ "00C0FC", "ELASTIC REALITY, INC." },
{ "00C067", "UNITED BARCODE INDUSTRIES" },
{ "00C0B4", "MYSON TECHNOLOGY, INC." },
{ "00C080", "NETSTAR, INC." },
{ "00C015", "NEW MEDIA CORPORATION" },
{ "00C09F", "QUANTA COMPUTER, INC." },
{ "0070B3", "DATA RECALL LTD." },
{ "00E6D3", "NIXDORF COMPUTER CORP." },
{ "00C083", "TRACE MOUNTAIN PRODUCTS, INC." },
{ "002081", "TITAN ELECTRONICS" },
{ "00201D", "KATANA PRODUCTS" },
{ "0020CF", "TEST & MEASUREMENT SYSTEMS INC" },
{ "002043", "NEURON COMPANY LIMITED" },
{ "002018", "CIS TECHNOLOGY INC." },
{ "002031", "Tattile SRL " },
{ "0020DE", "JAPAN DIGITAL LABORAT'Y CO.LTD" },
{ "0020F7", "CYBERDATA CORPORATION" },
{ "000267", "NODE RUNNER, INC." },
{ "002064", "PROTEC MICROSYSTEMS, INC." },
{ "002032", "ALCATEL TAISEL" },
{ "002027", "MING FORTUNE INDUSTRY CO., LTD" },
{ "0020ED", "GIGA-BYTE TECHNOLOGY CO., LTD." },
{ "00200E", "SATELLITE TECHNOLOGY MGMT, INC" },
{ "002096", "Invensys" },
{ "0020BB", "ZAX CORPORATION" },
{ "00204D", "INOVIS GMBH" },
{ "002089", "T3PLUS NETWORKING, INC." },
{ "00205F", "GAMMADATA COMPUTER GMBH" },
{ "0020EE", "GTECH CORPORATION" },
{ "00A08B", "ASTON ELECTRONIC DESIGNS LTD." },
{ "00A0AA", "SPACELABS MEDICAL" },
{ "00A04F", "AMERITEC CORP." },
{ "00A073", "COM21, INC." },
{ "00A084", "Dataplex Pty Ltd" },
{ "00A034", "AXEL" },
{ "00A092", "H. BOLLMANN MANUFACTURERS, LTD" },
{ "00A04D", "EDA INSTRUMENTS, INC." },
{ "00207F", "KYOEI SANGYO CO., LTD." },
{ "002077", "KARDIOS SYSTEMS CORP." },
{ "002068", "ISDYNE" },
{ "00202A", "N.V. DZINE" },
{ "0020F4", "SPECTRIX CORPORATION" },
{ "00204E", "NETWORK SECURITY SYSTEMS, INC." },
{ "00C074", "TOYODA AUTOMATIC LOOM" },
{ "00C07F", "NUPON COMPUTING CORP." },
{ "00C027", "CIPHER SYSTEMS, INC." },
{ "00C025", "DATAPRODUCTS CORPORATION" },
{ "00C022", "LASERMASTER TECHNOLOGIES, INC." },
{ "00C0E6", "Verilink Corporation" },
{ "00C05C", "ELONEX PLC" },
{ "00C0C1", "QUAD/GRAPHICS, INC." },
{ "00C091", "JABIL CIRCUIT, INC." },
{ "00C002", "SERCOMM CORPORATION" },
{ "00C0F5", "METACOMP, INC." },
{ "00C042", "DATALUX CORP." },
{ "00C089", "TELINDUS DISTRIBUTION" },
{ "00C09D", "DISTRIBUTED SYSTEMS INT'L, INC" },
{ "00C0A5", "DICKENS DATA SYSTEMS" },
{ "00C0E3", "OSITECH COMMUNICATIONS, INC." },
{ "00C071", "AREANEX COMMUNICATIONS, INC." },
{ "00C0AF", "TEKLOGIX INC." },
{ "00C05D", "L&N TECHNOLOGIES" },
{ "00C0E4", "SIEMENS BUILDING" },
{ "0040C4", "KINKEI SYSTEM CORPORATION" },
{ "0040D1", "FUKUDA DENSHI CO., LTD." },
{ "004024", "COMPAC INC." },
{ "0040B6", "COMPUTERM  CORPORATION" },
{ "00403F", "SSANGYONG COMPUTER SYSTEMS" },
{ "004003", "Emerson Process Management Power & Water Solutions, Inc." },
{ "004090", "ANSEL COMMUNICATIONS" },
{ "00409A", "NETWORK EXPRESS, INC." },
{ "004055", "METRONIX GMBH" },
{ "00C01B", "SOCKET COMMUNICATIONS, INC." },
{ "00C06E", "HAFT TECHNOLOGY, INC." },
{ "00406F", "SYNC RESEARCH INC." },
{ "00401F", "COLORGRAPH LTD" },
{ "0040CF", "STRAWBERRY TREE, INC." },
{ "0040F7", "Polaroid Corporation" },
{ "004037", "SEA-ILAN, INC." },
{ "0040CC", "SILCOM MANUF'G TECHNOLOGY INC." },
{ "00404C", "HYPERTEC PTY LTD." },
{ "00C0EE", "KYOCERA CORPORATION" },
{ "0040A5", "CLINICOMP INTL." },
{ "004059", "YOSHIDA KOGYO K. K." },
{ "004021", "RASTER GRAPHICS" },
{ "004081", "MANNESMANN SCANGRAPHIC GMBH" },
{ "00806C", "CEGELEC PROJECTS LTD" },
{ "00404A", "WEST AUSTRALIAN DEPARTMENT" },
{ "00400A", "PIVOTAL TECHNOLOGIES, INC." },
{ "004032", "DIGITAL COMMUNICATIONS" },
{ "004042", "N.A.T. GMBH" },
{ "0040C2", "APPLIED COMPUTING DEVICES" },
{ "00403C", "FORKS, INC." },
{ "004004", "ICM CO. LTD." },
{ "00C0CB", "CONTROL TECHNOLOGY CORPORATION" },
{ "00C09A", "PHOTONICS CORPORATION" },
{ "00C01A", "COROMETRICS MEDICAL SYSTEMS" },
{ "00404B", "MAPLE COMPUTER SYSTEMS" },
{ "00401D", "INVISIBLE SOFTWARE, INC." },
{ "0040BD", "STARLIGHT NETWORKS, INC." },
{ "00406D", "LANCO, INC." },
{ "00404D", "TELECOMMUNICATIONS TECHNIQUES" },
{ "00C0D0", "RATOC SYSTEM INC." },
{ "00C07A", "PRIVA B.V." },
{ "000701", "RACAL-DATACOM" },
{ "00C09C", "HIOKI E.E. CORPORATION" },
{ "00C004", "JAPAN BUSINESS COMPUTER CO.LTD" },
{ "00C062", "IMPULSE TECHNOLOGY" },
{ "00C0BC", "TELECOM AUSTRALIA/CSSC" },
{ "00C0EF", "ABIT CORPORATION" },
{ "00C03C", "TOWER TECH S.R.L." },
{ "00C061", "SOLECTEK CORPORATION" },
{ "004045", "TWINHEAD CORPORATION" },
{ "00409D", "DIGIBOARD, INC." },
{ "00401A", "FUJI ELECTRIC CO., LTD." },
{ "0040B9", "MACQ ELECTRONIQUE SA" },
{ "0040C7", "RUBY TECH CORPORATION" },
{ "004052", "STAR TECHNOLOGIES, INC." },
{ "00407A", "SOCIETE D'EXPLOITATION DU CNIT" },
{ "004089", "MEIDENSHA CORPORATION" },
{ "00405A", "GOLDSTAR INFORMATION & COMM." },
{ "004070", "INTERWARE CO., LTD." },
{ "008057", "ADSOFT, LTD." },
{ "00807A", "AITECH SYSTEMS LTD." },
{ "0080AA", "MAXPEED" },
{ "00C0E7", "FIBERDATA AB" },
{ "008095", "BASIC MERTON HANDELSGES.M.B.H." },
{ "008053", "INTELLICOM, INC." },
{ "008026", "NETWORK PRODUCTS CORPORATION" },
{ "0080FE", "AZURE TECHNOLOGIES, INC." },
{ "008028", "TRADPOST (HK) LTD" },
{ "0080B6", "THEMIS COMPUTER" },
{ "008058", "PRINTER SYSTEMS CORPORATION" },
{ "0080C0", "PENRIL DATACOMM" },
{ "0080F5", "Quantel Ltd" },
{ "00608C", "3COM CORPORATION" },
{ "00804E", "APEX COMPUTER COMPANY" },
{ "00800E", "ATLANTIX CORPORATION" },
{ "0080DA", "Bruel & Kjaer Sound & Vibration Measurement A/S" },
{ "0080BC", "HITACHI ENGINEERING CO., LTD" },
{ "008000", "MULTITECH SYSTEMS, INC." },
{ "0080A1", "MICROTEST, INC." },
{ "0080D0", "COMPUTER PERIPHERALS, INC." },
{ "00807D", "EQUINOX SYSTEMS INC." },
{ "008063", "Hirschmann Automation and Control GmbH" },
{ "008030", "NEXUS ELECTRONICS" },
{ "008022", "SCAN-OPTICS" },
{ "000041", "ICE CORPORATION" },
{ "0040DE", "Elsag Datamat spa" },
{ "004063", "VIA TECHNOLOGIES, INC." },
{ "00406C", "COPERNIQUE" },
{ "0040DF", "DIGALOG SYSTEMS, INC." },
{ "004015", "ASCOM INFRASYS AG" },
{ "008056", "SPHINX Electronics GmbH & Co KG" },
{ "008060", "NETWORK INTERFACE CORPORATION" },
{ "00805E", "LSI LOGIC CORPORATION" },
{ "008093", "XYRON CORPORATION" },
{ "008006", "COMPUADD CORPORATION" },
{ "0080EF", "RATIONAL" },
{ "0080C4", "DOCUMENT TECHNOLOGIES, INC." },
{ "00801D", "INTEGRATED INFERENCE MACHINES" },
{ "008015", "SEIKO SYSTEMS, INC." },
{ "008034", "SMT GOUPIL" },
{ "0080C9", "ALBERTA MICROELECTRONIC CENTRE" },
{ "00800B", "CSK CORPORATION" },
{ "00800A", "JAPAN COMPUTER CORP." },
{ "00806E", "NIPPON STEEL CORPORATION" },
{ "008010", "COMMODORE INTERNATIONAL" },
{ "0000C8", "ALTOS COMPUTER SYSTEMS" },
{ "000098", "CROSSCOMM CORPORATION" },
{ "00007D", "Oracle Corporation" },
{ "0000A2", "Bay Networks" },
{ "000038", "CSS LABS" },
{ "000061", "GATEWAY COMMUNICATIONS" },
{ "000043", "MICRO TECHNOLOGY" },
{ "0000E7", "Star Gate Technologies" },
{ "0000F3", "GANDALF DATA LIMITED" },
{ "00005C", "TELEMATICS INTERNATIONAL INC." },
{ "0000AC", "CONWARE COMPUTER CONSULTING" },
{ "0000F2", "SPIDER COMMUNICATIONS" },
{ "000030", "VG LABORATORY SYSTEMS LTD" },
{ "000035", "SPECTRAGRAPHICS CORPORATION" },
{ "0000E0", "QUADRAM CORP." },
{ "000057", "SCITEX CORPORATION LTD." },
{ "0000D6", "PUNCH LINE HOLDING" },
{ "00806F", "ONELAN LTD." },
{ "008098", "TDK CORPORATION" },
{ "00809C", "LUXCOM, INC." },
{ "008065", "CYBERGRAPHIC SYSTEMS PTY LTD." },
{ "008016", "WANDEL AND GOLTERMANN" },
{ "0080E6", "PEER NETWORKS, INC." },
{ "0080A2", "CREATIVE ELECTRONIC SYSTEMS" },
{ "0080E0", "XTP SYSTEMS, INC." },
{ "008050", "ZIATECH CORPORATION" },
{ "0080FF", "SOC. DE TELEINFORMATIQUE RTC" },
{ "000070", "HCL LIMITED" },
{ "00008E", "SOLBOURNE COMPUTER, INC." },
{ "0000DC", "HAYES MICROCOMPUTER PRODUCTS" },
{ "000024", "CONNECT AS" },
{ "000048", "SEIKO EPSON CORPORATION" },
{ "000016", "DU PONT PIXEL SYSTEMS     ." },
{ "00001E", "TELSIST INDUSTRIA ELECTRONICA" },
{ "00807B", "ARTEL COMMUNICATIONS CORP." },
{ "00802E", "CASTLE ROCK COMPUTING" },
{ "0080F9", "HEURIKON CORPORATION" },
{ "008005", "CACTUS COMPUTER INC." },
{ "008008", "DYNATECH COMPUTER SYSTEMS" },
{ "08005E", "COUNTERPOINT COMPUTER INC." },
{ "08005A", "IBM Corp" },
{ "080056", "STANFORD LINEAR ACCEL. CENTER" },
{ "080053", "MIDDLE EAST TECH. UNIVERSITY" },
{ "08004F", "CYGNET SYSTEMS" },
{ "080040", "FERRANTI COMPUTER SYS. LIMITED" },
{ "08003B", "TORUS SYSTEMS LIMITED" },
{ "08003D", "CADNETIX CORPORATIONS" },
{ "080039", "SPIDER SYSTEMS LIMITED" },
{ "00DD0C", "UNGERMANN-BASS INC." },
{ "000005", "XEROX CORPORATION" },
{ "0000AA", "XEROX CORPORATION" },
{ "000064", "Yokogawa Electric Corporation" },
{ "00002C", "AUTOTOTE LIMITED" },
{ "00002A", "TRW - SEDD/INP" },
{ "0000F1", "MAGNA COMPUTER CORPORATION" },
{ "000083", "TADPOLE TECHNOLOGY PLC" },
{ "000020", "DATAINDUSTRIER DIAB AB" },
{ "00007A", "DANA COMPUTER INC." },
{ "00007C", "AMPERE INCORPORATED" },
{ "00008A", "DATAHOUSE INFORMATION SYSTEMS" },
{ "080030", "NETWORK RESEARCH CORPORATION" },
{ "080027", "Cadmus Computer Systems" },
{ "020701", "RACAL-DATACOM" },
{ "080011", "TEKTRONIX INC." },
{ "08007F", "CARNEGIE-MELLON UNIVERSITY" },
{ "080082", "VERITAS SOFTWARE" },
{ "08007B", "SANYO ELECTRIC CO. LTD." },
{ "080074", "CASIO COMPUTER CO. LTD." },
{ "00406B", "SYSGEN" },
{ "AA0001", "DIGITAL EQUIPMENT CORPORATION" },
{ "080001", "COMPUTERVISION CORPORATION" },
{ "000053", "COMPUCORP" },
{ "08004B", "Planning Research Corp." },
{ "080003", "ADVANCED COMPUTER COMM." },
{ "00009B", "INFORMATION INTERNATIONAL, INC" },
{ "000068", "ROSEMOUNT CONTROLS" },
{ "0000A8", "STRATUS COMPUTER INC." },
{ "0000DF", "BELL & HOWELL PUB SYS DIV" },
{ "000062", "BULL HN INFORMATION SYSTEMS" },
{ "0000AD", "BRUKER INSTRUMENTS INC." },
{ "0000D0", "DEVELCON ELECTRONICS LTD." },
{ "000093", "PROTEON INC." },
{ "0000A0", "SANYO Electric Co., Ltd." },
{ "00DD0F", "UNGERMANN-BASS INC." },
{ "000001", "XEROX CORPORATION" },
{ "080021", "3M COMPANY" },
{ "AA0004", "DIGITAL EQUIPMENT CORPORATION" },
{ "08000C", "MIKLYN DEVELOPMENT CO." },
{ "00DD08", "UNGERMANN-BASS INC." },
{ "0000D8", "NOVELL, INC." },
{ "F8E71E", "Ruckus Wireless" },
{ "A01B29", "Sagemcom Broadband SAS" },
{ "90013B", "Sagemcom Broadband SAS" },
{ "ECDF3A", "vivo Mobile Communication Co., Ltd." },
{ "E45AA2", "vivo Mobile Communication Co., Ltd." },
{ "00194B", "Sagemcom Broadband SAS" },
{ "001F95", "Sagemcom Broadband SAS" },
{ "000E59", "Sagemcom Broadband SAS" },
{ "00235A", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "001B38", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "E46F13", "D-Link International" },
{ "DC6DCD", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "807B85", "IEEE Registration Authority" },
{ "CC1BE0", "IEEE Registration Authority" },
{ "A43BFA", "IEEE Registration Authority" },
{ "F40E11", "IEEE Registration Authority" },
{ "94C150", "2Wire Inc" },
{ "60FE20", "2Wire Inc" },
{ "D4AE52", "Dell Inc." },
{ "989096", "Dell Inc." },
{ "B82A72", "Dell Inc." },
{ "00D09E", "2Wire Inc" },
{ "000D72", "2Wire Inc" },
{ "B0E754", "2Wire Inc" },
{ "B8E625", "2Wire Inc" },
{ "000F1F", "Dell Inc." },
{ "14FEB5", "Dell Inc." },
{ "0015C5", "Dell Inc." },
{ "549F35", "Dell Inc." },
{ "64006A", "Dell Inc." },
{ "B4E10F", "Dell Inc." },
{ "0023AE", "Dell Inc." },
{ "9CD917", "Motorola Mobility LLC, a Lenovo Company" },
{ "9068C3", "Motorola Mobility LLC, a Lenovo Company" },
{ "408805", "Motorola Mobility LLC, a Lenovo Company" },
{ "A4A1C2", "Ericsson AB" },
{ "348446", "Ericsson AB" },
{ "F8F1B6", "Motorola Mobility LLC, a Lenovo Company" },
{ "AC2B6E", "Intel Corporate" },
{ "00216A", "Intel Corporate" },
{ "001E64", "Intel Corporate" },
{ "0016EB", "Intel Corporate" },
{ "0018DE", "Intel Corporate" },
{ "28B2BD", "Intel Corporate" },
{ "08D40C", "Intel Corporate" },
{ "843A4B", "Intel Corporate" },
{ "681729", "Intel Corporate" },
{ "5C514F", "Intel Corporate" },
{ "B808CF", "Intel Corporate" },
{ "5CC5D4", "Intel Corporate" },
{ "7CCCB8", "Intel Corporate" },
{ "F40669", "Intel Corporate" },
{ "C8F733", "Intel Corporate" },
{ "0CD292", "Intel Corporate" },
{ "78929C", "Intel Corporate" },
{ "6805CA", "Intel Corporate" },
{ "4851B7", "Intel Corporate" },
{ "3CA9F4", "Intel Corporate" },
{ "ACA31E", "Aruba Networks" },
{ "9C1C12", "Aruba Networks" },
{ "001A1E", "Aruba Networks" },
{ "28C2DD", "AzureWave Technology Inc." },
{ "84D47E", "Aruba Networks" },
{ "A85840", "Cambridge Industries(Group) Co.,Ltd." },
{ "002423", "AzureWave Technologies (Shanghai) Inc." },
{ "002243", "AzureWave Technology Inc." },
{ "74F06D", "AzureWave Technology Inc." },
{ "44D832", "AzureWave Technology Inc." },
{ "781881", "AzureWave Technology Inc." },
{ "B0EE45", "AzureWave Technology Inc." },
{ "240A64", "AzureWave Technology Inc." },
{ "D0E782", "AzureWave Technology Inc." },
{ "A81D16", "AzureWave Technology Inc." },
{ "38A53C", "COMECER Netherlands" },
{ "0C4C39", "MitraStar Technology Corp." },
{ "581243", "AcSiP Technology Corp." },
{ "0026B8", "Actiontec Electronics, Inc" },
{ "0030F1", "Accton Technology Corp" },
{ "001974", "16063" },
{ "3039F2", "ADB Broadband Italia" },
{ "000827", "ADB Broadband Italia" },
{ "001D8B", "ADB Broadband Italia" },
{ "A4526F", "ADB Broadband Italia" },
{ "001CA8", "AirTies Wireless Netowrks" },
{ "9097D5", "Espressif Inc." },
{ "18FE34", "Espressif Inc." },
{ "54F6C5", "FUJIAN STAR-NET COMMUNICATION CO.,LTD" },
{ "A43111", "ZIV" },
{ "ECF00E", "AboCom" },
{ "28EF01", "Private" },
{ "5C338E", "Alpha Networks Inc." },
{ "001AEB", "Allied Telesis R&D Center K.K." },
{ "5C93A2", "Liteon Technology Corporation" },
{ "E8C74F", "Liteon Technology Corporation" },
{ "E8F724", "Hewlett Packard Enterprise" },
{ "747548", "Amazon Technologies Inc." },
{ "080046", "Sony Corporation" },
{ "001DBA", "Sony Corporation" },
{ "000AD9", "Sony Mobile Communications AB" },
{ "000FDE", "Sony Mobile Communications AB" },
{ "001EDC", "Sony Mobile Communications AB" },
{ "001963", "Sony Mobile Communications AB" },
{ "001B59", "Sony Mobile Communications AB" },
{ "78843C", "Sony Corporation" },
{ "701A04", "Liteon Technology Corporation" },
{ "48D224", "Liteon Technology Corporation" },
{ "2CD05A", "Liteon Technology Corporation" },
{ "74E543", "Liteon Technology Corporation" },
{ "A4DB30", "Liteon Technology Corporation" },
{ "B8EE65", "Liteon Technology Corporation" },
{ "0023F1", "Sony Mobile Communications AB" },
{ "3017C8", "Sony Mobile Communications AB" },
{ "18002D", "Sony Mobile Communications AB" },
{ "04E676", "AMPAK Technology, Inc." },
{ "0022F4", "AMPAK Technology, Inc." },
{ "1C1448", "ARRIS Group, Inc." },
{ "707E43", "ARRIS Group, Inc." },
{ "0003E0", "ARRIS Group, Inc." },
{ "00128A", "ARRIS Group, Inc." },
{ "001225", "ARRIS Group, Inc." },
{ "001AAD", "ARRIS Group, Inc." },
{ "A47AA4", "ARRIS Group, Inc." },
{ "3C754A", "ARRIS Group, Inc." },
{ "0024C1", "ARRIS Group, Inc." },
{ "002136", "ARRIS Group, Inc." },
{ "0022B4", "ARRIS Group, Inc." },
{ "002395", "ARRIS Group, Inc." },
{ "0023ED", "ARRIS Group, Inc." },
{ "745612", "ARRIS Group, Inc." },
{ "E46449", "ARRIS Group, Inc." },
{ "002493", "ARRIS Group, Inc." },
{ "40FC89", "ARRIS Group, Inc." },
{ "001B52", "ARRIS Group, Inc." },
{ "00230B", "ARRIS Group, Inc." },
{ "001E8D", "ARRIS Group, Inc." },
{ "0023A2", "ARRIS Group, Inc." },
{ "001BDD", "ARRIS Group, Inc." },
{ "001404", "ARRIS Group, Inc." },
{ "00195E", "ARRIS Group, Inc." },
{ "0011F5", "ASKEY COMPUTER CORP" },
{ "DCD87C", "Beijing Jingdong Century Trading Co., LTD." },
{ "001C4A", "AVM GmbH" },
{ "000B6A", "Asiarock Technology Limited" },
{ "40BA61", "ARIMA Communications Corp." },
{ "000D92", "ARIMA Communications Corp." },
{ "009096", "ASKEY COMPUTER CORP" },
{ "204E7F", "NETGEAR" },
{ "A021B7", "NETGEAR" },
{ "0024B2", "NETGEAR" },
{ "C03F0E", "NETGEAR" },
{ "001F33", "NETGEAR" },
{ "841B5E", "NETGEAR" },
{ "001CCC", "BlackBerry RTS" },
{ "94EBCD", "BlackBerry RTS" },
{ "A4E4B8", "BlackBerry RTS" },
{ "58671A", "Barnes&Noble" },
{ "BC0543", "AVM GmbH" },
{ "002675", "Aztech Electronics Pte Ltd" },
{ "001D19", "Arcadyan Technology Corporation" },
{ "88252C", "Arcadyan Technology Corporation" },
{ "1883BF", "Arcadyan Technology Corporation" },
{ "9C80DF", "Arcadyan Technology Corporation" },
{ "644FB0", "Hyunjin.com" },
{ "001A2A", "Arcadyan Technology Corporation" },
{ "001F3F", "AVM GmbH" },
{ "506A03", "NETGEAR" },
{ "6CB0CE", "NETGEAR" },
{ "100D7F", "NETGEAR" },
{ "001018", "Broadcom" },
{ "001BE9", "Broadcom" },
{ "0020D6", "Breezecom, Ltd." },
{ "008077", "Brother industries, LTD." },
{ "307C5E", "Juniper Networks" },
{ "0010DB", "Juniper Networks" },
{ "00121E", "Juniper Networks" },
{ "0014F6", "Juniper Networks" },
{ "EC3EF7", "Juniper Networks" },
{ "0C8610", "Juniper Networks" },
{ "40A677", "Juniper Networks" },
{ "DC38E1", "Juniper Networks" },
{ "FC2F40", "Calxeda, Inc." },
{ "40B4F0", "Juniper Networks" },
{ "841888", "Juniper Networks" },
{ "002688", "Juniper Networks" },
{ "0017CB", "Juniper Networks" },
{ "029D8E", "CARDIAC RECORDERS, INC." },
{ "0026E4", "Canal +" },
{ "E458E7", "Samsung Electronics Co.,Ltd" },
{ "8CBFA6", "Samsung Electronics Co.,Ltd" },
{ "7840E4", "Samsung Electronics Co.,Ltd" },
{ "9000DB", "Samsung Electronics Co.,Ltd" },
{ "183A2D", "Samsung Electronics Co.,Ltd" },
{ "A89FBA", "Samsung Electronics Co.,Ltd" },
{ "FC1910", "Samsung Electronics Co.,Ltd" },
{ "083D88", "Samsung Electronics Co.,Ltd" },
{ "5C2E59", "Samsung Electronics Co.,Ltd" },
{ "646CB2", "Samsung Electronics Co.,Ltd" },
{ "A48431", "Samsung Electronics Co.,Ltd" },
{ "E4F8EF", "Samsung Electronics Co.,Ltd" },
{ "1867B0", "Samsung Electronics Co.,Ltd" },
{ "F40E22", "Samsung Electronics Co.,Ltd" },
{ "4CBCA5", "Samsung Electronics Co.,Ltd" },
{ "78595E", "Samsung Electronics Co.,Ltd" },
{ "B0D09C", "Samsung Electronics Co.,Ltd" },
{ "4CA56D", "Samsung Electronics Co.,Ltd" },
{ "08373D", "Samsung Electronics Co.,Ltd" },
{ "50F520", "Samsung Electronics Co.,Ltd" },
{ "A4EBD3", "Samsung Electronics Co.,Ltd" },
{ "28987B", "Samsung Electronics Co.,Ltd" },
{ "9C3AAF", "Samsung Electronics Co.,Ltd" },
{ "1432D1", "Samsung Electronics Co.,Ltd" },
{ "F884F2", "Samsung Electronics Co.,Ltd" },
{ "14B484", "Samsung Electronics Co.,Ltd" },
{ "608F5C", "Samsung Electronics Co.,Ltd" },
{ "389496", "Samsung Electronics Co.,Ltd" },
{ "0CB319", "Samsung Electronics Co.,Ltd" },
{ "08EE8B", "Samsung Electronics Co.,Ltd" },
{ "84A466", "Samsung Electronics Co.,Ltd" },
{ "981DFA", "Samsung Electronics Co.,Ltd" },
{ "FCF136", "Samsung Electronics Co.,Ltd" },
{ "0C8910", "Samsung Electronics Co.,Ltd" },
{ "54FA3E", "Samsung Electronics Co.,Ltd" },
{ "702559", "CyberTAN Technology Inc." },
{ "0090D6", "Crystal Group, Inc." },
{ "02CF1C", "Communication Machinery Corporation" },
{ "BCF2AF", "devolo AG" },
{ "0270B3", "DATA RECALL LTD." },
{ "000FF6", "DARFON LIGHTING CORP" },
{ "001DAA", "DrayTek Corp." },
{ "0C75BD", "Cisco Systems, Inc" },
{ "38F0C8", "Livestream" },
{ "0C1167", "Cisco Systems, Inc" },
{ "74EAE8", "ARRIS Group, Inc." },
{ "A811FC", "ARRIS Group, Inc." },
{ "001982", "SmarDTV" },
{ "00904B", "Gemtek Technology Co., Ltd." },
{ "10C6FC", "Garmin International" },
{ "00E000", "FUJITSU LIMITED" },
{ "00000E", "FUJITSU LIMITED" },
{ "002326", "FUJITSU LIMITED" },
{ "0007CB", "FREEBOX SAS" },
{ "3C591E", "TCL King Electrical Appliances (Huizhou) Co., Ltd" },
{ "002682", "Gemtek Technology Co., Ltd." },
{ "001A73", "Gemtek Technology Co., Ltd." },
{ "34AF2C", "Nintendo Co., Ltd." },
{ "8CCDE8", "Nintendo Co., Ltd." },
{ "9CE635", "Nintendo Co., Ltd." },
{ "600194", "Espressif Inc." },
{ "F44D17", "GOLDCARD HIGH-TECH CO.,LTD." },
{ "0021BD", "Nintendo Co., Ltd." },
{ "002709", "Nintendo Co., Ltd." },
{ "E84ECE", "Nintendo Co., Ltd." },
{ "D86BF7", "Nintendo Co., Ltd." },
{ "A4C0E1", "Nintendo Co., Ltd." },
{ "001AE9", "Nintendo Co., Ltd." },
{ "001CBE", "Nintendo Co., Ltd." },
{ "001E35", "Nintendo Co., Ltd." },
{ "001FC5", "Nintendo Co., Ltd." },
{ "0009BF", "Nintendo Co., Ltd." },
{ "002403", "Nokia Danmark A/S" },
{ "002265", "Nokia Danmark A/S" },
{ "0019B7", "Nokia Danmark A/S" },
{ "001D6E", "Nokia Danmark A/S" },
{ "001B33", "Nokia Danmark A/S" },
{ "ECF35B", "Nokia Corporation" },
{ "EC9B5B", "Nokia Corporation" },
{ "BCC6DB", "Nokia Corporation" },
{ "0021AA", "Nokia Danmark A/S" },
{ "002669", "Nokia Danmark A/S" },
{ "0022FD", "Nokia Danmark A/S" },
{ "002109", "Nokia Danmark A/S" },
{ "002108", "Nokia Danmark A/S" },
{ "001F01", "Nokia Danmark A/S" },
{ "000EED", "Nokia Danmark A/S" },
{ "001E3A", "Nokia Danmark A/S" },
{ "001A89", "Nokia Danmark A/S" },
{ "002404", "Nokia Danmark A/S" },
{ "0002EE", "Nokia Danmark A/S" },
{ "001C9A", "Nokia Danmark A/S" },
{ "B83241", "Wuhan Tianyu Information Industry Co., Ltd." },
{ "9897D1", "MitraStar Technology Corp." },
{ "94C960", "Zhongshan B&T technology.co.,ltd" },
{ "E04FBD", "SICHUAN TIANYI COMHEART TELECOMCO.,LTD" },
{ "001479", "NEC Magnus Communications,Ltd." },
{ "38B8EB", "IEEE Registration Authority" },
{ "9C4FDA", "Apple, Inc." },
{ "1C5CF2", "Apple, Inc." },
{ "0821EF", "Samsung Electronics Co.,Ltd" },
{ "B462AD", "Elysia Germany GmbH" },
{ "747818", "Jurumani Solutions" },
{ "A0CBFD", "Samsung Electronics Co.,Ltd" },
{ "34145F", "Samsung Electronics Co.,Ltd" },
{ "803896", "SHARP Corporation" },
{ "00D9D1", "Sony Computer Entertainment Inc." },
{ "F8D0AC", "Sony Computer Entertainment Inc." },
{ "0CFE45", "Sony Computer Entertainment Inc." },
{ "D8D43C", "Sony Computer Entertainment Inc." },
{ "3C0771", "Sony Computer Entertainment Inc." },
{ "686E23", "Wi3 Inc." },
{ "B8A175", "Roku, Inc." },
{ "80D160", "Integrated Device Technology (Malaysia) Sdn. Bhd." },
{ "0080E5", "NetApp" },
{ "E49A79", "Apple, Inc." },
{ "28A02B", "Apple, Inc." },
{ "B44BD2", "Apple, Inc." },
{ "002340", "MiXTelematics" },
{ "B48B19", "Apple, Inc." },
{ "4CCC6A", "Micro-Star INTL CO., LTD." },
{ "00AF1F", "Cisco Systems, Inc" },
{ "245EBE", "QNAP Systems, Inc." },
{ "A89352", "SHANGHAI ZHONGMI COMMUNICATION TECHNOLOGY CO.,LTD" },
{ "AC5F3E", "SAMSUNG ELECTRO-MECHANICS(THAILAND)" },
{ "985BB0", "KMDATA INC." },
{ "6C8FB5", "Microsoft Mobile Oy" },
{ "38FDFE", "IEEE Registration Authority" },
{ "D4E33F", "Alcatel-Lucent" },
{ "143E60", "Alcatel-Lucent" },
{ "248A07", "Mellanox Technologies, Inc." },
{ "9C9D5D", "Raden Inc" },
{ "B07FB9", "NETGEAR" },
{ "70661B", "Sonova AG" },
{ "1C98EC", "Hewlett Packard Enterprise" },
{ "EC438B", "YAPTV" },
{ "E8FD72", "SHANGHAI LINGUO TECHNOLOGY CO., LTD." },
{ "98BB1E", "BYD Precision Manufacture Company Ltd." },
{ "001D0D", "Sony Computer Entertainment Inc." },
{ "00041F", "Sony Computer Entertainment Inc." },
{ "20A90E", "TCT mobile ltd" },
{ "CCB11A", "Samsung Electronics Co.,Ltd" },
{ "1866DA", "Dell Inc." },
{ "981FB1", "Shenzhen Lemon Network Technology Co.,Ltd" },
{ "40476A", "AG Acquisition Corp. d.b.a. ASTRO Gaming" },
{ "A4BF01", "Intel Corporate" },
{ "7C477C", "IEEE Registration Authority" },
{ "0004C6", "YAMAHA MOTOR CO.,LTD" },
{ "509EA7", "Samsung Electronics Co.,Ltd" },
{ "DCCF96", "Samsung Electronics Co.,Ltd" },
{ "64CC2E", "Xiaomi Communications Co Ltd" },
{ "14D11F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "54511B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "68536C", "SPnS Co.,Ltd" },
{ "005BA1", "shanghai huayuan chuangxin software CO., LTD." },
{ "B07E70", "Zadara Storage Ltd." },
{ "405EE1", "Shenzhen H&T Intelligent Control Co.,Ltd." },
{ "88795B", "Konka Group Co., Ltd." },
{ "10F005", "Intel Corporate" },
{ "BC9889", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "E42F26", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "344B3D", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "FCF647", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "1088CE", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "D463FE", "Arcadyan Corporation" },
{ "9466E7", "WOM Engineering" },
{ "F8A188", "LED Roadway Lighting" },
{ "001174", "Mojo Networks, Inc." },
{ "BC15AC", "Vodafone Italia S.p.A." },
{ "1C740D", "ZyXEL Communications Corporation" },
{ "140C5B", "PLNetworks" },
{ "50FF99", "IEEE Registration Authority" },
{ "D0B0CD", "Moen" },
{ "DCFE07", "PEGATRON CORPORATION" },
{ "E47E66", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "9C741A", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "EC93ED", "DDoS-Guard LTD" },
{ "4C72B9", "PEGATRON CORPORATION" },
{ "0071C2", "PEGATRON CORPORATION" },
{ "F462D0", "Not for Radio, LLC" },
{ "94513D", "iSmart Alarm, Inc." },
{ "C89CDC", "Elitegroup Computer Systems Co.,Ltd." },
{ "002511", "Elitegroup Computer Systems Co.,Ltd." },
{ "000E03", "Emulex Corporation" },
{ "001BB9", "Elitegroup Computer Systems Co.,Ltd." },
{ "001921", "Elitegroup Computer Systems Co.,Ltd." },
{ "00142A", "Elitegroup Computer Systems Co.,Ltd." },
{ "0050FC", "Edimax Technology Co. Ltd." },
{ "200A5E", "Xiangshan Giant Eagle Technology Developing Co., Ltd." },
{ "0001F4", "Enterasys" },
{ "487ADA", "Hangzhou H3C Technologies Co., Limited" },
{ "1C7370", "Neotech" },
{ "30E37A", "Intel Corporate" },
{ "A08CFD", "Hewlett Packard" },
{ "4CA003", "T-21 Technologies LLC" },
{ "F0EE58", "PACE Telematics GmbH" },
{ "001397", "Oracle Corporation " },
{ "00A0A4", "Oracle Corporation " },
{ "A4E597", "Gessler GmbH" },
{ "D86CE9", "Sagemcom Broadband SAS" },
{ "3C81D8", "Sagemcom Broadband SAS" },
{ "2CE412", "Sagemcom Broadband SAS" },
{ "181E78", "Sagemcom Broadband SAS" },
{ "0037B7", "Sagemcom Broadband SAS" },
{ "0014BF", "Cisco-Linksys, LLC" },
{ "6C8DC1", "Apple, Inc." },
{ "38CADA", "Apple, Inc." },
{ "8C579B", "Wistron Neweb Corporation" },
{ "B436A9", "Fibocom Wireless Inc. " },
{ "6416F0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "48DB50", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2400BA", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "68DBCA", "Apple, Inc." },
{ "044BED", "Apple, Inc." },
{ "3CBB73", "Shenzhen Xinguodu Technology Co., Ltd." },
{ "3CCF5B", "ICOMM HK LIMITED" },
{ "F40304", "Google, Inc." },
{ "78ACC0", "Hewlett Packard" },
{ "3C9066", "SmartRG, Inc." },
{ "00195B", "D-Link Corporation" },
{ "000D88", "D-Link Corporation" },
{ "001346", "D-Link Corporation" },
{ "0021BA", "Texas Instruments" },
{ "0022A5", "Texas Instruments" },
{ "0024BA", "Texas Instruments" },
{ "D03761", "Texas Instruments" },
{ "0017E4", "Texas Instruments" },
{ "5C6B32", "Texas Instruments" },
{ "1C4593", "Texas Instruments" },
{ "84DD20", "Texas Instruments" },
{ "883314", "Texas Instruments" },
{ "0017EB", "Texas Instruments" },
{ "C4EDBA", "Texas Instruments" },
{ "34B1F7", "Texas Instruments" },
{ "C8A030", "Texas Instruments" },
{ "205532", "Gotech International Technology Limited" },
{ "002401", "D-Link Corporation" },
{ "1CAFF7", "D-Link International" },
{ "B8A386", "D-Link International" },
{ "C8D3A3", "D-Link International" },
{ "F4FC32", "Texas Instruments" },
{ "649C8E", "Texas Instruments" },
{ "D8952F", "Texas Instruments" },
{ "001833", "Texas Instruments" },
{ "4419B6", "Hangzhou Hikvision Digital Technology Co.,Ltd." },
{ "C056E3", "Hangzhou Hikvision Digital Technology Co.,Ltd." },
{ "C8E7D8", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "E01C41", "Aerohive Networks Inc." },
{ "D854A2", "Aerohive Networks Inc." },
{ "9CEFD5", "Panda Wireless, Inc." },
{ "C02C7A", "Shenzhen Horn Audio Co.,Ltd." },
{ "88B8D0", "Dongguan Koppo Electronic Co.,Ltd" },
{ "38E7D8", "HTC Corporation" },
{ "D8B377", "HTC Corporation" },
{ "B4CEF6", "HTC Corporation" },
{ "D40B1A", "HTC Corporation" },
{ "A08D16", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2C8158", "Hon Hai Precision Ind. Co.,Ltd." },
{ "601888", "zte corporation" },
{ "8002DF", "ORA Inc." },
{ "D8FC38", "Giantec Semiconductor Inc" },
{ "2C6798", "InTalTech Ltd." },
{ "D0BF9C", "Hewlett Packard" },
{ "B05ADA", "Hewlett Packard" },
{ "001083", "Hewlett Packard" },
{ "0001E6", "Hewlett Packard" },
{ "C44044", "RackTop Systems Inc." },
{ "3898D8", "MERITECH CO.,LTD" },
{ "C8675E", "Aerohive Networks Inc." },
{ "000CF1", "Intel Corporation" },
{ "000E0C", "Intel Corporation" },
{ "BC0F64", "Intel Corporate" },
{ "6CA100", "Intel Corporate" },
{ "94659C", "Intel Corporate" },
{ "1002B5", "Intel Corporate" },
{ "A468BC", "Private" },
{ "001DCF", "ARRIS Group, Inc." },
{ "001DD5", "ARRIS Group, Inc." },
{ "001DD0", "ARRIS Group, Inc." },
{ "5C571A", "ARRIS Group, Inc." },
{ "441EA1", "Hewlett Packard" },
{ "D8D385", "Hewlett Packard" },
{ "18A905", "Hewlett Packard" },
{ "00237D", "Hewlett Packard" },
{ "002655", "Hewlett Packard" },
{ "001438", "Hewlett Packard" },
{ "001560", "Hewlett Packard" },
{ "288023", "Hewlett Packard" },
{ "645106", "Hewlett Packard" },
{ "5CB901", "Hewlett Packard" },
{ "DC4A3E", "Hewlett Packard" },
{ "2C59E5", "Hewlett Packard" },
{ "9CB654", "Hewlett Packard" },
{ "38EAA7", "Hewlett Packard" },
{ "E83935", "Hewlett Packard" },
{ "901ACA", "ARRIS Group, Inc." },
{ "E8ED05", "ARRIS Group, Inc." },
{ "90C792", "ARRIS Group, Inc." },
{ "789684", "ARRIS Group, Inc." },
{ "CC65AD", "ARRIS Group, Inc." },
{ "986B3D", "ARRIS Group, Inc." },
{ "08EB74", "HUMAX Co., Ltd." },
{ "6CB56B", "HUMAX Co., Ltd." },
{ "940937", "HUMAX Co., Ltd." },
{ "403DEC", "HUMAX Co., Ltd." },
{ "E84DD0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D81FCC", "Brocade Communications Systems, Inc." },
{ "140467", "SNK Technologies Co.,Ltd." },
{ "EC5F23", "Qinghai Kimascend Electronics Technology Co. Ltd." },
{ "047D50", "Shenzhen Kang Ying Technology Co.Ltd." },
{ "54EFFE", "Fullpower Technologies, Inc." },
{ "EC52DC", "WORLD MEDIA AND TECHNOLOGY Corp." },
{ "A4D18C", "Apple, Inc." },
{ "CC25EF", "Apple, Inc." },
{ "240995", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "247F3C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "1C8E5C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "94772B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F4E3FB", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "04021F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0034FE", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D02DB3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "086361", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F80113", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "70723C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "5C7D5E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4C8BEF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "20F3A3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "ACE87B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "688F84", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001AB6", "Texas Instruments" },
{ "D03972", "Texas Instruments" },
{ "7C669D", "Texas Instruments" },
{ "78A504", "Texas Instruments" },
{ "C4BE84", "Texas Instruments" },
{ "D05FB8", "Texas Instruments" },
{ "74D6EA", "Texas Instruments" },
{ "7CEC79", "Texas Instruments" },
{ "E0E5CF", "Texas Instruments" },
{ "ACF7F3", "Xiaomi Communications Co Ltd" },
{ "889471", "Brocade Communications Systems, Inc." },
{ "CC4E24", "Brocade Communications Systems, Inc." },
{ "50EB1A", "Brocade Communications Systems, Inc." },
{ "0027F8", "Brocade Communications Systems, Inc." },
{ "000533", "Brocade Communications Systems, Inc." },
{ "0060DF", "Brocade Communications Systems, Inc." },
{ "4CAC0A", "zte corporation" },
{ "0026ED", "zte corporation" },
{ "002293", "zte corporation" },
{ "FCD733", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "10A5D0", "Murata Manufacturing Co., Ltd." },
{ "D4C9B2", "Quanergy Systems Inc" },
{ "E4CE02", "WyreStorm Technologies Ltd" },
{ "2002AF", "Murata Manufacturing Co., Ltd." },
{ "0026E8", "Murata Manufacturing Co., Ltd." },
{ "001C26", "Hon Hai Precision Ind. Co.,Ltd." },
{ "00197D", "Hon Hai Precision Ind. Co.,Ltd." },
{ "90FBA6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "142D27", "Hon Hai Precision Ind. Co.,Ltd." },
{ "ECCB30", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "786A89", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "2008ED", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "509F27", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "CC96A0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "54A51B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F4C714", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "286ED4", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "A01290", "Avaya Inc" },
{ "F81547", "Avaya Inc" },
{ "506184", "Avaya Inc" },
{ "BCADAB", "Avaya Inc" },
{ "B4A95A", "Avaya Inc" },
{ "3C3A73", "Avaya Inc" },
{ "04F938", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "FC48EF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "80FB06", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "D4B110", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "CC53B5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "002127", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "54E6FC", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D85D4C", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F81A67", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F0F336", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "44B32D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F07816", "Cisco Systems, Inc" },
{ "001310", "Cisco-Linksys, LLC" },
{ "0023BE", "Cisco SPVTG" },
{ "54D46F", "Cisco SPVTG" },
{ "24374C", "Cisco SPVTG" },
{ "BCC810", "Cisco SPVTG" },
{ "484487", "Cisco SPVTG" },
{ "445829", "Cisco SPVTG" },
{ "481D70", "Cisco SPVTG" },
{ "00214F", "ALPS ELECTRIC CO.,LTD." },
{ "00E036", "PIONEER CORPORATION" },
{ "C83DFC", "PIONEER CORPORATION" },
{ "E0AE5E", "ALPS ELECTRIC CO.,LTD." },
{ "34C731", "ALPS ELECTRIC CO.,LTD." },
{ "60380E", "ALPS ELECTRIC CO.,LTD." },
{ "64D4BD", "ALPS ELECTRIC CO.,LTD." },
{ "00000C", "Cisco Systems, Inc" },
{ "004096", "Cisco Systems, Inc" },
{ "30F70D", "Cisco Systems, Inc" },
{ "B07D47", "Cisco Systems, Inc" },
{ "D8B190", "Cisco Systems, Inc" },
{ "F0B2E5", "Cisco Systems, Inc" },
{ "188B9D", "Cisco Systems, Inc" },
{ "38ED18", "Cisco Systems, Inc" },
{ "ECBD1D", "Cisco Systems, Inc" },
{ "DCCEC1", "Cisco Systems, Inc" },
{ "84B261", "Cisco Systems, Inc" },
{ "009EC8", "Xiaomi Communications Co Ltd" },
{ "7C1DD9", "Xiaomi Communications Co Ltd" },
{ "A086C6", "Xiaomi Communications Co Ltd" },
{ "584498", "Xiaomi Communications Co Ltd" },
{ "70E422", "Cisco Systems, Inc" },
{ "0050BD", "Cisco Systems, Inc" },
{ "009086", "Cisco Systems, Inc" },
{ "005054", "Cisco Systems, Inc" },
{ "3C0E23", "Cisco Systems, Inc" },
{ "001CC3", "Pace plc" },
{ "14D4FE", "Pace plc" },
{ "70B14E", "Pace plc" },
{ "707630", "Pace plc" },
{ "90E6BA", "ASUSTek COMPUTER INC." },
{ "BCAEC5", "ASUSTek COMPUTER INC." },
{ "10BF48", "ASUSTek COMPUTER INC." },
{ "A80C0D", "Cisco Systems, Inc" },
{ "B83861", "Cisco Systems, Inc" },
{ "6C9989", "Cisco Systems, Inc" },
{ "580A20", "Cisco Systems, Inc" },
{ "0050D1", "Cisco Systems, Inc" },
{ "00500B", "Cisco Systems, Inc" },
{ "005073", "Cisco Systems, Inc" },
{ "00603E", "Cisco Systems, Inc" },
{ "00E034", "Cisco Systems, Inc" },
{ "001868", "Cisco SPVTG" },
{ "887556", "Cisco Systems, Inc" },
{ "60735C", "Cisco Systems, Inc" },
{ "FC9947", "Cisco Systems, Inc" },
{ "7CC537", "Apple, Inc." },
{ "70CD60", "Apple, Inc." },
{ "24AB81", "Apple, Inc." },
{ "581FAA", "Apple, Inc." },
{ "A46706", "Apple, Inc." },
{ "3C0754", "Apple, Inc." },
{ "E4CE8F", "Apple, Inc." },
{ "E8040B", "Apple, Inc." },
{ "B8C75D", "Apple, Inc." },
{ "403CFC", "Apple, Inc." },
{ "286AB8", "Apple, Inc." },
{ "7CC3A1", "Apple, Inc." },
{ "00E16D", "Cisco Systems, Inc" },
{ "F8C288", "Cisco Systems, Inc" },
{ "E0ACF1", "Cisco Systems, Inc" },
{ "FC5B39", "Cisco Systems, Inc" },
{ "346F90", "Cisco Systems, Inc" },
{ "E0D173", "Cisco Systems, Inc" },
{ "74A02F", "Cisco Systems, Inc" },
{ "547C69", "Cisco Systems, Inc" },
{ "689CE2", "Cisco Systems, Inc" },
{ "40A6E8", "Cisco Systems, Inc" },
{ "B8782E", "Apple, Inc." },
{ "000502", "Apple, Inc." },
{ "0010FA", "Apple, Inc." },
{ "000393", "Apple, Inc." },
{ "0016CB", "Apple, Inc." },
{ "0017F2", "Apple, Inc." },
{ "001B63", "Apple, Inc." },
{ "001EC2", "Apple, Inc." },
{ "002608", "Apple, Inc." },
{ "7C6D62", "Apple, Inc." },
{ "40D32D", "Apple, Inc." },
{ "D83062", "Apple, Inc." },
{ "C42C03", "Apple, Inc." },
{ "6C2056", "Cisco Systems, Inc" },
{ "BC1665", "Cisco Systems, Inc" },
{ "44ADD9", "Cisco Systems, Inc" },
{ "0C2724", "Cisco Systems, Inc" },
{ "6C416A", "Cisco Systems, Inc" },
{ "F872EA", "Cisco Systems, Inc" },
{ "0C6803", "Cisco Systems, Inc" },
{ "789F70", "Apple, Inc." },
{ "DC3714", "Apple, Inc." },
{ "40331A", "Apple, Inc." },
{ "94F6A3", "Apple, Inc." },
{ "D81D72", "Apple, Inc." },
{ "70ECE4", "Apple, Inc." },
{ "38C986", "Apple, Inc." },
{ "FCFC48", "Apple, Inc." },
{ "2857BE", "Hangzhou Hikvision Digital Technology Co.,Ltd." },
{ "50D59C", "Thai Habel Industrial Co., Ltd." },
{ "FCA386", "SHENZHEN CHUANGWEI-RGB ELECTRONICS CO.,LTD" },
{ "F0F249", "Hitron Technologies. Inc" },
{ "A4C361", "Apple, Inc." },
{ "AC7F3E", "Apple, Inc." },
{ "280B5C", "Apple, Inc." },
{ "90B931", "Apple, Inc." },
{ "24A2E1", "Apple, Inc." },
{ "80EA96", "Apple, Inc." },
{ "600308", "Apple, Inc." },
{ "04F13E", "Apple, Inc." },
{ "54724F", "Apple, Inc." },
{ "48746E", "Apple, Inc." },
{ "3CAB8E", "Apple, Inc." },
{ "7C6DF8", "Apple, Inc." },
{ "48D705", "Apple, Inc." },
{ "3CD0F8", "Apple, Inc." },
{ "98D6BB", "Apple, Inc." },
{ "4CB199", "Apple, Inc." },
{ "64E682", "Apple, Inc." },
{ "804971", "Apple, Inc." },
{ "98FE94", "Apple, Inc." },
{ "D8004D", "Apple, Inc." },
{ "98B8E3", "Apple, Inc." },
{ "80929F", "Apple, Inc." },
{ "885395", "Apple, Inc." },
{ "9C04EB", "Apple, Inc." },
{ "78FD94", "Apple, Inc." },
{ "C88550", "Apple, Inc." },
{ "D4F46F", "Apple, Inc." },
{ "787E61", "Apple, Inc." },
{ "60F81D", "Apple, Inc." },
{ "4C7C5F", "Apple, Inc." },
{ "48E9F1", "Apple, Inc." },
{ "FCE998", "Apple, Inc." },
{ "F099BF", "Apple, Inc." },
{ "68644B", "Apple, Inc." },
{ "A8968A", "Apple, Inc." },
{ "4C8D79", "Apple, Inc." },
{ "207D74", "Apple, Inc." },
{ "F4F15A", "Apple, Inc." },
{ "042665", "Apple, Inc." },
{ "2CB43A", "Apple, Inc." },
{ "689C70", "Apple, Inc." },
{ "087045", "Apple, Inc." },
{ "CCE0C3", "Mangstor, Inc." },
{ "84A423", "Sagemcom Broadband SAS" },
{ "346987", "zte corporation" },
{ "58685D", "Tempo Australia Pty Ltd" },
{ "789C85", "August Home, Inc." },
{ "FCCF43", "HUIZHOU CITY HUIYANG DISTRICT MEISIQI INDUSTRY DEVELOPMENT CO,.LTD" },
{ "5882A8", "Microsoft" },
{ "B4EF04", "DAIHAN Scientific Co., Ltd." },
{ "049645", "WUXI SKY CHIP INTERCONNECTION TECHNOLOGY CO.,LTD." },
{ "5CE3B6", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "9C88AD", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "C8C2C6", "Shanghai Airm2m Communication Technology Co., Ltd" },
{ "EC64E7", "MOCACARE Corporation" },
{ "D07C2D", "Leie IOT technology Co., Ltd" },
{ "40862E", "JDM MOBILE INTERNET SOLUTION CO., LTD." },
{ "EC388F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "BC9C31", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "90C99B", "Recore Systems" },
{ "5CB559", "CNEX Labs" },
{ "5CCF7F", "Espressif Inc." },
{ "380546", "Foctek Photonics, Inc." },
{ "6858C5", "ZF TRW Automotive" },
{ "044169", "GoPro" },
{ "ACC51B", "Zhuhai Pantum Electronics Co., Ltd." },
{ "4473D6", "Logitech" },
{ "E80734", "Champion Optical Network Engineering, LLC" },
{ "D02544", "Samsung Electro Mechanics co., LTD." },
{ "6CEBB2", "Dongguan Sen DongLv Electronics Co.,Ltd" },
{ "A03299", "Lenovo (Beijing) Co., Ltd." },
{ "A845CD", "Siselectron Technology LTD." },
{ "D0C193", "SKYBELL, INC" },
{ "209BCD", "Apple, Inc." },
{ "F0B0E7", "Apple, Inc." },
{ "A09169", "LG Electronics" },
{ "CC20E8", "Apple, Inc." },
{ "E435C8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "38FF36", "Ruckus Wireless" },
{ "D47208", "Bragi GmbH" },
{ "489A42", "Technomate Ltd" },
{ "B49D0B", "BQ" },
{ "98CB27", "Galore Networks Pvt. Ltd." },
{ "30D32D", "devolo AG" },
{ "CC794A", "BLU Products Inc." },
{ "60FD56", "WOORISYSTEMS CO., Ltd" },
{ "7CFE90", "Mellanox Technologies, Inc." },
{ "483974", "Proware Technologies Co., Ltd." },
{ "E855B4", "SAI Technology Inc." },
{ "9CA69D", "Whaley Technology Co.Ltd" },
{ "342606", "CarePredict, Inc." },
{ "B4AE2B", "Microsoft" },
{ "80EB77", "Wistron Corporation" },
{ "B88981", "Chengdu InnoThings Technology Co., Ltd." },
{ "B4293D", "Shenzhen Urovo Technology Co.,Ltd." },
{ "906FA9", "NANJING PUTIAN TELECOMMUNICATIONS TECHNOLOGY CO.,LTD." },
{ "14B370", "Gigaset Digital Technology (Shenzhen) Co., Ltd." },
{ "FC2FEF", "UTT Technologies Co., Ltd." },
{ "EC21E5", "Toshiba" },
{ "44FDA3", "Everysight LTD." },
{ "84D4C8", "Widex A/S" },
{ "247260", "IOTTECH Corp" },
{ "44975A", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "584822", "Sony Mobile Communications AB" },
{ "F8BF09", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "B4B265", "DAEHO I&T" },
{ "081FEB", "BinCube" },
{ "785F4C", "Argox Information Co., Ltd." },
{ "E866C4", "Datawise Systems" },
{ "5870C6", "Shanghai Xiaoyi Technology Co., Ltd." },
{ "803B2A", "ABB Xiamen Low Voltage Equipment Co.,Ltd." },
{ "A0A65C", "Supercomputing Systems AG" },
{ "5CB395", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C412F5", "D-Link International" },
{ "44F436", "zte corporation" },
{ "349B5B", "Maquet GmbH" },
{ "E861BE", "Melec Inc." },
{ "54B80A", "D-Link International" },
{ "D8ADDD", "Sonavation, Inc." },
{ "C09A71", "XIAMEN MEITU MOBILE TECHNOLOGY CO.LTD" },
{ "340B40", "MIOS ELETTRONICA SRL" },
{ "944A0C", "Sercomm Corporation" },
{ "D02516", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "D05C7A", "Sartura d.o.o." },
{ "583F54", "LG Electronics (Mobile Communications)" },
{ "9C37F4", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "5CEB68", "Cheerstar Technology Co., Ltd" },
{ "F46A92", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "14AEDB", "VTech Telecommunications Ltd." },
{ "EC4F82", "Calix Inc." },
{ "B8C3BF", "Henan Chengshi NetWork Technology Co.，Ltd" },
{ "C0EE40", "Laird Technologies" },
{ "F0182B", "LG Chem" },
{ "CC5FBF", "Topwise 3G Communication Co., Ltd." },
{ "14DDA9", "ASUSTek COMPUTER INC." },
{ "485D36", "Verizon" },
{ "EC60E0", "AVI-ON LABS" },
{ "145A83", "Logi-D inc" },
{ "4CEEB0", "SHC Netzwerktechnik GmbH" },
{ "188EF9", "G2C Co. Ltd." },
{ "809FAB", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "D00492", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "F4E9D4", "QLogic Corporation" },
{ "1422DB", "eero inc." },
{ "0C413E", "Microsoft Corporation" },
{ "007E56", "China Dragon Technology Limited" },
{ "086266", "ASUSTek COMPUTER INC." },
{ "346C0F", "Pramod Telecom Pvt. Ltd" },
{ "3C912B", "Vexata Inc" },
{ "54369B", "1Verge Internet Technology (Beijing) Co., Ltd." },
{ "E4FED9", "EDMI Europe Ltd" },
{ "2852E0", "Layon international Electronic & Telecom Co.,Ltd" },
{ "E48501", "Geberit International AG" },
{ "1C3947", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "2CAD13", "SHENZHEN ZHILU TECHNOLOGY CO.,LTD" },
{ "68B983", "b-plus GmbH" },
{ "BC74D7", "HangZhou JuRu Technology CO.,LTD" },
{ "E88E60", "NSD Corporation" },
{ "545146", "AMG Systems Ltd." },
{ "84DDB7", "Cilag GmbH International" },
{ "78EB14", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "D05BA8", "zte corporation" },
{ "8CE78C", "DK Networks" },
{ "E4BAD9", "360 Fly Inc." },
{ "7C3CB6", "Shenzhen Homecare Technology Co.,Ltd." },
{ "BCE767", "Quanzhou  TDX Electronics Co., Ltd" },
{ "6CA7FA", "YOUNGBO ENGINEERING INC." },
{ "D0929E", "Microsoft Corporation" },
{ "F4032F", "Reduxio Systems" },
{ "84CFBF", "Fairphone" },
{ "AC9E17", "ASUSTek COMPUTER INC." },
{ "ACC73F", "VITSMO CO., LTD." },
{ "505527", "LG Electronics" },
{ "18BDAD", "L-TECH CORPORATION" },
{ "44D244", "Seiko Epson Corporation" },
{ "10C07C", "Blu-ray Disc Association" },
{ "B87879", "Roche Diagnostics GmbH" },
{ "4480EB", "Motorola Mobility LLC, a Lenovo Company" },
{ "D06F4A", "TOPWELL INTERNATIONAL HOLDINGS LIMITED" },
{ "BC54F9", "Drogoo Technology Co., Ltd." },
{ "349E34", "Evervictory Electronic Co.Ltd" },
{ "A0C2DE", "Costar Video Systems" },
{ "3809A4", "Firefly Integrations" },
{ "00A509", "WigWag Inc." },
{ "A86405", "nimbus 9, Inc" },
{ "7076FF", "KERLINK" },
{ "68F0BC", "Shenzhen LiWiFi Technology Co., Ltd" },
{ "BCD165", "Cisco SPVTG" },
{ "4CA928", "Insensi" },
{ "2884FA", "SHARP Corporation" },
{ "3C1E04", "D-Link International" },
{ "E0FFF7", "Softiron Inc." },
{ "DC60A1", "Teledyne DALSA Professional Imaging" },
{ "78E980", "RainUs Co.,Ltd" },
{ "7C8274", "Shenzhen Hikeen Technology CO.,LTD" },
{ "B40566", "SP Best Corporation Co., LTD." },
{ "70AD54", "Malvern Instruments Ltd" },
{ "DCE026", "Patrol Tag, Inc" },
{ "EC3C88", "MCNEX Co.,Ltd." },
{ "F07959", "ASUSTek COMPUTER INC." },
{ "E08E3C", "Aztech Electronics Pte Ltd" },
{ "78A351", "SHENZHEN ZHIBOTONG ELECTRONICS CO.,LTD" },
{ "34FCEF", "LG Electronics" },
{ "94E2FD", "Boge Kompressoren OTTO Boge GmbH & Co. KG" },
{ "E4695A", "Dictum Health, Inc." },
{ "D46132", "Pro Concept Manufacturer Co.,Ltd." },
{ "54A050", "ASUSTek COMPUTER INC." },
{ "841826", "Osram GmbH" },
{ "14F893", "Wuhan FiberHome Digital Technology Co.,Ltd." },
{ "9816EC", "IC Intracom" },
{ "DCDA4F", "GETCK TECHNOLOGY,  INC" },
{ "30FAB7", "Tunai Creative" },
{ "0809B6", "Masimo Corp" },
{ "14EDE4", "Kaiam Corporation" },
{ "3438AF", "Inlab Software GmbH" },
{ "049B9C", "Eadingcore  Intelligent Technology Co., Ltd." },
{ "842690", "BEIJING THOUGHT SCIENCE CO.,LTD." },
{ "B84FD5", "Microsoft Corporation" },
{ "587BE9", "AirPro Technology India Pvt. Ltd" },
{ "FC1D84", "Autobase" },
{ "4CE933", "RailComm, LLC" },
{ "6050C1", "Kinetek Sports" },
{ "003560", "Rosen Aviation" },
{ "EC59E7", "Microsoft Corporation" },
{ "08EFAB", "SAYME WIRELESS SENSOR NETWORK" },
{ "C81B6B", "Innova Security" },
{ "5C966A", "RTNET" },
{ "2C5089", "Shenzhen Kaixuan Visual Technology Co.,Limited" },
{ "A89DD2", "Shanghai DareGlobal Technologies Co., Ltd" },
{ "EC13B2", "Netonix" },
{ "74BADB", "Longconn Electornics(shenzhen)Co.,Ltd" },
{ "4C7403", "BQ" },
{ "5876C5", "DIGI I'S LTD" },
{ "00A2F5", "Guangzhou Yuanyun Network Technology Co.,Ltd" },
{ "70FC8C", "OneAccess SA" },
{ "2C600C", "QUANTA COMPUTER INC." },
{ "902CC7", "C-MAX Asia Limited" },
{ "1C965A", "Weifang goertek Electronics CO.,LTD" },
{ "188219", "Alibaba Cloud Computing Ltd." },
{ "B41780", "DTI Group Ltd" },
{ "D437D7", "zte corporation" },
{ "AC3870", "Lenovo Mobile Communication Technology Ltd." },
{ "80EACA", "Dialog Semiconductor Hellas SA" },
{ "60512C", "TCT mobile limited" },
{ "4CBC42", "Shenzhen Hangsheng Electronics Co.,Ltd." },
{ "D82522", "Pace plc" },
{ "987E46", "Emizon Networks Limited" },
{ "8432EA", "ANHUI WANZTEN P&T CO., LTD" },
{ "ACA213", "Shenzhen Bilian electronic CO.,LTD" },
{ "90B686", "Murata Manufacturing Co., Ltd." },
{ "4C6E6E", "Comnect Technology CO.,LTD" },
{ "F4DD9E", "GoPro" },
{ "40B3CD", "Chiyoda Electronics Co.,Ltd." },
{ "3451AA", "JID GLOBAL" },
{ "04572F", "Sertel Electronics UK Ltd" },
{ "08B2A3", "Cynny Italia S.r.L." },
{ "D8977C", "Grey Innovation" },
{ "80AD67", "Kasda Networks Inc" },
{ "9CAD97", "Hon Hai Precision Ind. Co.,Ltd." },
{ "30595B", "streamnow AG" },
{ "B8AD3E", "BLUECOM" },
{ "10C37B", "ASUSTek COMPUTER INC." },
{ "48D855", "Telvent" },
{ "284ED7", "OutSmart Power Systems, Inc." },
{ "5C5BC2", "YIK Corporation" },
{ "184A6F", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "EC8A4C", "zte corporation" },
{ "340AFF", "Qingdao Hisense Communications Co.,Ltd" },
{ "8014A8", "Guangzhou V-SOLUTION Electronic Technology Co., Ltd." },
{ "908C63", "GZ Weedong Networks Technology Co. , Ltd" },
{ "B49EAC", "Imagik Int'l Corp" },
{ "C8E42F", "Technical Research Design and Development" },
{ "FC2325", "EosTek (Shenzhen) Co., Ltd." },
{ "485929", "LG Electronics" },
{ "A81374", "Panasonic Corporation AVC Networks Company" },
{ "4C83DE", "Cisco SPVTG" },
{ "5CB6CC", "NovaComm Technologies Inc." },
{ "B4AE6F", "Circle Reliance, Inc DBA Cranberry Networks" },
{ "B89919", "7signal Solutions, Inc" },
{ "90DA6A", "FOCUS H&S Co., Ltd." },
{ "A45DA1", "ADB Broadband Italia" },
{ "A43D78", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "E8EF89", "OPMEX Tech." },
{ "F4C447", "Coagent International Enterprise Limited" },
{ "08DF1F", "Bose Corporation" },
{ "542AA2", "Alpha Networks Inc." },
{ "58238C", "Technicolor CH USA" },
{ "84948C", "Hitron Technologies. Inc" },
{ "CCA0E5", "DZG Metering GmbH" },
{ "3059B7", "Microsoft" },
{ "80414E", "BBK Electronics Corp., Ltd.," },
{ "0874F6", "Winterhalter Gastronom GmbH" },
{ "FCC2DE", "Murata Manufacturing Co., Ltd." },
{ "1C1CFD", "Dalian Hi-Think Computer Technology, Corp" },
{ "7062B8", "D-Link International" },
{ "B875C0", "PayPal, Inc." },
{ "E47FB2", "FUJITSU LIMITED" },
{ "38262B", "UTran Technology" },
{ "20ED74", "Ability enterprise co.,Ltd." },
{ "982F3C", "Sichuan Changhong Electric Ltd." },
{ "7824AF", "ASUSTek COMPUTER INC." },
{ "0CAC05", "Unitend Technologies Inc." },
{ "B4B859", "Texa Spa" },
{ "045C8E", "gosund GROUP CO.,LTD" },
{ "54B753", "Hunan Fenghui Yinjia Science And Technology Co.,Ltd" },
{ "4826E8", "Tek-Air Systems, Inc." },
{ "A012DB", "TABUCHI ELECTRIC CO.,LTD" },
{ "ACB859", "Uniband Electronic Corp," },
{ "100F18", "Fu Gang Electronic(KunShan)CO.,LTD" },
{ "C8D590", "FLIGHT DATA SYSTEMS" },
{ "709383", "Intelligent Optical Network High Tech CO.,LTD." },
{ "3CCD93", "LG ELECTRONICS INC" },
{ "6047D4", "FORICS Electronic Technology Co., Ltd." },
{ "C09D26", "Topicon HK Lmd." },
{ "B061C7", "Ericsson-LG Enterprise" },
{ "B05706", "Vallox Oy" },
{ "C8D429", "Muehlbauer AG" },
{ "20EAC7", "SHENZHEN RIOPINE ELECTRONICS CO., LTD" },
{ "80618F", "Shenzhen sangfei consumer communications co.,ltd" },
{ "5CF50D", "Institute of microelectronic applications" },
{ "10DEE4", "automationNEXT GmbH" },
{ "444891", "HDMI Licensing, LLC" },
{ "FC923B", "Nokia Corporation" },
{ "38F708", "National Resource Management, Inc." },
{ "C4C919", "Energy Imports Ltd" },
{ "88A73C", "Ragentek Technology Group" },
{ "B0D7C5", "Logipix Ltd" },
{ "38C9A9", "SMART High Reliability Solutions, Inc." },
{ "BC1A67", "YF Technology Co., Ltd" },
{ "B024F3", "Progeny Systems" },
{ "8C4DB9", "Unmonday Ltd" },
{ "D87CDD", "SANIX INCORPORATED" },
{ "F8A2B4", "RHEWA-WAAGENFABRIK August Freudewald GmbH &amp;Co. KG" },
{ "84FE9E", "RTC Industries, Inc." },
{ "403067", "Conlog (Pty) Ltd" },
{ "98DA92", "Vuzix Corporation" },
{ "5C2AEF", "Open Access Pty Ltd" },
{ "E40439", "TomTom Software Ltd" },
{ "90AE1B", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "441E91", "ARVIDA Intelligent Electronics Technology  Co.,Ltd." },
{ "6C14F7", "Erhardt+Leimer GmbH" },
{ "70F96D", "Hangzhou H3C Technologies Co., Limited" },
{ "CC07E4", "Lenovo Mobile Communication Technology Ltd." },
{ "B4430D", "Broadlink Pty Ltd" },
{ "A4BBAF", "Lime Instruments" },
{ "7CE1FF", "Computer Performance, Inc. DBA Digital Loggers, Inc." },
{ "D069D0", "Verto Medical Solutions, LLC" },
{ "ACE069", "ISAAC Instruments" },
{ "E8EA6A", "StarTech.com" },
{ "C4E984", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "8059FD", "Noviga" },
{ "18FF2E", "Shenzhen Rui Ying Da Technology Co., Ltd" },
{ "1CAB01", "Innovolt" },
{ "68856A", "OuterLink Corporation" },
{ "30F42F", "ESP" },
{ "C816BD", "HISENSE ELECTRIC CO.,LTD." },
{ "746A8F", "VS Vision Systems GmbH" },
{ "B068B6", "Hangzhou OYE Technology Co. Ltd" },
{ "9C65F9", "AcSiP Technology Corp." },
{ "487604", "Private" },
{ "D057A1", "Werma Signaltechnik GmbH & Co. KG" },
{ "3C89A6", "KAPELSE" },
{ "90F1B0", "Hangzhou Anheng Info&Tech CO.,LTD" },
{ "9C86DA", "Phoenix Geophysics Ltd." },
{ "48FEEA", "HOMA B.V." },
{ "10DDF4", "Maxway Electronics CO.,LTD" },
{ "080371", "KRG CORPORATE" },
{ "B43A28", "Samsung Electronics Co.,Ltd" },
{ "ACC595", "Graphite Systems" },
{ "3413A8", "Mediplan Limited" },
{ "4CD9C4", "Magneti Marelli Automotive Electronics (Guangzhou) Co. Ltd" },
{ "743ECB", "Gentrice tech" },
{ "7071B3", "Brain Corporation" },
{ "208986", "zte corporation" },
{ "3CD4D6", "WirelessWERX, Inc" },
{ "64E625", "Woxu Wireless Co., Ltd" },
{ "7C444C", "Entertainment Solutions, S.L." },
{ "501AC5", "Microsoft" },
{ "609620", "Private" },
{ "F8572E", "Core Brands, LLC" },
{ "E0E631", "SNB TECHNOLOGIES LIMITED" },
{ "9401C2", "Samsung Electronics Co.,Ltd" },
{ "20C60D", "Shanghai annijie Information technology Co.,LTD" },
{ "7C9763", "Openmatics s.r.o." },
{ "0444A1", "TELECON GALICIA,S.A." },
{ "84569C", "Coho Data, Inc.," },
{ "78AE0C", "Far South Networks" },
{ "38CA97", "Contour Design LLC" },
{ "84A783", "Alcatel Lucent" },
{ "2C5D93", "Ruckus Wireless" },
{ "1CC11A", "Wavetronix" },
{ "4CF02E", "Vifa Denmark A/S" },
{ "3051F8", "BYK-Gardner GmbH" },
{ "94C3E4", "SCA Schucker Gmbh & Co KG" },
{ "FC19D0", "Cloud Vision Networks Technology Co.,Ltd." },
{ "20E791", "Siemens Healthcare Diagnostics, Inc" },
{ "68764F", "Sony Mobile Communications AB" },
{ "D4D919", "GoPro" },
{ "50C9A0", "SKIPPER Electronics AS" },
{ "A49F89", "Shanghai Rui Rui Communication Technology Co.Ltd." },
{ "D850E6", "ASUSTek COMPUTER INC." },
{ "94103E", "Belkin International Inc." },
{ "B4750E", "Belkin International Inc." },
{ "346178", "The Boeing Company" },
{ "187ED5", "shenzhen kaism technology Co. Ltd" },
{ "841B38", "Shenzhen Excelsecu Data Technology Co.,Ltd" },
{ "EC2AF0", "Ypsomed AG" },
{ "044F8B", "Adapteva, Inc." },
{ "9CE7BD", "Winduskorea co., Ltd" },
{ "3842A6", "Ingenieurbuero Stahlkopf" },
{ "A0BF50", "S.C. ADD-PRODUCTION S.R.L." },
{ "7CB733", "ASKEY COMPUTER CORP" },
{ "705957", "Medallion Instrumentation Systems" },
{ "6C8366", "Nanjing SAC Power Grid Automation Co., Ltd." },
{ "88576D", "XTA Electronics Ltd" },
{ "F83D4E", "Softlink Automation System Co., Ltd" },
{ "FCD817", "Beijing Hesun Technologies Co.Ltd." },
{ "909F43", "Accutron Instruments Inc." },
{ "C42795", "Technicolor USA Inc." },
{ "50C006", "Carmanah Signs" },
{ "98FB12", "Grand Electronics (HK) Ltd" },
{ "3C1040", "daesung network" },
{ "B04545", "YACOUB Automation GmbH" },
{ "701D7F", "Comtech Technology Co., Ltd." },
{ "60DB2A", "HNS" },
{ "7CBF88", "Mobilicom LTD" },
{ "90028A", "Shenzhen Shidean Legrand Electronic Products Co.,Ltd" },
{ "4C3C16", "Samsung Electronics Co.,Ltd" },
{ "90356E", "Vodafone Omnitel N.V." },
{ "3CCA87", "Iders Incorporated" },
{ "08CA45", "Toyou Feiji Electronics Co., Ltd." },
{ "9CA9E4", "zte corporation" },
{ "E47723", "zte corporation" },
{ "C098E5", "University of Michigan" },
{ "B8DF6B", "SpotCam Co., Ltd." },
{ "742B62", "FUJITSU LIMITED" },
{ "A0143D", "PARROT SA" },
{ "58BDF9", "Sigrand" },
{ "344F3F", "IO-Power Technology Co., Ltd." },
{ "C0C687", "Cisco SPVTG" },
{ "142BD2", "Armtel Ltd." },
{ "F845AD", "Konka Group Co., Ltd." },
{ "54A54B", "NSC Communications Siberia Ltd" },
{ "BC2B6B", "Beijing Haier IC Design Co.,Ltd" },
{ "642184", "Nippon Denki Kagaku Co.,LTD" },
{ "EC3E09", "PERFORMANCE DESIGNED PRODUCTS, LLC" },
{ "EC219F", "VidaBox LLC" },
{ "98D331", "Shenzhen Bolutek Technology Co.,Ltd." },
{ "3C1A57", "Cardiopulmonary Corp" },
{ "6CF97C", "Nanoptix Inc." },
{ "58E02C", "Micro Technic A/S" },
{ "E481B3", "Shenzhen ACT Industrial Co.,Ltd." },
{ "BC8556", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E4F3E3", "Shanghai iComhome Co.,Ltd." },
{ "04CF25", "MANYCOLORS, INC." },
{ "D41090", "iNFORM Systems AG" },
{ "3495DB", "Logitec Corporation" },
{ "88142B", "Protonic Holland" },
{ "B8241A", "SWEDA INFORMATICA LTDA" },
{ "3806B4", "A.D.C. GmbH" },
{ "341B22", "Grandbeing Technology Co., Ltd" },
{ "B4346C", "MATSUNICHI DIGITAL TECHNOLOGY (HONG KONG) LIMITED" },
{ "9C1465", "Edata Elektronik San. ve Tic. A.Ş." },
{ "C45444", "QUANTA COMPUTER INC." },
{ "587A4D", "Stonesoft Corporation" },
{ "E89218", "Arcontia International AB" },
{ "58F387", "HCCP" },
{ "B0793C", "Revolv Inc" },
{ "D022BE", "Samsung Electro Mechanics co.,LTD." },
{ "20CEC4", "Peraso Technologies" },
{ "04848A", "7INOVA TECHNOLOGY LIMITED" },
{ "94D771", "Samsung Electronics Co.,Ltd" },
{ "20C6EB", "Panasonic Corporation AVC Networks Company" },
{ "700FEC", "Poindus Systems Corp." },
{ "78D5B5", "NAVIELEKTRO KY" },
{ "E067B3", "C-Data Technology Co., Ltd" },
{ "B887A8", "Step Ahead Innovations Inc." },
{ "140D4F", "Flextronics International" },
{ "B847C6", "SanJet Technology Corp." },
{ "CC3540", "Technicolor USA Inc." },
{ "4CDF3D", "TEAM ENGINEERS ADVANCE TECHNOLOGIES INDIA PVT LTD" },
{ "B85E7B", "Samsung Electronics Co.,Ltd" },
{ "70F176", "Data Modul AG" },
{ "205721", "Salix Technology CO., Ltd." },
{ "704CED", "TMRG, Inc." },
{ "E8516E", "TSMART Inc." },
{ "A067BE", "Sicon s.r.l." },
{ "7C1AFC", "Dalian Co-Edifice Video Technology Co., Ltd" },
{ "C034B4", "Gigastone Corporation" },
{ "587E61", "Hisense Electric Co., Ltd" },
{ "74ADB7", "China Mobile Group Device Co.,Ltd." },
{ "C462EA", "Samsung Electronics Co.,Ltd" },
{ "DC6F00", "Livescribe, Inc." },
{ "D0737F", "Mini-Circuits" },
{ "A4D094", "Erwin Peters Systemtechnik GmbH" },
{ "0488E2", "Beats Electronics LLC" },
{ "D00EA4", "Porsche Cars North America" },
{ "F415FD", "Shanghai Pateo Electronic Equipment Manufacturing Co., Ltd." },
{ "2C9464", "Cincoze Co., Ltd." },
{ "B050BC", "SHENZHEN BASICOM ELECTRONIC CO.,LTD." },
{ "DC7014", "Private" },
{ "40BC73", "Cronoplast  S.L." },
{ "78303B", "Stephen Technologies Co.,Limited" },
{ "78F5E5", "BEGA Gantenbrink-Leuchten KG" },
{ "804B20", "Ventilation Control" },
{ "4007C0", "Railtec Systems GmbH" },
{ "94B8C5", "RuggedCom Inc." },
{ "8C3C07", "Skiva Technologies, Inc." },
{ "784B08", "f.robotics acquisitions ltd" },
{ "0C2D89", "QiiQ Communications Inc." },
{ "604A1C", "SUYIN Corporation" },
{ "3423BA", "Samsung Electro Mechanics co.,LTD." },
{ "A4D3B5", "GLITEL Stropkov, s.r.o." },
{ "A4F3C1", "Open Source Robotics Foundation, Inc." },
{ "6C8B2F", "zte corporation" },
{ "B863BC", "ROBOTIS, Co, Ltd" },
{ "C8DDC9", "Lenovo Mobile Communication Technology Ltd." },
{ "CC1AFA", "zte corporation" },
{ "8C5AF0", "Exeltech Solar Products" },
{ "F8DADF", "EcoTech, Inc." },
{ "30AE7B", "Deqing Dusun Electron CO., LTD" },
{ "1441E2", "Monaco Enterprises, Inc." },
{ "F07765", "Sourcefire, Inc" },
{ "E4F7A1", "Datafox GmbH" },
{ "601E02", "EltexAlatau" },
{ "E47D5A", "Beijing Hanbang Technology Corp." },
{ "4C6255", "SANMINA-SCI SYSTEM DE MEXICO S.A. DE C.V." },
{ "381766", "PROMZAKAZ LTD." },
{ "204C6D", "Hugo Brennenstuhl Gmbh & Co. KG." },
{ "DC825B", "JANUS, spol. s r.o." },
{ "B08807", "Strata Worldwide" },
{ "9893CC", "LG Electronics Inc." },
{ "74D02B", "ASUSTek COMPUTER INC." },
{ "A4E0E6", "FILIZOLA S.A. PESAGEM E AUTOMACAO" },
{ "60E00E", "SHINSEI ELECTRONICS CO LTD" },
{ "30D46A", "Autosales Incorporated" },
{ "30AABD", "Shanghai Reallytek Information Technology Co.,Ltd" },
{ "A4B818", "PENTA Gesellschaft für elektronische Industriedatenverarbeitung mbH" },
{ "106682", "NEC Platforms, Ltd." },
{ "102831", "Morion Inc." },
{ "D81EDE", "B&W Group Ltd" },
{ "6897E8", "Society of Motion Picture &amp; Television Engineers" },
{ "24EA40", "Systeme Helmholz GmbH" },
{ "FC58FA", "Shen Zhen Shi Xin Zhong Xin Technology Co.,Ltd." },
{ "60601F", "SZ DJI TECHNOLOGY CO.,LTD" },
{ "E0C6B3", "MilDef AB" },
{ "FCDB96", "ENERVALLEY CO., LTD" },
{ "74258A", "Hangzhou H3C Technologies Co., Limited" },
{ "F06BCA", "Samsung Electronics Co.,Ltd" },
{ "FC8B97", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "882E5A", "storONE" },
{ "D429EA", "Zimory GmbH" },
{ "C80E95", "OmniLync Inc." },
{ "18DC56", "Yulong Computer Telecommunication Scientific(shenzhen)Co.,Lt" },
{ "50ABBF", "Hoseo Telecom" },
{ "8C7716", "LONGCHEER TELECOMMUNICATION LIMITED" },
{ "C8EEA6", "Shenzhen SHX Technology Co., Ltd" },
{ "28CBEB", "One" },
{ "18E8DD", "MODULETEK" },
{ "2C282D", "BBK COMMUNICATIAO TECHNOLOGY CO.,LTD." },
{ "4CCC34", "Motorola Solutions Inc." },
{ "F82FA8", "Hon Hai Precision Ind. Co.,Ltd." },
{ "F084C9", "zte corporation" },
{ "E894F6", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "94ACCA", "trivum technologies GmbH" },
{ "7CD844", "Enmotus Inc" },
{ "40B0FA", "LG Electronics" },
{ "F4C6D7", "blackned GmbH" },
{ "68A40E", "BSH Bosch and Siemens Home Appliances GmbH" },
{ "4CCA53", "Skyera, Inc." },
{ "081DFB", "Shanghai Mexon Communication Technology Co.,Ltd" },
{ "D0CDE1", "Scientech Electronics" },
{ "98D6F7", "LG Electronics" },
{ "94756E", "QinetiQ North America" },
{ "543D37", "Ruckus Wireless" },
{ "905F2E", "TCT Mobile Limited" },
{ "0C5521", "Axiros GmbH" },
{ "A4D856", "Gimbal, Inc" },
{ "10A743", "SK Mtek Limited" },
{ "E4A7FD", "Cellco Partnership" },
{ "24F2DD", "Radiant Zemax LLC" },
{ "80CF41", "Lenovo Mobile Communication Technology Ltd." },
{ "7C9A9B", "VSE valencia smart energy" },
{ "A845E9", "Firich Enterprises CO., LTD." },
{ "78995C", "Nationz Technologies Inc" },
{ "8CC5E1", "ShenZhen Konka Telecommunication Technology Co.,Ltd" },
{ "6CB311", "Shenzhen Lianrui Electronics Co.,Ltd" },
{ "54115F", "Atamo Pty Ltd" },
{ "2411D0", "Chongqing Ehs Science and Technology Development Co.,Ltd." },
{ "6C9AC9", "Valentine Research, Inc." },
{ "10F49A", "T3 Innovation" },
{ "1C5A3E", "Samsung Eletronics Co., Ltd (Visual Display Divison)" },
{ "5865E6", "INFOMARK CO., LTD." },
{ "BC20A4", "Samsung Electronics" },
{ "60BD91", "Move Innovation" },
{ "98473C", "SHANGHAI SUNMON COMMUNICATION TECHNOGY CO.,LTD" },
{ "CC4BFB", "Hellberg Safety AB" },
{ "ACA22C", "Baycity Technologies Ltd" },
{ "6CADEF", "KZ Broadband Technologies, Ltd. " },
{ "044BFF", "GuangZhou Hedy Digital Technology Co., Ltd" },
{ "949BFD", "Trans New Technology, Inc." },
{ "E4EEFD", "MR&D Manufacturing" },
{ "105CBF", "DuroByte Inc" },
{ "30C82A", "Wi-Next s.r.l." },
{ "88A3CC", "Amatis Controls" },
{ "EC89F5", "Lenovo Mobile Communication Technology Ltd." },
{ "083AB8", "Shinoda Plasma Co., Ltd." },
{ "A0DD97", "PolarLink Technologies, Ltd" },
{ "E05597", "Emergent Vision Technologies Inc." },
{ "A01917", "Bertel S.p.a." },
{ "FC9FAE", "Fidus Systems Inc" },
{ "FC0647", "Cortland Research, LLC" },
{ "20918A", "PROFALUX" },
{ "7C438F", "E-Band Communications Corp." },
{ "FC626E", "Beijing MDC Telecom" },
{ "C0B339", "Comigo Ltd." },
{ "DCC0DB", "Shenzhen Kaiboer Technology Co., Ltd." },
{ "7076DD", "Oxyguard International A/S" },
{ "E89AFF", "Fujian Landi Commercial Equipment Co.,Ltd" },
{ "683B1E", "Countwise LTD" },
{ "D4136F", "Asia Pacific Brands" },
{ "9C2A70", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A0A130", "DLI Taiwan Branch office" },
{ "38BC1A", "Meizu technology co.,ltd" },
{ "ECE915", "STI Ltd" },
{ "A81FAF", "KRYPTON POLSKA" },
{ "087BAA", "SVYAZKOMPLEKTSERVICE, LLC" },
{ "2C26C5", "zte corporation" },
{ "BC629F", "Telenet Systems P. Ltd." },
{ "F47B5E", "Samsung Eletronics Co., Ltd" },
{ "B47F5E", "Foresight Manufacture (S) Pte Ltd" },
{ "785517", "SankyuElectronics" },
{ "848E96", "Embertec Pty Ltd" },
{ "CC3A61", "SAMSUNG ELECTRO MECHANICS CO., LTD." },
{ "A00363", "Robert Bosch Healthcare GmbH" },
{ "4C8FA5", "Jastec" },
{ "F0F644", "Whitesky Science & Technology Co.,Ltd." },
{ "30D357", "Logosol, Inc." },
{ "14F42A", "Samsung Electronics" },
{ "2C441B", "Spectrum Medical Limited" },
{ "1C5A6B", "Philips Electronics Nederland BV" },
{ "A875D6", "FreeTek International Co., Ltd." },
{ "58EB14", "Proteus Digital Health" },
{ "789F87", "Siemens AG I IA PP PRM" },
{ "7C0A50", "J-MEX Inc." },
{ "40F2E9", "IBM" },
{ "9C0473", "Tecmobile (International) Ltd. " },
{ "CC262D", "Verifi, LLC" },
{ "3C8AE5", "Tensun Information Technology(Hangzhou) Co.,LTD" },
{ "7CB232", "Hui Zhou Gaoshengda Technology Co.,LTD" },
{ "54DF63", "Intrakey technologies GmbH" },
{ "7C0187", "Curtis Instruments, Inc." },
{ "388EE7", "Fanhattan LLC" },
{ "54F666", "Berthold Technologies GmbH and Co.KG" },
{ "802FDE", "Zurich Instruments AG" },
{ "08AF78", "Totus Solutions, Inc." },
{ "5C38E0", "Shanghai Super Electronics Technology Co.,LTD" },
{ "A0E534", "Stratec Biomedical AG" },
{ "2891D0", "Stage Tec Entwicklungsgesellschaft für professionelle Audiotechnik mbH" },
{ "A854B2", "Wistron Neweb Corp." },
{ "98291D", "Jaguar de Mexico, SA de CV" },
{ "18863A", "DIGITAL ART SYSTEM" },
{ "F4B72A", "TIME INTERCONNECT LTD" },
{ "34D7B4", "Tributary Systems, Inc." },
{ "F40F9B", "WAVELINK" },
{ "144319", "Creative&Link Technology Limited" },
{ "64F50E", "Kinion Technology Company Limited" },
{ "28A186", "enblink" },
{ "1C9492", "RUAG Schweiz AG" },
{ "24694A", "Jasmine Systems Inc." },
{ "C8C791", "Zero1.tv GmbH" },
{ "60748D", "Atmaca Elektronik" },
{ "78D129", "Vicos" },
{ "78AB60", "ABB Australia" },
{ "289A4B", "SteelSeries ApS" },
{ "0CC66A", "Nokia Corporation" },
{ "3078C2", "Innowireless, Co. Ltd." },
{ "58986F", "Revolution Display" },
{ "7CFE28", "Salutron Inc." },
{ "109FA9", "Actiontec Electronics, Inc" },
{ "C0A364", "3D Systems Massachusetts" },
{ "98A7B0", "MCST ZAO" },
{ "88DC96", "SENAO Networks, Inc." },
{ "4C0B3A", "TCT Mobile Limited" },
{ "C455C2", "Bach-Simpson" },
{ "ECA29B", "Kemppi Oy" },
{ "04CE14", "Wilocity LTD." },
{ "802AFA", "Germaneers GmbH" },
{ "1C8464", "FORMOSA WIRELESS COMMUNICATION CORP." },
{ "D867D9", "Cisco Systems, Inc" },
{ "B4218A", "Dog Hunter LLC" },
{ "F8A03D", "Dinstar Technologies Co., Ltd." },
{ "D08CFF", "UPWIS AB" },
{ "9C066E", "Hytera Communications Corporation Limited" },
{ "746A89", "Rezolt Corporation" },
{ "68D1FD", "Shenzhen Trimax Technology Co.,Ltd" },
{ "241B13", "Shanghai Nutshell Electronic Co., Ltd." },
{ "B43564", "Fujian Tian Cheng Electron Science & Technical Development Co.,Ltd." },
{ "54D1B0", "Universal Laser Systems, Inc" },
{ "A497BB", "Hitachi Industrial Equipment Systems Co.,Ltd" },
{ "FC52CE", "Control iD" },
{ "E804F3", "Throughtek Co., Ltd." },
{ "B85810", "NUMERA, INC." },
{ "2CAB25", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "AC6E1A", "Shenzhen Gongjin Electronics Co.,Ltd" },
{ "9886B1", "Flyaudio corporation (China)" },
{ "28B3AB", "Genmark Automation" },
{ "44E8A5", "Myreka Technologies Sdn. Bhd." },
{ "AC14D2", "wi-daq, inc." },
{ "9C4CAE", "Mesa Labs" },
{ "7CD9FE", "New Cosmos Electric Co., Ltd." },
{ "E49069", "Rockwell Automation" },
{ "B48910", "Coster T.E. S.P.A." },
{ "183919", "Unicoi Systems" },
{ "A4B1E9", "Technicolor" },
{ "30AEF6", "Radio Mobile Access" },
{ "58343B", "Glovast Technology Ltd." },
{ "54A04F", "t-mac Technologies Ltd" },
{ "E44F5F", "EDS Elektronik Destek San.Tic.Ltd.Sti" },
{ "08B738", "Lite-On Technogy Corp." },
{ "9C6650", "Glodio Technolies Co.,Ltd Tianjin Branch" },
{ "503955", "Cisco SPVTG" },
{ "90CF6F", "Dlogixs Co Ltd" },
{ "68AF13", "Futura Mobility" },
{ "B82410", "Magneti Marelli Slovakia s.r.o." },
{ "A8EF26", "Tritonwave" },
{ "F0D3E7", "Sensometrix SA" },
{ "7CC8D0", "TIANJIN YAAN TECHNOLOGY CO., LTD." },
{ "88E917", "Tamaggo" },
{ "80AAA4", "USAG" },
{ "5C2479", "Baltech AG" },
{ "E8CBA1", "Nokia Corporation" },
{ "F85F2A", "Nokia Corporation" },
{ "286094", "CAPELEC" },
{ "60E956", "Ayla Networks, Inc" },
{ "287184", "Spire Payments" },
{ "1CB094", "HTC Corporation" },
{ "FC5090", "SIMEX Sp. z o.o." },
{ "209BA5", "JIAXING GLEAD Electronics Co.,Ltd" },
{ "60843B", "Soladigm, Inc." },
{ "508C77", "DIRMEIER Schanktechnik GmbH &Co KG" },
{ "6089B1", "Key Digital Systems" },
{ "080CC9", "Mission Technology Group, dba Magma" },
{ "3C970E", "Wistron InfoComm(Kunshan)Co.,Ltd." },
{ "A0F450", "HTC Corporation" },
{ "44D15E", "Shanghai Kingto Information Technology Ltd" },
{ "545EBD", "NL Technologies" },
{ "C8BBD3", "Embrane" },
{ "ECD19A", "Zhuhai Liming Industries Co., Ltd" },
{ "346E8A", "Ecosense" },
{ "ACEE3B", "6harmonics Inc" },
{ "681605", "Systems And Electronic Development FZCO" },
{ "04F17D", "Tarana Wireless" },
{ "A0DC04", "Becker-Antriebe GmbH" },
{ "B85510", "Zioncom Electronics (Shenzhen) Ltd." },
{ "8CC121", "Panasonic Corporation AVC Networks Company" },
{ "2CBE97", "Ingenieurbuero Bickele und Buehler GmbH" },
{ "045A95", "Nokia Corporation" },
{ "B40E96", "HERAN " },
{ "BC851F", "Samsung Electronics" },
{ "0CAF5A", "GENUS POWER INFRASTRUCTURES LIMITED" },
{ "D0699E", "LUMINEX Lighting Control Equipment" },
{ "64AE88", "Polytec GmbH" },
{ "2C542D", "Cisco Systems, Inc" },
{ "709E86", "X6D Limited" },
{ "946124", "Pason Systems" },
{ "DC309C", "Heyrex Limited" },
{ "E81324", "GuangZhou Bonsoninfo System CO.,LTD" },
{ "0036F8", "Conti Temic microelectronic GmbH" },
{ "443839", "Cumulus Networks, inc" },
{ "20F002", "MTData Developments Pty. Ltd." },
{ "CC912B", "TE Connectivity Touch Solutions" },
{ "785262", "Shenzhen Hojy Software Co., Ltd." },
{ "40336C", "Godrej & Boyce Mfg. co. ltd" },
{ "FC1D59", "I Smart Cities HK Ltd" },
{ "EC0ED6", "ITECH INSTRUMENTS SAS" },
{ "D0D212", "K2NET Co.,Ltd." },
{ "9C8EDC", "Teracom Limited" },
{ "146A0B", "Cypress Electronics Limited" },
{ "B0750C", "QA Cafe" },
{ "B4E1EB", "Private" },
{ "FC2A54", "Connected Data, Inc." },
{ "A090DE", "VEEDIMS,LLC" },
{ "AC1461", "ATAW  Co., Ltd." },
{ "508A42", "Uptmate Technology Co., LTD" },
{ "8C57FD", "LVX Western" },
{ "002A6A", "Cisco Systems, Inc" },
{ "B88F14", "Analytica GmbH" },
{ "94FAE8", "Shenzhen Eycom Technology Co., Ltd " },
{ "4844F7", "Samsung Electronics Co., LTD" },
{ "3CA315", "Bless Information & Communications Co., Ltd" },
{ "F8DB4C", "PNY Technologies, INC." },
{ "F83094", "Alcatel-Lucent Telecom Limited" },
{ "2817CE", "Omnisense Ltd" },
{ "28E608", "Tokheim" },
{ "E477D4", "Minrray Industry Co.,Ltd " },
{ "A4B980", "Parking BOXX Inc." },
{ "002D76", "TITECH GmbH" },
{ "DC7144", "Samsung Electro Mechanics" },
{ "78A183", "Advidia" },
{ "F85063", "Verathon" },
{ "400E67", "Tremol Ltd." },
{ "901B0E", "Fujitsu Technology Solutions GmbH" },
{ "5C6F4F", "S.A. SISTEL" },
{ "B058C4", "Broadcast Microwave Services, Inc" },
{ "B820E7", "Guangzhou Horizontal Information & Network Integration Co. Ltd" },
{ "98588A", "SYSGRATION Ltd." },
{ "842B50", "Huria Co.,Ltd." },
{ "0C5A19", "Axtion Sdn Bhd" },
{ "606BBD", "Samsung Electronics Co., LTD" },
{ "A00CA1", "SKTB SKiT" },
{ "E09579", "ORTHOsoft inc, d/b/a Zimmer CAS" },
{ "307ECB", "SFR" },
{ "90A783", "JSW PACIFIC CORPORATION " },
{ "000830", "Cisco Systems, Inc" },
{ "CCEF48", "Cisco Systems, Inc" },
{ "78A5DD", "Shenzhen Smarteye Digital Electronics Co., Ltd" },
{ "28B0CC", "Xenya d.o.o." },
{ "94D723", "Shanghai DareGlobal Technologies Co., Ltd" },
{ "ECE744", "Omntec mfg. inc" },
{ "80427C", "Adolf Tedsen GmbH & Co. KG" },
{ "F8F7D3", "International Communications Corporation" },
{ "B89AED", "OceanServer Technology, Inc" },
{ "E455EA", "Dedicated Computing" },
{ "00FC58", "WebSilicon Ltd." },
{ "64A0E7", "Cisco Systems, Inc" },
{ "18E80F", "Viking Electronics Inc." },
{ "EC6264", "Global411 Internet Services, LLC" },
{ "00F051", "KWB Gmbh" },
{ "44DC91", "PLANEX COMMUNICATIONS INC." },
{ "F0DEB9", "ShangHai Y&Y Electronics Co., Ltd" },
{ "AC54EC", "IEEE P1823 Standards Working Group" },
{ "C8292A", "Barun Electronics" },
{ "E0DADC", "JVC KENWOOD Corporation" },
{ "C894D2", "Jiangsu Datang  Electronic Products Co., Ltd" },
{ "A0423F", "Tyan Computer Corp" },
{ "5C18B5", "Talon Communications" },
{ "78BAD0", "Shinybow Technology Co. Ltd." },
{ "306CBE", "Skymotion Technology (HK) Limited" },
{ "40D559", "MICRO S.E.R.I." },
{ "F82F5B", "eGauge Systems LLC" },
{ "3499D7", "Universal Flow Monitors, Inc." },
{ "7C336E", "MEG Electronics Inc." },
{ "D0C1B1", "Samsung Electronics Co.,Ltd" },
{ "D4D249", "Power Ethernet" },
{ "10C2BA", "UTT Co., Ltd." },
{ "F0DA7C", "RLH INDUSTRIES,INC." },
{ "40984C", "Casacom Solutions AG" },
{ "B8975A", "BIOSTAR Microtech Int'l Corp." },
{ "4833DD", "ZENNIO AVANCE Y TECNOLOGIA, S.L." },
{ "D4D748", "Cisco Systems, Inc" },
{ "9CCAD9", "Nokia Corporation" },
{ "F8313E", "endeavour GmbH" },
{ "10FC54", "Shany Electronic Co., Ltd. " },
{ "D4CA6D", "Routerboard.com" },
{ "D8E743", "Wush, Inc" },
{ "A0F3E4", "Alcatel Lucent IPD" },
{ "908FCF", "UNO System Co., Ltd" },
{ "903CAE", "Yunnan KSEC Digital Technology Co.,Ltd." },
{ "000831", "Cisco Systems, Inc" },
{ "F0620D", "Shenzhen Egreat Tech Corp.,Ltd" },
{ "843611", "hyungseul publishing networks" },
{ "DC9FDB", "Ubiquiti Networks, Inc." },
{ "B8FD32", "Zhejiang ROICX Microelectronics" },
{ "D8052E", "Skyviia Corporation" },
{ "F83553", "Magenta Research Ltd." },
{ "DC3C2E", "Manufacturing System Insights, Inc." },
{ "40BC8B", "itelio GmbH" },
{ "88C36E", "Beijing Ereneben lnformation Technology Limited" },
{ "8CDE52", "ISSC Technologies Corp." },
{ "A8776F", "Zonoff" },
{ "FC4DD4", "Universal Global Scientific Industrial Co., Ltd." },
{ "902B34", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "48E1AF", "Vity" },
{ "245FDF", "KYOCERA Corporation" },
{ "C0A0DE", "Multi Touch Oy" },
{ "943AF0", "Nokia Corporation" },
{ "B826D4", "Furukawa Industrial S.A. Produtos Elétricos" },
{ "14E4EC", "mLogic LLC" },
{ "FC0A81", "Zebra Technologies Inc" },
{ "AC0DFE", "Ekon GmbH - myGEKKO" },
{ "005CB1", "Gospell DIGITAL TECHNOLOGY CO., LTD" },
{ "186751", "KOMEG Industrielle Messtechnik GmbH" },
{ "B467E9", "Qingdao GoerTek Technology Co., Ltd." },
{ "B49EE6", "SHENZHEN TECHNOLOGY CO LTD" },
{ "7041B7", "Edwards Lifesciences LLC" },
{ "A849A5", "Lisantech Co., Ltd." },
{ "94DB49", "SITCORP" },
{ "30144A", "Wistron Neweb Corp." },
{ "8CD17B", "CG Mobile" },
{ "144978", "Digital Control Incorporated" },
{ "FC8FC4", "Intelligent Technology Inc." },
{ "F04A2B", "PYRAMID Computer GmbH" },
{ "CC9093", "Hansong Tehnologies" },
{ "78F7D0", "Silverbrook Research" },
{ "F04B6A", "Scientific Production Association Siberian Arsenal, Ltd." },
{ "30DE86", "Cedac Software S.r.l." },
{ "F013C3", "SHENZHEN FENDA TECHNOLOGY CO., LTD" },
{ "CCE7DF", "American Magnetics, Inc." },
{ "E44E18", "Gardasoft VisionLimited" },
{ "D41C1C", "RCF S.P.A." },
{ "8C94CF", "Encell Technology, Inc." },
{ "149090", "KongTop industrial(shen zhen)CO.,LTD" },
{ "F008F1", "Samsung Electronics Co.,Ltd" },
{ "CCF8F0", "Xi'an HISU Multimedia Technology Co.,Ltd." },
{ "30F9ED", "Sony Corporation" },
{ "28C718", "Altierre" },
{ "2046A1", "VECOW Co., Ltd" },
{ "8C271D", "QuantHouse" },
{ "9C8BF1", "The Warehouse Limited" },
{ "147DC5", "Murata Manufacturing Co., Ltd." },
{ "944696", "BaudTec Corporation" },
{ "90342B", "Gatekeeper Systems, Inc." },
{ "D45251", "IBT Ingenieurbureau Broennimann Thun" },
{ "3071B2", "Hangzhou Prevail Optoelectronic Equipment Co.,LTD." },
{ "B82ADC", "EFR Europäische Funk-Rundsteuerung GmbH" },
{ "B09BD4", "GNH Software India Private Limited" },
{ "7CF429", "NUUO Inc. " },
{ "B8CDA7", "Maxeler Technologies Ltd." },
{ "F49461", "NexGen Storage" },
{ "402CF4", "Universal Global Scientific Industrial Co., Ltd." },
{ "804731", "Packet Design, Inc." },
{ "C4CAD9", "Hangzhou H3C Technologies Co., Limited" },
{ "ACCB09", "Hefcom Metering (Pty) Ltd" },
{ "10EED9", "Canoga Perkins Corporation" },
{ "240BB1", "KOSTAL Industrie Elektrik GmbH " },
{ "20EEC6", "Elefirst Science & Tech Co ., ltd" },
{ "807A7F", "ABB Genway Xiamen Electrical Equipment CO., LTD" },
{ "14373B", "PROCOM Systems" },
{ "B81999", "Nesys" },
{ "4C5585", "Hamilton Systems" },
{ "8CCF5C", "BEFEGA GmbH" },
{ "A0133B", "HiTi Digital, Inc." },
{ "448E12", "DT Research, Inc." },
{ "9C5711", "Feitian Xunda(Beijing) Aeronautical Information Technology Co., Ltd." },
{ "18AD4D", "Polostar Technology Corporation" },
{ "4CA74B", "Alcatel Lucent" },
{ "549478", "Silvershore Technology Partners" },
{ "F4B164", "Lightning Telecommunications Technology Co. Ltd" },
{ "0CFC83", "Airoha Technology Corp.," },
{ "0C51F7", "CHAUVIN ARNOUX" },
{ "70B035", "Shenzhen Zowee Technology Co., Ltd" },
{ "708105", "Cisco Systems, Inc" },
{ "00082F", "Cisco Systems, Inc" },
{ "542018", "Tely Labs" },
{ "581FEF", "Tuttnaer LTD" },
{ "F8F25A", "G-Lab GmbH" },
{ "BC779F", "SBM Co., Ltd." },
{ "C058A7", "Pico Systems Co., Ltd." },
{ "04D783", "Y&H E&C Co.,LTD." },
{ "00E175", "AK-Systems Ltd" },
{ "843F4E", "Tri-Tech Manufacturing, Inc." },
{ "C83232", "Hunting Innova" },
{ "D059C3", "CeraMicro Technology Corporation" },
{ "EC9681", "2276427 Ontario Inc" },
{ "B8288B", "Parker Hannifin Manufacturing (UK) Ltd" },
{ "5835D9", "Cisco Systems, Inc" },
{ "802E14", "azeti Networks AG" },
{ "E8944C", "Cogent Healthcare Systems Ltd" },
{ "68F895", "Redflow Limited" },
{ "A88792", "Broadband Antenna Tracking Systems" },
{ "901900", "SCS SA" },
{ "AC932F", "Nokia Corporation" },
{ "1435B3", "Future Designs, Inc." },
{ "FCF1CD", "OPTEX-FA CO.,LTD." },
{ "B03829", "Siliconware Precision Industries Co., Ltd." },
{ "C86C87", "ZyXEL Communications Corporation" },
{ "BC0F2B", "FORTUNE TECHGROUP CO.,LTD" },
{ "8CF9C9", "MESADA Technology Co.,Ltd." },
{ "E42AD3", "Magneti Marelli S.p.A. Powertrain" },
{ "FC10BD", "Control Sistematizado S.A." },
{ "443719", "2 Save Energy Ltd" },
{ "E83EB6", "RIM" },
{ "94FD1D", "WhereWhen Corp" },
{ "0CE82F", "Bonfiglioli Vectron GmbH" },
{ "C0626B", "Cisco Systems, Inc" },
{ "74D0DC", "ERICSSON AB" },
{ "B4B88D", "Thuh Company" },
{ "60F59C", "CRU-Dataport" },
{ "C4108A", "Ruckus Wireless" },
{ "4C73A5", "KOVE" },
{ "F86971", "Seibu Electric Co.," },
{ "44AA27", "udworks Co., Ltd." },
{ "6CAD3F", "Hubbell Building Automation, Inc." },
{ "8427CE", "Corporation of the Presiding Bishop of The Church of Jesus Christ of Latter-day Saints" },
{ "D428B2", "ioBridge, Inc." },
{ "90B8D0", "Joyent, Inc." },
{ "909060", "RSI VIDEO TECHNOLOGIES" },
{ "3859F9", "Hon Hai Precision Ind. Co.,Ltd." },
{ "281471", "Lantis co., LTD." },
{ "1407E0", "Abrantix AG" },
{ "DCCF94", "Beijing Rongcheng Hutong Technology Co., Ltd." },
{ "18E288", "STT Condigi" },
{ "68876B", "INQ Mobile Limited" },
{ "9866EA", "Industrial Control Communications, Inc." },
{ "F4A52A", "Hawa Technologies Inc" },
{ "90CF15", "Nokia Corporation" },
{ "B8D49D", "M Seven System Ltd." },
{ "B0A10A", "Pivotal Systems Corporation" },
{ "48F47D", "TechVision Holding  Internation Limited" },
{ "6C391D", "Beijing ZhongHuaHun Network Information center" },
{ "64D241", "Keith & Koep GmbH" },
{ "101212", "Vivo International Corporation Pty Ltd" },
{ "5087B8", "Nuvyyo Inc" },
{ "E41289", "topsystem Systemhaus GmbH" },
{ "A4134E", "Luxul " },
{ "B09928", "FUJITSU LIMITED" },
{ "8C11CB", "ABUS Security-Center GmbH & Co. KG" },
{ "806459", "Nimbus Inc." },
{ "A45A1C", "smart-electronic GmbH" },
{ "8C89A5", "Micro-Star INT'L CO., LTD" },
{ "3C672C", "Sciovid Inc." },
{ "18D071", "DASAN CO., LTD." },
{ "38D135", "EasyIO Corporation Sdn. Bhd." },
{ "184E94", "MESSOA TECHNOLOGIES INC." },
{ "A8922C", "LG Electronics" },
{ "94D93C", "ENELPS" },
{ "DC9B1E", "Intercom, Inc." },
{ "5C7757", "Haivision Network Video" },
{ "3816D1", "Samsung Electronics Co.,Ltd" },
{ "E8B4AE", "Shenzhen C&D Electronics Co.,Ltd" },
{ "C45600", "Galleon Embedded Computing" },
{ "E42FF6", "Unicore communication Inc." },
{ "B8F4D0", "Herrmann Ultraschalltechnik GmbH & Co. Kg" },
{ "B4F323", "PETATEL INC." },
{ "C81E8E", "ADV Security (S) Pte Ltd" },
{ "ACCABA", "Midokura Co., Ltd. " },
{ "9C417C", "Hame  Technology Co.,  Limited " },
{ "10768A", "EoCell" },
{ "044665", "Murata Manufacturing Co., Ltd." },
{ "D0131E", "Sunrex Technology Corp" },
{ "380197", "TSST Global,Inc" },
{ "B40142", "GCI Science & Technology Co.,LTD" },
{ "846EB1", "Park Assist LLC" },
{ "6C504D", "Cisco Systems, Inc" },
{ "C0C1C0", "Cisco-Linksys, LLC" },
{ "1CBD0E", "Amplified Engineering Pty Ltd" },
{ "F0A764", "GST Co., Ltd." },
{ "A0F217", "GE Medical System(China) Co., Ltd. " },
{ "5067F0", "ZyXEL Communications Corporation" },
{ "643409", "BITwave Pte Ltd" },
{ "20D5AB", "Korea Infocom Co.,Ltd." },
{ "F05849", "CareView Communications" },
{ "BC15A6", "Taiwan Jantek Electronics,Ltd." },
{ "241A8C", "Squarehead Technology AS" },
{ "1083D2", "Microseven Systems, LLC" },
{ "F05D89", "Dycon Limited" },
{ "AC02CF", "RW Tecnologia Industria e Comercio Ltda" },
{ "A0B662", "Acutvista Innovation Co., Ltd." },
{ "9067B5", "Alcatel-Lucent" },
{ "40987B", "Aisino Corporation" },
{ "6C2E33", "Accelink Technologies Co.,Ltd." },
{ "4CEDDE", "ASKEY COMPUTER CORP" },
{ "E8E08F", "GRAVOTECH MARKING SAS" },
{ "78B6C1", "AOBO Telecom Co.,Ltd" },
{ "B8BA68", "Xi'an Jizhong Digital Communication Co.,Ltd" },
{ "BC38D2", "Pandachip Limited" },
{ "A00BBA", "SAMSUNG ELECTRO-MECHANICS" },
{ "14EE9D", "AirNav Systems LLC" },
{ "48174C", "MicroPower technologies" },
{ "78471D", "Samsung Electronics Co.,Ltd" },
{ "F81037", "Atopia Systems, LP" },
{ "64F987", "Avvasi Inc." },
{ "3C7437", "RIM" },
{ "04209A", "Panasonic AVC Networks Company" },
{ "64DC01", "Static Systems Group PLC" },
{ "90A4DE", "Wistron Neweb Corp." },
{ "1CF5E7", "Turtle Industry Co., Ltd." },
{ "9C4A7B", "Nokia Corporation" },
{ "2C8065", "HARTING Inc. of North America" },
{ "80C6AB", "Technicolor USA Inc." },
{ "F8F014", "RackWare Inc." },
{ "889FFA", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E41C4B", "V2 TECHNOLOGY, INC." },
{ "F0F002", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E0143E", "Modoosis Inc." },
{ "5C6984", "NUVICO" },
{ "204AAA", "Hanscan Spain S.A." },
{ "F02572", "Cisco Systems, Inc" },
{ "8091C0", "AgileMesh, Inc." },
{ "0CF0B4", "Globalsat International Technology Ltd" },
{ "BCC61A", "SPECTRA EMBEDDED SYSTEMS" },
{ "48DF1C", "Wuhan NEC Fibre Optic Communications industry Co. Ltd" },
{ "D0D3FC", "Mios, Ltd." },
{ "989449", "Skyworth Wireless Technology Ltd." },
{ "C8DF7C", "Nokia Corporation" },
{ "F8C678", "Carefusion" },
{ "FC3598", "Favite Inc." },
{ "A0AAFD", "EraThink Technologies Corp." },
{ "801F02", "Edimax Technology Co. Ltd." },
{ "E03E7D", "data-complex GmbH" },
{ "A4E32E", "Silicon & Software Systems Ltd." },
{ "1C19DE", "eyevis GmbH" },
{ "DC07C1", "HangZhou QiYang Technology Co.,Ltd." },
{ "D8FE8F", "IDFone Co., Ltd." },
{ "0006F6", "Cisco Systems, Inc" },
{ "ACAB8D", "Lyngso Marine A/S" },
{ "181456", "Nokia Corporation" },
{ "E8995A", "PiiGAB, Processinformation i Goteborg AB" },
{ "18F46A", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D4E32C", "S. Siedle & Sohne" },
{ "68DCE8", "PacketStorm Communications" },
{ "78223D", "Affirmed Networks" },
{ "60C980", "Trymus" },
{ "94CDAC", "Creowave Oy" },
{ "F4DCDA", "Zhuhai Jiahe Communication Technology Co., limited" },
{ "100D32", "Embedian, Inc." },
{ "D82986", "Best Wish Technology LTD" },
{ "C03B8F", "Minicom Digital Signage" },
{ "D48890", "Samsung Electronics Co.,Ltd" },
{ "A4218A", "Nortel Networks" },
{ "6C0460", "RBH Access Technologies Inc." },
{ "5C864A", "Secret Labs LLC" },
{ "B8BA72", "Cynove" },
{ "C00D7E", "Additech, Inc." },
{ "68784C", "Nortel Networks" },
{ "6C626D", "Micro-Star INT'L CO., LTD" },
{ "8841C1", "ORBISAT DA AMAZONIA IND E AEROL SA" },
{ "18B209", "Torrey Pines Logic, Inc" },
{ "3018CF", "DEOS control systems GmbH" },
{ "4CF737", "SamJi Electronics Co., Ltd" },
{ "40406B", "Icomera" },
{ "1880CE", "Barberry Solutions Ltd" },
{ "CC43E3", "Trump s.a." },
{ "6C22AB", "Ainsworth Game Technology" },
{ "3C106F", "ALBAHITH TECHNOLOGIES " },
{ "7CE044", "NEON Inc" },
{ "64D02D", "Next Generation Integration (NGI)" },
{ "A04041", "SAMWONFA Co.,Ltd." },
{ "788C54", "Eltek Technologies LTD" },
{ "9411DA", "ITF Fröschl GmbH" },
{ "10E8EE", "PhaseSpace" },
{ "A47C1F", "Cobham plc" },
{ "8C1F94", "RF Surgical System Inc. " },
{ "74A4A7", "QRS Music Technologies, Inc." },
{ "8039E5", "PATLITE CORPORATION" },
{ "BCFFAC", "TOPCON CORPORATION" },
{ "602A54", "CardioTek B.V." },
{ "1C3DE7", "Sigma Koki Co.,Ltd." },
{ "482CEA", "Motorola Inc Business Light Radios" },
{ "70E139", "3view Ltd" },
{ "AC6123", "Drivven, Inc." },
{ "3C04BF", "PRAVIS SYSTEMS Co.Ltd.," },
{ "443D21", "Nuvolt" },
{ "749050", "Renesas Electronics Corporation" },
{ "7CBB6F", "Cosco Electronics Co., Ltd." },
{ "D466A8", "Riedo Networks GmbH" },
{ "98E165", "Accutome" },
{ "EC66D1", "B&W Group LTD" },
{ "385FC3", "Yu Jeong System, Co.Ltd" },
{ "94857A", "Evantage Industries Corp" },
{ "4451DB", "Raytheon BBN Technologies" },
{ "64995D", "LGE " },
{ "585076", "Linear Equipamentos Eletronicos SA" },
{ "4083DE", "Zebra Technologies Inc" },
{ "8897DF", "Entrypass Corporation Sdn. Bhd." },
{ "0C15C5", "SDTEC Co., Ltd." },
{ "9803A0", "ABB n.v. Power Quality Products" },
{ "DCFAD5", "STRONG Ges.m.b.H." },
{ "D84606", "Silicon Valley Global Marketing" },
{ "5CAC4C", "Hon Hai Precision Ind. Co.,Ltd." },
{ "689234", "Ruckus Wireless" },
{ "D0E347", "Yoga" },
{ "84A991", "Cyber Trans Japan Co.,Ltd." },
{ "380DD4", "Primax Electronics LTD." },
{ "D81C14", "Compacta International, Ltd." },
{ "9088A2", "IONICS TECHNOLOGY ME LTDA" },
{ "B0B8D5", "Nanjing Nengrui Auto Equipment CO.,Ltd" },
{ "8497B8", "Memjet Inc." },
{ "A8556A", "Pocketnet Technology Inc." },
{ "B081D8", "I-sys Corp" },
{ "206AFF", "Atlas Elektronik UK Limited" },
{ "EC542E", "Shanghai XiMei Electronic Technology Co. Ltd" },
{ "B88E3A", "Infinite Technologies JLT" },
{ "74BE08", "ATEK Products, LLC" },
{ "E0EE1B", "Panasonic Automotive Systems Company of America" },
{ "E80C38", "DAEYOUNG INFORMATION SYSTEM CO., LTD" },
{ "68597F", "Alcatel Lucent" },
{ "2C3068", "Pantech Co.,Ltd" },
{ "5C4058", "Jefferson Audio Video Systems, Inc." },
{ "64317E", "Dexin Corporation" },
{ "AC9B84", "Smak Tecnologia e Automacao" },
{ "4C022E", "CMR KOREA CO., LTD" },
{ "24A42C", "KOUKAAM a.s." },
{ "34F39B", "WizLAN Ltd." },
{ "74B9EB", "JinQianMao Technology Co.,Ltd." },
{ "244597", "GEMUE Gebr. Mueller Apparatebau" },
{ "30694B", "RIM" },
{ "AC5135", "MPI TECH" },
{ "E4EC10", "Nokia Corporation" },
{ "00D38D", "Hotel Technology Next Generation" },
{ "3C6278", "SHENZHEN JETNET TECHNOLOGY CO.,LTD." },
{ "8081A5", "TONGQING COMMUNICATION EQUIPMENT (SHENZHEN) Co.,Ltd" },
{ "EC8EAD", "DLX" },
{ "ECDE3D", "Lamprey Networks, Inc." },
{ "04FE7F", "Cisco Systems, Inc" },
{ "E8056D", "Nortel Networks" },
{ "00D11C", "ACETEL" },
{ "1056CA", "Peplink International Ltd." },
{ "E83A97", "OCZ Technology Group" },
{ "44A689", "PROMAX ELECTRONICA SA" },
{ "10CCDB", "AXIMUM PRODUITS ELECTRONIQUES" },
{ "6C92BF", "Inspur Electronic Information Industry Co.,Ltd." },
{ "E01CEE", "Bravo Tech, Inc." },
{ "3C1915", "GFI Chrono Time" },
{ "EC5C69", "MITSUBISHI HEAVY INDUSTRIES MECHATRONICS SYSTEMS,LTD." },
{ "04E548", "Cohda Wireless Pty Ltd" },
{ "0C1DC2", "SeAH Networks" },
{ "28CD4C", "Individual Computers GmbH" },
{ "8C53F7", "A&D ENGINEERING CO., LTD." },
{ "781185", "NBS Payment Solutions Inc." },
{ "2893FE", "Cisco Systems, Inc" },
{ "10B7F6", "Plastoform Industries Ltd." },
{ "2059A0", "Paragon Technologies Inc." },
{ "487119", "SGB GROUP LTD." },
{ "E0ABFE", "Orb Networks, Inc." },
{ "CCEA1C", "DCONWORKS  Co., Ltd" },
{ "ACE348", "MadgeTech, Inc" },
{ "687F74", "Cisco-Linksys, LLC" },
{ "CCB888", "AnB Securite s.a." },
{ "CC2218", "InnoDigital Co., Ltd." },
{ "B86491", "CK Telecom Ltd" },
{ "80C862", "Openpeak, Inc" },
{ "E43593", "Hangzhou GoTo technology Co.Ltd" },
{ "E0BC43", "C2 Microsystems, Inc." },
{ "7884EE", "INDRA ESPACIO S.A." },
{ "2C3F3E", "Alge-Timing GmbH" },
{ "ECE09B", "Samsung electronics CO., LTD" },
{ "C0CFA3", "Creative Electronics & Software, Inc." },
{ "D4823E", "Argosy Technologies, Ltd." },
{ "844823", "WOXTER TECHNOLOGY Co. Ltd" },
{ "D0F0DB", "Ericsson" },
{ "34C3AC", "Samsung Electronics" },
{ "7C1476", "Damall Technologies SAS" },
{ "D05875", "Active Control Technology Inc." },
{ "D81BFE", "TWINLINX CORPORATION" },
{ "D46CBF", "Goodrich ISR" },
{ "5C57C8", "Nokia Corporation" },
{ "4CC602", "Radios, Inc." },
{ "3C05AB", "Product Creation Studio" },
{ "3C39C3", "JW Electronics Co., Ltd." },
{ "547FEE", "Cisco Systems, Inc" },
{ "A4C2AB", "Hangzhou LEAD-IT Information & Technology Co.,Ltd" },
{ "48AA5D", "Store Electronic Systems" },
{ "1062C9", "Adatis GmbH & Co. KG" },
{ "D8AE90", "Itibia Technologies" },
{ "904716", "RORZE CORPORATION" },
{ "28E794", "Microtime Computer Inc." },
{ "8894F9", "Gemicom Technology, Inc." },
{ "0CA42A", "OB Telecom Electronic Technology Co., Ltd" },
{ "5850E6", "Best Buy Corporation" },
{ "AC9A96", "Lantiq Deutschland GmbH" },
{ "E86CDA", "Supercomputers and Neurocomputers Research Center" },
{ "24B6B8", "FRIEM SPA" },
{ "F86ECF", "Arcx Inc" },
{ "8C8401", "Private" },
{ "6C7039", "Novar GmbH" },
{ "C44619", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A4561B", "MCOT Corporation" },
{ "80EE73", "Shuttle Inc." },
{ "10C73F", "Midas Klark Teknik Ltd" },
{ "408A9A", "TITENG CO., Ltd." },
{ "702B1D", "E-Domus International Limited" },
{ "F077D0", "Xcellen" },
{ "785C72", "Hioso Technology Co., Ltd." },
{ "94236E", "Shenzhen Junlan Electronic Ltd" },
{ "88BA7F", "Qfiednet Co., Ltd." },
{ "E02636", "Nortel Networks" },
{ "4456B7", "Spawn Labs, Inc" },
{ "0C6076", "Hon Hai Precision Ind. Co.,Ltd." },
{ "0CEEE6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "A09805", "OpenVox Communication Co Ltd" },
{ "00271D", "Comba Telecom Systems (China) Ltd." },
{ "002721", "Shenzhen Baoan Fenda Industrial Co., Ltd" },
{ "A09A5A", "Time Domain" },
{ "64A837", "Juni Korea Co., Ltd" },
{ "B4B5AF", "Minsung Electronics" },
{ "044FAA", "Ruckus Wireless" },
{ "44568D", "PNC Technologies  Co., Ltd." },
{ "ACD180", "Crexendo Business Solutions, Inc." },
{ "AC8317", "Shenzhen Furtunetel Communication Co., Ltd" },
{ "E80B13", "Akib Systems Taiwan, INC" },
{ "44C9A2", "Greenwald Industries" },
{ "9CB206", "PROCENTEC" },
{ "44F459", "Samsung Electronics" },
{ "646E6C", "Radio Datacom LLC" },
{ "E4751E", "Getinge Sterilization AB" },
{ "F8811A", "OVERKIZ" },
{ "042BBB", "PicoCELA, Inc." },
{ "FC0877", "Prentke Romich Company" },
{ "ECD00E", "MiraeRecognition Co., Ltd." },
{ "747E1A", "Red Embedded Design Limited" },
{ "C47D4F", "Cisco Systems, Inc" },
{ "4C9EE4", "Hanyang Navicom Co.,Ltd." },
{ "3CDF1E", "Cisco Systems, Inc" },
{ "BCB181", "SHARP CORPORATION" },
{ "78B81A", "INTER SALES A/S" },
{ "78192E", "NASCENT Technology" },
{ "2C0623", "Win Leader Inc." },
{ "C82E94", "Halfa Enterprise Co., Ltd." },
{ "0C2755", "Valuable Techologies Limited" },
{ "C038F9", "Nokia Danmark A/S" },
{ "F46349", "Diffon Corporation" },
{ "5C8778", "Cybertelbridge co.,ltd" },
{ "9C5E73", "Calibre UK LTD" },
{ "F06281", "ProCurve Networking by HP" },
{ "003A9B", "Cisco Systems, Inc" },
{ "2C9127", "Eintechno Corporation" },
{ "C09C92", "COBY" },
{ "849000", "Arnold & Richter Cine Technik" },
{ "C87248", "Aplicom Oy" },
{ "74D850", "Evrisko Systems" },
{ "6CAC60", "Venetex Corp" },
{ "DC0265", "Meditech Kft" },
{ "986DC8", "TOSHIBA MITSUBISHI-ELECTRIC INDUSTRIAL SYSTEMS CORPORATION" },
{ "68A1B7", "Honghao Mingchuan Technology (Beijing) CO.,Ltd." },
{ "7CCFCF", "Shanghai SEARI Intelligent System Co., Ltd" },
{ "EC3091", "Cisco Systems, Inc" },
{ "3032D4", "Hanilstm Co., Ltd." },
{ "0026EE", "TKM GmbH" },
{ "0026E7", "Shanghai ONLAN Communication Tech. Co., Ltd." },
{ "0026E1", "Stanford University, OpenFlow Group" },
{ "0026DB", "Ionics EMS Inc." },
{ "0026CE", "Kozumi USA Corp." },
{ "0026D5", "Ory Solucoes em Comercio de Informatica Ltda." },
{ "0026C8", "System Sensor" },
{ "002711", "LanPro Inc" },
{ "00270D", "Cisco Systems, Inc" },
{ "002707", "Lift Complex DS, JSC" },
{ "002700", "Shenzhen Siglent Technology Co., Ltd." },
{ "0026FA", "BandRich Inc." },
{ "0026F4", "Nesslab" },
{ "0025D7", "CEDO" },
{ "0025D2", "InpegVision Co., Ltd" },
{ "0025D1", "Eastern Asia Technology Limited" },
{ "0025CB", "Reiner SCT" },
{ "0025C4", "Ruckus Wireless" },
{ "0025BF", "Wireless Cables Inc." },
{ "0025B1", "Maya-Creation Corporation" },
{ "0025B8", "Agile Communications, Inc." },
{ "0025B2", "MBDA Deutschland GmbH" },
{ "0025AC", "I-Tech corporation" },
{ "0026C2", "SCDI Co. LTD" },
{ "0026BC", "General Jack Technology Ltd." },
{ "0026B4", "Ford Motor Company" },
{ "0026AE", "Wireless Measurement Ltd" },
{ "0026AA", "Kenmec Mechanical Engineering Co., Ltd." },
{ "0026A4", "Novus Produtos Eletronicos Ltda" },
{ "00269E", "Quanta Computer Inc" },
{ "002698", "Cisco Systems, Inc" },
{ "00269D", "M2Mnet Co., Ltd." },
{ "00268B", "Guangzhou Escene Computer Technology Limited" },
{ "002685", "Digital Innovation" },
{ "00267E", "Parrot SA" },
{ "002678", "Logic Instrument SA" },
{ "002672", "AAMP of America" },
{ "00266C", "Inventec" },
{ "00266B", "SHINE UNION ENTERPRISE LIMITED" },
{ "002666", "EFM Networks" },
{ "002665", "ProtectedLogic Corporation" },
{ "00265F", "Samsung Electronics Co.,Ltd" },
{ "002651", "Cisco Systems, Inc" },
{ "002652", "Cisco Systems, Inc" },
{ "002646", "SHENYANG TONGFANG MULTIMEDIA TECHNOLOGY COMPANY LIMITED" },
{ "002640", "Baustem Broadband Technologies, Ltd." },
{ "00263A", "Digitec Systems" },
{ "002634", "Infineta Systems, Inc" },
{ "002633", "MIR - Medical International Research" },
{ "00262E", "Chengdu Jiuzhou Electronic Technology Inc" },
{ "002627", "Truesell" },
{ "002621", "InteliCloud Technology Inc." },
{ "00261B", "LAUREL BANK MACHINES CO., LTD." },
{ "002614", "KTNF" },
{ "00260E", "Ablaze Systems, LLC" },
{ "00260F", "Linn Products Ltd" },
{ "002602", "SMART Temps LLC" },
{ "002601", "Cutera Inc" },
{ "0025F7", "Ansaldo STS USA" },
{ "0025FC", "ENDA ENDUSTRIYEL ELEKTRONIK LTD. STI." },
{ "0025ED", "NuVo Technologies LLC" },
{ "0025EE", "Avtex Ltd" },
{ "0025E8", "Idaho Technology" },
{ "0025E3", "Hanshinit Inc." },
{ "0025DE", "Probits Co., LTD." },
{ "002579", "J & F Labs" },
{ "00257E", "NEW POS Technology Limited" },
{ "002572", "Nemo-Q International AB" },
{ "002566", "Samsung Electronics Co.,Ltd" },
{ "00256B", "ATENIX E.E. s.r.l." },
{ "00256C", "Azimut Production Association JSC" },
{ "00255F", "SenTec AG" },
{ "00255A", "Tantalus Systems Corp." },
{ "002559", "Syphan Technologies Ltd" },
{ "0025A5", "Walnut Media Network" },
{ "00259F", "TechnoDigital Technologies GmbH" },
{ "002599", "Hedon e.d. B.V." },
{ "002592", "Guangzhou Shirui Electronic Co., Ltd" },
{ "00258D", "Haier" },
{ "002588", "Genie Industries, Inc." },
{ "002583", "Cisco Systems, Inc" },
{ "00254C", "Videon Central, Inc." },
{ "002536", "Oki Electric Industry Co., Ltd." },
{ "00253D", "DRS Consolidated Controls" },
{ "002540", "Quasar Technologies, Inc." },
{ "002533", "WITTENSTEIN AG" },
{ "00252C", "Entourage Systems, Inc." },
{ "002502", "NaturalPoint" },
{ "0024FB", "Private" },
{ "0024F6", "MIYOSHI ELECTRONICS CORPORATION" },
{ "0024EA", "iris-GmbH infrared & intelligent sensors" },
{ "0024E3", "CAO Group" },
{ "002527", "Bitrode Corp." },
{ "002524", "Lightcomm Technology Co., Ltd" },
{ "00251F", "ZYNUS VISION INC." },
{ "00251A", "Psiber Data Systems Inc." },
{ "002515", "SFR" },
{ "00250E", "gt german telematics gmbh" },
{ "002507", "ASTAK Inc." },
{ "002509", "SHARETRONIC Group LTD" },
{ "002437", "Motorola - BSG" },
{ "00243C", "S.A.A.A." },
{ "002430", "Ruby Tech Corp." },
{ "0023FB", "IP Datatel, LLC." },
{ "0023F3", "Glocom, Inc." },
{ "0023EF", "Zuend Systemtechnik AG" },
{ "0023E9", "F5 Networks, Inc." },
{ "0023E3", "Microtronic AG" },
{ "0023E2", "SEA Signalisation" },
{ "0023DD", "ELGIN S.A." },
{ "0023D0", "Uniloc USA Inc." },
{ "0023CA", "Behind The Set, LLC" },
{ "0023D6", "Samsung Electronics Co.,LTD" },
{ "0024B0", "ESAB AB" },
{ "0024A9", "Ag Leader Technology" },
{ "0024A2", "Hong Kong Middleware Technology Limited" },
{ "0024A4", "Siklu Communication" },
{ "00249D", "NES Technology Inc." },
{ "00248A", "Kaga Electronics Co., Ltd." },
{ "00248F", "DO-MONIX" },
{ "002491", "Samsung Electronics" },
{ "002496", "Ginzinger electronic systems" },
{ "00247E", "Universal Global Scientific Industrial Co., Ltd" },
{ "002483", "LG Electronics" },
{ "002477", "Tibbo Technology" },
{ "002470", "AUROTECH ultrasound AS." },
{ "002472", "ReDriven Power Inc." },
{ "00246B", "Covia, Inc." },
{ "002464", "Bridge Technologies Co AS" },
{ "00245F", "Vine Telecom CO.,Ltd." },
{ "002420", "NetUP Inc." },
{ "002426", "NOHMI BOSAI LTD." },
{ "00241A", "Red Beetle Inc." },
{ "002413", "Cisco Systems, Inc" },
{ "00240D", "OnePath Networks LTD." },
{ "00240E", "Inventec Besta Co., Ltd." },
{ "002407", "TELEM SAS" },
{ "002400", "Nortel Networks" },
{ "0024D0", "Shenzhen SOGOOD Industry CO.,LTD." },
{ "0024D5", "Winward Industrial Limited" },
{ "0024C9", "Broadband Solutions Group" },
{ "0024C4", "Cisco Systems, Inc" },
{ "0024BF", "CIAT" },
{ "0024B5", "Nortel Networks" },
{ "00245A", "Nanjing Panda Electronics Company Limited" },
{ "002453", "Initra d.o.o." },
{ "00244D", "Hokkaido Electronics Corporation" },
{ "002452", "Silicon Software GmbH" },
{ "002446", "MMB Research Inc." },
{ "002441", "Wanzl Metallwarenfabrik GmbH" },
{ "002368", "Zebra Technologies Inc" },
{ "00236F", "DAQ System" },
{ "002362", "Goldline Controls" },
{ "002361", "Unigen Corporation" },
{ "00235C", "Aprius, Inc." },
{ "002355", "Kinco Automation(Shanghai) Ltd." },
{ "00234F", "Luminous Power Technologies Pvt. Ltd." },
{ "002350", "LynTec" },
{ "002349", "Helmholtz Centre Berlin for Material and Energy" },
{ "002244", "Chengdu Linkon Communications Device Co., Ltd" },
{ "00224F", "Byzoro Networks Ltd." },
{ "002248", "Microsoft Corporation" },
{ "00223E", "IRTrans GmbH" },
{ "002239", "Indiana Life Sciences Incorporated" },
{ "002232", "Design Design Technology Ltd" },
{ "00222C", "Ceton Corp" },
{ "00230E", "Gorba AG" },
{ "002307", "FUTURE INNOVATION TECH CO.,LTD" },
{ "002302", "Cobalt Digital, Inc." },
{ "0022EB", "Data Respons A/S" },
{ "0022EC", "IDEALBT TECHNOLOGY CORPORATION" },
{ "0022F1", "Private" },
{ "00239E", "Jiangsu Lemote Technology Corporation Limited" },
{ "002398", "Vutlan sro" },
{ "00238A", "Ciena Corporation" },
{ "002384", "GGH Engineering s.r.l." },
{ "002342", "Coffee Equipment Company" },
{ "002336", "METEL s.r.o." },
{ "00233D", "Novero holding B.V." },
{ "002330", "DIZIPIA, INC." },
{ "00232C", "Senticare" },
{ "002320", "Nicira Networks" },
{ "00231D", "Deltacom Electronics Ltd" },
{ "00231E", "Cezzer Multimedia Technologies" },
{ "0022B8", "Norcott" },
{ "0022B7", "GSS Grundig SAT-Systems GmbH" },
{ "0022B2", "4RF Communications Ltd" },
{ "0022AB", "Shenzhen Turbosight Technology Ltd" },
{ "0022A6", "Sony Computer Entertainment America" },
{ "00229F", "Sensys Traffic AB" },
{ "0022E5", "Fisher-Rosemount Systems Inc." },
{ "0022DE", "OPPO Digital, Inc." },
{ "0022D9", "Fortex Industrial Ltd." },
{ "0022D2", "All Earth Comércio de Eletrônicos LTDA." },
{ "0022CC", "SciLog, Inc." },
{ "0022C8", "Applied Instruments B.V." },
{ "0022BE", "Cisco Systems, Inc" },
{ "00228C", "Photon Europe GmbH" },
{ "002286", "ASTRON" },
{ "002285", "NOMUS COMM SYSTEMS" },
{ "002280", "A2B Electronics AB" },
{ "002276", "Triple EYE B.V." },
{ "00227B", "Apogee Labs, Inc." },
{ "002262", "BEP Marine" },
{ "00226C", "LinkSprite Technologies, Inc." },
{ "00225E", "Uwin Technologies Co.,LTD" },
{ "002258", "Taiyo Yuden Co., Ltd." },
{ "0023C3", "LogMeIn, Inc." },
{ "0023BD", "Digital Ally, Inc." },
{ "0023B7", "Q-Light Co., Ltd." },
{ "0023B1", "Longcheer Technology (Singapore) Pte Ltd" },
{ "0023B0", "COMXION Technology Inc." },
{ "0023AB", "Cisco Systems, Inc" },
{ "0023A4", "New Concepts Development Corp." },
{ "001FC0", "Control Express Finland Oy" },
{ "001FBB", "Xenatech Co.,LTD" },
{ "001FB4", "SmartShare Systems" },
{ "001FAD", "Brown Innovations, Inc" },
{ "001FAF", "NextIO, Inc." },
{ "001FAE", "Blick South Africa (Pty) Ltd" },
{ "001FA8", "Smart Energy Instruments Inc." },
{ "001FA3", "T&W Electronics(Shenzhen)Co.,Ltd." },
{ "002142", "Advanced Control Systems doo" },
{ "002140", "EN Technologies Inc." },
{ "002138", "Cepheid" },
{ "00212E", "dresden-elektronik" },
{ "002128", "Oracle Corporation" },
{ "002122", "Chip-pro Ltd." },
{ "00211B", "Cisco Systems, Inc" },
{ "002115", "PHYWE Systeme GmbH & Co. KG" },
{ "002116", "Transcon Electronic Systems, spol. s r. o." },
{ "00210F", "Cernium Corp" },
{ "00210B", "GEMINI TRAZE RFID PVT. LTD." },
{ "00210C", "Cymtec Systems, Inc." },
{ "002105", "Alcatel-Lucent" },
{ "001FFC", "Riccius+Sohn GmbH" },
{ "001FF7", "Nakajima All Precision Co., Ltd." },
{ "00216E", "Function ATI (Huizhou) Telecommunications Co., Ltd." },
{ "002168", "iVeia, LLC" },
{ "002161", "Yournet Inc." },
{ "00215B", "Inotive" },
{ "002155", "Cisco Systems, Inc" },
{ "00214E", "GS Yuasa Power Supply Ltd." },
{ "002149", "China Daheng Group ,Inc." },
{ "001FF0", "Audio Partnership" },
{ "001FE9", "Printrex, Inc." },
{ "001FEB", "Trio Datacom Pty Ltd" },
{ "001FEA", "Applied Media Technologies Corporation" },
{ "001FDD", "GDI LLC" },
{ "001FD8", "A-TRUST COMPUTER CORPORATION" },
{ "001FD3", "RIVA Networks Inc." },
{ "001FCE", "QTECH LLC" },
{ "00219D", "Adesys BV" },
{ "0021A1", "Cisco Systems, Inc" },
{ "002198", "Thai Radio Co, LTD" },
{ "002193", "Videofon MV" },
{ "00218D", "AP Router Ind. Eletronica LTDA" },
{ "00218E", "MEKICS CO., LTD." },
{ "002187", "Imacs GmbH" },
{ "002181", "Si2 Microsystems Limited" },
{ "00217B", "Bastec AB" },
{ "002174", "AvaLAN Wireless" },
{ "0021F8", "Enseo, Inc." },
{ "0021F3", "Si14 SpA" },
{ "0021EC", "Solutronic GmbH" },
{ "0021E6", "Starlight Video Limited" },
{ "0021E0", "CommAgility Ltd" },
{ "0021D3", "BOCOM SECURITY(ASIA PACIFIC) LIMITED" },
{ "0021D4", "Vollmer Werke GmbH" },
{ "0021D9", "SEKONIC CORPORATION" },
{ "0021CD", "LiveTV" },
{ "0021C7", "Russound" },
{ "0021C6", "CSJ Global, Inc." },
{ "0021C1", "ABB Oy / Medium Voltage Products" },
{ "0021B4", "APRO MEDIA CO., LTD" },
{ "0021AE", "ALCATEL-LUCENT FRANCE - WTD" },
{ "0021A2", "EKE-Electronics Ltd." },
{ "0021A7", "Hantle System Co., Ltd." },
{ "00221F", "eSang Technologies Co., Ltd." },
{ "002226", "Avaak, Inc." },
{ "00221A", "Audio Precision" },
{ "002213", "PCI CORPORATION" },
{ "00220D", "Cisco Systems, Inc" },
{ "00220C", "Cisco Systems, Inc" },
{ "002207", "Inteno Broadband Technology AB" },
{ "002202", "Excito Elektronik i Skåne AB" },
{ "0021F9", "WIRECOM Technologies" },
{ "001F46", "Nortel" },
{ "001F40", "Speakercraft Inc." },
{ "001F38", "POSITRON" },
{ "001F3D", "Qbit GmbH" },
{ "001F37", "Genesis I&C" },
{ "001F2A", "ACCM" },
{ "001F31", "Radiocomp" },
{ "001F25", "MBS GmbH" },
{ "001F1E", "Astec Technology Co., Ltd" },
{ "001F17", "IDX Company, Ltd." },
{ "001F18", "Hakusan.Mfg.Co,.Ltd" },
{ "001E61", "ITEC GmbH" },
{ "001E5C", "RB GeneralEkonomik" },
{ "001E5B", "Unitron Company, Inc." },
{ "001E55", "COWON SYSTEMS,Inc." },
{ "001E4E", "DAKO EDV-Ingenieur- und Systemhaus GmbH" },
{ "001E49", "Cisco Systems, Inc" },
{ "001E44", "SANTEC" },
{ "001E3F", "TrellisWare Technologies, Inc." },
{ "001E38", "Bluecard Software Technology Co., Ltd." },
{ "001E31", "INFOMARK CO.,LTD." },
{ "001E32", "Zensys" },
{ "001E2C", "CyVerse Corporation" },
{ "001E20", "Intertain Inc." },
{ "001E25", "Intek Digital Inc" },
{ "001E19", "GTRI" },
{ "001E1F", "Nortel" },
{ "001E0F", "Briot International" },
{ "001EE4", "ACS Solutions France" },
{ "001EEB", "Talk-A-Phone Co." },
{ "001EDF", "Master Industrialization Center Kista" },
{ "001EDA", "Wesemann Elektrotechniek B.V." },
{ "001ED5", "Tekon-Automatics" },
{ "001ECE", "BISA Technologies (Hong Kong) Limited" },
{ "001EC8", "Rapid Mobile (Pty) Ltd" },
{ "001EBB", "BLUELIGHT TECHNOLOGY INC." },
{ "001EB6", "TAG Heuer SA" },
{ "001EB5", "Ever Sparkle Technologies Ltd" },
{ "001EAF", "Ophir Optronics Ltd" },
{ "001EAA", "E-Senza Technologies GmbH" },
{ "001E9D", "Recall Technologies, Inc." },
{ "001E98", "GreenLine Communications" },
{ "001E97", "Medium Link System Technology CO., LTD," },
{ "001E91", "KIMIN Electronic Co., Ltd." },
{ "001E8A", "eCopy, Inc" },
{ "001E85", "Lagotek Corporation" },
{ "001E7E", "Nortel" },
{ "001E78", "Owitek Technology Ltd.," },
{ "001E6D", "IT R&D Center" },
{ "001E6E", "Shenzhen First Mile Communications Ltd" },
{ "001E68", "Quanta Computer" },
{ "001F71", "xG Technology, Inc." },
{ "001F72", "QingDao Hiphone Technology Co,.Ltd" },
{ "001F76", "AirLogic Systems Inc." },
{ "001F6C", "Cisco Systems, Inc" },
{ "001F60", "COMPASS SYSTEMS CORP." },
{ "001F65", "KOREA ELECTRIC TERMINAL CO., LTD." },
{ "001F5F", "Blatand GmbH" },
{ "001F59", "Kronback Tracers" },
{ "001F4D", "Segnetics LLC" },
{ "001F52", "UVT Unternehmensberatung fur Verkehr und Technik GmbH" },
{ "001F0A", "Nortel" },
{ "001F03", "NUM AG" },
{ "001EFE", "LEVEL s.r.o." },
{ "001F04", "Granch Ltd." },
{ "001EF2", "Micro Motion Inc" },
{ "001EF7", "Cisco Systems, Inc" },
{ "001EF1", "Servimat" },
{ "001F9E", "Cisco Systems, Inc" },
{ "001F92", "VideoIQ, Inc." },
{ "001F97", "BERTANA srl" },
{ "001F8B", "Cache IQ" },
{ "001F84", "Gigle Semiconductor" },
{ "001F7F", "Phabrix Limited" },
{ "001CFF", "Napera Networks Inc" },
{ "001CF8", "Parade Technologies, Ltd." },
{ "001CF1", "SUPoX Technology Co. , LTD." },
{ "001CF2", "Tenlon Technology Co.,Ltd." },
{ "001CEC", "Mobilesoft (Aust.) Pty Ltd" },
{ "001CE7", "Rocon PLC Research Centre" },
{ "001CE2", "Attero Tech, LLC." },
{ "001CDB", "CARPOINT CO.,LTD" },
{ "001CD5", "ZeeVee, Inc." },
{ "001CCF", "LIMETEK" },
{ "001E08", "Centec Networks Inc" },
{ "001E03", "LiComm Co., Ltd." },
{ "001DFC", "KSIC" },
{ "001DF5", "Sunshine Co,LTD" },
{ "001DF6", "Samsung Electronics Co.,Ltd" },
{ "001DF0", "Vidient Systems, Inc." },
{ "001DDC", "HangZhou DeChangLong Tech&Info Co.,Ltd" },
{ "001DE4", "Visioneered Image Systems" },
{ "001DE2", "Radionor Communications" },
{ "001CC8", "INDUSTRONIC Industrie-Electronic GmbH & Co. KG" },
{ "001CBC", "CastGrabber, LLC" },
{ "001CB2", "BPT SPA" },
{ "001CA6", "Win4NET" },
{ "001CAB", "Meyer Sound Laboratories, Inc." },
{ "001CAC", "Qniq Technology Corp." },
{ "001CA1", "AKAMAI TECHNOLOGIES, INC." },
{ "001C9C", "Nortel" },
{ "001C95", "Opticomm Corporation" },
{ "001C90", "Empacket Corporation" },
{ "001C8F", "Advanced Electronic Design, Inc." },
{ "001C89", "Force Communications, Inc." },
{ "001C7F", "Check Point Software Technologies" },
{ "001C75", "Segnet Ltd." },
{ "001C6E", "Newbury Networks, Inc." },
{ "001C69", "Packet Vision Ltd" },
{ "001C62", "LG Electronics Inc" },
{ "001DA5", "WB Electronics" },
{ "001DA6", "Media Numerics Limited" },
{ "001DA0", "Heng Yu Electronic Manufacturing Company Limited" },
{ "001D99", "Cyan Optic, Inc." },
{ "001D94", "Climax Technology Co., Ltd" },
{ "001D93", "Modacom" },
{ "001D8D", "Raytek GmbH" },
{ "001D86", "Shinwa Industries(China) Ltd." },
{ "001DC9", "GainSpan Corp." },
{ "001DC2", "XORTEC OY" },
{ "001DBD", "Versamed Inc." },
{ "001DB6", "BestComm Networks, Inc." },
{ "001DB0", "FuJian HengTong Information Technology Co.,Ltd" },
{ "001DAC", "Gigamon Systems LLC" },
{ "001D81", "GUANGZHOU GATEWAY ELECTRONICS CO., LTD" },
{ "001D69", "Knorr-Bremse IT-Services GmbH" },
{ "001D70", "Cisco Systems, Inc" },
{ "001D77", "NSGate" },
{ "001D7C", "ABE Elettronica S.p.A." },
{ "001D64", "Adam Communications Systems Int Ltd" },
{ "001D5D", "Control Dynamics Pty. Ltd." },
{ "001D2E", "Ruckus Wireless" },
{ "001D21", "Alcad SL" },
{ "001D1C", "Gennet s.a." },
{ "001D17", "Digital Sky Corporation" },
{ "001D12", "ROHM CO., LTD." },
{ "001D11", "Analogue & Micro Ltd" },
{ "001D0B", "Power Standards Lab" },
{ "001D04", "Zipit Wireless, Inc." },
{ "001D58", "CQ Inc" },
{ "001D57", "CAETEC Messtechnik" },
{ "001D51", "Babcock & Wilcox Power Generation Group, Inc" },
{ "001D47", "Covote GmbH & Co KG" },
{ "001D40", "Intel – GE Care Innovations LLC" },
{ "001D34", "SYRIS Technology Corp" },
{ "001D2D", "Pylone, Inc." },
{ "001B2A", "Cisco Systems, Inc" },
{ "001B1D", "Phoenix International Co., Ltd" },
{ "001B22", "Palit Microsystems ( H.K.) Ltd." },
{ "001B1B", "Siemens AG," },
{ "001B16", "Celtro Ltd." },
{ "001B0A", "Intelligent Distributed Controls Ltd" },
{ "001B0F", "Petratec" },
{ "001AFE", "SOFACREAL" },
{ "001B03", "Action Technology (SZ) Co., Ltd" },
{ "001B68", "Modnnet Co., Ltd" },
{ "001B62", "JHT Optoelectronics Co.,Ltd." },
{ "001B61", "Digital Acoustics, LLC" },
{ "001B5C", "Azuretec Co., Ltd." },
{ "001B55", "Hurco Automation Ltd." },
{ "001B50", "Nizhny Novgorod Factory named after M.Frunze, FSUE (NZiF)" },
{ "001B44", "SanDisk Corporation" },
{ "001B49", "Roberts Radio limited" },
{ "001B42", "Wise & Blue" },
{ "001B3D", "EuroTel Spa" },
{ "001B36", "Tsubata Engineering Co.,Ltd. (Head Office)" },
{ "001B31", "Neural Image. Co. Ltd." },
{ "001C56", "Pado Systems, Inc." },
{ "001C5B", "Chubb Electronic Security Systems Ltd" },
{ "001C5D", "Leica Microsystems" },
{ "001C5C", "Integrated Medical Systems, Inc." },
{ "001C51", "Celeno Communications" },
{ "001C52", "VISIONEE SRL" },
{ "001C45", "Chenbro Micom Co., Ltd." },
{ "001C4C", "Petrotest Instruments" },
{ "001C39", "S Netsystems Inc." },
{ "001C40", "VDG-Security bv" },
{ "001C32", "Telian Corporation" },
{ "001AC7", "UNIPOINT" },
{ "001AC2", "YEC Co.,Ltd." },
{ "001AB8", "Anseri Corporation" },
{ "001ABD", "Impatica Inc." },
{ "001AB1", "Asia Pacific Satellite Industries Co., Ltd." },
{ "001B8C", "JMicron Technology Corp." },
{ "001B91", "EFKON AG" },
{ "001B87", "Deepsound Tech. Co., Ltd" },
{ "001B82", "Taiwan Semiconductor Co., Ltd." },
{ "001B7B", "The Tintometer Ltd" },
{ "001B74", "MiraLink Corporation" },
{ "001B6F", "Teletrak Ltd" },
{ "001AFC", "ModusLink Corporation" },
{ "001AF2", "Dynavisions Schweiz AG" },
{ "001AF7", "dataschalt e+a GmbH" },
{ "001AED", "INCOTEC GmbH" },
{ "001ADF", "Interactivetv Pty Limited" },
{ "001AE1", "EDGE ACCESS INC" },
{ "001AE6", "Atlanta Advanced Communications Holdings Limited" },
{ "001AD3", "Vamp Ltd." },
{ "001ADA", "Biz-2-Me Inc." },
{ "001ACE", "YUPITERU CORPORATION" },
{ "001BC8", "MIURA CO.,LTD" },
{ "001BC1", "HOLUX Technology, Inc." },
{ "001BB7", "Alta Heights Technology Corp." },
{ "001BAB", "Telchemy, Incorporated" },
{ "001BB0", "BHARAT ELECTRONICS" },
{ "001BA4", "S.A.E Afikim" },
{ "001B9F", "Calyptech Pty Ltd" },
{ "001B98", "Samsung Electronics Co., Ltd." },
{ "001B9D", "Novus Security Sp. z o.o." },
{ "001BF6", "CONWISE Technology Corporation Ltd." },
{ "001BF1", "Nanjing SilverNet Software Co., Ltd." },
{ "001BEC", "Netio Technologies Co., Ltd" },
{ "001BE7", "Postek Electronics Co., Ltd." },
{ "001BE0", "TELENOT ELECTRONIC GmbH" },
{ "001BD9", "Edgewater Computer Systems" },
{ "001BDB", "Valeo VECS" },
{ "001BDA", "UTStarcom Inc" },
{ "001BD4", "Cisco Systems, Inc" },
{ "001BCD", "DAVISCOMMS (S) PTE LTD" },
{ "001C2D", "FlexRadio Systems" },
{ "001C1C", "Center Communication Systems GmbH" },
{ "001C21", "Nucsafe Inc." },
{ "001C20", "CLB Benelux" },
{ "001C17", "Nortel" },
{ "001C15", "iPhotonix LLC" },
{ "001C16", "ThyssenKrupp Elevator" },
{ "001C10", "Cisco-Linksys, LLC" },
{ "001C09", "SAE Electronic Co.,Ltd." },
{ "001C04", "Airgain, Inc." },
{ "001BFD", "Dignsys Inc." },
{ "00192B", "Aclara RF Systems Inc." },
{ "001930", "Cisco Systems, Inc" },
{ "00191F", "Microlink communications Inc." },
{ "001924", "LBNL  Engineering" },
{ "001911", "Just In Mobile Information Technologies (Shanghai) Co., Ltd." },
{ "001918", "Interactive Wear AG" },
{ "00190C", "Encore Electronics, Inc." },
{ "001900", "Intelliverese - DBA Voicecom" },
{ "001905", "SCHRACK Seconet AG" },
{ "0018F4", "EO TECHNICS Co., Ltd." },
{ "0018F6", "Thomson Telecom Belgium" },
{ "0018FB", "Compro Technology" },
{ "0019EE", "CARLO GAVAZZI CONTROLS SPA-Controls Division" },
{ "0019F0", "UNIONMAN TECHNOLOGY CO.,LTD" },
{ "0019F5", "Imagination Technologies Ltd" },
{ "0019E9", "S-Information Technolgy, Co., Ltd." },
{ "0019DB", "MICRO-STAR INTERNATIONAL CO., LTD." },
{ "0019DD", "FEI-Zyfer, Inc." },
{ "0019CA", "Broadata Communications, Inc" },
{ "0019CF", "SALICRU, S.A." },
{ "0019D6", "LS Cable and System Ltd." },
{ "0019B4", "Intellio Ltd" },
{ "001A6E", "Impro Technologies" },
{ "001A67", "Infinite QL Sdn Bhd" },
{ "001A69", "Wuhan Yangtze Optical Technology CO.,Ltd." },
{ "001A62", "Data Robotics, Incorporated" },
{ "001A58", "CCV Deutschland GmbH - Celectronic eHealth Div." },
{ "001A5D", "Mobinnova Corp." },
{ "001A4C", "Crossbow Technology, Inc" },
{ "001A51", "Alfred Mann Foundation" },
{ "001AAA", "Analogic Corp." },
{ "001AA1", "Cisco Systems, Inc" },
{ "001A9C", "RightHand Technologies, Inc." },
{ "001A8B", "CHUNIL ELECTRIC IND., CO." },
{ "001A95", "Hisense Mobile Communications Technoligy Co.,Ltd." },
{ "001A84", "V One Multimedia Pte Ltd" },
{ "0019A1", "LG INFORMATION & COMM." },
{ "0019AD", "BOBST SA" },
{ "0019B2", "XYnetsoft Co.,Ltd" },
{ "00199A", "EDO-EVI" },
{ "00199F", "DKT A/S" },
{ "001995", "Jurong Hi-Tech (Suzhou)Co.ltd" },
{ "001990", "ELM DATA Co., Ltd." },
{ "001989", "Sonitrol Corporation" },
{ "001A3E", "Faster Technology LLC" },
{ "001A40", "A-FOUR TECH CO., LTD." },
{ "001A2D", "The Navvo Group" },
{ "001A32", "ACTIVA MULTIMEDIA" },
{ "001A39", "Merten GmbH&CoKG" },
{ "001A28", "ASWT Co., LTD. Taiwan Branch H.K." },
{ "001A1C", "GT&T Engineering Pte Ltd" },
{ "001A21", "Indac B.V." },
{ "001A23", "Ice Qube, Inc" },
{ "001A15", "gemalto e-Payment" },
{ "001A10", "LUCENT TRANS ELECTRONICS CO.,LTD" },
{ "001A09", "Wayfarer Transit Systems Ltd" },
{ "001A02", "SECURE CARE PRODUCTS, INC" },
{ "001A04", "Interay Solutions BV" },
{ "001984", "ESTIC Corporation" },
{ "001976", "Xipher Technologies, LLC" },
{ "001978", "Datum Systems, Inc." },
{ "00196A", "MikroM GmbH" },
{ "001971", "Guangzhou Unicomp Technology Co.,Ltd" },
{ "001965", "YuHua TelTech (ShangHai) Co., Ltd." },
{ "001960", "DoCoMo Systems, Inc." },
{ "001954", "Leaf Corporation." },
{ "001959", "Staccato Communications Inc." },
{ "00194D", "Avago Technologies Sdn Bhd" },
{ "001948", "AireSpider Networks" },
{ "001941", "Pitney Bowes, Inc" },
{ "001935", "DUERR DENTAL AG" },
{ "00193A", "OESOLUTIONS" },
{ "00193C", "HighPoint Technologies Incorporated" },
{ "001773", "Laketune Technologies Co. Ltd" },
{ "001778", "Central Music Co." },
{ "00177A", "ASSA ABLOY AB" },
{ "00176F", "PAX Computer Technology(Shenzhen) Ltd." },
{ "00176A", "Avago Technologies" },
{ "001763", "Essentia S.p.A." },
{ "00175E", "Zed-3" },
{ "001750", "GSI Group, MicroE Systems" },
{ "001752", "DAGS, Inc" },
{ "001757", "RIX TECHNOLOGY LIMITED" },
{ "00183D", "Vertex Link Corporation" },
{ "001844", "Heads Up Technologies, Inc." },
{ "001838", "PanAccess Communications,Inc." },
{ "001827", "NEC UNIFIED SOLUTIONS NEDERLAND B.V." },
{ "00182C", "Ascend Networks, Inc." },
{ "00182E", "XStreamHD, LLC" },
{ "00181B", "TaiJin Metal Co., Ltd." },
{ "001814", "Mitutoyo Corporation" },
{ "001819", "Cisco Systems, Inc" },
{ "001820", "w5networks" },
{ "001808", "SightLogix, Inc." },
{ "00180D", "Terabytes Server Storage Tech Corp" },
{ "001803", "ArcSoft Shanghai Co. LTD" },
{ "0017F0", "SZCOM Broadband Network Technology Co.,Ltd" },
{ "0017F7", "CEM Solutions Pvt Ltd" },
{ "0017FE", "TALOS SYSTEM INC." },
{ "0017D8", "Magnum Semiconductor, Inc." },
{ "0017DD", "Clipsal Australia" },
{ "0017DF", "Cisco Systems, Inc" },
{ "0018C6", "OPW Fuel Management Systems" },
{ "0018CB", "Tecobest Technology Limited" },
{ "0018BF", "Essence Technology Solution, Inc." },
{ "0018BA", "Cisco Systems, Inc" },
{ "0018B8", "New Voice International AG" },
{ "0018B3", "TEC WizHome Co., Ltd." },
{ "0018AC", "Shanghai Jiao Da HISYS Technology Co. Ltd." },
{ "0018A5", "ADigit Technologies Corp." },
{ "0018A7", "Yoggie Security Systems LTD." },
{ "001896", "Great Well Electronic LTD" },
{ "00189B", "Thomson Inc." },
{ "00179E", "Sirit Inc" },
{ "0017A3", "MIX s.r.l." },
{ "0017A8", "EDM Corporation" },
{ "001792", "Falcom Wireless Comunications Gmbh" },
{ "001797", "Telsy Elettronica S.p.A." },
{ "001799", "SmarTire Systems Inc." },
{ "00178B", "Teledyne Technologies Incorporated" },
{ "00177F", "Worldsmart Retech" },
{ "001786", "wisembed" },
{ "001877", "Amplex A/S" },
{ "00186B", "Sambu Communics CO., LTD." },
{ "001870", "E28 Shanghai Limited" },
{ "001863", "Veritech Electronics Limited" },
{ "001850", "Secfone Kft" },
{ "001855", "Aeromaritime Systembau GmbH" },
{ "001857", "Unilever R&D" },
{ "001849", "Pigeon Point Systems LLC" },
{ "0017C7", "MARA Systems Consulting AB" },
{ "0017CE", "Screen Service Spa" },
{ "0017D3", "Etymotic Research, Inc." },
{ "0017BB", "Syrinx Industrial Electronics" },
{ "0017B4", "Remote Security Systems, LLC" },
{ "0017B6", "Aquantia" },
{ "0017AF", "Enermet" },
{ "0018E8", "Hacetron Corporation" },
{ "0018EF", "Escape Communications, Inc." },
{ "0018E3", "Visualgate Systems, Inc." },
{ "0018DC", "Prostar Co., Ltd." },
{ "0018E1", "Verkerk Service Systemen" },
{ "0018D0", "AtRoad,  A Trimble Company" },
{ "0018D5", "REIGNCOM" },
{ "0018A0", "Cierma Ascenseurs" },
{ "001883", "FORMOSA21 INC." },
{ "00188A", "Infinova LLC" },
{ "00188F", "Montgomery Technology, Inc." },
{ "00187C", "INTERCROSS, LLC" },
{ "00187E", "RGB Spectrum" },
{ "00164A", "Vibration Technology Limited" },
{ "001644", "LITE-ON Technology Corp." },
{ "001645", "Power Distribution, Inc." },
{ "00163B", "VertexRSI/General Dynamics" },
{ "001640", "Asmobile Communication Inc." },
{ "001639", "UBIQUAM Co.,Ltd" },
{ "00163A", "YVES TECHNOLOGY CO., LTD." },
{ "001634", "Mathtech, Inc." },
{ "00162D", "STNet Co., Ltd." },
{ "001628", "Ultra Electronics Manufacturing and Card Systems" },
{ "001621", "Colorado Vnet" },
{ "00161A", "Dametric AB" },
{ "001615", "Nittan Company, Limited" },
{ "0016C4", "SiRF Technology, Inc." },
{ "0016C6", "North Atlantic Industries" },
{ "0016D2", "Caspian" },
{ "0016BF", "PaloDEx Group Oy" },
{ "0016B3", "Photonicbridges (China) Co., Ltd." },
{ "0016AC", "Toho Technology Corp." },
{ "0016B1", "KBS" },
{ "0016A7", "AWETA G&P" },
{ "001724", "Studer Professional Audio GmbH" },
{ "001718", "Vansco Electronics Oy" },
{ "00171D", "DIGIT" },
{ "001711", "GE Healthcare Bio-Sciences AB" },
{ "00170C", "Twig Com Ltd." },
{ "001707", "InGrid, Inc" },
{ "0016FB", "SHENZHEN MTC CO.,LTD." },
{ "001702", "Osung Midicom Co., Ltd" },
{ "001744", "Araneo Ltd." },
{ "00173C", "Extreme Engineering Solutions" },
{ "001737", "Industrie Dial Face S.p.A." },
{ "00172B", "Global Technologies Inc." },
{ "001730", "Automation Electronics" },
{ "001729", "Ubicod Co.LTD" },
{ "00169B", "Alstom Transport" },
{ "0016A2", "CentraLite Systems, Inc." },
{ "001696", "QDI Technology (H.K.) Limited" },
{ "001688", "ServerEngines LLC" },
{ "00168A", "id-Confirm Inc" },
{ "001683", "WEBIO International Co.,.Ltd." },
{ "00167C", "iRex Technologies BV" },
{ "001610", "Carina Technology" },
{ "00160B", "TVWorks LLC" },
{ "001604", "Sigpro" },
{ "0015FE", "SCHILLING ROBOTICS LLC" },
{ "0015FD", "Complete Media Systems" },
{ "0015FF", "Novatel Wireless, Inc." },
{ "0015F8", "Kingtronics Industrial Co. Ltd." },
{ "0015EC", "Boca Devices LLC" },
{ "0015F1", "KYLINK Communications Corp." },
{ "001677", "Bihl + Wiedemann GmbH" },
{ "001670", "SKNET Corporation" },
{ "001664", "Prod-El SpA" },
{ "001669", "MRV Communication (Networks) LTD" },
{ "00165D", "AirDefense, Inc." },
{ "001651", "Exeo Systems" },
{ "0015E5", "Cheertek Inc." },
{ "0015DB", "Canesta Inc." },
{ "0015D4", "Emitor AB" },
{ "0015C8", "FlexiPanel Ltd" },
{ "0015C3", "Ruf Telematik AG" },
{ "0015C2", "3M Germany" },
{ "0015BE", "Iqua Ltd." },
{ "0015B7", "Toshiba" },
{ "0015B9", "Samsung Electronics Co., Ltd." },
{ "0016EF", "Koko Fitness, Inc." },
{ "0016F4", "Eidicom Co., Ltd." },
{ "0016E8", "Sigma Designs, Inc." },
{ "0016ED", "Digital Safety Technologies, Inc" },
{ "0016DC", "ARCHOS" },
{ "0016E1", "SiliconStor, Inc." },
{ "0016D7", "Sunways AG" },
{ "0014CB", "LifeSync Corporation" },
{ "0014D0", "BTI Systems Inc." },
{ "0014C4", "Vitelcom Mobile Technology" },
{ "0014BE", "Wink communication technology CO.LTD" },
{ "0014BD", "incNETWORKS, Inc" },
{ "0014B8", "Hill-Rom" },
{ "0014AE", "Wizlogics Co., Ltd." },
{ "0014B3", "CoreStar International Corp" },
{ "00149B", "Nokota Communications, LLC" },
{ "00143F", "Hotway Technology Corporation" },
{ "001431", "PDL Electronics Ltd" },
{ "001433", "Empower Technologies(Canada) Inc." },
{ "001432", "Tarallax Wireless, Inc." },
{ "00142C", "Koncept International, Inc." },
{ "001425", "Galactic Computing Corp." },
{ "001420", "G-Links networking company" },
{ "00141B", "Cisco Systems, Inc" },
{ "00146D", "RF Technologies" },
{ "00146F", "Kohler Co" },
{ "00146E", "H. Stoll GmbH & Co. KG" },
{ "001468", "CelPlan International, Inc." },
{ "001461", "CORONA CORPORATION" },
{ "00145C", "Intronics B.V." },
{ "001455", "Coder Electronics Corporation" },
{ "001444", "Grundfos Holding" },
{ "00144B", "Hifn, Inc." },
{ "001589", "D-MAX Technology Co.,Ltd" },
{ "00157D", "POSDATA CO., LTD." },
{ "001582", "Pulse Eight Limited" },
{ "00157C", "Dave Networks, Inc." },
{ "001578", "Audio / Video Innovations" },
{ "001573", "NewSoft  Technology Corporation" },
{ "00156C", "SANE SYSTEM CO., LTD" },
{ "001571", "Nolan Systems" },
{ "001572", "Red-Lemon" },
{ "001565", "XIAMEN YEALINK NETWORK TECHNOLOGY CO.,LTD" },
{ "001559", "Securaplane Technologies, Inc." },
{ "0014A2", "Core Micro Systems Inc." },
{ "001494", "ESU AG" },
{ "00148F", "Protronic (Far East) Ltd." },
{ "001488", "Akorri" },
{ "001483", "eXS Inc." },
{ "001480", "Hitachi-LG Data Storage Korea, Inc" },
{ "00147B", "Iteris, Inc." },
{ "001474", "K40 Electronics" },
{ "0015B8", "Tahoe" },
{ "0015B2", "Advanced Industrial Computer, Inc." },
{ "0015AE", "kyung il" },
{ "0015AD", "Accedian Networks" },
{ "00E0A8", "SAT GmbH & Co." },
{ "0015A1", "ECA-SINTERS" },
{ "00159C", "B-KYUNG SYSTEM Co.,Ltd." },
{ "001595", "Quester Tangent Corporation" },
{ "00158E", "Plustek.INC" },
{ "001552", "Wi-Gear Inc." },
{ "001548", "CUBE TECHNOLOGIES" },
{ "00154D", "Netronome Systems, Inc." },
{ "00153C", "Kprotech Co., Ltd." },
{ "001543", "Aberdeen Test Center" },
{ "001535", "OTE Spa" },
{ "001537", "Ventus Networks" },
{ "001536", "Powertech co.,Ltd" },
{ "001530", "EMC Corporation" },
{ "001529", "N3 Corporation" },
{ "0014F9", "Vantage Controls" },
{ "0014FB", "Technical Solutions Inc." },
{ "0014FA", "AsGa S.A." },
{ "0014F4", "DekTec Digital Video B.V." },
{ "0014ED", "Airak, Inc." },
{ "0014DE", "Sage Instruments Inc." },
{ "0014E3", "mm-lab GmbH" },
{ "0014D7", "Datastore Technology Corp" },
{ "001524", "Numatics, Inc." },
{ "00151D", "M2I CORPORATION" },
{ "001513", "EFS sas" },
{ "001507", "Renaissance Learning Inc" },
{ "00129E", "Surf Communications Inc." },
{ "001297", "O2Micro, Inc." },
{ "001298", "MICO ELECTRIC(SHENZHEN) LIMITED" },
{ "00128D", "STB Datenservice GmbH" },
{ "00128E", "Q-Free ASA" },
{ "001292", "Griffin Technology" },
{ "00127C", "SWEGON AB" },
{ "001281", "March Networks S.p.A." },
{ "00127B", "VIA Networking Technologies, Inc." },
{ "001327", "Data Acquisitions limited" },
{ "00131D", "Scanvaegt International A/S" },
{ "001322", "DAQ Electronics, Inc." },
{ "001316", "L-S-B Broadcast Technologies GmbH" },
{ "00130A", "Nortel" },
{ "00130F", "EGEMEN Bilgisayar Muh San ve Tic LTD STI" },
{ "0012F7", "Xiamen Xinglian Electronics Co., Ltd." },
{ "0012FE", "Lenovo Mobile Communication Technology Ltd." },
{ "001303", "GateConnect" },
{ "0012FD", "OPTIMUS IC S.A." },
{ "00140F", "Federal State Unitary Enterprise Leningrad R&D Institute of" },
{ "001416", "Scosche Industries, Inc." },
{ "001406", "Go Networks" },
{ "001407", "Sperian Protection Instrumentation" },
{ "00140C", "GKB CCTV CO., LTD." },
{ "0013FF", "Dage-MTI of MC, Inc." },
{ "001400", "MINERVA KOREA CO., LTD" },
{ "0013FA", "LifeSize Communications, Inc" },
{ "0013F3", "Giga-byte Communications Inc." },
{ "0013EE", "JBX Designs Inc." },
{ "0013ED", "PSIA" },
{ "00135A", "Project T&E Limited" },
{ "00135F", "Cisco Systems, Inc" },
{ "001360", "Cisco Systems, Inc" },
{ "001352", "Naztec, Inc." },
{ "00134B", "ToGoldenNet Technology Inc." },
{ "00134C", "YDT Technology International" },
{ "00133A", "VadaTech Inc." },
{ "00133F", "Eppendorf Instrumente GmbH" },
{ "00132C", "MAZ Brandenburg GmbH" },
{ "001339", "CCV Deutschland GmbH" },
{ "0013AD", "Sendo Ltd" },
{ "0013B4", "Appear TV" },
{ "0013A8", "Tanisys Technology" },
{ "0013A7", "BATTELLE MEMORIAL INSTITUTE" },
{ "0013A1", "Crow Electronic Engeneering" },
{ "00139A", "K-ubique ID Corp." },
{ "001395", "congatec AG" },
{ "00138E", "FOAB Elektronik AB" },
{ "001388", "WiMedia Alliance" },
{ "0013E4", "YANGJAE SYSTEMS CORP." },
{ "0013E9", "VeriWave, Inc." },
{ "0013E3", "CoVi Technologies, Inc." },
{ "0013DD", "Abbott Diagnostics" },
{ "0013D6", "TII NETWORK TECHNOLOGIES, INC." },
{ "0013D1", "KIRK telecom A/S" },
{ "0013CA", "Pico Digital" },
{ "0013C3", "Cisco Systems, Inc" },
{ "0013C4", "Cisco Systems, Inc" },
{ "0013BA", "ReadyLinks Inc" },
{ "0013BE", "Virtual Conexions" },
{ "0013B9", "BM SPA" },
{ "0012F3", "connectBlue AB" },
{ "0012ED", "AVG Advanced Technologies" },
{ "0012E6", "SPECTEC COMPUTER CO., LTD." },
{ "0012E1", "Alliant Networks, Inc" },
{ "0012D3", "Zetta Systems, Inc." },
{ "0012DA", "Cisco Systems, Inc" },
{ "0012D4", "Princeton Technology, Ltd" },
{ "0012C7", "SECURAY Technologies Ltd.Co." },
{ "0012CE", "Advanced Cybernetics Group" },
{ "0012C2", "Apex Electronics Factory" },
{ "0012C1", "Check Point Software Technologies" },
{ "0012B8", "G2 Microsystems" },
{ "0012BD", "Avantec Manufacturing Limited" },
{ "0012B7", "PTW Freiburg" },
{ "0012B1", "Dai Nippon Printing Co., Ltd" },
{ "0012A5", "Stargen, Inc." },
{ "0012AA", "IEE, Inc." },
{ "001379", "PONDER INFORMATION INDUSTRIES LTD." },
{ "001380", "Cisco Systems, Inc" },
{ "001385", "Add-On Technology Co., LTD." },
{ "00137F", "Cisco Systems, Inc" },
{ "00136D", "Tentaculus AB" },
{ "001366", "Neturity Technologies Inc." },
{ "001258", "Activis Polska" },
{ "001251", "SILINK" },
{ "001252", "Citronix, LLC" },
{ "001245", "Zellweger Analytics, Inc." },
{ "00124C", "BBWM Corporation" },
{ "001239", "S Net Systems Inc." },
{ "001240", "AMOI ELECTRONICS CO.,LTD" },
{ "00122D", "SiNett Corporation" },
{ "001232", "LeWiz Communications Inc." },
{ "0011C5", "TEN Technology" },
{ "0011C8", "Powercom Co., Ltd." },
{ "0011CD", "Axsun Technologies" },
{ "0011C6", "Seagate Technology" },
{ "0011B4", "Westermo Teleindustri AB" },
{ "0011B9", "Inner Range Pty. Ltd." },
{ "0011C0", "Aday Technology Inc" },
{ "0011B3", "YOSHIMIYA CO.,LTD." },
{ "0011AD", "Shanghai Ruijie Technology" },
{ "001138", "TAISHIN CO., LTD." },
{ "00113F", "Alcatel DI" },
{ "001133", "Siemens Austria SIMEA" },
{ "001132", "Synology Incorporated" },
{ "001129", "Paradise Datacom Ltd." },
{ "00112E", "CEICOM" },
{ "001128", "Streamit" },
{ "00111B", "Targa Systems Div L-3 Communications Canada" },
{ "001122", "CIMSYS Inc" },
{ "001171", "DEXTER Communications, Inc." },
{ "001165", "Znyx Networks" },
{ "00116A", "Domo Ltd" },
{ "001160", "ARTDIO Company Co., LTD" },
{ "001154", "Webpro Technologies Inc." },
{ "00114B", "Francotyp-Postalia GmbH" },
{ "001145", "ValuePoint Networks" },
{ "0011A1", "VISION NETWARE CO.,LTD" },
{ "0011A6", "Sypixx Networks" },
{ "00119A", "Alkeria srl" },
{ "001190", "Digital Design Corporation" },
{ "00118A", "Viewtran Technology Limited" },
{ "001194", "Chi Mei Communication Systems, Inc." },
{ "001189", "Aerotech Inc" },
{ "001184", "Humo Laboratory,Ltd." },
{ "00117D", "ZMD America, Inc." },
{ "001178", "Chiron Technology Ltd" },
{ "001177", "Coaxial Networks, Inc." },
{ "001223", "Pixim" },
{ "001228", "Data Ltd." },
{ "00121C", "PARROT S.A." },
{ "001210", "WideRay Corp" },
{ "001215", "iStor Networks, Inc." },
{ "001216", "ICP Internet Communication Payment AG" },
{ "001209", "Fastrax Ltd" },
{ "001204", "u10 Networks, Inc." },
{ "0011FD", "KORG INC." },
{ "001203", "ActivNetworks" },
{ "0011F3", "NeoMedia Europe AG" },
{ "0011E7", "WORLDSAT - Texas de France" },
{ "0011EC", "AVIX INC." },
{ "0011E0", "U-MEDIA Communications, Inc." },
{ "0011DA", "Vivaas Technology Inc." },
{ "0011D4", "NetEnrich, Inc" },
{ "0011D9", "TiVo" },
{ "00111C", "Pleora Technologies Inc." },
{ "00110F", "netplat,Inc." },
{ "001116", "COTEAU VERT CO., LTD." },
{ "001109", "Micro-Star International" },
{ "001103", "kawamura electric inc." },
{ "000FFD", "Glorytek Network Inc." },
{ "000FEE", "XTec, Incorporated" },
{ "000FF4", "Guntermann & Drunck GmbH" },
{ "001275", "Sentilla Corporation" },
{ "00126E", "Seidel Elektronik GmbH Nfg.KG" },
{ "001269", "Value Electronics" },
{ "00125C", "Green Hills Software, Inc." },
{ "000F15", "Kjaerulff1 A/S" },
{ "000F1A", "Gaming Support B.V." },
{ "000F0E", "WaveSplitter Technologies, Inc." },
{ "000F08", "Indagon Oy" },
{ "000F07", "Mangrove Systems, Inc." },
{ "000F02", "Digicube Technology Co., Ltd" },
{ "000EFB", "Macey Enterprises" },
{ "000EF5", "iPAC Technology Co., Ltd." },
{ "000EF6", "E-TEN Information Systems Co., Ltd." },
{ "000E8A", "Avara Technologies Pty. Ltd." },
{ "000E83", "Cisco Systems, Inc" },
{ "000E73", "Tpack A/S" },
{ "000E7D", "Electronics Line 3000 Ltd." },
{ "000E77", "Decru, Inc." },
{ "000E7E", "ionSign Oy" },
{ "000E6F", "IRIS Corporation Berhad" },
{ "000E6A", "3Com Ltd" },
{ "000E69", "China Electric Power Research Institute" },
{ "000E63", "Lemke Diagnostics GmbH" },
{ "000EBC", "Paragon Fidelity GmbH" },
{ "000EB0", "Solutions Radio BV" },
{ "000EB5", "Ecastle Electronics Co., Ltd." },
{ "000EAF", "CASTEL" },
{ "000EA9", "Shanghai Xun Shi Communications Equipment Ltd. Co." },
{ "000E9D", "Tiscali UK Ltd" },
{ "000EA2", "McAfee, Inc" },
{ "000E90", "PONICO CORP." },
{ "000E8F", "Sercomm Corp." },
{ "000E96", "Cubic Defense Applications, Inc." },
{ "000F4E", "Cellink" },
{ "000F41", "Zipher Ltd" },
{ "000F48", "Polypix Inc." },
{ "000F4D", "TalkSwitch" },
{ "000F39", "IRIS SENSORS" },
{ "000F3C", "Endeleo Limited" },
{ "000F34", "Cisco Systems, Inc" },
{ "000F2D", "CHUNG-HSIN ELECTRIC & MACHINERY MFG.CORP." },
{ "000F27", "TEAL Electronics, Inc." },
{ "000F28", "Itronix Corporation" },
{ "000F21", "Scientific Atlanta, Inc" },
{ "000EE8", "zioncom" },
{ "000EEF", "Private" },
{ "000EDC", "Tellion INC." },
{ "000EE3", "Chiyu Technology Co.,Ltd" },
{ "000EC8", "Zoran Corporation" },
{ "000ECF", "PROFIBUS Nutzerorganisation e.V." },
{ "000ED4", "CRESITT INDUSTRIE" },
{ "000EC2", "Lowrance Electronics, Inc." },
{ "000EC1", "MYNAH Technologies" },
{ "000F92", "Microhard Systems Inc." },
{ "000F99", "APAC opto Electronics Inc." },
{ "000F8D", "FAST TV-Server AG" },
{ "000F80", "Trinity Security Systems,Inc." },
{ "000F7F", "UBSTORAGE Co.,Ltd." },
{ "000FC2", "Uniwell Corporation" },
{ "000FC9", "Allnet GmbH" },
{ "000FBC", "Onkey Technologies, Inc." },
{ "000FBB", "Nokia Siemens Networks GmbH & Co. KG." },
{ "000FB6", "Europlex Technologies" },
{ "000FA9", "PC Fabrik" },
{ "000FAA", "Nexus Technologies" },
{ "000FAF", "Dialog Inc." },
{ "000FE8", "Lobos, Inc." },
{ "000FED", "Anam Electronics Co., Ltd" },
{ "000FDB", "Westell Technologies" },
{ "000FDC", "Ueda Japan  Radio Co., Ltd." },
{ "000FE1", "ID DIGITAL CORPORATION" },
{ "000FD5", "Schwechat - RISE" },
{ "000FCE", "Kikusui Electronics Corp." },
{ "000F73", "RS Automation Co., Ltd" },
{ "000F7A", "BeiJing NuQX Technology CO.,LTD" },
{ "000F6D", "Midas Engineering" },
{ "000F67", "West Instruments" },
{ "000F6E", "BBox" },
{ "000F60", "Lifetron Co.,Ltd" },
{ "000F5B", "Delta Information Systems, Inc." },
{ "000F54", "Entrelogic Corporation" },
{ "000D75", "Kobian Pte Ltd - Taiwan Branch" },
{ "000D7C", "Codian Ltd" },
{ "000D6F", "Ember Corporation" },
{ "000D69", "TMT&D Corporation" },
{ "000D70", "Datamax Corporation" },
{ "000D5D", "Raritan Computer, Inc" },
{ "000D62", "Funkwerk Dabendorf GmbH" },
{ "000D50", "Galazar Networks" },
{ "000D4A", "Steag ETA-Optik" },
{ "000DAB", "Parker Hannifin GmbH Electromechanical Division Europe" },
{ "000DA7", "Private" },
{ "000DA1", "MIRAE ITS Co.,LTD." },
{ "000DA2", "Infrant Technologies, Inc." },
{ "000D9B", "Heraeus Electro-Nite International N.V." },
{ "000D8F", "King Tsushin Kogyo Co., LTD." },
{ "000D94", "AFAR Communications,Inc" },
{ "000D82", "PHS srl" },
{ "000D81", "Pepperl+Fuchs GmbH" },
{ "000DCE", "Dynavac Technology Pte Ltd" },
{ "000DC8", "AirMagnet, Inc" },
{ "000DC2", "Private" },
{ "000DC7", "COSMIC ENGINEERING INC." },
{ "000DBB", "Nippon Dentsu Co.,Ltd." },
{ "000DB5", "GLOBALSAT TECHNOLOGY CORPORATION" },
{ "000DAF", "Plexus Corp (UK) Ltd" },
{ "000D29", "Cisco Systems, Inc" },
{ "000D23", "Smart Solution, Inc" },
{ "000D17", "Turbo Networks Co.Ltd" },
{ "000D1C", "Amesys Defense" },
{ "000D0A", "Projectiondesign as" },
{ "000D09", "Yuehua(Zhuhai) Electronic CO. LTD" },
{ "000D10", "Embedtronics Oy" },
{ "000D04", "Foxboro Eckardt Development GmbH" },
{ "000CF7", "Nortel Networks" },
{ "000CF8", "Nortel Networks" },
{ "000CFD", "Hyundai ImageQuest Co.,Ltd." },
{ "000D4F", "Kenwood Corporation" },
{ "000D46", "Parker SSD Drives" },
{ "000D42", "Newbest Development Limited" },
{ "000D3C", "i.Tech Dynamic Ltd" },
{ "000D36", "Wu Han Routon Electronic Co., Ltd" },
{ "000D3B", "Microelectronics Technology Inc." },
{ "000D2A", "Scanmatic AS" },
{ "000D2F", "AIN Comm.Tech.Co., LTD" },
{ "000DFA", "Micro Control Systems Ltd." },
{ "000DF4", "Watertek Co." },
{ "000DF9", "NDS Limited" },
{ "000E00", "Atrie" },
{ "000DE7", "Snap-on OEM Group" },
{ "000DE8", "Nasaco Electronics Pte. Ltd" },
{ "000DED", "Cisco Systems, Inc" },
{ "000DE1", "Control Products, Inc." },
{ "000DD5", "O'RITE TECHNOLOGY CO.,LTD" },
{ "000DDA", "ALLIED TELESIS K.K." },
{ "000E20", "ACCESS Systems Americas, Inc." },
{ "000E27", "Crere Networks, Inc." },
{ "000E14", "Visionary Solutions, Inc." },
{ "000E1B", "IAV GmbH" },
{ "000E57", "Iworld Networking, Inc." },
{ "000E50", "Thomson Telecom Belgium" },
{ "000E4A", "Changchun Huayu WEBPAD Co.,LTD" },
{ "000E49", "Forsway Scandinavia AB" },
{ "000E3D", "Televic N.V." },
{ "000E44", "Digital 5, Inc." },
{ "000E33", "Shuko Electronics Co.,Ltd" },
{ "000E3A", "Cirrus Logic" },
{ "000E2D", "Hyundai Digital Technology Co.,Ltd." },
{ "000CEA", "aphona Kommunikationssysteme" },
{ "000CD9", "Itcare Co., Ltd" },
{ "000CD3", "Prettl Elektronik Radeberg GmbH" },
{ "000CDA", "FreeHand Systems, Inc." },
{ "000CDF", "PULNiX America, Inc" },
{ "000CC7", "Intelligent Computer Solutions Inc." },
{ "000CCC", "Aeroscout Ltd." },
{ "000C13", "MediaQ" },
{ "000C05", "RPA Reserch Co., Ltd." },
{ "000C0C", "APPRO TECHNOLOGY INC." },
{ "000BF4", "Private" },
{ "000BF9", "Gemstone Communications, Inc." },
{ "000C00", "BEB Industrie-Elektronik AG" },
{ "000BF3", "BAE SYSTEMS" },
{ "000C63", "Zenith Electronics Corporation" },
{ "000C68", "SigmaTel, Inc." },
{ "000C6F", "Amtek system co.,LTD." },
{ "000C50", "Seagate Technology" },
{ "000C55", "Microlink Communications Inc." },
{ "000C5C", "GTN Systems B.V." },
{ "000C61", "AC Tech corporation DBA Advanced Digital" },
{ "000C49", "Dangaard Telecom RTC Division A/S" },
{ "000CBA", "Jamex, Inc." },
{ "000CB9", "LEA" },
{ "000CC0", "Genera Oy" },
{ "000CB4", "AutoCell Laboratories, Inc." },
{ "000C34", "Vixen Co., Ltd." },
{ "000CA2", "Harmonic Video Network" },
{ "000CA7", "Metro (Suzhou) Technologies Co., Ltd." },
{ "000CA9", "Ebtron Inc." },
{ "000CAE", "Ailocom Oy" },
{ "000C42", "Routerboard.com" },
{ "000C44", "Automated Interfaces, Inc." },
{ "000C39", "Sentinel Wireless Inc." },
{ "000C3B", "Orion Electric Co., Ltd." },
{ "000C40", "Altech Controls" },
{ "000C3A", "Oxance" },
{ "000C2F", "SeorimTechnology Co.,Ltd." },
{ "000C31", "Cisco Systems, Inc" },
{ "000C2A", "OCTTEL Communication Co., Ltd." },
{ "000C27", "Sammy Corporation" },
{ "000C18", "Zenisu Keisoku Inc." },
{ "000C20", "Fi WIn, Inc." },
{ "000BED", "ELM Inc." },
{ "000BF2", "Chih-Kan Technology Co., Ltd." },
{ "000BE1", "Nokia NET Product Operations" },
{ "000BE6", "Datel Electronics" },
{ "000BDA", "EyeCross Co.,Inc." },
{ "000BD1", "Aeronix, Inc." },
{ "000BC5", "SMC Networks, Inc." },
{ "000BCC", "JUSAN, S.A." },
{ "000BB9", "Imsys AB" },
{ "000BBE", "Cisco Systems, Inc" },
{ "000BB2", "SMALLBIG TECHNOLOGY" },
{ "000BB7", "Micro Systems Co.,Ltd." },
{ "000C96", "OQO, Inc." },
{ "000C9B", "EE Solutions, Inc" },
{ "000C8A", "Bose Corporation" },
{ "000C8F", "Nergal s.r.l." },
{ "000C83", "Logical Solutions" },
{ "000C88", "Apache Micro Peripherals, Inc." },
{ "000C74", "RIVERTEC CORPORATION" },
{ "000C76", "MICRO-STAR INTERNATIONAL CO., LTD." },
{ "000C7B", "ALPHA PROJECT Co.,Ltd." },
{ "000B85", "Cisco Systems, Inc" },
{ "000B7F", "Align Engineering LLC" },
{ "000B84", "BODET" },
{ "000B73", "Kodeos Communications" },
{ "000B78", "TAIFATECH INC." },
{ "000B6C", "Sychip Inc." },
{ "000B60", "Cisco Systems, Inc" },
{ "000B65", "Sy.A.C. srl" },
{ "000B57", "Silicon Laboratories" },
{ "000B5C", "Newtech Co.,Ltd" },
{ "000B4F", "Verifone, INC." },
{ "000B43", "Microscan Systems, Inc." },
{ "000B48", "sofrel" },
{ "000B4A", "Visimetrics (UK) Ltd" },
{ "000B35", "Quad Bit System co., Ltd." },
{ "000B37", "MANUFACTURE DES MONTRES ROLEX SA" },
{ "000B3C", "Cygnal Integrated Products, Inc." },
{ "000B29", "LS(LG) Industrial Systems co.,Ltd" },
{ "000B30", "Beijing Gongye Science & Technology Co.,Ltd" },
{ "000BA1", "SYSCOM Ltd." },
{ "000BA8", "HANBACK ELECTRONICS CO., LTD." },
{ "000B92", "Ascom Danmark A/S" },
{ "000B97", "Matsushita Electric Industrial Co.,Ltd." },
{ "000B9C", "TriBeam Technologies, Inc." },
{ "000B8B", "KERAJET, S.A." },
{ "0009D6", "KNC One GmbH" },
{ "0009D5", "Signal Communication, Inc." },
{ "0009DC", "Galaxis Technology AG" },
{ "0009C9", "BlueWINC Co., Ltd." },
{ "0009D0", "Solacom Technologies Inc." },
{ "0009BC", "Digital Safety Technologies, Inc" },
{ "0009C1", "PROCES-DATA A/S" },
{ "0009C4", "Medicore Co., Ltd" },
{ "00098F", "Cetacean Networks" },
{ "00097D", "SecWell Networks Oy" },
{ "00097E", "IMI TECHNOLOGY CO., LTD" },
{ "000983", "GlobalTop Technology, Inc." },
{ "000970", "Vibration Research Corporation" },
{ "000977", "Brunner Elektronik AG" },
{ "000964", "Hi-Techniques, Inc." },
{ "00096B", "IBM Corp" },
{ "000957", "Supercaller, Inc." },
{ "00095C", "Philips Medical Systems - Cardiac and Monitoring Systems (CM" },
{ "000AE3", "YANG MEI TECHNOLOGY CO., LTD" },
{ "000AEA", "ADAM ELEKTRONIK LTD. ŞTI" },
{ "000ADE", "Happy Communication Co., Ltd." },
{ "000AD7", "Origin ELECTRIC CO.,LTD." },
{ "000ACB", "XPAK MSA Group" },
{ "000AD0", "Niigata Develoment Center,  F.I.T. Co., Ltd." },
{ "000AD2", "JEPICO Corporation" },
{ "000ABD", "Rupprecht & Patashnick Co." },
{ "000ABF", "HIROTA SS" },
{ "000AC4", "Daewoo Teletech Co., Ltd" },
{ "000AAC", "TerraTec Electronic GmbH" },
{ "000AB1", "GENETEC Corporation" },
{ "000AB8", "Cisco Systems, Inc" },
{ "000AA5", "MAXLINK INDUSTRIES LIMITED" },
{ "000A8D", "EUROTHERM LIMITED" },
{ "000A9E", "BroadWeb Corportation" },
{ "000AA0", "Cedar Point Communications" },
{ "000A98", "M+F Gwinner GmbH & Co" },
{ "000A92", "Presonus Corporation" },
{ "000A7E", "The Advantage Group" },
{ "000A85", "PLAT'C2,Inc" },
{ "000A8A", "Cisco Systems, Inc" },
{ "0009B5", "3J Tech. Co., Ltd." },
{ "0009AF", "e-generis" },
{ "0009B0", "Onkyo Corporation" },
{ "0009A9", "Ikanos Communications" },
{ "00099D", "Haliplex Communications" },
{ "0009A2", "Interface Co., Ltd." },
{ "000990", "ACKSYS Communications & systems" },
{ "000996", "RDI" },
{ "00098A", "EqualLogic Inc" },
{ "000A77", "Bluewire Technologies LLC" },
{ "000A79", "corega K.K" },
{ "000A72", "STEC, INC." },
{ "000A5F", "almedio inc." },
{ "000A66", "MITSUBISHI ELECTRIC SYSTEM & SERVICE CO.,LTD." },
{ "000A6B", "Tadiran Telecom Business Systems LTD" },
{ "000A5A", "GreenNET Technologies Co.,Ltd." },
{ "000A53", "Intronics, Incorporated" },
{ "000A58", "Freyer & Siegel Elektronik GmbH & Co. KG" },
{ "000A4C", "Molecular Devices Corporation" },
{ "000B24", "AirLogic" },
{ "000B1D", "LayerZero Power Systems, Inc." },
{ "000B16", "Communication Machinery Corporation" },
{ "000B18", "Private" },
{ "000B11", "HIMEJI ABC TRADING CO.,LTD." },
{ "000B0A", "dBm Optics" },
{ "000B05", "Pacific Broadband Networks" },
{ "000AFE", "NovaPal Ltd" },
{ "000B03", "Taekwang Industrial Co., Ltd" },
{ "000AEF", "OTRUM ASA" },
{ "000AF2", "NeoAxiom Corp." },
{ "000A05", "Widax Corp." },
{ "000A08", "ALPINE ELECTRONICS, INC." },
{ "000A0A", "SUNIX Co., Ltd." },
{ "000A0F", "Ilryung Telesys, Inc" },
{ "0009FF", "X.net 2000 GmbH" },
{ "0009FE", "Daisy Technologies, Inc." },
{ "000A00", "Mediatek Corp." },
{ "0009F6", "Shenzhen Eastern Digital Tech Ltd." },
{ "0009F5", "Emerson Network Power Co.,Ltd" },
{ "0009E8", "Cisco Systems, Inc" },
{ "0009EF", "Vocera Communications" },
{ "0009E3", "Angel Iglesias S.A." },
{ "000A39", "LoPA Information Technology" },
{ "000A40", "Crown Audio -- Harmanm International" },
{ "000A45", "Audio-Technica Corp." },
{ "000A47", "Allied Vision Technologies" },
{ "000A34", "Identicard Systems Incorporated" },
{ "000A2D", "Cabot Communications Limited" },
{ "000A22", "Amperion Inc" },
{ "000A16", "Lassen Research" },
{ "000A1B", "Stream Labs" },
{ "000878", "Benchmark Storage Innovations" },
{ "000872", "Sorenson Communications" },
{ "00087E", "Bon Electro-Telecom Inc." },
{ "00086B", "MIPSYS" },
{ "000865", "JASCOM CO., LTD" },
{ "000866", "DSX Access Systems, Inc." },
{ "00085F", "Picanol N.V." },
{ "000859", "ShenZhen Unitone Electronics Co., Ltd." },
{ "000853", "Schleicher GmbH & Co. Relaiswerke KG" },
{ "000858", "Novatechnology Inc." },
{ "00081D", "Ipsil, Incorporated" },
{ "000829", "Aval Nagasaki Corporation" },
{ "000823", "Texa Corp." },
{ "00082A", "Powerwallz Network Security" },
{ "000817", "EmergeCore Networks LLC" },
{ "00091E", "Firstech Technology Corp." },
{ "000925", "VSN Systemen BV" },
{ "000918", "SAMSUNG TECHWIN CO.,LTD" },
{ "000917", "WEM Technology Inc" },
{ "000912", "Cisco Systems, Inc" },
{ "00090B", "MTL  Instruments PLC" },
{ "000905", "iTEC Technologies Ltd." },
{ "0008FF", "Trilogy Communications Ltd" },
{ "000906", "Esteem Networks" },
{ "0008FB", "SonoSite, Inc." },
{ "0008F1", "Voltaire" },
{ "0008F2", "C&S Technology" },
{ "0008F7", "Hitachi Ltd, Semiconductor & Integrated Circuits Gr" },
{ "0008ED", "ST&T Instrument Corp." },
{ "0007D1", "Spectrum Signal Processing Inc." },
{ "0007CE", "Cabletime Limited" },
{ "0007C8", "Brain21, Inc." },
{ "0007BC", "Identix Inc." },
{ "00047C", "Skidata AG" },
{ "0007BB", "Candera Inc." },
{ "0007C2", "Netsys Telecom" },
{ "0007B5", "Any One Wireless Ltd." },
{ "0007AF", "Red Lion Controls, LP" },
{ "0007A2", "Opteon Corporation" },
{ "0007A7", "A-Z Inc." },
{ "0007A1", "VIASYS Healthcare GmbH" },
{ "0007A8", "Haier Group Technologies Ltd." },
{ "00094A", "Homenet Communications" },
{ "000949", "Glyph Technologies Inc." },
{ "000950", "Independent Storage Corporation" },
{ "000944", "Cisco Systems, Inc" },
{ "00093D", "Newisys,Inc." },
{ "000937", "Inventec Appliance Corp" },
{ "000931", "Future Internet, Inc." },
{ "000938", "Allot Communications" },
{ "00092A", "MYTECS Co.,Ltd." },
{ "0008B1", "ProQuent Systems" },
{ "0008AB", "EnerLinx.com, Inc." },
{ "0008AC", "Eltromat GmbH" },
{ "0008A5", "Peninsula Systems Inc." },
{ "000899", "Netbind, Inc." },
{ "00089E", "Beijing Enter-Net co.LTD" },
{ "000895", "DIRC Technologie GmbH & Co.KG" },
{ "000891", "Lyan Inc." },
{ "00088B", "Tropic Networks Inc." },
{ "00088A", "Minds@Work" },
{ "000885", "EMS Dr. Thomas Wünsche" },
{ "0008E8", "Excel Master Ltd." },
{ "0008E7", "SHI ControlSystems,Ltd." },
{ "0008E1", "Barix AG" },
{ "0008DA", "SofaWare Technologies Ltd." },
{ "0008D5", "Vanguard Networks Solutions, LLC" },
{ "0008CE", "IPMobileNet Inc." },
{ "0008C8", "Soneticom, Inc." },
{ "0008C4", "Hikari Co.,Ltd." },
{ "0008BE", "XENPAK MSA Group" },
{ "0008B8", "E.F. Johnson" },
{ "00079B", "Aurora Networks" },
{ "00078F", "Emkay Innovative Products" },
{ "000788", "Clipcomm, Inc." },
{ "000779", "Sungil Telecom Co., Ltd." },
{ "000778", "GERSTEL GmbH & Co. KG" },
{ "000772", "Alcatel Shanghai Bell Co., Ltd." },
{ "00076C", "Daehanet, Inc." },
{ "00075C", "Eastman Kodak Company" },
{ "000761", "Logitech Europe SA" },
{ "000768", "Danfoss A/S" },
{ "000762", "Group Sense Limited" },
{ "000755", "Lafon" },
{ "00074F", "Cisco Systems, Inc" },
{ "000741", "Sierra Automated Systems" },
{ "000749", "CENiX Inc." },
{ "000735", "Flarion Technologies, Inc." },
{ "00073B", "Tenovis GmbH & Co KG" },
{ "000729", "Kistler Instrumente AG" },
{ "00072E", "North Node AB" },
{ "000728", "Neo Telecom" },
{ "000718", "iCanTek Co., Ltd." },
{ "00080D", "Toshiba" },
{ "000806", "Raonet Systems, Inc." },
{ "0007FD", "LANergy Ltd." },
{ "0007F6", "Qqest Software Systems" },
{ "0007FC", "Adept Systems Inc." },
{ "0007EA", "Massana, Inc." },
{ "0007F0", "LogiSync LLC" },
{ "0007E3", "Navcom Technology, Inc." },
{ "0007E4", "SoftRadio Co., Ltd." },
{ "0007DD", "Cradle Technologies" },
{ "0007D7", "Caporis Networks AG" },
{ "0006E3", "Quantitative Imaging Corporation" },
{ "0006DD", "AT & T Laboratories - Cambridge Ltd" },
{ "0006A4", "INNOWELL Corp." },
{ "0006D3", "Alpha Telecom, Inc. U.S.A." },
{ "0006D2", "Tundra Semiconductor Corp." },
{ "000647", "Etrali S.A." },
{ "0006D9", "IPM-Net S.p.A." },
{ "0005EA", "Rednix" },
{ "0006CD", "Leaf Imaging Ltd." },
{ "0006BC", "Macrolink, Inc." },
{ "0006C6", "lesswire AG" },
{ "000654", "Winpresa Building Automation Technologies GmbH" },
{ "0006B6", "Nir-Or Israel Ltd." },
{ "0006B0", "Comtech EF Data Corp." },
{ "00071F", "European Systems Integration" },
{ "000724", "Telemax Co., Ltd." },
{ "000707", "Interalia Inc." },
{ "00070C", "SVA-Intrusion.com Co. Ltd." },
{ "000711", "Acterna" },
{ "000712", "JAL Information Technology" },
{ "0006FA", "IP SQUARE Co, Ltd." },
{ "0006EF", "Maxxan Systems, Inc." },
{ "0006EA", "ELZET80 Mikrocomputer GmbH&Co. KG" },
{ "0006E9", "Intime Corp." },
{ "0005EB", "Blue Ridge Networks, Inc." },
{ "0005F7", "Analog Devices, Inc." },
{ "0005E4", "Red Lion Controls Inc." },
{ "0005F1", "Vrcom, Inc." },
{ "0005FD", "PacketLight Networks Ltd." },
{ "0005E2", "Creativ Network Technologies" },
{ "0005DC", "Cisco Systems, Inc" },
{ "0005E1", "Trellis Photonics, Ltd." },
{ "0005D8", "Arescom, Inc." },
{ "0005D7", "Vista Imaging, Inc." },
{ "0005C5", "Flaga HF" },
{ "0005D1", "Metavector Technologies" },
{ "0005D2", "DAP Technologies" },
{ "0005CB", "ROIS Technologies, Inc." },
{ "00057F", "Acqis Technology" },
{ "000579", "Universal Control Solution Corp." },
{ "000575", "CDS-Electronics BV" },
{ "00056F", "Innomedia Technologies Pvt. Ltd." },
{ "000569", "VMware, Inc." },
{ "000568", "Piltofish Networks AB" },
{ "000562", "Digital View Limited" },
{ "00055C", "Kowa Company, Ltd." },
{ "000556", "360 Systems" },
{ "000550", "Vcomms Connect Limited" },
{ "000545", "Internet Photonics" },
{ "00053F", "VisionTek, Inc." },
{ "000546", "KDDI Network & Solultions Inc." },
{ "0006AA", "VT Miltope" },
{ "0006A9", "Universal Instruments Corp." },
{ "0006A0", "Mx Imaging" },
{ "00069F", "Kuokoa Networks" },
{ "000699", "Vida Design Co." },
{ "000693", "Flexus Computer Technology, Inc." },
{ "00069A", "e & Tel" },
{ "00068D", "SEPATON, Inc." },
{ "000687", "Omnitron Systems Technology, Inc." },
{ "000680", "Card Access, Inc." },
{ "000539", "A Brand New World in Sweden AB" },
{ "000526", "IPAS GmbH" },
{ "00052D", "Zoltrix International Limited" },
{ "00052C", "Supreme Magic Corporation" },
{ "000520", "Smartronix, Inc." },
{ "00051A", "3COM EUROPE LTD." },
{ "000510", "Infinite Shanghai Communication Terminals Ltd." },
{ "000514", "KDT Systems Co., Ltd." },
{ "000509", "AVOC Nishimura Ltd." },
{ "000503", "ICONAG" },
{ "00050A", "ICS Spa" },
{ "0004FF", "Acronet Co., Ltd." },
{ "000500", "Cisco Systems, Inc" },
{ "000641", "ITCN" },
{ "00063D", "Microwave Data Systems Inc." },
{ "000631", "Calix" },
{ "000630", "Adtranz Sweden" },
{ "000637", "Toptrend-Meta Information (ShenZhen) Inc." },
{ "000620", "Serial System Ltd." },
{ "00061A", "Zetari Inc." },
{ "00060C", "Melco Industries, Inc." },
{ "000614", "Prism Holdings" },
{ "000606", "RapidWAN, Inc." },
{ "000677", "SICK AG" },
{ "000673", "TKH Security Solutions USA" },
{ "000666", "Roving Networks" },
{ "00066D", "Compuprint S.P.A." },
{ "00066C", "Robinson Corporation" },
{ "000653", "Cisco Systems, Inc" },
{ "00065A", "Strix Systems" },
{ "00064D", "Sencore" },
{ "000660", "NADEX Co., Ltd." },
{ "0005B8", "Electronic Design Associates, Inc." },
{ "0005BF", "JustEzy Technology, Inc." },
{ "0005AE", "Mediaport USA" },
{ "0005B2", "Medison Co., Ltd." },
{ "00059E", "Zinwell Corporation" },
{ "0005A5", "KOTT" },
{ "000598", "CRONOS S.r.l." },
{ "0005A4", "Lucid Voice Ltd." },
{ "000592", "Pultek Corp." },
{ "00058B", "IPmental, Inc." },
{ "00058C", "Opentech Inc." },
{ "00037E", "PORTech Communications, Inc." },
{ "000383", "Metera Networks, Inc." },
{ "000377", "Gigabit Wireless" },
{ "00037B", "IDEC IZUMI Corporation" },
{ "00036B", "Cisco Systems, Inc" },
{ "000372", "ULAN" },
{ "000367", "Jasmine Networks, Inc." },
{ "00036A", "Mainnet, Ltd." },
{ "000364", "Scenix Semiconductor, Inc." },
{ "00035F", "Prüftechnik Condition Monitoring GmbH & Co. KG" },
{ "00035C", "Saint Song Corp." },
{ "000358", "Hanyang Digitech Co., Ltd." },
{ "00034D", "Chiaro Networks, Ltd." },
{ "0003FA", "TiMetra Networks" },
{ "0003F5", "Chip2Chip" },
{ "0003EE", "MKNet Corporation" },
{ "0003E8", "Wavelength Digital Limited" },
{ "0003E3", "Cisco Systems, Inc" },
{ "0003DC", "Lexar Media, Inc." },
{ "0003D7", "NextNet Wireless, Inc." },
{ "0003D4", "Alloptic, Inc." },
{ "00030B", "Hunter Technology, Inc." },
{ "0003D0", "KOANKEISO Co., Ltd." },
{ "0003C9", "TECOM Co., Ltd." },
{ "0003C4", "Tomra Systems ASA" },
{ "0004FA", "NBS Technologies Inc." },
{ "0004F9", "Xtera Communications, Inc." },
{ "0004F3", "FS FORTH-SYSTEME GmbH" },
{ "0004E7", "Lightpointe Communications, Inc" },
{ "0004ED", "Billion Electric Co., Ltd." },
{ "0004DD", "Cisco Systems, Inc" },
{ "0004D6", "Takagi Industrial Co., Ltd." },
{ "0004D0", "Softlink s.r.o." },
{ "0004CA", "FreeMs Corp." },
{ "0004BE", "OptXCon, Inc." },
{ "0004C3", "CASTOR Informatique" },
{ "0004C4", "Allen & Heath Limited" },
{ "0004B7", "AMB i.t. Holding" },
{ "0004B1", "Signal Technology, Inc." },
{ "0004AD", "Malibu Networks" },
{ "0004AA", "Jetstream Communications" },
{ "0004A3", "Microchip Technology, Inc." },
{ "00049D", "Ipanema Technologies" },
{ "000497", "MacroSystem Digital Video AG" },
{ "000490", "Optical Access" },
{ "00048B", "Poscon Corporation" },
{ "000341", "Axon Digital Design" },
{ "00033E", "Tateyama System Laboratory Co., Ltd." },
{ "00033A", "Silicon Wave, Inc." },
{ "000333", "Digitel Co., Ltd." },
{ "00032B", "GAI Datenfunksysteme GmbH" },
{ "000327", "ACT'L" },
{ "00032E", "Scope Information Management, Ltd." },
{ "000322", "IDIS Co., Ltd." },
{ "00031E", "Optranet, Inc." },
{ "00B052", "Atheros Communications" },
{ "000319", "Infineon AG" },
{ "000316", "Nobell Communications, Inc." },
{ "000312", "TR-Systemtechnik GmbH" },
{ "000447", "Acrowave Systems Co., Ltd." },
{ "00043B", "Lava Computer Mfg., Inc." },
{ "000440", "cyberPIXIE, Inc." },
{ "00043A", "Intelligent Telecommunications, Inc." },
{ "000434", "Accelent Systems, Inc." },
{ "00042D", "Sarian Systems, Ltd." },
{ "00042E", "Netous Technologies, Ltd." },
{ "000428", "Cisco Systems, Inc" },
{ "000421", "Ocular Networks" },
{ "000417", "ELAU AG" },
{ "000411", "Inkra Networks, Inc." },
{ "00040B", "3COM EUROPE LTD." },
{ "000404", "Makino Milling Machine Co., Ltd." },
{ "000481", "Econolite Control Products, Inc." },
{ "000486", "ITTC, University of Kansas" },
{ "000477", "Scalant Systems, Inc." },
{ "000476", "3 Com Corporation" },
{ "000469", "Innocom, Inc." },
{ "000470", "ipUnplugged AB" },
{ "00046A", "Navini Networks" },
{ "000464", "Pulse-Link Inc" },
{ "00045D", "BEKA Elektronik" },
{ "0003B2", "Radware" },
{ "000457", "Universal Access Technology, Inc." },
{ "000451", "Medrad, Inc." },
{ "0003C1", "Packet Dynamics Ltd" },
{ "0003BD", "OmniCluster Technologies, Inc." },
{ "0003B8", "NetKit Solutions, LLC" },
{ "0003B6", "QSI Corporation" },
{ "0003A6", "Traxit Technology, Inc." },
{ "0003AB", "Bridge Information Systems" },
{ "0003A3", "MAVIX, Ltd." },
{ "00039F", "Cisco Systems, Inc" },
{ "00039A", "SiConnect" },
{ "00038C", "Total Impact" },
{ "000384", "AETA" },
{ "000387", "Blaze Network Products" },
{ "000306", "Fusion In Tech Co., Ltd." },
{ "000303", "JAMA Electronics Co., Ltd." },
{ "0002FF", "Handan BroadInfoCom" },
{ "0002F3", "Media Serve Co., Ltd." },
{ "0002FA", "DX Antenna Co., Ltd." },
{ "0002ED", "DXO Telecom Co., Ltd." },
{ "0002E5", "Timeware Ltd." },
{ "0002E8", "E.D.&A." },
{ "0002DC", "Fujitsu General Limited" },
{ "0002E1", "Integrated Network Corporation" },
{ "0002D5", "ACR" },
{ "0002C9", "Mellanox Technologies" },
{ "0002CE", "FoxJet, Inc." },
{ "00B0DB", "Nextcell, Inc." },
{ "00B08E", "Cisco Systems, Inc" },
{ "00B01C", "Westport Technologies" },
{ "00B02D", "ViaGate Technologies, Inc." },
{ "00B03B", "HiQ Networks" },
{ "0030A9", "Netiverse, Inc." },
{ "00B0F0", "CALY NETWORKS" },
{ "00B086", "LocSoft Limited" },
{ "0030C4", "Canon Imaging Systems Inc." },
{ "00309D", "Nimble Microsystems, Inc." },
{ "003037", "Packard Bell Nec Services" },
{ "00302E", "Hoft & Wessel AG" },
{ "00301B", "SHUTTLE, INC." },
{ "003028", "FASE Saldatura srl" },
{ "0030FB", "AZS Technology AG" },
{ "003048", "Supermicro Computer, Inc." },
{ "0001DA", "WINCOMM Corporation" },
{ "0001E1", "Kinpo Electronics, Inc." },
{ "0001DD", "Avail Networks" },
{ "0001CE", "Custom Micro Products, Ltd." },
{ "0001CA", "Geocast Network Systems, Inc." },
{ "0001B8", "Netsensity, Inc." },
{ "0001BD", "Peterson Electro-Musical Products, Inc." },
{ "0001B4", "Wayport, Inc." },
{ "0001C3", "Acromag, Inc." },
{ "0001BF", "Teleforce Co., Ltd." },
{ "0001AD", "Coach Master International  d.b.a. CMI Worldwide, Inc." },
{ "00017E", "ADTEK System Science Co., Ltd." },
{ "00018A", "ROI COMPUTER AG" },
{ "000119", "RTUnet (Australia)" },
{ "000125", "YAESU MUSEN CO., LTD." },
{ "000121", "Watchguard Technologies, Inc." },
{ "000128", "EnjoyWeb, Inc." },
{ "000106", "Tews Datentechnik GmbH" },
{ "000112", "Shark Multimedia Inc." },
{ "000102", "3COM CORPORATION" },
{ "000115", "EXTRATECH CORPORATION" },
{ "000109", "Nagano Japan Radio Co., Ltd." },
{ "081443", "UNIBRAIN S.A." },
{ "00B0F5", "NetWorth Technologies, Inc." },
{ "00B019", "UTC CCS" },
{ "00B02A", "ORSYS GmbH" },
{ "00B0AE", "Symmetricom" },
{ "000181", "Nortel Networks" },
{ "00018D", "AudeSi Technologies" },
{ "00019A", "LEUNIG GmbH" },
{ "000193", "Hanbyul Telecom Co., Ltd." },
{ "0001A2", "Logical Co., Ltd." },
{ "000196", "Cisco Systems, Inc" },
{ "0001A6", "Scientific-Atlanta Arcodan A/S" },
{ "000172", "TechnoLand Co., LTD." },
{ "00303F", "TurboComm Tech Inc." },
{ "003073", "International Microsystems, In" },
{ "00014D", "Shin Kin Enterprises Co., Ltd" },
{ "00016B", "LightChip, Inc." },
{ "000167", "HIOKI E.E. CORPORATION" },
{ "000215", "Cotas Computer Technology A/B" },
{ "000211", "Nature Worldwide Technology Corp." },
{ "000209", "Shenzhen SED Information Technology Co., Ltd." },
{ "000205", "Hitachi Denshi, Ltd." },
{ "000202", "Amino Communications, Ltd." },
{ "0001F6", "Association of Musical Electronics Industry" },
{ "0001ED", "SETA Corp." },
{ "0001E9", "Litton Marine Systems B.V." },
{ "0002C6", "Data Track Technology PLC" },
{ "0002C2", "Net Vision Telecom" },
{ "0002B9", "Cisco Systems, Inc" },
{ "0002B4", "DAPHNE" },
{ "0002AD", "HOYA Corporation" },
{ "0002A6", "Effinet Systems Co., Ltd." },
{ "0002A1", "World Wide Packets" },
{ "00029B", "Kreatel Communications AB" },
{ "00029E", "Information Equipment Co., Ltd." },
{ "000296", "Lectron Co,. Ltd." },
{ "00028F", "Globetek, Inc." },
{ "000289", "DNE Technologies" },
{ "000285", "Riverstone Networks" },
{ "00027E", "Cisco Systems, Inc" },
{ "000280", "Mu Net, Inc." },
{ "000279", "Control Applications, Ltd." },
{ "000272", "CC&C Technologies, Inc." },
{ "00026B", "BCM Computers Co., Ltd." },
{ "00026D", "Adept Telecom" },
{ "000262", "Soyo Group Soyo Com Tech Co., Ltd" },
{ "000260", "Accordion Networks, Inc." },
{ "00025B", "Cambridge Silicon Radio" },
{ "000087", "HITACHI, LTD." },
{ "000252", "Carrier Corporation" },
{ "00024B", "Cisco Systems, Inc" },
{ "000246", "All-Win Tech Co., Ltd." },
{ "00017A", "Chengdu Maipu Electric Industrial Co., Ltd." },
{ "000235", "Paragon Networks International" },
{ "000238", "Serome Technology, Inc." },
{ "000230", "Intersoft Electronics" },
{ "000229", "Adtec Corporation" },
{ "000225", "One Stop Systems" },
{ "00021C", "Network Elements, Inc." },
{ "000221", "DSP Application, Ltd." },
{ "00016E", "Conklin Corporation" },
{ "00015B", "ITALTEL S.p.A/RF-UP-I" },
{ "000154", "G3M Corporation" },
{ "000150", "GILAT COMMUNICATIONS, LTD." },
{ "00012E", "PC Partner Ltd." },
{ "00013A", "SHELCAD COMMUNICATIONS, LTD." },
{ "000141", "CABLE PRINT" },
{ "000131", "Bosch Security Systems, Inc." },
{ "00013D", "RiscStation Ltd." },
{ "000149", "T.D.T. Transfer Data Test GmbH" },
{ "00D047", "XN TECHNOLOGIES" },
{ "00D018", "QWES. COM, INC." },
{ "00D048", "ECTON, INC." },
{ "00D028", "Harmonic, Inc" },
{ "00D02F", "VLSI TECHNOLOGY INC." },
{ "00D025", "XROSSTECH, INC." },
{ "00D085", "OTIS ELEVATOR COMPANY" },
{ "00D077", "LUCENT TECHNOLOGIES" },
{ "00D093", "TQ - COMPONENTS GMBH" },
{ "00D013", "PRIMEX AEROSPACE COMPANY" },
{ "00D056", "SOMAT CORPORATION" },
{ "00D017", "SYNTECH INFORMATION CO., LTD." },
{ "00D036", "TECHNOLOGY ATLANTA CORP." },
{ "00D0D6", "AETHRA TELECOMUNICAZIONI" },
{ "003078", "Cisco Systems, Inc" },
{ "003003", "Phasys Ltd." },
{ "0030D5", "DResearch GmbH" },
{ "0030CE", "Zaffire" },
{ "003095", "Procomp Informatics, Ltd." },
{ "003055", "Renesas Technology America, Inc." },
{ "0030B0", "Convergenet Technologies" },
{ "0030CC", "Tenor Networks, Inc." },
{ "003013", "NEC Corporation" },
{ "003061", "MobyTEL" },
{ "00D0AB", "DELTAKABEL TELECOM CV" },
{ "00D0A8", "NETWORK ENGINES, INC." },
{ "00D01C", "SBS TECHNOLOGIES," },
{ "00D0C0", "Cisco Systems, Inc" },
{ "00D051", "O2 MICRO, INC." },
{ "00D06D", "ACRISON, INC." },
{ "0050A1", "CARLO GAVAZZI, INC." },
{ "00D06C", "SHAREWAVE, INC." },
{ "00D03A", "ZONEWORX, INC." },
{ "0050C1", "GEMFLEX NETWORKS, LTD." },
{ "0050FB", "VSK ELECTRONICS" },
{ "005033", "MAYAN NETWORKS" },
{ "0030A0", "TYCO SUBMARINE SYSTEMS, LTD." },
{ "0030CB", "OMNI FLOW COMPUTERS, INC." },
{ "00306B", "CMOS SYSTEMS, INC." },
{ "003068", "CYBERNETICS TECH. CO., LTD." },
{ "0030E3", "SEDONA NETWORKS CORP." },
{ "00D007", "MIC ASSOCIATES, INC." },
{ "00D07F", "STRATEGY & TECHNOLOGY, LIMITED" },
{ "003085", "Cisco Systems, Inc" },
{ "003026", "HeiTel Digital Video GmbH" },
{ "0030A6", "VIANET TECHNOLOGIES, LTD." },
{ "003047", "NISSEI ELECTRIC CO., LTD." },
{ "00D0FC", "GRANITE MICROSYSTEMS" },
{ "00D042", "MAHLO GMBH & CO. UG" },
{ "00D046", "DOLBY LABORATORIES, INC." },
{ "00D0BA", "Cisco Systems, Inc" },
{ "00D0BC", "Cisco Systems, Inc" },
{ "00D0D8", "3Com Corporation" },
{ "00D06B", "SR TELECOM INC." },
{ "0030AA", "AXUS MICROSYSTEMS, INC." },
{ "003043", "IDREAM TECHNOLOGIES, PTE. LTD." },
{ "003010", "VISIONETICS INTERNATIONAL" },
{ "003096", "Cisco Systems, Inc" },
{ "003084", "ALLIED TELESYN INTERNAIONAL" },
{ "0030CF", "TWO TECHNOLOGIES, INC." },
{ "00D0E3", "ELE-CHEM ENGINEERING CO., LTD." },
{ "00D0ED", "XIOX" },
{ "00D0C2", "BALTHAZAR TECHNOLOGY AB" },
{ "00D0FB", "TEK MICROSYSTEMS, INCORPORATED" },
{ "00D082", "IOWAVE INC." },
{ "00D0AD", "TL INDUSTRIES" },
{ "00D0DB", "MCQUAY INTERNATIONAL" },
{ "00D06A", "LINKUP SYSTEMS CORPORATION" },
{ "00D065", "TOKO ELECTRIC" },
{ "00D08F", "ARDENT TECHNOLOGIES, INC." },
{ "00D0E7", "VCON TELECOMMUNICATION LTD." },
{ "00D087", "MICROFIRST INC." },
{ "00D008", "MACTELL CORPORATION" },
{ "003005", "Fujitsu Siemens Computers" },
{ "00304E", "BUSTEC PRODUCTION LTD." },
{ "0030E0", "OXFORD SEMICONDUCTOR LTD." },
{ "0030A1", "WEBGATE Inc." },
{ "00303D", "IVA CORPORATION" },
{ "0030C3", "FLUECKIGER ELEKTRONIK AG" },
{ "009047", "GIGA FAST E. LTD." },
{ "0090CB", "Wireless OnLine, Inc." },
{ "00903F", "AZTEC RADIOMEDIA" },
{ "001043", "A2 CORPORATION" },
{ "00108D", "Johnson Controls, Inc." },
{ "00108E", "HUGH SYMONS CONCEPT Technologies Ltd." },
{ "001052", "METTLER-TOLEDO (ALBSTADT) GMBH" },
{ "00100E", "MICRO LINEAR COPORATION" },
{ "0010D7", "ARGOSY RESEARCH INC." },
{ "001059", "DIABLO RESEARCH CO. LLC" },
{ "0010B6", "ENTRATA COMMUNICATIONS CORP." },
{ "001019", "SIRONA DENTAL SYSTEMS GmbH & Co. KG" },
{ "001013", "Kontron America, Inc." },
{ "0090A4", "ALTIGA NETWORKS" },
{ "00906C", "Sartorius Hamburg GmbH" },
{ "0090FC", "NETWORK COMPUTING DEVICES" },
{ "0090A3", "Corecess Inc." },
{ "009022", "IVEX" },
{ "0090A5", "SPECTRA LOGIC" },
{ "0090BA", "VALID NETWORKS, INC." },
{ "0090EE", "PERSONAL COMMUNICATIONS TECHNOLOGIES" },
{ "0090CD", "ENT-EMPRESA NACIONAL DE TELECOMMUNICACOES, S.A." },
{ "0090D0", "Thomson Telecom Belgium" },
{ "009075", "NEC DO BRASIL S.A." },
{ "00902E", "NAMCO LIMITED" },
{ "0090A0", "8X8 INC." },
{ "00907C", "DIGITALCAST, INC." },
{ "0090DF", "MITSUBISHI CHEMICAL AMERICA, INC." },
{ "009023", "ZILOG INC." },
{ "00908A", "BAYLY COMMUNICATIONS, INC." },
{ "009063", "COHERENT COMMUNICATIONS SYSTEMS CORPORATION" },
{ "009041", "APPLIED DIGITAL ACCESS" },
{ "0090D8", "WHITECROSS SYSTEMS" },
{ "009011", "WAVTrace, Inc." },
{ "009040", "Siemens Network Convergence LLC" },
{ "0090C7", "ICOM INC." },
{ "009035", "ALPHA TELECOM, INC." },
{ "009087", "ITIS" },
{ "00906E", "PRAXON, INC." },
{ "009039", "SHASTA NETWORKS" },
{ "00909A", "ONE WORLD SYSTEMS, INC." },
{ "009053", "DAEWOO ELECTRONICS CO., LTD." },
{ "00909E", "Critical IO, LLC" },
{ "0090C2", "JK microsystems, Inc." },
{ "009091", "DigitalScape, Inc." },
{ "0090ED", "CENTRAL SYSTEM RESEARCH CO., LTD." },
{ "00901B", "DIGITAL CONTROLS" },
{ "00905C", "EDMI" },
{ "0090D2", "ARTEL VIDEO SYSTEMS" },
{ "00508C", "RSI SYSTEMS" },
{ "00502D", "ACCEL, INC." },
{ "0050B8", "INOVA COMPUTERS GMBH & CO. KG" },
{ "00503A", "DATONG ELECTRONICS LTD." },
{ "00508E", "OPTIMATION, INC." },
{ "0050BB", "CMS TECHNOLOGIES" },
{ "005051", "IWATSU ELECTRIC CO., LTD." },
{ "0050BE", "FAST MULTIMEDIA AG" },
{ "0050AD", "CommUnique Wireless Corp." },
{ "005016", "SST/WOODHEAD INDUSTRIES" },
{ "005003", "Xrite Inc" },
{ "005023", "PG DESIGN ELECTRONICS, INC." },
{ "005039", "MARINER NETWORKS" },
{ "00505A", "NETWORK ALCHEMY, INC." },
{ "005071", "AIWA CO., LTD." },
{ "B01F81", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "58FCDB", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "7C70BC", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "2C265F", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "009071", "Applied Innovation Inc." },
{ "009031", "MYSTICOM, LTD." },
{ "00901F", "ADTEC PRODUCTIONS, INC." },
{ "009081", "ALOHA NETWORKS, INC." },
{ "0090B3", "AGRANAT SYSTEMS" },
{ "00500D", "SATORI ELECTORIC CO., LTD." },
{ "0050EC", "OLICOM A/S" },
{ "005083", "GILBARCO, INC." },
{ "0050CF", "VANLINK COMMUNICATION TECHNOLOGY RESEARCH INSTITUTE" },
{ "005008", "TIVA MICROCOMPUTER CORP. (TMC)" },
{ "005001", "YAMASHITA SYSTEMS CORP." },
{ "0050B5", "FICHET-BAUCHE" },
{ "0050B0", "TECHNOLOGY ATLANTA CORPORATION" },
{ "00504E", "SIERRA MONITOR CORP." },
{ "00504D", "Tokyo Electron Device Limited" },
{ "0050F7", "VENTURE MANUFACTURING (SINGAPORE) LTD." },
{ "005029", "1394 PRINTER WORKING GROUP" },
{ "00E08D", "PRESSURE SYSTEMS, INC." },
{ "00E040", "DeskStation Technology, Inc." },
{ "00E0D6", "COMPUTER & COMMUNICATION RESEARCH LAB." },
{ "00E07E", "WALT DISNEY IMAGINEERING" },
{ "00E094", "OSAI SRL" },
{ "00E032", "MISYS FINANCIAL SYSTEMS, LTD." },
{ "00E06B", "W&G SPECIAL PRODUCTS" },
{ "00E01C", "Cradlepoint, Inc" },
{ "00E076", "DEVELOPMENT CONCEPTS, INC." },
{ "00E0A7", "IPC INFORMATION SYSTEMS, INC." },
{ "00E0A4", "ESAOTE S.p.A." },
{ "00E080", "CONTROL RESOURCES CORPORATION" },
{ "00E0CC", "HERO SYSTEMS, LTD." },
{ "00E099", "SAMSON AG" },
{ "0010E9", "RAIDTEC LTD." },
{ "001003", "IMATRON, INC." },
{ "00105A", "3COM CORPORATION" },
{ "0010A9", "ADHOC TECHNOLOGIES" },
{ "000400", "LEXMARK INTERNATIONAL, INC." },
{ "00101A", "PictureTel Corp." },
{ "001097", "WinNet Metropolitan Communications Systems, Inc." },
{ "00106F", "TRENTON TECHNOLOGY INC." },
{ "0010C6", "Universal Global Scientific Industrial Co., Ltd." },
{ "0010DA", "Kollmorgen Corp" },
{ "0010DF", "RISE COMPUTER INC." },
{ "00109E", "AWARE, INC." },
{ "001072", "GVN TECHNOLOGIES, INC." },
{ "00E019", "ING. GIORDANO ELETTRONICA" },
{ "00E0D7", "SUNSHINE ELECTRONICS, INC." },
{ "00E0DA", "Alcatel North America ESD" },
{ "00E068", "MERRIMAC SYSTEMS INC." },
{ "00E01D", "WebTV NETWORKS, INC." },
{ "00E01F", "AVIDIA Systems, Inc." },
{ "00E056", "HOLONTECH CORPORATION" },
{ "00E0C9", "AutomatedLogic Corporation" },
{ "00E030", "MELITA INTERNATIONAL CORP." },
{ "00E0BA", "BERGHOF AUTOMATIONSTECHNIK GmbH" },
{ "00E0B2", "TELMAX COMMUNICATIONS CORP." },
{ "00E0EF", "DIONEX" },
{ "00E0BD", "INTERFACE SYSTEMS, INC." },
{ "00E071", "EPIS MICROCOMPUTER" },
{ "00E0A6", "TELOGY NETWORKS, INC." },
{ "00E026", "Redlake MASD LLC" },
{ "00E0B8", "GATEWAY 2000" },
{ "00E088", "LTX-Credence CORPORATION" },
{ "00E07C", "METTLER-TOLEDO, INC." },
{ "00E08C", "NEOPARADIGM LABS, INC." },
{ "00E061", "EdgePoint Networks, Inc." },
{ "00E06E", "FAR SYSTEMS S.p.A." },
{ "00E01B", "SPHERE COMMUNICATIONS, INC." },
{ "00E0AE", "XAQTI CORPORATION" },
{ "00E0C8", "VIRTUAL ACCESS, LTD." },
{ "00101D", "WINBOND ELECTRONICS CORP." },
{ "00105F", "ZODIAC DATA SYSTEMS" },
{ "0010CB", "FACIT K.K." },
{ "00108C", "FUJITSU TELECOMMUNICATIONS EUROPE, LTD." },
{ "001075", "Segate Technology LLC" },
{ "001058", "ArrowPoint Communications" },
{ "0010A8", "RELIANCE COMPUTER CORP." },
{ "0010AA", "MEDIA4, INC." },
{ "0010E8", "TELOCITY, INCORPORATED" },
{ "001010", "INITIO CORPORATION" },
{ "00E007", "Avaya ECS Ltd" },
{ "001022", "SatCom Media Corporation" },
{ "0010C7", "DATA TRANSMISSION NETWORK" },
{ "001098", "STARNET TECHNOLOGIES, INC." },
{ "001096", "TRACEWELL SYSTEMS, INC." },
{ "001082", "JNA TELECOMMUNICATIONS LIMITED" },
{ "001021", "ENCANTO NETWORKS, INC." },
{ "0010CE", "VOLAMP, LTD." },
{ "0010B2", "COACTIVE AESTHETICS" },
{ "00109A", "NETLINE" },
{ "0010EA", "ADEPT TECHNOLOGY" },
{ "0010BD", "THE TELECOMMUNICATION TECHNOLOGY COMMITTEE (TTC)" },
{ "0060D5", "MIYACHI TECHNOS CORP." },
{ "006099", "SBE, Inc." },
{ "0060FD", "NetICs, Inc." },
{ "0060B5", "KEBA GmbH" },
{ "006027", "Superior Modular Products" },
{ "0060C1", "WaveSpan Corporation" },
{ "006041", "Yokogawa Electric Corporation" },
{ "006005", "FEEDBACK DATA LTD." },
{ "00607B", "FORE SYSTEMS, INC." },
{ "00609C", "Perkin-Elmer Incorporated" },
{ "006007", "ACRES GAMING, INC." },
{ "006035", "DALLAS SEMICONDUCTOR, INC." },
{ "0060F1", "EXP COMPUTER, INC." },
{ "006040", "NETRO CORP." },
{ "006034", "ROBERT BOSCH GmbH" },
{ "0060BA", "SAHARA NETWORKS, INC." },
{ "006096", "T.S. MICROTECH INC." },
{ "00603A", "QUICK CONTROLS LTD." },
{ "0060AC", "RESILIENCE CORPORATION" },
{ "0060EB", "FOURTHTRACK SYSTEMS" },
{ "00606D", "DIGITAL EQUIPMENT CORP." },
{ "006014", "EDEC CO., LTD." },
{ "0060E1", "ORCKIT COMMUNICATIONS LTD." },
{ "006062", "TELESYNC, INC." },
{ "006038", "Nortel Networks" },
{ "006095", "ACCU-TIME SYSTEMS, INC." },
{ "00A016", "MICROPOLIS CORP." },
{ "00A01C", "NASCENT NETWORKS CORPORATION" },
{ "00A0FC", "IMAGE SCIENCES, INC." },
{ "00A0B7", "CORDANT, INC." },
{ "00A037", "Mindray DS USA, Inc." },
{ "00A04C", "INNOVATIVE SYSTEMS & TECHNOLOGIES, INC." },
{ "00A0E9", "ELECTRONIC RETAILING SYSTEMS INTERNATIONAL" },
{ "006078", "POWER MEASUREMENT LTD." },
{ "00600D", "Digital Logic GmbH" },
{ "00608A", "CITADEL COMPUTER" },
{ "00A05D", "CS COMPUTER SYSTEME GmbH" },
{ "00A0BD", "I-TECH CORP." },
{ "00A0B9", "EAGLE TECHNOLOGY, INC." },
{ "00A069", "Symmetricom, Inc." },
{ "00A07A", "ADVANCED PERIPHERALS TECHNOLOGIES, INC." },
{ "00A04E", "VOELKER TECHNOLOGIES, INC." },
{ "00A05A", "KOFAX IMAGE PRODUCTS" },
{ "00A093", "B/E AEROSPACE, Inc." },
{ "00A0BF", "WIRELESS DATA GROUP MOTOROLA" },
{ "00609F", "PHAST CORPORATION" },
{ "006067", "ACER NETXUS INC." },
{ "00600C", "Eurotech Inc." },
{ "006025", "ACTIVE IMAGING PLC" },
{ "006071", "MIDAS LAB, INC." },
{ "0060A7", "MICROSENS GmbH & CO. KG" },
{ "0060FC", "CONSERVATION THROUGH INNOVATION LTD." },
{ "0060D4", "ELDAT COMMUNICATION LTD." },
{ "006085", "Storage Concepts" },
{ "0060D3", "AT&T" },
{ "006018", "STELLAR ONE CORPORATION" },
{ "00602B", "PEAK AUDIO" },
{ "00606F", "CLARION CORPORATION OF AMERICA" },
{ "0060ED", "RICARDO TEST AUTOMATION LTD." },
{ "0060F6", "NEXTEST COMMUNICATIONS PRODUCTS, INC." },
{ "0060DD", "MYRICOM, INC." },
{ "006092", "MICRO/SYS, INC." },
{ "006080", "MICROTRONIX DATACOM LTD." },
{ "006068", "Dialogic Corporation" },
{ "0060DB", "NTP ELEKTRONIK A/S" },
{ "00A002", "LEEDS & NORTHRUP AUSTRALIA PTY LTD" },
{ "00A0E4", "OPTIQUEST" },
{ "00A01F", "TRICORD SYSTEMS, INC." },
{ "00A0C0", "DIGITAL LINK CORP." },
{ "00A043", "AMERICAN TECHNOLOGY LABS, INC." },
{ "00A047", "INTEGRATED FITNESS CORP." },
{ "00A00E", "VISUAL NETWORKS, INC." },
{ "00A07C", "TONYANG NYLON CO., LTD." },
{ "00A0EC", "TRANSMITTON LTD." },
{ "00A07E", "AVID TECHNOLOGY, INC." },
{ "00A035", "CYLINK CORPORATION" },
{ "00A028", "CONNER PERIPHERALS" },
{ "00A0C7", "TADIRAN TELECOMMUNICATIONS" },
{ "00E0BE", "GENROCO INTERNATIONAL, INC." },
{ "00E010", "HESS SB-AUTOMATENBAU GmbH" },
{ "00E0E9", "DATA LABS, INC." },
{ "00E0A0", "WILTRON CO." },
{ "00E024", "GADZOOX NETWORKS" },
{ "00E017", "EXXACT GmbH" },
{ "00603B", "AMTEC spa" },
{ "00E08B", "QLogic Corp." },
{ "0020E5", "APEX DATA, INC." },
{ "00207D", "ADVANCED COMPUTER APPLICATIONS" },
{ "0020D0", "VERSALYNX CORPORATION" },
{ "00206C", "EVERGREEN TECHNOLOGY CORP." },
{ "002012", "CAMTRONICS MEDICAL SYSTEMS" },
{ "00200B", "OCTAGON SYSTEMS CORP." },
{ "00209E", "BROWN'S OPERATING SYSTEM SERVICES, LTD." },
{ "0020D7", "JAPAN MINICOMPUTER SYSTEMS CO., Ltd." },
{ "0020FB", "OCTEL COMMUNICATIONS CORP." },
{ "0020B1", "COMTECH RESEARCH INC." },
{ "002033", "SYNAPSE TECHNOLOGIES, INC." },
{ "002099", "BON ELECTRIC CO., LTD." },
{ "0020AE", "ORNET DATA COMMUNICATION TECH." },
{ "0020EA", "EFFICIENT NETWORKS, INC." },
{ "0020FF", "SYMMETRICAL TECHNOLOGIES" },
{ "00208B", "LAPIS TECHNOLOGIES, INC." },
{ "002069", "ISDN SYSTEMS CORPORATION" },
{ "0020BA", "CENTER FOR HIGH PERFORMANCE" },
{ "002006", "GARRETT COMMUNICATIONS, INC." },
{ "00A0A2", "DIGICOM S.P.A." },
{ "00A09B", "QPSX COMMUNICATIONS, LTD." },
{ "00A054", "Private" },
{ "00A030", "CAPTOR NV/SA" },
{ "00A0B1", "FIRST VIRTUAL CORPORATION" },
{ "0020CB", "PRETEC ELECTRONICS CORP." },
{ "0020AB", "MICRO INDUSTRIES CORP." },
{ "00202D", "TAIYO CORPORATION" },
{ "00A088", "ESSENTIAL COMMUNICATIONS" },
{ "00A0FA", "Marconi Communication GmbH" },
{ "00A014", "CSIR" },
{ "00A045", "PHOENIX CONTACT GMBH & CO." },
{ "00A064", "KVB/ANALECT" },
{ "00A07F", "GSM-SYNTEL, LTD." },
{ "00A03E", "ATM FORUM" },
{ "00A050", "CYPRESS SEMICONDUCTOR" },
{ "00A098", "NetApp" },
{ "00A021", "General Dynamics" },
{ "00A0A8", "RENEX CORPORATION" },
{ "002049", "COMTRON, INC." },
{ "002050", "KOREA COMPUTER INC." },
{ "00203C", "EUROTIME AB" },
{ "002028", "WEST EGG SYSTEMS, INC." },
{ "002014", "GLOBAL VIEW CO., LTD." },
{ "002053", "HUNTSVILLE MICROSYSTEMS, INC." },
{ "002001", "DSP SOLUTIONS, INC." },
{ "00209C", "PRIMARY ACCESS CORP." },
{ "0020C5", "EAGLE TECHNOLOGY" },
{ "002009", "PACKARD BELL ELEC., INC." },
{ "002095", "RIVA ELECTRONICS" },
{ "00203F", "JUKI CORPORATION" },
{ "00C014", "TELEMATICS CALABASAS INT'L,INC" },
{ "00C045", "ISOLATION SYSTEMS, LTD." },
{ "00C000", "LANOPTICS, LTD." },
{ "00AA3C", "OLIVETTI TELECOM SPA (OLTECO)" },
{ "00C079", "FONSYS CO.,LTD." },
{ "002011", "CANOPUS CO., LTD." },
{ "00C00B", "NORCONTROL A.S." },
{ "00C0C0", "SHORE MICROSYSTEMS, INC." },
{ "00C00C", "RELIA TECHNOLGIES" },
{ "00A0E7", "CENTRAL DATA CORPORATION" },
{ "00A068", "BHP LIMITED" },
{ "00A0B3", "ZYKRONIX" },
{ "00A06E", "AUSTRON, INC." },
{ "00A0BB", "HILAN GMBH" },
{ "00A0C8", "ADTRAN INC." },
{ "00A017", "J B M CORPORATION" },
{ "0020D5", "VIPA GMBH" },
{ "002079", "MIKRON GMBH" },
{ "0020FA", "GDE SYSTEMS, INC." },
{ "002007", "SFA, INC." },
{ "002062", "SCORPION LOGIC, LTD." },
{ "00200A", "SOURCE-COMM CORP." },
{ "002000", "LEXMARK INTERNATIONAL, INC." },
{ "002003", "PIXEL POWER LTD." },
{ "0020B4", "TERMA ELEKTRONIK AS" },
{ "00205B", "Kentrox, LLC" },
{ "002030", "ANALOG & DIGITAL SYSTEMS" },
{ "0020A8", "SAST TECHNOLOGY CORP." },
{ "002066", "GENERAL MAGIC, INC." },
{ "002036", "BMC SOFTWARE" },
{ "0040BE", "BOEING DEFENSE & SPACE" },
{ "004036", "Zoom Telephonics, Inc" },
{ "004046", "UDC RESEARCH LIMITED" },
{ "00406A", "KENTEK INFORMATION SYSTEMS,INC" },
{ "0040F2", "JANICH & KLASS COMPUTERTECHNIK" },
{ "004082", "LABORATORY EQUIPMENT CORP." },
{ "004022", "KLEVER COMPUTERS, INC." },
{ "0040A2", "KINGSTAR TECHNOLOGY INC." },
{ "0040B4", "NEXTCOM K.K." },
{ "0040D4", "GAGE TALKER CORP." },
{ "004038", "TALENT ELECTRIC INCORPORATED" },
{ "004018", "ADOBE SYSTEMS, INC." },
{ "0040B0", "BYTEX CORPORATION, ENGINEERING" },
{ "004040", "RING ACCESS, INC." },
{ "0080D7", "Fantum Engineering" },
{ "0080D9", "EMK Elektronik GmbH & Co. KG" },
{ "00806A", "ERI (EMPAC RESEARCH INC.)" },
{ "00403B", "SYNERJET INTERNATIONAL CORP." },
{ "0040AB", "ROLAND DG CORPORATION" },
{ "0040D5", "Sartorius Mechatronics T&H GmbH " },
{ "004027", "SMC MASSACHUSETTS, INC." },
{ "00409C", "TRANSWARE" },
{ "00405C", "FUTURE SYSTEMS, INC." },
{ "00008C", "Alloy Computer Products (Australia) Pty Ltd" },
{ "004000", "PCI COMPONENTES DA AMZONIA LTD" },
{ "0040C5", "MICOM COMMUNICATIONS INC." },
{ "0040AA", "Metso Automation" },
{ "004023", "LOGIC CORPORATION" },
{ "0040A4", "ROSE ELECTRONICS" },
{ "004048", "SMD INFORMATICA S.A." },
{ "004025", "MOLECULAR DYNAMICS" },
{ "004010", "SONIC SYSTEMS, INC." },
{ "0040CA", "FIRST INTERNAT'L COMPUTER, INC" },
{ "004050", "IRONICS, INCORPORATED" },
{ "00402B", "TRIGEM COMPUTER, INC." },
{ "00C08C", "PERFORMANCE TECHNOLOGIES, INC." },
{ "00C02B", "GERLOFF GESELLSCHAFT FUR" },
{ "00C0A7", "SEEL LTD." },
{ "0040B3", "ParTech Inc." },
{ "00407D", "EXTENSION TECHNOLOGY CORP." },
{ "004079", "JUKO MANUFACTURE COMPANY, LTD." },
{ "0040D9", "AMERICAN MEGATRENDS INC." },
{ "004011", "ANDOVER CONTROLS CORPORATION" },
{ "0040C1", "BIZERBA-WERKE WILHEIM KRAUT" },
{ "00C06B", "OSI PLUS CORPORATION" },
{ "00C06A", "ZAHNER-ELEKTRIK GMBH & CO. KG" },
{ "00C097", "ARCHIPEL SA" },
{ "00C072", "KNX LTD." },
{ "00C0EC", "DAUPHIN TECHNOLOGY" },
{ "00C066", "DOCUPOINT, INC." },
{ "00C028", "JASCO CORPORATION" },
{ "00C0DC", "EOS TECHNOLOGIES, INC." },
{ "00C02D", "FUJI PHOTO FILM CO., LTD." },
{ "00C0BD", "INEX TECHNOLOGIES, INC." },
{ "00C054", "NETWORK PERIPHERALS, LTD." },
{ "00C0D5", "Werbeagentur Jürgen Siebert" },
{ "00C044", "EMCOM CORPORATION" },
{ "00C050", "TOYO DENKI SEIZO K.K." },
{ "00408A", "TPS TELEPROCESSING SYS. GMBH" },
{ "0040FD", "LXE" },
{ "00403D", "Teradata Corporation" },
{ "0040E0", "ATOMWIDE LTD." },
{ "00408C", "AXIS COMMUNICATIONS AB" },
{ "004068", "EXTENDED SYSTEMS" },
{ "0040BA", "ALLIANT COMPUTER SYSTEMS CORP." },
{ "004069", "LEMCOM SYSTEMS, INC." },
{ "0040F8", "SYSTEMHAUS DISCOM" },
{ "004077", "MAXTON TECHNOLOGY CORPORATION" },
{ "0040E7", "ARNOS INSTRUMENTS & COMPUTER" },
{ "0040AC", "SUPER WORKSTATION, INC." },
{ "00C0AC", "GAMBIT COMPUTER COMMUNICATIONS" },
{ "00C02C", "CENTRUM COMMUNICATIONS, INC." },
{ "00C0ED", "US ARMY ELECTRONIC" },
{ "00C0F0", "KINGSTON TECHNOLOGY CORP." },
{ "00C0D1", "COMTREE TECHNOLOGY CORPORATION" },
{ "00C0D2", "SYNTELLECT, INC." },
{ "00C0FB", "ADVANCED TECHNOLOGY LABS" },
{ "00C092", "MENNEN MEDICAL INC." },
{ "00C06C", "SVEC COMPUTER CORP." },
{ "00C02E", "NETWIZ" },
{ "00C05B", "NETWORKS NORTHWEST, INC." },
{ "00C0BF", "TECHNOLOGY CONCEPTS, LTD." },
{ "00C0C9", "ELSAG BAILEY PROCESS" },
{ "00809D", "Commscraft Ltd." },
{ "008017", "PFU LIMITED" },
{ "0080F8", "MIZAR, INC." },
{ "008024", "KALPANA, INC." },
{ "008074", "FISHER CONTROLS" },
{ "008021", "Alcatel Canada Inc." },
{ "000055", "COMMISSARIAT A L`ENERGIE ATOM." },
{ "000086", "MEGAHERTZ CORPORATION" },
{ "000092", "COGENT DATA TECHNOLOGIES" },
{ "008068", "YAMATECH SCIENTIFIC LTD." },
{ "0080F2", "RAYCOM SYSTEMS INC" },
{ "0080EA", "ADVA Optical Networking Ltd." },
{ "008025", "STOLLMANN GMBH" },
{ "000067", "SOFT * RITE, INC." },
{ "0000E8", "ACCTON TECHNOLOGY CORP." },
{ "0000B2", "TELEVIDEO SYSTEMS, INC." },
{ "0000EE", "NETWORK DESIGNERS, LTD." },
{ "000089", "CAYMAN SYSTEMS INC." },
{ "0000F0", "SAMSUNG ELECTRONICS CO., LTD." },
{ "000021", "SUREMAN COMP. & COMMUN. CORP." },
{ "0000CF", "HAYES MICROCOMPUTER PRODUCTS" },
{ "0000A4", "ACORN COMPUTERS LIMITED" },
{ "000018", "WEBSTER COMPUTER CORPORATION" },
{ "008033", "EMS Aviation, Inc." },
{ "008052", "TECHNICALLY ELITE CONCEPTS" },
{ "00804F", "DAIKIN INDUSTRIES, LTD." },
{ "00806D", "CENTURY SYSTEMS CORP." },
{ "00802D", "XYLOGICS INC" },
{ "008048", "COMPEX INCORPORATED" },
{ "008085", "H-THREE SYSTEMS CORPORATION" },
{ "008014", "ESPRIT SYSTEMS" },
{ "0080B4", "SOPHIA SYSTEMS" },
{ "00807F", "DY-4 INCORPORATED" },
{ "0000E4", "IN2 GROUPE INTERTECHNIQUE" },
{ "000079", "NETWORTH INCORPORATED" },
{ "000075", "Nortel Networks" },
{ "004009", "TACHIBANA TECTRON CO., LTD." },
{ "00409E", "CONCURRENT TECHNOLOGIES  LTD." },
{ "008092", "Silex Technology, Inc." },
{ "008011", "DIGITAL SYSTEMS INT'L. INC." },
{ "008044", "SYSTECH COMPUTER CORP." },
{ "00808A", "SUMMIT MICROSYSTEMS CORP." },
{ "0080E3", "CORAL NETWORK CORPORATION" },
{ "008072", "MICROPLEX SYSTEMS LTD." },
{ "008054", "FRONTIER TECHNOLOGIES CORP." },
{ "0080AE", "HUGHES NETWORK SYSTEMS" },
{ "0080AF", "ALLUMER CO., LTD." },
{ "0080EC", "SUPERCOMPUTING SOLUTIONS, INC." },
{ "0080A4", "LIBERTY ELECTRONICS" },
{ "008073", "DWB ASSOCIATES" },
{ "00802B", "INTEGRATED MARKETING CO" },
{ "0080BE", "ARIES RESEARCH" },
{ "008027", "ADAPTIVE SYSTEMS, INC." },
{ "0080E2", "T.D.I. CO., LTD." },
{ "0040EE", "OPTIMEM" },
{ "00405E", "NORTH HILLS ISRAEL" },
{ "004072", "Applied Innovation Inc." },
{ "004031", "KOKUSAI ELECTRIC CO., LTD" },
{ "00400C", "GENERAL MICRO SYSTEMS, INC." },
{ "0040E6", "C.A.E.N." },
{ "0040FC", "IBR COMPUTER TECHNIK GMBH" },
{ "004001", "Zero One Technology Co. Ltd." },
{ "004002", "PERLE SYSTEMS LIMITED" },
{ "0080DB", "GRAPHON CORPORATION" },
{ "0080B1", "SOFTCOM A/S" },
{ "0080D8", "NETWORK PERIPHERALS INC." },
{ "0080AB", "DUKANE NETWORK INTEGRATION" },
{ "00809B", "JUSTSYSTEM CORPORATION" },
{ "008089", "TECNETICS (PTY) LTD." },
{ "000039", "TOSHIBA CORPORATION" },
{ "0000CB", "COMPU-SHACK ELECTRONIC GMBH" },
{ "0000D1", "ADAPTEC INCORPORATED" },
{ "0000B6", "MICRO-MATIC RESEARCH" },
{ "000066", "TALARIS SYSTEMS, INC." },
{ "000014", "NETRONIX" },
{ "000072", "MINIWARE TECHNOLOGY" },
{ "0000AB", "LOGIC MODELING CORPORATION" },
{ "000029", "IMC NETWORKS CORP." },
{ "0080CD", "MICRONICS COMPUTER, INC." },
{ "008083", "AMDAHL" },
{ "008003", "HYTEC ELECTRONICS LTD." },
{ "00801B", "KODIAK TECHNOLOGY" },
{ "0080CC", "MICROWAVE BYPASS SYSTEMS" },
{ "080079", "THE DROID WORKS" },
{ "080077", "TSL COMMUNICATIONS LTD." },
{ "080071", "MATRA (DSIE)" },
{ "08006A", "ATT BELL LABORATORIES" },
{ "08005F", "SABER TECHNOLOGY CORP." },
{ "08005C", "FOUR PHASE SYSTEMS" },
{ "08005B", "VTA TECHNOLOGIES INC." },
{ "080058", "SYSTEMS CONCEPTS" },
{ "080050", "DAISY SYSTEMS CORP." },
{ "080052", "INSYSTEC" },
{ "080047", "SEQUENT COMPUTER SYSTEMS INC." },
{ "080045", "CONCURRENT COMPUTER CORP." },
{ "080044", "DAVID SYSTEMS INC." },
{ "080041", "RACAL-MILGO INFORMATION SYS.." },
{ "080038", "BULL S.A.S." },
{ "08003C", "SCHLUMBERGER WELL SERVICES" },
{ "080034", "FILENET CORPORATION" },
{ "08002C", "BRITTON LEE INC." },
{ "0000B9", "MCDONNELL DOUGLAS COMPUTER SYS" },
{ "00002D", "CHROMATICS INC" },
{ "00004A", "ADC CODENOLL TECHNOLOGY CORP." },
{ "0000C0", "WESTERN DIGITAL CORPORATION" },
{ "000040", "APPLICON, INC." },
{ "00005D", "CS TELECOM" },
{ "08008E", "Tandem Computers" },
{ "080086", "KONICA MINOLTA HOLDINGS, INC." },
{ "080083", "Seiko Instruments Inc." },
{ "080080", "AES DATA INC." },
{ "080030", "ROYAL MELBOURNE INST OF TECH" },
{ "080064", "Sitasys AG" },
{ "00DD09", "UNGERMANN-BASS INC." },
{ "08008A", "PerfTech, Inc." },
{ "00DD04", "UNGERMANN-BASS INC." },
{ "080066", "AGFA CORPORATION" },
{ "08001A", "TIARA/ 10NET" },
{ "080090", "SONOMA SYSTEMS" },
{ "08000B", "UNISYS CORPORATION" },
{ "080017", "NATIONAL SEMICONDUCTOR" },
{ "00005E", "ICANN, IANA Department" },
{ "0000AF", "Canberra Industries, Inc." },
{ "0000EC", "MICROPROCESS" },
{ "00009E", "MARLI S.A." },
{ "000042", "METIER MANAGEMENT SYSTEMS LTD." },
{ "00008D", "Cryptek Inc." },
{ "000065", "Network General Corporation" },
{ "00004D", "DCI CORPORATION" },
{ "080024", "10NET COMMUNICATIONS/DCA" },
{ "08001E", "APOLLO COMPUTER INC." },
{ "08001B", "EMC Corporation" },
{ "00DD0D", "UNGERMANN-BASS INC." },
{ "AA0002", "DIGITAL EQUIPMENT CORPORATION" },
{ "080005", "SYMBOLICS INC." },
{ "000000", "XEROX CORPORATION" },
{ "0040D6", "LOCAMATION B.V." },
{ "800010", "ATT BELL LABORATORIES" },
{ "AA0003", "DIGITAL EQUIPMENT CORPORATION" },
{ "080008", "BOLT BERANEK AND NEWMAN INC." },
{ "08000E", "NCR CORPORATION" },
{ "00006F", "Madge Ltd." },
{ "00005A", "SysKonnect GmbH" },
{ "000023", "ABB INDUSTRIAL SYSTEMS AB" },
{ "000045", "FORD AEROSPACE & COMM. CORP." },
{ "0000BC", "Rockwell Automation" },
{ "0000C3", "HARRIS CORP COMPUTER SYS DIV" },
{ "000004", "XEROX CORPORATION" },
{ "000009", "XEROX CORPORATION" },
{ "00003D", "UNISYS" },
{ "F82C18", "2Wire Inc" },
{ "00173F", "Belkin International Inc." },
{ "388602", "Flexoptix GmbH" },
{ "F4EB38", "Sagemcom Broadband SAS" },
{ "001E74", "Sagemcom Broadband SAS" },
{ "00604C", "Sagemcom Broadband SAS" },
{ "002691", "Sagemcom Broadband SAS" },
{ "C0D044", "Sagemcom Broadband SAS" },
{ "6C2E85", "Sagemcom Broadband SAS" },
{ "CC33BB", "Sagemcom Broadband SAS" },
{ "681590", "Sagemcom Broadband SAS" },
{ "5464D9", "Sagemcom Broadband SAS" },
{ "00023F", "COMPAL ELECTRONICS, INC." },
{ "0080C2", "IEEE 802.1" },
{ "C46699", "vivo Mobile Communication Co., Ltd." },
{ "F80278", "IEEE Registration Authority" },
{ "D02212", "IEEE Registration Authority" },
{ "002067", "Private" },
{ "74E14A", "IEEE Registration Authority" },
{ "383BC8", "2Wire Inc" },
{ "DC7FA4", "2Wire Inc" },
{ "1100AA", "Private" },
{ "001288", "2Wire Inc" },
{ "001EC7", "2Wire Inc" },
{ "28162E", "2Wire Inc" },
{ "3CEA4F", "2Wire Inc" },
{ "848F69", "Dell Inc." },
{ "90B11C", "Dell Inc." },
{ "F8CAB8", "Dell Inc." },
{ "24B6FD", "Dell Inc." },
{ "000D56", "Dell Inc." },
{ "00123F", "Dell Inc." },
{ "001372", "Dell Inc." },
{ "74867A", "Dell Inc." },
{ "3417EB", "Dell Inc." },
{ "EC8892", "Motorola Mobility LLC, a Lenovo Company" },
{ "B07994", "Motorola Mobility LLC, a Lenovo Company" },
{ "141AA3", "Motorola Mobility LLC, a Lenovo Company" },
{ "CCC3EA", "Motorola Mobility LLC, a Lenovo Company" },
{ "34BB26", "Motorola Mobility LLC, a Lenovo Company" },
{ "40786A", "Motorola Mobility LLC, a Lenovo Company" },
{ "0019B9", "Dell Inc." },
{ "002219", "Dell Inc." },
{ "00B0D0", "Dell Inc." },
{ "5C260A", "Dell Inc." },
{ "B083FE", "Dell Inc." },
{ "141877", "Dell Inc." },
{ "0024E8", "Dell Inc." },
{ "A48E0A", "DeLaval International AB" },
{ "00215C", "Intel Corporate" },
{ "002315", "Intel Corporate" },
{ "001500", "Intel Corporate" },
{ "104A7D", "Intel Corporate" },
{ "A4C494", "Intel Corporate" },
{ "902E1C", "Intel Corporate" },
{ "3CFDFE", "Intel Corporate" },
{ "B8BF83", "Intel Corporate" },
{ "001DE1", "Intel Corporate" },
{ "0022FB", "Intel Corporate" },
{ "081196", "Intel Corporate" },
{ "6036DD", "Intel Corporate" },
{ "A0369F", "Intel Corporate" },
{ "502DA2", "Intel Corporate" },
{ "4C79BA", "Intel Corporate" },
{ "4CEB42", "Intel Corporate" },
{ "606720", "Intel Corporate" },
{ "84A6C8", "Intel Corporate" },
{ "5891CF", "Intel Corporate" },
{ "88532E", "Intel Corporate" },
{ "0024D7", "Intel Corporate" },
{ "C40938", "FUJIAN STAR-NET COMMUNICATION CO.,LTD" },
{ "00AA02", "Intel Corporation" },
{ "5CD2E4", "Intel Corporate" },
{ "04BD88", "Aruba Networks" },
{ "000B86", "Aruba Networks" },
{ "8896F2", "Valeo Schalter und Sensoren GmbH" },
{ "80A589", "AzureWave Technology Inc." },
{ "0CCC26", "Airenetworks" },
{ "4CB0E8", "Beijing RongZhi xinghua technology co., LTD" },
{ "4C14A3", "TCL Technoly Electronics (Huizhou) Co., Ltd." },
{ "F48E38", "Dell Inc." },
{ "74DAEA", "Texas Instruments" },
{ "D887D5", "Leadcore Technology CO.,LTD" },
{ "00DA55", "Cisco Systems, Inc" },
{ "80D21D", "AzureWave Technology Inc." },
{ "705A0F", "Hewlett Packard" },
{ "586356", "FN-LINK TECHNOLOGY LIMITED" },
{ "B046FC", "MitraStar Technology Corp." },
{ "08A95A", "AzureWave Technology Inc." },
{ "6CADF8", "AzureWave Technology Inc." },
{ "54271E", "AzureWave Technology Inc." },
{ "008C54", "ADB Broadband Italia" },
{ "F0842F", "ADB Broadband Italia" },
{ "8CB864", "AcSiP Technology Corp." },
{ "0020E0", "Actiontec Electronics, Inc" },
{ "0004E3", "Accton Technology Corp" },
{ "409558", "Aisino Corporation" },
{ "00D0C9", "ADVANTECH CO., LTD." },
{ "002553", "ADB Broadband Italia" },
{ "00238E", "ADB Broadband Italia" },
{ "001CA2", "ADB Broadband Italia" },
{ "0017C2", "ADB Broadband Italia" },
{ "D0D412", "ADB Broadband Italia" },
{ "000FA3", "Alpha Networks Inc." },
{ "001D6A", "Alpha Networks Inc." },
{ "0000F4", "Allied Telesis, Inc." },
{ "10AE60", "Private" },
{ "F04F7C", "Private" },
{ "70F1A1", "Liteon Technology Corporation" },
{ "6CFAA7", "AMPAK Technology, Inc." },
{ "0024EF", "Sony Mobile Communications AB" },
{ "6C0E0D", "Sony Mobile Communications AB" },
{ "B4527D", "Sony Mobile Communications AB" },
{ "E063E5", "Sony Mobile Communications AB" },
{ "000E07", "Sony Mobile Communications AB" },
{ "001A75", "Sony Mobile Communications AB" },
{ "0016B8", "Sony Mobile Communications AB" },
{ "001D28", "Sony Mobile Communications AB" },
{ "001FE4", "Sony Mobile Communications AB" },
{ "002298", "Sony Mobile Communications AB" },
{ "0019A6", "ARRIS Group, Inc." },
{ "001700", "ARRIS Group, Inc." },
{ "0015A8", "ARRIS Group, Inc." },
{ "000E5C", "ARRIS Group, Inc." },
{ "000CE5", "ARRIS Group, Inc." },
{ "0004BD", "ARRIS Group, Inc." },
{ "00E06F", "ARRIS Group, Inc." },
{ "386BBB", "ARRIS Group, Inc." },
{ "0015CF", "ARRIS Group, Inc." },
{ "0014E8", "ARRIS Group, Inc." },
{ "24FD52", "Liteon Technology Corporation" },
{ "2016D8", "Liteon Technology Corporation" },
{ "9CB70D", "Liteon Technology Corporation" },
{ "1C659D", "Liteon Technology Corporation" },
{ "F80BBE", "ARRIS Group, Inc." },
{ "DC4517", "ARRIS Group, Inc." },
{ "74F612", "ARRIS Group, Inc." },
{ "74E7C6", "ARRIS Group, Inc." },
{ "B81619", "ARRIS Group, Inc." },
{ "B077AC", "ARRIS Group, Inc." },
{ "145BD1", "ARRIS Group, Inc." },
{ "6CC1D2", "ARRIS Group, Inc." },
{ "0025F2", "ARRIS Group, Inc." },
{ "002374", "ARRIS Group, Inc." },
{ "002641", "ARRIS Group, Inc." },
{ "0026BA", "ARRIS Group, Inc." },
{ "002180", "ARRIS Group, Inc." },
{ "0019C0", "ARRIS Group, Inc." },
{ "001B9E", "ASKEY COMPUTER CORP" },
{ "E0CA94", "ASKEY COMPUTER CORP" },
{ "C0D962", "ASKEY COMPUTER CORP" },
{ "00150C", "AVM GmbH" },
{ "744401", "NETGEAR" },
{ "E091F5", "NETGEAR" },
{ "001B2F", "NETGEAR" },
{ "00223F", "NETGEAR" },
{ "E0469A", "NETGEAR" },
{ "F40B93", "BlackBerry RTS" },
{ "68ED43", "BlackBerry RTS" },
{ "34BB1F", "BlackBerry RTS" },
{ "489D24", "BlackBerry RTS" },
{ "000F86", "BlackBerry RTS" },
{ "001333", "BaudTec Corporation" },
{ "507E5D", "Arcadyan Technology Corporation" },
{ "849CA6", "Arcadyan Technology Corporation" },
{ "1CC63C", "Arcadyan Technology Corporation" },
{ "C02506", "AVM GmbH" },
{ "0896D7", "AVM GmbH" },
{ "008EF2", "NETGEAR" },
{ "4494FC", "NETGEAR" },
{ "20E52A", "NETGEAR" },
{ "9CD36D", "NETGEAR" },
{ "C40415", "NETGEAR" },
{ "08BD43", "NETGEAR" },
{ "4C09D4", "Arcadyan Technology Corporation" },
{ "DC446D", "Allwinner Technology Co., Ltd" },
{ "BC620E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "78F557", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E02861", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C4473F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "000AF7", "Broadcom" },
{ "000DB6", "Broadcom" },
{ "18C086", "Broadcom" },
{ "80ACAC", "Juniper Networks" },
{ "003146", "Juniper Networks" },
{ "000585", "Juniper Networks" },
{ "F01C2D", "Juniper Networks" },
{ "5C4527", "Juniper Networks" },
{ "44F477", "Juniper Networks" },
{ "CCE17F", "Juniper Networks" },
{ "3C6104", "Juniper Networks" },
{ "C03E0F", "BSkyB Ltd" },
{ "54E032", "Juniper Networks" },
{ "78FE3D", "Juniper Networks" },
{ "F8C001", "Juniper Networks" },
{ "50C58D", "Juniper Networks" },
{ "0024DC", "Juniper Networks" },
{ "001F12", "Juniper Networks" },
{ "0019E2", "Juniper Networks" },
{ "0020D4", "Cabletron Systems, Inc." },
{ "00001D", "Cabletron Systems, Inc." },
{ "0060BB", "Cabletron Systems, Inc." },
{ "D0542D", "Cambridge Industries(Group) Co.,Ltd." },
{ "001FC7", "Casio Hitachi Mobile Communications Co., Ltd." },
{ "ACEE9E", "Samsung Electronics Co.,Ltd" },
{ "C08997", "Samsung Electronics Co.,Ltd" },
{ "2827BF", "Samsung Electronics Co.,Ltd" },
{ "F05B7B", "Samsung Electronics Co.,Ltd" },
{ "7CF90E", "Samsung Electronics Co.,Ltd" },
{ "AC5A14", "Samsung Electronics Co.,Ltd" },
{ "B0C559", "Samsung Electronics Co.,Ltd" },
{ "BCD11F", "Samsung Electronics Co.,Ltd" },
{ "A0B4A5", "Samsung Electronics Co.,Ltd" },
{ "80656D", "Samsung Electronics Co.,Ltd" },
{ "48137E", "Samsung Electronics Co.,Ltd" },
{ "E83A12", "Samsung Electronics Co.,Ltd" },
{ "9C0298", "Samsung Electronics Co.,Ltd" },
{ "6C8336", "Samsung Electronics Co.,Ltd" },
{ "B8C68E", "Samsung Electronics Co.,Ltd" },
{ "74458A", "Samsung Electronics Co.,Ltd" },
{ "A49A58", "Samsung Electronics Co.,Ltd" },
{ "B4EF39", "Samsung Electronics Co.,Ltd" },
{ "14A364", "Samsung Electronics Co.,Ltd" },
{ "3CA10D", "Samsung Electronics Co.,Ltd" },
{ "206E9C", "Samsung Electronics Co.,Ltd" },
{ "183F47", "Samsung Electronics Co.,Ltd" },
{ "0C715D", "Samsung Electronics Co.,Ltd" },
{ "0C1420", "Samsung Electronics Co.,Ltd" },
{ "A80600", "Samsung Electronics Co.,Ltd" },
{ "6CF373", "Samsung Electronics Co.,Ltd" },
{ "90F1AA", "Samsung Electronics Co.,Ltd" },
{ "C4576E", "Samsung Electronics Co.,Ltd" },
{ "78BDBC", "Samsung Electronics Co.,Ltd" },
{ "3872C0", "Comtrend Corporation" },
{ "F4068D", "devolo AG" },
{ "000BCA", "DATAVAN TC" },
{ "00507F", "DrayTek Corp." },
{ "3C8970", "Neosfar" },
{ "C43655", "Shenzhen Fenglian Technology Co., Ltd." },
{ "78CA83", "IEEE Registration Authority" },
{ "78CB68", "DAEHAP HYPER-TECH" },
{ "001A7F", "GCI Science & Technology Co.,LTD" },
{ "00054F", "Private" },
{ "D04D2C", "Roku, Inc." },
{ "E00C7F", "Nintendo Co., Ltd." },
{ "58BDA3", "Nintendo Co., Ltd." },
{ "0025A0", "Nintendo Co., Ltd." },
{ "002659", "Nintendo Co., Ltd." },
{ "8C56C5", "Nintendo Co., Ltd." },
{ "CC9E00", "Nintendo Co., Ltd." },
{ "001656", "Nintendo Co., Ltd." },
{ "00191D", "Nintendo Co., Ltd." },
{ "0019FD", "Nintendo Co., Ltd." },
{ "001EA9", "Nintendo Co., Ltd." },
{ "A84481", "Nokia Corporation" },
{ "8844F6", "Nokia Corporation" },
{ "A87B39", "Nokia Corporation" },
{ "14C126", "Nokia Corporation" },
{ "4C2578", "Nokia Corporation" },
{ "001262", "Nokia Danmark A/S" },
{ "00174B", "Nokia Danmark A/S" },
{ "002547", "Nokia Danmark A/S" },
{ "001D3B", "Nokia Danmark A/S" },
{ "0014A7", "Nokia Danmark A/S" },
{ "001EA4", "Nokia Danmark A/S" },
{ "001CD6", "Nokia Danmark A/S" },
{ "001DE9", "Nokia Danmark A/S" },
{ "D099D5", "Alcatel-Lucent" },
{ "DC0077", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "0060DC", "NEC Magnus Communications,Ltd." },
{ "9CAED3", "Seiko Epson Corporation" },
{ "F45C89", "Apple, Inc." },
{ "A41588", "ARRIS Group, Inc." },
{ "8C3C4A", "NAKAYO TELECOMMUNICATIONS,INC" },
{ "0021FD", "LACROIX TRAFFIC S.A.U" },
{ "4CB44A", "NANOWAVE Technologies Inc." },
{ "78C3E9", "Samsung Electronics Co.,Ltd" },
{ "9C5C8E", "ASUSTek COMPUTER INC." },
{ "102AB3", "Xiaomi Communications Co Ltd" },
{ "70884D", "JAPAN RADIO CO., LTD." },
{ "4C55CC", "Zentri Pty Ltd" },
{ "BCEC5D", "Apple, Inc." },
{ "DC415F", "Apple, Inc." },
{ "30636B", "Apple, Inc." },
{ "280DFC", "Sony Computer Entertainment Inc." },
{ "84683E", "Intel Corporate" },
{ "C88722", "Lumenpulse" },
{ "FC1A11", "vivo Mobile Communication Co., Ltd." },
{ "30A9DE", "LG Innotek" },
{ "702526", "Alcatel-Lucent" },
{ "903AA0", "Alcatel-Lucent" },
{ "E0CDFD", "Beijing E3Control Technology Co, LTD" },
{ "BC52B4", "Alcatel-Lucent" },
{ "08BE77", "Green Electronics" },
{ "208B37", "Skyworth Digital Technology(Shenzhen) Co.,Ltd" },
{ "280C28", "Unigen DataStorage Corporation" },
{ "980CA5", "Motorola (Wuhan) Mobility Technologies Communication Co., Ltd." },
{ "1CC035", "PLANEX COMMUNICATIONS INC." },
{ "34543C", "TAKAOKA TOKO CO.,LTD." },
{ "D49524", "Clover Network, Inc." },
{ "0034DA", "LG Electronics (Mobile Communications)" },
{ "9046A2", "Tedipay UK Ltd" },
{ "6479A7", "Phison Electronics Corp.   " },
{ "0019C5", "Sony Computer Entertainment Inc." },
{ "0015C1", "Sony Computer Entertainment Inc." },
{ "C83870", "Samsung Electronics Co.,Ltd" },
{ "288335", "Samsung Electronics Co.,Ltd" },
{ "44783E", "Samsung Electronics Co.,Ltd" },
{ "202D07", "Samsung Electronics Co.,Ltd" },
{ "FC2FAA", "Alcatel-Lucent" },
{ "D4612E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "1C6758", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0452C7", "Bose Corporation" },
{ "E85659", "Advanced-Connectek Inc." },
{ "34E70B", "Beijing HAN Networks Co., Ltd" },
{ "8801F2", "Vitec System Engineering Inc." },
{ "FC084A", "FUJITSU LIMITED" },
{ "847BEB", "Dell Inc." },
{ "F8C96C", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "34BF90", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "D467E7", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "04C1B9", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "689361", "Integrated Device Technology (Malaysia) Sdn. Bhd." },
{ "D4AD2D", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "48555F", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "04A316", "Texas Instruments" },
{ "98072D", "Texas Instruments" },
{ "A082AC", "Linear DMS Solutions Sdn. Bhd." },
{ "705A9E", "Technicolor CH USA Inc." },
{ "002697", "Alpha  Technologies Inc." },
{ "4CB8B5", "Shenzhen YOUHUA Technology Co., Ltd" },
{ "1CABC0", "Hitron Technologies. Inc" },
{ "84E323", "Green Wave Telecommunication SDN BHD" },
{ "7071BC", "PEGATRON CORPORATION" },
{ "44650D", "Amazon Technologies Inc." },
{ "E06995", "PEGATRON CORPORATION" },
{ "D897BA", "PEGATRON CORPORATION" },
{ "54D9E4", "BRILLIANTTS CO., LTD" },
{ "E4F3F5", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "00185C", "EDSLAB Technologies" },
{ "000E2E", "Edimax Technology Co. Ltd." },
{ "00020E", "ECI Telecom Ltd." },
{ "0000C9", "Emulex Corporation" },
{ "00115B", "Elitegroup Computer Systems Co.,Ltd." },
{ "000795", "Elitegroup Computer Systems Co.,Ltd." },
{ "B8AEED", "Elitegroup Computer Systems Co.,Ltd." },
{ "C03FD5", "Elitegroup Computer Systems Co.,Ltd." },
{ "7427EA", "Elitegroup Computer Systems Co.,Ltd." },
{ "00089F", "EFM Networks" },
{ "042AE2", "Cisco Systems, Inc" },
{ "001A45", "GN Netcom A/S" },
{ "00168F", "GN Netcom A/S" },
{ "00104F", "Oracle Corporation " },
{ "000782", "Oracle Corporation " },
{ "083FBC", "zte corporation" },
{ "903809", "Ericsson AB" },
{ "1C1B0D", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "2C3996", "Sagemcom Broadband SAS" },
{ "0054BD", "Swelaser AB" },
{ "0057D2", "Cisco Systems, Inc" },
{ "3C6716", "Lily Robotics" },
{ "806AB0", "Shenzhen TINNO Mobile Technology Corp." },
{ "A0F895", "Shenzhen TINNO Mobile Technology Corp." },
{ "0078CD", "Ignition Design Labs" },
{ "40D855", "IEEE Registration Authority" },
{ "70B3D5", "IEEE Registration Authority" },
{ "28ED6A", "Apple, Inc." },
{ "34AB37", "Apple, Inc." },
{ "60A37D", "Apple, Inc." },
{ "0056CD", "Apple, Inc." },
{ "7081EB", "Apple, Inc." },
{ "086698", "Apple, Inc." },
{ "002926", "Applied Optoelectronics, Inc Taiwan Branch" },
{ "44C15C", "Texas Instruments" },
{ "1CE2CC", "Texas Instruments" },
{ "985945", "Texas Instruments" },
{ "1CBA8C", "Texas Instruments" },
{ "BC6A29", "Texas Instruments" },
{ "2CFD37", "Blue Calypso, Inc." },
{ "0C6127", "Actiontec Electronics, Inc" },
{ "001B11", "D-Link Corporation" },
{ "001E58", "D-Link Corporation" },
{ "002191", "D-Link Corporation" },
{ "0022B0", "D-Link Corporation" },
{ "F07D68", "D-Link Corporation" },
{ "78542E", "D-Link International" },
{ "3CDD89", "SOMO HOLDINGS & TECH. CO.,LTD." },
{ "2C56DC", "ASUSTek COMPUTER INC." },
{ "001830", "Texas Instruments" },
{ "C0E422", "Texas Instruments" },
{ "04E451", "Texas Instruments" },
{ "D00790", "Texas Instruments" },
{ "0017E7", "Texas Instruments" },
{ "0017E9", "Texas Instruments" },
{ "001E4C", "Hon Hai Precision Ind. Co.,Ltd." },
{ "B8AF67", "Hewlett Packard" },
{ "9C3426", "ARRIS Group, Inc." },
{ "188B45", "Cisco Systems, Inc" },
{ "B0C090", "Chicony Electronics Co., Ltd." },
{ "001DD2", "ARRIS Group, Inc." },
{ "B0C287", "Technicolor CH USA" },
{ "1CA770", "SHENZHEN CHUANGWEI-RGB ELECTRONICS CO.,LTD" },
{ "C42F90", "Hangzhou Hikvision Digital Technology Co.,Ltd." },
{ "9C5D12", "Aerohive Networks Inc." },
{ "1CCB99", "TCT mobile ltd" },
{ "A42BB0", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "4CE676", "BUFFALO.INC" },
{ "B0C745", "BUFFALO.INC" },
{ "CCE1D5", "BUFFALO.INC" },
{ "B8FC9A", "Le Shi Zhi Xin Electronic Technology (Tianjin) Limited" },
{ "2C4138", "Hewlett Packard" },
{ "2C768A", "Hewlett Packard" },
{ "0018FE", "Hewlett Packard" },
{ "0019BB", "Hewlett Packard" },
{ "002264", "Hewlett Packard" },
{ "002481", "Hewlett Packard" },
{ "000D9D", "Hewlett Packard" },
{ "0014C2", "Hewlett Packard" },
{ "788B77", "Standar Telecom" },
{ "84ACFB", "Crouzet Automatismes" },
{ "34BA75", "Tembo Systems, Inc." },
{ "FCFFAA", "IEEE Registration Authority" },
{ "00CB00", "Private" },
{ "9486CD", "SEOUL ELECTRONICS&TELECOM" },
{ "94ABDE", "OMX Technology - FZE" },
{ "000E35", "Intel Corporation" },
{ "00207B", "Intel Corporation" },
{ "0013CE", "Intel Corporate" },
{ "801934", "Intel Corporate" },
{ "B8B81E", "Intel Corporate" },
{ "185E0F", "Intel Corporate" },
{ "C80E77", "Le Shi Zhi Xin Electronic Technology (Tianjin) Limited" },
{ "843497", "Hewlett Packard" },
{ "ECB1D7", "Hewlett Packard" },
{ "3CA82A", "Hewlett Packard" },
{ "480FCF", "Hewlett Packard" },
{ "5820B1", "Hewlett Packard" },
{ "2C233A", "Hewlett Packard" },
{ "000EB3", "Hewlett Packard" },
{ "0004EA", "Hewlett Packard" },
{ "00306E", "Hewlett Packard" },
{ "0060B0", "Hewlett Packard" },
{ "24BE05", "Hewlett Packard" },
{ "94877C", "ARRIS Group, Inc." },
{ "407009", "ARRIS Group, Inc." },
{ "F8EDA5", "ARRIS Group, Inc." },
{ "5465DE", "ARRIS Group, Inc." },
{ "6CCA08", "ARRIS Group, Inc." },
{ "5C8FE0", "ARRIS Group, Inc." },
{ "BCCAB5", "ARRIS Group, Inc." },
{ "000FCC", "ARRIS Group, Inc." },
{ "000423", "Intel Corporation" },
{ "0008C7", "Hewlett Packard" },
{ "0010E3", "Hewlett Packard" },
{ "00805F", "Hewlett Packard" },
{ "BCEAFA", "Hewlett Packard" },
{ "5C8A38", "Hewlett Packard" },
{ "D89D67", "Hewlett Packard" },
{ "2C44FD", "Hewlett Packard" },
{ "F0921C", "Hewlett Packard" },
{ "B4B52F", "Hewlett Packard" },
{ "902155", "HTC Corporation" },
{ "64A769", "HTC Corporation" },
{ "BCCFCC", "HTC Corporation" },
{ "B0F1A3", "Fengfan (BeiJing) Technology Co., Ltd. " },
{ "90CDB6", "Hon Hai Precision Ind. Co.,Ltd." },
{ "7C7D3D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4482E5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "00265C", "Hon Hai Precision Ind. Co.,Ltd." },
{ "002556", "Hon Hai Precision Ind. Co.,Ltd." },
{ "542758", "Motorola (Wuhan) Mobility Technologies Communication Co., Ltd." },
{ "4CD08A", "HUMAX Co., Ltd." },
{ "20906F", "Shenzhen Tencent Computer System Co., Ltd." },
{ "1C7839", "Shenzhen Tencent Computer System Co., Ltd." },
{ "D837BE", "Shanghai Gongjing Telecom Technology Co,LTD" },
{ "A4516F", "Microsoft Mobile Oy" },
{ "FC64BA", "Xiaomi Communications Co Ltd" },
{ "246081", "razberi technologies" },
{ "8CAB8E", "Shanghai Feixun Communication Co.,Ltd." },
{ "9060F1", "Apple, Inc." },
{ "EC26CA", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "001FE1", "Hon Hai Precision Ind. Co.,Ltd." },
{ "002268", "Hon Hai Precision Ind. Co.,Ltd." },
{ "9471AC", "TCT mobile ltd" },
{ "A09347", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "2C088C", "HUMAX Co., Ltd." },
{ "D42C0F", "Pace plc" },
{ "40F308", "Murata Manufacturing Co., Ltd." },
{ "5CDAD4", "Murata Manufacturing Co., Ltd." },
{ "000E6D", "Murata Manufacturing Co., Ltd." },
{ "904CE5", "Hon Hai Precision Ind. Co.,Ltd." },
{ "CCAF78", "Hon Hai Precision Ind. Co.,Ltd." },
{ "1C666D", "Hon Hai Precision Ind. Co.,Ltd." },
{ "785968", "Hon Hai Precision Ind. Co.,Ltd." },
{ "F80D43", "Hon Hai Precision Ind. Co.,Ltd." },
{ "F866D1", "Hon Hai Precision Ind. Co.,Ltd." },
{ "0071CC", "Hon Hai Precision Ind. Co.,Ltd." },
{ "B05B67", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "38F889", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F4DCF9", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "904E2B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0C96BF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "9CC172", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0014C9", "Brocade Communications Systems, Inc." },
{ "00010F", "Brocade Communications Systems, Inc." },
{ "080088", "Brocade Communications Systems, Inc." },
{ "00051E", "Brocade Communications Systems, Inc." },
{ "384608", "zte corporation" },
{ "B4B362", "zte corporation" },
{ "B075D5", "zte corporation" },
{ "08181A", "zte corporation" },
{ "002512", "zte corporation" },
{ "CCF954", "Avaya Inc" },
{ "703018", "Avaya Inc" },
{ "B0A37E", "Qingdao Haier Telecom Co.，Ltd" },
{ "70A8E3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "F84ABF", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4CB16C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "4C1FCC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "486276", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "AC4E91", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "E468A3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "80D09B", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "581F28", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "8C34FD", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "90671C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "587F66", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "BC25E0", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "C4072F", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0CD6BD", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "A49947", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "346BD3", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "1C1D67", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "84A8E4", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "202BC1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "3475C7", "Avaya Inc" },
{ "6CFA58", "Avaya Inc" },
{ "64A7DD", "Avaya Inc" },
{ "646A52", "Avaya Inc" },
{ "F873A2", "Avaya Inc" },
{ "64C354", "Avaya Inc" },
{ "B4B017", "Avaya Inc" },
{ "581626", "Avaya Inc" },
{ "741BB2", "Apple, Inc." },
{ "002586", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F8D111", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "F4EC38", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "20DCE6", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "1C6E4C", "Logistic Service & Engineering Co.,Ltd" },
{ "00101F", "Cisco Systems, Inc" },
{ "001054", "Cisco Systems, Inc" },
{ "DCEB94", "Cisco Systems, Inc" },
{ "5C838F", "Cisco Systems, Inc" },
{ "AC7E8A", "Cisco Systems, Inc" },
{ "382056", "Cisco Systems, Inc" },
{ "28CFE9", "Apple, Inc." },
{ "00502A", "Cisco Systems, Inc" },
{ "005014", "Cisco Systems, Inc" },
{ "0090D9", "Cisco Systems, Inc" },
{ "009092", "Cisco Systems, Inc" },
{ "001029", "Cisco Systems, Inc" },
{ "001007", "Cisco Systems, Inc" },
{ "00605C", "Cisco Systems, Inc" },
{ "00E0F7", "Cisco Systems, Inc" },
{ "00E0B0", "Cisco Systems, Inc" },
{ "00E0FE", "Cisco Systems, Inc" },
{ "00E0A3", "Cisco Systems, Inc" },
{ "00E0F9", "Cisco Systems, Inc" },
{ "001BD7", "Cisco SPVTG" },
{ "105172", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "9017AC", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "94049C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "001237", "Texas Instruments" },
{ "948854", "Texas Instruments" },
{ "A863F2", "Texas Instruments" },
{ "D0FF50", "Texas Instruments" },
{ "20C38F", "Texas Instruments" },
{ "A0E6F8", "Texas Instruments" },
{ "5C313E", "Texas Instruments" },
{ "F4B85E", "Texas Instruments" },
{ "68C90B", "Texas Instruments" },
{ "EC24B8", "Texas Instruments" },
{ "689E19", "Texas Instruments" },
{ "C46AB7", "Xiaomi Communications Co Ltd" },
{ "68DFDD", "Xiaomi Communications Co Ltd" },
{ "64B473", "Xiaomi Communications Co Ltd" },
{ "7451BA", "Xiaomi Communications Co Ltd" },
{ "3480B3", "Xiaomi Communications Co Ltd" },
{ "5006AB", "Cisco Systems, Inc" },
{ "0050E2", "Cisco Systems, Inc" },
{ "005050", "Cisco Systems, Inc" },
{ "009021", "Cisco Systems, Inc" },
{ "0090B1", "Cisco Systems, Inc" },
{ "00023D", "Cisco Systems, Inc" },
{ "18E728", "Cisco Systems, Inc" },
{ "2C3ECF", "Cisco Systems, Inc" },
{ "1005CA", "Cisco Systems, Inc" },
{ "1CDEA7", "Cisco Systems, Inc" },
{ "1C6A7A", "Cisco Systems, Inc" },
{ "CCD8C1", "Cisco Systems, Inc" },
{ "7C0ECE", "Cisco Systems, Inc" },
{ "F09E63", "Cisco Systems, Inc" },
{ "F07F06", "Cisco Systems, Inc" },
{ "84802D", "Cisco Systems, Inc" },
{ "E0899D", "Cisco Systems, Inc" },
{ "A89D21", "Cisco Systems, Inc" },
{ "BCF1F2", "Cisco Systems, Inc" },
{ "C80084", "Cisco Systems, Inc" },
{ "A0F849", "Cisco Systems, Inc" },
{ "88908D", "Cisco Systems, Inc" },
{ "A46C2A", "Cisco Systems, Inc" },
{ "0021BE", "Cisco SPVTG" },
{ "7CB21B", "Cisco SPVTG" },
{ "002643", "ALPS ELECTRIC CO.,LTD." },
{ "002433", "ALPS ELECTRIC CO.,LTD." },
{ "745E1C", "PIONEER CORPORATION" },
{ "0006F5", "ALPS ELECTRIC CO.,LTD." },
{ "0006F7", "ALPS ELECTRIC CO.,LTD." },
{ "000704", "ALPS ELECTRIC CO.,LTD." },
{ "1C1D86", "Cisco Systems, Inc" },
{ "E0B7B1", "Pace plc" },
{ "001A92", "ASUSTek COMPUTER INC." },
{ "001D60", "ASUSTek COMPUTER INC." },
{ "002215", "ASUSTek COMPUTER INC." },
{ "20CF30", "ASUSTek COMPUTER INC." },
{ "E0CB4E", "ASUSTek COMPUTER INC." },
{ "1C872C", "ASUSTek COMPUTER INC." },
{ "C4143C", "Cisco Systems, Inc" },
{ "2401C7", "Cisco Systems, Inc" },
{ "04DAD2", "Cisco Systems, Inc" },
{ "F41FC2", "Cisco Systems, Inc" },
{ "4C0082", "Cisco Systems, Inc" },
{ "DCA5F4", "Cisco Systems, Inc" },
{ "7C95F3", "Cisco Systems, Inc" },
{ "5017FF", "Cisco Systems, Inc" },
{ "E8EDF3", "Cisco Systems, Inc" },
{ "78DA6E", "Cisco Systems, Inc" },
{ "24E9B3", "Cisco Systems, Inc" },
{ "E425E7", "Apple, Inc." },
{ "080007", "Apple, Inc." },
{ "000A95", "Apple, Inc." },
{ "002241", "Apple, Inc." },
{ "0023DF", "Apple, Inc." },
{ "0025BC", "Apple, Inc." },
{ "00264A", "Apple, Inc." },
{ "0026B0", "Apple, Inc." },
{ "041E64", "Apple, Inc." },
{ "D49A20", "Apple, Inc." },
{ "9027E4", "Apple, Inc." },
{ "60334B", "Apple, Inc." },
{ "A43135", "Apple, Inc." },
{ "9C35EB", "Apple, Inc." },
{ "507A55", "Apple, Inc." },
{ "A0999B", "Apple, Inc." },
{ "24240E", "Apple, Inc." },
{ "903C92", "Apple, Inc." },
{ "341298", "Apple, Inc." },
{ "9C293F", "Apple, Inc." },
{ "488AD2", "SHENZHEN MERCURY COMMUNICATION TECHNOLOGIES CO.,LTD." },
{ "A88E24", "Apple, Inc." },
{ "E8802E", "Apple, Inc." },
{ "68AE20", "Apple, Inc." },
{ "E0B52D", "Apple, Inc." },
{ "80BE05", "Apple, Inc." },
{ "D8BB2C", "Apple, Inc." },
{ "D04F7E", "Apple, Inc." },
{ "2C1F23", "Apple, Inc." },
{ "549F13", "Apple, Inc." },
{ "B8098A", "Apple, Inc." },
{ "F0DBE2", "Apple, Inc." },
{ "18EE69", "Apple, Inc." },
{ "748114", "Apple, Inc." },
{ "18F643", "Apple, Inc." },
{ "D0A637", "Apple, Inc." },
{ "A01828", "Apple, Inc." },
{ "D0034B", "Apple, Inc." },
{ "5C5948", "Apple, Inc." },
{ "78CA39", "Apple, Inc." },
{ "18E7F4", "Apple, Inc." },
{ "B8FF61", "Apple, Inc." },
{ "DC2B61", "Apple, Inc." },
{ "1093E9", "Apple, Inc." },
{ "442A60", "Apple, Inc." },
{ "E0F847", "Apple, Inc." },
{ "145A05", "Apple, Inc." },
{ "28CFDA", "Apple, Inc." },
{ "148FC6", "Apple, Inc." },
{ "283737", "Apple, Inc." },
{ "045453", "Apple, Inc." },
{ "F0CBA1", "Apple, Inc." },
{ "C06394", "Apple, Inc." },
{ "8C006D", "Apple, Inc." },
{ "B09FBA", "Apple, Inc." },
{ "DC86D8", "Apple, Inc." },
{ "8C2937", "Apple, Inc." },
{ "DC9B9C", "Apple, Inc." },
{ "98F0AB", "Apple, Inc." },
{ "F0DBF8", "Apple, Inc." },
{ "ACCF5C", "Apple, Inc." },
{ "3C15C2", "Apple, Inc." },
{ "04489A", "Apple, Inc." },
{ "D8CF9C", "Apple, Inc." },
{ "30F7C5", "Apple, Inc." },
{ "008865", "Apple, Inc." },
{ "40B395", "Apple, Inc." },
{ "3090AB", "Apple, Inc." },
{ "1CE62B", "Apple, Inc." },
{ "A0EDCD", "Apple, Inc." },
{ "A886DD", "Apple, Inc." },
{ "54EAA8", "Apple, Inc." },
{ "E4C63D", "Apple, Inc." },
{ "843835", "Apple, Inc." },
{ "7073CB", "Apple, Inc." },
{ "9C207B", "Apple, Inc." },
{ "842999", "Apple, Inc." },
{ "74E2F5", "Apple, Inc." },
{ "20C9D0", "Apple, Inc." },
{ "1402EC", "Hewlett Packard Enterprise" },
{ "707938", "Wuxi Zhanrui Electronic Technology Co.,LTD" },
{ "646A74", "AUTH-SERVERS, LLC" },
{ "34C9F0", "LM Technologies Ltd" },
{ "E034E4", "Feit Electric Company, Inc." },
{ "681401", "Hon Hai Precision Ind. Co.,Ltd." },
{ "98E848", "Axiim" },
{ "A0F9E0", "VIVATEL COMPANY LIMITED" },
{ "F8C372", "TSUZUKI DENKI" },
{ "908D78", "D-Link International" },
{ "A4CC32", "Inficomm Co., Ltd" },
{ "582BDB", "Pax AB" },
{ "D00F6D", "T&W Electronics Company" },
{ "48BF74", "Baicells Technologies Co.,LTD" },
{ "38F557", "JOLATA, INC." },
{ "280E8B", "Beijing Spirit Technology Development Co., Ltd." },
{ "F44D30", "Elitegroup Computer Systems Co.,Ltd." },
{ "DC9A8E", "Nanjing Cocomm electronics co., LTD" },
{ "C4EF70", "Home Skinovations" },
{ "B813E9", "Trace Live Network" },
{ "746F19", "ICARVISIONS (SHENZHEN) TECHNOLOGY CO., LTD." },
{ "7C7176", "Wuxi iData Technology Company Ltd." },
{ "7C0191", "Apple, Inc." },
{ "70480F", "Apple, Inc." },
{ "A4B805", "Apple, Inc." },
{ "587F57", "Apple, Inc." },
{ "80D605", "Apple, Inc." },
{ "68A828", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "988744", "Wuxi Hongda Science and Technology Co.,LTD" },
{ "C869CD", "Apple, Inc." },
{ "BC6C21", "Apple, Inc." },
{ "9C8DD3", "Leonton Technologies" },
{ "246C8A", "YUKAI Engineering" },
{ "A43831", "RF elements s.r.o." },
{ "D0BAE4", "Shanghai MXCHIP Information Technology Co., Ltd." },
{ "A4DCBE", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "10CC1B", "Liverock technologies,INC" },
{ "48B620", "ROLI Ltd." },
{ "20D160", "Private" },
{ "382187", "Midea Group Co., Ltd." },
{ "305A3A", "ASUSTek COMPUTER INC." },
{ "A87285", "IDT, INC." },
{ "AC1FD7", "Real Vision Technology Co.,Ltd." },
{ "C8A2CE", "Oasis Media Systems LLC" },
{ "A4DEC9", "QLove Mobile Intelligence Information Technology (W.H.) Co. Ltd." },
{ "3C7A8A", "ARRIS Group, Inc." },
{ "A4A6A9", "Private" },
{ "0469F8", "Apple, Inc." },
{ "9C7A03", "Ciena Corporation" },
{ "380AAB", "Formlabs" },
{ "F41535", "SPON Communication Technology Co.,Ltd" },
{ "E41A2C", "ZPE Systems, Inc." },
{ "A815D6", "Shenzhen Meione Technology CO., LTD" },
{ "D09380", "Ducere Technologies Pvt. Ltd." },
{ "84A788", "Perples" },
{ "6889C1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "845B12", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "143EBF", "zte corporation" },
{ "041E7A", "DSPWorks" },
{ "38B725", "Wistron Infocomm (Zhongshan) Corporation" },
{ "ACEC80", "ARRIS Group, Inc." },
{ "80EA23", "Wistron Neweb Corp." },
{ "4CC681", "Shenzhen Aisat Electronic Co., Ltd." },
{ "28B9D9", "Radisys Corporation" },
{ "E0553D", "Cisco Meraki" },
{ "0894EF", "Wistron Infocomm (Zhongshan) Corporation" },
{ "304487", "Hefei Radio Communication Technology Co., Ltd" },
{ "E0319E", "Valve Corporation" },
{ "E4A32F", "Shanghai Artimen Technology Co., Ltd." },
{ "D47BB0", "ASKEY COMPUTER CORP" },
{ "5045F7", "Liuhe Intelligence Technology Ltd." },
{ "20F510", "Codex Digital Limited" },
{ "949F3E", "Sonos, Inc." },
{ "788E33", "Jiangsu SEUIC Technology Co.,Ltd" },
{ "94D859", "TCT mobile ltd" },
{ "E01AEA", "Allied Telesis, Inc." },
{ "340CED", "Moduel AB" },
{ "507B9D", "LCFC(HeFei) Electronics Technology co., ltd" },
{ "6C7220", "D-Link International" },
{ "F02624", "WAFA TECHNOLOGIES CO., LTD." },
{ "F8F464", "Rawe Electonic GmbH" },
{ "F4672D", "ShenZhen Topstar Technology Company" },
{ "382B78", "ECO PLUGS ENTERPRISE CO., LTD" },
{ "606DC7", "Hon Hai Precision Ind. Co.,Ltd." },
{ "BCEB5F", "Fujian Beifeng Telecom Technology Co., Ltd." },
{ "800B51", "Chengdu XGimi Technology Co.,Ltd" },
{ "00FC8D", "Hitron Technologies. Inc" },
{ "1CC586", "Absolute Acoustics" },
{ "C49A02", "LG Electronics (Mobile Communicaitons)" },
{ "E076D0", "AMPAK Technology, Inc." },
{ "24B0A9", "Shanghai Mobiletek Communication Ltd." },
{ "64167F", "Polycom" },
{ "54E2C8", "Dongguan Aoyuan Electronics Technology Co., Ltd" },
{ "08D0B7", "HISENSE ELECTRIC CO.,LTD." },
{ "20D75A", "Posh Mobile Limited" },
{ "88D37B", "FirmTek, LLC" },
{ "10AF78", "Shenzhen ATUE Technology Co., Ltd" },
{ "B0966C", "Lanbowan Technology Ltd." },
{ "A408EA", "Murata Manufacturing Co., Ltd." },
{ "D4F9A1", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "9CB6D0", "Rivet Networks" },
{ "D0C0BF", "Actions Microelectronics Co., Ltd" },
{ "94F665", "Ruckus Wireless" },
{ "707781", "Hon Hai Precision Ind. Co.,Ltd." },
{ "E04B45", "Hi-P Electronics Pte Ltd" },
{ "6C4598", "Antex Electronic Corp." },
{ "94A7B7", "zte corporation" },
{ "3C8375", "Microsoft Corporation" },
{ "C8458F", "Wyler AG" },
{ "149A10", "Microsoft Corporation" },
{ "FC9AFA", "Motus Global Inc." },
{ "5CB43E", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "FCE1FB", "Array Networks" },
{ "54E140", "INGENICO" },
{ "14157C", "TOKYO COSMOS ELECTRIC CO.,LTD." },
{ "408D5C", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "6CE01E", "Modcam AB" },
{ "D09DAB", "TCT mobile ltd" },
{ "E8F2E3", "Starcor Beijing Co.,Limited" },
{ "D048F3", "DATTUS Inc" },
{ "CC19A8", "PT Inovação e Sistemas SA" },
{ "6C4418", "Zappware" },
{ "44962B", "Aidon Oy" },
{ "D4D7A9", "Shanghai Kaixiang Info Tech LTD" },
{ "185D9A", "BobjGear LLC" },
{ "884157", "Shenzhen Atsmart Technology Co.,Ltd." },
{ "3CDA2A", "zte corporation" },
{ "747336", "MICRODIGTAL Inc" },
{ "0CE725", "Microsoft Corporation" },
{ "6C2E72", "B&B EXPORTING LIMITED" },
{ "98EECB", "Wistron InfoComm(ZhongShan)Corporation" },
{ "FC3288", "CELOT Wireless Co., Ltd" },
{ "BCB308", "HONGKONG RAGENTEK COMMUNICATION TECHNOLOGY CO.,LIMITED" },
{ "445ECD", "Razer Inc" },
{ "749637", "Todaair Electronic Co., Ltd" },
{ "2031EB", "HDSN" },
{ "C0335E", "Microsoft" },
{ "ACCAAB", "Virtual Electric Inc" },
{ "241B44", "Hangzhou Tuners Electronics Co., Ltd" },
{ "B0E03C", "TCT mobile ltd" },
{ "90C35F", "Nanjing Jiahao Technology Co., Ltd." },
{ "18F145", "NetComm Wireless Limited" },
{ "4CA515", "Baikal Electronics JSC" },
{ "9CE230", "JULONG CO,.LTD." },
{ "80F503", "Pace plc" },
{ "34873D", "Quectel Wireless Solution Co.,Ltd." },
{ "186882", "Beward R&D Co., Ltd." },
{ "FC3D93", "LONGCHEER TELECOMMUNICATION LIMITED" },
{ "344CA4", "amazipoint technology Ltd." },
{ "A8F038", "SHEN ZHEN SHI JIN HUA TAI ELECTRONICS CO.,LTD" },
{ "74E277", "Vizmonet Pte Ltd" },
{ "10A659", "Mobile Create Co.,Ltd." },
{ "58856E", "QSC AG" },
{ "FCAFAC", "Socionext Inc." },
{ "F8C397", "NZXT Corp. Ltd." },
{ "C4366C", "LG Innotek" },
{ "D85DE2", "Hon Hai Precision Ind. Co.,Ltd." },
{ "60D9A0", "Lenovo Mobile Communication Technology Ltd." },
{ "5C3B35", "Gehirn Inc." },
{ "5CF7C3", "SYNTECH (HK) TECHNOLOGY LIMITED" },
{ "3CC2E1", "XINHUA CONTROL ENGINEERING CO.,LTD" },
{ "7C534A", "Metamako" },
{ "9C3066", "RWE Effizienz GmbH" },
{ "FCA22A", "PT. Callysta Multi Engineering" },
{ "247656", "Shanghai Net Miles Fiber Optics Technology Co., LTD." },
{ "A0ADA1", "JMR Electronics, Inc" },
{ "601970", "HUIZHOU QIAOXING ELECTRONICS TECHNOLOGY CO., LTD." },
{ "887033", "Hangzhou Silan Microelectronic Inc" },
{ "8C7967", "zte corporation" },
{ "D083D4", "XTel ApS" },
{ "78F944", "Private" },
{ "CCA4AF", "Shenzhen Sowell Technology Co., LTD" },
{ "84F129", "Metrascale Inc." },
{ "2028BC", "Visionscape Co,. Ltd." },
{ "B8F080", "SPS, INC." },
{ "7858F3", "Vachen Co.,Ltd" },
{ "FCDC4A", "G-Wearables Corp." },
{ "F42C56", "SENOR TECH CO LTD" },
{ "50502A", "Egardia" },
{ "48EE0C", "D-Link International" },
{ "48C093", "Xirrus, Inc." },
{ "3C1A0F", "ClearSky Data" },
{ "ACB57D", "Liteon Technology Corporation" },
{ "DCE1AD", "Shenzhen Wintop Photoelectric Technology Co., Ltd" },
{ "900CB4", "Alinket Electronic Technology Co., Ltd" },
{ "883B8B", "Cheering Connection Co. Ltd." },
{ "94D417", "GPI KOREA INC." },
{ "D855A3", "zte corporation" },
{ "70DA9C", "TECSEN" },
{ "6CF5E8", "Mooredoll Inc." },
{ "70FF5C", "Cheerzing Communication(Xiamen)Technology Co.,Ltd" },
{ "E0107F", "Ruckus Wireless" },
{ "08115E", "Bitel Co., Ltd." },
{ "44CE7D", "SFR" },
{ "0881BC", "HongKong Ipro Technology Co., Limited" },
{ "4C16F1", "zte corporation" },
{ "800902", "Keysight Technologies, Inc." },
{ "6872DC", "CETORY.TV Company Limited" },
{ "D8B6B7", "Comtrend Corporation" },
{ "0499E6", "Shenzhen Yoostar Technology Co., Ltd" },
{ "94BF95", "Shenzhen Coship Electronics Co., Ltd" },
{ "344DF7", "LG Electronics" },
{ "FC9FE1", "CONWIN.Tech. Ltd" },
{ "90203A", "BYD Precision Manufacture Co.,Ltd" },
{ "A81B5D", "Foxtel Management Pty Ltd" },
{ "B8BD79", "TrendPoint Systems" },
{ "2C010B", "NASCENT Technology, LLC - RemKon" },
{ "D4EC86", "LinkedHope Intelligent Technologies Co., Ltd" },
{ "20A99B", "Microsoft Corporation" },
{ "6C7660", "KYOCERA Corporation" },
{ "A0A3E2", "Actiontec Electronics, Inc" },
{ "54098D", "deister electronic GmbH" },
{ "F0FE6B", "Shanghai High-Flying Electronics Technology Co., Ltd" },
{ "3CAE69", "ESA Elektroschaltanlagen Grimma GmbH" },
{ "00F3DB", "WOO Sports" },
{ "08A5C8", "Sunnovo International Limited" },
{ "848EDF", "Sony Mobile Communications AB" },
{ "CCBDD3", "Ultimaker B.V." },
{ "50294D", "NANJING IOT SENSOR TECHNOLOGY CO,LTD" },
{ "90EF68", "ZyXEL Communications Corporation" },
{ "0CCFD1", "SPRINGWAVE Co., Ltd" },
{ "58108C", "Intelbras" },
{ "187117", "eta plus electronic gmbh" },
{ "7CB177", "Satelco AG" },
{ "8C5D60", "UCI Corporation Co.,Ltd." },
{ "104B46", "Mitsubishi Electric Corporation" },
{ "4C0BBE", "Microsoft" },
{ "08EB29", "Jiangsu Huitong Group Co.,Ltd." },
{ "D88039", "Microchip Technology Inc." },
{ "E48C0F", "Discovery Insure" },
{ "587FB7", "SONAR INDUSTRIAL CO., LTD." },
{ "E42354", "SHENZHEN FUZHI SOFTWARE TECHNOLOGY CO.,LTD" },
{ "207693", "Lenovo (Beijing) Limited." },
{ "C4BD6A", "SKF GmbH" },
{ "14488B", "Shenzhen Doov Technology Co.,Ltd" },
{ "70BAEF", "Hangzhou H3C Technologies Co., Limited" },
{ "CC03FA", "Technicolor CH USA" },
{ "603696", "The Sapling Company" },
{ "54FFCF", "Mopria Alliance" },
{ "BCBC46", "SKS Welding Systems GmbH" },
{ "A8D88A", "Wyconn" },
{ "00E6E8", "Netzin Technology Corporation,.Ltd." },
{ "64B21D", "Chengdu Phycom Tech Co., Ltd." },
{ "88708C", "Lenovo Mobile Communication Technology Ltd." },
{ "F03D29", "Actility" },
{ "909F33", "EFM Networks" },
{ "849681", "Cathay Communication Co.,Ltd" },
{ "A056B2", "Harman/Becker Automotive Systems GmbH" },
{ "40C62A", "Shanghai Jing Ren Electronic Technology Co., Ltd." },
{ "E8150E", "Nokia Corporation" },
{ "F4D032", "Yunnan Ideal Information&Technology.,Ltd" },
{ "44A6E5", "THINKING TECHNOLOGY CO.,LTD" },
{ "A8329A", "Digicom Futuristic Technologies Ltd." },
{ "B40AC6", "DEXON Systems Ltd." },
{ "480C49", "NAKAYO TELECOMMUNICATIONS,INC" },
{ "5CB8CB", "Allis Communications" },
{ "4C9EFF", "ZyXEL Communications Corporation" },
{ "C44BD1", "Wallys Communications  Teachnologies Co.,Ltd." },
{ "E85D6B", "Luminate Wireless" },
{ "8C3357", "HiteVision Digital Media Technology Co.,Ltd." },
{ "506787", "iTellus" },
{ "F4D261", "SEMOCON Co., Ltd" },
{ "D05AF1", "Shenzhen Pulier Tech CO.,Ltd" },
{ "481A84", "Pointer Telocation Ltd" },
{ "E4F4C6", "NETGEAR" },
{ "DC663A", "Apacer Technology Inc." },
{ "B009D3", "Avizia" },
{ "B01041", "Hon Hai Precision Ind. Co.,Ltd." },
{ "3CAA3F", "iKey, Ltd." },
{ "0C383E", "Fanvil Technology Co., Ltd." },
{ "60CDA9", "Abloomy" },
{ "B40B44", "Smartisan Technology Co., Ltd." },
{ "A0FC6E", "Telegrafia a.s." },
{ "44D4E0", "Sony Mobile Communications AB" },
{ "5CF4AB", "ZyXEL Communications Corporation" },
{ "D0FA1D", "Qihoo  360  Technology Co.,Ltd" },
{ "046785", "scemtec Hard- und Software fuer Mess- und Steuerungstechnik GmbH" },
{ "FC6DC0", "BME CORPORATION" },
{ "784561", "CyberTAN Technology Inc." },
{ "D896E0", "Alibaba Cloud Computing Ltd." },
{ "300D2A", "Zhejiang Wellcom Technology Co.,Ltd." },
{ "8496D8", "Pace plc" },
{ "64EAC5", "SiboTech Automation Co., Ltd." },
{ "74DA38", "Edimax Technology Co. Ltd." },
{ "F4F26D", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "5C1515", "ADVAN" },
{ "D0A0D6", "Chengdu TD Tech Ltd." },
{ "8CBF9D", "Shanghai Xinyou Information Technology Ltd. Co." },
{ "D49398", "Nokia Corporation" },
{ "78D66F", "Aristocrat Technologies Australia Pty. Ltd." },
{ "50C7BF", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "C06118", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "D0C7C0", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "209AE9", "Volacomm Co., Ltd" },
{ "345D10", "Wytek" },
{ "58E326", "Compass Technologies Inc." },
{ "848DC7", "Cisco SPVTG" },
{ "A8BD3A", "UNIONMAN TECHNOLOGY CO.,LTD" },
{ "C44E1F", "BlueN" },
{ "CCA614", "AIFA TECHNOLOGY CORP." },
{ "B0869E", "Chloride S.r.L" },
{ "344F5C", "R&amp;M AG" },
{ "A46CC1", "LTi REEnergy GmbH" },
{ "90DB46", "E-LEAD ELECTRONIC CO., LTD" },
{ "F8A9D0", "LG Electronics" },
{ "289AFA", "TCT Mobile Limited" },
{ "D42F23", "Akenori PTE Ltd" },
{ "286336", "Siemens AG - Industrial Automation - EWA" },
{ "38F098", "Vapor Stone Rail Systems" },
{ "400107", "Arista Corp" },
{ "4C8B30", "Actiontec Electronics, Inc" },
{ "0805CD", "DongGuang EnMai Electronic Product Co.Ltd." },
{ "0092FA", "SHENZHEN WISKY TECHNOLOGY CO.,LTD" },
{ "4CF45B", "Blue Clover Devices" },
{ "B06971", "DEI Sales, Inc." },
{ "58493B", "Palo Alto Networks" },
{ "580528", "LABRIS NETWORKS" },
{ "28656B", "Keystone Microtech Corporation" },
{ "EC2E4E", "HITACHI-LG DATA STORAGE INC" },
{ "505800", "WyTec International, Inc." },
{ "78923E", "Nokia Corporation" },
{ "D4CFF9", "Shenzhen Sen5 Technology Co., Ltd." },
{ "D8492F", "CANON INC." },
{ "D46761", "SAHAB TECHNOLOGY" },
{ "145645", "Savitech Corp." },
{ "D4E08E", "ValueHD Corporation" },
{ "70305D", "Ubiquoss Inc" },
{ "5850AB", "TLS Corporation" },
{ "90DFB7", "s.m.s smart microwave sensors GmbH" },
{ "B843E4", "Vlatacom" },
{ "8425A4", "Tariox Limited" },
{ "E07F53", "TECHBOARD SRL" },
{ "4C0DEE", "JABIL CIRCUIT (SHANGHAI) LTD." },
{ "A07771", "Vialis BV" },
{ "D0BD01", "DS International" },
{ "C0C569", "SHANGHAI LYNUC CNC TECHNOLOGY CO.,LTD" },
{ "200E95", "IEC – TC9 WG43" },
{ "E0DB88", "Open Standard Digital-IF Interface for SATCOM Systems" },
{ "D86194", "Objetivos y Sevicios de Valor Añadido" },
{ "589CFC", "FreeBSD Foundation" },
{ "602103", "STCUBE.INC" },
{ "085DDD", "Mercury Corporation" },
{ "98349D", "Krauss Maffei Technologies GmbH" },
{ "18CC23", "Philio Technology Corporation" },
{ "648D9E", "IVT Electronic Co.,Ltd" },
{ "CCFA00", "LG Electronics" },
{ "CC95D7", "Vizio, Inc" },
{ "749C52", "Huizhou Desay SV Automotive Co., Ltd." },
{ "C0F79D", "Powercode" },
{ "3C0C48", "Servergy, Inc." },
{ "68D247", "Portalis LC" },
{ "FC27A2", "TRANS ELECTRIC CO., LTD." },
{ "14C089", "DUNE HD LTD" },
{ "F08A28", "JIANGSU HENGSION ELECTRONIC S and T CO.,LTD" },
{ "A8574E", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "DC3EF8", "Nokia Corporation" },
{ "706173", "Calantec GmbH" },
{ "50C271", "SECURETECH INC" },
{ "7C49B9", "Plexus Manufacturing Sdn Bhd" },
{ "184462", "Riava Networks, Inc." },
{ "9C443D", "CHENGDU XUGUANG TECHNOLOGY CO, LTD" },
{ "301966", "Samsung Electronics Co.,Ltd" },
{ "CC07AB", "Samsung Electronics Co.,Ltd" },
{ "E84E84", "Samsung Electronics Co.,Ltd" },
{ "74A4B5", "Powerleader Science and Technology Co. Ltd." },
{ "BC4100", "CODACO ELECTRONIC s.r.o." },
{ "7CCD3C", "Guangzhou Juzing Technology Co., Ltd" },
{ "10B26B", "base Co.,Ltd." },
{ "DCCEBC", "Shenzhen JSR Technology Co.,Ltd." },
{ "9486D4", "Surveillance Pro Corporation" },
{ "F89550", "Proton Products Chengdu Ltd" },
{ "943BB1", "KAONMEDIA" },
{ "447BC4", "DualShine Technology(SZ)Co.,Ltd" },
{ "542F89", "Euclid Laboratories, Inc." },
{ "48B977", "PulseOn Oy" },
{ "AC2DA3", "TXTR GmbH" },
{ "C8F68D", "S.E.TECHNOLOGIES LIMITED" },
{ "BC14EF", "ITON Technology Limited" },
{ "14F28E", "ShenYang ZhongKe-Allwin Technology Co.LTD" },
{ "C064C6", "Nokia Corporation" },
{ "9C44A6", "SwiftTest, Inc." },
{ "44C4A9", "Opticom Communication, LLC" },
{ "6C3C53", "SoundHawk Corp" },
{ "64BABD", "SDJ Technologies, Inc." },
{ "889166", "Viewcooper Corp." },
{ "103378", "FLECTRON Co., LTD" },
{ "DC0575", "SIEMENS ENERGY AUTOMATION" },
{ "342387", "Hon Hai Precision Ind. Co.,Ltd." },
{ "5C1193", "Seal One AG" },
{ "B4527E", "Sony Mobile Communications AB" },
{ "50E14A", "Private" },
{ "68FCB3", "Next Level Security Systems, Inc." },
{ "70305E", "Nanjing Zhongke Menglian Information Technology Co.,LTD" },
{ "6C98EB", "Ocedo GmbH" },
{ "9C8888", "Simac Techniek NV" },
{ "180C14", "iSonea Limited" },
{ "8CAE89", "Y-cam Solutions Ltd" },
{ "58B961", "SOLEM Electronique" },
{ "F46ABC", "Adonit Corp. Ltd." },
{ "20180E", "Shenzhen Sunchip Technology Co., Ltd" },
{ "80B219", "ELEKTRON TECHNOLOGY UK LIMITED" },
{ "D08A55", "Skullcandy" },
{ "C4D655", "Tercel technology co.,ltd" },
{ "9CA10A", "SCLE SFE" },
{ "78D99F", "NuCom HK Ltd." },
{ "44C56F", "NGN Easy Satfinder (Tianjin) Electronic Co., Ltd" },
{ "2C5A05", "Nokia Corporation" },
{ "848336", "Newrun" },
{ "EC71DB", "Shenzhen Baichuan Digital Technology Co., Ltd." },
{ "B8266C", "ANOV France" },
{ "284D92", "Luminator" },
{ "1C4BB9", "SMG ENTERPRISE, LLC" },
{ "0C5CD8", "DOLI Elektronik GmbH" },
{ "2C5FF3", "Pertronic Industries" },
{ "E0AF4B", "Pluribus Networks, Inc." },
{ "50FC9F", "Samsung Electronics Co.,Ltd" },
{ "C85663", "Sunflex Europe GmbH" },
{ "88FED6", "ShangHai WangYong Software Co., Ltd." },
{ "600347", "Billion Electric Co. Ltd." },
{ "084027", "Gridstore Inc." },
{ "7C2048", "KoamTac" },
{ "BCF5AC", "LG Electronics" },
{ "705986", "OOO TTV" },
{ "20DF3F", "Nanjing SAC Power Grid Automation Co., Ltd." },
{ "30786B", "TIANJIN Golden Pentagon Electronics Co., Ltd." },
{ "4CD637", "Qsono Electronics Co., Ltd" },
{ "8CF945", "Power Automation pte Ltd" },
{ "2C922C", "Kishu Giken Kogyou Company Ltd,." },
{ "509871", "Inventum Technologies Private Limited" },
{ "384233", "Wildeboer Bauteile GmbH" },
{ "9440A2", "Anywave Communication Technologies, Inc." },
{ "7CB77B", "Paradigm Electronics Inc" },
{ "28A241", "exlar corp" },
{ "9876B6", "Adafruit" },
{ "AC220B", "ASUSTek COMPUTER INC." },
{ "88354C", "Transics" },
{ "709BFC", "Bryton Inc." },
{ "D82D9B", "Shenzhen G.Credit Communication Technology Co., Ltd" },
{ "94BF1E", "eflow Inc. / Smart Device Planning and Development Division" },
{ "C0A39E", "EarthCam, Inc." },
{ "088E4F", "SF Software Solutions" },
{ "E8EADA", "Denkovi Assembly Electroncs LTD" },
{ "DCAE04", "CELOXICA Ltd" },
{ "5422F8", "zte corporation" },
{ "486E73", "Pica8, Inc." },
{ "A0CEC8", "CE LINK LIMITED" },
{ "907A28", "Beijing Morncloud Information And Technology Co. Ltd." },
{ "28285D", "ZyXEL Communications Corporation" },
{ "CCD29B", "Shenzhen Bopengfa Elec&Technology CO.,Ltd" },
{ "9C4EBF", "BoxCast" },
{ "34A68C", "Shine Profit Development Limited" },
{ "78DAB3", "GBO Technology" },
{ "80BBEB", "Satmap Systems Ltd" },
{ "6CB7F4", "Samsung Electronics Co.,Ltd" },
{ "C06599", "Samsung Electronics Co.,Ltd" },
{ "182666", "Samsung Electronics Co.,Ltd" },
{ "949FB4", "ChengDu JiaFaAnTai Technology Co.,Ltd" },
{ "406826", "Thales UK Limited" },
{ "5C15E1", "AIDC TECHNOLOGY (S) PTE LTD" },
{ "048D38", "Netcore Technology Inc." },
{ "1C4AF7", "AMON INC" },
{ "985D46", "PeopleNet Communication" },
{ "446755", "Orbit Irrigation" },
{ "789F4C", "HOERBIGER Elektronik GmbH" },
{ "98F8C1", "IDT Technology Limited" },
{ "F47A4E", "Woojeon&Handan" },
{ "28BAB5", "Samsung Electronics Co.,Ltd" },
{ "44700B", "IFFU" },
{ "8C2F39", "IBA Dosimetry GmbH" },
{ "B8F828", "Changshu Gaoshida Optoelectronic Technology Co. Ltd." },
{ "58468F", "Koncar Electronics and Informatics" },
{ "103B59", "Samsung Electronics Co.,Ltd" },
{ "746630", "T:mi Ytti" },
{ "70E284", "Wistron InfoComm(Zhongshan) Corporation" },
{ "B0FEBD", "Private" },
{ "940BD5", "Himax Technologies, Inc" },
{ "30055C", "Brother industries, LTD." },
{ "0C8268", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "B01743", "EDISON GLOBAL CIRCUITS LLC" },
{ "90DA4E", "AVANU" },
{ "7038B4", "Low Tech Solutions" },
{ "AC1826", "SEIKO EPSON CORPORATION" },
{ "4C804F", "Armstrong Monitoring Corp" },
{ "901D27", "zte corporation" },
{ "7CD762", "Freestyle Technology Pty Ltd" },
{ "D073D5", "LIFI LABS MANAGEMENT PTY LTD" },
{ "B8C46F", "PRIMMCON INDUSTRIES INC" },
{ "505AC6", "GUANGDONG SUPER TELECOM CO.,LTD." },
{ "38A86B", "Orga BV" },
{ "141330", "Anakreon UK LLP" },
{ "0CF405", "Beijing Signalway Technologies Co.,Ltd" },
{ "BC72B1", "Samsung Electronics Co.,Ltd" },
{ "78F7BE", "Samsung Electronics Co.,Ltd" },
{ "1C76CA", "Terasic Technologies Inc." },
{ "0C1105", "Ringslink (Xiamen) Network Communication Technologies Co., Ltd" },
{ "945047", "Rechnerbetriebsgruppe" },
{ "D8DCE9", "Kunshan Erlab ductless filtration system Co.,Ltd" },
{ "54112F", "Sulzer Pump Solutions Finland Oy" },
{ "E0DCA0", "Siemens Electrical Apparatus Ltd., Suzhou Chengdu Branch" },
{ "4C55B8", "Turkcell Teknoloji" },
{ "088039", "Cisco SPVTG" },
{ "2C72C3", "Soundmatters" },
{ "84E4D9", "Shenzhen NEED technology Ltd." },
{ "C44838", "Satcom Direct, Inc." },
{ "545414", "Digital RF Corea, Inc" },
{ "24EB65", "SAET I.S. S.r.l." },
{ "D0F27F", "SteadyServ Technoligies, LLC" },
{ "DC647C", "C.R.S. iiMotion GmbH" },
{ "188410", "CoreTrust Inc." },
{ "A08A87", "HuiZhou KaiYue Electronic Co.,Ltd" },
{ "04BFA8", "ISB Corporation" },
{ "5C8486", "Brightsource Industries Israel LTD" },
{ "28CD9C", "Shenzhen Dynamax Software Development Co.,Ltd." },
{ "E0EDC7", "Shenzhen Friendcom Technology Development Co., Ltd" },
{ "2CF203", "EMKO ELEKTRONIK SAN VE TIC AS" },
{ "246278", "sysmocom - systems for mobile communications GmbH" },
{ "F45842", "Boxx TV Ltd" },
{ "A861AA", "Cloudview Limited" },
{ "C89346", "MXCHIP Company Limited" },
{ "F0F260", "Mobitec AB" },
{ "1423D7", "EUTRONIX CO., LTD." },
{ "1C3E84", "Hon Hai Precision Ind. Co.,Ltd." },
{ "3CFB96", "Emcraft Systems LLC" },
{ "081F3F", "WondaLink Inc." },
{ "DC6F08", "Bay Storage Technology" },
{ "E492E7", "Gridlink Tech. Co.,Ltd." },
{ "60BB0C", "Beijing HuaqinWorld Technology Co,Ltd" },
{ "70E027", "HONGYU COMMUNICATION TECHNOLOGY LIMITED" },
{ "E880D8", "GNTEK Electronics Co.,Ltd." },
{ "889B39", "Samsung Electronics Co.,Ltd" },
{ "E432CB", "Samsung Electronics Co.,Ltd" },
{ "188857", "Beijing Jinhong Xi-Dian Information Technology Corp." },
{ "287994", "Realplay Digital Technology(Shenzhen) Co.,Ltd" },
{ "105C3B", "Perma-Pipe, Inc." },
{ "40C4D6", "ChongQing Camyu Technology Development Co.,Ltd." },
{ "A0EB76", "AirCUVE Inc." },
{ "6C6126", "Rinicom Holdings" },
{ "C04DF7", "SERELEC" },
{ "ECD040", "GEA Farm Technologies GmbH" },
{ "005907", "LenovoEMC Products USA, LLC" },
{ "78B3CE", "Elo touch solutions" },
{ "A8FB70", "WiseSec L.t.d" },
{ "30F31D", "zte corporation" },
{ "E4776B", "AARTESYS AG" },
{ "5C335C", "Swissphone Telecom AG" },
{ "A4FCCE", "Security Expert Ltd." },
{ "E0CEC3", "ASKEY COMPUTER CORP" },
{ "5C43D2", "HAZEMEYER" },
{ "D819CE", "Telesquare" },
{ "D809C3", "Cercacor Labs" },
{ "84ED33", "BBMC Co.,Ltd" },
{ "681E8B", "InfoSight Corporation" },
{ "C044E3", "Shenzhen Sinkna Electronics Co., LTD" },
{ "08F1B7", "Towerstream Corpration" },
{ "20858C", "Assa" },
{ "187A93", "AMICCOM Electronics Corporation" },
{ "94C962", "Teseq AG" },
{ "B8763F", "Hon Hai Precision Ind. Co.,Ltd." },
{ "384369", "Patrol Products Consortium LLC" },
{ "D08B7E", "Passif Semiconductor" },
{ "6886E7", "Orbotix, Inc." },
{ "2CE871", "Alert Metalguard ApS" },
{ "58D071", "BW Broadcast" },
{ "C0A0C7", "FAIRFIELD INDUSTRIES" },
{ "98208E", "Definium Technologies" },
{ "704AE4", "Rinstrum Pty Ltd" },
{ "5CA39D", "SAMSUNG ELECTRO-MECHANICS CO., LTD." },
{ "68B8D9", "Act KDE, Inc." },
{ "F84897", "Hitachi, Ltd." },
{ "74E424", "APISTE CORPORATION" },
{ "58D6D3", "Dairy Cheq Inc" },
{ "68FB95", "Generalplus Technology Inc." },
{ "6002B4", "Wistron NeWeb Corp." },
{ "E4C146", "Objetivos y Servicios de Valor A" },
{ "D4BF2D", "SE Controls Asia Pacific Ltd" },
{ "C45DD8", "HDMI Forum" },
{ "C44EAC", "Shenzhen Shiningworth Technology Co., Ltd." },
{ "44334C", "Shenzhen Bilian electronic CO.,LTD" },
{ "C458C2", "Shenzhen TATFOOK Technology Co., Ltd." },
{ "44184F", "Fitview" },
{ "8C76C1", "Goden Tech Limited" },
{ "DC2A14", "Shanghai Longjing Technology Co." },
{ "0C191F", "Inform Electronik" },
{ "080FFA", "KSP INC." },
{ "ECFC55", "A. Eberle GmbH & Co. KG" },
{ "0C8CDC", "Suunto Oy" },
{ "20B5C6", "Mimosa Networks" },
{ "AC3CB4", "Nilan A/S" },
{ "A830AD", "Wei Fang Goertek Electronics Co.,Ltd" },
{ "8007A2", "Esson Technology Inc." },
{ "2C3557", "ELLIY Power CO..Ltd" },
{ "6C5A34", "Shenzhen Haitianxiong Electronic Co., Ltd." },
{ "485A3F", "WISOL" },
{ "70F1E5", "Xetawave LLC" },
{ "C0AA68", "OSASI Technos Inc." },
{ "B829F7", "Blaster Tech" },
{ "CC2D8C", "LG Electronics Inc" },
{ "00C14F", "DDL Co,.ltd." },
{ "5CE0CA", "FeiTian United (Beijing) System Technology Co., Ltd." },
{ "9C9811", "Guangzhou Sunrise Electronics Development Co., Ltd" },
{ "A0FE91", "AVAT Automation GmbH" },
{ "5809E5", "Kivic Inc." },
{ "74ECF1", "Acumen" },
{ "6815D3", "Zaklady Elektroniki i Mechaniki Precyzyjnej R&G S.A." },
{ "50B7C3", "Samsung Electronics CO., LTD" },
{ "601929", "VOLTRONIC POWER TECHNOLOGY(SHENZHEN) CORP." },
{ "C0BD42", "ZPA Smart Energy a.s." },
{ "48B253", "Marketaxess Corporation" },
{ "60D2B9", "REALAND BIO CO., LTD." },
{ "2067B1", "Pluto inc." },
{ "087D21", "Altasec technology corporation" },
{ "30FD11", "MACROTECH (USA) INC." },
{ "F8051C", "DRS Imaging and Targeting Solutions" },
{ "6032F0", "Mplus technology" },
{ "749975", "IBM Corporation" },
{ "0CDCCC", "Inala Technologies" },
{ "F0ACA4", "HBC-radiomatic" },
{ "14DB85", "S NET MEDIA" },
{ "D493A0", "Fidelix Oy" },
{ "AC7236", "Lexking Technology Co., Ltd." },
{ "CCB3F8", "FUJITSU ISOTEC LIMITED" },
{ "3CD7DA", "SK Mtek microelectronics(shenzhen)limited" },
{ "E86D54", "Digit Mobile Inc" },
{ "9857D3", "HON HAI-CCPBG  PRECISION IND.CO.,LTD." },
{ "689423", "Hon Hai Precision Ind. Co.,Ltd." },
{ "9C8D1A", "INTEG process group inc" },
{ "742D0A", "Norfolk Elektronik AG" },
{ "480362", "DESAY ELECTRONICS(HUIZHOU)CO.,LTD" },
{ "B0358D", "Nokia Corporation" },
{ "0CF361", "Java Information" },
{ "34BDFA", "Cisco SPVTG" },
{ "70F927", "Samsung Electronics" },
{ "A8AD3D", "Alcatel-Lucent Shanghai Bell Co., Ltd " },
{ "8CEEC6", "Precepscion Pty. Ltd." },
{ "ECD950", "IRT SA" },
{ "74273C", "ChangYang Technology (Nanjing) Co., LTD" },
{ "087CBE", "Quintic Corp." },
{ "C4AD21", "MEDIAEDGE Corporation" },
{ "DCBF90", "HUIZHOU QIAOXING TELECOMMUNICATION INDUSTRY CO.,LTD." },
{ "E0F5CA", "CHENG UEI PRECISION INDUSTRY CO.,LTD." },
{ "1C5C60", "Shenzhen Belzon Technology Co.,LTD." },
{ "2CEDEB", "Alpheus Digital Company Limited" },
{ "381C4A", "SIMCom Wireless Solutions Co.,Ltd." },
{ "C8DE51", "Integra Networks, Inc." },
{ "5CE8EB", "Samsung Electronics" },
{ "901EDD", "GREAT COMPUTER CORPORATION" },
{ "2C6289", "Regenersis (Glenrothes) Ltd" },
{ "F093C5", "Garland Technology" },
{ "4C09B4", "zte corporation" },
{ "B8B94E", "Shenzhen iBaby Labs, Inc." },
{ "00F403", "Orbis Systems Oy" },
{ "ACC698", "Kohzu Precision Co., Ltd." },
{ "907025", "Garea Microsys Co.,Ltd." },
{ "502ECE", "Asahi Electronics Co.,Ltd" },
{ "440CFD", "NetMan Co., Ltd." },
{ "7CEBEA", "ASCT" },
{ "085B0E", "Fortinet, Inc." },
{ "4C0FC7", "Earda Electronics Co.,Ltd " },
{ "64C944", "LARK Technologies, Inc" },
{ "6869F2", "ComAp s.r.o." },
{ "B889CA", "ILJIN ELECTRIC Co., Ltd." },
{ "B85AFE", "Handaer Communication Technology (Beijing) Co., Ltd" },
{ "604616", "XIAMEN VANN INTELLIGENT CO., LTD" },
{ "ECD925", "RAMI" },
{ "38AA3C", "SAMSUNG ELECTRO-MECHANICS" },
{ "049F06", "Smobile Co., Ltd." },
{ "D806D1", "Honeywell Fire System (Shanghai) Co,. Ltd." },
{ "687251", "Ubiquiti Networks" },
{ "B8D9CE", "Samsung Electronics" },
{ "8C6AE4", "Viogem Limited" },
{ "20C1AF", "i Wit Digital Co., Limited" },
{ "D88A3B", "UNIT-EM" },
{ "BCD940", "ASR Co,.Ltd." },
{ "F45214", "Mellanox Technologies, Inc." },
{ "EC4993", "Qihan Technology Co., Ltd " },
{ "B0ACFA", "FUJITSU LIMITED" },
{ "1C959F", "Veethree Electronics And Marine LLC" },
{ "18D949", "Qvis Labs, LLC" },
{ "646223", "Cellient Co., Ltd." },
{ "F0E77E", "Samsung Electronics Co.,Ltd" },
{ "ACF0B2", "Becker Electronics Taiwan Ltd." },
{ "10A932", "Beijing Cyber Cloud Technology Co. ,Ltd." },
{ "C47BA3", "NAVIS Inc." },
{ "A81758", "Elektronik System i Umeå AB" },
{ "44348F", "MXT INDUSTRIAL LTDA" },
{ "9C0111", "Shenzhen Newabel Electronic Co., Ltd." },
{ "0CA138", "Blinq Wireless Inc." },
{ "B0B2DC", "ZyXEL Communications Corporation" },
{ "348137", "UNICARD SA" },
{ "64F242", "Gerdes Aktiengesellschaft" },
{ "60F281", "TRANWO TECHNOLOGY CO., LTD." },
{ "B0E892", "SEIKO EPSON CORPORATION" },
{ "642400", "Xorcom Ltd." },
{ "4CAA16", "AzureWave Technologies (Shanghai) Inc." },
{ "1C6BCA", "Mitsunami Co., Ltd." },
{ "08379C", "Topaz Co. LTD." },
{ "E83EFB", "GEODESIC LTD." },
{ "4016FA", "EKM Metering" },
{ "3C363D", "Nokia Corporation" },
{ "BC0200", "Stewart Audio" },
{ "1C973D", "PRICOM Design" },
{ "8018A7", "Samsung Eletronics Co., Ltd" },
{ "F00786", "Shandong Bittel Electronics Co., Ltd" },
{ "885C47", "Alcatel Lucent" },
{ "E0F9BE", "Cloudena Corp." },
{ "3CC1F6", "Melange Systems Pvt. Ltd." },
{ "54E63F", "ShenZhen LingKeWeiEr Technology Co., Ltd." },
{ "006B9E", "VIZIO Inc" },
{ "F88C1C", "KAISHUN ELECTRONIC TECHNOLOGY CO., LTD. BEIJING" },
{ "940149", "AutoHotBox" },
{ "C035BD", "Velocytech Aps" },
{ "F897CF", "DAESHIN-INFORMATION TECHNOLOGY CO., LTD." },
{ "383F10", "DBL Technology Ltd." },
{ "8C6878", "Nortek-AS" },
{ "8016B7", "Brunel University" },
{ "9C611D", "Omni-ID USA, Inc." },
{ "78BEBD", "STULZ GmbH" },
{ "3C9174", "ALONG COMMUNICATION TECHNOLOGY" },
{ "B8E937", "Sonos, Inc." },
{ "E8D0FA", "MKS Instruments Deutschland GmbH" },
{ "98262A", "Applied Research Associates, Inc" },
{ "B0D2F5", "Vello Systems, Inc." },
{ "C89F42", "VDII Innovation AB" },
{ "A41875", "Cisco Systems, Inc" },
{ "640E94", "Pluribus Networks, Inc." },
{ "6CE983", "Gastron Co., LTD." },
{ "0CB4EF", "Digience Co.,Ltd." },
{ "D0DB32", "Nokia Corporation" },
{ "609084", "DSSD Inc" },
{ "A4E731", "Nokia Corporation" },
{ "0808EA", "AMSC" },
{ "C05E79", "SHENZHEN HUAXUN ARK TECHNOLOGIES CO.,LTD" },
{ "A4934C", "Cisco Systems, Inc" },
{ "E85484", "NEO Information Systems Co., Ltd." },
{ "206432", "SAMSUNG ELECTRO MECHANICS CO.,LTD." },
{ "74AE76", "iNovo Broadband, Inc." },
{ "60B933", "Deutron Electronics Corp." },
{ "38EE9D", "Anedo Ltd." },
{ "80CEB1", "Theissen Training Systems GmbH" },
{ "3C3888", "ConnectQuest, llc" },
{ "08BE09", "Astrol Electronic AG" },
{ "D8B8F6", "Nantworks" },
{ "6044F5", "Easy Digital Ltd." },
{ "AC51EE", "Cambridge Communication Systems Ltd" },
{ "00AA70", "LG Electronics" },
{ "10E4AF", "APR, LLC" },
{ "E03005", "Alcatel-Lucent Shanghai Bell Co., Ltd" },
{ "B0BD6D", "Echostreams Innovative Solutions" },
{ "F0D14F", "LINEAR LLC" },
{ "AC3D75", "HANGZHOU ZHIWAY TECHNOLOGIES CO.,LTD." },
{ "C01885", "Hon Hai Precision Ind. Co.,Ltd." },
{ "141A51", "Treetech Sistemas Digitais" },
{ "845787", "DVR C&C Co., Ltd." },
{ "F436E1", "Abilis Systems SARL" },
{ "587FC8", "S2M" },
{ "C49805", "Minieum Networks, Inc" },
{ "90F4C1", "Rand McNally" },
{ "18193F", "Tamtron Oy" },
{ "F8F7FF", "SYN-TECH SYSTEMS INC" },
{ "F473CA", "Conversion Sound Inc." },
{ "00E8AB", "Meggitt Training Systems, Inc." },
{ "18421D", "Private" },
{ "78617C", "MITSUMI ELECTRIC CO.,LTD " },
{ "C401B1", "SeekTech INC" },
{ "1C5FFF", "Beijing Ereneben Information Technology Co.,Ltd Shenzhen Branch" },
{ "C0C946", "MITSUYA LABORATORIES INC." },
{ "ACC2EC", "CLT INT'L IND. CORP." },
{ "702F4B", "PolyVision Inc." },
{ "741489", "SRT Wireless" },
{ "94CA0F", "Honeywell Analytics" },
{ "848D84", "Rajant Corporation" },
{ "D8337F", "Office FA.com Co.,Ltd." },
{ "7CEF8A", "Inhon International Ltd." },
{ "84AF1F", "Beat System Service Co,. Ltd." },
{ "100D2F", "Online Security Pty. Ltd." },
{ "408B07", "Actiontec Electronics, Inc" },
{ "980284", "Theobroma Systems GmbH" },
{ "E03C5B", "SHENZHEN JIAXINJIE ELECTRON CO.,LTD" },
{ "645563", "Intelight Inc." },
{ "C467B5", "Libratone A/S" },
{ "A4EF52", "Telewave Co., Ltd." },
{ "F4044C", "ValenceTech Limited" },
{ "1CBBA8", "OJSC Ufimskiy Zavod Promsvyaz" },
{ "506028", "Xirrus Inc." },
{ "24B657", "Cisco Systems, Inc" },
{ "940B2D", "NetView Technologies(Shenzhen) Co., Ltd" },
{ "306E5C", "Validus Technologies" },
{ "E843B6", "QNAP Systems, Inc." },
{ "5CC9D3", "PALLADIUM ENERGY ELETRONICA DA AMAZONIA LTDA" },
{ "407B1B", "Mettle Networks Inc." },
{ "64E161", "DEP Corp." },
{ "C8A620", "Nebula, Inc" },
{ "989080", "Linkpower Network System Inc Ltd." },
{ "0064A6", "Maquet CardioVascular" },
{ "3C4E47", "Etronic A/S" },
{ "C8F9F9", "Cisco Systems, Inc" },
{ "F0F755", "Cisco Systems, Inc" },
{ "10F96F", "LG Electronics" },
{ "B01C91", "Elim Co" },
{ "0CA2F4", "Chameleon Technology (UK) Limited" },
{ "846AED", "Wireless Tsukamoto.,co.LTD" },
{ "D8E952", "KEOPSYS" },
{ "3CB9A6", "Belden Deutschland GmbH" },
{ "3440B5", "IBM" },
{ "90D74F", "Bookeen" },
{ "905682", "Lenbrook Industries Limited" },
{ "CC6DEF", "TJK Tietolaite Oy" },
{ "3CE624", "LG Display " },
{ "D8F0F2", "Zeebo Inc" },
{ "B0CF4D", "MI-Zone Technology Ireland" },
{ "BCB1F3", "Samsung Electronics" },
{ "143605", "Nokia Corporation" },
{ "B87424", "Viessmann Elektronik GmbH" },
{ "C81AFE", "DLOGIC GmbH" },
{ "9C53CD", "ENGICAM s.r.l." },
{ "DCC101", "SOLiD Technologies, Inc." },
{ "AC6FBB", "TATUNG Technology Inc." },
{ "1803FA", "IBT Interfaces" },
{ "608645", "Avery Weigh-Tronix, LLC" },
{ "541DFB", "Freestyle Energy Ltd" },
{ "9CF67D", "Ricardo Prague, s.r.o." },
{ "A0E201", "AVTrace Ltd.(China)" },
{ "38ECE4", "Samsung Electronics" },
{ "04EE91", "x-fabric GmbH" },
{ "183825", "Wuhan Lingjiu High-tech Co.,Ltd." },
{ "5404A6", "ASUSTek COMPUTER INC." },
{ "F83376", "Good Mind Innovation Co., Ltd." },
{ "C46044", "Everex Electronics Limited" },
{ "645422", "Equinox Payments" },
{ "D412BB", "Quadrant Components Inc. Ltd" },
{ "40E793", "Shenzhen Siviton Technology Co.,Ltd" },
{ "2C67FB", "ShenZhen Zhengjili Electronics Co., LTD" },
{ "D89760", "C2 Development, Inc." },
{ "1CB17F", "NEC Platforms, Ltd." },
{ "942E17", "Schneider Electric Canada Inc" },
{ "B89674", "AllDSP GmbH & Co. KG" },
{ "6CA682", "EDAM information & communications" },
{ "48A22D", "Shenzhen Huaxuchang Telecom Technology Co.,Ltd" },
{ "50ED94", "EGATEL SL" },
{ "B87447", "Convergence Technologies" },
{ "70A66A", "Prox Dynamics AS" },
{ "DC175A", "Hitachi High-Technologies Corporation" },
{ "9034FC", "Hon Hai Precision Ind. Co.,Ltd." },
{ "5C076F", "Thought Creator" },
{ "3C0FC1", "KBC Networks" },
{ "58E636", "EVRsafe Technologies" },
{ "90D11B", "Palomar Medical Technologies" },
{ "CC60BB", "Empower RF Systems" },
{ "24497B", "Innovative Converged Devices Inc" },
{ "ECBD09", "FUSION Electronics Ltd" },
{ "54847B", "Digital Devices GmbH" },
{ "705CAD", "Konami Gaming Inc" },
{ "788973", "CMC" },
{ "DCCE41", "FE GLOBAL HONG KONG LIMITED" },
{ "4C774F", "Embedded Wireless Labs " },
{ "203706", "Cisco Systems, Inc" },
{ "7C4C58", "Scale Computing, Inc." },
{ "FCC23D", "Atmel Corporation" },
{ "7C1E52", "Microsoft" },
{ "DCB4C4", "Microsoft XCG" },
{ "74FDA0", "Compupal (Group) Corporation " },
{ "C029F3", "XySystem" },
{ "48F317", "Private" },
{ "B07D62", "Dipl.-Ing. H. Horstmann GmbH" },
{ "68974B", "Shenzhen Costar Electronics Co. Ltd." },
{ "B8BB6D", "ENERES Co.,Ltd." },
{ "645DD7", "Shenzhen Lifesense Medical Electronics Co., Ltd.    " },
{ "D45AB2", "Galleon Systems" },
{ "C40142", "MaxMedia Technology Limited" },
{ "A06E50", "Nanotek Elektronik Sistemler Ltd. Sti." },
{ "182C91", "Concept Development, Inc." },
{ "EC4670", "Meinberg Funkuhren GmbH & Co. KG" },
{ "B40B7A", "Brusa Elektronik AG" },
{ "BC764E", "Rackspace US, Inc." },
{ "C4EEAE", "VSS Monitoring" },
{ "2437EF", "EMC Electronic Media Communication SA" },
{ "CCF9E8", "Samsung Electronics Co.,Ltd" },
{ "D4F63F", "IEA S.R.L." },
{ "4C0289", "LEX COMPUTECH CO., LTD" },
{ "C0E54E", "DENX Computer Systems GmbH" },
{ "E435FB", "Sabre Technology (Hull) Ltd" },
{ "146308", "JABIL CIRCUIT (SHANGHAI) LTD." },
{ "28BE9B", "Technicolor USA Inc." },
{ "F01C13", "LG Electronics" },
{ "00CD90", "MAS Elektronik AG" },
{ "A8BD1A", "Honey Bee (Hong Kong) Limited" },
{ "ACCC8E", "Axis Communications AB" },
{ "187C81", "Valeo Vision Systems" },
{ "DC1EA3", "Accensus LLC" },
{ "A40130", "ABIsystems Co., LTD" },
{ "68F125", "Data Controls Inc." },
{ "706F81", "Private" },
{ "30E4DB", "Cisco Systems, Inc" },
{ "742B0F", "Infinidat Ltd." },
{ "280CB8", "Mikrosay Yazilim ve Elektronik A.S." },
{ "A06CEC", "RIM" },
{ "443EB2", "DEOTRON Co., LTD." },
{ "8CB82C", "IPitomy Communications" },
{ "807DE3", "Chongqing Sichuan Instrument Microcircuit Co.LTD." },
{ "1C8E8E", "DB Communication & Systems Co., ltd." },
{ "F0022B", "Chrontel" },
{ "007F28", "Actiontec Electronics, Inc" },
{ "0C924E", "Rice Lake Weighing Systems" },
{ "40040C", "A&T" },
{ "A0165C", "Triteka LTD" },
{ "90B97D", "Johnson Outdoors Marine Electronics d/b/a Minnkota" },
{ "8821E3", "Nebusens, S.L." },
{ "B0F1BC", "Dhemax Ingenieros Ltda" },
{ "3C096D", "Powerhouse Dynamics" },
{ "CC501C", "KVH Industries, Inc." },
{ "AC6FD9", "Valueplus Inc." },
{ "A4E391", "DENY FONTAINE" },
{ "04A82A", "Nokia Corporation" },
{ "48D8FE", "ClarIDy Solutions, Inc." },
{ "70B265", "Hiltron s.r.l." },
{ "84D9C8", "Unipattern Co.," },
{ "1C955D", "I-LAX ELECTRONICS INC." },
{ "94AAB8", "Joview(Beijing) Technology Co. Ltd." },
{ "18B3BA", "Netlogic AB" },
{ "F43E9D", "Benu Networks, Inc." },
{ "6469BC", "Hytera Communications Co .,ltd" },
{ "64094C", "Beijing Superbee Wireless Technology Co.,Ltd" },
{ "F0AE51", "Xi3 Corp" },
{ "782EEF", "Nokia Corporation" },
{ "78510C", "LiveU Ltd." },
{ "306118", "Paradom Inc." },
{ "C84529", "IMK Networks Co.,Ltd" },
{ "A88CEE", "MicroMade Galka i Drozdz sp.j." },
{ "204005", "feno GmbH" },
{ "CC52AF", "Universal Global Scientific Industrial Co., Ltd." },
{ "6C81FE", "Mitsuba Corporation" },
{ "E8F928", "RFTECH SRL" },
{ "703AD8", "Shenzhen Afoundry Electronic Co., Ltd" },
{ "4C98EF", "Zeo" },
{ "DCA6BD", "Beijing Lanbo Technology Co., Ltd." },
{ "D0667B", "Samsung Electronics Co., LTD" },
{ "58E808", "AUTONICS CORPORATION" },
{ "B8C716", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "8058C5", "NovaTec Kommunikationstechnik GmbH" },
{ "C0EAE4", "Sonicwall" },
{ "F8A9DE", "PUISSANCE PLUS" },
{ "D4F027", "Navetas Energy Management" },
{ "5C0CBB", "CELIZION Inc." },
{ "B8871E", "Good Mind Industries Co., Ltd." },
{ "F8EA0A", "Dipl.-Math. Michael Rauch" },
{ "BC5FF4", "ASRock Incorporation" },
{ "A4B36A", "JSC SDO Chromatec" },
{ "905F8D", "modas GmbH" },
{ "E0C922", "Jireh Energy Tech., Ltd." },
{ "28401A", "C8 MediSensors, Inc." },
{ "DC3C84", "Ticom Geomatics, Inc." },
{ "E8CC32", "Micronet  LTD" },
{ "9C6ABE", "QEES ApS." },
{ "3429EA", "MCD ELECTRONICS SP. Z O.O." },
{ "D43AE9", "DONGGUAN ipt INDUSTRIAL CO., LTD" },
{ "ACC935", "Ness Corporation" },
{ "7C4A82", "Portsmith LLC" },
{ "2C0033", "EControls, LLC" },
{ "E0F211", "Digitalwatt" },
{ "0432F4", "Partron" },
{ "AC199F", "SUNGROW POWER SUPPLY CO.,LTD." },
{ "1CAA07", "Cisco Systems, Inc" },
{ "308CFB", "Dropcam" },
{ "CCF841", "Lumewave" },
{ "701404", "Limited Liability Company" },
{ "1C35F1", "NEW Lift Neue Elektronische Wege Steuerungsbau GmbH" },
{ "CCD9E9", "SCR Engineers Ltd." },
{ "F0DB30", "Yottabyte" },
{ "9C31B6", "Kulite Semiconductor Products Inc" },
{ "5C6A7D", "KENTKART EGE ELEKTRONIK SAN. VE TIC. LTD. STI. " },
{ "04FF51", "NOVAMEDIA INNOVISION SP. Z O.O." },
{ "FCD4F2", "The Coca Cola Company" },
{ "C471FE", "Cisco Systems, Inc" },
{ "340804", "D-Link Corporation" },
{ "B44CC2", "NR ELECTRIC CO., LTD" },
{ "084EBF", "Broad Net Mux Corporation" },
{ "18ABF5", "Ultra Electronics - Electrics" },
{ "48CB6E", "Cello Electronics (UK) Ltd" },
{ "EC3BF0", "NovelSat" },
{ "A86A6F", "RIM" },
{ "4022ED", "Digital Projection Ltd" },
{ "0CA402", "Alcatel Lucent IPD" },
{ "0817F4", "IBM Corp" },
{ "C4D489", "JiangSu Joyque Information Industry Co.,Ltd" },
{ "1C7C11", "EID " },
{ "F43E61", "Shenzhen Gongjin Electronics Co., Ltd" },
{ "B0B32B", "Slican Sp. z o.o." },
{ "5842E4", "Baxter International Inc" },
{ "8CA048", "Beijing NeTopChip Technology Co.,LTD" },
{ "804F58", "ThinkEco, Inc." },
{ "B06563", "Shanghai Railway Communication Factory" },
{ "349A0D", "ZBD Displays Ltd" },
{ "A0B5DA", "HongKong THTF Co., Ltd" },
{ "CCCD64", "SM-Electronic GmbH" },
{ "E82877", "TMY Co., Ltd." },
{ "AC8112", "Gemtek Technology Co., Ltd." },
{ "6CA906", "Telefield Ltd" },
{ "3C02B1", "Creation Technologies LP" },
{ "E46C21", "messMa GmbH" },
{ "0470BC", "Globalstar Inc." },
{ "E05FB9", "Cisco Systems, Inc" },
{ "081735", "Cisco Systems, Inc" },
{ "20FECD", "System In Frontier Inc." },
{ "94D019", "Cydle Corp." },
{ "9C220E", "TASCAN Service GmbH" },
{ "2CA157", "acromate, Inc." },
{ "70DDA1", "Tellabs" },
{ "30EB25", "INTEK DIGITAL" },
{ "BC3E13", "Accordance Systems Inc." },
{ "0455CA", "BriView (Xiamen) Corp." },
{ "D45D42", "Nokia Corporation" },
{ "BC2846", "NextBIT Computing Pvt. Ltd." },
{ "4425BB", "Bamboo Entertainment Corporation" },
{ "B8A8AF", "Logic S.p.A." },
{ "648125", "Alphatron Marine BV" },
{ "042605", "GFR Gesellschaft für Regelungstechnik und Energieeinsparung mbH" },
{ "9C645E", "Harman Consumer Group" },
{ "78CD8E", "SMC Networks Inc" },
{ "5C9AD8", "FUJITSU LIMITED" },
{ "144C1A", "Max Communication GmbH" },
{ "FCE557", "Nokia Corporation" },
{ "BC6E76", "Green Energy Options Ltd" },
{ "108CCF", "Cisco Systems, Inc" },
{ "74E06E", "Ergophone GmbH" },
{ "18AF9F", "DIGITRONIC Automationsanlagen GmbH" },
{ "EC4644", "TTK SAS" },
{ "DCD87F", "Shenzhen JoinCyber Telecom Equipment Ltd" },
{ "B08991", "LGE " },
{ "44DCCB", "SEMINDIA SYSTEMS PVT LTD" },
{ "90D92C", "HUG-WITSCHI AG" },
{ "B428F1", "E-Prime Co., Ltd." },
{ "B4749F", "ASKEY COMPUTER CORP" },
{ "AC2FA8", "Humannix Co.,Ltd." },
{ "7C4AA8", "MindTree Wireless PVT Ltd" },
{ "C8A70A", "Verizon Business" },
{ "304EC3", "Tianjin Techua Technology Co., Ltd." },
{ "BC4377", "Hang Zhou Huite Technology Co.,ltd." },
{ "A81B18", "XTS CORP" },
{ "04E2F8", "AEP Ticketing solutions srl" },
{ "8C5105", "Shenzhen ireadygo Information Technology CO.,LTD." },
{ "28E297", "Shanghai InfoTM Microelectronics Co.,Ltd." },
{ "D093F8", "Stonestreet One LLC" },
{ "1C334D", "ITS Telecom" },
{ "609E64", "Vivonic GmbH" },
{ "906EBB", "Hon Hai Precision Ind. Co.,Ltd." },
{ "D44F80", "Kemper Digital GmbH" },
{ "34684A", "Teraworks Co., Ltd." },
{ "0CC6AC", "DAGS" },
{ "D82A7E", "Nokia Corporation" },
{ "5CBD9E", "HONGKONG MIRACLE EAGLE TECHNOLOGY(GROUP) LIMITED" },
{ "743889", "ANNAX Anzeigesysteme GmbH" },
{ "E89A8F", "Quanta Computer Inc." },
{ "647FDA", "TEKTELIC Communications Inc." },
{ "90610C", "Fida International (S) Pte Ltd" },
{ "3C5F01", "Synerchip Co., Ltd." },
{ "708B78", "citygrow technology co., ltd" },
{ "74CD0C", "Smith Myers Communications Ltd." },
{ "B8EE79", "YWire Technologies, Inc." },
{ "40C245", "Shenzhen Hexicom Technology Co., Ltd." },
{ "7076F0", "LevelOne Communications (India) Private Limited" },
{ "48C8B6", "SysTec GmbH" },
{ "303855", "Nokia Corporation" },
{ "9C4563", "DIMEP Sistemas" },
{ "E42771", "Smartlabs" },
{ "C4EEF5", "Oclaro, Inc." },
{ "0876FF", "Thomson Telecom Belgium" },
{ "401D59", "Biometric Associates, LP" },
{ "4C2C80", "Beijing Skyway Technologies Co.,Ltd " },
{ "08D29A", "Proformatique" },
{ "90D852", "Comtec Co., Ltd." },
{ "28061E", "NINGBO GLOBAL USEFUL ELECTRIC CO.,LTD" },
{ "4037AD", "Macro Image Technology, Inc." },
{ "64E8E6", "global moisture management system" },
{ "34A183", "AWare, Inc" },
{ "740ABC", "JSJS Designs (Europe) Limited" },
{ "E8E0B7", "Toshiba" },
{ "588D09", "Cisco Systems, Inc" },
{ "342109", "Jensen Scandinavia AS" },
{ "08FAE0", "Fohhn Audio AG" },
{ "B439D6", "ProCurve Networking by HP" },
{ "506F9A", "Wi-Fi Alliance" },
{ "7CF098", "Bee Beans Technologies, Inc." },
{ "9C7514", "Wildix srl" },
{ "BC7DD1", "Radio Data Comms" },
{ "28068D", "ITL, LLC" },
{ "F0D767", "Axema Passagekontroll AB" },
{ "A4AE9A", "Maestro Wireless Solutions ltd." },
{ "5CD135", "Xtreme Power Systems" },
{ "9C28BF", "Continental Automotive Czech Republic s.r.o." },
{ "206FEC", "Braemac CA LLC" },
{ "64A232", "OOO Samlight" },
{ "A082C7", "P.T.I Co.,LTD" },
{ "F41F0B", "YAMABISHI Corporation" },
{ "447C7F", "Innolight Technology Corporation" },
{ "FC75E6", "Handreamnet" },
{ "20B0F7", "Enclustra GmbH" },
{ "8C90D3", "Alcatel Lucent" },
{ "4013D9", "Global ES" },
{ "F4DC4D", "Beijing CCD Digital Technology Co., Ltd" },
{ "F8B599", "Guangzhou CHNAVS Digital Technology Co.,Ltd" },
{ "7C3920", "SSOMA SECURITY" },
{ "9C77AA", "NADASNV" },
{ "D8B6C1", "NetworkAccountant, Inc." },
{ "58D08F", "IEEE 1904.1 Working Group" },
{ "3C99F7", "Lansentechnology AB" },
{ "94E711", "Xirka Dama Persada PT" },
{ "507D02", "BIODIT" },
{ "F44227", "S & S Research Inc." },
{ "D4CBAF", "Nokia Corporation" },
{ "CC09C8", "IMAQLIQ LTD" },
{ "C4B512", "General Electric Digital Energy" },
{ "E02538", "Titan Pet Products" },
{ "CC7A30", "CMAX Wireless Co., Ltd." },
{ "D8760A", "Escort, Inc." },
{ "101DC0", "Samsung Electronics Co.,Ltd" },
{ "F49F54", "Samsung Electronics" },
{ "6063FD", "Transcend Communication Beijing Co.,Ltd." },
{ "E08A7E", "Exponent" },
{ "80C6CA", "Endian s.r.l." },
{ "F8DAE2", "Beta LaserMike" },
{ "E80462", "Cisco Systems, Inc" },
{ "70B08C", "Shenou Communication Equipment Co.,Ltd" },
{ "F0E5C3", "Drägerwerk AG & Co. KG aA" },
{ "446132", "ecobee inc" },
{ "A4B2A7", "Adaxys Solutions AG" },
{ "F455E0", "Niceway CNC Technology Co.,Ltd.Hunan Province" },
{ "AC4FFC", "SVS-VISTEK GmbH" },
{ "FC7CE7", "FCI USA LLC" },
{ "145412", "Entis Co., Ltd." },
{ "807D1B", "Neosystem Co. Ltd." },
{ "14FEAF", "SAGITTAR LIMITED" },
{ "7CB542", "ACES Technology" },
{ "40CD3A", "Z3 Technology" },
{ "045D56", "camtron industrial inc." },
{ "AC83F0", "ImmediaTV Corporation" },
{ "6CE0B0", "SOUND4" },
{ "00336C", "SynapSense Corporation" },
{ "E446BD", "C&C TECHNIC TAIWAN CO., LTD." },
{ "7415E2", "Tri-Sen Systems Corporation" },
{ "F0BDF1", "Sipod Inc." },
{ "288915", "CashGuard Sverige AB" },
{ "180675", "DILAX Intelcom GmbH" },
{ "40618E", "Stella-Green Co" },
{ "9C4E20", "Cisco Systems, Inc" },
{ "408493", "Clavister AB" },
{ "1C3A4F", "AccuSpec Electronics, LLC" },
{ "58E747", "Deltanet AG" },
{ "D87533", "Nokia Corporation" },
{ "ECFE7E", "BlueRadios, Inc." },
{ "7C6F06", "Caterpillar Trimble Control Technologies" },
{ "7C7673", "ENMAS GmbH" },
{ "6C6F18", "Stereotaxis, Inc." },
{ "003532", "Electro-Metrics Corporation" },
{ "44376F", "Young Electric Sign Co" },
{ "8C640B", "Beyond Devices d.o.o." },
{ "F04335", "DVN(Shanghai)Ltd." },
{ "A479E4", "KLINFO Corp" },
{ "FCFAF7", "Shanghai Baud Data Communication Co.,Ltd." },
{ "003CC5", "WONWOO Engineering Co., Ltd" },
{ "E85E53", "Infratec Datentechnik GmbH" },
{ "C848F5", "MEDISON Xray Co., Ltd" },
{ "1C17D3", "Cisco Systems, Inc" },
{ "E8E5D6", "Samsung Electronics Co.,Ltd" },
{ "ACBE75", "Ufine Technologies Co.,Ltd." },
{ "D87157", "Lenovo Mobile Communication Technology Ltd." },
{ "806629", "Prescope Technologies CO.,LTD." },
{ "90F278", "Radius Gateway" },
{ "68CA00", "Octopus Systems Limited" },
{ "4C3089", "Thales Transportation Systems GmbH" },
{ "0C7D7C", "Kexiang Information Technology Co, Ltd." },
{ "70D880", "Upos System sp. z o.o." },
{ "0CC9C6", "Samwin Hong Kong Limited" },
{ "B45861", "CRemote, LLC" },
{ "AC6706", "Ruckus Wireless" },
{ "B8653B", "Bolymin, Inc." },
{ "B0973A", "E-Fuel Corporation" },
{ "A05DC1", "TMCT Co., LTD." },
{ "E0CA4D", "Shenzhen Unistar Communication Co.,LTD" },
{ "E497F0", "Shanghai VLC Technologies Ltd. Co." },
{ "44A42D", "TCT Mobile Limited" },
{ "204E6B", "Axxana(israel) ltd" },
{ "50F003", "Open Stack, Inc." },
{ "0C17F1", "TELECSYS" },
{ "5492BE", "Samsung Electronics Co.,Ltd" },
{ "98BC99", "Edeltech Co.,Ltd." },
{ "E8E1E2", "Energotest" },
{ "FC683E", "Directed Perception, Inc" },
{ "6C1811", "Decatur Electronics" },
{ "94592D", "EKE Building Technology Systems Ltd" },
{ "9CC077", "PrintCounts, LLC" },
{ "A85BB0", "Shenzhen Dehoo Technology Co.,Ltd" },
{ "089F97", "LEROY AUTOMATION" },
{ "4C5DCD", "Oy Finnish Electric Vehicle Technologies Ltd" },
{ "10090C", "Janome Sewing Machine Co., Ltd." },
{ "ECB106", "Acuro Networks, Inc" },
{ "7C2E0D", "Blackmagic Design" },
{ "08F6F8", "GET Engineering" },
{ "6CDC6A", "Promethean Limited" },
{ "9055AE", "Ericsson, EAB/RWI/K" },
{ "2C3A28", "Fagor Electrónica" },
{ "90A7C1", "Pakedge Device and Software Inc." },
{ "80F593", "IRCO Sistemas de Telecomunicación S.A." },
{ "6CFDB9", "Proware Technologies Co Ltd." },
{ "6CFFBE", "MPB Communications Inc." },
{ "583CC6", "Omneality Ltd." },
{ "0097FF", "Heimann Sensor GmbH" },
{ "34BA51", "Se-Kure Controls, Inc." },
{ "44A8C2", "SEWOO TECH CO., LTD" },
{ "8CD628", "Ikor Metering" },
{ "481BD2", "Intron Scientific co., ltd." },
{ "444E1A", "Samsung Electronics Co.,Ltd" },
{ "009363", "Uni-Link Technology Co., Ltd." },
{ "64DB18", "OpenPattern" },
{ "580556", "Elettronica GF S.r.L." },
{ "88B627", "Gembird Europe BV" },
{ "D41F0C", "JAI Oy" },
{ "3C4C69", "Infinity System S.L." },
{ "44E49A", "OMNITRONICS PTY LTD" },
{ "74F07D", "BnCOM Co.,Ltd" },
{ "1065A3", "Core Brands LLC" },
{ "20415A", "Smarteh d.o.o." },
{ "703C39", "SEAWING Kft" },
{ "14A86B", "ShenZhen Telacom Science&Technology Co., Ltd" },
{ "0CC3A7", "Meritec" },
{ "4C322D", "TELEDATA NETWORKS" },
{ "B8B1C7", "BT&COM CO.,LTD" },
{ "A0BFA5", "CORESYS" },
{ "D411D6", "ShotSpotter, Inc." },
{ "7CCB0D", "Antaira Technologies, LLC" },
{ "ECE9F8", "Guang Zhou TRI-SUN Electronics Technology  Co., Ltd" },
{ "E89D87", "Toshiba" },
{ "9CAFCA", "Cisco Systems, Inc" },
{ "784476", "Zioncom technology co.,ltd" },
{ "34CE94", "Parsec (Pty) Ltd" },
{ "ACE9AA", "Hay Systems Ltd" },
{ "082AD0", "SRD Innovations Inc." },
{ "24828A", "Prowave Technologies Ltd." },
{ "6C0F6A", "JDC Tech Co., Ltd." },
{ "6CF049", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "D4C766", "Acentic GmbH" },
{ "48EB30", "ETERNA TECHNOLOGY, INC." },
{ "207C8F", "Quanta Microsystems,Inc." },
{ "F8472D", "X2gen Digital Corp. Ltd" },
{ "8C598B", "C Technologies AB" },
{ "64F970", "Kenade Electronics Technology Co.,LTD." },
{ "A04025", "Actioncable, Inc." },
{ "78998F", "MEDILINE ITALIA SRL" },
{ "40ECF8", "Siemens AG" },
{ "F04BF2", "JTECH Communications, Inc." },
{ "A8CB95", "EAST BEST CO., LTD." },
{ "C8D1D1", "AGAiT Technology Corporation" },
{ "3CF52C", "DSPECIALISTS GmbH" },
{ "040EC2", "ViewSonic Mobile China Limited" },
{ "5403F5", "EBN Technology Corp." },
{ "7C2F80", "Gigaset Communications GmbH" },
{ "446C24", "Reallin Electronic Co.,Ltd" },
{ "A0593A", "V.D.S. Video Display Systems srl" },
{ "A8F94B", "Eltex Enterprise Ltd." },
{ "906DC8", "DLG Automação Industrial Ltda" },
{ "48343D", "IEP GmbH" },
{ "C8C13C", "RuggedTek Hangzhou Co., Ltd" },
{ "609F9D", "CloudSwitch" },
{ "0CE936", "ELIMOS srl" },
{ "A4DE50", "Total Walther GmbH" },
{ "E8A4C1", "Deep Sea Electronics PLC" },
{ "701AED", "ADVAS CO., LTD." },
{ "64C6AF", "AXERRA Networks Ltd" },
{ "D8D67E", "GSK CNC EQUIPMENT CO.,LTD" },
{ "A4E7E4", "Connex GmbH" },
{ "AC583B", "Human Assembler, Inc." },
{ "A05DE7", "DIRECTV, Inc." },
{ "10CA81", "PRECIA" },
{ "003A98", "Cisco Systems, Inc" },
{ "705AB6", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "003A9A", "Cisco Systems, Inc" },
{ "ACBEB6", "Visualedge Technology Co., Ltd." },
{ "40A6A4", "PassivSystems Ltd" },
{ "903D6B", "Zicon Technology Corp." },
{ "7C3BD5", "Imago Group" },
{ "B894D2", "Retail Innovation HTT AB" },
{ "DCE71C", "AUG Elektronik GmbH" },
{ "88A5BD", "QPCOM INC." },
{ "DC3350", "TechSAT GmbH" },
{ "00271E", "Xagyl Communications" },
{ "002722", "Ubiquiti Networks" },
{ "002716", "Adachi-Syokai Co., Ltd." },
{ "002715", "Rebound Telecom. Co., Ltd" },
{ "00270A", "IEE S.A." },
{ "002674", "Electronic Solutions, Inc." },
{ "00266E", "Nissho-denki Co.,LTD." },
{ "00265B", "Hitron Technologies. Inc" },
{ "002661", "Irumtek Co., Ltd." },
{ "002657", "OOO NPP EKRA" },
{ "00264E", "Rail & Road Protec GmbH" },
{ "0025E6", "Belgian Monitoring Systems bvba" },
{ "0025E5", "LG Electronics Inc" },
{ "0025E1", "SHANGHAI SEEYOO ELECTRONIC & TECHNOLOGY CO., LTD" },
{ "0025DB", "ATI Electronics(Shenzhen) Co., LTD" },
{ "0025D5", "Robonica (Pty) Ltd" },
{ "0025C9", "SHENZHEN HUAPU DIGITAL CO., LTD" },
{ "0025CE", "InnerSpace" },
{ "0025C2", "RingBell Co.,Ltd." },
{ "0026A0", "moblic" },
{ "00269A", "Carina System Co., Ltd." },
{ "002694", "Senscient Ltd" },
{ "002693", "QVidium Technologies, Inc." },
{ "00268D", "CellTel S.p.A." },
{ "00268E", "Alta Solutions, Inc." },
{ "002687", "corega K.K" },
{ "002681", "Interspiro AB" },
{ "00267B", "GSI Helmholtzzentrum für Schwerionenforschung GmbH" },
{ "0025BB", "INNERINT Co., Ltd." },
{ "0025B6", "Telecom FM" },
{ "0025AF", "COMFILE Technology" },
{ "0025AA", "Beijing Soul Technology Co.,Ltd." },
{ "0025A9", "Shanghai Embedway Information Technologies Co.,Ltd" },
{ "0025A3", "Trimax Wireless, Inc." },
{ "00259C", "Cisco-Linksys, LLC" },
{ "002597", "Kalki Communication Technologies" },
{ "002590", "Super Micro Computer, Inc." },
{ "002580", "Equipson S.A." },
{ "00257C", "Huachentel Technology Development Co., Ltd" },
{ "002575", "FiberPlex Technologies, LLC" },
{ "002576", "NELI TECHNOLOGIES" },
{ "002570", "Eastern Communications Company Limited" },
{ "002563", "Luxtera Inc" },
{ "002704", "Accelerated Concepts, Inc" },
{ "0026FE", "MKD Technology Inc." },
{ "0026F8", "Golden Highway Industry Development Co., Ltd." },
{ "0026F1", "ProCurve Networking by HP" },
{ "0026EB", "Advanced Spectrum Technology Co., Ltd." },
{ "0026E5", "AEG Power Solutions" },
{ "0026DF", "TaiDoc Technology Corp." },
{ "0026D8", "Magic Point Inc." },
{ "0026D2", "Pcube Systems, Inc." },
{ "0026C5", "Guangdong Gosun Telecommunications Co.,Ltd" },
{ "0026C0", "EnergyHub" },
{ "0026BF", "ShenZhen Temobi Science&Tech Development Co.,Ltd" },
{ "0026B7", "Kingston Technology Company, Inc." },
{ "0026A6", "TRIXELL" },
{ "00263C", "Bachmann Technology GmbH & Co. KG" },
{ "002637", "Samsung Electro-Mechanics" },
{ "002630", "ACOREL S.A.S" },
{ "002629", "Juphoon System Software Inc." },
{ "00262A", "Proxense, LLC" },
{ "002624", "Thomson Inc." },
{ "00261D", "COP SECURITY SYSTEM CORP." },
{ "002611", "Licera AB" },
{ "002617", "OEM Worldwide" },
{ "00260A", "Cisco Systems, Inc" },
{ "0025FE", "Pilot Electronics Corporation" },
{ "002605", "CC Systems AB" },
{ "002604", "Audio Processing Technology Ltd" },
{ "0025F4", "KoCo Connector AG" },
{ "0025EB", "Reutech Radar Systems (PTY) Ltd" },
{ "00242A", "Hittite Microwave Corporation" },
{ "00241D", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "002424", "Axis Network Technology" },
{ "002417", "Thomson Telecom Belgium" },
{ "002418", "Nextwave Semiconductor" },
{ "002411", "PharmaSmart LLC" },
{ "00240B", "Virtual Computer Inc." },
{ "00240A", "US Beverage Net" },
{ "0024B8", "free alliance sdn bhd" },
{ "0024BD", "Hainzl Industriesysteme GmbH" },
{ "0024B3", "Graf-Syteco GmbH & Co. KG" },
{ "0024AE", "Morpho" },
{ "0024A7", "Advanced Video Communications Inc." },
{ "0024AC", "Hangzhou DPtech Technologies Co., Ltd." },
{ "00255D", "Morningstar Corporation" },
{ "002551", "SE-Elektronic GmbH" },
{ "00254A", "RingCube Technologies, Inc." },
{ "002543", "MONEYTECH" },
{ "002544", "LoJack Corporation" },
{ "002539", "IfTA GmbH" },
{ "00253B", "din Dietmar Nocker Facilitymanagement GmbH" },
{ "00250B", "CENTROFACTOR  INC" },
{ "002504", "Valiant Communications Limited" },
{ "0024FF", "QLogic Corporation" },
{ "0024FD", "Accedian Networks Inc" },
{ "0024F8", "Technical Solutions Company Ltd." },
{ "0024F1", "Shenzhen Fanhai Sanjiang Electronics Co., Ltd." },
{ "0024EC", "United Information Technology Co.,Ltd." },
{ "00249B", "Action Star Enterprise Co., Ltd." },
{ "002499", "Aquila Technologies" },
{ "002488", "Centre For Development Of Telematics" },
{ "002494", "Shenzhen Baoxin Tech CO., Ltd." },
{ "00247A", "FU YI CHENG Technology Co., Ltd." },
{ "002475", "Compass System(Embedded Dept.)" },
{ "00246E", "Phihong USA Corp." },
{ "002467", "AOC International (Europe) GmbH" },
{ "002469", "Smart Doorphones" },
{ "002462", "Rayzone Corporation" },
{ "002458", "PA Bastion CC" },
{ "00245D", "Terberg besturingstechniek B.V." },
{ "002455", "MuLogic BV" },
{ "002450", "Cisco Systems, Inc" },
{ "00244B", "PERCEPTRON INC" },
{ "00253A", "CEVA, Ltd." },
{ "002531", "Cloud Engines, Inc." },
{ "00252F", "Energy, Inc." },
{ "00252A", "Chengdu GeeYa Technology Co.,LTD" },
{ "002521", "Logitek Electronic Systems, Inc." },
{ "00251C", "EDT" },
{ "002517", "Venntis, LLC" },
{ "002510", "Pico-Tesla Magnetic Therapies" },
{ "0024E5", "Seer Technology, Inc" },
{ "0024E0", "DS Tech, LLC" },
{ "0024DE", "GLOBAL Technology Inc." },
{ "0024D9", "BICOM, Inc." },
{ "0024CB", "Autonet Mobile" },
{ "0024CD", "Willow Garage, Inc." },
{ "0024C6", "Hager Electro SAS" },
{ "00243A", "Ludl Electronic Products" },
{ "002434", "Lectrosonics, Inc." },
{ "00242E", "Datastrip Inc." },
{ "002296", "LinoWave Corporation" },
{ "00228F", "CNRS" },
{ "002290", "Cisco Systems, Inc" },
{ "00228A", "Teratronik elektronische systeme gmbh" },
{ "00227E", "Chengdu 30Kaitian Communication Industry Co.Ltd" },
{ "00227D", "YE DATA INC." },
{ "002278", "Shenzhen  Tongfang Multimedia  Technology Co.,Ltd." },
{ "002272", "American Micro-Fuel Device Corp." },
{ "002271", "Jäger Computergesteuerte Meßtechnik GmbH." },
{ "00226E", "Gowell Electronic Limited" },
{ "002358", "SYSTEL SA" },
{ "002357", "Pitronot Technologies and Engineering P.T.E. Ltd." },
{ "002352", "DATASENSOR S.p.A." },
{ "00234B", "Inyuan Technology Inc." },
{ "002346", "Vestac" },
{ "00233F", "Purechoice Inc" },
{ "002338", "OJ-Electronics A/S" },
{ "002333", "Cisco Systems, Inc" },
{ "00232F", "Advanced Card Systems Ltd." },
{ "00232A", "eonas IT-Beratung und -Entwicklung GmbH" },
{ "0022C1", "Active Storage Inc." },
{ "0022C2", "Proview Eletrônica do Brasil LTDA" },
{ "0022BC", "JDSU France SAS" },
{ "0022B5", "NOVITA" },
{ "0022A9", "LG Electronics Inc" },
{ "0022AF", "Safety Vision" },
{ "0022A2", "Xtramus Technologies" },
{ "00229D", "PYUNG-HWA IND.CO.,LTD" },
{ "002327", "Shouyo Electronics CO., LTD" },
{ "002323", "Zylin AS" },
{ "00231A", "ITF Co., Ltd." },
{ "002318", "Toshiba" },
{ "002311", "Gloscom Co., Ltd." },
{ "00230C", "CLOVER ELECTRONICS CO.,LTD." },
{ "002305", "Cisco Systems, Inc" },
{ "0022FF", "NIVIS LLC" },
{ "0022FE", "Advanced Illumination" },
{ "002300", "Cayee Computer Ltd." },
{ "0022F6", "Syracuse Research Corporation" },
{ "0022F9", "Pollin Electronic GmbH" },
{ "0023AD", "Xmark Corporation" },
{ "0023A7", "Redpine Signals, Inc." },
{ "0023A1", "Trend Electronics Ltd" },
{ "0023A6", "E-Mon" },
{ "00239A", "EasyData Hardware GmbH" },
{ "002394", "Samjeon" },
{ "002390", "Algolware Corporation" },
{ "002386", "Tour & Andersson AB" },
{ "002405", "Dilog Nordic AB" },
{ "0023F5", "WILO SE" },
{ "0023F8", "ZyXEL Communications Corporation" },
{ "0023FE", "Biodevices, SA" },
{ "0023F0", "Shanghai Jinghan Weighing Apparatus Co. Ltd." },
{ "0023EB", "Cisco Systems, Inc" },
{ "0023E5", "IPaXiom Networks" },
{ "0023E6", "Pirkus, Inc." },
{ "0023D9", "Banner Engineering" },
{ "0023D3", "AirLink WiFi Networking Corp." },
{ "0023D8", "Ball-It Oy" },
{ "0023C6", "SMC Corporation" },
{ "0023C0", "Broadway Networks" },
{ "0023B9", "EADS Deutschland GmbH" },
{ "0023B3", "Lyyn AB" },
{ "0022F5", "Advanced Realtime Tracking GmbH" },
{ "0022EF", "iWDL Technologies" },
{ "0022E8", "Applition Co., Ltd." },
{ "0022E3", "Amerigon" },
{ "0022D5", "Eaton Corp. Electrical Group Data Center Solutions - Pulizzi" },
{ "0022DC", "Vigil Health Solutions Inc." },
{ "0022D6", "Cypak AB" },
{ "0022D0", "Polar Electro Oy" },
{ "0022CB", "IONODES Inc." },
{ "0022C6", "Sutus Inc" },
{ "002380", "Nanoteq" },
{ "00237A", "RIM" },
{ "002377", "Isotek Electronics Ltd" },
{ "002371", "SOAM Systel" },
{ "002365", "ELKA-Elektronik GmbH" },
{ "00236A", "SmartRG Inc" },
{ "00235E", "Cisco Systems, Inc" },
{ "00225A", "Garde Security AB" },
{ "002254", "Bigelow Aerospace" },
{ "002251", "Lumasense Technologies" },
{ "00224B", "AIRTECH TECHNOLOGIES, INC." },
{ "002245", "Leine & Linde AB" },
{ "002242", "Alacron Inc." },
{ "00223B", "Communication Networks, LLC" },
{ "00214C", "SAMSUNG ELECTRONICS CO., LTD." },
{ "002146", "Sanmina-SCI" },
{ "00213D", "Cermetek Microelectronics, Inc." },
{ "00213E", "TomTom" },
{ "002135", "ALCATEL-LUCENT" },
{ "00213A", "Winchester Systems Inc." },
{ "002130", "Keico Hightech Inc." },
{ "00217E", "Telit Communication s.p.a" },
{ "002178", "Matuschek Messtechnik GmbH" },
{ "002172", "Seoultek Valley" },
{ "002166", "NovAtel Inc." },
{ "002165", "Presstek Inc." },
{ "00215F", "IHSE GmbH" },
{ "002153", "SeaMicro Inc." },
{ "002158", "Style Flying Technology Co." },
{ "0021AC", "Infrared Integrated Systems Ltd" },
{ "0021A5", "ERLPhase Power Technologies Ltd." },
{ "00219F", "SATEL OY" },
{ "00218A", "Electronic Design and Manufacturing Company" },
{ "00218B", "Wescon Technology, Inc." },
{ "002185", "MICRO-STAR INT'L CO.,LTD." },
{ "001FF9", "Advanced Knowledge Associates" },
{ "001FF2", "VIA Technologies, Inc." },
{ "001FED", "Tecan Systems Inc." },
{ "001FE6", "Alphion Corporation" },
{ "001FE0", "EdgeVelocity Corp" },
{ "001FDA", "Nortel Networks" },
{ "002209", "Omron Healthcare Co., Ltd" },
{ "002203", "Glensound Electronics Ltd" },
{ "002200", "IBM Corp" },
{ "0021F6", "Oracle Corporation" },
{ "0021F0", "EW3 Technologies LLC" },
{ "0021EA", "Bystronic Laser AG" },
{ "0021E3", "SerialTek LLC" },
{ "0021DE", "Firepro Wireless" },
{ "0021DD", "Northstar Systems Corp" },
{ "0021D7", "Cisco Systems, Inc" },
{ "002235", "Strukton Systems bv" },
{ "002234", "Corventis Inc." },
{ "00222F", "Open Grid Computing, Inc." },
{ "002228", "Breeze Innovations Ltd." },
{ "002222", "Schaffner Deutschland GmbH" },
{ "00221C", "Private" },
{ "00220F", "MoCA (Multimedia over Coax Alliance)" },
{ "00212B", "MSA Auer" },
{ "00211D", "Dataline AB" },
{ "002124", "Optos Plc" },
{ "002118", "Athena Tech, Inc." },
{ "002111", "Uniphone Inc." },
{ "002107", "Seowonintech Co Ltd." },
{ "002101", "Aplicaciones Electronicas Quasar (AEQ)" },
{ "002102", "UpdateLogic Inc." },
{ "0021D1", "Samsung Electronics Co.,Ltd" },
{ "0021D0", "Global Display Solutions Spa" },
{ "0021CB", "SMS TECNOLOGIA ELETRONICA LTDA" },
{ "0021C4", "Consilium AB" },
{ "0021B8", "Inphi Corporation" },
{ "0021B1", "DIGITAL SOLUTIONS LTD" },
{ "001F82", "Cal-Comp Electronics & Communications Co., Ltd" },
{ "001F7D", "embedded wireless GmbH" },
{ "001F7B", "TechNexion Ltd." },
{ "001F7C", "Witelcom AS" },
{ "001F79", "Lodam Electronics A/S" },
{ "001F74", "Eigen Development" },
{ "001F6F", "Fujian Sunnada Communication Co.,Ltd." },
{ "001F63", "JSC Goodwin-Europa" },
{ "001F6A", "PacketFlux Technologies, Inc." },
{ "001F69", "Pingood Technology Co., Ltd." },
{ "001F57", "Phonik Innovation Co.,LTD" },
{ "001F21", "Inner Mongolia Yin An Science & Technology Development Co.,L" },
{ "001F22", "Source Photonics, Inc." },
{ "001F1C", "KOBISHI ELECTRIC Co.,Ltd." },
{ "001F15", "Bioscrypt Inc" },
{ "001F10", "TOLEDO DO BRASIL INDUSTRIA DE BALANCAS  LTDA" },
{ "001F0C", "Intelligent Digital Services GmbH" },
{ "001F07", "AZTEQ Mobile" },
{ "001FAA", "Taseon, Inc." },
{ "001FA5", "Blue-White Industries" },
{ "001FA4", "ShenZhen Gongjin Electronics Co.,Ltd" },
{ "001FA0", "A10 Networks" },
{ "001F9A", "Nortel Networks" },
{ "001F99", "SERONICS co.ltd" },
{ "001F9B", "POSBRO" },
{ "001F94", "Lascar Electronics Ltd" },
{ "001F8D", "Ingenieurbuero Stark GmbH und Ko. KG" },
{ "001F89", "Signalion GmbH" },
{ "001ED0", "Ingespace" },
{ "001ECB", "RPC Energoautomatika Ltd" },
{ "001EC4", "Celio Corp" },
{ "001EBE", "Cisco Systems, Inc" },
{ "001EBD", "Cisco Systems, Inc" },
{ "001EB8", "Fortis, Inc." },
{ "001EB1", "Cryptsoft Pty Ltd" },
{ "001EA6", "Best IT World (India) Pvt. Ltd." },
{ "001EAC", "Armadeus Systems" },
{ "001E9F", "Visioneering Systems, Inc." },
{ "001EA0", "XLN-t" },
{ "001EF4", "L-3 Communications Display Systems" },
{ "001EF9", "Pascom Kommunikations systeme GmbH." },
{ "001EFA", "PROTEI Ltd." },
{ "001EE8", "Mytek" },
{ "001EED", "Adventiq Ltd." },
{ "001EE7", "Epic Systems Inc" },
{ "001EE1", "Samsung Electronics Co.,Ltd" },
{ "001ED7", "H-Stream Wireless, Inc." },
{ "001E6B", "Cisco SPVTG" },
{ "001E72", "PCS" },
{ "001E66", "RESOL Elektronische Regelungen GmbH" },
{ "001E5F", "KwikByte, LLC" },
{ "001E53", "Further Tech Co., LTD" },
{ "001E9A", "HAMILTON Bonaduz AG" },
{ "001E93", "CiriTech Systems Inc" },
{ "001E8E", "Hunkeler AG" },
{ "001E88", "ANDOR SYSTEM SUPPORT CO., LTD." },
{ "001E82", "SanDisk Corporation" },
{ "001E81", "CNB Technology Inc." },
{ "001E7C", "Taiwick Limited" },
{ "001E77", "Air2App" },
{ "001F50", "Swissdis AG" },
{ "001F49", "Manhattan TV Ltd" },
{ "001F4A", "Albentia Systems S.A." },
{ "001F44", "GE Transportation Systems" },
{ "001F2F", "Berker GmbH & Co. KG" },
{ "001F34", "Lung Hwa Electronics Co., Ltd." },
{ "001F28", "HPN Supply Chain" },
{ "001FD5", "MICRORISC s.r.o." },
{ "001FD6", "Shenzhen Allywll" },
{ "001FD0", "GIGA-BYTE TECHNOLOGY CO.,LTD." },
{ "001FC9", "Cisco Systems, Inc" },
{ "001FBD", "Kyocera Wireless Corp." },
{ "001FB1", "Cybertech Inc." },
{ "001FB6", "Chi Lin Technology Co., Ltd." },
{ "001D02", "Cybertech Telecom Development" },
{ "001CF6", "Cisco Systems, Inc" },
{ "001CEF", "Primax Electronics LTD" },
{ "001CEA", "Scientific-Atlanta, Inc" },
{ "001CE9", "Galaxy Technology Limited" },
{ "001CE5", "MBS Electronic Systems GmbH" },
{ "001CE0", "DASAN TPS" },
{ "001CD9", "GlobalTop Technology Inc." },
{ "001CD2", "King Champion (Hong Kong) Limited" },
{ "001CCD", "Alektrona Corporation" },
{ "001CC6", "ProStor Systems" },
{ "001CBA", "VerScient, Inc." },
{ "001CB0", "Cisco Systems, Inc" },
{ "001CB5", "Neihua Network Technology Co.,LTD.(NHN)" },
{ "001CB6", "Duzon CNT Co., Ltd." },
{ "001CA9", "Audiomatica Srl" },
{ "001D5F", "OverSpeed SARL" },
{ "001D53", "S&O Electronics (Malaysia) Sdn. Bhd." },
{ "001D4E", "TCM Mobile LLC" },
{ "001D4D", "Adaptive Recognition Hungary, Inc" },
{ "001D49", "Innovation Wireless Inc." },
{ "001D44", "KROHNE Messtechnik GmbH" },
{ "001D3D", "Avidyne Corporation" },
{ "001D43", "Shenzhen G-link Digital Technology Co., Ltd." },
{ "001E17", "STN BV" },
{ "001E1C", "SWS Australia Pty Limited" },
{ "001E12", "Ecolab" },
{ "001E0D", "Micran Ltd." },
{ "001E06", "WIBRAIN" },
{ "001DFF", "Network Critical Solutions Ltd" },
{ "001E00", "Shantou Institute of Ultrasonic Instruments" },
{ "001DFA", "Fujian LANDI Commercial Equipment Co.,Ltd" },
{ "001DF3", "SBS Science & Technology Co., Ltd" },
{ "001DEE", "NEXTVISION SISTEMAS DIGITAIS DE TELEVISÃO LTDA." },
{ "001DED", "Grid Net, Inc." },
{ "001DDE", "Zhejiang Broadcast&Television Technology Co.,Ltd." },
{ "001DE7", "Marine Sonic Technology, Ltd." },
{ "001DD7", "Algolith" },
{ "001DD8", "Microsoft Corporation" },
{ "001DCB", "Exéns Development Oy" },
{ "001DC6", "SNR Inc." },
{ "001DC5", "Beijing Jiaxun Feihong Electricial Co., Ltd." },
{ "001DBF", "Radiient Technologies, Inc." },
{ "001DB8", "Intoto Inc." },
{ "001D36", "ELECTRONICS CORPORATION OF INDIA LIMITED" },
{ "001D31", "HIGHPRO INTERNATIONAL R&D CO,.LTD." },
{ "001D2A", "SHENZHEN BUL-TECH CO.,LTD." },
{ "001D23", "SENSUS " },
{ "001D24", "Aclara Power-Line Systems Inc." },
{ "001D1B", "Sangean Electronics Inc." },
{ "001D1E", "KYUSHU TEN CO.,LTD" },
{ "001D15", "Shenzhen Dolphin Electronic Co., Ltd" },
{ "001D0E", "Agapha Technology co., Ltd." },
{ "001DB3", "HPN Supply Chain" },
{ "001DAE", "CHANG TSENG TECHNOLOGY CO., LTD" },
{ "001DA9", "Castles Technology, Co., LTD" },
{ "001DA2", "Cisco Systems, Inc" },
{ "001D9C", "Rockwell Automation" },
{ "001D9B", "Hokuyo Automatic Co., Ltd." },
{ "001D96", "WatchGuard Video" },
{ "001D8F", "PureWave Networks" },
{ "001D8A", "TechTrex Inc" },
{ "001D89", "VaultStor Corporation" },
{ "001D7F", "Tekron International Ltd" },
{ "001D83", "Emitech Corporation" },
{ "001D72", "Wistron Corporation" },
{ "001D79", "SIGNAMAX LLC" },
{ "001D66", "Hyundai Telecom" },
{ "001D6D", "Confidant International LLC" },
{ "001E42", "Teltonika" },
{ "001E3C", "Lyngbox Media AB" },
{ "001E2F", "DiMoto Pty Ltd" },
{ "001E36", "IPTE" },
{ "001E29", "Hypertherm Inc" },
{ "001E23", "Electronic Educational Devices, Inc" },
{ "001C0C", "TANITA Corporation" },
{ "001C06", "Siemens Numerical Control Ltd., Nanjing" },
{ "001BFF", "Millennia Media inc." },
{ "001BFA", "G.i.N. mbH" },
{ "001BE3", "Health Hero Network, Inc." },
{ "001BE5", "802automation Limited" },
{ "001BE4", "TOWNET SRL" },
{ "001BDE", "Renkus-Heinz, Inc." },
{ "001BD2", "ULTRA-X ASIA PACIFIC Inc." },
{ "001C6B", "COVAX  Co. Ltd" },
{ "001C64", "Landis+Gyr" },
{ "001C5F", "Winland Electronics, Inc." },
{ "001C53", "Synergy Lighting Controls" },
{ "001C58", "Cisco Systems, Inc" },
{ "001C4E", "TASA International Limited" },
{ "001C47", "Hangzhou Hollysys Automation Co., Ltd" },
{ "001C49", "Zoltan Technology Inc." },
{ "001C48", "WiDeFi, Inc." },
{ "001C3B", "AmRoad Technology Inc." },
{ "001C42", "Parallels, Inc." },
{ "001B72", "Sicep s.p.a." },
{ "001B6D", "Midtronics, Inc." },
{ "001B6B", "Swyx Solutions AG" },
{ "001B6C", "LookX Digital Media BV" },
{ "001B66", "Sennheiser electronic GmbH & Co. KG" },
{ "001B5F", "Alien Technology" },
{ "001B5A", "Apollo Imaging Technologies, Inc." },
{ "001B53", "Cisco Systems, Inc" },
{ "001B47", "Futarque A/S" },
{ "001B4C", "Signtech" },
{ "001B4E", "Navman New Zealand" },
{ "001B40", "Network Automation mxc AB" },
{ "001C9E", "Dualtech IT AB" },
{ "001C97", "Enzytek Technology Inc.," },
{ "001C98", "LUCKY TECHNOLOGY (HK) COMPANY LIMITED" },
{ "001C92", "Tervela" },
{ "001C8B", "MJ Innovations Ltd." },
{ "001C86", "Cranite Systems, Inc." },
{ "001C85", "Eunicorn" },
{ "001C81", "NextGen Venturi LTD" },
{ "001C72", "Mayer & Cie GmbH & Co KG" },
{ "001C77", "Prodys" },
{ "001B34", "Focus System Inc." },
{ "001B39", "Proxicast" },
{ "001B3B", "Yi-Qing CO., LTD" },
{ "001B28", "POLYGON, JSC" },
{ "001B2D", "Med-Eng Systems Inc." },
{ "001B24", "Quanta Computer Inc." },
{ "001B1F", "DELTA - Danish Electronics, Light & Acoustics" },
{ "001B18", "Tsuken Electric Ind. Co.,Ltd" },
{ "001B13", "Icron Technologies Corporation" },
{ "001B0C", "Cisco Systems, Inc" },
{ "001BA7", "Lorica Solutions" },
{ "001BA2", "IDS Imaging Development Systems GmbH" },
{ "001B96", "General Sensing" },
{ "001B9B", "Hose-McCann Communications" },
{ "001B8F", "Cisco Systems, Inc" },
{ "001B85", "MAN Diesel SE" },
{ "001B7E", "Beckmann GmbH" },
{ "001B79", "FAIVELEY TRANSPORT" },
{ "001C36", "iNEWiT NV" },
{ "001C2F", "Pfister GmbH" },
{ "001C28", "Sphairon Technologies GmbH " },
{ "001C1E", "emtrion GmbH" },
{ "001C19", "secunet Security Networks AG" },
{ "001C0B", "SmartAnt Telecom" },
{ "001C0D", "G-Technology, Inc." },
{ "001BCB", "PEMPEK SYSTEMS PTY LTD" },
{ "001BC4", "Ultratec, Inc." },
{ "001BBA", "Nortel" },
{ "001BB5", "ZF Electronics GmbH" },
{ "001BAE", "Micro Control Systems, Inc" },
{ "001BA8", "UBI&MOBI,.Inc" },
{ "001B05", "YMC AG" },
{ "001B00", "Neopost Technologies" },
{ "001AF4", "Handreamnet" },
{ "001AF9", "AeroVIronment (AV Inc)" },
{ "001AEF", "Loopcomm Technology, Inc." },
{ "001AE3", "Cisco Systems, Inc" },
{ "001AE8", "Unify GmbH and Co KG" },
{ "001AEA", "Radio Terminal Systems Pty Ltd" },
{ "001A26", "Deltanode Solutions AB" },
{ "001A2B", "Ayecom Technology Co., Ltd." },
{ "001A1F", "Coastal Environmental Systems" },
{ "001A1A", "Gentex Corporation/Electro-Acoustic Products" },
{ "001A13", "Wanlida Group Co., LTD" },
{ "001A0E", "Cheng Uei Precision Industry Co.,Ltd" },
{ "001A0C", "Swe-Dish Satellite Systems AB" },
{ "001A07", "Arecont Vision" },
{ "001A00", "MATRIX INC." },
{ "001AD0", "Albis Technologies AG" },
{ "001AD5", "KMC CHAIN INDUSTRIAL CO., LTD." },
{ "001AD7", "Christie Digital Systems, Inc." },
{ "001AC9", "SUZUKEN CO.,LTD" },
{ "001ABA", "Caton Overseas Limited" },
{ "001ABF", "TRUMPF Laser Marking Systems AG" },
{ "001A81", "Zelax" },
{ "001A88", "Venergy,Co,Ltd" },
{ "001A7A", "Lismore Instruments Limited" },
{ "001A70", "Cisco-Linksys, LLC" },
{ "001A72", "Mosart Semiconductor Corp." },
{ "001A6B", "Universal Global Scientific Industrial Co., Ltd." },
{ "001A64", "IBM Corp" },
{ "001A56", "ViewTel Co,. Ltd." },
{ "001A5B", "NetCare Service Co., Ltd." },
{ "001A5F", "KitWorks.fi Ltd." },
{ "0019B6", "Euro Emme s.r.l." },
{ "0019A3", "asteel electronique atlantique" },
{ "0019A8", "WiQuest Communications" },
{ "0019AA", "Cisco Systems, Inc" },
{ "0019AF", "Rigol Technologies, Inc." },
{ "001992", "ADTRAN INC." },
{ "001997", "Soft Device Sdn Bhd" },
{ "00199C", "CTRING" },
{ "001A43", "Logical Link Communications" },
{ "001A48", "Takacom Corporation" },
{ "001A4A", "Qumranet Inc." },
{ "001A3C", "Technowave Ltd." },
{ "001A30", "Cisco Systems, Inc" },
{ "001A35", "BARTEC GmbH" },
{ "001A37", "Lear Corporation" },
{ "0019F2", "Teradyne K.K." },
{ "0019F7", "Onset Computer Corporation" },
{ "0019DF", "Thomson Inc." },
{ "0019E6", "TOYO MEDIC CO.,LTD." },
{ "0019EB", "Pyronix Ltd" },
{ "0019CC", "RCG (HK) Ltd" },
{ "0019D3", "TRAK Microwave" },
{ "0019D8", "MAXFOR" },
{ "0019C2", "Equustek Solutions, Inc." },
{ "00198B", "Novera Optics Korea, Inc." },
{ "00198D", "Ocean Optics, Inc." },
{ "00197F", "PLANTRONICS, INC." },
{ "001986", "Cheng Hongjian" },
{ "001973", "Zeugma Systems" },
{ "00197A", "MAZeT GmbH" },
{ "001967", "TELDAT Sp.J." },
{ "00196C", "ETROVISION TECHNOLOGY" },
{ "00196E", "Metacom (Pty) Ltd." },
{ "001AAC", "Corelatus AB" },
{ "001AAE", "Savant Systems LLC" },
{ "001AB3", "VISIONITE INC." },
{ "001AA7", "Torian Wireless" },
{ "001A9E", "ICON Digital International Limited" },
{ "001AA3", "DELORME" },
{ "001AA5", "BRN Phoenix" },
{ "001AA4", "Future University-Hakodate" },
{ "001A97", "fitivision technology Inc." },
{ "001A8D", "AVECS Bergen GmbH" },
{ "001962", "Commerciant, LP" },
{ "00195D", "ShenZhen XinHuaTong Opto Electronics Co.,Ltd" },
{ "001951", "NETCONS, s.r.o." },
{ "001956", "Cisco Systems, Inc" },
{ "00194A", "TESTO AG" },
{ "001943", "Belden" },
{ "001873", "Cisco Systems, Inc" },
{ "001875", "AnaCise Testnology Pte Ltd" },
{ "00187A", "Wiremold" },
{ "00186E", "3Com Ltd" },
{ "00185E", "Nexterm Inc." },
{ "001860", "SIM Technology Group Shanghai Simcom Ltd.," },
{ "001865", "Siemens Healthcare Diagnostics Manufacturing Ltd" },
{ "001903", "Bigfoot Networks Inc" },
{ "0018F9", "VVOND, Inc." },
{ "0018F2", "Beijing Tianyu Communication Equipment Co., Ltd" },
{ "0018EB", "Blue Zen Enterprises Private Limited" },
{ "0018ED", "Accutech Ultrasystems Co., Ltd." },
{ "0018E6", "Computer Hardware Design SIA" },
{ "0018DA", "AMBER wireless GmbH" },
{ "0018DF", "The Morey Corporation" },
{ "001937", "CommerceGuard AB" },
{ "00192E", "Spectral Instruments, Inc." },
{ "001932", "Gude Analog- und Digialsysteme GmbH" },
{ "001922", "CM Comandos Lineares" },
{ "001927", "ImCoSys Ltd" },
{ "001929", "2M2B Montadora de Maquinas Bahia Brasil LTDA" },
{ "00190F", "Advansus Corp." },
{ "001916", "PayTec AG" },
{ "00191B", "Sputnik Engineering AG" },
{ "001908", "Duaxes Corporation" },
{ "00190A", "HASWARE INC." },
{ "0017D6", "Bluechips Microhouse Co.,Ltd." },
{ "0017DB", "CANKO TECHNOLOGIES INC." },
{ "0017CC", "Alcatel-Lucent" },
{ "0017D1", "Nortel" },
{ "0017C5", "SonicWALL" },
{ "0017B9", "Gambro Lundia AB" },
{ "0017BE", "Tratec Telecom B.V." },
{ "0017C0", "PureTech Systems, Inc." },
{ "001852", "StorLink Semiconductors, Inc." },
{ "001859", "Strawberry Linux Co.,Ltd." },
{ "00184B", "Las Vegas Gaming, Inc." },
{ "001846", "Crypto S.A." },
{ "00183A", "Westell Technologies" },
{ "001829", "Gatsometer" },
{ "001835", "Thoratec / ITC" },
{ "001824", "Kimaldi Electronics, S.L." },
{ "001822", "CEC TELECOM CO.,LTD." },
{ "0017B2", "SK Telesys" },
{ "0017AD", "AceNet Corporation" },
{ "0017A6", "YOSIN ELECTRONICS CO., LTD." },
{ "0017A1", "3soft inc." },
{ "00179C", "DEPRAG SCHULZ GMBH u. CO." },
{ "001790", "HYUNDAI DIGITECH Co, Ltd." },
{ "001795", "Cisco Systems, Inc" },
{ "0018CE", "Dreamtech Co., Ltd" },
{ "0018D3", "TEAMCAST" },
{ "0018C2", "Firetide, Inc" },
{ "0018C4", "Raba Technologies LLC" },
{ "0018C9", "EOps Technology Limited" },
{ "0018BD", "SHENZHEN DVBWORLD TECHNOLOGY CO., LTD." },
{ "0018B1", "IBM Corp" },
{ "0018B6", "S3C, Inc." },
{ "0018AF", "Samsung Electronics Co., Ltd." },
{ "0018A3", "ZIPPY TECHNOLOGY CORP." },
{ "0018AA", "Protec Fire Detection plc" },
{ "001816", "Ubixon Co., Ltd." },
{ "00181D", "ASIA ELECTRONICS CO.,LTD" },
{ "001811", "Neuros Technology International, LLC." },
{ "00180A", "Meraki, Inc." },
{ "001801", "Actiontec Electronics, Inc" },
{ "0017F5", "LIG NEOPTEK" },
{ "0017FA", "Microsoft Corporation" },
{ "0017FC", "Suprema Inc." },
{ "00189E", "OMNIKEY GmbH." },
{ "001894", "NPCore, Inc." },
{ "001899", "ShenZhen jieshun Science&Technology Industry CO,LTD." },
{ "001886", "EL-TECH, INC." },
{ "001888", "GOTIVE a.s." },
{ "001881", "Buyang Electronics Industrial Co., Ltd" },
{ "0016D4", "Compal Communications, Inc." },
{ "0016D9", "NINGBO BIRD CO.,LTD." },
{ "0016C8", "Cisco Systems, Inc" },
{ "0016CD", "HIJI HIGH-TECH CO., LTD." },
{ "0016C1", "Eleksen Ltd" },
{ "0016BA", "WEATHERNEWS INC." },
{ "00164F", "World Ethnic Broadcastin Inc." },
{ "00164D", "Alcatel North America IP Division" },
{ "001648", "SSD Company Limited" },
{ "001643", "Sunhillo Corporation" },
{ "00163E", "Xensource, Inc." },
{ "001637", "CITEL SpA" },
{ "001632", "SAMSUNG ELECTRONICS CO., LTD." },
{ "00162B", "Togami Electric Mfg.co.,Ltd." },
{ "001755", "GE Security" },
{ "001747", "Trimble" },
{ "001749", "HYUNDAE YONG-O-SA CO.,LTD" },
{ "00174E", "Parama-tech Co.,Ltd." },
{ "001732", "Science-Technical Center RISSA" },
{ "001734", "ADC Telecommunications" },
{ "001739", "Bright Headphone Electronics Company" },
{ "00172D", "Axcen Photonics Corporation" },
{ "001624", "Teneros, Inc." },
{ "001613", "LibreStream Technologies Inc." },
{ "001618", "HIVION Co., Ltd." },
{ "00161F", "SUNWAVETEC Co., Ltd." },
{ "00160E", "Optica Technologies Inc." },
{ "001607", "Curves International Inc." },
{ "001609", "Unitech electronics co., ltd." },
{ "001608", "Sequans Communications" },
{ "001602", "CEYON TECHNOLOGY CO.,LTD." },
{ "0015FB", "setex schermuly textile computer gmbh" },
{ "0015F6", "SCIENCE AND ENGINEERING SERVICES, INC." },
{ "00177D", "IDT International Limited" },
{ "001782", "LoBenn Inc." },
{ "001789", "Zenitron Corporation" },
{ "00176D", "CORE CORPORATION" },
{ "001771", "APD Communications Ltd" },
{ "001776", "Meso Scale Diagnostics, LLC" },
{ "001761", "Private" },
{ "001768", "Zinwave Ltd" },
{ "00175C", "SHARP CORPORATION" },
{ "00175A", "Cisco Systems, Inc" },
{ "001709", "Exalt Communications" },
{ "001704", "Shinco Electronics Group Co.,Ltd" },
{ "0016FD", "Jaty Electronics" },
{ "0016F1", "OmniSense, LLC" },
{ "0016F6", "Video Products Group" },
{ "0016F8", "AVIQTECH TECHNOLOGY CO., LTD." },
{ "0016E5", "FORDLEY DEVELOPMENT LIMITED" },
{ "0016DE", "FAST Inc" },
{ "00167E", "DIBOSS.CO.,LTD" },
{ "001680", "Bally Gaming + Systems" },
{ "001679", "eOn Communications" },
{ "00166E", "Arbitron Inc." },
{ "001667", "A-TEC Subsystem INC." },
{ "001660", "Nortel" },
{ "00165B", "Grip Audio" },
{ "001654", "Flex-P Industries Sdn. Bhd." },
{ "001721", "FITRE S.p.A." },
{ "001726", "m2c Electronic Technology Ltd." },
{ "00171A", "Winegard Company" },
{ "00171F", "IMV Corporation" },
{ "001713", "Tiger NetCom" },
{ "00170E", "Cisco Systems, Inc" },
{ "0016A9", "2EI" },
{ "0016AE", "INVENTEL" },
{ "00169D", "Cisco Systems, Inc" },
{ "00169F", "Vimtron Electronics Co., Ltd." },
{ "0016A4", "Ezurio Ltd" },
{ "001691", "Moser-Baer AG" },
{ "001698", "T&A Mobile Phones" },
{ "00168C", "DSL Partner AS" },
{ "001685", "Elisa Oyj" },
{ "0015EF", "NEC TOKIN Corporation" },
{ "0015E8", "Nortel" },
{ "0015E3", "Dream Technologies Corporation" },
{ "0015D9", "PKC Electronics Oy" },
{ "0015D2", "Xantech Corporation" },
{ "0015CC", "UQUEST, LTD." },
{ "0015CB", "Surf Communication Solutions Ltd." },
{ "0015CD", "Exartech International Corp." },
{ "0015C6", "Cisco Systems, Inc" },
{ "0015BB", "SMA Solar Technology AG" },
{ "0014D5", "Datang Telecom Technology CO. , LCD,Optical Communication Br" },
{ "0014DA", "Huntleigh Healthcare" },
{ "0014CE", "NF CORPORATION" },
{ "0014C8", "Contemporary Research Corp" },
{ "0014C7", "Nortel" },
{ "0014BB", "Open Interface North America" },
{ "0014B6", "Enswer Technology Inc." },
{ "0014AC", "Bountiful WiFi" },
{ "0014B1", "Axell Wireless Limited" },
{ "001476", "MultiCom Industries Limited" },
{ "001471", "Eastern Asia Technology Limited" },
{ "00146A", "Cisco Systems, Inc" },
{ "001463", "IDCS N.V." },
{ "001465", "Novo Nordisk A/S" },
{ "001464", "Cryptosoft" },
{ "00145E", "IBM Corp" },
{ "001457", "T-VIPS AS" },
{ "001452", "CALCULEX,INC." },
{ "001592", "Facom UK Ltd (Melksham)" },
{ "00158B", "Park Air Systems Ltd" },
{ "001584", "Schenck Process GmbH" },
{ "00157F", "ChuanG International Holding CO.,LTD." },
{ "00157A", "Telefin S.p.A." },
{ "001575", "Nevis Networks Inc." },
{ "00156E", "A. W. Communication Systems Ltd" },
{ "001567", "RADWIN Inc." },
{ "001569", "PECO II, Inc." },
{ "001568", "Dilithium Networks" },
{ "001562", "Cisco Systems, Inc" },
{ "001503", "PROFIcomms s.r.o." },
{ "001505", "Actiontec Electronics, Inc" },
{ "001504", "GAME PLUS CO., LTD." },
{ "0014FE", "Artech Electronics" },
{ "0014F7", "CREVIS Co., LTD" },
{ "0014F2", "Cisco Systems, Inc" },
{ "0014EB", "AwarePoint Corporation" },
{ "0014E1", "Data Display AG" },
{ "00155B", "Sampo Corporation" },
{ "00154F", "one RF Technology" },
{ "001546", "ITG Worldwide Sdn Bhd" },
{ "001540", "Nortel" },
{ "00153F", "Alcatel Alenia Space Italia" },
{ "001541", "StrataLight Communications, Inc." },
{ "00153A", "Shenzhen Syscan Technology Co.,Ltd." },
{ "0015BF", "technicob" },
{ "0015B4", "Polymap  Wireless LLC" },
{ "0015AA", "Rextechnik International Co.," },
{ "0015A5", "DCI Co., Ltd." },
{ "00159E", "Mad Catz Interactive Inc" },
{ "001597", "AETA AUDIO SYSTEMS" },
{ "00149E", "UbONE Co., Ltd" },
{ "001499", "Helicomm Inc" },
{ "001492", "Liteon, Mobile Media Solution SBU" },
{ "00148B", "Globo Electronic GmbH & Co. KG" },
{ "00148D", "Cubic Defense Simulation Systems" },
{ "00148C", "Fortress Technologies" },
{ "001486", "Echo Digital Audio Corporation" },
{ "00147D", "Aeon Digital International" },
{ "001533", "NADAM.CO.,LTD" },
{ "00152E", "PacketHop, Inc." },
{ "001527", "Balboa Instruments" },
{ "001520", "Radiocrafts AS" },
{ "00151B", "Isilon Systems Inc." },
{ "001516", "URIEL SYSTEMS INC." },
{ "001511", "Data Center Systems" },
{ "00150A", "Sonoa Systems, Inc" },
{ "00131F", "NxtPhase T&D, Corp." },
{ "001318", "DGSTATION Co., Ltd." },
{ "00130C", "HF System Corporation" },
{ "001313", "GuangZhou Post & Telecom Equipment ltd" },
{ "001354", "Zcomax Technologies, Inc." },
{ "001358", "Realm Systems, Inc." },
{ "00135D", "NTTPC Communications, Inc." },
{ "00134F", "Tranzeo Wireless Technologies Inc." },
{ "001348", "Artila Electronics Co., Ltd." },
{ "001342", "Vision Research, Inc." },
{ "00133C", "QUINTRON SYSTEMS INC." },
{ "001341", "Shandong New Beiyang Information Technology Co.,Ltd" },
{ "001329", "VSST Co., LTD" },
{ "001330", "EURO PROTECTION SURVEILLANCE" },
{ "001335", "VS Industry Berhad" },
{ "00132F", "Interactek" },
{ "0012C4", "Viseon, Inc." },
{ "0012D0", "Gossen-Metrawatt-GmbH" },
{ "0012CA", "Mechatronic Brick Aps" },
{ "0012BA", "FSI Systems, Inc." },
{ "0012AE", "HLS HARD-LINE Solutions Inc." },
{ "0012B3", "Advance Wireless Technology Corp." },
{ "0012AD", "IDS GmbH" },
{ "00144D", "Intelligent Systems" },
{ "001441", "Innovation Sound Technology Co., LTD." },
{ "001448", "Inventec Multimedia & Telecom Corporation" },
{ "00143A", "RAYTALK INTERNATIONAL SRL" },
{ "001435", "CityCom Corp." },
{ "00142E", "77 Elektronika Kft." },
{ "001429", "V Center Technologies Co., Ltd." },
{ "001428", "Vocollect, Inc" },
{ "001427", "JazzMutant" },
{ "00141E", "P.A. Semi, Inc." },
{ "0012F9", "URYU SEISAKU, LTD." },
{ "001300", "IT-FACTORY, INC." },
{ "001305", "Epicom, Inc." },
{ "001306", "Always On Wireless" },
{ "0012F4", "Belco International Co.,Ltd." },
{ "0012EF", "OneAccess SA" },
{ "0012EA", "Trane" },
{ "0012E9", "Abbey Systems Ltd" },
{ "0012DC", "SunCorp Industrial Limited" },
{ "0012E3", "Agat-RT, Ltd." },
{ "0012D7", "Invento Networks, Inc." },
{ "0013F0", "Wavefront Semiconductor" },
{ "0013EB", "Sysmaster Corporation" },
{ "0013E6", "Technolution" },
{ "0013DF", "Ryvor Corp." },
{ "0013D9", "Matrix Product Development, Inc." },
{ "0013DA", "Diskware Co., Ltd" },
{ "0013CD", "MTI co. LTD" },
{ "0013D3", "MICRO-STAR INTERNATIONAL CO., LTD." },
{ "0013C1", "Asoka USA Corporation" },
{ "0013BC", "Artimi Ltd" },
{ "0013B7", "Scantech ID" },
{ "0013AB", "Telemotive AG" },
{ "0013B2", "Carallon Limited" },
{ "0013B1", "Intelligent Control Systems (Asia) Pte Ltd" },
{ "0013A4", "KeyEye Communications" },
{ "00139F", "Electronics Design Services, Co., Ltd." },
{ "001398", "TrafficSim Co.,Ltd" },
{ "001392", "Ruckus Wireless" },
{ "00138C", "Kumyoung.Co.Ltd" },
{ "001391", "OUEN CO.,LTD." },
{ "001377", "Samsung Electronics CO., LTD" },
{ "00137C", "Kaicom co., Ltd." },
{ "001383", "Application Technologies and Engineering Research Laboratory" },
{ "001364", "Paradigm Technology Inc.." },
{ "001369", "Honda Electron Co., LED." },
{ "00136A", "Hach Lange Sarl" },
{ "001418", "C4Line" },
{ "00141D", "LTi DRIVES GmbH" },
{ "001411", "Deutschmann Automation GmbH & Co. KG" },
{ "004501", "Versus Technology, Inc." },
{ "001403", "Renasis, LLC" },
{ "0013FC", "SiCortex, Inc" },
{ "0013F5", "Akimbi Systems" },
{ "0013F6", "Cintech" },
{ "001286", "ENDEVCO CORP" },
{ "00127F", "Cisco Systems, Inc" },
{ "001278", "International Bar Code" },
{ "00126C", "Visonic Ltd." },
{ "001273", "Stoke Inc" },
{ "001266", "Swisscom Hospitality Services SA" },
{ "001265", "Enerdyne Technologies, Inc." },
{ "00125B", "KAIMEI ELECTRONI" },
{ "0011D2", "Perception Digital Ltd" },
{ "0011D7", "eWerks Inc" },
{ "0011D1", "Soft Imaging System GmbH" },
{ "0011C2", "United Fiber Optic Communication" },
{ "0011CB", "Jacobsons AB" },
{ "0011BB", "Cisco Systems, Inc" },
{ "0011BC", "Cisco Systems, Inc" },
{ "0011AA", "Uniclass Technology, Co., LTD" },
{ "0011AF", "Medialink-i,Inc" },
{ "001200", "Cisco Systems, Inc" },
{ "0011FB", "Heidelberg Engineering GmbH" },
{ "0011F6", "Asia Pacific Microsystems , Inc." },
{ "0011F1", "QinetiQ Ltd" },
{ "0011EA", "IWICS Inc." },
{ "0011E3", "Thomson, Inc." },
{ "0011DE", "EURILOGIC" },
{ "0011E4", "Danelec Electronics A/S" },
{ "001230", "Picaso Infocommunication CO., LTD." },
{ "001226", "Japan Direx Corporation" },
{ "001220", "Cadco Systems" },
{ "00121A", "Techno Soft Systemnics Inc." },
{ "00121F", "Harding Instruments" },
{ "001213", "Metrohm AG" },
{ "00120D", "Advanced Telecommunication Technologies, Inc." },
{ "001207", "Head Strong International Limited" },
{ "00120E", "AboCom" },
{ "00117A", "Singim International Corp." },
{ "00116E", "PePLink Ltd." },
{ "001173", "SMART Storage Systems" },
{ "001167", "Integrated System Solution Corp." },
{ "00116D", "American Time and Signal" },
{ "001163", "SYSTEM SPA DEPT. ELECTRONICS" },
{ "001156", "Pharos Systems NZ" },
{ "00115D", "Cisco Systems, Inc" },
{ "0012A7", "ISR TECHNOLOGIES Inc" },
{ "0012A0", "NeoMeridian Sdn Bhd" },
{ "00129B", "E2S Electronic Engineering Solutions, S.L." },
{ "001294", "SUMITOMO ELECTRIC DEVICE INNOVATIONS, INC" },
{ "00128B", "Sensory Networks Inc" },
{ "001285", "Gizmondo Europe Ltd" },
{ "0011A9", "MOIMSTONE Co., LTD" },
{ "0011A3", "LanReady Technologies Inc." },
{ "001197", "Monitoring Technologies Limited" },
{ "00119C", "EP&T Energy" },
{ "00118D", "Hanchang System Corp." },
{ "001192", "Cisco Systems, Inc" },
{ "001186", "Prime Systems, Inc." },
{ "00117F", "Neotune Information Technology Corporation,.LTD" },
{ "001260", "Stanton Magnetics,inc." },
{ "001256", "LG INFORMATION & COMM." },
{ "00124F", "Pentair Thermal Management" },
{ "00124A", "Dedicated Devices, Inc." },
{ "001249", "Delta Elettronica S.p.A." },
{ "001243", "Cisco Systems, Inc" },
{ "00123C", "Second Rule LLC" },
{ "001148", "Prolon Control Systems" },
{ "00114D", "Atsumi Electric Co.,LTD." },
{ "00114E", "690885 Ontario Inc." },
{ "001141", "GoodMan Corporation" },
{ "00113B", "Micronet Communications Inc." },
{ "001135", "Grandeye Ltd" },
{ "001126", "Venstar Inc." },
{ "000EB9", "HASHIMOTO Electronics Industry Co.,Ltd." },
{ "000EBA", "HANMI SEMICONDUCTOR CO., LTD." },
{ "000EAC", "MINTRON ENTERPRISE CO., LTD." },
{ "000EA0", "NetKlass Technology Inc." },
{ "000EA7", "Endace Technology" },
{ "000E9A", "BOE TECHNOLOGY GROUP CO.,LTD" },
{ "000E99", "Spectrum Digital, Inc" },
{ "00112B", "NetModule AG" },
{ "001120", "Cisco Systems, Inc" },
{ "001125", "IBM Corp" },
{ "001119", "Solteras, Inc." },
{ "001113", "Fraunhofer FOKUS" },
{ "001106", "Siemens NV (Belgium)" },
{ "00110D", "SANBlaze Technology, Inc." },
{ "001101", "CET Technologies Pte Ltd" },
{ "000FB3", "Actiontec Electronics, Inc" },
{ "000FA6", "S2 Security Corporation" },
{ "000FAD", "FMN communications GmbH" },
{ "000F9B", "Ross Video Limited" },
{ "000F9E", "Murrelektronik GmbH" },
{ "000FA1", "Gigabit Systems Inc." },
{ "000F95", "ELECOM Co.,LTD Laneed Division" },
{ "000F96", "Telco Systems, Inc. " },
{ "000F8F", "Cisco Systems, Inc" },
{ "000F88", "AMETEK, Inc." },
{ "000F83", "Brainium Technologies Inc." },
{ "000F51", "Azul Systems, Inc." },
{ "000F44", "Tivella Inc." },
{ "000F43", "Wasabi Systems Inc." },
{ "000F4A", "Kyushu-kyohan co.,ltd" },
{ "000F3E", "CardioNet, Inc" },
{ "000F3A", "HISHARP" },
{ "000F30", "Raza Microelectronics Inc" },
{ "000F2F", "W-LINX TECHNOLOGY CO., LTD." },
{ "000F36", "Accurate Techhnologies, Inc." },
{ "000F2A", "Cableware Electronics" },
{ "000F76", "Digital Keystone, Inc." },
{ "000F70", "Wintec Industries, inc." },
{ "000F75", "First Silicon Solutions" },
{ "000F7C", "ACTi Corporation" },
{ "000F69", "SEW Eurodrive GmbH & Co. KG" },
{ "000F63", "Obzerv Technologies" },
{ "000F64", "D&R Electronica Weesp BV" },
{ "000F5D", "Genexis BV" },
{ "000F56", "Continuum Photonics Inc" },
{ "000EEB", "Sandmartin(zhong shan)Electronics Co.,Ltd" },
{ "000EEC", "Orban" },
{ "000EF1", "EZQUEST INC." },
{ "000EDE", "REMEC, Inc." },
{ "000EE5", "bitWallet, Inc." },
{ "000ECC", "Tableau, LLC" },
{ "000ED9", "Aksys, Ltd." },
{ "000ECB", "VineSys Technology" },
{ "000ED2", "Filtronic plc" },
{ "000EBF", "Remsdaq Limited" },
{ "000EC6", "ASIX ELECTRONICS CORP." },
{ "000F23", "Cisco Systems, Inc" },
{ "000F1D", "Cosmo Techs Co., Ltd." },
{ "000F10", "RDM Corporation" },
{ "000F17", "Insta Elektro GmbH" },
{ "000F1E", "Chengdu KT Electric Co.of High & New Technology" },
{ "000F0B", "Kentima Technologies AB" },
{ "000F04", "cim-usa inc" },
{ "000EFE", "EndRun Technologies LLC" },
{ "000EF8", "SBC ASI" },
{ "000EFD", "FUJINON CORPORATION" },
{ "000FFB", "Nippon Denso Industry Co., Ltd." },
{ "000FF8", "Cisco Systems, Inc" },
{ "000FF2", "Loud Technologies Inc." },
{ "000FF7", "Cisco Systems, Inc" },
{ "000FE5", "MERCURY SECURITY CORPORATION" },
{ "000FE6", "MBTech Systems, Inc." },
{ "000FEB", "Cylon Controls" },
{ "000FDF", "SOLOMON Technology Corp." },
{ "000FD8", "Force, Inc." },
{ "000FD3", "Digium" },
{ "000FC6", "Eurocom Industries A/S" },
{ "000FC5", "KeyMed Ltd" },
{ "000FC0", "DELCOMp" },
{ "000FB4", "Timespace Technology" },
{ "000FB9", "Adaptive Instruments" },
{ "000D4D", "Ninelanes" },
{ "000D54", "3Com Ltd" },
{ "000D45", "Tottori SANYO Electric Co., Ltd." },
{ "000D48", "AEWIN Technologies Co., Ltd." },
{ "000D40", "Verint Loronix Video Solutions" },
{ "000D39", "Network Electronics" },
{ "000D33", "Prediwave Corp." },
{ "000D34", "Shell International Exploration and Production, Inc." },
{ "000D2D", "NCT Deutschland GmbH" },
{ "000D26", "Primagraphics Limited" },
{ "000D21", "WISCORE Inc." },
{ "000D14", "Vtech Innovation LP dba Advanced American Telephones" },
{ "000D13", "Wilhelm Rutenbeck GmbH&Co.KG" },
{ "000D1A", "Mustek System Inc." },
{ "000D0E", "Inqnet Systems, Inc." },
{ "000D01", "P&E Microcomputer Systems, Inc." },
{ "000D02", "NEC Platforms, Ltd." },
{ "000D07", "Calrec Audio Ltd" },
{ "000E8D", "Systems in Progress Holding GmbH" },
{ "000E94", "Maas International BV" },
{ "000E87", "adp Gauselmann GmbH" },
{ "000E81", "Devicescape Software, Inc." },
{ "000E88", "VIDEOTRON CORP." },
{ "000E75", "New York Air Brake Corp." },
{ "000E7A", "GemWon Communications Co., Ltd." },
{ "000E66", "Hitachi Industry & Control Solutions, Ltd." },
{ "000DF6", "Technology Thesaurus Corp." },
{ "000DFD", "Huges Hi-Tech Inc.," },
{ "000E02", "Advantech AMT Inc." },
{ "000DF0", "QCOM TECHNOLOGY INC." },
{ "000DEA", "Kingtel Telecommunication Corp." },
{ "000DEF", "Soc. Coop. Bilanciai" },
{ "000DDD", "Profilo Telra Elektronik Sanayi ve Ticaret. A.Ş" },
{ "000DDE", "Joyteck Co., Ltd." },
{ "000DE3", "AT Sweden AB" },
{ "000DD0", "TetraTec Instruments GmbH" },
{ "000DD7", "Bright" },
{ "000E61", "MICROTROL LIMITED" },
{ "000E5A", "TELEFIELD inc." },
{ "000E54", "AlphaCell Wireless Ltd." },
{ "000E4E", "Waveplus Technology Co., Ltd." },
{ "000E53", "AV TECH CORPORATION" },
{ "000E47", "NCI System Co.,Ltd." },
{ "000E41", "NIHON MECHATRONICS CO.,LTD." },
{ "000E42", "Motic Incoporation Ltd." },
{ "000E3C", "Transact Technologies Inc" },
{ "000E36", "HEINESYS, Inc." },
{ "000DB1", "Japan Network Service Co., Ltd." },
{ "000DA9", "T.E.A.M. S.L." },
{ "000DAC", "Japan CBM Corporation" },
{ "000DA4", "DOSCH & AMAND SYSTEMS AG" },
{ "000D97", "ABB Inc./Tropos" },
{ "000D98", "S.W.A.C. Schmitt-Walter Automation Consult GmbH" },
{ "000D8A", "Winners Electronics Co., Ltd." },
{ "000D91", "Eclipse (HQ Espana) S.L." },
{ "000D7F", "MIDAS  COMMUNICATION TECHNOLOGIES PTE LTD ( Foreign Branch)" },
{ "000D79", "Dynamic Solutions Co,.Ltd." },
{ "000D73", "Technical Support, Inc." },
{ "000D7A", "DiGATTO Asia Pacific Pte Ltd" },
{ "000D6C", "M-Audio" },
{ "000D5A", "Tiesse SpA" },
{ "000D60", "IBM Corp" },
{ "000D59", "Amity Systems, Inc." },
{ "000DCB", "Petcomkorea Co., Ltd." },
{ "000DC4", "Emcore Corporation" },
{ "000DBE", "Bel Fuse Europe Ltd.,UK" },
{ "000DB8", "SCHILLER AG" },
{ "000DBD", "Cisco Systems, Inc" },
{ "000E30", "AERAS Networks, Inc." },
{ "000E29", "Shester Communications Inc" },
{ "000E23", "Incipient, Inc." },
{ "000E24", "Huwell Technology Inc." },
{ "000E16", "SouthWing S.L." },
{ "000E1D", "ARION Technology Inc." },
{ "000E09", "Shenzhen Coship Software Co.,LTD." },
{ "000E11", "BDT Büro und Datentechnik GmbH & Co.KG " },
{ "000BC8", "AirFlow Networks" },
{ "000BCF", "AGFA NDT INC." },
{ "000BC3", "Multiplex, Inc." },
{ "000BBC", "En Garde Systems, Inc." },
{ "000BC1", "Bay Microsystems, Inc." },
{ "000BB0", "Sysnet Telematica srl" },
{ "000BB5", "nStor Technologies, Inc." },
{ "000BA6", "Miyakawa Electric Works Ltd." },
{ "000BAB", "Advantech Technology (CHINA) Co., Ltd." },
{ "000B99", "SensAble Technologies, Inc." },
{ "000B9A", "Shanghai Ulink Telecom Equipment Co. Ltd." },
{ "000B9F", "Neue ELSA GmbH" },
{ "000B94", "Digital Monitoring Products, Inc." },
{ "000C1D", "Mettler & Fuchs AG" },
{ "000C22", "Double D Electronics Ltd" },
{ "000C0F", "Techno-One Co., Ltd" },
{ "000C16", "Concorde Microsystems Inc." },
{ "000C0A", "Guangdong Province Electronic Technology Research Institute" },
{ "000BFD", "Cisco Systems, Inc" },
{ "000BF7", "NIDEK CO.,LTD" },
{ "000BFC", "Cisco Systems, Inc" },
{ "000BFE", "CASTEL Broadband Limited" },
{ "000C03", "HDMI Licensing, LLC" },
{ "000CA4", "Prompttec Product Management GmbH" },
{ "000CAB", "COMMEND International" },
{ "000C98", "LETEK Communications Inc." },
{ "000C9D", "UbeeAirWalk, Inc." },
{ "000C9F", "NKE Corporation" },
{ "000C8C", "KODICOM CO.,LTD." },
{ "000C91", "Riverhead Networks Inc." },
{ "000C80", "Opelcomm Inc." },
{ "000C85", "Cisco Systems, Inc" },
{ "000CD0", "Symetrix" },
{ "000CD5", "Passave Inc." },
{ "000CDC", "BECS Technology, Inc" },
{ "000CC9", "ILWOO DATA & TECHNOLOGY CO.,LTD" },
{ "000CB0", "Star Semiconductor Corporation" },
{ "000CB6", "NANJING SEU MOBILE & INTERNET TECHNOLOGY CO.,LTD" },
{ "000CBD", "Interface Masters, Inc" },
{ "000CC2", "ControlNet (India) Private Limited" },
{ "000CAF", "TRI TERM CO.,LTD." },
{ "000C71", "Wybron, Inc" },
{ "000C78", "In-Tech Electronics Limited" },
{ "000C7D", "TEIKOKU ELECTRIC MFG. CO., LTD" },
{ "000C65", "Sunin Telecom" },
{ "000C6A", "MBARI" },
{ "000C6C", "Elgato Systems LLC" },
{ "000B88", "Vidisco ltd." },
{ "000B8D", "Avvio Networks" },
{ "000B7B", "Test-Um Inc." },
{ "000B7A", "L-3 Linkabit" },
{ "000B7C", "Telex Communications" },
{ "000B81", "Kaparel Corporation" },
{ "000B6E", "Neff Instrument Corp." },
{ "000B75", "Iosoft Ltd." },
{ "000B69", "Franke Finland Oy" },
{ "0091D6", "Crystal Group, Inc." },
{ "000B62", "ib-mohnen KG" },
{ "000B59", "ScriptPro, LLC" },
{ "000C52", "Roll Systems Inc." },
{ "000C57", "MACKIE Engineering Services Belgium BVBA" },
{ "000C59", "Indyme Electronics, Inc." },
{ "000C5E", "Calypso Medical" },
{ "000C4B", "Cheops Elektronik" },
{ "000C46", "Allied Telesyn Inc." },
{ "000C3D", "Glsystech Co., Ltd." },
{ "000C33", "Compucase Enterprise Co. Ltd." },
{ "000C36", "SHARP TAKAYA ELECTRONICS INDUSTRY CO.,LTD." },
{ "000C2C", "Enwiser Inc." },
{ "000CFB", "Korea Network Systems" },
{ "000CEF", "Open Networks Engineering Ltd" },
{ "000CF4", "AKATSUKI ELECTRIC MFG.CO.,LTD." },
{ "000CE8", "GuangZhou AnJuBao Co., Ltd" },
{ "000CE1", "The Open Group" },
{ "000CCF", "Cisco Systems, Inc" },
{ "000BEB", "Systegra AG" },
{ "000BF0", "MoTEX Products Co., Ltd." },
{ "000BDD", "TOHOKU RICOH Co., LTD." },
{ "000BE4", "Hosiden Corporation" },
{ "000BD8", "Industrial Scientific Corp." },
{ "000BD4", "Beijing Wise Technology & Science Development Co.Ltd" },
{ "000A1D", "Optical Communications Products Inc." },
{ "000A1F", "ART WARE Telecommunication Co., Ltd." },
{ "000A24", "Octave Communications" },
{ "000A18", "Vichel Inc." },
{ "000A0C", "Scientific Research Corporation" },
{ "000A11", "ExPet Technologies, Inc" },
{ "0009F8", "UNIMO TECHNOLOGY CO., LTD." },
{ "0009FB", "Philips Patient Monitoring" },
{ "000A02", "ANNSO CO., LTD." },
{ "0009EB", "HuMANDATA LTD." },
{ "0009EC", "Daktronics, Inc." },
{ "0009F1", "Yamaki Electric Corporation" },
{ "0009E5", "Hottinger Baldwin Messtechnik GmbH" },
{ "0009D9", "Neoscale Systems, Inc" },
{ "0009DE", "Samjin Information & Communications Co., Ltd." },
{ "0009CC", "Moog GmbH" },
{ "0009C6", "Visionics Corporation" },
{ "0009CB", "HBrain" },
{ "0009D2", "Mai Logic Inc." },
{ "0009BE", "Mamiya-OP Co.,Ltd." },
{ "0009C2", "Onity, Inc." },
{ "000B51", "Micetek International Inc." },
{ "000B54", "BiTMICRO Networks, Inc." },
{ "000B45", "Cisco Systems, Inc" },
{ "000B4C", "Clarion (M) Sdn Bhd" },
{ "000B40", "Oclaro" },
{ "000B32", "VORMETRIC, INC." },
{ "000B39", "Keisoku Giken Co.,Ltd." },
{ "000B3E", "BittWare, Inc" },
{ "000B26", "Wetek Corporation" },
{ "000B2B", "HOSTNET CORPORATION" },
{ "000B2D", "Danfoss Inc." },
{ "000ABB", "Taiwan Secom Co,. Ltd" },
{ "000AC7", "Unication Group" },
{ "000AAF", "Pipal Systems" },
{ "000AB6", "COMPUNETIX, INC" },
{ "000AA3", "SHIMAFUJI ELECTRIC CO.,LTD." },
{ "000AA8", "ePipe Pty. Ltd." },
{ "000AAA", "AltiGen Communications Inc." },
{ "000A90", "Bayside Interactive, Inc." },
{ "000A9C", "Server Technology, Inc." },
{ "000A96", "MEWTEL TECHNOLOGY INC." },
{ "000A81", "TEIMA Audiotex S.L." },
{ "000A83", "SALTO SYSTEMS S.L." },
{ "000A88", "InCypher S.A." },
{ "000A7C", "Tecton Ltd" },
{ "000A70", "MPLS Forum" },
{ "000A75", "Caterpillar, Inc" },
{ "000A62", "Crinis Networks, Inc." },
{ "000A64", "Eracom Technologies" },
{ "000A69", "SUNNY bell Technology Co., Ltd." },
{ "000A5D", "FingerTec Worldwide Sdn Bhd" },
{ "000AF4", "Cisco Systems, Inc" },
{ "000AED", "HARTING Systems GmbH & Co KG" },
{ "000AE8", "Cathay Roxus Information Technology Co. LTD" },
{ "000ADA", "Vindicator Technologies" },
{ "000ADC", "RuggedCom Inc." },
{ "000AE1", "EG Technology" },
{ "000AC9", "Zambeel Inc" },
{ "000ACE", "RADIANTECH, INC." },
{ "000AD5", "Brainchild Electronic Co., Ltd." },
{ "000A4F", "Brain Boxes Limited" },
{ "000A51", "GyroSignal Technology Co., Ltd." },
{ "000A56", "HITACHI Maxell Ltd." },
{ "000A4A", "Targa Systems Ltd." },
{ "000A37", "Procera Networks, Inc." },
{ "000A3E", "EADS Telecom" },
{ "000A43", "Chunghwa Telecom Co., Ltd." },
{ "000A30", "Visteon Corporation" },
{ "000A32", "Xsido Corporation" },
{ "000A2B", "Etherstuff" },
{ "000A29", "Pan Dacom Networking AG" },
{ "000B1A", "Industrial Defender, Inc." },
{ "000B1F", "I CON Computer Co." },
{ "000B13", "ZETRON INC" },
{ "000B0E", "Trapeze Networks" },
{ "000B0C", "Agile Systems Inc." },
{ "000B07", "Voxpath Networks" },
{ "000AF9", "HiConnect, Inc." },
{ "000AFB", "Ambri Limited" },
{ "000B00", "FUJIAN START COMPUTER EQUIPMENT CO.,LTD" },
{ "0009B8", "Entise Systems" },
{ "0009B7", "Cisco Systems, Inc" },
{ "0009B2", "L&F Inc." },
{ "0009A5", "HANSUNG ELETRONIC INDUSTRIES DEVELOPMENT CO., LTD" },
{ "0009A6", "Ignis Optics, Inc." },
{ "0009AB", "Netcontrol Oy" },
{ "00099F", "VIDEX INC." },
{ "0007B3", "Cisco Systems, Inc" },
{ "0007AD", "Pentacon GmbH Foto-und Feinwerktechnik" },
{ "0007A5", "Y.D.K Co. Ltd." },
{ "00079F", "Action Digital Inc." },
{ "000792", "Sütron Electronic GmbH" },
{ "000799", "Tipping Point Technologies, Inc." },
{ "00078C", "Elektronikspecialisten i Borlange AB" },
{ "000786", "Wireless Networks Inc." },
{ "000775", "Valence Semiconductor, Inc." },
{ "00077C", "Westermo Teleindustri AB" },
{ "000776", "Federal APD" },
{ "00077F", "J Communications Co., Ltd." },
{ "000780", "Bluegiga Technologies OY" },
{ "000881", "DIGITAL HANDS CO.,LTD." },
{ "02C08C", "3COM CORPORATION" },
{ "00087B", "RTX Telecom A/S" },
{ "000880", "BroadTel Canada Communications inc." },
{ "00086E", "Hyglo AB" },
{ "000868", "PurOptix" },
{ "000861", "SoftEnergy Co., Ltd." },
{ "00084F", "Qualstar Corporation" },
{ "00085B", "Hanbit Electronics Co., Ltd." },
{ "000855", "NASA-Goddard Space Flight Center" },
{ "00084E", "DivergeNet, Inc." },
{ "00085C", "Shanghai Dare Technologies Co. Ltd." },
{ "0007ED", "Altera Corporation" },
{ "0007F4", "Eletex Co., Ltd." },
{ "0007E1", "WIS Communications Co. Ltd." },
{ "0007D4", "Zhejiang Yutong Network Communication Co Ltd." },
{ "0007DB", "Kirana Networks, Inc." },
{ "0007D5", "3e Technologies Int;., Inc." },
{ "0005F9", "TOA Corporation" },
{ "0007C5", "Gcom, Inc." },
{ "0007CC", "Kaba Benzing GmbH" },
{ "0007C6", "VDS Vosskuhler GmbH" },
{ "0007B9", "Ginganet Corporation" },
{ "0007BF", "Armillaire Technologies, Inc." },
{ "00047F", "Chr. Mayr GmbH & Co. KG" },
{ "000961", "Switchgear and Instrumentation Ltd" },
{ "00095A", "RACEWOOD TECHNOLOGY" },
{ "000954", "AMiT spol. s. r. o." },
{ "00094E", "BARTECH SYSTEMS INTERNATIONAL, INC" },
{ "000953", "Linkage System Integration Co.Ltd." },
{ "000942", "Wireless Technologies, Inc" },
{ "000947", "Aztek, Inc." },
{ "00093B", "HYUNDAI NETWORKS INC." },
{ "000934", "Dream-Multimedia-Tv GmbH" },
{ "0008BA", "Erskine Systems Ltd" },
{ "0008B4", "SYSPOL" },
{ "0008AE", "PacketFront Network Products AB" },
{ "0008A7", "iLogic Inc." },
{ "0008A2", "ADI Engineering, Inc." },
{ "0008A1", "CNet Technology Inc." },
{ "00089B", "ICP Electronics Inc." },
{ "00088D", "Sigma-Links Inc." },
{ "000893", "LE INFORMATION COMMUNICATION INC." },
{ "00088E", "Nihon Computer Co., Ltd." },
{ "000897", "Quake Technologies" },
{ "000887", "Maschinenfabrik Reinhausen GmbH" },
{ "0008FD", "BlueKorea Co., Ltd." },
{ "0008F5", "YESTECHNOLOGY Co.,Ltd." },
{ "0008EF", "DIBAL,S.A." },
{ "0008EA", "Motion Control Engineering, Inc" },
{ "0008DD", "Telena Communications, Inc." },
{ "0008DE", "3UP Systems" },
{ "0008E3", "Cisco Systems, Inc" },
{ "0008D7", "HOW CORPORATION" },
{ "0008CB", "Zeta Broadband Inc." },
{ "0008D0", "Musashi Engineering Co., LTD." },
{ "0008C1", "Avistar Communications Corporation" },
{ "0008C6", "Philips Consumer Communications" },
{ "000993", "Visteon Corporation" },
{ "000998", "Capinfo Company Limited" },
{ "000986", "Metalink LTD." },
{ "000985", "Auto Telecom Company" },
{ "00098C", "Option Wireless Sweden" },
{ "000980", "Power Zenith Inc." },
{ "000973", "Lenten Technology Co., Ltd." },
{ "000974", "Innopia Technologies, Inc." },
{ "000979", "Advanced Television Systems Committee, Inc." },
{ "000966", "Thales Navigation" },
{ "00096D", "Powernet Technologies Corp." },
{ "00081F", "Pou Yuen Tech Corp. Ltd." },
{ "000826", "Colorado Med Tech" },
{ "000820", "Cisco Systems, Inc" },
{ "000825", "Acme Packet" },
{ "00082C", "Homag AG" },
{ "000819", "Banksys" },
{ "000810", "Key Technology, Inc." },
{ "000813", "Diskbank, Inc." },
{ "00080A", "Espera-Werke GmbH" },
{ "000804", "ICA Inc." },
{ "0007FA", "ITT Co., Ltd." },
{ "0007E7", "FreeWave Technologies" },
{ "0007EE", "telco Informationssysteme GmbH" },
{ "000928", "Telecore" },
{ "00092F", "Akom Technology Corporation" },
{ "000922", "TST Biometrics GmbH" },
{ "000921", "Planmeca Oy" },
{ "00091C", "CacheVision, Inc" },
{ "000910", "Simple Access Inc." },
{ "000915", "CAS Corp." },
{ "00090F", "Fortinet Inc." },
{ "000909", "Telenor Connect A/S" },
{ "000902", "Redline Communications Inc." },
{ "00065E", "Photuris, Inc." },
{ "000645", "Meisei Electric Co. Ltd." },
{ "000644", "neix,Inc" },
{ "00064B", "Alexon Co., Ltd." },
{ "00063B", "Arcturus Networks Inc." },
{ "00063A", "Dura Micro, Inc." },
{ "000634", "GTE Airfone Inc." },
{ "00062A", "Cisco Systems, Inc" },
{ "000627", "Uniwide Technologies, Inc." },
{ "00062E", "Aristos Logic Corp." },
{ "000617", "Redswitch Inc." },
{ "00061E", "Maxan Systems" },
{ "000618", "DigiPower Manufacturing Inc." },
{ "000770", "Ubiquoss Inc" },
{ "00076B", "Stralfors AB" },
{ "00075F", "VCS Video Communication Systems AG" },
{ "000766", "Chou Chin Industrial Co., Ltd." },
{ "000759", "Boris Manufacturing Corp." },
{ "00074C", "Beicom Inc." },
{ "000753", "Beijing Qxcomm Technology Co., Ltd." },
{ "000743", "Chelsio Communications" },
{ "000744", "Unico, Inc." },
{ "000747", "Mecalc" },
{ "000737", "Soriya Co. Ltd." },
{ "00073E", "China Great-Wall Computer Shenzhen Co., Ltd." },
{ "0006C4", "Piolink Inc." },
{ "0006C0", "United Internetworks, Inc." },
{ "0006BA", "Westwave Communications" },
{ "0006AD", "KB Electronics Ltd." },
{ "0006B4", "Vorne Industries, Inc." },
{ "0006AE", "Himachal Futuristic Communications Ltd" },
{ "0006B3", "Diagraph Corporation" },
{ "0006A3", "Bitran Corporation" },
{ "00069D", "Petards Ltd" },
{ "0006A7", "Primarion" },
{ "000657", "Market Central, Inc." },
{ "000697", "R & D Center" },
{ "000691", "PT Inovacao" },
{ "0005C7", "I/F-COM A/S" },
{ "0005CE", "Prolink Microsystems Corporation" },
{ "0005C1", "A-Kyung Motion, Inc." },
{ "0005BB", "Myspace AB" },
{ "00059B", "Cisco Systems, Inc" },
{ "0005A7", "Hyperchip, Inc." },
{ "0005B5", "Broadcom Technologies" },
{ "00059A", "Cisco Systems, Inc" },
{ "0005A1", "Zenocom" },
{ "0005AB", "Cyber Fone, Inc." },
{ "000588", "Sensoria Corp." },
{ "00058E", "Flextronics International GmbH & Co. Nfg. KG" },
{ "000612", "Accusys, Inc." },
{ "000609", "Crossport Systems" },
{ "00060F", "Narad Networks Inc" },
{ "000602", "Cirkitech Electronics Co." },
{ "0005ED", "Technikum Joanneum GmbH" },
{ "000600", "Toshiba Teli Corporation" },
{ "0005E7", "Netrake an AudioCodes Company" },
{ "0005F3", "Webyn" },
{ "0005FA", "IPOptical, Inc." },
{ "0005DE", "Gi Fone Korea, Inc." },
{ "0005DA", "Apex Automationstechnik" },
{ "0005C8", "VERYTECH" },
{ "0005D4", "FutureSmart Networks, Inc." },
{ "0005CD", "Denon, Ltd." },
{ "0006EC", "Harris Corporation" },
{ "0006DF", "AIDONIC Corporation" },
{ "0006E0", "MAT Co., Ltd." },
{ "0006E5", "Fujian Newland Computer Ltd. Co." },
{ "0006DB", "ICHIPS Co., Ltd." },
{ "0006D0", "Elgar Electronics Corp." },
{ "0006D7", "Cisco Systems, Inc" },
{ "0006CA", "American Computer & Digital Components, Inc. (ACDC)" },
{ "000581", "Snell" },
{ "00057B", "Chung Nam Electronic Co., Ltd." },
{ "000582", "ClearCube Technology" },
{ "000577", "SM Information & Communication" },
{ "000571", "Seiwa Electronics Co." },
{ "00056B", "C.P. Technology Co., Ltd." },
{ "000565", "Tailyn Communication Company Ltd." },
{ "00055F", "Cisco Systems, Inc" },
{ "00055E", "Cisco Systems, Inc" },
{ "000558", "Synchronous, Inc." },
{ "000552", "Xycotec Computer GmbH" },
{ "000549", "Salira Optical Network Systems" },
{ "00072B", "Jung Myung Telecom Co., Ltd." },
{ "000731", "Ophir-Spiricon LLC" },
{ "00071A", "Finedigital Inc." },
{ "000721", "Formac Elektronik GmbH" },
{ "00070E", "Cisco Systems, Inc" },
{ "000715", "General Research of Electronics, Inc." },
{ "000708", "Bitrage Inc." },
{ "0006F2", "Platys Communications" },
{ "0006FE", "Ambrado, Inc" },
{ "0006FC", "Fnet Co., Ltd." },
{ "000684", "Biacore AB" },
{ "00068A", "NeuronNet Co. Ltd. R&D Center" },
{ "00067E", "WinCom Systems, Inc." },
{ "000670", "Upponetti Oy" },
{ "000676", "Novra Technologies Inc." },
{ "00067A", "JMP Systems" },
{ "000664", "Fostex Corporation" },
{ "00066A", "InfiniCon Systems, Inc." },
{ "000651", "Aspen Networks Inc." },
{ "00065D", "Heidelberg Web Systems" },
{ "000415", "Rasteme Systems Co., Ltd." },
{ "000408", "Sanko Electronics Co., Ltd." },
{ "000409", "Cratos Networks" },
{ "000402", "Nexsan Technologies, Ltd." },
{ "0003F8", "SanCastle Technologies, Inc." },
{ "0003FF", "Microsoft Corporation" },
{ "0003F1", "Cicada Semiconductor, Inc." },
{ "0003F2", "Seneca Networks" },
{ "0003EC", "ICG Research, Inc." },
{ "0003E6", "Entone, Inc." },
{ "0003DE", "OTC Wireless" },
{ "0003E1", "Winmate Communication, Inc." },
{ "0003DA", "Takamisawa Cybernetics Co., Ltd." },
{ "00054C", "RF Innovations Pty Ltd" },
{ "000543", "IQ Wireless GmbH" },
{ "00053D", "Agere Systems" },
{ "000530", "Andiamo Systems, Inc." },
{ "000537", "Nets Technology Co., Ltd." },
{ "000536", "Danam Communications, Inc." },
{ "000524", "BTL System (HK) Limited" },
{ "00052A", "Ikegami Tsushinki Co., Ltd." },
{ "00051D", "Airocon, Inc." },
{ "000517", "Shellcomm, Inc." },
{ "000513", "VTLinx Multimedia Systems, Inc." },
{ "0004D4", "Proview Electronics Co., Ltd." },
{ "0004CE", "Patria Ailon" },
{ "0004CD", "Extenway Solutions Inc" },
{ "0004C7", "NetMount" },
{ "0004C8", "LIBA Maschinenfabrik GmbH" },
{ "0004C1", "Cisco Systems, Inc" },
{ "0004BB", "Bardac Corporation" },
{ "0004B5", "Equitrac Corporation" },
{ "0004A7", "FabiaTech Corporation" },
{ "0004A1", "Pathway Connectivity" },
{ "00049A", "Cisco Systems, Inc" },
{ "00035B", "BridgeWave Communications" },
{ "000356", "Wincor Nixdorf International GmbH" },
{ "00034B", "Nortel Networks" },
{ "000350", "BTICINO SPA" },
{ "000348", "Norscan Instruments, Ltd." },
{ "000345", "Routrek Networks Corporation" },
{ "00033D", "ILSHin Lab" },
{ "0001EC", "Ericsson Group" },
{ "000331", "Cisco Systems, Inc" },
{ "000338", "Oak Technology" },
{ "000335", "Mirae Technology" },
{ "00032C", "ABB Switzerland Ltd" },
{ "000325", "Arima Computer Corp." },
{ "000453", "YottaYotta, Inc." },
{ "00044D", "Cisco Systems, Inc" },
{ "000449", "Mapletree Networks" },
{ "000443", "Agilent Technologies, Inc." },
{ "00043D", "INDEL AG" },
{ "000431", "GlobalStreams, Inc." },
{ "000436", "ELANsat Technologies, Inc." },
{ "000430", "Netgem" },
{ "00042A", "Wireless Networks, Inc." },
{ "000424", "TMC s.r.l." },
{ "00041B", "Bridgeworks Ltd." },
{ "00041E", "Shikoku Instrumentation Co., Ltd." },
{ "0003D3", "Internet Energy Systems, Inc." },
{ "0003CE", "ETEN Technologies, Inc." },
{ "0003CB", "Nippon Systems Development Co., Ltd." },
{ "0003C2", "Solphone K.K." },
{ "0003C7", "hopf Elektronik GmbH" },
{ "0003BB", "Signal Communications Limited" },
{ "0003B5", "Entra Technology Co." },
{ "0003B0", "Xsense Technology Corp." },
{ "0003A4", "Imation Corp." },
{ "0003A9", "AXCENT Media AG" },
{ "0003AD", "Emerson Energy Systems AB" },
{ "000396", "EZ Cast Co., Ltd." },
{ "00039D", "Qisda Corporation" },
{ "00050D", "Midstream Technologies, Inc." },
{ "000507", "Fine Appliance Corp." },
{ "0004FD", "Japan Control Engineering Co., Ltd." },
{ "0004F7", "Omega Band, Inc." },
{ "0004F1", "WhereNet" },
{ "0004DA", "Relax Technology, Inc." },
{ "008087", "OKI ELECTRIC INDUSTRY CO., LTD" },
{ "0004E0", "Procket Networks" },
{ "000460", "Knilink Technology, Inc." },
{ "000494", "Breezecom, Ltd." },
{ "00048E", "Ohm Tech Labs, Inc." },
{ "000495", "Tejas Networks India Limited" },
{ "000483", "Deltron Technology, Inc." },
{ "000489", "YAFO Networks, Inc." },
{ "000479", "Radius Co., Ltd." },
{ "00046D", "Cisco Systems, Inc" },
{ "000472", "Telelynx, Inc." },
{ "00046C", "Cyber Technology Co., Ltd." },
{ "000466", "ARMITEL Co." },
{ "00045A", "The Linksys Group, Inc." },
{ "00045F", "Avalue Technology, Inc." },
{ "000391", "Advanced Digital Broadcast, Ltd." },
{ "00038A", "America Online, Inc." },
{ "00038E", "Atoga Systems, Inc." },
{ "00037C", "Coax Media" },
{ "000381", "Ingenico International" },
{ "000375", "NetMedia, Inc." },
{ "00036E", "Nicon Systems (Pty) Limited" },
{ "000362", "Vodtel Communications, Inc." },
{ "00031C", "Svenska Hardvarufabriken AB" },
{ "000315", "Cidco Incorporated" },
{ "000310", "E-Globaledge Corporation" },
{ "00030D", "Uniwill Computer Corp." },
{ "000309", "Texcel Technology PLC" },
{ "000304", "Pacific Broadband Communications" },
{ "00019F", "ReadyNet" },
{ "0002FD", "Cisco Systems, Inc" },
{ "0002F6", "Equipe Communications" },
{ "0002F1", "Pinetron Co., Ltd." },
{ "0002EF", "CCC Network Systems Group Ltd." },
{ "0002EB", "Pico Communications" },
{ "0002E6", "Gould Instrument Systems, Inc." },
{ "0002DF", "Net Com Systems, Inc." },
{ "0002D3", "NetBotz, Inc." },
{ "0002D8", "BRECIS Communications Corporation" },
{ "0002CC", "M.C.C.I" },
{ "0002D0", "Comdial Corporation" },
{ "0002C5", "Evertz Microsystems Ltd." },
{ "0002C0", "Bencent Tzeng Industry Co., Ltd." },
{ "0002BD", "Bionet Co., Ltd." },
{ "0002B7", "Watanabe Electric Industry Co., Ltd." },
{ "0002B0", "Hokubu Communication & Industrial Co., Ltd." },
{ "0002A8", "Air Link Technology" },
{ "0002AB", "CTC Union Technologies Co., Ltd." },
{ "0002A4", "AddPac Technology Co., Ltd." },
{ "000299", "Apex, Inc." },
{ "00029D", "Merix Corp." },
{ "000291", "Open Network Co., Ltd." },
{ "00028A", "Ambit Microsystems Corporation" },
{ "000287", "Adapcom" },
{ "00028C", "Micrel-Synergy Semiconductor" },
{ "000282", "ViaClix, Inc." },
{ "00027B", "Amplify Net, Inc." },
{ "00024F", "IPM Datacom S.R.L." },
{ "000274", "Tommy Technologies Corp." },
{ "000276", "Primax Electronics Ltd." },
{ "00026F", "Senao International Co., Ltd." },
{ "000264", "AudioRamp.com" },
{ "00306C", "Hitex Holding GmbH" },
{ "000177", "EDSL" },
{ "000161", "Meta Machine Technology" },
{ "000168", "VITANA CORPORATION" },
{ "000174", "CyberOptics Corporation" },
{ "000164", "Cisco Systems, Inc" },
{ "000170", "ESE Embedded System Engineer'g" },
{ "000152", "CHROMATEK INC." },
{ "000156", "FIREWIREDIRECT.COM, INC." },
{ "00013F", "Neighbor World Co., Ltd." },
{ "000146", "Tesco Controls, Inc." },
{ "000133", "KYOWA Electronic Instruments C" },
{ "0001E3", "Siemens AG" },
{ "0001EA", "Cirilium Corp." },
{ "0001EF", "Camtel Technology Corp." },
{ "0001F2", "Mark of the Unicorn, Inc." },
{ "0001D7", "F5 Networks, Inc." },
{ "0001DC", "Activetelco" },
{ "0001DF", "ISDN Communications, Ltd." },
{ "0001D3", "PAXCOMM, Inc." },
{ "0001C5", "Simpler Networks" },
{ "0001D0", "VitalPoint, Inc." },
{ "0001B2", "Digital Processing Systems, Inc." },
{ "0001C1", "Vitesse Semiconductor Corporation" },
{ "0001BA", "IC-Net, Inc." },
{ "0001B6", "SAEJIN T&M Co., Ltd." },
{ "00022B", "SAXA, Inc." },
{ "000226", "XESystems, Inc." },
{ "00021E", "SIMTEL S.R.L." },
{ "00021A", "Zuma Networks" },
{ "00020B", "Native Networks, Inc." },
{ "000212", "SierraCom" },
{ "000217", "Cisco Systems, Inc" },
{ "000207", "VisionGlobal Network Corp." },
{ "000204", "Bodmann Industries Elektronik GmbH" },
{ "0001F8", "TEXIO TECHNOLOGY CORPORATION" },
{ "0001FF", "Data Direct Networks, Inc." },
{ "0001FB", "DoTop Technology, Inc." },
{ "000268", "Harris Government Communications" },
{ "00025D", "Calix Networks" },
{ "000258", "Flying Packets Communications" },
{ "000257", "Microcom Corp." },
{ "000254", "WorldGate" },
{ "000248", "Pilz GmbH & Co." },
{ "00022E", "TEAC Corp. R& D" },
{ "000241", "Amer.com" },
{ "000232", "Avision, Inc." },
{ "00012A", "Telematica Sistems Inteligente" },
{ "000130", "Extreme Networks" },
{ "000137", "IT Farm Corporation" },
{ "000143", "Cisco Systems, Inc" },
{ "00011B", "Unizone Technologies, Inc." },
{ "000122", "Trend Communications, Ltd." },
{ "00011E", "Precidia Technologies, Inc." },
{ "000108", "AVLAB Technology, Inc." },
{ "00010B", "Space CyberLink, Inc." },
{ "0001AE", "Trex Enterprises" },
{ "0001AA", "Airspan Communications, Ltd." },
{ "000198", "Darim Vision" },
{ "000180", "AOpen, Inc." },
{ "000187", "I2SE GmbH" },
{ "00018F", "Kenetec, Inc." },
{ "000183", "ANITE TELECOMS" },
{ "00019C", "JDS Uniphase Inc." },
{ "000190", "SMK-M" },
{ "0030D1", "INOVA CORPORATION" },
{ "003032", "MagicRam, Inc." },
{ "00305A", "TELGEN CORPORATION" },
{ "003069", "IMPACCT TECHNOLOGY CORP." },
{ "0030EC", "BORGARDT" },
{ "0030B4", "INTERSIL CORP." },
{ "00308E", "CROSS MATCH TECHNOLOGIES, INC." },
{ "0030D0", "Tellabs" },
{ "0030A5", "ACTIVE POWER" },
{ "003009", "Tachion Networks, Inc." },
{ "00302F", "GE Aviation System" },
{ "0030A4", "Woodwind Communications System" },
{ "0030E5", "Amper Datos S.A." },
{ "0030C0", "Lara Technology, Inc." },
{ "00300E", "Klotz Digital AG" },
{ "003094", "Cisco Systems, Inc" },
{ "00309A", "ASTRO TERRA CORP." },
{ "00300C", "CONGRUENCY, LTD." },
{ "0030FD", "INTEGRATED SYSTEMS DESIGN" },
{ "003023", "COGENT COMPUTER SYSTEMS, INC." },
{ "0030DF", "KB/TEL TELECOMUNICACIONES" },
{ "00307D", "GRE AMERICA, INC." },
{ "00D0E4", "Cisco Systems, Inc" },
{ "00D08B", "ADVA Optical Networking Ltd." },
{ "00D098", "Photon Dynamics Canada Inc." },
{ "00D05E", "STRATABEAM TECHNOLOGY, INC." },
{ "00D0BE", "EMUTEC INC." },
{ "00D0F4", "CARINTHIAN TECH INSTITUTE" },
{ "00D0AA", "CHASE COMMUNICATIONS" },
{ "00D0FA", "Thales e-Security Ltd." },
{ "00D006", "Cisco Systems, Inc" },
{ "00D03D", "GALILEO TECHNOLOGY, LTD." },
{ "00D014", "ROOT, INC." },
{ "00D0DD", "SUNRISE TELECOM, INC." },
{ "00D091", "SMARTSAN SYSTEMS, INC." },
{ "00B0EE", "Ajile Systems, Inc." },
{ "00B0E7", "British Federal Ltd." },
{ "00B04A", "Cisco Systems, Inc" },
{ "00B069", "Honewell Oy" },
{ "00B0C2", "Cisco Systems, Inc" },
{ "00B0DF", "Starboard Storage Systems" },
{ "00B0EC", "EACEM" },
{ "003092", "ModuNORM GmbH" },
{ "0030EE", "DSG Technology, Inc." },
{ "003042", "DeTeWe-Deutsche Telephonwerke" },
{ "003099", "BOENIG UND KALLENBACH OHG" },
{ "003051", "ORBIT AVIONIC & COMMUNICATION" },
{ "0030AB", "DELTA NETWORKS, INC." },
{ "003093", "Sonnet Technologies, Inc" },
{ "00303C", "ONNTO CORP." },
{ "0030C7", "Macromate Corp." },
{ "003066", "RFM" },
{ "00307F", "IRLAN LTD." },
{ "003016", "ISHIDA CO., LTD." },
{ "00302A", "SOUTHERN INFORMATION" },
{ "0030DC", "RIGHTECH CORPORATION" },
{ "00D0A4", "ALANTRO COMMUNICATIONS" },
{ "00D043", "ZONAL RETAIL DATA SYSTEMS" },
{ "00D016", "SCM MICROSYSTEMS, INC." },
{ "00D012", "GATEWORKS CORP." },
{ "00D092", "GLENAYRE WESTERN MULTIPLEX" },
{ "00D0C5", "COMPUTATIONAL SYSTEMS, INC." },
{ "0001A7", "UNEX TECHNOLOGY CORPORATION" },
{ "00D0B5", "IPricot formerly DotCom" },
{ "0030E8", "ENSIM CORP." },
{ "0030ED", "Expert Magnetics Corp." },
{ "0030F9", "Sollae Systems Co., Ltd." },
{ "003098", "Global Converging Technologies" },
{ "0030E2", "GARNET SYSTEMS CO., LTD." },
{ "003002", "Expand Networks" },
{ "00300B", "mPHASE Technologies, Inc." },
{ "00308F", "MICRILOR, Inc." },
{ "0030F3", "At Work Computers" },
{ "00D0F9", "ACUTE COMMUNICATIONS CORP." },
{ "00D063", "Cisco Systems, Inc" },
{ "00D069", "TECHNOLOGIC SYSTEMS" },
{ "00D070", "LONG WELL ELECTRONICS CORP." },
{ "00D061", "TREMON ENTERPRISES CO., LTD." },
{ "00D0C4", "TERATECH CORPORATION" },
{ "0030BF", "MULTIDATA GMBH" },
{ "00D0D7", "B2C2, INC." },
{ "00D015", "UNIVEX MICROTECHNOLOGY CORP." },
{ "00D0A5", "AMERICAN ARIUM" },
{ "00D0E5", "SOLIDUM SYSTEMS CORP." },
{ "00D0B3", "DRS Technologies Canada Ltd" },
{ "00D0E9", "Advantage Century Telecommunication Corp." },
{ "00D094", "Seeion Control LLC" },
{ "009045", "Marconi Communications" },
{ "0090F6", "ESCALATE NETWORKS, INC." },
{ "0090EA", "ALPHA TECHNOLOGIES, INC." },
{ "0090FE", "ELECOM CO., LTD.  (LANEED DIV.)" },
{ "0090EB", "SENTRY TELECOM SYSTEMS" },
{ "00908E", "Nortel Networks Broadband Access" },
{ "0090CA", "ACCORD VIDEO TELECOMMUNICATIONS, LTD." },
{ "00908B", "Tattile SRL" },
{ "009099", "ALLIED TELESIS, K.K." },
{ "00900E", "HANDLINK TECHNOLOGIES, INC." },
{ "0090F7", "NBASE COMMUNICATIONS LTD." },
{ "009024", "PIPELINKS, INC." },
{ "009052", "SELCOM ELETTRONICA S.R.L." },
{ "0090E5", "TEKNEMA, INC." },
{ "009085", "GOLDEN ENTERPRISES, INC." },
{ "009019", "HERMES ELECTRONICS CO., LTD." },
{ "0090DC", "TECO INFORMATION SYSTEMS" },
{ "00D0A2", "INTEGRATED DEVICE" },
{ "00D0AE", "ORESIS COMMUNICATIONS, INC." },
{ "00D0D4", "V-BITS, INC." },
{ "00D041", "AMIGO TECHNOLOGY CO., LTD." },
{ "00D0D1", "Sycamore Networks" },
{ "00D0A1", "OSKAR VIERLING GMBH + CO. KG" },
{ "00D00B", "RHK TECHNOLOGY, INC." },
{ "00D02C", "CAMPBELL SCIENTIFIC, INC." },
{ "00D0A0", "MIPS DENMARK" },
{ "00D04E", "LOGIBAG" },
{ "00D0D9", "DEDICATED MICROCOMPUTERS" },
{ "00D0CD", "ATAN TECHNOLOGY INC." },
{ "00D01D", "FURUNO ELECTRIC CO., LTD." },
{ "00D0C7", "PATHWAY, INC." },
{ "00D05C", "KATHREIN TechnoTrend GmbH" },
{ "00D040", "SYSMATE CO., LTD." },
{ "00D08A", "PHOTRON USA" },
{ "00D076", "Bank of America" },
{ "00D07A", "AMAQUEST COMPUTER CORP." },
{ "00D0BB", "Cisco Systems, Inc" },
{ "00D001", "VST TECHNOLOGIES, INC." },
{ "00904C", "Epigram, Inc." },
{ "009000", "DIAMOND MULTIMEDIA" },
{ "009025", "BAE Systems Australia (Electronic Systems) Pty Ltd" },
{ "0090F8", "MEDIATRIX TELECOM" },
{ "009084", "ATECH SYSTEM" },
{ "009054", "INNOVATIVE SEMICONDUCTORS, INC" },
{ "009080", "NOT LIMITED, INC." },
{ "0090C0", "K.J. LAW ENGINEERS, INC." },
{ "0090BC", "TELEMANN CO., LTD." },
{ "00900A", "PROTON ELECTRONIC INDUSTRIAL CO., LTD." },
{ "00904E", "DELEM BV" },
{ "00904A", "CONCUR SYSTEM TECHNOLOGIES" },
{ "009029", "CRYPTO AG" },
{ "009061", "PACIFIC RESEARCH & ENGINEERING CORPORATION" },
{ "0090A9", "WESTERN DIGITAL" },
{ "009006", "HAMAMATSU PHOTONICS K.K." },
{ "009072", "SIMRAD AS" },
{ "005048", "INFOLIBRIA" },
{ "0050EA", "XEL COMMUNICATIONS, INC." },
{ "0050CE", "LG INTERNATIONAL CORP." },
{ "005019", "SPRING TIDE NETWORKS, INC." },
{ "0050AC", "MAPLE COMPUTER CORPORATION" },
{ "005044", "ASACA CORPORATION" },
{ "0050C6", "LOOP TELECOMMUNICATION INTERNATIONAL, INC." },
{ "005049", "Arbor Networks Inc" },
{ "00509F", "HORIZON COMPUTER" },
{ "0050C8", "Addonics Technologies, Inc." },
{ "0050DC", "TAS TELEFONBAU A. SCHWABE GMBH & CO. KG" },
{ "005069", "PixStream Incorporated" },
{ "00901D", "PEC (NZ) LTD." },
{ "00902D", "DATA ELECTRONICS (AUST.) PTY, LTD." },
{ "009007", "DOMEX TECHNOLOGY CORP." },
{ "009048", "ZEAL CORPORATION" },
{ "0090E6", "ALi Corporation" },
{ "009046", "DEXDYNE, LTD." },
{ "00905E", "RAULAND-BORG CORPORATION" },
{ "009067", "WalkAbout Computers, Inc." },
{ "0090DA", "DYNARC, INC." },
{ "009026", "ADVANCED SWITCHING COMMUNICATIONS, INC." },
{ "0090BB", "TAINET COMMUNICATION SYSTEM Corp." },
{ "009033", "INNOVAPHONE AG" },
{ "009010", "SIMULATION LABORATORIES, INC." },
{ "9802D8", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "28FD80", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "B0C5CA", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "E81863", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "00903D", "BIOPAC SYSTEMS, INC." },
{ "009057", "AANetcom, Inc." },
{ "00901C", "mps Software Gmbh" },
{ "009056", "TELESTREAM, INC." },
{ "00907D", "Lake Communications" },
{ "0090DB", "NEXT LEVEL COMMUNICATIONS" },
{ "005042", "SCI MANUFACTURING SINGAPORE PTE, LTD." },
{ "0050C0", "GATAN, INC." },
{ "0050D3", "DIGITAL AUDIO PROCESSING PTY. LTD." },
{ "00509A", "TAG ELECTRONIC SYSTEMS" },
{ "00507D", "IFP" },
{ "0050D0", "MINERVA SYSTEMS" },
{ "005098", "GLOBALOOP, LTD." },
{ "D07650", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "BC6641", "IEEE REGISTRATION AUTHORITY  - Please see MAM public listing for more information." },
{ "0050FA", "OXTEL, LTD." },
{ "005086", "TELKOM SA, LTD." },
{ "0050E1", "NS TECH ELECTRONICS SDN BHD" },
{ "005013", "Chaparral Network Storage" },
{ "005022", "ZONET TECHNOLOGY, INC." },
{ "005040", "Panasonic Electric Works Co., Ltd." },
{ "0050D6", "ATLAS COPCO TOOLS AB" },
{ "005082", "FORESSON CORPORATION" },
{ "0050CA", "NET TO NET TECHNOLOGIES" },
{ "0050A6", "OPTRONICS" },
{ "0050DB", "CONTEMPORARY CONTROL" },
{ "00506B", "SPX-ATEG" },
{ "005074", "ADVANCED HI-TECH CORP." },
{ "005047", "Private" },
{ "005067", "AEROCOMM, INC." },
{ "005024", "NAVIC SYSTEMS, INC." },
{ "005041", "Coretronic Corporation" },
{ "0050D2", "CMC Electronics Inc" },
{ "0090DE", "CARDKEY SYSTEMS, INC." },
{ "009060", "SYSTEM CREATE CORP." },
{ "0090F1", "DOT HILL SYSTEMS CORPORATION" },
{ "0090E2", "DISTRIBUTED PROCESSING TECHNOLOGY" },
{ "00906B", "APPLIED RESOURCES, INC." },
{ "009020", "PHILIPS ANALYTICAL X-RAY B.V." },
{ "009065", "FINISAR CORPORATION" },
{ "001053", "COMPUTER TECHNOLOGY CORP." },
{ "0010A3", "OMNITRONIX, INC." },
{ "00102B", "UMAX DATA SYSTEMS, INC." },
{ "001055", "FUJITSU MICROELECTRONICS, INC." },
{ "00103C", "IC ENSEMBLE, INC." },
{ "0010D9", "IBM JAPAN, FUJISAWA MT+D" },
{ "0010A5", "OXFORD INSTRUMENTS" },
{ "001046", "ALCORN MCBRIDE INC." },
{ "00E0DC", "NEXWARE CORP." },
{ "00E0D9", "TAZMO CO., LTD." },
{ "00E0C2", "NECSY S.p.A." },
{ "00E09B", "ENGAGE NETWORKS, INC." },
{ "00E045", "TOUCHWAVE, INC." },
{ "00E055", "INGENIERIA ELECTRONICA COMERCIAL INELCOM S.A." },
{ "00E037", "CENTURY CORPORATION" },
{ "00E081", "TYAN COMPUTER CORP." },
{ "00E0D4", "EXCELLENT COMPUTER" },
{ "00E01A", "COMTEC SYSTEMS. CO., LTD." },
{ "00E0BC", "SYMON COMMUNICATIONS, INC." },
{ "00E084", "COMPULITE R&D" },
{ "00E0F6", "DECISION EUROPE" },
{ "00E027", "DUX, INC." },
{ "00E07F", "LOGISTISTEM s.r.l." },
{ "00E043", "VitalCom" },
{ "00E0BF", "TORRENT NETWORKING TECHNOLOGIES CORP." },
{ "00E09D", "SARNOFF CORPORATION" },
{ "00E0BB", "NBX CORPORATION" },
{ "00E08A", "GEC AVERY, LTD." },
{ "00E04B", "JUMP INDUSTRIELLE COMPUTERTECHNIK GmbH" },
{ "001015", "OOmon Inc." },
{ "001088", "AMERICAN NETWORKS INC." },
{ "001008", "VIENNA SYSTEMS CORPORATION" },
{ "0010CC", "CLP COMPUTER LOGISTIK PLANUNG GmbH" },
{ "001094", "Performance Analysis Broadband, Spirent plc" },
{ "0010BB", "DATA & INFORMATION TECHNOLOGY" },
{ "001028", "COMPUTER TECHNICA, INC." },
{ "00108A", "TeraLogic, Inc." },
{ "0010C5", "PROTOCOL TECHNOLOGIES, INC." },
{ "00106D", "Axxcelera Broadband Wireless" },
{ "0010FC", "BROADBAND NETWORKS, INC." },
{ "001078", "NUERA COMMUNICATIONS, INC." },
{ "001048", "HTRC AUTOMATION, INC." },
{ "001081", "DPS, INC." },
{ "00102D", "HITACHI SOFTWARE ENGINEERING" },
{ "00109F", "PAVO, INC." },
{ "0010A1", "KENDIN SEMICONDUCTOR, INC." },
{ "001084", "K-BOT COMMUNICATIONS" },
{ "0010AF", "TAC SYSTEMS, INC." },
{ "00100F", "INDUSTRIAL CPU SYSTEMS" },
{ "0010A2", "TNS" },
{ "001000", "CABLE TELEVISION LABORATORIES, INC." },
{ "00103B", "HIPPI NETWORKING FORUM" },
{ "0060C2", "MPL AG" },
{ "0060A2", "NIHON UNISYS LIMITED CO." },
{ "006046", "VMETRO, INC." },
{ "00609D", "PMI FOOD EQUIPMENT GROUP" },
{ "0060BF", "MACRAIGOR SYSTEMS, INC." },
{ "00604A", "SAIC IDEAS GROUP" },
{ "006081", "TV/COM INTERNATIONAL" },
{ "0060B4", "GLENAYRE R&D INC." },
{ "006045", "PATHLIGHT TECHNOLOGIES" },
{ "00A005", "DANIEL INSTRUMENTS, LTD." },
{ "00A053", "COMPACT DEVICES, INC." },
{ "00A033", "imc MeBsysteme GmbH" },
{ "00A059", "HAMILTON HALLMARK" },
{ "00A0AD", "MARCONI SPA" },
{ "00A0F6", "AutoGas Systems Inc." },
{ "00A096", "MITSUMI ELECTRIC CO., LTD." },
{ "00A006", "IMAGE DATA PROCESSING SYSTEM GROUP" },
{ "0060F3", "Performance Analysis Broadband, Spirent plc" },
{ "00600B", "LOGWARE GmbH" },
{ "00603F", "PATAPSCO DESIGNS" },
{ "00607C", "WaveAccess, Ltd." },
{ "00608D", "UNIPULSE CORP." },
{ "006049", "VINA TECHNOLOGIES" },
{ "0060A1", "VPNet, Inc." },
{ "0060C9", "ControlNet, Inc." },
{ "00605F", "NIPPON UNISOFT CORPORATION" },
{ "006021", "DSC CORPORATION" },
{ "00601D", "LUCENT TECHNOLOGIES" },
{ "000800", "MULTITECH SYSTEMS, INC." },
{ "0060C7", "AMATI COMMUNICATIONS CORP." },
{ "00E0CA", "BEST DATA PRODUCTS" },
{ "00E097", "CARRIER ACCESS CORPORATION" },
{ "00E09F", "PIXEL VISION" },
{ "00E0F5", "TELES AG" },
{ "00E070", "DH TECHNOLOGY" },
{ "00E0B5", "ARDENT COMMUNICATIONS CORP." },
{ "00E073", "NATIONAL AMUSEMENT NETWORK, INC." },
{ "00E09E", "QUANTUM CORPORATION" },
{ "00E0E8", "GRETACODER Data Systems AG" },
{ "00E016", "RAPID CITY COMMUNICATIONS" },
{ "00E001", "STRAND LIGHTING LIMITED" },
{ "00E082", "ANERMA" },
{ "00E0EA", "INNOVAT COMMUNICATIONS, INC." },
{ "00E06A", "KAPSCH AG" },
{ "00E023", "TELRAD" },
{ "00E0C3", "SAKAI SYSTEM DEVELOPMENT CORP." },
{ "00601A", "KEITHLEY INSTRUMENTS" },
{ "0060AF", "PACIFIC MICRO DATA, INC." },
{ "00601F", "STALLION TECHNOLOGIES" },
{ "0060B1", "INPUT/OUTPUT, INC." },
{ "00608F", "TEKRAM TECHNOLOGY CO., LTD." },
{ "0060C5", "ANCOT CORP." },
{ "006023", "PERICOM SEMICONDUCTOR CORP." },
{ "006063", "PSION DACOM PLC." },
{ "00604F", "Tattile SRL " },
{ "0060E8", "HITACHI COMPUTER PRODUCTS (AMERICA), INC." },
{ "006072", "VXL INSTRUMENTS, LIMITED" },
{ "006054", "CONTROLWARE GMBH" },
{ "00A0DC", "O.N. ELECTRONIC CO., LTD." },
{ "00A013", "TELTREND LTD." },
{ "00A0DF", "STS TECHNOLOGIES, INC." },
{ "00A061", "PURITAN BENNETT" },
{ "00A0CE", "Ecessa" },
{ "00A02A", "TRANCELL SYSTEMS" },
{ "00A02C", "interWAVE Communications" },
{ "00A077", "FUJITSU NEXION, INC." },
{ "00A020", "CITICORP/TTI" },
{ "00A00D", "THE PANDA PROJECT" },
{ "00A031", "HAZELTINE CORPORATION, MS 1-17" },
{ "00A041", "INFICON" },
{ "0060FA", "EDUCATIONAL TECHNOLOGY RESOURCES, INC." },
{ "000288", "GLOBAL VILLAGE COMMUNICATION" },
{ "0060F9", "DIAMOND LANE COMMUNICATIONS" },
{ "0060EA", "StreamLogic" },
{ "0060EC", "HERMARY OPTO ELECTRONICS INC." },
{ "00604E", "CYCLE COMPUTER CORPORATION, INC." },
{ "00602C", "LINX Data Terminals, Inc." },
{ "006028", "MACROVISION CORPORATION" },
{ "00606A", "MITSUBISHI WIRELESS COMMUNICATIONS. INC." },
{ "00E011", "Uniden Corporation" },
{ "00E021", "FREEGATE CORP." },
{ "00E0AB", "DIMAT S.A." },
{ "00E0B6", "Entrada Networks" },
{ "00E0EC", "CELESTICA INC." },
{ "00E038", "PROXIMA CORPORATION" },
{ "00E090", "BECKMAN LAB. AUTOMATION DIV." },
{ "00E02E", "SPC ELECTRONICS CORPORATION" },
{ "00E0F4", "INSIDE Technology A/S" },
{ "00E03C", "AdvanSys" },
{ "00E096", "SHIMADZU CORPORATION" },
{ "00E0F1", "THAT CORPORATION" },
{ "00A0D0", "TEN X TECHNOLOGY, INC." },
{ "00A0E0", "TENNYSON TECHNOLOGIES PTY LTD" },
{ "00A099", "K-NET LTD." },
{ "00A03D", "OPTO-22" },
{ "00A08C", "MultiMedia LANs, Inc." },
{ "1000E8", "NATIONAL SEMICONDUCTOR" },
{ "006076", "SCHLUMBERGER TECHNOLOGIES RETAIL PETROLEUM SYSTEMS" },
{ "0060AE", "TRIO INFORMATION SYSTEMS AB" },
{ "00606C", "ARESCOM" },
{ "006032", "I-CUBE, INC." },
{ "006060", "Data Innovations North America" },
{ "00A0EB", "Encore Networks, Inc." },
{ "00A0C1", "ORTIVUS MEDICAL AB" },
{ "00A07D", "SEEQ TECHNOLOGY, INC." },
{ "00A0C6", "QUALCOMM INCORPORATED" },
{ "00A0CF", "SOTAS, INC." },
{ "00A03A", "KUBOTEK CORPORATION" },
{ "00A0D7", "KASTEN CHASE APPLIED RESEARCH" },
{ "00A09D", "JOHNATHON FREEMAN TECHNOLOGIES" },
{ "00A036", "APPLIED NETWORK TECHNOLOGY" },
{ "00A0D2", "ALLIED TELESIS INTERNATIONAL CORPORATION" },
{ "00A075", "MICRON TECHNOLOGY, INC." },
{ "00A009", "WHITETREE NETWORK" },
{ "00A060", "ACER PERIPHERALS, INC." },
{ "00A00C", "KINGMAX TECHNOLOGY, INC." },
{ "0020FD", "ITV TECHNOLOGIES, INC." },
{ "00200D", "CARL ZEISS" },
{ "002091", "J125, NATIONAL SECURITY AGENCY" },
{ "002054", "Sycamore Networks" },
{ "0020A7", "PAIRGAIN TECHNOLOGIES, INC." },
{ "0020DA", "Alcatel North America ESD" },
{ "002005", "SIMPLE TECHNOLOGY" },
{ "00202B", "ADVANCED TELECOMMUNICATIONS MODULES, LTD." },
{ "002086", "MICROTECH ELECTRONICS LIMITED" },
{ "002052", "RAGULA SYSTEMS" },
{ "002090", "ADVANCED COMPRESSION TECHNOLOGY, INC." },
{ "0020A3", "Harmonic, Inc" },
{ "00206A", "OSAKA COMPUTER CORP." },
{ "0020DB", "XNET TECHNOLOGY, INC." },
{ "0020A4", "MULTIPOINT NETWORKS" },
{ "00201C", "EXCEL, INC." },
{ "00209B", "ERSAT ELECTRONIC GMBH" },
{ "0020C9", "VICTRON BV" },
{ "0020D1", "MICROCOMPUTER SYSTEMS (M) SDN." },
{ "002084", "OCE PRINTING SYSTEMS, GMBH" },
{ "0020C2", "TEXAS MEMORY SYSTEMS, INC." },
{ "0020C8", "LARSCOM INCORPORATED" },
{ "0020EC", "TECHWARE SYSTEMS CORP." },
{ "002083", "PRESTICOM INCORPORATED" },
{ "00206D", "DATA RACE, INC." },
{ "00203A", "DIGITAL BI0METRICS INC." },
{ "00A06C", "SHINDENGEN ELECTRIC MFG. CO., LTD." },
{ "00A0EE", "NASHOBA NETWORKS" },
{ "00A0FB", "TORAY ENGINEERING CO., LTD." },
{ "00A0E3", "XKL SYSTEMS CORP." },
{ "00A01E", "EST CORPORATION" },
{ "00A080", "Tattile SRL " },
{ "00A0C2", "R.A. SYSTEMS CO., LTD." },
{ "00A0CB", "ARK TELECOMMUNICATIONS, INC." },
{ "00A074", "PERCEPTION TECHNOLOGY" },
{ "00A06A", "Verilink Corporation" },
{ "00A070", "COASTCOM" },
{ "00A079", "ALPS ELECTRIC (USA), INC." },
{ "002059", "MIRO COMPUTER PRODUCTS AG" },
{ "0020BC", "Long Reach Networks Pty Ltd" },
{ "0020AD", "LINQ SYSTEMS" },
{ "002046", "CIPRICO, INC." },
{ "002071", "IBR GMBH" },
{ "0020A2", "GALCOM NETWORKING LTD." },
{ "002098", "HECTRONIC AB" },
{ "002065", "SUPERNET NETWORKING INC." },
{ "002094", "CUBIX CORPORATION" },
{ "0020C3", "COUNTER SOLUTIONS LTD." },
{ "0020A5", "API ENGINEERING" },
{ "002070", "HYNET, LTD." },
{ "00201E", "NETQUEST CORPORATION" },
{ "002097", "APPLIED SIGNAL TECHNOLOGY" },
{ "0020E8", "DATATREK CORPORATION" },
{ "00204F", "DEUTSCHE AEROSPACE AG" },
{ "00202E", "DAYSTAR DIGITAL" },
{ "0020B0", "GATEWAY DEVICES, INC." },
{ "0020A9", "WHITE HORSE INDUSTRIAL" },
{ "002061", "GarrettCom, Inc." },
{ "0020C6", "NECTEC" },
{ "0020D2", "RAD DATA COMMUNICATIONS, LTD." },
{ "00A0F8", "Zebra Technologies Inc" },
{ "00A025", "REDCOM LABS INC." },
{ "00A0D4", "RADIOLAN,  INC." },
{ "00A08A", "BROOKTROUT TECHNOLOGY, INC." },
{ "002093", "LANDINGS TECHNOLOGY CORP." },
{ "002056", "NEOPRODUCTS" },
{ "0020A6", "Proxim Wireless" },
{ "00C073", "XEDIA CORPORATION" },
{ "00C0D4", "AXON NETWORKS, INC." },
{ "00C0E5", "GESPAC, S.A." },
{ "00A0CA", "FUJITSU DENSO LTD." },
{ "00A029", "COULTER CORPORATION" },
{ "00C088", "EKF ELEKTRONIK GMBH" },
{ "00C056", "SOMELEC" },
{ "00C063", "MORNING STAR TECHNOLOGIES, INC" },
{ "00C021", "NETEXPRESS" },
{ "00C049", "U.S. ROBOTICS, INC." },
{ "00C032", "I-CUBED LIMITED" },
{ "00C051", "ADVANCED INTEGRATION RESEARCH" },
{ "00C085", "ELECTRONICS FOR IMAGING, INC." },
{ "00C0FE", "APTEC COMPUTER SYSTEMS, INC." },
{ "00C0E8", "PLEXCOM, INC." },
{ "00C0B2", "NORAND CORPORATION" },
{ "00C0B1", "GENIUS NET CO." },
{ "00C0D9", "QUINTE NETWORK CONFIDENTIALITY" },
{ "00C038", "RASTER IMAGE PROCESSING SYSTEM" },
{ "00C098", "CHUNTEX ELECTRONIC CO., LTD." },
{ "00C0DD", "QLogic Corporation" },
{ "00C08A", "Lauterbach GmbH" },
{ "00409F", "Telco Systems, Inc. " },
{ "0040FF", "TELEBIT CORPORATION" },
{ "0040D7", "STUDIO GEN INC." },
{ "004007", "TELMAT INFORMATIQUE" },
{ "00408D", "THE GOODYEAR TIRE & RUBBER CO." },
{ "00402C", "ISIS DISTRIBUTED SYSTEMS, INC." },
{ "00C03D", "WIESEMANN & THEIS GMBH" },
{ "00C026", "LANS TECHNOLOGY CO., LTD." },
{ "0040E2", "MESA RIDGE TECHNOLOGIES, INC." },
{ "004078", "WEARNES AUTOMATION PTE LTD" },
{ "004062", "E-SYSTEMS, INC./GARLAND DIV." },
{ "0040D2", "PAGINE CORPORATION" },
{ "0040D0", "MITAC INTERNATIONAL CORP." },
{ "0040E4", "E-M TECHNOLOGY, INC." },
{ "0040BF", "CHANNEL SYSTEMS INTERN'L INC." },
{ "004094", "SHOGRAPHICS, INC." },
{ "00407F", "FLIR Systems" },
{ "0040A9", "DATACOM INC." },
{ "00C07D", "RISC DEVELOPMENTS LTD." },
{ "00C01E", "LA FRANCAISE DES JEUX" },
{ "00C084", "DATA LINK CORP. LTD." },
{ "00C087", "UUNET TECHNOLOGIES, INC." },
{ "00C033", "TELEBIT COMMUNICATIONS APS" },
{ "00C081", "METRODATA LTD." },
{ "00C006", "NIPPON AVIONICS CO., LTD." },
{ "00C013", "NETRIX" },
{ "00C058", "DATAEXPERT CORP." },
{ "0040E8", "CHARLES RIVER DATA SYSTEMS,INC" },
{ "004030", "GK COMPUTER" },
{ "0080DC", "PICKER INTERNATIONAL" },
{ "00C0A8", "GVC CORPORATION" },
{ "00C010", "HIRAKAWA HEWTECH CORP." },
{ "00C020", "ARCO ELECTRONIC, CONTROL LTD." },
{ "0040A6", "Cray, Inc." },
{ "004098", "DRESSLER GMBH & CO." },
{ "00C0B9", "FUNK SOFTWARE, INC." },
{ "00C065", "SCOPE COMMUNICATIONS, INC." },
{ "00C018", "LANART CORPORATION" },
{ "00C0FF", "DOT HILL SYSTEMS CORPORATION" },
{ "00400D", "LANNET DATA COMMUNICATIONS,LTD" },
{ "0040F5", "OEM ENGINES" },
{ "004019", "AEON SYSTEMS, INC." },
{ "0040A1", "ERGO COMPUTING" },
{ "00407E", "EVERGREEN SYSTEMS, INC." },
{ "0040F6", "KATRON COMPUTERS INC." },
{ "004076", "Sun Conversion Technologies" },
{ "0040F4", "CAMEO COMMUNICATIONS, INC." },
{ "00C06D", "BOCA RESEARCH, INC." },
{ "00C0DB", "IPC CORPORATION (PTE) LTD." },
{ "00C0DA", "NICE SYSTEMS LTD." },
{ "00C09B", "RELIANCE COMM/TEC, R-TEC" },
{ "00C0B8", "FRASER'S HILL LTD." },
{ "00C016", "ELECTRONIC THEATRE CONTROLS" },
{ "00C096", "TAMURA CORPORATION" },
{ "00C035", "QUINTAR COMPANY" },
{ "00C0CC", "TELESCIENCES CO SYSTEMS, INC." },
{ "00C078", "COMPUTER SYSTEMS ENGINEERING" },
{ "0040F3", "NETCOR" },
{ "004033", "ADDTRON TECHNOLOGY CO., LTD." },
{ "0040A3", "MICROUNITY SYSTEMS ENGINEERING" },
{ "0040ED", "NETWORK CONTROLS INT'NATL INC." },
{ "0040AD", "SMA REGELSYSTEME GMBH" },
{ "0080D2", "SHINNIHONDENKO CO., LTD." },
{ "0080DF", "ADC CODENOLL TECHNOLOGY CORP." },
{ "008071", "SAI TECHNOLOGY" },
{ "00803D", "SURIGIKEN CO.,  LTD." },
{ "00804B", "EAGLE TECHNOLOGIES PTY.LTD." },
{ "008007", "DLOG NC-SYSTEME" },
{ "008001", "PERIPHONICS CORPORATION" },
{ "008062", "INTERFACE  CO." },
{ "0080F3", "SUN ELECTRONICS CORP." },
{ "00808D", "WESTCOAST TECHNOLOGY B.V." },
{ "0080B2", "NETWORK EQUIPMENT TECHNOLOGIES" },
{ "00805B", "CONDOR SYSTEMS, INC." },
{ "00801C", "NEWPORT SYSTEMS SOLUTIONS" },
{ "0080C6", "NATIONAL DATACOMM CORPORATION" },
{ "0080FA", "RWT GMBH" },
{ "008084", "THE CLOUD INC." },
{ "008046", "Tattile SRL " },
{ "0080A6", "REPUBLIC TECHNOLOGY, INC." },
{ "008009", "JUPITER SYSTEMS, INC." },
{ "0080B5", "UNITED NETWORKS INC." },
{ "008035", "TECHNOLOGY WORKS, INC." },
{ "008088", "VICTOR COMPANY OF JAPAN, LTD." },
{ "00809E", "DATUS GMBH" },
{ "008055", "FERMILAB" },
{ "00802A", "TEST SYSTEMS & SIMULATIONS INC" },
{ "0040E3", "QUIN SYSTEMS LTD" },
{ "004091", "PROCOMP INDUSTRIA ELETRONICA" },
{ "004014", "COMSOFT GMBH" },
{ "00400F", "DATACOM TECHNOLOGIES" },
{ "004085", "SAAB INSTRUMENTS AB" },
{ "004006", "SAMPO TECHNOLOGY CORPORATION" },
{ "00402D", "HARRIS ADACOM CORPORATION" },
{ "004047", "WIND RIVER SYSTEMS" },
{ "0040FA", "MICROBOARDS, INC." },
{ "00002E", "SOCIETE EVIRA" },
{ "0000ED", "APRIL" },
{ "00003C", "AUSPEX SYSTEMS INC." },
{ "000051", "HOB ELECTRONIC GMBH & CO. KG" },
{ "0000A7", "NETWORK COMPUTING DEVICES INC." },
{ "0000F7", "YOUTH KEEP ENTERPRISE CO LTD" },
{ "0000FC", "MEIKO" },
{ "0000B5", "DATABILITY SOFTWARE SYS. INC." },
{ "000026", "SHA-KEN CO., LTD." },
{ "000022", "VISUAL TECHNOLOGY INC." },
{ "00006D", "CRAY COMMUNICATIONS, LTD." },
{ "0000FA", "MICROSAGE COMPUTER SYSTEMS INC" },
{ "00002B", "CRISP AUTOMATION, INC" },
{ "000019", "APPLIED DYNAMICS INTERNATIONAL" },
{ "0080D3", "SHIVA CORP." },
{ "0080A5", "SPEED INTERNATIONAL" },
{ "0080A9", "CLEARPOINT RESEARCH" },
{ "008069", "COMPUTONE SYSTEMS" },
{ "008091", "TOKYO ELECTRIC CO.,LTD" },
{ "0080F4", "TELEMECANIQUE ELECTRIQUE" },
{ "00800C", "VIDECOM LIMITED" },
{ "0080E8", "CUMULUS CORPORATIION" },
{ "0000CD", "Allied Telesis Labs Ltd" },
{ "0000A5", "Tattile SRL " },
{ "00801E", "XINETRON, INC." },
{ "00804A", "PRO-LOG" },
{ "008059", "STANLEY ELECTRIC CO., LTD" },
{ "00806B", "SCHMID TELECOMMUNICATION" },
{ "00802C", "THE SAGE GROUP PLC" },
{ "008018", "KOBE STEEL, LTD." },
{ "0080EE", "THOMSON CSF" },
{ "008013", "THOMAS-CONRAD CORPORATION" },
{ "00808E", "RADSTONE TECHNOLOGY" },
{ "000036", "ATARI CORPORATION" },
{ "0080BD", "THE FURUKAWA ELECTRIC CO., LTD" },
{ "0080A8", "VITACOM CORPORATION" },
{ "0080FB", "BVM LIMITED" },
{ "008042", "Artesyn Embedded Technologies" },
{ "008067", "SQUARE D COMPANY" },
{ "008045", "MATSUSHITA ELECTRIC IND. CO" },
{ "00804C", "CONTEC CO., LTD." },
{ "008020", "NETWORK PRODUCTS" },
{ "00809F", "ALE International" },
{ "004044", "QNIX COMPUTER CO., LTD." },
{ "0040DD", "HONG TECHNOLOGIES" },
{ "00403A", "IMPACT TECHNOLOGIES" },
{ "0040C9", "NCUBE" },
{ "004075", "Tattile SRL " },
{ "0080F1", "OPUS SYSTEMS" },
{ "08008F", "CHIPCOM CORPORATION" },
{ "080081", "ASTECH INC." },
{ "08007A", "INDATA" },
{ "080078", "ACCELL CORPORATION" },
{ "08006E", "MASSCOMP" },
{ "08006D", "WHITECHAPEL COMPUTER WORKS" },
{ "08006C", "SUNTEK TECHNOLOGY INT'L" },
{ "080067", "ComDesign" },
{ "080063", "PLESSEY" },
{ "080060", "INDUSTRIAL NETWORKING INC." },
{ "000081", "Bay Networks" },
{ "0000A1", "MARQUETTE ELECTRIC CO." },
{ "0000F5", "DIAMOND SALES LIMITED" },
{ "0000E5", "SIGMEX LTD." },
{ "0000BA", "SIIG, INC." },
{ "00002F", "TIMEPLEX INC." },
{ "0000B8", "SEIKOSHA CO., LTD." },
{ "00007F", "LINOTYPE-HELL AG" },
{ "0000B7", "DOVE COMPUTER CORPORATION" },
{ "00009A", "RC COMPUTER A/S" },
{ "0000DE", "CETIA" },
{ "00004B", "ICL DATA OY" },
{ "000013", "CAMEX" },
{ "000095", "SONY TEKTRONIX CORP." },
{ "080037", "FUJI-XEROX CO. LTD." },
{ "080031", "LITTLE MACHINES INC." },
{ "08002B", "DIGITAL EQUIPMENT CORPORATION" },
{ "08002A", "MOSAIC TECHNOLOGIES INC." },
{ "080029", "Megatek Corporation" },
{ "080026", "NORSK DATA A.S." },
{ "08001F", "SHARP CORPORATION" },
{ "0000AE", "DASSAULT ELECTRONIQUE" },
{ "0000DD", "TCL INCORPORATED" },
{ "0000D9", "NIPPON TELEGRAPH & TELEPHONE" },
{ "000046", "OLIVETTI NORTH AMERICA" },
{ "000017", "Oracle" },
{ "00009F", "AMERISTAR TECHNOLOGIES INC." },
{ "0000E3", "INTEGRATED MICRO PRODUCTS LTD" },
{ "000073", "SIECOR CORPORATION" },
{ "0000D3", "WANG LABORATORIES INC." },
{ "0000B3", "CIMLINC INCORPORATED" },
{ "00009D", "LOCUS COMPUTING CORPORATION" },
{ "000060", "KONTRON ELEKTRONIK GMBH" },
{ "000011", "NORMEREL SYSTEMES" },
{ "08006F", "PHILIPS APELDOORN B.V." },
{ "0000B0", "RND-RAD NETWORK DEVICES" },
{ "00001B", "NOVELL INC." },
{ "000071", "ADRA SYSTEMS INC." },
{ "00006C", "Private" },
{ "AA0000", "DIGITAL EQUIPMENT CORPORATION" },
{ "0270B0", "M/A-COM INC. COMPANIES" },
{ "00000B", "MATRIX CORPORATION" },
{ "080042", "JAPAN MACNICS CORP." },
{ "026086", "LOGIC REPLACEMENT TECH. LTD." },
{ "08000D", "INTERNATIONAL COMPUTERS LTD." },
{ "00DD05", "UNGERMANN-BASS INC." },
{ "00DD0A", "UNGERMANN-BASS INC." },
{ "00BBF0", "UNGERMANN-BASS INC." },
{ "0080E9", "Madge Ltd." },
{ "080055", "STANFORD TELECOMM. INC." },
{ "080048", "EUROTHERM GAUGING SYSTEMS" },
{ "080049", "UNIVATION" },
{ "00DD02", "UNGERMANN-BASS INC." },
{ "000003", "XEROX CORPORATION" },
{ "000008", "XEROX CORPORATION" },
{ "080030", "CERN" },
{ "00DD01", "UNGERMANN-BASS INC." },
{ "18017D", "Harbin Arteor technology co., LTD" },
{ "001CDF", "Belkin International Inc." },
{ "944452", "Belkin International Inc." },
{ "08863B", "Belkin International Inc." },
{ "2082C0", "Xiaomi Communications Co Ltd" },
{ "001556", "Sagemcom Broadband SAS" },
{ "002569", "Sagemcom Broadband SAS" },
{ "001BBF", "Sagemcom Broadband SAS" },
{ "4C17EB", "Sagemcom Broadband SAS" },
{ "7C034C", "Sagemcom Broadband SAS" },
{ "88AE1D", "COMPAL INFORMATION (KUNSHAN) CO., LTD." },
{ "5C353B", "Compal Broadband Networks, Inc." },
{ "C8F230", "GUANGDONG OPPO MOBILE TELECOMMUNICATIONS CORP.,LTD" },
{ "1C4419", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "74F8DB", "IEEE Registration Authority" },
{ "005079", "Private" },
{ "9C93E4", "Private" },
{ "B0D5CC", "Texas Instruments" },
{ "5CF821", "Texas Instruments" },
{ "0CEFAF", "IEEE Registration Authority" },
{ "749DDC", "2Wire Inc" },
{ "782BCB", "Dell Inc." },
{ "B8CA3A", "Dell Inc." },
{ "F01FAF", "Dell Inc." },
{ "C81F66", "Dell Inc." },
{ "00183F", "2Wire Inc" },
{ "0019E4", "2Wire Inc" },
{ "001AC4", "2Wire Inc" },
{ "001D5A", "2Wire Inc" },
{ "34EF44", "2Wire Inc" },
{ "982CBE", "2Wire Inc" },
{ "001422", "Dell Inc." },
{ "001C23", "Dell Inc." },
{ "00219B", "Dell Inc." },
{ "000874", "Dell Inc." },
{ "002564", "Dell Inc." },
{ "842B2B", "Dell Inc." },
{ "E0DB55", "Dell Inc." },
{ "A41F72", "Dell Inc." },
{ "00C04F", "Dell Inc." },
{ "F04DA2", "Dell Inc." },
{ "BC305B", "Dell Inc." },
{ "001D09", "Dell Inc." },
{ "F8E079", "Motorola Mobility LLC, a Lenovo Company" },
{ "1430C6", "Motorola Mobility LLC, a Lenovo Company" },
{ "044E06", "Ericsson AB" },
{ "000D67", "Ericsson" },
{ "E0757D", "Motorola Mobility LLC, a Lenovo Company" },
{ "001E65", "Intel Corporate" },
{ "001F3B", "Intel Corporate" },
{ "0016EA", "Intel Corporate" },
{ "00216B", "Intel Corporate" },
{ "0019D1", "Intel Corporate" },
{ "001CC0", "Intel Corporate" },
{ "5CE0C5", "Intel Corporate" },
{ "183DA2", "Intel Corporate" },
{ "448500", "Intel Corporate" },
{ "809B20", "Intel Corporate" },
{ "100BA9", "Intel Corporate" },
{ "247703", "Intel Corporate" },
{ "C48508", "Intel Corporate" },
{ "0026C6", "Intel Corporate" },
{ "74E50B", "Intel Corporate" },
{ "58946B", "Intel Corporate" },
{ "002710", "Intel Corporate" },
{ "64D4DA", "Intel Corporate" },
{ "DCA971", "Intel Corporate" },
{ "001CBF", "Intel Corporate" },
{ "A0A8CD", "Intel Corporate" },
{ "340286", "Intel Corporate" },
{ "34DE1A", "Intel Corporate" },
{ "80000B", "Intel Corporate" },
{ "B80305", "Intel Corporate" },
{ "303A64", "Intel Corporate" },
{ "ACFDCE", "Intel Corporate" },
{ "E09467", "Intel Corporate" },
{ "00DBDF", "Intel Corporate" },
{ "0C8BFD", "Intel Corporate" },
{ "E09D31", "Intel Corporate" },
{ "CC3D82", "Intel Corporate" },
{ "D00ED9", "Taicang T&W Electronics" },
{ "6C2995", "Intel Corporate" },
{ "40E3D6", "Aruba Networks" },
{ "24DEC6", "Aruba Networks" },
{ "D8C7C8", "Aruba Networks" },
{ "18E3BC", "TCT mobile ltd" },
{ "900BC1", "Sprocomm Technologies CO.,Ltd" },
{ "6C71D9", "AzureWave Technology Inc." },
{ "384FF0", "AzureWave Technology Inc." },
{ "0015AF", "AzureWave Technology Inc." },
{ "485D60", "AzureWave Technology Inc." },
{ "54E4BD", "FN-LINK TECHNOLOGY LIMITED" },
{ "98743D", "Shenzhen Jun Kai Hengye Technology Co. Ltd" },
{ "A04FD4", "ADB Broadband Italia" },
{ "842615", "ADB Broadband Italia" },
{ "5CE2F4", "AcSiP Technology Corp." },
{ "002662", "Actiontec Electronics, Inc" },
{ "00193E", "ADB Broadband Italia" },
{ "0013C8", "ADB Broadband Italia" },
{ "DC0B1A", "ADB Broadband Italia" },
{ "74888B", "ADB Broadband Italia" },
{ "8841FC", "AirTies Wireless Netowrks" },
{ "182861", "AirTies Wireless Netowrks" },
{ "84D6D0", "Amazon Technologies Inc." },
{ "E0CB1D", "Private" },
{ "ACD074", "Espressif Inc." },
{ "D05349", "Liteon Technology Corporation" },
{ "00BB3A", "Private" },
{ "000941", "Allied Telesis R&D Center K.K." },
{ "984B4A", "ARRIS Group, Inc." },
{ "00014A", "Sony Corporation" },
{ "001CA4", "Sony Mobile Communications AB" },
{ "002345", "Sony Mobile Communications AB" },
{ "8C6422", "Sony Mobile Communications AB" },
{ "90C115", "Sony Mobile Communications AB" },
{ "8400D2", "Sony Mobile Communications AB" },
{ "5CB524", "Sony Mobile Communications AB" },
{ "0015A3", "ARRIS Group, Inc." },
{ "0015A4", "ARRIS Group, Inc." },
{ "94A1A2", "AMPAK Technology, Inc." },
{ "00D088", "ARRIS Group, Inc." },
{ "0017EE", "ARRIS Group, Inc." },
{ "001180", "ARRIS Group, Inc." },
{ "00909C", "ARRIS Group, Inc." },
{ "8096B1", "ARRIS Group, Inc." },
{ "7CBFB1", "ARRIS Group, Inc." },
{ "001A77", "ARRIS Group, Inc." },
{ "CC7D37", "ARRIS Group, Inc." },
{ "0017E2", "ARRIS Group, Inc." },
{ "001784", "ARRIS Group, Inc." },
{ "0016B5", "ARRIS Group, Inc." },
{ "001675", "ARRIS Group, Inc." },
{ "74DE2B", "Liteon Technology Corporation" },
{ "68A3C4", "Liteon Technology Corporation" },
{ "002210", "ARRIS Group, Inc." },
{ "001FC4", "ARRIS Group, Inc." },
{ "001C12", "ARRIS Group, Inc." },
{ "001CFB", "ARRIS Group, Inc." },
{ "0012C9", "ARRIS Group, Inc." },
{ "E48399", "ARRIS Group, Inc." },
{ "00211E", "ARRIS Group, Inc." },
{ "0024A0", "ARRIS Group, Inc." },
{ "002636", "ARRIS Group, Inc." },
{ "C8FF28", "Liteon Technology Corporation" },
{ "0024D2", "ASKEY COMPUTER CORP" },
{ "DC64B8", "Shenzhen JingHanDa Electronics Co.Ltd" },
{ "C4DA7D", "Ivium Technologies B.V." },
{ "9492BC", "SYNTECH(HK) TECHNOLOGY LIMITED" },
{ "001A4F", "AVM GmbH" },
{ "00040E", "AVM GmbH" },
{ "0016E3", "ASKEY COMPUTER CORP" },
{ "30469A", "NETGEAR" },
{ "0026F2", "NETGEAR" },
{ "00184D", "NETGEAR" },
{ "001E2A", "NETGEAR" },
{ "E8FCAF", "NETGEAR" },
{ "4C60DE", "NETGEAR" },
{ "00300A", "Aztech Electronics Pte Ltd" },
{ "A06391", "NETGEAR" },
{ "9CC7A6", "AVM GmbH" },
{ "DCEF09", "NETGEAR" },
{ "743170", "Arcadyan Technology Corporation" },
{ "A8D3F7", "Arcadyan Technology Corporation" },
{ "7C4FB5", "Arcadyan Technology Corporation" },
{ "0012BF", "Arcadyan Technology Corporation" },
{ "200CC8", "NETGEAR" },
{ "04FE8D", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "480031", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "0019FB", "BSkyB Ltd" },
{ "0CF9C0", "BSkyB Ltd" },
{ "001BA9", "Brother industries, LTD." },
{ "0011B6", "Open Systems International" },
{ "002283", "Juniper Networks" },
{ "2C6BF5", "Juniper Networks" },
{ "64649B", "Juniper Networks" },
{ "541E56", "Juniper Networks" },
{ "E03E44", "Broadcom" },
{ "D40129", "Broadcom" },
{ "544B8C", "Juniper Networks" },
{ "84B59C", "Juniper Networks" },
{ "100E7E", "Juniper Networks" },
{ "288A1C", "Juniper Networks" },
{ "FCB698", "Cambridge Industries(Group) Co.,Ltd." },
{ "3C94D5", "Juniper Networks" },
{ "B0A86E", "Juniper Networks" },
{ "AC4BC8", "Juniper Networks" },
{ "00E03A", "Cabletron Systems, Inc." },
{ "002159", "Juniper Networks" },
{ "000117", "Canal +" },
{ "0019C7", "Cambridge Industries(Group) Co.,Ltd." },
{ "006DFB", "Vutrix Technologies Ltd" },
{ "C81073", "CENTURY OPTICOMM CO.,LTD" },
{ "744AA4", "zte corporation" },
{ "9CD35B", "Samsung Electronics Co.,Ltd" },
{ "60AF6D", "Samsung Electronics Co.,Ltd" },
{ "B85A73", "Samsung Electronics Co.,Ltd" },
{ "103047", "Samsung Electronics Co.,Ltd" },
{ "109266", "Samsung Electronics Co.,Ltd" },
{ "B047BF", "Samsung Electronics Co.,Ltd" },
{ "7C0BC6", "Samsung Electronics Co.,Ltd" },
{ "804E81", "Samsung Electronics Co.,Ltd" },
{ "244B81", "Samsung Electronics Co.,Ltd" },
{ "50A4C8", "Samsung Electronics Co.,Ltd" },
{ "8425DB", "Samsung Electronics Co.,Ltd" },
{ "D8C4E9", "Samsung Electronics Co.,Ltd" },
{ "50C8E5", "Samsung Electronics Co.,Ltd" },
{ "446D6C", "Samsung Electronics Co.,Ltd" },
{ "38D40B", "Samsung Electronics Co.,Ltd" },
{ "647791", "Samsung Electronics Co.,Ltd" },
{ "781FDB", "Samsung Electronics Co.,Ltd" },
{ "08FC88", "Samsung Electronics Co.,Ltd" },
{ "30C7AE", "Samsung Electronics Co.,Ltd" },
{ "18227E", "Samsung Electronics Co.,Ltd" },
{ "00F46F", "Samsung Electronics Co.,Ltd" },
{ "BC1485", "Samsung Electronics Co.,Ltd" },
{ "9CE6E7", "Samsung Electronics Co.,Ltd" },
{ "380195", "Samsung Electronics Co.,Ltd" },
{ "5CF6DC", "Samsung Electronics Co.,Ltd" },
{ "1077B1", "Samsung Electronics Co.,Ltd" },
{ "508569", "Samsung Electronics Co.,Ltd" },
{ "0090A2", "CyberTAN Technology Inc." },
{ "0030DA", "Comtrend Corporation" },
{ "64680C", "Comtrend Corporation" },
{ "00CF1C", "Communication Machinery Corporation" },
{ "0090F5", "CLEVO CO." },
{ "0030FF", "DataFab Systems Inc." },
{ "E498D1", "Microsoft Mobile Oy" },
{ "A8A089", "Tactical Communications" },
{ "48365F", "Wintecronics Ltd." },
{ "005A39", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "5CC6D0", "Skyworth Digital Technology(Shenzhen) Co.,Ltd" },
{ "080581", "Roku, Inc." },
{ "B0A737", "Roku, Inc." },
{ "B83E59", "Roku, Inc." },
{ "DC3A5E", "Roku, Inc." },
{ "0014A5", "Gemtek Technology Co., Ltd." },
{ "001742", "FUJITSU LIMITED" },
{ "2C10C1", "Nintendo Co., Ltd." },
{ "CCFB65", "Nintendo Co., Ltd." },
{ "40D28A", "Nintendo Co., Ltd." },
{ "7CBB8A", "Nintendo Co., Ltd." },
{ "00224C", "Nintendo Co., Ltd." },
{ "0023CC", "Nintendo Co., Ltd." },
{ "002444", "Nintendo Co., Ltd." },
{ "E0E751", "Nintendo Co., Ltd." },
{ "0017AB", "Nintendo Co., Ltd." },
{ "001BEA", "Nintendo Co., Ltd." },
{ "48F7C0", "Cisco SPVTG" },
{ "0015DE", "Nokia Danmark A/S" },
{ "001370", "Nokia Danmark A/S" },
{ "00247C", "Nokia Danmark A/S" },
{ "0023B4", "Nokia Danmark A/S" },
{ "0021AB", "Nokia Danmark A/S" },
{ "001FDF", "Nokia Danmark A/S" },
{ "00194F", "Nokia Danmark A/S" },
{ "00188D", "Nokia Danmark A/S" },
{ "00180F", "Nokia Danmark A/S" },
{ "547975", "Nokia Corporation" },
{ "2CCC15", "Nokia Corporation" },
{ "00BD3A", "Nokia Corporation" },
{ "0026CC", "Nokia Danmark A/S" },
{ "00164E", "Nokia Danmark A/S" },
{ "0016BC", "Nokia Danmark A/S" },
{ "001ADC", "Nokia Danmark A/S" },
{ "002668", "Nokia Danmark A/S" },
{ "001F5C", "Nokia Danmark A/S" },
{ "001F00", "Nokia Danmark A/S" },
{ "001E3B", "Nokia Danmark A/S" },
{ "A04E04", "Nokia Corporation" },
{ "240B0A", "Palo Alto Networks" },
{ "C4E510", "Mechatro, Inc." },
{ "74C330", "SHENZHEN FAST TECHNOLOGIES CO.,LTD" },
{ "403F8C", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "14C3C2", "K.A. Schmersal GmbH & Co. KG" },
{ "10785B", "Actiontec Electronics, Inc" },
{ "20768F", "Apple, Inc." },
{ "C0C522", "ARRIS Group, Inc." },
{ "9C5CF9", "Sony Mobile Communications AB" },
{ "88A084", "Formation Data Systems" },
{ "0025DC", "Sumitomo Electric Industries,Ltd" },
{ "001CFC", "Sumitomo Electric Industries,Ltd" },
{ "00D0EC", "NAKAYO TELECOMMUNICATIONS,INC" },
{ "8CC661", "Current, powered by GE" },
{ "009050", "Teleste Corporation" },
{ "BC44B0", "Elastifile" },
{ "7864E6", "Green Motive Technology Limited" },
{ "743E2B", "Ruckus Wireless" },
{ "C0CCF8", "Apple, Inc." },
{ "80ED2C", "Apple, Inc." },
{ "E8B2AC", "Apple, Inc." },
{ "FCF152", "Sony Computer Entertainment Inc." },
{ "0080B8", "DMG MORI B.U.G. CO., LTD." },
{ "8489AD", "Apple, Inc." },
{ "40B688", "LEGIC Identsystems AG" },
{ "A09D91", "SoundBridge" },
{ "30785C", "Partow Tamas Novin (Parman)" },
{ "0C54B9", "Alcatel-Lucent" },
{ "C4084A", "Alcatel-Lucent" },
{ "34AA99", "Alcatel-Lucent" },
{ "441102", "EDMI  Europe Ltd" },
{ "2C21D7", "IMAX Corporation" },
{ "0026F7", "Nivetti Systems Pvt. Ltd." },
{ "24C3F9", "Securitas Direct AB" },
{ "DC4D23", "MRV Comunications" },
{ "085BDA", "CliniCare LTD" },
{ "00248D", "Sony Computer Entertainment Inc." },
{ "0C5A9E", "Wi-SUN Alliance" },
{ "00C164", "Cisco Systems, Inc" },
{ "C4BED4", "Avaya Inc" },
{ "98E7F5", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "24BCF8", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "10D0AB", "zte corporation" },
{ "202DF8", "Digital Media Cartridge Ltd." },
{ "042DB4", "First Property (Beijing) Co., Ltd Modern MOMA Branch" },
{ "008A96", "Cisco Systems, Inc" },
{ "007888", "Cisco Systems, Inc" },
{ "98DED0", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "30FC68", "TP-LINK TECHNOLOGIES CO.,LTD." },
{ "5CCA1A", "Microsoft Mobile Oy" },
{ "EC13DB", "Juniper Networks" },
{ "000594", "HMS Industrial Networks" },
{ "000AC2", "Wuhan FiberHome Digital Technology Co.,Ltd." },
{ "F08CFB", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "D4F207", "DIAODIAO(Beijing)Technology CO.,Ltd" },
{ "FCF8B7", "TRONTEQ Electronic" },
{ "FC0F4B", "Texas Instruments" },
{ "D4883F", "HDPRO CO., LTD." },
{ "001BF3", "TRANSRADIO SenderSysteme Berlin AG" },
{ "E0071B", "Hewlett Packard Enterprise" },
{ "A86AC1", "HanbitEDS Co., Ltd." },
{ "40163B", "Samsung Electronics Co.,Ltd" },
{ "88B1E1", "Mojo Networks, Inc." },
{ "74DFBF", "Liteon Technology Corporation" },
{ "FC3F7C", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "608334", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "84AD58", "HUAWEI TECHNOLOGIES CO.,LTD" },
{ "746FF7", "Wistron Neweb Corporation" },
{ "B01BD2", "Le Shi Zhi Xin Electronic Technology (Tianjin) Limited" },
{ "74852A", "PEGATRON CORPORATION" },
{ "386077", "PEGATRON CORPORATION" },
{ "60B4F7", "Plume Design Inc" },
{ "A4D8CA", "HONG KONG WATER WORLD TECHNOLOGY CO. LIMITED" },
{ "00109B", "Emulex Corporation" },
{ "00E0D5", "Emulex Corporation" },
{ "001035", "Elitegroup Computer Systems Co.,Ltd." },
{ "ECA86B", "Elitegroup Computer Systems Co.,Ltd." },
{ "4487FC", "Elitegroup Computer Systems Co.,Ltd." },
{ "002197", "Elitegroup Computer Systems Co.,Ltd." },
{ "649968", "Elentec" },
{ "00208F", "ECI Telecom Ltd." },
{ "9CDF03", "Harman/Becker Automotive Systems GmbH" },
{ "F0407B", "Fiberhome Telecommunication Technologies Co.,LTD" },
{ "94885E", "Surfilter Network Technology Co., Ltd. " },
{ "002378", "GN Netcom A/S" },
{ "002088", "GLOBAL VILLAGE COMMUNICATION" },
{ "90C7D8", "zte corporation" },
{ "BC6A44", "Commend International GmbH" },
{ "0020F2", "Oracle Corporation " },
{ "00015D", "Oracle Corporation " },
{ "F8DA0C", "Hon Hai Precision Ind. Co.,Ltd." },
{ NULL, NULL }
};
