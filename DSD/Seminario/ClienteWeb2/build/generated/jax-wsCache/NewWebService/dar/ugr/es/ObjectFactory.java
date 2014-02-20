
package dar.ugr.es;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the dar.ugr.es package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _HelloResponse_QNAME = new QName("http://es.ugr.dar/", "helloResponse");
    private final static QName _Hello_QNAME = new QName("http://es.ugr.dar/", "hello");
    private final static QName _Divisa_QNAME = new QName("http://es.ugr.dar/", "divisa");
    private final static QName _DivisaResponse_QNAME = new QName("http://es.ugr.dar/", "divisaResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: dar.ugr.es
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link Hello }
     * 
     */
    public Hello createHello() {
        return new Hello();
    }

    /**
     * Create an instance of {@link Divisa }
     * 
     */
    public Divisa createDivisa() {
        return new Divisa();
    }

    /**
     * Create an instance of {@link HelloResponse }
     * 
     */
    public HelloResponse createHelloResponse() {
        return new HelloResponse();
    }

    /**
     * Create an instance of {@link DivisaResponse }
     * 
     */
    public DivisaResponse createDivisaResponse() {
        return new DivisaResponse();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link HelloResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://es.ugr.dar/", name = "helloResponse")
    public JAXBElement<HelloResponse> createHelloResponse(HelloResponse value) {
        return new JAXBElement<HelloResponse>(_HelloResponse_QNAME, HelloResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Hello }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://es.ugr.dar/", name = "hello")
    public JAXBElement<Hello> createHello(Hello value) {
        return new JAXBElement<Hello>(_Hello_QNAME, Hello.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Divisa }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://es.ugr.dar/", name = "divisa")
    public JAXBElement<Divisa> createDivisa(Divisa value) {
        return new JAXBElement<Divisa>(_Divisa_QNAME, Divisa.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link DivisaResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://es.ugr.dar/", name = "divisaResponse")
    public JAXBElement<DivisaResponse> createDivisaResponse(DivisaResponse value) {
        return new JAXBElement<DivisaResponse>(_DivisaResponse_QNAME, DivisaResponse.class, null, value);
    }

}
