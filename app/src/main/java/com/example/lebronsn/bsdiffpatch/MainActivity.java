package com.example.lebronsn.bsdiffpatch;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

import java.io.File;

public class MainActivity extends AppCompatActivity {
    //旧版本
    String old =getsdpath()+"hello.apk";
    //新版本
    String newp = getsdpath()+"hehehe.apk";
    //差分包
    String patch = getsdpath()+"patch.patch";
    //旧版apk和差分包合并生成的新版apk
    String tmp = getsdpath()+"new.apk";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//

//    TextView tv = (TextView) findViewById(R.id.sample_text);
    }

    public void click(View view){
        switch (view.getId()){
            case R.id.bt_diff:
                long s = System.currentTimeMillis();
                diff(old,newp,patch);
                long s1 = System.currentTimeMillis();
                Toast.makeText(this,"diff success"+(s1-s),Toast.LENGTH_SHORT).show();
                break;
            case R.id.bt_patch:
                long s2 = System.currentTimeMillis();
                patch(old,tmp,patch);
                long s3 = System.currentTimeMillis();
                Toast.makeText(this,"patch success"+(s3-s2),Toast.LENGTH_SHORT).show();
                break;
        }
    }

    private String getsdpath(){
        return Environment.getExternalStorageDirectory().getPath()+ File.separator;
    }
    //生成差分包
    public native int diff(String oldpath,String newpath,String patch);
    //旧apk和差分包合并
    public native int patch(String oldpath,String newpath,String patch);
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
