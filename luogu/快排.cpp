#include <iostream>
#include <cstring>
#include <algorithm>
using  namespace std;
void quicksort(int i,int j,int *arr){
	if (i>=j)return;
	int left=i,right=j,base=arr[i];
	while (left<right){
		while (arr[right]>=base&&left<right)right--;
		while (arr[left]<=base&&left<right)left++;
		if (left<right){int temp=arr[left];arr[left]=arr[right];arr[right]=temp;}
	}
	arr[i]=arr[left];arr[left]=base;
	quicksort(i,left-1,arr);
	quicksort(left+1,j,arr);
}

int cmp(const void *a,const void *b){
	return (*(int*)a)-(*(int*)b);
} 


int main (){
	int arr[999]={940,1779,1131,1082,1836,213,1983,1390,716,198,296,281,1926,922,1344,1268,1921,305,1832,1668,897,1286,1467,575,880,439,278,1927,1786,1631,1805,1093,2,1788,117,1639,606,827,831,422,949,1974,353,1106,1,718,1453,489,1726,1880,148,998,375,324,391,782,1885,1333,916,1035,702,1217,1538,577,183,535,1160,769,389,841,1557,827,1192,148,1593,1601,1790,1399,161,1749,905,1625,1828,1266,50,732,1110,1580,125,338,943,663,918,796,164,566,1937,1796,1017,1232,1181,332,306,363,743,620,1755,277,1964,393,982,746,957,551,806,291,1711,307,1573,922,1061,1885,1805,202,1856,1812,1007,1836,84,1681,1229,1747,298,798,816,715,444,293,1043,1863,1063,150,1890,1953,327,1987,1961,489,1544,1131,174,841,172,1112,1811,1329,1848,659,38,929,749,725,1914,562,1649,1192,986,1121,372,1618,1979,1819,1780,1587,99,37,402,1624,384,1163,837,1773,1937,1945,713,594,1882,1665,801,1899,607,1024,1287,192,1917,1388,1203,983,1711,1882,554,1847,1517,304,1330,231,388,848,707,44,589,1589,1051,1691,1044,377,1991,743,741,1384,1319,1289,1894,1137,1659,1083,1112,1566,497,1548,893,1701,1446,1166,1493,854,1431,725,255,1830,182,1809,413,489,459,394,1018,941,996,1052,1639,732,984,603,311,440,1390,799,577,858,1919,146,37,1639,139,1274,1326,213,870,1787,760,1475,1077,405,1125,1174,897,200,1959,1990,1455,858,1218,1600,1796,319,1495,1545,1236,362,1695,1019,1902,1121,631,1737,1994,743,1598,391,1172,704,1184,45,201,212,1603,882,738,1594,1558,1644,953,1704,775,739,508,219,1975,525,1853,1880,1306,1457,1253,55,395,432,738,1066,1661,1981,497,645,613,1799,478,493,1412,1532,1564,524,611,198,792,108,1822,162,1772,1250,1843,943,938,1078,565,393,1731,675,1658,178,733,120,778,1648,1421,971,402,23,1751,604,1924,792,1004,368,511,1280,974,1594,807,36,843,1921,1924,1252,567,1626,1347,1142,443,1323,420,1105,1,1435,1464,955,32,1800,1683,1866,765,1999,1561,1570,961,55,200,1286,1059,260,920,875,1862,303,1359,1917,899,1238,285,1352,132,1266,1281,1343,895,1112,994,1013,121,747,1153,1795,98,704,1138,420,422,1749,50,1618,1834,1288,152,467,1675,539,607,78,444,630,473,581,1221,1343,1089,1620,542,704,1184,311,47,1213,1650,109,1056,1207,1287,1045,1482,494,1758,996,1043,294,1203,1106,645,1458,32,1925,1820,462,1440,1882,1639,460,1752,591,213,290,1387,951,982,781,809,1641,1232,1213,1112,1251,1108,591,250,1356,1351,1368,422,647,646,304,1659,611,757,215,207,1485,1033,1239,1076,1435,751,1416,1097,1044,1689,737,1555,370,741,1690,541,414,364,292,306,74,1467,1194,1389,217,144,1494,941,1447,744,1999,1783,1886,331,159,998,33,1751,1126,442,799,1359,857,1966,470,1178,1744,567,605,1739,390,1612,1889,545,1007,1944,476,621,114,853,1792,3,984,510,263,486,1576,910,1263,1605,1954,1571,1920,1227,753,94,542,1054,1852,545,1726,724,672,1775,800,1359,165,1911,539,1259,323,1849,1118,1070,309,1419,1942,820,90,1238,1497,1983,41,1737,179,1691,1041,1441,1109,984,868,829,94,1125,865,341,904,1641,1514,1958,1443,259,1913,1378,145,258,1267,24,1438,1733,1330,1064,1517,1854,925,505,459,1483,642,472,1500,1460,1716,699,1642,1207,300,1036,1158,28,923,1134,1595,693,811,474,225,497,1790,8,449,1006,983,1627,394,410,1628,809,920,228,1030,1028,1280,1599,1632,789,105,675,640,1995,889,1097,85,724,644,1499,1265,62,1622,1464,1734,138,23,1527,1428,501,1257,1719,937,1640,1589,712,1281,1384,1398,1738,407,42,1648,930,1858,542,1054,883,468,1915,1066,311,1123,1179,46,372,84,231,175,738,1370,766,1587,803,888,1716,1919,829,1911,869,1657,1962,754,877,1958,541,822,1236,753,641,1533,944,1388,288,679,1466,1593,1091,1120,903,1,1428,1559,732,861,1518,440,156,545,27,450,361,1226,1702,1036,55,1855,519,1116,745,1328,1405,1007,629,766,137,1854,536,1920,325,152,86,790,339,878,1378,1049,1422,123,950,1560,426,429,1938,925,337,1642,1634,411,1443,615,1872,1626,945,593,674,562,616,606,1937,956,1503,1109,469,621,57,661,1838,807,820,242,1133,425,1376,725,387,142,354,613,1725,4,862,1157,805,98,1281,460,1526,625,326,314,1588,1172,1633,1742,1713,192,1138,857,1994,926,1483,1748,632,1189,1173,1570,11,1300,1949,1568,1635,1992,486,801,725,245,964,879,921,1375,1276,1362,1144,348,674,920,1391,1431,750,1561,344,951,1759,106,506,789,565,510,935,1188,1810,721,812,408,1915,401,1459,1037,1767,1879,998,1286,1172,256,1262,39,455,1967,1167,1003,5,1542,1534,1064,681,858,7,1733,1029,545,1551,1794,240,832,789,602,785,717,1378,1125,464,1970,1987,306,1391,1655,1266,1195,294,275,716,1908,1201,1818,1231,1417,11,1670,1946,888,131,633,1035,1640,282,1692,1542,219,115,1458,306,151,114,544,1206,1747,950,1948,659,68,822,1,464,811,1263,929,90};
	//quicksort(0,998,arr);
	//sort(arr,arr+999);
	//qsort(arr,999,sizeof(int),cmp);
	//for (int i=0;i<=998;i++)printf("%d\n",arr[i]);
	
	return 0;
} 
