package cc.myoga.weather;

import cc.myoga.bean.WeatherQueryResultByLocationAndNow;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.hc.client5.http.classic.methods.HttpGet;
import org.apache.hc.client5.http.impl.classic.CloseableHttpClient;
import org.apache.hc.client5.http.impl.classic.CloseableHttpResponse;
import org.apache.hc.client5.http.impl.classic.HttpClientBuilder;
import org.apache.hc.core5.http.HttpEntity;
import org.apache.hc.core5.http.ParseException;
import org.apache.hc.core5.http.io.entity.EntityUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * 获取天气信息的Servlet
 */
@WebServlet(name = "GetWeatherServlet", urlPatterns = "/GetWeatherServlet")
public class GetWeatherServlet extends HttpServlet {
    // 定义一个CloseableHttpClient
    CloseableHttpClient build = null;
    // 定义响应接收对象
    CloseableHttpResponse res = null;
    @Override
    public void init() throws ServletException {
        super.init();
        //初始化对象
        build = HttpClientBuilder.create().build();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        // 定义天气接口Api的Url
        String url = "https://devapi.heweather.net/v7/weather/now?location=121.4012,31.0449&key=e4cf87b1febf4b33b7d614072ab0c370";
        // 定义请求
        HttpGet httpGet = new HttpGet(url);
        // 获取查询结果
        res = build.execute(httpGet);
        // 获取到响应状态
        int code = res.getCode();
        // 请求成功
        if (code == 200){
            HttpEntity responseEntity = res.getEntity();
            String res = "";
            try {
                res = EntityUtils.toString(responseEntity);
                JSONObject jsonObject = JSON.parseObject(res);
                WeatherQueryResultByLocationAndNow object = JSONObject.toJavaObject(jsonObject, WeatherQueryResultByLocationAndNow.class);
                request.setAttribute("object",object);
                request.getRequestDispatcher("weather_info.jsp").forward(request,response);
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }else {
            response.getWriter().write("600:请求出错");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        this.doPost(request, response);
    }
}