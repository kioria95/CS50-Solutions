package com.theknights.pokedexx;

import androidx.appcompat.app.AppCompatActivity;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class PokemonActivity extends AppCompatActivity
{
    private TextView nameTextView;
    private TextView numberTextview;
    private TextView type1Textview;
    private TextView type2Textview;
    private String url;
    private RequestQueue requestQueue;
    private Button button;
    int state = 1;
    int saved;

    int[] myarrays=new int[300];



    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pokemon);

        url = getIntent().getStringExtra("url");

       requestQueue = Volley.newRequestQueue(getApplicationContext());
       nameTextView = findViewById(R.id.pokemon_name);
       numberTextview = findViewById(R.id.pokemon_number);
       type1Textview = findViewById(R.id.pokemon_type1);
       type2Textview = findViewById(R.id.pokemon_type2);

       load();

        button = findViewById(R.id.catch_button);

        button.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {

                if(state % 2 != 0)
                {
                    button.setText("Release");

                }

                if(state % 2 == 0)
                {
                    button.setText("Catch");
                }

                state++;
                saved = state;

            }
        });

    }



    protected void onResume()
    {
        super.onResume();

        // Fetching the stored data
        // from the SharedPreference
        SharedPreferences sh= getSharedPreferences("Button_state",MODE_APPEND);
        state = sh.getInt("saved", 0);
    }

    protected void onPause()
    {
        super.onPause();

        // Creating a shared pref object
        // with a file name "MySharedPref" in private mode
        SharedPreferences sharedPreferences = getSharedPreferences("Button_state", MODE_PRIVATE);
        SharedPreferences.Editor myEdit  = sharedPreferences.edit();
        myEdit.putInt("saved", saved);
        myEdit.putInt("pokemon", saved);
        myEdit.commit();
    }

    public void load()
    {
        type1Textview.setText("");
        type2Textview.setText("");

         JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET, url, null, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject response)
            {
                //Gets the array with the key results
                //Add in try and catch to catch the exception it is throwing if we get wrong JSON
                try {
                    nameTextView.setText(response.getString("name"));
                    numberTextview.setText(String.format("#%03d", response.getInt("id")));

                       JSONArray typeEntries = response.getJSONArray("types");
                       for( int i = 0; i< typeEntries.length(); i++)
                       {
                           JSONObject typeEntry = typeEntries.getJSONObject(i);
                           int slot = typeEntry.getInt("slot");
                           String type = typeEntry.getJSONObject("type").getString("name");

                           if(slot == 1)
                           {
                               type1Textview.setText(type);

                           }
                           else if(slot == 2)
                           {
                               type2Textview.setText(type);
                           }
                       }
                    }
                catch (JSONException e)
                {
                    Log.e("cs50", "Pokemon Json error");
                }

            }
        }, new Response.ErrorListener()
        {
            @Override
            public void onErrorResponse(VolleyError error) {
                Log.e("cs50", "Pokemon Details error");
            }
        });

         requestQueue.add(request);
    }






}