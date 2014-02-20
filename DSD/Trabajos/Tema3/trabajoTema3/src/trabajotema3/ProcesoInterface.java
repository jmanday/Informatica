/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.Remote;
import java.util.ArrayList;

/**
 *
 * @author jesus
 */
public interface ProcesoInterface extends Remote{
       
    /*
     * Este metodo devuelve el nombre de un objeto ProcesoInterface
     */
    public String getNombre() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo devuelve el identificador de un objeto ProcesoInterface
     */
    public int getID() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo devuelve verdadero si el objeto sobre el que se aplica es poseedor del testigo
     */
    public boolean tieneTestigo() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo asigna el testigo al objeto sobre el que se aplica 
     */
    public void asignarTestigo() throws java.rmi.RemoteException;
        
    
    /*
     * Este metodo desasigna el testigo al objeto sobre el que se aplica 
     */
    public void desasignarTestigo() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo indica el nombre del proceso que actualmente posee el testigo
     */
    public void posesionTestigo(ProcesoInterface proc) throws java.rmi.RemoteException;
    
    
    /*
     * El objeto que invoca este método actualiza quien es el que tiene el testigo
     */
    public void actualizarTestigo(ProcesoInterface p) throws java.rmi.RemoteException;
    
    
    /*
     * Este método nos devuelve el tiempo que lleva el proceso en su seccion critica
     */
    public int getTime() throws java.rmi.RemoteException;
    
    
    /*
     * Este método nos devuelve el tiempo que tiene asignado el proceso para acceder a su seccion critica
     */
    public double getSC() throws java.rmi.RemoteException;

}
