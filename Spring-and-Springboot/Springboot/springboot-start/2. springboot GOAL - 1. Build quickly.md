# springboot GOAL - 1. Build quickly

스프링부트를 잘 이해하려면, 스프링부트를 잘 다루는 방법뿐만 아니라 **스프링부트 백그라운드**에서는 무슨 일이 일어나고 있는지를 잘 파악해두어야 한다.

스프링부트는 주로, 웹 개발을 편리하게 하기 위해 만들어진 자바언어 기반의 프레임워크다. 

스프링부트의 목표는 크게 2가지라고 보면 된다.

- Build quickly
    - Spring initializer : start.spring.io 웹사이트에서 쉽게 만들 수 있음
    - Spring Boot Starter Project
    - Spring Boot Auto Configuration
    - Spring Boot DevTools

- production-ready
    - Logging
    - Differnt Configuration for Different Environments
        - Profiles, ConfigurationProperties
    - Monitoring(Spring Boot Actuator)

위의 내용을 두개의 포스팅에 걸쳐서 정리할 것이다.

# 목차

- Spring Boot Starter Project
- Spring Boot Auto Configuration
- Spring Boot DevTools

## Spring Boot Starter Project

### starter Project의 필요성과 의미

어플리케이션의 기능을 build할 때마다 많은 프레임워크가 필요하다. 가령, REST API를 build하려면, Spring프레임워크, Spring MVC 프레임워크, tomcat 프레임워크, JSON conversion... 등등의 많은 프레임워크가 필요하다.

이러한 프레임워크를 그룹화해서, 어플리케이션을 쉽게 빌드하고자 만든 것이 바로, starter project이다. 

starter project의 뜻부터 먼저 말하자면, **define all application dependencies**이다.

그럼 이제 starter project를 실제로 사용해, 어플리케이션 의존성을 주입하는 방법을 살펴보자.

### starter project 사용법

## Spring Boot Auto Configuration

## Spring Boot DevTools


