package com.kyhsgeekcode.disassembler;

import android.app.*;
import android.content.*;
import android.os.*;
import android.util.*;
import android.view.*;
import android.widget.*;

public class ColorPrefDialog extends Dialog
{
    private TextView mTitleView;
    private TextView mContentView;
    private Button mLeftButton;
    private Button mRightButton;
    private String mTitle;
    private String mContent;

    SharedPreferences setting;
    SharedPreferences.Editor editor;
    private View.OnClickListener mLeftClickListener;
    private View.OnClickListener mRightClickListener;

    //MainActivity ma;//may cause leak?...
    private String TAG = "Disassembler dialog";

    private ListView lvRows;

    private ColorPrefLvAdapter adapter;

    private TextView preview;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setting = getContext().getSharedPreferences("setting", 0);
        editor = setting.edit();
        // ????? ?? ?? ??? ??
        WindowManager.LayoutParams lpWindow = new WindowManager.LayoutParams();
        lpWindow.flags = WindowManager.LayoutParams.FLAG_DIM_BEHIND;
        lpWindow.dimAmount =  (float) 0.8;
        getWindow().setAttributes(lpWindow);

        setContentView(R.layout.colorpref_dialog);

        mTitleView = (TextView) findViewById(R.id.colorpef_title);
        mContentView = (TextView) findViewById(R.id.colorpref_subtitle);
        mLeftButton = (Button) findViewById(R.id.colorprefdialogButtonCancel);
        mRightButton = (Button) findViewById(R.id.colorprefdialogButtonOK);

        lvRows = (ListView) findViewById(R.id.colorpref_list);
        lvRows.setAdapter(adapter);

        preview = (TextView) findViewById(R.id.colorpref_preview);
        // ??? ??? ????? ????.
        mTitleView.setText(mTitle);
        mContentView.setText(mContent);
        mRightButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View p1)
            {
                //p1.setTag(
                if (mRightClickListener != null)
                    mRightClickListener.onClick(p1);
                dismiss();
            }
        });
        mLeftButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View p1)
            {
                if (mLeftClickListener != null)
                    mLeftClickListener.onClick(p1);
                dismiss();
            }
        });
    }

    // ????? ???? ??? ??? ?????? ???.
    public ColorPrefDialog(Context context, String title,
                           View.OnClickListener singleListener, Palette palette)
    {
        super(context, android.R.style.Theme_Translucent_NoTitleBar);
        this.mTitle = title;
        this.mRightClickListener = singleListener;
        adapter = new ColorPrefLvAdapter(palette, context);
        //if(context instanceof MainActivity)
        //{
        //	ma=(MainActivity) context;
        //}
    }

    // ????? ??? ?? ???? ??? ??? ???? ???
    public ColorPrefDialog(Context context, String title,
                           String content, View.OnClickListener leftListener,
                           View.OnClickListener rightListener, Palette palette)
    {
        super(context, android.R.style.Theme_Translucent_NoTitleBar);
        this.mTitle = title;
        this.mContent = content;
        this.mLeftClickListener = leftListener;
        this.mRightClickListener = rightListener;
        adapter = new ColorPrefLvAdapter(palette, context);
        //if(context instanceof MainActivity)
        //{
        //	ma=(MainActivity) context;
        //}
    }

}

