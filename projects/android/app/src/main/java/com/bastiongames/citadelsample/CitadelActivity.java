package com.bastiongames.citadelsample;

import android.app.Activity;
import android.app.NativeActivity;
import android.os.Bundle;

public class CitadelActivity extends NativeActivity {
    static {
        System.loadLibrary("citadel-sample");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }
}
