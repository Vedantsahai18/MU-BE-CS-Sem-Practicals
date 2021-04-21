package com.example.expno7;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class CalculatorActivity extends AppCompatActivity implements View.OnClickListener{

    Button btn_1,btn_2,btn_3,btn_4,btn_5,btn_6,btn_7,btn_8,btn_9,btn_0,btn_Add,btn_Sub,btn_Mul,btn_Div,btn_calc,btn_dec,btn_clear;
    EditText ed1;

    float Value1, Value2;
    boolean mAddition, mSubtract, mMultiplication, mDivision ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_0 = (Button) findViewById(R.id.btn_0);
        btn_1 = (Button) findViewById(R.id.btn_1);
        btn_2 = (Button) findViewById(R.id.btn_2);
        btn_3 = (Button) findViewById(R.id.btn_3);
        btn_4 = (Button) findViewById(R.id.btn_4);
        btn_5 = (Button) findViewById(R.id.btn_5);
        btn_6 = (Button) findViewById(R.id.btn_6);
        btn_7 = (Button) findViewById(R.id.btn_7);
        btn_8 = (Button) findViewById(R.id.btn_8);
        btn_9 = (Button) findViewById(R.id.btn_9);
        btn_Add = (Button) findViewById(R.id.btn_Add);
        btn_Div = (Button) findViewById(R.id.btn_Div);
        btn_Sub = (Button) findViewById(R.id.btn_Sub);
        btn_Mul = (Button) findViewById(R.id.btn_Mul);
        btn_calc = (Button) findViewById(R.id.btn_calc);
        btn_dec = (Button) findViewById(R.id.btn_dec);
        btn_clear = (Button) findViewById(R.id.btn_clear);
        ed1 = (EditText) findViewById(R.id.edText1);

        btn_0.setOnClickListener((View.OnClickListener) this);
        btn_1.setOnClickListener((View.OnClickListener) this);
        btn_2.setOnClickListener((View.OnClickListener) this);
        btn_3.setOnClickListener((View.OnClickListener) this);
        btn_4.setOnClickListener((View.OnClickListener) this);
        btn_5.setOnClickListener((View.OnClickListener) this);
        btn_6.setOnClickListener((View.OnClickListener) this);
        btn_7.setOnClickListener((View.OnClickListener) this);
        btn_8.setOnClickListener((View.OnClickListener) this);
        btn_9.setOnClickListener((View.OnClickListener) this);
        btn_Add.setOnClickListener((View.OnClickListener) this);
        btn_Div.setOnClickListener((View.OnClickListener) this);
        btn_Sub.setOnClickListener((View.OnClickListener) this);
        btn_Mul.setOnClickListener((View.OnClickListener) this);
        btn_calc.setOnClickListener((View.OnClickListener) this);
        btn_dec.setOnClickListener((View.OnClickListener) this);
        btn_clear.setOnClickListener((View.OnClickListener) this);
        ed1.setOnClickListener((View.OnClickListener) this);

    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_0:
                ed1.setText(ed1.getText()+"0");
                break;
            case R.id.btn_1:
                ed1.setText(ed1.getText()+"1");

                break;
            case R.id.btn_2:
                ed1.setText(ed1.getText()+"2");

                break;
            case R.id.btn_3:
                ed1.setText(ed1.getText()+"3");

                break;
            case R.id.btn_4:
                ed1.setText(ed1.getText()+"4");

                break;
            case R.id.btn_5:
                ed1.setText(ed1.getText()+"5");

                break;
            case R.id.btn_6:
                ed1.setText(ed1.getText()+"6");

                break;
            case R.id.btn_7:
                ed1.setText(ed1.getText()+"7");

                break;
            case R.id.btn_8:
                ed1.setText(ed1.getText()+"8");

                break;
            case R.id.btn_9:
                ed1.setText(ed1.getText()+"9");

                break;
            case R.id.btn_Add:
                if (ed1 == null){
                    ed1.setText("");
                }else {
                    Value1 = Float.parseFloat(ed1.getText() + "");
                    mAddition = true;
                    ed1.setText(null);
                }
                break;
            case R.id.btn_Sub:
                Value1 = Float.parseFloat(ed1.getText() + "");
                mSubtract = true ;
                ed1.setText(null);
                break;
            case R.id.btn_Mul:
                Value1 = Float.parseFloat(ed1.getText() + "");
                mMultiplication = true ;
                ed1.setText(null);
                break;
            case R.id.btn_Div:
                Value1 = Float.parseFloat(ed1.getText()+"");
                mDivision = true ;
                ed1.setText(null);
                break;
            case R.id.btn_calc:
                Value2 = Float.parseFloat(ed1.getText() + "");

                if (mAddition == true){
                    ed1.setText(Value1 + Value2 +"");
                    mAddition=false;
                }
                if (mSubtract == true){
                    ed1.setText(Value1 - Value2 +"");
                    mSubtract=false;
                }

                if (mMultiplication == true){
                    ed1.setText(Value1 * Value2 + "");
                    mMultiplication=false;
                }

                if (mDivision == true){
                    ed1.setText(Value1 / Value2+"");
                    mDivision=false;
                }
                break;
            case R.id.btn_clear:
                ed1.setText("");
                break;
            case R.id.btn_dec:
                ed1.setText(ed1.getText()+".");
                break;
        }

    }


}
