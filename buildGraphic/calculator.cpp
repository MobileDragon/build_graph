#include "calculator.h"


Calculator::Calculator(QString myformul)
{
    bool flag=false;
    QString s1=myformul;
    func="";
    QString t_func="";
    int kol = s1.length();
    for(int i=0; i<kol; i++)//���������� �����
    {
        if(!flag && s1[i]=="=")
        {
            flag=true;
            i++;
            if(i>kol)
                break;
        }
        if(flag)
        {
            if(s1[i]!=" ")
                func.append(s1[i]) ;
        }
        else
        {
            if(s1[i]!=" ")
                t_func.append(s1[i]);
        }
    }
    if(t_func.length()>func.length())
    {
        nameY=func;
        func=t_func;
    }
    else
    {
        nameY=t_func;
    }
    if(nameY.length()==0)
        nameY="Y";

    //func=myformul;
    //--
    startX=15;
    endX=30;
    step=0.1;
    WriteFormul();
    nameX="x";//заглушка
    //nameY="y";//заглушка
    //

    float i=startX;
    MyPoint aa;
    while(i<endX+0.1)
    {
        arrVariable[nameX]=i;
        aa.x=i;
        aa.y=expr();
        relationXY.append(aa);
        WriteFormul();
        i+=step;
    }


}

void Calculator::WriteFormul()
{
    formul.clear();
    for(int i=func.length()-1; i>=0; i--)//���������� �����
    {
        formul.push(func[i]);
    }
}

QList<MyPoint> Calculator::getPoints()
{
    return relationXY;
}

QList<QString> Calculator::getListVariable()//
{
    QList<QString>vars;
    //
    QChar c;
    QString var="";

    while (!formul.empty())
    {

        c=formul.top();
        formul.pop();

        if(c.isLetter() || (var.length()>0 && c.isDigit() ) )
            var.append(c);
        else
            if(var.length()!=3)//длина sin cos exp и так далее пока
            {
                vars.append(var);
                var="";
            }
            else
                if(var=="sin" || var=="cos" || var=="exp")
                    var="";
                else
                {
                    vars.append(var);
                    var="";
                }
    }
    vars.append(var);
    WriteFormul();
    return vars;
}

float Calculator::expr()//сумма
{
    //
    float result = factor();//произведение
    QChar c;

    while (!formul.empty())
    {

        c=formul.top();
        formul.pop();

        while (c == ' ')//
        {
            c=formul.top();
            formul.pop();
            //c = std::cin.get();
        }
        if(c=='+')
        {
            float tempR=result;
            result=factor() + tempR;
        }
        else
        {
            formul.push(c);

            return result;
        }
    }

    return result;
}
//
float Calculator::factor()//произведение
{
    float result = brackets();
    QChar c;


    while (!formul.empty())
    {
        c=formul.top();
        formul.pop();

        while (c == ' ')
        {
            c=formul.top();
            formul.pop();
        }
        if(c=='*')
        {


            float tempR=result;
            result=brackets()*tempR;
        }
        else
        {
            formul.push(c);
            return result;
        }
    }

    return result;
}

float Calculator::brackets()
{
    float result;
    bool sign = true;//знак
    QChar c;

    c=formul.top();
    formul.pop();

    while (c == ' ')
    {
        c=formul.top();
        formul.pop();
    }

    if (c == '-')
    {
        sign = false;
        c=formul.top();
        formul.pop();
    }

    while (c == ' ')
    {
        c=formul.top();
        formul.pop();
    }

    if (c == '(')
    {
        result = expr();

        c=formul.top();
        formul.pop();

        if (c != ')')
        {
            broken="The wrong placement of brackets \")\"! ";
            return 0;
        }


        return result;
    }
    else
    {
        formul.push(c);

        result=variable();
        if(!sign)
        {
            result=result*(-1);
        }

        return result;
    }
}



//
float Calculator::variable()//добавить расспознование sin,cos,exp
{
    float result;
    bool sign = true;//знак
    QChar c;

    c=formul.top();
    formul.pop();

    while (c == ' ')
    {
        c=formul.top();
        formul.pop();
    }

    if (c == '-')
    {
        sign = false;
    }
    else
        formul.push(c);//
//
    QString temp="";
    bool ok;//яляется ли переменная константой
    while (!formul.empty())
    {
        c=formul.top();
        formul.pop();

        while (c == ' ')
        {
            c=formul.top();
            formul.pop();
        }

        if (c.isLetterOrNumber() || c=='.')//дробная часть(вещественное число)
        {
            temp+=c;
        }
        else
        {

            formul.push(c);
            break;
        }

    }
    if(temp.length()>0)
    {
        result=temp.toFloat(&ok);
        if(ok)//перменная
        {
            if(!sign)
                result=result*(-1);
        }
        else
            result=arrVariable[temp];
            //если это не переменная(sin, cos...), то вернуть строку temp в стек

    }

    return result;
}
