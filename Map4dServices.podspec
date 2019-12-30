Pod::Spec.new do |s|
    s.name              = 'Map4dServices'
    s.version           = '0.2.0'
    s.summary           = 'Map4D Services SDK'
    s.homepage          = 'http://map4d.vn'

    s.author            = { 'Sua Le' => 'sua8051@gmail.com' }
    s.license           = { :type => 'Apache-2.0'}

    s.platform          = :ios
    s.swift_versions    = '5.0'
    s.source = { :git => 'https://github.com/map4d/map4d-services-ios-sdk.git', :tag => s.version.to_s }

    s.ios.deployment_target = '10.0'
    s.dependency 'Alamofire', '~> 4.7'
    s.dependency 'AlamofireMapper'
    s.ios.vendored_frameworks = 'sdk/Map4dServices.framework'
end
