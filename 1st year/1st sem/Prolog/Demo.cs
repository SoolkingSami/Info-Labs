using System;
using System.Collections.Generic;

public interface IRequest
{
}

public class Request1: IRequest
{
}

public class Request2: IRequest
{
}

public interface IRequestHandler
{
}

public class RequestHandler1: IRequestHandler
{
}

public class RequestHandler2: IRequestHandler
{
}

public class RequestBus
{
    private readonly Dictionary<Type, Type> handlers = new Dictionary<Type, Type>();

    public void RegisterHandler<TRequest, THandler>() 
        where TRequest: IRequest
        where THandler: IRequestHandler
    {
        if (handlers.ContainsKey(typeof(THandler)))
            throw new ArgumentException("requestType is already registered.", nameof(TRequest));

        handlers.Add(typeof(TRequest), typeof(THandler));
    }
}

public static class Bootstrapper {
    private static readonly RequestBus requestBus = new RequestBus();

    public static void Bootstrap() 
    {
        requestBus.RegisterHandler<Request1, RequestHandler1>();
        requestBus.RegisterHandler<Request2, RequestHandler2>();
    }
}