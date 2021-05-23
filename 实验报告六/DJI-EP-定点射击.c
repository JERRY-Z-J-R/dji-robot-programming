    // DJI-EP-定点射击
    // 周吉瑞 2021/05/10
    // 伪代码（C语言风格）
    
    // 全局变量
    double turret_height = 0.30;    // 炮塔高度（30cm）
    double x0 = 0;                  // 原点 x 坐标（默认为 0）
    double y0 = 0;                  // 原点 y 坐标（默认为 0）
    double x;                       // 目标点 x 坐标
    double y;                       // 目标点 y 坐标
    double a;                       // 原点与目标点的 x 坐标差值
    double b;                       // 原点与目标点的 y 坐标差值
    double h_angle;                 // 待旋转的航向角
    double f_angle;                 // 待旋转的俯仰角
    
    main() {
        setSport(freedom);          // 设置整机运动（自由模式）
        setRotateSpeed(180);        // 设置云台旋转速率（180度/秒）
    
        where {
            // 默认每一个小方格的边长为50cm
            scanf("%lf%lf", &x, &y);               // 输入待射击的目标点坐标
            getDifference(double x, double y);     // 求原点与目标点的差值
            moveCannonAngle();                     // 调整炮台角度（航向角、俯仰角）
            shooting(once);                        // 射击水弹（单次发射）
            wait(3);                               // 等待（3秒）
        }
    }
    
    // 函数：求原点与目标点的差值
    getDifference(double x, double y) {
        // 默认原点为 (0, 0)
        a = x - x0;
        b = y - y0;
    }
    
    // 函数：调整炮台角度（航向角、俯仰角）
    moveCannonAngle() {
        // 航向角计算
        // 计算公式：航向角角度 = atan(对/邻)
        // 分类讨论：
        // 目标点位于原点的第一象限
        if (a >= 0 && b >= 0) {
            h_angle = atan(a / b);
        } 
        // 目标点位于原点的第二象限
        if (a <= 0 && b >= 0) {
            h_angle = -1 * atan(abs(a) / b);
        } 
        // 目标点位于原点的第三象限
        if (a <= 0 && b <= 0) {
            h_angle = -90 - atan(abs(b) / abs(a));
        }
        // 目标点位于原点的第四象限
        if (a >= 0 && b <= 0) {
            h_angle = 90 + atan(abs(b) / a);
        }
        
        // 俯仰角计算
        // 计算公式：航向角角度 = -(atan(对/邻)
        f_angle = -1 * atan(turret_height / (sqrt(abs(a) * abs(a) + abs(b) * abs(b))));
    
        // 调整炮台航向角
        moveCourseAngle(h_angle);
    
        // 调整炮台俯仰角
        movePitchAngle(f_angle);
    }
    