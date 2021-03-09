package com.google.sps.servlets;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;

/** Handles requests sent to the /skills URL. **/

@WebServlet("/skills")
public class SkillsServlet extends HttpServlet {

    public static ArrayList<String> skills = new ArrayList<>();

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        skills.add("Python");
        skills.add("Java");
        skills.add("SQL");
        Gson gson = new Gson();
        String json = gson.toJson(skills);
        // Send the JSON as the response
        response.setContentType("application/json;");
        response.getWriter().println(json);
    }
}
