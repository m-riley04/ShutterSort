#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Define the hash table
    std::unordered_map<std::string, std::string> exifTags;

    // Inserting tags into the hash table
    exifTags["NewSubfileType"] = "Exif.Image.NewSubfileType";
    exifTags["SubfileType"] = "Exif.Image.SubfileType";
    exifTags["ImageWidth"] = "Exif.Image.ImageWidth";
    exifTags["ImageLength"] = "Exif.Image.ImageLength";
    exifTags["Compression"] = "Exif.Image.Compression";
    exifTags["PhotometricInterpretation"] = "Exif.Image.PhotometricInterpretation";
    exifTags["Thresholding"] = "Exif.Image.Thresholding";
    exifTags["CellWidth"] = "Exif.Image.CellWidth";
    exifTags["CellLength"] = "Exif.Image.CellLength";
    exifTags["FillOrder"] = "Exif.Image.FillOrder";
    exifTags["StripOffsets"] = "Exif.Image.StripOffsets";
    exifTags["Orientation"] = "Exif.Image.Orientation";
    exifTags["SamplesPerPixel"] = "Exif.Image.SamplesPerPixel";
    exifTags["RowsPerStrip"] = "Exif.Image.RowsPerStrip";
    exifTags["XResolution"] = "Exif.Image.XResolution";
    exifTags["YResolution"] = "Exif.Image.YResolution";
    exifTags["PlanarConfiguration"] = "Exif.Image.PlanarConfiguration";
    exifTags["XPosition"] = "Exif.Image.XPosition";
    exifTags["YPosition"] = "Exif.Image.YPosition";
    exifTags["GrayResponseUnit"] = "Exif.Image.GrayResponseUnit";
    exifTags["GrayResponseCurve"] = "Exif.Image.GrayResponseCurve";
    exifTags["T4Options"] = "Exif.Image.T4Options";
    exifTags["T6Options"] = "Exif.Image.T6Options";
    exifTags["ResolutionUnit"] = "Exif.Image.ResolutionUnit";
    exifTags["PageNumber"] = "Exif.Image.PageNumber";
    exifTags["TransferFunction"] = "Exif.Image.TransferFunction";
    exifTags["Predictor"] = "Exif.Image.Predictor";
    exifTags["WhitePoint"] = "Exif.Image.WhitePoint";
    exifTags["PrimaryChromaticities"] = "Exif.Image.PrimaryChromaticities";
    exifTags["ColorMap"] = "Exif.Image.ColorMap";
    exifTags["HalftoneHints"] = "Exif.Image.HalftoneHints";
    exifTags["TileWidth"] = "Exif.Image.TileWidth";
    exifTags["TileLength"] = "Exif.Image.TileLength";
    exifTags["TileOffsets"] = "Exif.Image.TileOffsets";
    exifTags["TileByteCounts"] = "Exif.Image.TileByteCounts";
    exifTags["SubIFDs"] = "Exif.Image.SubIFDs";
    exifTags["InkSet"] = "Exif.Image.InkSet";
    exifTags["NumberOflnks"] = "Exif.Image.NumberOfInks";
    exifTags["ExtraSamples"] = "Exif.Image.ExtraSamples";
    exifTags["SampleFormat"] = "Exif.Image.SampleFormat";
    exifTags["SMinSampleValue"] = "Exif.Image.SMinSampleValue";
    exifTags["SMaxSampleValue"] = "Exif.Image.SMaxSampleValue";
    exifTags["TransferRange"] = "Exif.Image.TransferRange";
    exifTags["XClipPathUnits"] = "Exif.Image.XClipPathUnits";
    exifTags["YClipPathUnits"] = "Exif.Image.YClipPathUnits";
    exifTags["Indexed"] = "Exif.Image.Indexed";
    exifTags["OPIProxy"] = "Exif.Image.OPIProxy";
    exifTags["JPEGProc"] = "Exif.Image.JPEGProc";
    exifTags["JPEGInterchangeFormat"] = "Exif.Image.JPEGInterchangeFormat";
    exifTags["JPEGInterchangeFormatLength"] = "Exif.Image.JPEGInterchangeFormatLength";
    exifTags["JPEGRestartInterval"] = "Exif.Image.JPEGRestartInterval";
    exifTags["JPEGLosslessPredictors"] = "Exif.Image.JPEGLosslessPredictors";
    exifTags["JPEGPointTransforms"] = "Exif.Image.JPEGPointTransforms";
    exifTags["JPEGQTables"] = "Exif.Image.JPEGQTables";
    exifTags["JPEGDCTables"] = "Exif.Image.JPEGDCTables";
    exifTags["JPEGACTables"] = "Exif.Image.JPEGACTables";
    exifTags["YCbCrSubSampling"] = "Exif.Image.YCbCrSubSampling";
    exifTags["YCbCrPositioning"] = "Exif.Image.YCbCrPositioning";
    exifTags["ReferenceBlackWhite"] = "Exif.Image.ReferenceBlackWhite";
    exifTags["Rating"] = "Exif.Image.Rating";
    exifTags["RatingPercent"] = "Exif.Image.RatingPercent";
    exifTags["VignettingCorrParams"] = "Exif.Image.VignettingCorrParams";
    exifTags["ChromaticAberrationCorrParams"] = "Exif.Image.ChromaticAberrationCorrParams";
    exifTags["DistortionCorrParams"] = "Exif.Image.DistortionCorrParams";
    exifTags["CFARepeatPatternDim"] = "Exif.Image.CFARepeatPatternDim";
    exifTags["BatteryLevel"] = "Exif.Image.BatteryLevel";
    exifTags["ExposureTime"] = "Exif.Photo.ExposureTime";
    exifTags["FNumber"] = "Exif.Photo.FNumber";
    exifTags["IPTCNAA"] = "Exif.Photo.IPTCNAA";
    exifTags["ExifTag"] = "Exif.Photo.ExifTag";
    exifTags["ExposureProgram"] = "Exif.Photo.ExposureProgram";
    exifTags["GPSTag"] = "Exif.Photo.GPSTag";
    exifTags["ISOSpeedRatings"] = "Exif.Photo.ISOSpeedRatings";
    exifTags["Interlace"] = "Exif.Photo.Interlace";
    exifTags["TimeZoneOffset"] = "Exif.Photo.TimeZoneOffset";
    exifTags["SelfTimerMode"] = "Exif.Photo.SelfTimerMode";
    exifTags["CompressedBitsPerPixel"] = "Exif.Photo.CompressedBitsPerPixel";
    exifTags["ShutterSpeedValue"] = "Exif.Photo.ShutterSpeedValue";
    exifTags["ApertureValue"] = "Exif.Photo.ApertureValue";
    exifTags["BrightnessValue"] = "Exif.Photo.BrightnessValue";
    exifTags["ExposureBiasValue"] = "Exif.Photo.ExposureBiasValue";
    exifTags["MaxApertureValue"] = "Exif.Photo.MaxApertureValue";
    exifTags["SubjectDistance"] = "Exif.Photo.SubjectDistance";
    exifTags["MeteringMode"] = "Exif.Photo.MeteringMode";
    exifTags["LightSource"] = "Exif.Photo.LightSource";
    exifTags["Flash"] = "Exif.Photo.Flash";
    exifTags["FocalLength"] = "Exif.Photo.FocalLength";
    exifTags["FlashEnergy"] = "Exif.Photo.FlashEnergy";
    exifTags["FocalPlaneXResolution"] = "Exif.Photo.FocalPlaneXResolution";
    exifTags["FocalPlaneYResolution"] = "Exif.Photo.FocalPlaneYResolution";
    exifTags["FocalPlaneResolutionUnit"] = "Exif.Photo.FocalPlaneResolutionUnit";
    exifTags["ImageNumber"] = "Exif.Photo.ImageNumber";
    exifTags["SubjectLocation"] = "Exif.Photo.SubjectLocation";
    exifTags["ExposureIndex"] = "Exif.Photo.ExposureIndex";
    exifTags["SensingMethod"] = "Exif.Photo.SensingMethod";
    exifTags["CFALayout"] = "Exif.Photo.CFALayout";
    exifTags["LinearizationTable"] = "Exif.Photo.LinearizationTable";
    exifTags["BlackLevelRepeatDim"] = "Exif.Photo.BlackLevelRepeatDim";
    exifTags["BlackLevel"] = "Exif.Photo.BlackLevel";
    exifTags["BlackLevelDeltaH"] = "Exif.Photo.BlackLevelDeltaH";
    exifTags["BlackLevelDeltaV"] = "Exif.Photo.BlackLevelDeltaV";
    exifTags["WhiteLevel"] = "Exif.Photo.WhiteLevel";
    exifTags["DefaultScale"] = "Exif.Photo.DefaultScale";
    exifTags["DefaultCropOrigin"] = "Exif.Photo.DefaultCropOrigin";
    exifTags["DefaultCropSize"] = "Exif.Photo.DefaultCropSize";
    exifTags["BaselineNoise"] = "Exif.Photo.BaselineNoise";
    exifTags["BaselineSharpness"] = "Exif.Photo.BaselineSharpness";
    exifTags["CameraSerialNumber"] = "Exif.Photo.CameraSerialNumber";
    exifTags["LensInfo"] = "Exif.Photo.LensInfo";
    exifTags["ChromaBlurRadius"] = "Exif.Photo.ChromaBlurRadius";
    exifTags["AntiAliasStrength"] = "Exif.Photo.AntiAliasStrength";
    exifTags["ShadowScale"] = "Exif.Photo.ShadowScale";
    exifTags["MakerNoteSafety"] = "Exif.Photo.MakerNoteSafety";
    exifTags["BestQualityScale"] = "Exif.Photo.BestQualityScale";
    exifTags["ColorimetricReference"] = "Exif.Photo.ColorimetricReference";
    exifTags["ExtraCameraProfiles"] = "Exif.Photo.ExtraCameraProfiles";
    exifTags["NoiseReductionApplied"] = "Exif.Photo.NoiseReductionApplied";
    exifTags["ProfileEmbedPolicy"] = "Exif.Photo.ProfileEmbedPolicy";
    exifTags["NoiseProfile"] = "Exif.Photo.NoiseProfile";
    exifTags["FrameRate"] = "Exif.Photo.FrameRate";
    exifTags["TStop"] = "Exif.Photo.TStop";
    exifTags["ExposureTime"] = "Exif.Photo.ExposureTime";
    exifTags["FNumber"] = "Exif.Photo.FNumber";
    exifTags["ExposureProgram"] = "Exif.Photo.ExposureProgram";
    exifTags["ISOSpeedRatings"] = "Exif.Photo.ISOSpeedRatings";
    exifTags["ISOSpeed"] = "Exif.Photo.ISOSpeed";
    exifTags["ApertureValue"] = "Exif.Photo.ApertureValue";
    exifTags["BrightnessValue"] = "Exif.Photo.BrightnessValue";
    exifTags["MaxApertureValue"] = "Exif.Photo.MaxApertureValue";
    exifTags["SubjectDistance"] = "Exif.Photo.SubjectDistance";
    exifTags["MeteringMode"] = "Exif.Photo.MeteringMode";
    exifTags["LightSource"] = "Exif.Photo.LightSource";
    exifTags["Flash"] = "Exif.Photo.Flash";
    exifTags["FocalLength"] = "Exif.Photo.FocalLength";
    exifTags["SubjectArea"] = "Exif.Photo.SubjectArea";
    exifTags["ColorSpace"] = "Exif.Photo.ColorSpace";
    exifTags["ExposureMode"] = "Exif.Photo.ExposureMode";
    exifTags["WhiteBalance"] = "Exif.Photo.WhiteBalance";
    exifTags["DigitalZoomRatio"] = "Exif.Photo.DigitalZoomRatio";
    exifTags["GainControl"] = "Exif.Photo.GainControl";
    exifTags["Contrast"] = "Exif.Photo.Contrast";
    exifTags["Saturation"] = "Exif.Photo.Saturation";
    exifTags["Sharpness"] = "Exif.Photo.Sharpness";
    exifTags["LensSpecification"] = "Exif.Photo.LensSpecification";
    exifTags["Gamma"] = "Exif.Photo.Gamma";













