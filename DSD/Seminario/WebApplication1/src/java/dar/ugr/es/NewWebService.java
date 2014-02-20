/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dar.ugr.es;

import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;

/**
 *
 * @author jesus
 */
@WebService(serviceName = "NewWebService")
public class NewWebService {

    /**
     * This is a sample web service operation
     */
    @WebMethod(operationName = "hello")
    public String hello(@WebParam(name = "name") String txt) {
        return "Hello " + txt + " !";
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "divisa")
    public String divisa() {
        //TODO write your implementation code here:
        return "USD";
    }
}
