// DJI-EP-底盘精控
// 周吉瑞 2021/05/18
// 伪代码（C语言风格）

main()
{
    double time;                     // 所需时间
    double x;                        // 当前底盘的x坐标
    double y;                        // 当前底盘的y坐标
    double left_front_rotate_speed;  // 左前轮转速
    double right_front_rotate_speed; // 右前轮转速
    double left_rear_rotate_speed;   // 左后轮转速
    double right_rear_rotate_speed;  // 左后轮转速

    scanf("%lf", &left_front_rotate_speed);
    scanf("%lf", &right_front_rotate_speed);
    scanf("%lf", &left_rear_rotate_speed);
    scanf("%lf", &right_rear_rotate_speed);

    timerStart(time); // 计时器开始计时

    // 起点坐标为（0,0），转动180°后相当于y又回到0
    while (y < 0) // 当底盘旋转180°后退出循环
    {
        x = getChassisX(); // 获取底盘当前位置x坐标
        y = getChassisY(); // 获取底盘当前位置y坐标

        // 将所有转速放慢5倍（尽量减少惯性带来的影响）
        left_front_rotate_speed /= 5;
        right_front_rotate_speed /= 5;
        left_rear_rotate_speed /= 5;
        right_rear_rotate_speed /= 5;

        // 控制轮子转动
        wheelTurn(left_front_rotate_speed,
                  right_front_rotate_speed,
                  left_rear_rotate_speed,
                  right_rear_rotate_speed);
    }

    timerStop(time); // 计时器结束计时

    // 输出底盘转动90°所需时间（÷2=90°；÷5加快5倍）
    printf("time is %lf\n", time / 5 / 2);
}