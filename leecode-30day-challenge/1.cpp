// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// class Solution {
// public:
//     int *visit;
//     int t;
//     int **arr;
//     int cnt = 0;
//     int size;
//     int numWays(int n, vector<vector<int>>& relation, int k) {
//         arr = new int*[n];
//         visit = new int[n];
//         size = n;
//         for (int i = 0; i < n; i++) {
//             visit[i] = 0;
//             arr[i] = new int[n];
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++)
//                 arr[i][j] = 0;
//         }
//         for (int i = 0; i < relation.size(); i++) {
//             arr[relation[i][0]][relation[i][1]] = 1;
//             //arr[relation[i][1]][relation[i][0]] = 1;
//         }
//         t = k;

//         dfs(n-1);
//         // for (int m = 0; m < k; m++) {
//         //     for (int i = 0; i < n; i++) {
//         //         for (int j = 0; i < n; j++) {
//         //             if ()
//         //         }
//         //     }
//         // }

//         return cnt;
//     }

//     void dfs (int u){
//         visit[u] = 1;
//         if (u == t) {
//             cnt++;
//         }
//         for (int i = 0; i < size; i++) {
//             if (visit[i] == false && arr[u][i] == 1) {
//                 dfs(i);
//             }
//         }
//     }

// };

// class Solution_1 {
// public:
//     int numWays(int n, vector<vector<int>>& relation, int k) {
//         map<int, vector<int> rel;
//         for (int i = 0; i < n; i++)
//             rel.insert(make_pair(0, vector<int>()));
//         for (int i = 0; i < relation.size(); i++) {
//             for (int j = 0; j < relation[i].size(); j++)
//                 rel[relation[i][0]].push_back(relation[i][1]);
//         }
//         int cnt = 0;
//         while (k) {
//             for (int i = 0;i < n; i++) {
//                 next = rel[next][i];
//                 if (next == (n-1)) cnt++;
//             }
//         }
//     }
// };

// int main(int argc, char const *argv[]) {
//     Solution_1 sol;
//     vector<vector<int>> relation;
//     vector<int> tmp;
//     tmp.push_back(0);
//     tmp.push_back(2);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(2);
//     tmp.push_back(1);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(3);
//     tmp.push_back(4);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(2);
//     tmp.push_back(3);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(1);
//     tmp.push_back(4);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(2);
//     tmp.push_back(0);
//     relation.push_back(tmp);
//     tmp.clear();
//     tmp.push_back(0);
//     tmp.push_back(4);
//     relation.push_back(tmp);
//     // relation.push_back();
//     // relation.push_back();
//     // relation.push_back();
//     // relation.push_back();
//     // relation.push_back();
//     cout << sol.numWays(5, relation, 3) << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>
# define PI 3.1415926
using namespace std;

struct MeasureResult
{
    float distance;
    float yaw;
    float pitch;
};

// 计算距离
// x为在第y行laser在图像上中心点的位置
// x等于公式中的px
void calcDistanceByPos( float x, int y, int img_height, MeasureResult * result)
{
/*
       dist = a/(b-c*x)+d
*/
    const float a = 698.1; // a = fs 焦距 乘以 摄像头与激光的距离，4.2mm*160mm=672，如果s就是baseline，那焦距就是6um*100，100为s和baseline
    const float b = 4.354;  // 这个可能是整个摄像头传感器宽度的实际尺寸，640*PixelSize，假设分辨率为640*480
    const float c = 0.006912; // 像素点的大小，PixelSize
    const float d = -40.88; // d是校正的补偿量，修补测得距离的系统误差，计算时不需要，且每个人校正算法不同也未必会有这个。可以不用理会
    
    const float baseline = 100.0;

    const float laser_angle = 1.486407302; // 这个是对应图片中的beta角度，计算值=83°/180°* PI
    const float rotation_r  = 49.2; // 旋转中心到激光的距离，这里是旋转轴的一半左右

	// d'=f'baseline/x .... (6)
    const float focal = a/baseline; // focal是焦距的意思，那这样的话是

	// d=fs/(PixelSize*px+offset)/sin(beta) .... (4)
    float center_distance = a/(b-c*x); // 这个对应的是d'，也是三角形解释中的q
    //cout << "center distance: " << center_distance << endl;

	// f'=f/cos(arctan((P2'.y-P1'.y)/f)) .... (7)
	// y - img_height/2表示的是P2'.y-P1'.y，然后需要转化成实际的距离信息，所以下式中还要乘以像素大小c
    float pitch_angle = atan(((y - img_height/2)*c)/(focal)); // atan为反正切函数函数，arctan，计算出像素点与中心位置的俯仰角度
    float pitch_distance = center_distance/cos(pitch_angle);
    
    float laser_to_dist_pt = center_distance*tan(PI/2 - laser_angle); // laser_to_dist_pt对应的原理中d'的垂足的位置到激光的距离
    float laser_to_current_pt = sqrt(pitch_distance*pitch_distance + laser_to_dist_pt*laser_to_dist_pt);
    float laser_to_center_pt  = sqrt(center_distance*center_distance + laser_to_dist_pt*laser_to_dist_pt);


    float real_center_distance = sqrt( (laser_to_dist_pt-rotation_r)*(laser_to_dist_pt-rotation_r) +  center_distance*center_distance); // 图像中心位置的距离
    float yaw_angle = PI/2 - acos((rotation_r*rotation_r + 
		                           real_center_distance*real_center_distance - 
		                           laser_to_center_pt*laser_to_center_pt)
		                           /2.0f/rotation_r/real_center_distance); // 这里用到余弦定理求角度
 

    float real_distance = sqrt( (laser_to_dist_pt-rotation_r)*(laser_to_dist_pt-rotation_r) +  pitch_distance*pitch_distance);

    result->distance = real_distance;
    result->yaw = yaw_angle; // yaw偏航角
    result->pitch = pitch_angle -18.0*PI/180.0f; // pitch俯仰角， -18.0*PI/180.0f”是测距定标时所产生的修正量
}


int main(int argc, char const *argv[]) {
    MeasureResult result = { 0, 0, 0};
    float * laserDotArr = new float[480];
    for (int i = 0; i < 480; i++)
        laserDotArr[i] = 503.58;
    calcDistanceByPos(laserDotArr[0], 0, 480, &result);
    printf("%.2f %.2f %.2f\n", result.distance, result.yaw * 180.0f/PI , result.pitch* 180.0f/PI);
    return 0;
}