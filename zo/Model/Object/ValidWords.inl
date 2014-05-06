{
    SubName * sn0 = &root.name["\""];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["%"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["'"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["."];
    {
        SubName * sn1 = &sn0->name["C"];
        {
            SubName * sn2 = &sn1->name["N"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["O"];
            {
                SubName * sn3 = &sn2->name["M"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["N"];
        {
            SubName * sn2 = &sn1->name["E"];
            {
                SubName * sn3 = &sn2->name["T"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["S"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["A"];
    {
        SubName * sn1 = &sn0->name["D"];
        {
            SubName * sn2 = &sn1->name["M"];
            {
                SubName * sn3 = &sn2->name["I"];
                {
                    SubName * sn4 = &sn3->name["N"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["I"];
        {
            SubName * sn2 = &sn1->name["D"];
            {
                SubName * sn3 = &sn2->name["S"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["S"];
        {
            SubName * sn2 = &sn1->name["S"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["B"];
    {
        SubName * sn1 = &sn0->name["I"];
        {
            SubName * sn2 = &sn1->name["T"];
            {
                SubName * sn3 = &sn2->name["C"];
                {
                    SubName * sn4 = &sn3->name["H"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["L"];
        {
            SubName * sn2 = &sn1->name["O"];
            {
                SubName * sn3 = &sn2->name["W"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["C"];
    {
        SubName * sn1 = &sn0->name["A"];
        {
            SubName * sn2 = &sn1->name["O"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["H"];
        {
            SubName * sn2 = &sn1->name["I"];
            {
                SubName * sn3 = &sn2->name["N"];
                {
                    SubName * sn4 = &sn3->name["A"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["L"];
        {
            SubName * sn2 = &sn1->name["I"];
            {
                SubName * sn3 = &sn2->name["E"];
                {
                    SubName * sn4 = &sn3->name["N"];
                    {
                        SubName * sn5 = &sn4->name["T"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["D"];
    {
        SubName * sn1 = &sn0->name["I"];
        {
            SubName * sn2 = &sn1->name["C"];
            {
                SubName * sn3 = &sn2->name["K"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["F"];
    {
        SubName * sn1 = &sn0->name["U"];
        {
            SubName * sn2 = &sn1->name["C"];
            {
                SubName * sn3 = &sn2->name["K"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["G"];
    {
        SubName * sn1 = &sn0->name["A"];
        {
            SubName * sn2 = &sn1->name["M"];
            {
                SubName * sn3 = &sn2->name["E"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["M"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["J"];
    {
        SubName * sn1 = &sn0->name["O"];
        {
            SubName * sn2 = &sn1->name["B"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["K"];
    {
        SubName * sn1 = &sn0->name["A"];
        {
            SubName * sn2 = &sn1->name["O"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["E"];
        {
            SubName * sn2 = &sn1->name["F"];
            {
                SubName * sn3 = &sn2->name["U"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["I"];
        {
            SubName * sn2 = &sn1->name["S"];
            {
                SubName * sn3 = &sn2->name["S"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["他"];
        {
            SubName * sn2 = &sn1->name["命"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["M"];
    {
        SubName * sn1 = &sn0->name["A"];
        {
            SubName * sn2 = &sn1->name["S"];
            {
                SubName * sn3 = &sn2->name["T"];
                {
                    SubName * sn4 = &sn3->name["E"];
                    {
                        SubName * sn5 = &sn4->name["R"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["L"];
        {
            SubName * sn2 = &sn1->name["花"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["Y"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["N"];
    {
        SubName * sn1 = &sn0->name["M"];
        {
            SubName * sn2 = &sn1->name["D"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["N"];
        {
            SubName * sn2 = &sn1->name["D"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["P"];
    {
        SubName * sn1 = &sn0->name["E"];
        {
            SubName * sn2 = &sn1->name["N"];
            {
                SubName * sn3 = &sn2->name["I"];
                {
                    SubName * sn4 = &sn3->name["S"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["S"];
    {
        SubName * sn1 = &sn0->name["B"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["E"];
        {
            SubName * sn2 = &sn1->name["R"];
            {
                SubName * sn3 = &sn2->name["V"];
                {
                    SubName * sn4 = &sn3->name["E"];
                    {
                        SubName * sn5 = &sn4->name["R"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["X"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["H"];
        {
            SubName * sn2 = &sn1->name["I"];
            {
                SubName * sn3 = &sn2->name["T"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["M"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["U"];
        {
            SubName * sn2 = &sn1->name["C"];
            {
                SubName * sn3 = &sn2->name["K"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["T"];
    {
        SubName * sn1 = &sn0->name["E"];
        {
            SubName * sn2 = &sn1->name["S"];
            {
                SubName * sn3 = &sn2->name["T"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["M"];
        {
            SubName * sn2 = &sn1->name["D"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["N"];
        {
            SubName * sn2 = &sn1->name["N"];
            {
                SubName * sn3 = &sn2->name["D"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["W"];
    {
        SubName * sn1 = &sn0->name["W"];
        {
            SubName * sn2 = &sn1->name["W"];
            {
                SubName * sn3 = &sn2->name["."];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["\\"];
    {
        SubName * sn1 = &sn0->name["\\"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["一"];
    {
        SubName * sn1 = &sn0->name["中"];
        {
            SubName * sn2 = &sn1->name["一"];
            {
                SubName * sn3 = &sn2->name["台"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["党"];
        {
            SubName * sn2 = &sn1->name["专"];
            {
                SubName * sn3 = &sn2->name["政"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["專"];
            {
                SubName * sn3 = &sn2->name["政"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["夜"];
        {
            SubName * sn2 = &sn1->name["情"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["貫"];
        {
            SubName * sn2 = &sn1->name["道"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["贯"];
        {
            SubName * sn2 = &sn1->name["道"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["黨"];
        {
            SubName * sn2 = &sn1->name["专"];
            {
                SubName * sn3 = &sn2->name["政"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["專"];
            {
                SubName * sn3 = &sn2->name["政"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["三"];
    {
        SubName * sn1 = &sn0->name["陪"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["上"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["妳"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["下"];
    {
        SubName * sn1 = &sn0->name["注"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["专"];
    {
        SubName * sn1 = &sn0->name["制"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["政"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["世"];
    {
        SubName * sn1 = &sn0->name["界"];
        {
            SubName * sn2 = &sn1->name["維"];
            {
                SubName * sn3 = &sn2->name["吾"];
                {
                    SubName * sn4 = &sn3->name["尔"];
                    {
                        SubName * sn5 = &sn4->name["大"];
                        {
                            SubName * sn6 = &sn5->name["会"];
                            sn6->isLeaf = true;
                        }
                        {
                            SubName * sn6 = &sn5->name["會"];
                            sn6->isLeaf = true;
                        }
                    }
                }
                {
                    SubName * sn4 = &sn3->name["爾"];
                    {
                        SubName * sn5 = &sn4->name["大"];
                        {
                            SubName * sn6 = &sn5->name["会"];
                            sn6->isLeaf = true;
                        }
                        {
                            SubName * sn6 = &sn5->name["會"];
                            sn6->isLeaf = true;
                        }
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["维"];
            {
                SubName * sn3 = &sn2->name["吾"];
                {
                    SubName * sn4 = &sn3->name["尔"];
                    {
                        SubName * sn5 = &sn4->name["大"];
                        {
                            SubName * sn6 = &sn5->name["会"];
                            sn6->isLeaf = true;
                        }
                        {
                            SubName * sn6 = &sn5->name["會"];
                            sn6->isLeaf = true;
                        }
                    }
                }
                {
                    SubName * sn4 = &sn3->name["爾"];
                    {
                        SubName * sn5 = &sn4->name["大"];
                        {
                            SubName * sn6 = &sn5->name["会"];
                            sn6->isLeaf = true;
                        }
                        {
                            SubName * sn6 = &sn5->name["會"];
                            sn6->isLeaf = true;
                        }
                    }
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["丘"];
    {
        SubName * sn1 = &sn0->name["吉"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["东"];
    {
        SubName * sn1 = &sn0->name["亚"];
        {
            SubName * sn2 = &sn1->name["病"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["亞"];
        {
            SubName * sn2 = &sn1->name["病"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["条"];
        {
            SubName * sn2 = &sn1->name["英"];
            {
                SubName * sn3 = &sn2->name["机"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["機"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["條"];
        {
            SubName * sn2 = &sn1->name["英"];
            {
                SubName * sn3 = &sn2->name["机"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["機"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["正"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["两"];
    {
        SubName * sn1 = &sn0->name["个"];
        {
            SubName * sn2 = &sn1->name["中"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["個"];
        {
            SubName * sn2 = &sn1->name["中"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["中"];
    {
        SubName * sn1 = &sn0->name["共"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["国"];
        {
            SubName * sn2 = &sn1->name["之"];
            {
                SubName * sn3 = &sn2->name["春"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["國"];
        {
            SubName * sn2 = &sn1->name["之"];
            {
                SubName * sn3 = &sn2->name["春"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["习"];
    {
        SubName * sn1 = &sn0->name["近"];
        {
            SubName * sn2 = &sn1->name["平"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["乡"];
    {
        SubName * sn1 = &sn0->name["巴"];
        {
            SubName * sn2 = &sn1->name["佬"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["乱"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["乳"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["头"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["峰"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["房"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["晕"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["暈"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["乾"];
    {
        SubName * sn1 = &sn0->name["乾"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["死"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["爽"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["亂"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["二"];
    {
        SubName * sn1 = &sn0->name["十"];
        {
            SubName * sn2 = &sn1->name["日"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["亚"];
    {
        SubName * sn1 = &sn0->name["历"];
        {
            SubName * sn2 = &sn1->name["山"];
            {
                SubName * sn3 = &sn2->name["大"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["歷"];
        {
            SubName * sn2 = &sn1->name["山"];
            {
                SubName * sn3 = &sn2->name["大"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["亞"];
    {
        SubName * sn1 = &sn0->name["历"];
        {
            SubName * sn2 = &sn1->name["山"];
            {
                SubName * sn3 = &sn2->name["大"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["歷"];
        {
            SubName * sn2 = &sn1->name["山"];
            {
                SubName * sn3 = &sn2->name["大"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["亲"];
    {
        SubName * sn1 = &sn0->name["民"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["人"];
    {
        SubName * sn1 = &sn0->name["民"];
        {
            SubName * sn2 = &sn1->name["報"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["报"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["仆"];
    {
        SubName * sn1 = &sn0->name["街"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["他"];
    {
        SubName * sn1 = &sn0->name["妈"];
        {
            SubName * sn2 = &sn1->name["的"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["娘"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["媽"];
        {
            SubName * sn2 = &sn1->name["的"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["伊"];
    {
        SubName * sn1 = &sn0->name["斯"];
        {
            SubName * sn2 = &sn1->name["兰"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["蘭"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["伟"];
    {
        SubName * sn1 = &sn0->name["哥"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["伺"];
    {
        SubName * sn1 = &sn0->name["务"];
        {
            SubName * sn2 = &sn1->name["器"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["服"];
        {
            SubName * sn2 = &sn1->name["器"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["佛"];
    {
        SubName * sn1 = &sn0->name["教"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["祖"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["你"];
    {
        SubName * sn1 = &sn0->name["妈"];
        {
            SubName * sn2 = &sn1->name["了"];
            {
                SubName * sn3 = &sn2->name["妹"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["逼"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["媽"];
        {
            SubName * sn2 = &sn1->name["了"];
            {
                SubName * sn3 = &sn2->name["妹"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["逼"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["來"];
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["插"];
        {
            SubName * sn2 = &sn1->name["我"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["爽"];
        {
            SubName * sn2 = &sn1->name["我"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["侧"];
    {
        SubName * sn1 = &sn0->name["那"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["俞"];
    {
        SubName * sn1 = &sn0->name["正"];
        {
            SubName * sn2 = &sn1->name["声"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["聲"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["假"];
    {
        SubName * sn1 = &sn0->name["庆"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["慶"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["偉"];
    {
        SubName * sn1 = &sn0->name["哥"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["做"];
    {
        SubName * sn1 = &sn0->name["愛"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["爱"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["側"];
    {
        SubName * sn1 = &sn0->name["那"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["催"];
    {
        SubName * sn1 = &sn0->name["情"];
        {
            SubName * sn2 = &sn1->name["药"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["葯"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["傻"];
    {
        SubName * sn1 = &sn0->name["B"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["子"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["比"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["元"];
    {
        SubName * sn1 = &sn0->name["宝"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["寶"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["先"];
    {
        SubName * sn1 = &sn0->name["奸"];
        {
            SubName * sn2 = &sn1->name["后"];
            {
                SubName * sn3 = &sn2->name["杀"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["殺"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["克"];
    {
        SubName * sn1 = &sn0->name["林"];
        {
            SubName * sn2 = &sn1->name["頓"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["顿"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["兩"];
    {
        SubName * sn1 = &sn0->name["个"];
        {
            SubName * sn2 = &sn1->name["中"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["個"];
        {
            SubName * sn2 = &sn1->name["中"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["六"];
    {
        SubName * sn1 = &sn0->name["四"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["共"];
    {
        SubName * sn1 = &sn0->name["产"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["党"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["匪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["產"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["黨"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["冈"];
    {
        SubName * sn1 = &sn0->name["村"];
        {
            SubName * sn2 = &sn1->name["宁"];
            {
                SubName * sn3 = &sn2->name["次"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["寧"];
            {
                SubName * sn3 = &sn2->name["次"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["秀"];
            {
                SubName * sn3 = &sn2->name["树"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["樹"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["冊"];
    {
        SubName * sn1 = &sn0->name["那"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["册"];
    {
        SubName * sn1 = &sn0->name["那"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["再"];
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["冰"];
    {
        SubName * sn1 = &sn0->name["毒"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["出"];
    {
        SubName * sn1 = &sn0->name["售"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["列"];
    {
        SubName * sn1 = &sn0->name["宁"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["寧"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["刘"];
    {
        SubName * sn1 = &sn0->name["云"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["伯"];
        {
            SubName * sn2 = &sn1->name["承"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["少"];
        {
            SubName * sn2 = &sn1->name["奇"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["淇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雲"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["劉"];
    {
        SubName * sn1 = &sn0->name["云"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["伯"];
        {
            SubName * sn2 = &sn1->name["承"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["少"];
        {
            SubName * sn2 = &sn1->name["奇"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["淇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雲"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["助"];
    {
        SubName * sn1 = &sn0->name["理"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["劳"];
    {
        SubName * sn1 = &sn0->name["拉"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["勞"];
    {
        SubName * sn1 = &sn0->name["拉"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["升"];
    {
        SubName * sn1 = &sn0->name["天"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["华"];
    {
        SubName * sn1 = &sn0->name["建"];
        {
            SubName * sn2 = &sn1->name["敏"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盛"];
        {
            SubName * sn2 = &sn1->name["頓"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["顿"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["卖"];
    {
        SubName * sn1 = &sn0->name["淫"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逼"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["南"];
    {
        SubName * sn1 = &sn0->name["华"];
        {
            SubName * sn2 = &sn1->name["早"];
            {
                SubName * sn3 = &sn2->name["報"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["报"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["華"];
        {
            SubName * sn2 = &sn1->name["早"];
            {
                SubName * sn3 = &sn2->name["報"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["报"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["蛮"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["蠻"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["卡"];
    {
        SubName * sn1 = &sn0->name["斯"];
        {
            SubName * sn2 = &sn1->name["特"];
            {
                SubName * sn3 = &sn2->name["罗"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["羅"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["原"];
    {
        SubName * sn1 = &sn0->name["子"];
        {
            SubName * sn2 = &sn1->name["弹"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["彈"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["去"];
    {
        SubName * sn1 = &sn0->name["他"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["你"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["的"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["她"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["妳"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["的"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["死"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["反"];
    {
        SubName * sn1 = &sn0->name["党"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["共"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["黨"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["发"];
    {
        SubName * sn1 = &sn0->name["騷"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["骚"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["变"];
    {
        SubName * sn1 = &sn0->name["态"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["態"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["口"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["可"];
    {
        SubName * sn1 = &sn0->name["卡"];
        {
            SubName * sn2 = &sn1->name["因"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["台"];
    {
        SubName * sn1 = &sn0->name["湾"];
        {
            SubName * sn2 = &sn1->name["岛"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["島"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["民"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["独"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["獨"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["灣"];
        {
            SubName * sn2 = &sn1->name["岛"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["島"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["民"];
            {
                SubName * sn3 = &sn2->name["国"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["國"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["独"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["獨"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["独"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["獨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["联"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["聯"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["叶"];
    {
        SubName * sn1 = &sn0->name["剑"];
        {
            SubName * sn2 = &sn1->name["英"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["劍"];
        {
            SubName * sn2 = &sn1->name["英"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["叼"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["吉"];
    {
        SubName * sn1 = &sn0->name["跋"];
        {
            SubName * sn2 = &sn1->name["猫"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["貓"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["吊"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["吕"];
    {
        SubName * sn1 = &sn0->name["秀"];
        {
            SubName * sn2 = &sn1->name["莲"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["蓮"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["吟"];
    {
        SubName * sn1 = &sn0->name["稻"];
        {
            SubName * sn2 = &sn1->name["雁"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["吳"];
    {
        SubName * sn1 = &sn0->name["仪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["儀"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["官"];
        {
            SubName * sn2 = &sn1->name["正"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["晓"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["曉"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["邦"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["吴"];
    {
        SubName * sn1 = &sn0->name["仪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["儀"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["官"];
        {
            SubName * sn2 = &sn1->name["正"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["晓"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["曉"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["邦"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["吸"];
    {
        SubName * sn1 = &sn0->name["毒"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["吹"];
    {
        SubName * sn1 = &sn0->name["喇"];
        {
            SubName * sn2 = &sn1->name["叭"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["箫"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["簫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["呂"];
    {
        SubName * sn1 = &sn0->name["秀"];
        {
            SubName * sn2 = &sn1->name["莲"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["蓮"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["周"];
    {
        SubName * sn1 = &sn0->name["恩"];
        {
            SubName * sn2 = &sn1->name["來"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["来"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["永"];
        {
            SubName * sn2 = &sn1->name["康"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["唐"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["璇"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["商"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["嗑"];
    {
        SubName * sn1 = &sn0->name["药"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["藥"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["回"];
    {
        SubName * sn1 = &sn0->name["回"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["教"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["民"];
        {
            SubName * sn2 = &sn1->name["吃"];
            {
                SubName * sn3 = &sn2->name["猪"];
                {
                    SubName * sn4 = &sn3->name["肉"];
                    sn4->isLeaf = true;
                }
            }
            {
                SubName * sn3 = &sn2->name["豬"];
                {
                    SubName * sn4 = &sn3->name["肉"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["良"];
        {
            SubName * sn2 = &sn1->name["玉"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["国"];
    {
        SubName * sn1 = &sn0->name["內"];
        {
            SubName * sn2 = &sn1->name["动"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["動"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["内"];
        {
            SubName * sn2 = &sn1->name["动"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["動"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["圆"];
    {
        SubName * sn1 = &sn0->name["满"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["滿"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["國"];
    {
        SubName * sn1 = &sn0->name["內"];
        {
            SubName * sn2 = &sn1->name["动"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["動"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["内"];
        {
            SubName * sn2 = &sn1->name["动"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["動"];
            {
                SubName * sn3 = &sn2->name["态"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
            {
                SubName * sn3 = &sn2->name["態"];
                {
                    SubName * sn4 = &sn3->name["清"];
                    {
                        SubName * sn5 = &sn4->name["样"];
                        sn5->isLeaf = true;
                    }
                    {
                        SubName * sn5 = &sn4->name["樣"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["圓"];
    {
        SubName * sn1 = &sn0->name["满"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["滿"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["圣"];
    {
        SubName * sn1 = &sn0->name["战"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戰"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["母"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["地"];
    {
        SubName * sn1 = &sn0->name["藏"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["坐"];
    {
        SubName * sn1 = &sn0->name["庄"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["莊"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["基"];
    {
        SubName * sn1 = &sn0->name["地"];
        {
            SubName * sn2 = &sn1->name["組"];
            {
                SubName * sn3 = &sn2->name["織"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["织"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["组"];
            {
                SubName * sn3 = &sn2->name["織"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["织"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["督"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["塔"];
    {
        SubName * sn1 = &sn0->name["利"];
        {
            SubName * sn2 = &sn1->name["班"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["墨"];
    {
        SubName * sn1 = &sn0->name["索"];
        {
            SubName * sn2 = &sn1->name["里"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["外"];
    {
        SubName * sn1 = &sn0->name["挂"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["掛"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["多"];
    {
        SubName * sn1 = &sn0->name["維"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["维"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["夢"];
    {
        SubName * sn1 = &sn0->name["遗"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["遺"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["大"];
    {
        SubName * sn1 = &sn0->name["卫"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["参"];
        {
            SubName * sn2 = &sn1->name["考"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["參"];
        {
            SubName * sn2 = &sn1->name["考"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["法"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["血"];
        {
            SubName * sn2 = &sn1->name["比"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["衛"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["麻"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["天"];
    {
        SubName * sn1 = &sn0->name["主"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["安"];
        {
            SubName * sn2 = &sn1->name["門"];
            {
                SubName * sn3 = &sn2->name["事"];
                {
                    SubName * sn4 = &sn3->name["件"];
                    sn4->isLeaf = true;
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["门"];
            {
                SubName * sn3 = &sn2->name["事"];
                {
                    SubName * sn4 = &sn3->name["件"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["太"];
    {
        SubName * sn1 = &sn0->name["子"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["奥"];
    {
        SubName * sn1 = &sn0->name["巴"];
        {
            SubName * sn2 = &sn1->name["馬"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["马"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["马"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["奧"];
    {
        SubName * sn1 = &sn0->name["巴"];
        {
            SubName * sn2 = &sn1->name["馬"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["马"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["马"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["奶"];
    {
        SubName * sn1 = &sn0->name["娘"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["子"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["奸"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["她"];
    {
        SubName * sn1 = &sn0->name["娘"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["如"];
    {
        SubName * sn1 = &sn0->name["來"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["来"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["妈"];
    {
        SubName * sn1 = &sn0->name["比"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["的"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["妓"];
    {
        SubName * sn1 = &sn0->name["女"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["妳"];
    {
        SubName * sn1 = &sn0->name["娘"];
        {
            SubName * sn2 = &sn1->name["的"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["老"];
        {
            SubName * sn2 = &sn1->name["母"];
            {
                SubName * sn3 = &sn2->name["的"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["姚"];
    {
        SubName * sn1 = &sn0->name["文"];
        {
            SubName * sn2 = &sn1->name["元"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["姦"];
    {
        SubName * sn1 = &sn0->name["淫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["威"];
    {
        SubName * sn1 = &sn0->name["而"];
        {
            SubName * sn2 = &sn1->name["柔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["鋼"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["钢"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["婊"];
    {
        SubName * sn1 = &sn0->name["子"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["媽"];
    {
        SubName * sn1 = &sn0->name["比"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["的"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["嫖"];
    {
        SubName * sn1 = &sn0->name["娼"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["嫩"];
    {
        SubName * sn1 = &sn0->name["B"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["孙"];
    {
        SubName * sn1 = &sn0->name["中"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["文"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逸"];
        {
            SubName * sn2 = &sn1->name["仙"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["学"];
    {
        SubName * sn1 = &sn0->name["潮"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["运"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["運"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["孫"];
    {
        SubName * sn1 = &sn0->name["中"];
        {
            SubName * sn2 = &sn1->name["山"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["文"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逸"];
        {
            SubName * sn2 = &sn1->name["仙"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["學"];
    {
        SubName * sn1 = &sn0->name["潮"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["运"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["運"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["安"];
    {
        SubName * sn1 = &sn0->name["南"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["非"];
        {
            SubName * sn2 = &sn1->name["他"];
            {
                SubName * sn3 = &sn2->name["命"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["宋"];
    {
        SubName * sn1 = &sn0->name["楚"];
        {
            SubName * sn2 = &sn1->name["瑜"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["官"];
    {
        SubName * sn1 = &sn0->name["方"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["审"];
    {
        SubName * sn1 = &sn0->name["查"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["客"];
    {
        SubName * sn1 = &sn0->name["戶"];
        {
            SubName * sn2 = &sn1->name["服"];
            {
                SubName * sn3 = &sn2->name["务"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["務"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["户"];
        {
            SubName * sn2 = &sn1->name["服"];
            {
                SubName * sn3 = &sn2->name["务"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["務"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["服"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["密"];
    {
        SubName * sn1 = &sn0->name["宗"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["富"];
    {
        SubName * sn1 = &sn0->name["兰"];
        {
            SubName * sn2 = &sn1->name["克"];
            {
                SubName * sn3 = &sn2->name["林"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["蘭"];
        {
            SubName * sn2 = &sn1->name["克"];
            {
                SubName * sn3 = &sn2->name["林"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["審"];
    {
        SubName * sn1 = &sn0->name["查"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["导"];
    {
        SubName * sn1 = &sn0->name["弹"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["彈"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["射"];
    {
        SubName * sn1 = &sn0->name["精"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["專"];
    {
        SubName * sn1 = &sn0->name["制"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["政"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["尉"];
    {
        SubName * sn1 = &sn0->name["健"];
        {
            SubName * sn2 = &sn1->name["行"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["導"];
    {
        SubName * sn1 = &sn0->name["弹"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["彈"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["小"];
    {
        SubName * sn1 = &sn0->name["参"];
        {
            SubName * sn2 = &sn1->name["考"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["參"];
        {
            SubName * sn2 = &sn1->name["考"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["泉"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["穴"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["尻"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["尼"];
    {
        SubName * sn1 = &sn0->name["克"];
        {
            SubName * sn2 = &sn1->name["松"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["尾"];
    {
        SubName * sn1 = &sn0->name["申"];
        {
            SubName * sn2 = &sn1->name["鯨"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["鲸"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["尿"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屁"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屄"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屌"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屎"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屙"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["屠"];
    {
        SubName * sn1 = &sn0->name["杀"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["殺"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["山"];
    {
        SubName * sn1 = &sn0->name["本"];
        {
            SubName * sn2 = &sn1->name["五"];
            {
                SubName * sn3 = &sn2->name["十"];
                {
                    SubName * sn4 = &sn3->name["六"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["岡"];
    {
        SubName * sn1 = &sn0->name["村"];
        {
            SubName * sn2 = &sn1->name["宁"];
            {
                SubName * sn3 = &sn2->name["次"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["寧"];
            {
                SubName * sn3 = &sn2->name["次"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["秀"];
            {
                SubName * sn3 = &sn2->name["树"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["樹"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["巡"];
    {
        SubName * sn1 = &sn0->name["查"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["布"];
    {
        SubName * sn1 = &sn0->name["什"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["希"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["朗"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["莱"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["萊"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["希"];
    {
        SubName * sn1 = &sn0->name["拉"];
        {
            SubName * sn2 = &sn1->name["克"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["特"];
        {
            SubName * sn2 = &sn1->name["勒"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["干"];
    {
        SubName * sn1 = &sn0->name["X"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["一"];
        {
            SubName * sn2 = &sn1->name["干"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["乾"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["他"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["入"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["到"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["勒"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["啦"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["她"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["妳"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["它"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["尼"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["您"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["我"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["机"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["林"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["機"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["死"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["汝"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["爆"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["爽"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["牠"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雞"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸡"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["广"];
    {
        SubName * sn1 = &sn0->name["场"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["場"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["废"];
    {
        SubName * sn1 = &sn0->name["物"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["廢"];
    {
        SubName * sn1 = &sn0->name["物"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["廣"];
    {
        SubName * sn1 = &sn0->name["场"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["場"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["开"];
    {
        SubName * sn1 = &sn0->name["房"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["张"];
    {
        SubName * sn1 = &sn0->name["德"];
        {
            SubName * sn2 = &sn1->name["江"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["春"];
        {
            SubName * sn2 = &sn1->name["桥"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["橋"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["立"];
        {
            SubName * sn2 = &sn1->name["昌"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["張"];
    {
        SubName * sn1 = &sn0->name["德"];
        {
            SubName * sn2 = &sn1->name["江"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["春"];
        {
            SubName * sn2 = &sn1->name["桥"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["橋"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["立"];
        {
            SubName * sn2 = &sn1->name["昌"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["強"];
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["强"];
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["彭"];
    {
        SubName * sn1 = &sn0->name["德"];
        {
            SubName * sn2 = &sn1->name["怀"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["懷"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["徐"];
    {
        SubName * sn1 = &sn0->name["向"];
        {
            SubName * sn2 = &sn1->name["前"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["性"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["慾"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["欲"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["虐"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["高"];
        {
            SubName * sn2 = &sn1->name["潮"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["恩"];
    {
        SubName * sn1 = &sn0->name["格"];
        {
            SubName * sn2 = &sn1->name["斯"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["情"];
    {
        SubName * sn1 = &sn0->name["色"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["愛"];
    {
        SubName * sn1 = &sn0->name["液"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["滋"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["我"];
    {
        SubName * sn1 = &sn0->name["咧"];
        {
            SubName * sn2 = &sn1->name["干"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["操"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["日"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["戳"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["手"];
    {
        SubName * sn1 = &sn0->name["淫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["打"];
    {
        SubName * sn1 = &sn0->name["倒"];
        {
            SubName * sn2 = &sn1->name["共"];
            {
                SubName * sn3 = &sn2->name["产"];
                {
                    SubName * sn4 = &sn3->name["党"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["黨"];
                    sn4->isLeaf = true;
                }
            }
            {
                SubName * sn3 = &sn2->name["產"];
                {
                    SubName * sn4 = &sn3->name["党"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["黨"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["抢"];
    {
        SubName * sn1 = &sn0->name["劫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["押"];
    {
        SubName * sn1 = &sn0->name["大"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["小"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["抽"];
    {
        SubName * sn1 = &sn0->name["头"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["拉"];
    {
        SubName * sn1 = &sn0->name["姆"];
        {
            SubName * sn2 = &sn1->name["斯"];
            {
                SubName * sn3 = &sn2->name["菲"];
                {
                    SubName * sn4 = &sn3->name["尔"];
                    {
                        SubName * sn5 = &sn4->name["德"];
                        sn5->isLeaf = true;
                    }
                }
                {
                    SubName * sn4 = &sn3->name["爾"];
                    {
                        SubName * sn5 = &sn4->name["德"];
                        sn5->isLeaf = true;
                    }
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["拐"];
    {
        SubName * sn1 = &sn0->name["卖"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["賣"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["拿"];
    {
        SubName * sn1 = &sn0->name["破"];
        {
            SubName * sn2 = &sn1->name["仑"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["崙"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["挨"];
    {
        SubName * sn1 = &sn0->name["球"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["掯"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["插"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["援"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["搖"];
    {
        SubName * sn1 = &sn0->name["头"];
        {
            SubName * sn2 = &sn1->name["丸"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        {
            SubName * sn2 = &sn1->name["丸"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["搞"];
    {
        SubName * sn1 = &sn0->name["栗"];
        {
            SubName * sn2 = &sn1->name["棒"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["搶"];
    {
        SubName * sn1 = &sn0->name["劫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["摇"];
    {
        SubName * sn1 = &sn0->name["头"];
        {
            SubName * sn2 = &sn1->name["丸"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        {
            SubName * sn2 = &sn1->name["丸"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["摩"];
    {
        SubName * sn1 = &sn0->name["門"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["门"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["摸"];
    {
        SubName * sn1 = &sn0->name["咪"];
        {
            SubName * sn2 = &sn1->name["咪"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["撒"];
    {
        SubName * sn1 = &sn0->name["切"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["操"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["支"];
    {
        SubName * sn1 = &sn0->name["那"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["政"];
    {
        SubName * sn1 = &sn0->name["变"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["府"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["治"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["變"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["教"];
    {
        SubName * sn1 = &sn0->name["閻"];
        {
            SubName * sn2 = &sn1->name["王"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["阎"];
        {
            SubName * sn2 = &sn1->name["王"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["文"];
    {
        SubName * sn1 = &sn0->name["化"];
        {
            SubName * sn2 = &sn1->name["部"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["殊"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["斯"];
    {
        SubName * sn1 = &sn0->name["大"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["新"];
    {
        SubName * sn1 = &sn0->name["党"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["疆"];
        {
            SubName * sn2 = &sn1->name["分"];
            {
                SubName * sn3 = &sn2->name["裂"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["独"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["獨"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["黨"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["无"];
    {
        SubName * sn1 = &sn0->name["帮"];
        {
            SubName * sn2 = &sn1->name["过"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["過"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["幫"];
        {
            SubName * sn2 = &sn1->name["过"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["過"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["日"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["死"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["早"];
    {
        SubName * sn1 = &sn0->name["泄"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["明"];
    {
        SubName * sn1 = &sn0->name["慧"];
        {
            SubName * sn2 = &sn1->name["網"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["网"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["映"];
    {
        SubName * sn1 = &sn0->name["山"];
        {
            SubName * sn2 = &sn1->name["紅"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["红"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["普"];
    {
        SubName * sn1 = &sn0->name["京"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["賢"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["贤"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["曹"];
    {
        SubName * sn1 = &sn0->name["刚"];
        {
            SubName * sn2 = &sn1->name["川"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["剛"];
        {
            SubName * sn2 = &sn1->name["川"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["曼"];
    {
        SubName * sn1 = &sn0->name["德"];
        {
            SubName * sn2 = &sn1->name["拉"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["曾"];
    {
        SubName * sn1 = &sn0->name["培"];
        {
            SubName * sn2 = &sn1->name["炎"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["庆"];
        {
            SubName * sn2 = &sn1->name["紅"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["红"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["慶"];
        {
            SubName * sn2 = &sn1->name["紅"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["红"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["服"];
    {
        SubName * sn1 = &sn0->name["务"];
        {
            SubName * sn2 = &sn1->name["器"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["天"];
            {
                SubName * sn3 = &sn2->name["使"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["務"];
        {
            SubName * sn2 = &sn1->name["天"];
            {
                SubName * sn3 = &sn2->name["使"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["服"];
        {
            SubName * sn2 = &sn1->name["器"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["本"];
    {
        SubName * sn1 = &sn0->name["拉"];
        {
            SubName * sn2 = &sn1->name["登"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["朱"];
    {
        SubName * sn1 = &sn0->name["德"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鎔"];
        {
            SubName * sn2 = &sn1->name["基"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["镕"];
        {
            SubName * sn2 = &sn1->name["基"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["机"];
    {
        SubName * sn1 = &sn0->name["八"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["叭"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["巴"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["掰"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["杀"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["李"];
    {
        SubName * sn1 = &sn0->name["大"];
        {
            SubName * sn2 = &sn1->name["师"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["師"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["釗"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["钊"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["岚"];
        {
            SubName * sn2 = &sn1->name["清"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["嵐"];
        {
            SubName * sn2 = &sn1->name["清"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["洪"];
        {
            SubName * sn2 = &sn1->name["志"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["瑞"];
        {
            SubName * sn2 = &sn1->name["环"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["環"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["登"];
        {
            SubName * sn2 = &sn1->name["輝"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["辉"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["長"];
        {
            SubName * sn2 = &sn1->name["春"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["长"];
        {
            SubName * sn2 = &sn1->name["春"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["鵬"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鹏"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["杜"];
    {
        SubName * sn1 = &sn0->name["冷"];
        {
            SubName * sn2 = &sn1->name["丁"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["魯"];
        {
            SubName * sn2 = &sn1->name["門"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["门"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["鲁"];
        {
            SubName * sn2 = &sn1->name["門"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["门"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["来"];
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["插"];
        {
            SubName * sn2 = &sn1->name["我"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["爽"];
        {
            SubName * sn2 = &sn1->name["我"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["東"];
    {
        SubName * sn1 = &sn0->name["亚"];
        {
            SubName * sn2 = &sn1->name["病"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["亞"];
        {
            SubName * sn2 = &sn1->name["病"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["条"];
        {
            SubName * sn2 = &sn1->name["英"];
            {
                SubName * sn3 = &sn2->name["机"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["機"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["條"];
        {
            SubName * sn2 = &sn1->name["英"];
            {
                SubName * sn3 = &sn2->name["机"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["機"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["正"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["林"];
    {
        SubName * sn1 = &sn0->name["彪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["肯"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["柯"];
    {
        SubName * sn1 = &sn0->name["林"];
        {
            SubName * sn2 = &sn1->name["頓"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["顿"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["柴"];
    {
        SubName * sn1 = &sn0->name["玲"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["核"];
    {
        SubName * sn1 = &sn0->name["工"];
        {
            SubName * sn2 = &sn1->name["业"];
            {
                SubName * sn3 = &sn2->name["基"];
                {
                    SubName * sn4 = &sn3->name["地"];
                    sn4->isLeaf = true;
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["業"];
            {
                SubName * sn3 = &sn2->name["基"];
                {
                    SubName * sn4 = &sn3->name["地"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["武"];
        {
            SubName * sn2 = &sn1->name["器"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["潛"];
        {
            SubName * sn2 = &sn1->name["艇"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["潜"];
        {
            SubName * sn2 = &sn1->name["艇"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["梅"];
    {
        SubName * sn1 = &sn0->name["毒"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["花"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["梦"];
    {
        SubName * sn1 = &sn0->name["遗"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["遺"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["機"];
    {
        SubName * sn1 = &sn0->name["八"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["叭"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["巴"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["掰"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["欠"];
    {
        SubName * sn1 = &sn0->name["人"];
        {
            SubName * sn2 = &sn1->name["騎"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["骑"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["騎"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["骑"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["殺"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["毛"];
    {
        SubName * sn1 = &sn0->name["泽"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["澤"];
        {
            SubName * sn2 = &sn1->name["东"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["東"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["民"];
    {
        SubName * sn1 = &sn0->name["主"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["国"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["國"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["运"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["进"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["進"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["運"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["氢"];
    {
        SubName * sn1 = &sn0->name["弹"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["彈"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["氫"];
    {
        SubName * sn1 = &sn0->name["弹"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["彈"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["江"];
    {
        SubName * sn1 = &sn0->name["泽"];
        {
            SubName * sn2 = &sn1->name["民"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["澤"];
        {
            SubName * sn2 = &sn1->name["民"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["青"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["沃"];
    {
        SubName * sn1 = &sn0->name["尔"];
        {
            SubName * sn2 = &sn1->name["开"];
            {
                SubName * sn3 = &sn2->name["西"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["開"];
            {
                SubName * sn3 = &sn2->name["西"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["爾"];
        {
            SubName * sn2 = &sn1->name["开"];
            {
                SubName * sn3 = &sn2->name["西"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["開"];
            {
                SubName * sn3 = &sn2->name["西"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["河"];
    {
        SubName * sn1 = &sn0->name["殇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["殤"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["法"];
    {
        SubName * sn1 = &sn0->name["克"];
        {
            SubName * sn2 = &sn1->name["魷"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["鱿"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["国"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["國"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["輪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["轮"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["活"];
    {
        SubName * sn1 = &sn0->name["动"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["動"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["测"];
    {
        SubName * sn1 = &sn0->name["拿"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["試"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["试"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["海"];
    {
        SubName * sn1 = &sn0->name["洛"];
        {
            SubName * sn2 = &sn1->name["因"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["淋"];
    {
        SubName * sn1 = &sn0->name["病"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["淫"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["渣"];
    {
        SubName * sn1 = &sn0->name["波"];
        {
            SubName * sn2 = &sn1->name["波"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["温"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["宝"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["寶"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["測"];
    {
        SubName * sn1 = &sn0->name["拿"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["試"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["试"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["游"];
    {
        SubName * sn1 = &sn0->name["戏"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["戲"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["行"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["湿"];
    {
        SubName * sn1 = &sn0->name["了"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["溫"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["宝"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["寶"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["滚"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["滥"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["滾"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["潛"];
    {
        SubName * sn1 = &sn0->name["烈"];
        {
            SubName * sn2 = &sn1->name["蟹"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["潜"];
    {
        SubName * sn1 = &sn0->name["烈"];
        {
            SubName * sn2 = &sn1->name["蟹"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["濕"];
    {
        SubName * sn1 = &sn0->name["了"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["濫"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["烂"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逼"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鳥"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸟"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["热"];
    {
        SubName * sn1 = &sn0->name["比"];
        {
            SubName * sn2 = &sn1->name["娅"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["婭"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["那"];
        {
            SubName * sn2 = &sn1->name["亚"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["亞"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["無"];
    {
        SubName * sn1 = &sn0->name["帮"];
        {
            SubName * sn2 = &sn1->name["过"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["過"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["幫"];
        {
            SubName * sn2 = &sn1->name["过"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["過"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["熱"];
    {
        SubName * sn1 = &sn0->name["比"];
        {
            SubName * sn2 = &sn1->name["娅"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["婭"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["那"];
        {
            SubName * sn2 = &sn1->name["亚"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["亞"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["爛"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逼"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鳥"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸟"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["爱"];
    {
        SubName * sn1 = &sn0->name["液"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["滋"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["爽"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["牛"];
    {
        SubName * sn1 = &sn0->name["头"];
        {
            SubName * sn2 = &sn1->name["馬"];
            {
                SubName * sn3 = &sn2->name["面"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["马"];
            {
                SubName * sn3 = &sn2->name["面"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        {
            SubName * sn2 = &sn1->name["馬"];
            {
                SubName * sn3 = &sn2->name["面"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["马"];
            {
                SubName * sn3 = &sn2->name["面"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["牡"];
    {
        SubName * sn1 = &sn0->name["丹"];
        {
            SubName * sn2 = &sn1->name["花"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["狗"];
    {
        SubName * sn1 = &sn0->name["娘"];
        {
            SubName * sn2 = &sn1->name["养"];
            {
                SubName * sn3 = &sn2->name["的"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["養"];
            {
                SubName * sn3 = &sn2->name["的"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["操"];
        {
            SubName * sn2 = &sn1->name["卖"];
            {
                SubName * sn3 = &sn2->name["逼"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["賣"];
            {
                SubName * sn3 = &sn2->name["逼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["猪"];
    {
        SubName * sn1 = &sn0->name["猡"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["玀"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["王"];
    {
        SubName * sn1 = &sn0->name["丹"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["乐"];
        {
            SubName * sn2 = &sn1->name["泉"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["兆"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["八"];
        {
            SubName * sn2 = &sn1->name["蛋"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["刚"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["剛"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["樂"];
        {
            SubName * sn2 = &sn1->name["泉"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["洪"];
        {
            SubName * sn2 = &sn1->name["文"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["班"];
    {
        SubName * sn1 = &sn0->name["禅"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["禪"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["甲"];
    {
        SubName * sn1 = &sn0->name["庆"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["慶"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["疆"];
    {
        SubName * sn1 = &sn0->name["独"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["獨"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["瘟"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["宝"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["寶"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["瘸"];
    {
        SubName * sn1 = &sn0->name["腿"];
        {
            SubName * sn2 = &sn1->name["帮"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["幫"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["發"];
    {
        SubName * sn1 = &sn0->name["騷"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["骚"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["白"];
    {
        SubName * sn1 = &sn0->name["痴"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["粉"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["莲"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["蓮"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["监"];
    {
        SubName * sn1 = &sn0->name["狱"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["獄"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["督"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["管"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["監"];
    {
        SubName * sn1 = &sn0->name["狱"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["獄"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["督"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["管"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["真"];
    {
        SubName * sn1 = &sn0->name["主"];
        {
            SubName * sn2 = &sn1->name["安"];
            {
                SubName * sn3 = &sn2->name["拉"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["善"];
        {
            SubName * sn2 = &sn1->name["忍"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["理"];
        {
            SubName * sn2 = &sn1->name["教"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["破"];
    {
        SubName * sn1 = &sn0->name["鞋"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["示"];
    {
        SubName * sn1 = &sn0->name["威"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["神"];
    {
        SubName * sn1 = &sn0->name["婆"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["汉"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["漢"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["經"];
        {
            SubName * sn2 = &sn1->name["病"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["经"];
        {
            SubName * sn2 = &sn1->name["病"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["私"];
    {
        SubName * sn1 = &sn0->name["人"];
        {
            SubName * sn2 = &sn1->name["伺"];
            {
                SubName * sn3 = &sn2->name["务"];
                {
                    SubName * sn4 = &sn3->name["器"];
                    sn4->isLeaf = true;
                }
            }
            {
                SubName * sn3 = &sn2->name["服"];
                {
                    SubName * sn4 = &sn3->name["器"];
                    sn4->isLeaf = true;
                }
            }
        }
        {
            SubName * sn2 = &sn1->name["服"];
            {
                SubName * sn3 = &sn2->name["务"];
                {
                    SubName * sn4 = &sn3->name["器"];
                    sn4->isLeaf = true;
                }
            }
            {
                SubName * sn3 = &sn2->name["服"];
                {
                    SubName * sn4 = &sn3->name["器"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["服"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["穆"];
    {
        SubName * sn1 = &sn0->name["斯"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["罕"];
        {
            SubName * sn2 = &sn1->name["默"];
            {
                SubName * sn3 = &sn2->name["德"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["穴"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["笨"];
    {
        SubName * sn1 = &sn0->name["蛋"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["筹"];
    {
        SubName * sn1 = &sn0->name["码"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["碼"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["管"];
    {
        SubName * sn1 = &sn0->name["理"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["里"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["籌"];
    {
        SubName * sn1 = &sn0->name["码"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["碼"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["精"];
    {
        SubName * sn1 = &sn0->name["子"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["液"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["系"];
    {
        SubName * sn1 = &sn0->name["統"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["统"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["納"];
    {
        SubName * sn1 = &sn0->name["粹"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["純"];
    {
        SubName * sn1 = &sn0->name["一"];
        {
            SubName * sn2 = &sn1->name["郎"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["維"];
    {
        SubName * sn1 = &sn0->name["护"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["護"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["纯"];
    {
        SubName * sn1 = &sn0->name["一"];
        {
            SubName * sn2 = &sn1->name["郎"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["纳"];
    {
        SubName * sn1 = &sn0->name["粹"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["维"];
    {
        SubName * sn1 = &sn0->name["护"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["護"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["罂"];
    {
        SubName * sn1 = &sn0->name["粟"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["罌"];
    {
        SubName * sn1 = &sn0->name["粟"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["罗"];
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["榮"];
        {
            SubName * sn2 = &sn1->name["桓"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["荣"];
        {
            SubName * sn2 = &sn1->name["桓"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["羅"];
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["榮"];
        {
            SubName * sn2 = &sn1->name["桓"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["荣"];
        {
            SubName * sn2 = &sn1->name["桓"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["美"];
    {
        SubName * sn1 = &sn0->name["国"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["國"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["習"];
    {
        SubName * sn1 = &sn0->name["近"];
        {
            SubName * sn2 = &sn1->name["平"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["老"];
    {
        SubName * sn1 = &sn0->name["土"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["母"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["毛"];
        {
            SubName * sn2 = &sn1->name["子"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["虎"];
        {
            SubName * sn2 = &sn1->name["机"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["機"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["耶"];
    {
        SubName * sn1 = &sn0->name["和"];
        {
            SubName * sn2 = &sn1->name["华"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["華"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["稣"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["穌"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["聂"];
    {
        SubName * sn1 = &sn0->name["榮"];
        {
            SubName * sn2 = &sn1->name["臻"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["荣"];
        {
            SubName * sn2 = &sn1->name["臻"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["聖"];
    {
        SubName * sn1 = &sn0->name["战"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戰"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["母"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["聶"];
    {
        SubName * sn1 = &sn0->name["榮"];
        {
            SubName * sn2 = &sn1->name["臻"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["荣"];
        {
            SubName * sn2 = &sn1->name["臻"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["肉"];
    {
        SubName * sn1 = &sn0->name["壶"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["壺"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["棒"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["肏"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["肛"];
    {
        SubName * sn1 = &sn0->name["交"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["門"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["门"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["胡"];
    {
        SubName * sn1 = &sn0->name["志"];
        {
            SubName * sn2 = &sn1->name["明"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["耀"];
        {
            SubName * sn2 = &sn1->name["邦"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["錦"];
        {
            SubName * sn2 = &sn1->name["涛"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["濤"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["锦"];
        {
            SubName * sn2 = &sn1->name["涛"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["濤"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["自"];
    {
        SubName * sn1 = &sn0->name["焚"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["臭"];
    {
        SubName * sn1 = &sn0->name["机"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["機"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["西"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雞"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸡"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["色"];
    {
        SubName * sn1 = &sn0->name["情"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["艹"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["艾"];
    {
        SubName * sn1 = &sn0->name["森"];
        {
            SubName * sn2 = &sn1->name["豪"];
            {
                SubName * sn3 = &sn2->name["威"];
                {
                    SubName * sn4 = &sn3->name["尔"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["爾"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
}
{
    SubName * sn0 = &root.name["苏"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["屯"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["茉"];
    {
        SubName * sn1 = &sn0->name["莉"];
        {
            SubName * sn2 = &sn1->name["花"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["茎"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["草"];
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["拟"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["擬"];
        {
            SubName * sn2 = &sn1->name["妈"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["媽"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["泥"];
        {
            SubName * sn2 = &sn1->name["馬"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["马"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["荡"];
    {
        SubName * sn1 = &sn0->name["妇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["婦"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["莖"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["菊"];
    {
        SubName * sn1 = &sn0->name["花"];
        {
            SubName * sn2 = &sn1->name["蚕"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["蠶"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["華"];
    {
        SubName * sn1 = &sn0->name["建"];
        {
            SubName * sn2 = &sn1->name["敏"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盛"];
        {
            SubName * sn2 = &sn1->name["頓"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["顿"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["萨"];
    {
        SubName * sn1 = &sn0->name["达"];
        {
            SubName * sn2 = &sn1->name["姆"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["達"];
        {
            SubName * sn2 = &sn1->name["姆"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        {
            SubName * sn2 = &sn1->name["兰"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["蘭"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["马"];
        {
            SubName * sn2 = &sn1->name["兰"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["蘭"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["葉"];
    {
        SubName * sn1 = &sn0->name["剑"];
        {
            SubName * sn2 = &sn1->name["英"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["劍"];
        {
            SubName * sn2 = &sn1->name["英"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["葵"];
    {
        SubName * sn1 = &sn0->name["花"];
        {
            SubName * sn2 = &sn1->name["子"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["蒋"];
    {
        SubName * sn1 = &sn0->name["中"];
        {
            SubName * sn2 = &sn1->name["正"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["介"];
        {
            SubName * sn2 = &sn1->name["石"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["經"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["经"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["蒙"];
    {
        SubName * sn1 = &sn0->name["古"];
        {
            SubName * sn2 = &sn1->name["鞑"];
            {
                SubName * sn3 = &sn2->name["子"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["韃"];
            {
                SubName * sn3 = &sn2->name["子"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["蔣"];
    {
        SubName * sn1 = &sn0->name["中"];
        {
            SubName * sn2 = &sn1->name["正"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["介"];
        {
            SubName * sn2 = &sn1->name["石"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["經"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["经"];
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["蕩"];
    {
        SubName * sn1 = &sn0->name["妇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["婦"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["薩"];
    {
        SubName * sn1 = &sn0->name["达"];
        {
            SubName * sn2 = &sn1->name["姆"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["達"];
        {
            SubName * sn2 = &sn1->name["姆"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        {
            SubName * sn2 = &sn1->name["兰"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["蘭"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["马"];
        {
            SubName * sn2 = &sn1->name["兰"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["蘭"];
            {
                SubName * sn3 = &sn2->name["奇"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["藏"];
    {
        SubName * sn1 = &sn0->name["复"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["妇"];
        {
            SubName * sn2 = &sn1->name["会"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["會"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["婦"];
        {
            SubName * sn2 = &sn1->name["会"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["會"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["復"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["独"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["獨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["青"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["蘇"];
    {
        SubName * sn1 = &sn0->name["家"];
        {
            SubName * sn2 = &sn1->name["屯"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["蠢"];
    {
        SubName * sn1 = &sn0->name["猪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["豬"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["西"];
    {
        SubName * sn1 = &sn0->name["哈"];
        {
            SubName * sn2 = &sn1->name["努"];
            {
                SubName * sn3 = &sn2->name["克"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["藏"];
        {
            SubName * sn2 = &sn1->name["分"];
            {
                SubName * sn3 = &sn2->name["裂"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["国"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["國"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["独"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["獨"];
            {
                SubName * sn3 = &sn2->name["立"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["親"];
    {
        SubName * sn1 = &sn0->name["民"];
        {
            SubName * sn2 = &sn1->name["党"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["黨"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["覽"];
    {
        SubName * sn1 = &sn0->name["叫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["觀"];
    {
        SubName * sn1 = &sn0->name["世"];
        {
            SubName * sn2 = &sn1->name["音"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["观"];
    {
        SubName * sn1 = &sn0->name["世"];
        {
            SubName * sn2 = &sn1->name["音"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["览"];
    {
        SubName * sn1 = &sn0->name["叫"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["謀"];
    {
        SubName * sn1 = &sn0->name["杀"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["殺"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["變"];
    {
        SubName * sn1 = &sn0->name["态"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["態"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["谋"];
    {
        SubName * sn1 = &sn0->name["杀"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["殺"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["豬"];
    {
        SubName * sn1 = &sn0->name["猡"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["玀"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["販"];
    {
        SubName * sn1 = &sn0->name["毒"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["賀"];
    {
        SubName * sn1 = &sn0->name["国"];
        {
            SubName * sn2 = &sn1->name["強"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["强"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["國"];
        {
            SubName * sn2 = &sn1->name["強"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["强"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["龍"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["龙"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["賈"];
    {
        SubName * sn1 = &sn0->name["庆"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["慶"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["賣"];
    {
        SubName * sn1 = &sn0->name["淫"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["逼"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["賤"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["貨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["货"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["賭"];
    {
        SubName * sn1 = &sn0->name["博"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["球"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["马"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["賴"];
    {
        SubName * sn1 = &sn0->name["昌"];
        {
            SubName * sn2 = &sn1->name["星"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["賽"];
    {
        SubName * sn1 = &sn0->name["他"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["你"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["她"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["妳"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["贩"];
    {
        SubName * sn1 = &sn0->name["毒"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["贱"];
    {
        SubName * sn1 = &sn0->name["人"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["貨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["货"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["贺"];
    {
        SubName * sn1 = &sn0->name["国"];
        {
            SubName * sn2 = &sn1->name["強"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["强"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["國"];
        {
            SubName * sn2 = &sn1->name["強"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["强"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["龍"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["龙"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["贾"];
    {
        SubName * sn1 = &sn0->name["庆"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["慶"];
        {
            SubName * sn2 = &sn1->name["林"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["赌"];
    {
        SubName * sn1 = &sn0->name["博"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["球"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["馬"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["马"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["赖"];
    {
        SubName * sn1 = &sn0->name["昌"];
        {
            SubName * sn2 = &sn1->name["星"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["赛"];
    {
        SubName * sn1 = &sn0->name["他"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["你"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["她"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["妳"];
        {
            SubName * sn2 = &sn1->name["娘"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["赫"];
    {
        SubName * sn1 = &sn0->name["魯"];
        {
            SubName * sn2 = &sn1->name["晓"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["曉"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["鲁"];
        {
            SubName * sn2 = &sn1->name["晓"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["曉"];
            {
                SubName * sn3 = &sn2->name["夫"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["走"];
    {
        SubName * sn1 = &sn0->name["向"];
        {
            SubName * sn2 = &sn1->name["圆"];
            {
                SubName * sn3 = &sn2->name["满"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["滿"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["圓"];
            {
                SubName * sn3 = &sn2->name["满"];
                sn3->isLeaf = true;
            }
            {
                SubName * sn3 = &sn2->name["滿"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["私"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["赵"];
    {
        SubName * sn1 = &sn0->name["紫"];
        {
            SubName * sn2 = &sn1->name["阳"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["陽"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["起"];
    {
        SubName * sn1 = &sn0->name["义"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["義"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["趙"];
    {
        SubName * sn1 = &sn0->name["紫"];
        {
            SubName * sn2 = &sn1->name["阳"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["陽"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["路"];
    {
        SubName * sn1 = &sn0->name["易"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["跳"];
    {
        SubName * sn1 = &sn0->name["大"];
        {
            SubName * sn2 = &sn1->name["神"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["輔"];
    {
        SubName * sn1 = &sn0->name["助"];
        {
            SubName * sn2 = &sn1->name["程"];
            {
                SubName * sn3 = &sn2->name["序"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["輪"];
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["流"];
        {
            SubName * sn2 = &sn1->name["干"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盘"];
        {
            SubName * sn2 = &sn1->name["賭"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["赌"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盤"];
        {
            SubName * sn2 = &sn1->name["賭"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["赌"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["轉"];
    {
        SubName * sn1 = &sn0->name["法"];
        {
            SubName * sn2 = &sn1->name["輪"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["轮"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["转"];
    {
        SubName * sn1 = &sn0->name["法"];
        {
            SubName * sn2 = &sn1->name["輪"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["轮"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["轮"];
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["干"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["流"];
        {
            SubName * sn2 = &sn1->name["干"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盘"];
        {
            SubName * sn2 = &sn1->name["賭"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["赌"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["盤"];
        {
            SubName * sn2 = &sn1->name["賭"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["赌"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["辅"];
    {
        SubName * sn1 = &sn0->name["助"];
        {
            SubName * sn2 = &sn1->name["程"];
            {
                SubName * sn3 = &sn2->name["序"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["达"];
    {
        SubName * sn1 = &sn0->name["菲"];
        {
            SubName * sn2 = &sn1->name["雞"];
            {
                SubName * sn3 = &sn2->name["等"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["鸡"];
            {
                SubName * sn3 = &sn2->name["等"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["賴"];
        {
            SubName * sn2 = &sn1->name["喇"];
            {
                SubName * sn3 = &sn2->name["嘛"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["赖"];
        {
            SubName * sn2 = &sn1->name["喇"];
            {
                SubName * sn3 = &sn2->name["嘛"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["运"];
    {
        SubName * sn1 = &sn0->name["營"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["营"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["连"];
    {
        SubName * sn1 = &sn0->name["战"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戰"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["迷"];
    {
        SubName * sn1 = &sn0->name["幻"];
        {
            SubName * sn2 = &sn1->name["药"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["藥"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["造"];
    {
        SubName * sn1 = &sn0->name["反"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["連"];
    {
        SubName * sn1 = &sn0->name["战"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戰"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["逼"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["遊"];
    {
        SubName * sn1 = &sn0->name["戏"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["戲"];
        {
            SubName * sn2 = &sn1->name["管"];
            {
                SubName * sn3 = &sn2->name["理"];
                {
                    SubName * sn4 = &sn3->name["员"];
                    sn4->isLeaf = true;
                }
                {
                    SubName * sn4 = &sn3->name["員"];
                    sn4->isLeaf = true;
                }
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["行"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["運"];
    {
        SubName * sn1 = &sn0->name["營"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["营"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["道"];
    {
        SubName * sn1 = &sn0->name["教"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["達"];
    {
        SubName * sn1 = &sn0->name["菲"];
        {
            SubName * sn2 = &sn1->name["雞"];
            {
                SubName * sn3 = &sn2->name["等"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["鸡"];
            {
                SubName * sn3 = &sn2->name["等"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["賴"];
        {
            SubName * sn2 = &sn1->name["喇"];
            {
                SubName * sn3 = &sn2->name["嘛"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["赖"];
        {
            SubName * sn2 = &sn1->name["喇"];
            {
                SubName * sn3 = &sn2->name["嘛"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["遗"];
    {
        SubName * sn1 = &sn0->name["精"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["遺"];
    {
        SubName * sn1 = &sn0->name["精"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["邓"];
    {
        SubName * sn1 = &sn0->name["小"];
        {
            SubName * sn2 = &sn1->name["平"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["郁"];
    {
        SubName * sn1 = &sn0->name["慕"];
        {
            SubName * sn2 = &sn1->name["明"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["郭"];
    {
        SubName * sn1 = &sn0->name["伯"];
        {
            SubName * sn2 = &sn1->name["雄"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["鄉"];
    {
        SubName * sn1 = &sn0->name["巴"];
        {
            SubName * sn2 = &sn1->name["佬"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["鄧"];
    {
        SubName * sn1 = &sn0->name["小"];
        {
            SubName * sn2 = &sn1->name["平"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["释"];
    {
        SubName * sn1 = &sn0->name["迦"];
        {
            SubName * sn2 = &sn1->name["牟"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["釋"];
    {
        SubName * sn1 = &sn0->name["迦"];
        {
            SubName * sn2 = &sn1->name["牟"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["里"];
    {
        SubName * sn1 = &sn0->name["根"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["金"];
    {
        SubName * sn1 = &sn0->name["日"];
        {
            SubName * sn2 = &sn1->name["成"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["正"];
        {
            SubName * sn2 = &sn1->name["日"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["鈾"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["鎮"];
    {
        SubName * sn1 = &sn0->name["压"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["壓"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["铀"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["镇"];
    {
        SubName * sn1 = &sn0->name["压"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["壓"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["開"];
    {
        SubName * sn1 = &sn0->name["房"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["閻"];
    {
        SubName * sn1 = &sn0->name["王"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["阎"];
    {
        SubName * sn1 = &sn0->name["王"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["阳"];
    {
        SubName * sn1 = &sn0->name["具"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["物"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["痿"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["阴"];
    {
        SubName * sn1 = &sn0->name["唇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戶"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["户"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["核"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["茎"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["莖"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["蒂"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["道"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["部"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["門"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["门"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["阿"];
    {
        SubName * sn1 = &sn0->name["弥"];
        {
            SubName * sn2 = &sn1->name["陀"];
            {
                SubName * sn3 = &sn2->name["佛"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["彌"];
        {
            SubName * sn2 = &sn1->name["陀"];
            {
                SubName * sn3 = &sn2->name["佛"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["扁"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["拉"];
        {
            SubName * sn2 = &sn1->name["法"];
            {
                SubName * sn3 = &sn2->name["特"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["罗"];
        {
            SubName * sn2 = &sn1->name["約"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["约"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["羅"];
        {
            SubName * sn2 = &sn1->name["約"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["约"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["陈"];
    {
        SubName * sn1 = &sn0->name["云"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["毅"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["水"];
        {
            SubName * sn2 = &sn1->name["扁"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["独"];
        {
            SubName * sn2 = &sn1->name["秀"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["獨"];
        {
            SubName * sn2 = &sn1->name["秀"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["至"];
        {
            SubName * sn2 = &sn1->name["立"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["良"];
        {
            SubName * sn2 = &sn1->name["宇"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["雲"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["陰"];
    {
        SubName * sn1 = &sn0->name["唇"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["戶"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["户"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["核"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["茎"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["莖"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["蒂"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["道"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["部"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["門"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["门"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["陳"];
    {
        SubName * sn1 = &sn0->name["云"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["毅"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["水"];
        {
            SubName * sn2 = &sn1->name["扁"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["独"];
        {
            SubName * sn2 = &sn1->name["秀"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["獨"];
        {
            SubName * sn2 = &sn1->name["秀"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["至"];
        {
            SubName * sn2 = &sn1->name["立"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["良"];
        {
            SubName * sn2 = &sn1->name["宇"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["雲"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["陽"];
    {
        SubName * sn1 = &sn0->name["具"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["物"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["痿"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["雅"];
    {
        SubName * sn1 = &sn0->name["蠛"];
        {
            SubName * sn2 = &sn1->name["蝶"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["雞"];
    {
        SubName * sn1 = &sn0->name["八"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["叭"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["巴"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["掰"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["歪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雞"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸡"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["靠"];
    sn0->isLeaf = true;
}
{
    SubName * sn0 = &root.name["額"];
    {
        SubName * sn1 = &sn0->name["尔"];
        {
            SubName * sn2 = &sn1->name["德"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["爾"];
        {
            SubName * sn2 = &sn1->name["德"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["顏"];
    {
        SubName * sn1 = &sn0->name["射"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["颜"];
    {
        SubName * sn1 = &sn0->name["射"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["额"];
    {
        SubName * sn1 = &sn0->name["尔"];
        {
            SubName * sn2 = &sn1->name["德"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["爾"];
        {
            SubName * sn2 = &sn1->name["德"];
            {
                SubName * sn3 = &sn2->name["尼"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["風"];
    {
        SubName * sn1 = &sn0->name["水"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["风"];
    {
        SubName * sn1 = &sn0->name["水"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["馬"];
    {
        SubName * sn1 = &sn0->name["克"];
        {
            SubName * sn2 = &sn1->name["思"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["加"];
        {
            SubName * sn2 = &sn1->name["爵"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["的"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["英"];
        {
            SubName * sn2 = &sn1->name["九"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["騎"];
    {
        SubName * sn1 = &sn0->name["他"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["她"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["騷"];
    {
        SubName * sn1 = &sn0->name["B"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["貨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["货"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["马"];
    {
        SubName * sn1 = &sn0->name["克"];
        {
            SubName * sn2 = &sn1->name["思"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["加"];
        {
            SubName * sn2 = &sn1->name["爵"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["的"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["英"];
        {
            SubName * sn2 = &sn1->name["九"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["骑"];
    {
        SubName * sn1 = &sn0->name["他"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["你"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["她"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["骚"];
    {
        SubName * sn1 = &sn0->name["B"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["貨"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["货"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["高"];
    {
        SubName * sn1 = &sn0->name["丽"];
        {
            SubName * sn2 = &sn1->name["朴"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["棒"];
            {
                SubName * sn3 = &sn2->name["子"];
                sn3->isLeaf = true;
            }
        }
    }
    {
        SubName * sn1 = &sn0->name["治"];
        {
            SubName * sn2 = &sn1->name["联"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["聯"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["自"];
        {
            SubName * sn2 = &sn1->name["联"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["聯"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["麗"];
        {
            SubName * sn2 = &sn1->name["朴"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["棒"];
            {
                SubName * sn3 = &sn2->name["子"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["鮑"];
    {
        SubName * sn1 = &sn0->name["威"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["鲍"];
    {
        SubName * sn1 = &sn0->name["威"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["鴉"];
    {
        SubName * sn1 = &sn0->name["片"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["鸡"];
    {
        SubName * sn1 = &sn0->name["八"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["叭"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["奸"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["姦"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["巴"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["掰"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["歪"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["雞"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["鸡"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["鸦"];
    {
        SubName * sn1 = &sn0->name["片"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["黃"];
    {
        SubName * sn1 = &sn0->name["大"];
        {
            SubName * sn2 = &sn1->name["仙"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["色"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["菊"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["黄"];
    {
        SubName * sn1 = &sn0->name["大"];
        {
            SubName * sn2 = &sn1->name["仙"];
            sn2->isLeaf = true;
        }
    }
    {
        SubName * sn1 = &sn0->name["色"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["菊"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["黑"];
    {
        SubName * sn1 = &sn0->name["白"];
        {
            SubName * sn2 = &sn1->name["无"];
            {
                SubName * sn3 = &sn2->name["常"];
                sn3->isLeaf = true;
            }
        }
        {
            SubName * sn2 = &sn1->name["無"];
            {
                SubName * sn3 = &sn2->name["常"];
                sn3->isLeaf = true;
            }
        }
    }
}
{
    SubName * sn0 = &root.name["默"];
    {
        SubName * sn1 = &sn0->name["克"];
        {
            SubName * sn2 = &sn1->name["尔"];
            sn2->isLeaf = true;
        }
        {
            SubName * sn2 = &sn1->name["爾"];
            sn2->isLeaf = true;
        }
    }
}
{
    SubName * sn0 = &root.name["龜"];
    {
        SubName * sn1 = &sn0->name["头"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["龟"];
    {
        SubName * sn1 = &sn0->name["头"];
        sn1->isLeaf = true;
    }
    {
        SubName * sn1 = &sn0->name["頭"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["Ｇ"];
    {
        SubName * sn1 = &sn0->name["Ｍ"];
        sn1->isLeaf = true;
    }
}
{
    SubName * sn0 = &root.name["ｇ"];
    {
        SubName * sn1 = &sn0->name["ｍ"];
        sn1->isLeaf = true;
    }
}
