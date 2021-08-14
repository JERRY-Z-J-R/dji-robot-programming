    // README：
    // timer() 控制计时器：1开启，0关闭
    // getTimer() 获取当前计时器时间
    // mechanicalArm() 控制机械臂：0回中
    // getMechanicalClaw() 获取机械爪状态：1张开，0闭合
    // mechanicalArm() 控制机械爪：1张开，0闭合
    // led() 控制LED灯

    main()
    {
        timer(1);
        while (getTimer() > 15)
        {
            if (getTimer() >= 0 && getTimer() < 5)
            {
                func1();
            }
            if (getTimer() >= 5 && getTimer() < 10)
            {
                func2();
            }
            if (getTimer() >= 10)
            {
                func3();
            }
        }
    }

    func1()
    {
        led(1, 1, 'g', 1);
        mechanicalArm(0);
        while (getMechanicalClaw() == 1)
        {
            mechanicalArm(1);
        }
    }

    func2()
    {
        led(1, 1, 'y', 2);
        mechanicalArm(100, 140);
        while (getMechanicalClaw() == 0)
        {
            mechanicalArm(0);
        }
    }

    func3()
    {
        led(1, 1, 'r', 3);
        mechanicalArm(200, -60);
        while (getMechanicalClaw() == 1)
        {
            mechanicalArm(1);
        }
    }