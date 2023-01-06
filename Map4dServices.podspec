Pod::Spec.new do |s|
    s.name              = 'Map4dServices'
    s.version           = '2.1.1'
    s.summary           = 'Map4D Services SDK'
    s.homepage          = 'http://map4d.vn'

    s.author            = { 'IOTLink' => 'admin@iotlink.com.vn' }
    s.license           = { :type => 'Apache-2.0'}

    s.platform          = :ios, '9.3'
    s.source = { :git => 'https://github.com/map4d/map4d-services-ios-sdk.git', :tag => s.version.to_s }

    s.ios.vendored_frameworks = 'sdk/Map4dServices.framework'
end
