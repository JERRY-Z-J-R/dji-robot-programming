    // 射击函数
    // a：姿态角（航向角）的左边界
    // b：姿态角（航向角）的右边界
    shooting(double a, double b)
    {
        // 介于左右边界之间时
        if (getAngle() > a && getAngle() < b)
        {
            // 设置射击时的转动速度
            setSpeed(10);
            // 设置单次射击
            launch(once);
        }
    }