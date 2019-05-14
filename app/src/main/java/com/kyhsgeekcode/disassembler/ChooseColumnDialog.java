package com.kyhsgeekcode.disassembler;


import android.app.*;
import android.content.*;
import android.os.*;
import android.util.*;
import android.view.*;
import android.widget.*;
import java.util.*;

public class ChooseColumnDialog extends Dialog
{

    private TextView mTitleView;
    private TextView mContentView;
    private Button mLeftButton;
    private Button mRightButton;
    private String mTitle;
    private String mContent;

    private CheckBox mCKAddress;
    private CheckBox mCKLabel;
    private CheckBox mCKBytes;
    private CheckBox mCKInstruction;
    private CheckBox mCKCondition;
    private CheckBox mCKOperands;
    private CheckBox mCKComments;

    SharedPreferences setting;
    SharedPreferences.Editor editor;
    private View.OnClickListener mLeftClickListener;
    private View.OnClickListener mRightClickListener;

    MainActivity ma;//may cause leak?...
    private String TAG = "Disassembler dialog";

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

        setContentView(R.layout.activity_custom_dialog);

        mTitleView = (TextView) findViewById(R.id.txt_title);
        mContentView = (TextView) findViewById(R.id.txt_content);
        mLeftButton = (Button) findViewById(R.id.btn_left);
        mRightButton = (Button) findViewById(R.id.btn_right);

        mCKCondition = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxCondition);
        mCKInstruction = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxInstruction);
        mCKOperands = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxOperands);
        mCKComments = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxComment);
        mCKBytes = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxBytes);
        mCKLabel = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxLabel);
        mCKAddress = (CheckBox) findViewById(R.id.activitycustomdialogCheckBoxAddress);

        mCKCondition.setChecked(setting.getBoolean("condition", true));
        mCKInstruction.setChecked(setting.getBoolean("instruction", true));
        mCKOperands.setChecked(setting.getBoolean("operands", true));
        mCKComments.setChecked(setting.getBoolean("comments", true));
        mCKBytes.setChecked(setting.getBoolean("bytes", true));
        mCKLabel.setChecked(setting.getBoolean("label", true));
        mCKAddress.setChecked(setting.getBoolean("address", true));

        // ??? ??? ????? ????.
        mTitleView.setText(mTitle);
        mContentView.setText(mContent);
        mLeftButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View p1)
            {

                editor.putBoolean("condition", mCKCondition.isChecked());
                editor.putBoolean("instruction", mCKInstruction.isChecked());
                editor.putBoolean("operands", mCKOperands.isChecked());
                editor.putBoolean("comments", mCKComments.isChecked());
                editor.putBoolean("bytes", mCKBytes.isChecked());
                editor.putBoolean("label", mCKLabel.isChecked());
                editor.putBoolean("address", mCKAddress.isChecked());
                editor.commit();
                //Context c=getContext();
                //	Activity activity=	getOwnerActivity();
                //if (activity instanceof MainActivity)
                {
                    //ma = (MainActivity) activity;
                    Log.v(TAG, "Activity is MA");
                    ColumnSetting cs = new ColumnSetting();
                    cs.showAddress = mCKAddress.isChecked();
                    cs.showInstruction = mCKInstruction.isChecked();
                    cs.showLabel = mCKLabel.isChecked();
                    cs.showOperands = mCKOperands.isChecked();
                    cs.showBytes = mCKBytes.isChecked();
                    cs.showConditions = mCKCondition.isChecked();
                    cs.showComments = mCKComments.isChecked();
                    //mLeftButton.setTag(0,mCKLabel.isChecked());
                    //MainActivity ma=(MainActivity)c;
                    //						mLeftButton.setHint(new String(Arrays.toString(new boolean[]{
                    //						/*mLeftButton.setTag(TAGLabel,*/mCKLabel.isChecked()
                    //						/*mLeftButton.setTag(TAGAddress*/,mCKAddress.isChecked()
                    //						/*mLeftButton.setTag(TAGBytes*/,mCKBytes.isChecked()
                    //						/*mLeftButton.setTag(TAGInstruction*/,mCKInstruction.isChecked()
                    //						/*mLeftButton.setTag(TAGComment*/,mCKComments.isChecked()
                    //						/*mLeftButton.setTag(TAGCondition*/,mCKCondition.isChecked()
                    //						/*mLeftButton.setTag(TAGOperands*/,mCKOperands.isChecked()})));
                    //						//ma.RefreshTable();
                    mLeftButton.setTag(cs);
                }
                if(mLeftClickListener != null)
                    mLeftClickListener.onClick(mLeftButton);
                dismiss();
            }
        });
        mRightButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View p1)
            {
                if(mRightClickListener != null)
                    mRightClickListener.onClick(mRightButton);
                dismiss();
            }
        });

    }

    // ????? ???? ??? ??? ?????? ???.
    public ChooseColumnDialog(Context context, String title,
                              View.OnClickListener singleListener)
    {
        super(context, android.R.style.Theme_Translucent_NoTitleBar);
        this.mTitle = title;
        this.mLeftClickListener = singleListener;
        //if(context instanceof MainActivity)
        //{
        //	ma=(MainActivity) context;
        //}
    }

    // ????? ??? ?? ???? ??? ??? ???? ???
    public ChooseColumnDialog(Context context, String title,
                              String content, View.OnClickListener leftListener,
                              View.OnClickListener rightListener)
    {
        super(context, android.R.style.Theme_Translucent_NoTitleBar);
        this.mTitle = title;
        this.mContent = content;
        this.mLeftClickListener = leftListener;
        this.mRightClickListener = rightListener;
        //if(context instanceof MainActivity)
        //{
        //	ma=(MainActivity) context;
        //}
    }
    public static final int TAGLabel = 1;
    public static final int TAGAddress = 2;
    public static final int TAGBytes = 3;
    public static final int TAGInstruction = 4;
    public static final int TAGCondition = 5;
    public static final int TAGOperands = 6;
    public static final int TAGComment = 7;

}
